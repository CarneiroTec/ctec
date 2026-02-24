/*
 *  NILDO - NILDO Compiler
 *
 *  Copyright (c) 2001-2004 Fabrice Bellard
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "nld.h"

/********************************************************/
/* global variables */

/* use GNU C extensions */
ST_DATA int gnu_ext = 1;

/* use Nildo extensions */
ST_DATA int nld_ext = 1;

/* XXX: get rid of this ASAP */
ST_DATA struct NILDOState *nld_state;

static int nb_states;

/********************************************************/

#if ONE_SOURCE
#include "nldpp.c"
#include "nldgen.c"
#include "nldelf.c"
#include "nldrun.c"
#ifdef NILDO_TARGET_I386
#include "i386-gen.c"
#include "i386-link.c"
#include "i386-asm.c"
#endif
#ifdef NILDO_TARGET_ARM
#include "arm-gen.c"
#include "arm-link.c"
#include "arm-asm.c"
#endif
#ifdef NILDO_TARGET_ARM64
#include "arm64-gen.c"
#include "arm64-link.c"
#endif
#ifdef NILDO_TARGET_C67
#include "c67-gen.c"
#include "c67-link.c"
#include "nldcoff.c"
#endif
#ifdef NILDO_TARGET_X86_64
#include "x86_64-gen.c"
#include "x86_64-link.c"
#include "i386-asm.c"
#endif
#ifdef CONFIG_NILDO_ASM
#include "nldasm.c"
#endif
#ifdef NILDO_TARGET_PE
#include "nldpe.c"
#endif
#endif /* ONE_SOURCE */

/********************************************************/
#ifndef CONFIG_NILDO_ASM
ST_FUNC void asm_instr(void)
{
    nld_error("inline asm() not supported");
}
ST_FUNC void asm_global_instr(void)
{
    nld_error("inline asm() not supported");
}
#endif

/********************************************************/
#ifdef _WIN32
ST_FUNC char *normalize_slashes(char *path)
{
    char *p;
    for (p = path; *p; ++p)
        if (*p == '\\')
            *p = '/';
    return path;
}

static HMODULE nld_module;

/* on win32, we suppose the lib and includes are at the location of 'nld.exe' */
static void nld_set_lib_path_w32(NILDOState *s)
{
    char path[1024], *p;
    GetModuleFileNameA(nld_module, path, sizeof path);
    p = nld_basename(normalize_slashes(strlwr(path)));
    if (p > path)
        --p;
    *p = 0;
    nld_set_lib_path(s, path);
}

#ifdef NILDO_TARGET_PE
static void nld_add_systemdir(NILDOState *s)
{
    char buf[1000];
    GetSystemDirectory(buf, sizeof buf);
    nld_add_library_path(s, normalize_slashes(buf));
}
#endif

#ifdef LIBNILDO_AS_DLL
BOOL WINAPI DllMain (HINSTANCE hDll, DWORD dwReason, LPVOID lpReserved)
{
    if (DLL_PROCESS_ATTACH == dwReason)
        nld_module = hDll;
    return TRUE;
}
#endif
#endif

/********************************************************/
/* copy a string and truncate it. */
ST_FUNC char *pstrcpy(char *buf, int buf_size, const char *s)
{
    char *q, *q_end;
    int c;

    if (buf_size > 0) {
        q = buf;
        q_end = buf + buf_size - 1;
        while (q < q_end) {
            c = *s++;
            if (c == '\0')
                break;
            *q++ = c;
        }
        *q = '\0';
    }
    return buf;
}

/* strcat and truncate. */
ST_FUNC char *pstrcat(char *buf, int buf_size, const char *s)
{
    int len;
    len = strlen(buf);
    if (len < buf_size)
        pstrcpy(buf + len, buf_size - len, s);
    return buf;
}

ST_FUNC char *pstrncpy(char *out, const char *in, size_t num)
{
    memcpy(out, in, num);
    out[num] = '\0';
    return out;
}

/* extract the basename of a file */
PUB_FUNC char *nld_basename(const char *name)
{
    char *p = strchr(name, 0);
    while (p > name && !IS_DIRSEP(p[-1]))
        --p;
    return p;
}

/* extract extension part of a file
 *
 * (if no extension, return pointer to end-of-string)
 */
PUB_FUNC char *nld_fileextension (const char *name)
{
    char *b = nld_basename(name);
    char *e = strrchr(b, '.');
    return e ? e : strchr(b, 0);
}

/********************************************************/
/* memory management */

#undef free
#undef malloc
#undef realloc

#ifndef MEM_DEBUG

PUB_FUNC void nld_free(void *ptr)
{
    free(ptr);
}

PUB_FUNC void *nld_malloc(unsigned long size)
{
    void *ptr;
    ptr = malloc(size);
    if (!ptr && size)
        nld_error("memory full (malloc)");
    return ptr;
}

PUB_FUNC void *nld_mallocz(unsigned long size)
{
    void *ptr;
    ptr = nld_malloc(size);
    memset(ptr, 0, size);
    return ptr;
}

PUB_FUNC void *nld_realloc(void *ptr, unsigned long size)
{
    void *ptr1;
    ptr1 = realloc(ptr, size);
    if (!ptr1 && size)
        nld_error("memory full (realloc)");
    return ptr1;
}

PUB_FUNC char *nld_strdup(const char *str)
{
    char *ptr;
    ptr = nld_malloc(strlen(str) + 1);
    strcpy(ptr, str);
    return ptr;
}

PUB_FUNC void nld_memcheck(void)
{
}

#else

#define MEM_DEBUG_MAGIC1 0xFEEDDEB1
#define MEM_DEBUG_MAGIC2 0xFEEDDEB2
#define MEM_DEBUG_MAGIC3 0xFEEDDEB3
#define MEM_DEBUG_FILE_LEN 40
#define MEM_DEBUG_CHECK3(header) \
    ((mem_debug_header_t*)((char*)header + header->size))->magic3
#define MEM_USER_PTR(header) \
    ((char *)header + offsetof(mem_debug_header_t, magic3))
#define MEM_HEADER_PTR(ptr) \
    (mem_debug_header_t *)((char*)ptr - offsetof(mem_debug_header_t, magic3))

struct mem_debug_header {
    unsigned magic1;
    unsigned size;
    struct mem_debug_header *prev;
    struct mem_debug_header *next;
    int line_num;
    char file_name[MEM_DEBUG_FILE_LEN + 1];
    unsigned magic2;
    ALIGNED(16) unsigned magic3;
};

typedef struct mem_debug_header mem_debug_header_t;

static mem_debug_header_t *mem_debug_chain;
static unsigned mem_cur_size;
static unsigned mem_max_size;

static mem_debug_header_t *malloc_check(void *ptr, const char *msg)
{
    mem_debug_header_t * header = MEM_HEADER_PTR(ptr);
    if (header->magic1 != MEM_DEBUG_MAGIC1 ||
        header->magic2 != MEM_DEBUG_MAGIC2 ||
        MEM_DEBUG_CHECK3(header) != MEM_DEBUG_MAGIC3 ||
        header->size == (unsigned)-1) {
        fprintf(stderr, "%s check failed\n", msg);
        if (header->magic1 == MEM_DEBUG_MAGIC1)
            fprintf(stderr, "%s:%u: block allocated here.\n",
                header->file_name, header->line_num);
        exit(1);
    }
    return header;
}

PUB_FUNC void *nld_malloc_debug(unsigned long size, const char *file, int line)
{
    int ofs;
    mem_debug_header_t *header;

    header = malloc(sizeof(mem_debug_header_t) + size);
    if (!header)
        nld_error("memory full (malloc)");

    header->magic1 = MEM_DEBUG_MAGIC1;
    header->magic2 = MEM_DEBUG_MAGIC2;
    header->size = size;
    MEM_DEBUG_CHECK3(header) = MEM_DEBUG_MAGIC3;
    header->line_num = line;
    ofs = strlen(file) - MEM_DEBUG_FILE_LEN;
    strncpy(header->file_name, file + (ofs > 0 ? ofs : 0), MEM_DEBUG_FILE_LEN);
    header->file_name[MEM_DEBUG_FILE_LEN] = 0;

    header->next = mem_debug_chain;
    header->prev = NULL;
    if (header->next)
        header->next->prev = header;
    mem_debug_chain = header;

    mem_cur_size += size;
    if (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;

    return MEM_USER_PTR(header);
}

PUB_FUNC void nld_free_debug(void *ptr)
{
    mem_debug_header_t *header;
    if (!ptr)
        return;
    header = malloc_check(ptr, "nld_free");
    mem_cur_size -= header->size;
    header->size = (unsigned)-1;
    if (header->next)
        header->next->prev = header->prev;
    if (header->prev)
        header->prev->next = header->next;
    if (header == mem_debug_chain)
        mem_debug_chain = header->next;
    free(header);
}

PUB_FUNC void *nld_mallocz_debug(unsigned long size, const char *file, int line)
{
    void *ptr;
    ptr = nld_malloc_debug(size,file,line);
    memset(ptr, 0, size);
    return ptr;
}

PUB_FUNC void *nld_realloc_debug(void *ptr, unsigned long size, const char *file, int line)
{
    mem_debug_header_t *header;
    int mem_debug_chain_update = 0;
    if (!ptr)
        return nld_malloc_debug(size, file, line);
    header = malloc_check(ptr, "nld_realloc");
    mem_cur_size -= header->size;
    mem_debug_chain_update = (header == mem_debug_chain);
    header = realloc(header, sizeof(mem_debug_header_t) + size);
    if (!header)
        nld_error("memory full (realloc)");
    header->size = size;
    MEM_DEBUG_CHECK3(header) = MEM_DEBUG_MAGIC3;
    if (header->next)
        header->next->prev = header;
    if (header->prev)
        header->prev->next = header;
    if (mem_debug_chain_update)
        mem_debug_chain = header;
    mem_cur_size += size;
    if (mem_cur_size > mem_max_size)
        mem_max_size = mem_cur_size;
    return MEM_USER_PTR(header);
}

PUB_FUNC char *nld_strdup_debug(const char *str, const char *file, int line)
{
    char *ptr;
    ptr = nld_malloc_debug(strlen(str) + 1, file, line);
    strcpy(ptr, str);
    return ptr;
}

PUB_FUNC void nld_memcheck(void)
{
    if (mem_cur_size) {
        mem_debug_header_t *header = mem_debug_chain;
        fprintf(stderr, "MEM_DEBUG: mem_leak= %d bytes, mem_max_size= %d bytes\n",
            mem_cur_size, mem_max_size);
        while (header) {
            fprintf(stderr, "%s:%u: error: %u bytes leaked\n",
                header->file_name, header->line_num, header->size);
            header = header->next;
        }
#if MEM_DEBUG-0 == 2
        exit(2);
#endif
    }
}
#endif /* MEM_DEBUG */

#define free(p) use_nld_free(p)
#define malloc(s) use_nld_malloc(s)
#define realloc(p, s) use_nld_realloc(p, s)

/********************************************************/
/* dynarrays */

ST_FUNC void dynarray_add(void *ptab, int *nb_ptr, void *data)
{
    int nb, nb_alloc;
    void **pp;

    nb = *nb_ptr;
    pp = *(void ***)ptab;
    /* every power of two we double array size */
    if ((nb & (nb - 1)) == 0) {
        if (!nb)
            nb_alloc = 1;
        else
            nb_alloc = nb * 2;
        pp = nld_realloc(pp, nb_alloc * sizeof(void *));
        *(void***)ptab = pp;
    }
    pp[nb++] = data;
    *nb_ptr = nb;
}

ST_FUNC void dynarray_reset(void *pp, int *n)
{
    void **p;
    for (p = *(void***)pp; *n; ++p, --*n)
        if (*p)
            nld_free(*p);
    nld_free(*(void**)pp);
    *(void**)pp = NULL;
}

static void nld_split_path(NILDOState *s, void *p_ary, int *p_nb_ary, const char *in)
{
    const char *p;
    do {
        int c;
        CString str;

        cstr_new(&str);
        for (p = in; c = *p, c != '\0' && c != PATHSEP[0]; ++p) {
            if (c == '{' && p[1] && p[2] == '}') {
                c = p[1], p += 2;
                if (c == 'B')
                    cstr_cat(&str, s->nld_lib_path, -1);
            } else {
                cstr_ccat(&str, c);
            }
        }
        if (str.size) {
            cstr_ccat(&str, '\0');
            dynarray_add(p_ary, p_nb_ary, nld_strdup(str.data));
        }
        cstr_free(&str);
        in = p+1;
    } while (*p);
}

/********************************************************/

static void strcat_vprintf(char *buf, int buf_size, const char *fmt, va_list ap)
{
    int len;
    len = strlen(buf);
    vsnprintf(buf + len, buf_size - len, fmt, ap);
}

static void strcat_printf(char *buf, int buf_size, const char *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    strcat_vprintf(buf, buf_size, fmt, ap);
    va_end(ap);
}

static void error1(NILDOState *s1, int is_warning, const char *fmt, va_list ap)
{
    char buf[2048];
    BufferedFile **pf, *f;

    buf[0] = '\0';
    /* use upper file if inline ":asm:" or token ":paste:" */
    for (f = file; f && f->filename[0] == ':'; f = f->prev)
     ;
    if (f) {
        for(pf = s1->include_stack; pf < s1->include_stack_ptr; pf++)
            strcat_printf(buf, sizeof(buf), "In file included from %s:%d:\n",
                (*pf)->filename, (*pf)->line_num);
        if (s1->error_set_jmp_enabled) {
            strcat_printf(buf, sizeof(buf), "%s:%d: ",
                f->filename, f->line_num - !!(tok_flags & TOK_FLAG_BOL));
        } else {
            strcat_printf(buf, sizeof(buf), "%s: ",
                f->filename);
        }
    } else {
        strcat_printf(buf, sizeof(buf), "nld: ");
    }
    if (is_warning)
        strcat_printf(buf, sizeof(buf), "warning: ");
    else
        strcat_printf(buf, sizeof(buf), "error: ");
    strcat_vprintf(buf, sizeof(buf), fmt, ap);

    if (!s1->error_func) {
        /* default case: stderr */
        if (s1->output_type == NILDO_OUTPUT_PREPROCESS && s1->ppfp == stdout)
            /* print a newline during nld -E */
            printf("\n"), fflush(stdout);
        fflush(stdout); /* flush -v output */
        fprintf(stderr, "%s\n", buf);
        fflush(stderr); /* print error/warning now (win32) */
    } else {
        s1->error_func(s1->error_opaque, buf);
    }
    if (!is_warning || s1->warn_error)
        s1->nb_errors++;
}

LIBNILDOAPI void nld_set_error_func(NILDOState *s, void *error_opaque,
                        void (*error_func)(void *opaque, const char *msg))
{
    s->error_opaque = error_opaque;
    s->error_func = error_func;
}

/* error without aborting current compilation */
PUB_FUNC void nld_error_noabort(const char *fmt, ...)
{
    NILDOState *s1 = nld_state;
    va_list ap;

    va_start(ap, fmt);
    error1(s1, 0, fmt, ap);
    va_end(ap);
}

PUB_FUNC void nld_error(const char *fmt, ...)
{
    NILDOState *s1 = nld_state;
    va_list ap;

    va_start(ap, fmt);
    error1(s1, 0, fmt, ap);
    va_end(ap);
    /* better than nothing: in some cases, we accept to handle errors */
    if (s1->error_set_jmp_enabled) {
        longjmp(s1->error_jmp_buf, 1);
    } else {
        /* XXX: eliminate this someday */
        exit(1);
    }
}

PUB_FUNC void nld_warning(const char *fmt, ...)
{
    NILDOState *s1 = nld_state;
    va_list ap;

    if (s1->warn_none)
        return;

    va_start(ap, fmt);
    error1(s1, 1, fmt, ap);
    va_end(ap);
}

/********************************************************/
/* I/O layer */

ST_FUNC void nld_open_bf(NILDOState *s1, const char *filename, int initlen)
{
    BufferedFile *bf;
    int buflen = initlen ? initlen : IO_BUF_SIZE;

    bf = nld_mallocz(sizeof(BufferedFile) + buflen);
    bf->buf_ptr = bf->buffer;
    bf->buf_end = bf->buffer + initlen;
    bf->buf_end[0] = CH_EOB; /* put eob symbol */
    pstrcpy(bf->filename, sizeof(bf->filename), filename);
    bf->true_filename = bf->filename;
    bf->line_num = 1;
    bf->ifdef_stack_ptr = s1->ifdef_stack_ptr;
    bf->fd = -1;
    bf->prev = file;
    file = bf;
    tok_flags = TOK_FLAG_BOL | TOK_FLAG_BOF;
}

ST_FUNC void nld_close(void)
{
    BufferedFile *bf = file;
    if (bf->fd > 0) {
        close(bf->fd);
        total_lines += bf->line_num;
    }
    if (bf->true_filename != bf->filename)
        nld_free(bf->true_filename);
    file = bf->prev;
    nld_free(bf);
}

ST_FUNC int nld_open(NILDOState *s1, const char *filename)
{
    int fd;
    if (strcmp(filename, "-") == 0)
        fd = 0, filename = "<stdin>";
    else
        fd = open(filename, O_RDONLY | O_BINARY);
    if ((s1->verbose == 2 && fd >= 0) || s1->verbose == 3)
        printf("%s %*s%s\n", fd < 0 ? "nf":"->",
               (int)(s1->include_stack_ptr - s1->include_stack), "", filename);
    if (fd < 0)
        return -1;
    nld_open_bf(s1, filename, 0);
#ifdef _WIN32
    normalize_slashes(file->filename);
#endif
    file->fd = fd;
    return fd;
}

/* compile the file opened in 'file'. Return non zero if errors. */
static int nld_compile(NILDOState *s1)
{
    Sym *define_start;
    int filetype, is_asm;

    define_start = define_stack;
    filetype = s1->filetype;
    is_asm = filetype == AFF_TYPE_ASM || filetype == AFF_TYPE_ASMPP;
    nldelf_begin_file(s1);

    if (setjmp(s1->error_jmp_buf) == 0) {
        s1->nb_errors = 0;
        s1->error_set_jmp_enabled = 1;

        preprocess_start(s1, is_asm);
        if (s1->output_type == NILDO_OUTPUT_PREPROCESS) {
            nld_preprocess(s1);
        } else if (is_asm) {
#ifdef CONFIG_NILDO_ASM
            nld_assemble(s1, filetype == AFF_TYPE_ASMPP);
#else
            nld_error_noabort("asm not supported");
#endif
        } else {
            nldgen_compile(s1);
        }
    }
    s1->error_set_jmp_enabled = 0;

    preprocess_end(s1);
    free_inline_functions(s1);
    /* reset define stack, but keep -D and built-ins */
    free_defines(define_start);
    sym_pop(&global_stack, NULL, 0);
    sym_pop(&local_stack, NULL, 0);
    nldelf_end_file(s1);
    return s1->nb_errors != 0 ? -1 : 0;
}

LIBNILDOAPI int nld_compile_string(NILDOState *s, const char *str)
{
    int len, ret;

    len = strlen(str);
    nld_open_bf(s, "<string>", len);
    memcpy(file->buffer, str, len);
    ret = nld_compile(s);
    nld_close();
    return ret;
}

/* define a preprocessor symbol. A value can also be provided with the '=' operator */
LIBNILDOAPI void nld_define_symbol(NILDOState *s1, const char *sym, const char *value)
{
    int len1, len2;
    /* default value */
    if (!value)
        value = "1";
    len1 = strlen(sym);
    len2 = strlen(value);

    /* init file structure */
    nld_open_bf(s1, "<define>", len1 + len2 + 1);
    memcpy(file->buffer, sym, len1);
    file->buffer[len1] = ' ';
    memcpy(file->buffer + len1 + 1, value, len2);

    /* parse with define parser */
    next_nomacro();
    parse_define();
    nld_close();
}

/* undefine a preprocessor symbol */
LIBNILDOAPI void nld_undefine_symbol(NILDOState *s1, const char *sym)
{
    TokenSym *ts;
    Sym *s;
    ts = tok_alloc(sym, strlen(sym));
    s = define_find(ts->tok);
    /* undefine symbol by putting an invalid name */
    if (s)
        define_undef(s);
}

/* cleanup all static data used during compilation */
static void nld_cleanup(void)
{
    if (NULL == nld_state)
        return;
    while (file)
        nld_close();
    nldpp_delete(nld_state);
    nld_state = NULL;
    /* free sym_pools */
    dynarray_reset(&sym_pools, &nb_sym_pools);
    /* reset symbol stack */
    sym_free_first = NULL;
}

LIBNILDOAPI NILDOState *nld_new(void)
{
    NILDOState *s;

    nld_cleanup();

    s = nld_mallocz(sizeof(NILDOState));
    if (!s)
        return NULL;
    nld_state = s;
    ++nb_states;

    s->alacarte_link = 1;
    s->nocommon = 1;
    s->warn_implicit_function_declaration = 1;
    s->ms_extensions = 1;

#ifdef CHAR_IS_UNSIGNED
    s->char_is_unsigned = 1;
#endif
#ifdef NILDO_TARGET_I386
    s->seg_size = 32;
#endif
    /* enable this if you want symbols with leading underscore on windows: */
#if 0 /* def NILDO_TARGET_PE */
    s->leading_underscore = 1;
#endif
#ifdef _WIN32
    nld_set_lib_path_w32(s);
#else
    nld_set_lib_path(s, CONFIG_NILDODIR);
#endif
    nldelf_new(s);
    nldpp_new(s);

    /* we add dummy defines for some special macros to speed up tests
       and to have working defined() */
    define_push(TOK___LINE__, MACRO_OBJ, NULL, NULL);
    define_push(TOK___FILE__, MACRO_OBJ, NULL, NULL);
    define_push(TOK___DATE__, MACRO_OBJ, NULL, NULL);
    define_push(TOK___TIME__, MACRO_OBJ, NULL, NULL);
    define_push(TOK___COUNTER__, MACRO_OBJ, NULL, NULL);
    {
        /* define __TINYC__ 92X  */
        char buffer[32]; int a,b,c;
        sscanf(NILDO_VERSION, "%d.%d.%d", &a, &b, &c);
        sprintf(buffer, "%d", a*10000 + b*100 + c);
        nld_define_symbol(s, "__TINYC__", buffer);
    }

    /* standard defines */
    nld_define_symbol(s, "__STDC__", NULL);
    nld_define_symbol(s, "__STDC_VERSION__", "199901L");
    nld_define_symbol(s, "__STDC_HOSTED__", NULL);

    /* target defines */
#if defined(NILDO_TARGET_I386)
    nld_define_symbol(s, "__i386__", NULL);
    nld_define_symbol(s, "__i386", NULL);
    nld_define_symbol(s, "i386", NULL);
#elif defined(NILDO_TARGET_X86_64)
    nld_define_symbol(s, "__x86_64__", NULL);
#elif defined(NILDO_TARGET_ARM)
    nld_define_symbol(s, "__ARM_ARCH_4__", NULL);
    nld_define_symbol(s, "__arm_elf__", NULL);
    nld_define_symbol(s, "__arm_elf", NULL);
    nld_define_symbol(s, "arm_elf", NULL);
    nld_define_symbol(s, "__arm__", NULL);
    nld_define_symbol(s, "__arm", NULL);
    nld_define_symbol(s, "arm", NULL);
    nld_define_symbol(s, "__APCS_32__", NULL);
    nld_define_symbol(s, "__ARMEL__", NULL);
#if defined(NILDO_ARM_EABI)
    nld_define_symbol(s, "__ARM_EABI__", NULL);
#endif
#if defined(NILDO_ARM_HARDFLOAT)
    s->float_abi = ARM_HARD_FLOAT;
    nld_define_symbol(s, "__ARM_PCS_VFP", NULL);
#else
    s->float_abi = ARM_SOFTFP_FLOAT;
#endif
#elif defined(NILDO_TARGET_ARM64)
    nld_define_symbol(s, "__aarch64__", NULL);
#elif defined NILDO_TARGET_C67
    nld_define_symbol(s, "__C67__", NULL);
#endif

#ifdef NILDO_TARGET_PE
    nld_define_symbol(s, "_WIN32", NULL);
# ifdef NILDO_TARGET_X86_64
    nld_define_symbol(s, "_WIN64", NULL);
# endif
#else
    nld_define_symbol(s, "__unix__", NULL);
    nld_define_symbol(s, "__unix", NULL);
    nld_define_symbol(s, "unix", NULL);
# if defined(__linux__)
    nld_define_symbol(s, "__linux__", NULL);
    nld_define_symbol(s, "__linux", NULL);
# endif
# if defined(__FreeBSD__)
    nld_define_symbol(s, "__FreeBSD__", "__FreeBSD__");
    /* No 'Thread Storage Local' on FreeBSD with nld */
    nld_define_symbol(s, "__NO_TLS", NULL);
# endif
# if defined(__FreeBSD_kernel__)
    nld_define_symbol(s, "__FreeBSD_kernel__", NULL);
# endif
# if defined(__NetBSD__)
    nld_define_symbol(s, "__NetBSD__", "__NetBSD__");
# endif
# if defined(__OpenBSD__)
    nld_define_symbol(s, "__OpenBSD__", "__OpenBSD__");
# endif
#endif

    /* Nildo & gcc defines */
#if PTR_SIZE == 4
    /* 32bit systems. */
    nld_define_symbol(s, "TAMANHO", "Natural Inteiro");
    nld_define_symbol(s, "DIFERENÇA", "Inteiro");
    nld_define_symbol(s, "__ILP32__", NULL);
#elif LONG_SIZE == 4
    /* 64bit Windows. */
    nld_define_symbol(s, "TAMANHO", "Natural Longo Longo");
    nld_define_symbol(s, "DIFERENÇA", "Longo Longo");
    nld_define_symbol(s, "__LLP64__", NULL);
#else
    /* Other 64bit systems. */
    nld_define_symbol(s, "TAMANHO", "Natural Longo");
    nld_define_symbol(s, "DIFERENÇA", "Longo");
    nld_define_symbol(s, "__LP64__", NULL);
#endif

#ifdef NILDO_TARGET_PE
    nld_define_symbol(s, "CARACTERE_MAIOR", "Natural Curto");
    nld_define_symbol(s, "INTEIRO", "Natural Curto");
#else
    nld_define_symbol(s, "CARACTERE_MAIOR", "Inteiro");
    /* wint_t is unsigned int by default, but (signed) int on BSDs
       and unsigned short on windows.  Other OSes might have still
       other conventions, sigh.  */
# if defined(__FreeBSD__) || defined (__FreeBSD_kernel__) \
  || defined(__NetBSD__) || defined(__OpenBSD__)
    nld_define_symbol(s, "INTEIRO", "Inteiro");
#  ifdef __FreeBSD__
    /* define __GNUC__ to have some useful stuff from sys/cdefs.h
       that are unconditionally used in FreeBSDs other system headers :/ */
    nld_define_symbol(s, "__GNUC__", "2");
    nld_define_symbol(s, "__GNUC_MINOR__", "7");
    nld_define_symbol(s, "__builtin_alloca", "alloca");
#  endif
# else
    nld_define_symbol(s, "INTEIRO", "Natural Inteiro");
    /* glibc defines */
    nld_define_symbol(s, "__REDIRECT(name, proto, alias)",
        "name proto __asm__ (#alias)");
    nld_define_symbol(s, "__REDIRECT_NTH(name, proto, alias)",
        "name proto __asm__ (#alias) __THROW");
# endif
# if defined(NILDO_MUSL)
    nld_define_symbol(s, "__DEFINED_va_list", "");
    nld_define_symbol(s, "__DEFINED___isoc_va_list", "");
    nld_define_symbol(s, "__isoc_va_list", "Vazio *");
# endif /* NILDO_MUSL */
    /* Some GCC builtins that are simple to express as macros.  */
    nld_define_symbol(s, "__builtin_extract_return_addr(x)", "x");
#endif /* ndef NILDO_TARGET_PE */
    return s;
}

LIBNILDOAPI void nld_delete(NILDOState *s1)
{
    nld_cleanup();

    /* free sections */
    nldelf_delete(s1);

    /* free library paths */
    dynarray_reset(&s1->library_paths, &s1->nb_library_paths);
    dynarray_reset(&s1->crt_paths, &s1->nb_crt_paths);

    /* free include paths */
    dynarray_reset(&s1->cached_includes, &s1->nb_cached_includes);
    dynarray_reset(&s1->include_paths, &s1->nb_include_paths);
    dynarray_reset(&s1->sysinclude_paths, &s1->nb_sysinclude_paths);
    dynarray_reset(&s1->cmd_include_files, &s1->nb_cmd_include_files);

    nld_free(s1->nld_lib_path);
    nld_free(s1->soname);
    nld_free(s1->rpath);
    nld_free(s1->init_symbol);
    nld_free(s1->fini_symbol);
    nld_free(s1->outfile);
    nld_free(s1->deps_outfile);
    dynarray_reset(&s1->files, &s1->nb_files);
    dynarray_reset(&s1->target_deps, &s1->nb_target_deps);
    dynarray_reset(&s1->pragma_libs, &s1->nb_pragma_libs);
    dynarray_reset(&s1->argv, &s1->argc);

#ifdef NILDO_IS_NATIVE
    /* free runtime memory */
    nld_run_free(s1);
#endif

    nld_free(s1);
    if (0 == --nb_states)
        nld_memcheck();
}

LIBNILDOAPI int nld_set_output_type(NILDOState *s, int output_type)
{
    s->output_type = output_type;

    /* always elf for objects */
    if (output_type == NILDO_OUTPUT_OBJ)
        s->output_format = NILDO_OUTPUT_FORMAT_ELF;

    if (s->char_is_unsigned)
        nld_define_symbol(s, "__CHAR_UNSIGNED__", NULL);

    if (!s->nostdinc) {
        /* default include paths */
        /* -isystem paths have already been handled */
        nld_add_sysinclude_path(s, CONFIG_NILDO_SYSINCLUDEPATHS);
    }

#ifdef CONFIG_NILDO_BCHECK
    if (s->do_bounds_check) {
        /* if bound checking, then add corresponding sections */
        nldelf_bounds_new(s);
        /* define symbol */
        nld_define_symbol(s, "__BOUNDS_CHECKING_ON", NULL);
    }
#endif
    if (s->do_debug) {
        /* add debug sections */
        nldelf_stab_new(s);
    }

    nld_add_library_path(s, CONFIG_NILDO_LIBPATHS);

#ifdef NILDO_TARGET_PE
# ifdef _WIN32
    if (!s->nostdlib && output_type != NILDO_OUTPUT_OBJ)
        nld_add_systemdir(s);
# endif
#else
    /* paths for crt objects */
    nld_split_path(s, &s->crt_paths, &s->nb_crt_paths, CONFIG_NILDO_CRTPREFIX);
    /* add libc crt1/crti objects */
    if ((output_type == NILDO_OUTPUT_EXE || output_type == NILDO_OUTPUT_DLL) &&
        !s->nostdlib) {
        if (output_type != NILDO_OUTPUT_DLL)
            nld_add_crt(s, "crt1.o");
        nld_add_crt(s, "crti.o");
    }
#endif
    return 0;
}

LIBNILDOAPI int nld_add_include_path(NILDOState *s, const char *pathname)
{
    nld_split_path(s, &s->include_paths, &s->nb_include_paths, pathname);
    return 0;
}

LIBNILDOAPI int nld_add_sysinclude_path(NILDOState *s, const char *pathname)
{
    nld_split_path(s, &s->sysinclude_paths, &s->nb_sysinclude_paths, pathname);
    return 0;
}

ST_FUNC int nld_add_file_internal(NILDOState *s1, const char *filename, int flags)
{
    int ret;

    /* open the file */
    ret = nld_open(s1, filename);
    if (ret < 0) {
        if (flags & AFF_PRINT_ERROR)
            nld_error_noabort("file '%s' not found", filename);
        return ret;
    }

    /* update target deps */
    dynarray_add(&s1->target_deps, &s1->nb_target_deps,
            nld_strdup(filename));

    if (flags & AFF_TYPE_BIN) {
        ElfW(Ehdr) ehdr;
        int fd, obj_type;

        fd = file->fd;
        obj_type = nld_object_type(fd, &ehdr);
        lseek(fd, 0, SEEK_SET);

#ifdef NILDO_TARGET_MACHO
        if (0 == obj_type && 0 == strcmp(nld_fileextension(filename), ".dylib"))
            obj_type = AFF_BINTYPE_DYN;
#endif

        switch (obj_type) {
        case AFF_BINTYPE_REL:
            ret = nld_load_object_file(s1, fd, 0);
            break;
#ifndef NILDO_TARGET_PE
        case AFF_BINTYPE_DYN:
            if (s1->output_type == NILDO_OUTPUT_MEMORY) {
                ret = 0;
#ifdef NILDO_IS_NATIVE
                if (NULL == dlopen(filename, RTLD_GLOBAL | RTLD_LAZY))
                    ret = -1;
#endif
            } else {
                ret = nld_load_dll(s1, fd, filename,
                                   (flags & AFF_REFERENCED_DLL) != 0);
            }
            break;
#endif
        case AFF_BINTYPE_AR:
            ret = nld_load_archive(s1, fd);
            break;
#ifdef NILDO_TARGET_COFF
        case AFF_BINTYPE_C67:
            ret = nld_load_coff(s1, fd);
            break;
#endif
        default:
#ifdef NILDO_TARGET_PE
            ret = pe_load_file(s1, filename, fd);
#else
            /* as GNU ld, consider it is an ld script if not recognized */
            ret = nld_load_ldscript(s1);
#endif
            if (ret < 0)
                nld_error_noabort("unrecognized file type");
            break;
        }
    } else {
        ret = nld_compile(s1);
    }
    nld_close();
    return ret;
}

LIBNILDOAPI int nld_add_file(NILDOState *s, const char *filename)
{
    int filetype = s->filetype;
    int flags = AFF_PRINT_ERROR;
    if (filetype == 0) {
        /* use a file extension to detect a filetype */
        const char *ext = nld_fileextension(filename);
        if (ext[0]) {
            ext++;
            if (!strcmp(ext, "S"))
                filetype = AFF_TYPE_ASMPP;
            else if (!strcmp(ext, "s"))
                filetype = AFF_TYPE_ASM;
            else if (!PATHCMP(ext, "nld") || !PATHCMP(ext, "i"))
                filetype = AFF_TYPE_C;
            else
                flags |= AFF_TYPE_BIN;
        } else {
            filetype = AFF_TYPE_C;
        }
        s->filetype = filetype;
    }
    return nld_add_file_internal(s, filename, flags);
}

LIBNILDOAPI int nld_add_library_path(NILDOState *s, const char *pathname)
{
    nld_split_path(s, &s->library_paths, &s->nb_library_paths, pathname);
    return 0;
}

static int nld_add_library_internal(NILDOState *s, const char *fmt,
    const char *filename, int flags, char **paths, int nb_paths)
{
    char buf[1024];
    int i;

    for(i = 0; i < nb_paths; i++) {
        snprintf(buf, sizeof(buf), fmt, paths[i], filename);
        if (nld_add_file_internal(s, buf, flags | AFF_TYPE_BIN) == 0)
            return 0;
    }
    return -1;
}

/* find and load a dll. Return non zero if not found */
/* XXX: add '-rpath' option support ? */
ST_FUNC int nld_add_dll(NILDOState *s, const char *filename, int flags)
{
    return nld_add_library_internal(s, "%s/%s", filename, flags,
        s->library_paths, s->nb_library_paths);
}

ST_FUNC int nld_add_crt(NILDOState *s, const char *filename)
{
    if (-1 == nld_add_library_internal(s, "%s/%s",
        filename, 0, s->crt_paths, s->nb_crt_paths))
        nld_error_noabort("file '%s' not found", filename);
    return 0;
}

/* the library name is the same as the argument of the '-l' option */
LIBNILDOAPI int nld_add_library(NILDOState *s, const char *libraryname)
{
#if defined NILDO_TARGET_PE
    const char *libs[] = { "%s/%s.def", "%s/lib%s.def", "%s/%s.dll", "%s/lib%s.dll", "%s/lib%s.a", NULL };
    const char **pp = s->static_link ? libs + 4 : libs;
#elif defined NILDO_TARGET_MACHO
    const char *libs[] = { "%s/lib%s.dylib", "%s/lib%s.a", NULL };
    const char **pp = s->static_link ? libs + 1 : libs;
#else
    const char *libs[] = { "%s/lib%s.so", "%s/lib%s.a", NULL };
    const char **pp = s->static_link ? libs + 1 : libs;
#endif
    while (*pp) {
        if (0 == nld_add_library_internal(s, *pp,
            libraryname, 0, s->library_paths, s->nb_library_paths))
            return 0;
        ++pp;
    }
    return -1;
}

PUB_FUNC int nld_add_library_err(NILDOState *s, const char *libname)
{
    int ret = nld_add_library(s, libname);
    if (ret < 0)
        nld_error_noabort("library '%s' not found", libname);
    return ret;
}

/* handle #pragma comment(lib,) */
ST_FUNC void nld_add_pragma_libs(NILDOState *s1)
{
    int i;
    for (i = 0; i < s1->nb_pragma_libs; i++)
        nld_add_library_err(s1, s1->pragma_libs[i]);
}

LIBNILDOAPI int nld_add_symbol(NILDOState *s, const char *name, const void *val)
{
#ifdef NILDO_TARGET_PE
    /* On x86_64 'val' might not be reachable with a 32bit offset.
       So it is handled here as if it were in a DLL. */
    pe_putimport(s, 0, name, (uintptr_t)val);
#else
    set_elf_sym(symtab_section, (uintptr_t)val, 0,
        ELFW(ST_INFO)(STB_GLOBAL, STT_NOTYPE), 0,
        SHN_ABS, name);
#endif
    return 0;
}

LIBNILDOAPI void nld_set_lib_path(NILDOState *s, const char *path)
{
    nld_free(s->nld_lib_path);
    s->nld_lib_path = nld_strdup(path);
}

#define WD_ALL    0x0001 /* warning is activated when using -Wall */
#define FD_INVERT 0x0002 /* invert value before storing */

typedef struct FlagDef {
    uint16_t offset;
    uint16_t flags;
    const char *name;
} FlagDef;

static int no_flag(const char **pp)
{
    const char *p = *pp;
    if (*p != 'n' || *++p != 'o' || *++p != '-')
        return 0;
    *pp = p + 1;
    return 1;
}

ST_FUNC int set_flag(NILDOState *s, const FlagDef *flags, const char *name)
{
    int value, ret;
    const FlagDef *p;
    const char *r;

    value = 1;
    r = name;
    if (no_flag(&r))
        value = 0;

    for (ret = -1, p = flags; p->name; ++p) {
        if (ret) {
            if (strcmp(r, p->name))
                continue;
        } else {
            if (0 == (p->flags & WD_ALL))
                continue;
        }
        if (p->offset) {
            *(int*)((char *)s + p->offset) =
                p->flags & FD_INVERT ? !value : value;
            if (ret)
                return 0;
        } else {
            ret = 0;
        }
    }
    return ret;
}

static int strstart(const char *val, const char **str)
{
    const char *p, *q;
    p = *str;
    q = val;
    while (*q) {
        if (*p != *q)
            return 0;
        p++;
        q++;
    }
    *str = p;
    return 1;
}

/* Like strstart, but automatically takes into account that ld options can
 *
 * - start with double or single dash (e.g. '--soname' or '-soname')
 * - arguments can be given as separate or after '=' (e.g. '-Wl,-soname,x.so'
 *   or '-Wl,-soname=x.so')
 *
 * you provide `val` always in 'option[=]' form (no leading -)
 */
static int link_option(const char *str, const char *val, const char **ptr)
{
    const char *p, *q;
    int ret;

    /* there should be 1 or 2 dashes */
    if (*str++ != '-')
        return 0;
    if (*str == '-')
        str++;

    /* then str & val should match (potentially up to '=') */
    p = str;
    q = val;

    ret = 1;
    if (q[0] == '?') {
        ++q;
        if (no_flag(&p))
            ret = -1;
    }

    while (*q != '\0' && *q != '=') {
        if (*p != *q)
            return 0;
        p++;
        q++;
    }

    /* '=' near eos means ',' or '=' is ok */
    if (*q == '=') {
        if (*p == 0)
            *ptr = p;
        if (*p != ',' && *p != '=')
            return 0;
        p++;
    } else if (*p) {
        return 0;
    }
    *ptr = p;
    return ret;
}

static const char *skip_linker_arg(const char **str)
{
    const char *s1 = *str;
    const char *s2 = strchr(s1, ',');
    *str = s2 ? s2++ : (s2 = s1 + strlen(s1));
    return s2;
}

static void copy_linker_arg(char **pp, const char *s, int sep)
{
    const char *q = s;
    char *p = *pp;
    int l = 0;
    if (p && sep)
        p[l = strlen(p)] = sep, ++l;
    skip_linker_arg(&q);
    pstrncpy(l + (*pp = nld_realloc(p, q - s + l + 1)), s, q - s);
}

/* set linker options */
static int nld_set_linker(NILDOState *s, const char *option)
{
    while (*option) {

        const char *p = NULL;
        char *end = NULL;
        int ignoring = 0;
        int ret;

        if (link_option(option, "Bsymbolic", &p)) {
            s->symbolic = 1;
        } else if (link_option(option, "nostdlib", &p)) {
            s->nostdlib = 1;
        } else if (link_option(option, "fini=", &p)) {
            copy_linker_arg(&s->fini_symbol, p, 0);
            ignoring = 1;
        } else if (link_option(option, "image-base=", &p)
                || link_option(option, "Ttext=", &p)) {
            s->text_addr = strtoull(p, &end, 16);
            s->has_text_addr = 1;
        } else if (link_option(option, "init=", &p)) {
            copy_linker_arg(&s->init_symbol, p, 0);
            ignoring = 1;
        } else if (link_option(option, "oformat=", &p)) {
#if defined(NILDO_TARGET_PE)
            if (strstart("pe-", &p)) {
#elif PTR_SIZE == 8
            if (strstart("elf64-", &p)) {
#else
            if (strstart("elf32-", &p)) {
#endif
                s->output_format = NILDO_OUTPUT_FORMAT_ELF;
            } else if (!strcmp(p, "binary")) {
                s->output_format = NILDO_OUTPUT_FORMAT_BINARY;
#ifdef NILDO_TARGET_COFF
            } else if (!strcmp(p, "coff")) {
                s->output_format = NILDO_OUTPUT_FORMAT_COFF;
#endif
            } else
                goto err;

        } else if (link_option(option, "as-needed", &p)) {
            ignoring = 1;
        } else if (link_option(option, "O", &p)) {
            ignoring = 1;
        } else if (link_option(option, "export-all-symbols", &p)) {
            s->rdynamic = 1;
        } else if (link_option(option, "rpath=", &p)) {
            copy_linker_arg(&s->rpath, p, ':');
        } else if (link_option(option, "enable-new-dtags", &p)) {
            s->enable_new_dtags = 1;
        } else if (link_option(option, "section-alignment=", &p)) {
            s->section_align = strtoul(p, &end, 16);
        } else if (link_option(option, "soname=", &p)) {
            copy_linker_arg(&s->soname, p, 0);
#ifdef NILDO_TARGET_PE
        } else if (link_option(option, "large-address-aware", &p)) {
            s->pe_characteristics |= 0x20;
        } else if (link_option(option, "file-alignment=", &p)) {
            s->pe_file_align = strtoul(p, &end, 16);
        } else if (link_option(option, "stack=", &p)) {
            s->pe_stack_size = strtoul(p, &end, 10);
        } else if (link_option(option, "subsystem=", &p)) {
#if defined(NILDO_TARGET_I386) || defined(NILDO_TARGET_X86_64)
            if (!strcmp(p, "native")) {
                s->pe_subsystem = 1;
            } else if (!strcmp(p, "console")) {
                s->pe_subsystem = 3;
            } else if (!strcmp(p, "gui") || !strcmp(p, "windows")) {
                s->pe_subsystem = 2;
            } else if (!strcmp(p, "posix")) {
                s->pe_subsystem = 7;
            } else if (!strcmp(p, "efiapp")) {
                s->pe_subsystem = 10;
            } else if (!strcmp(p, "efiboot")) {
                s->pe_subsystem = 11;
            } else if (!strcmp(p, "efiruntime")) {
                s->pe_subsystem = 12;
            } else if (!strcmp(p, "efirom")) {
                s->pe_subsystem = 13;
#elif defined(NILDO_TARGET_ARM)
            if (!strcmp(p, "wince")) {
                s->pe_subsystem = 9;
#endif
            } else
                goto err;
#endif
        } else if (ret = link_option(option, "?whole-archive", &p), ret) {
            s->alacarte_link = ret < 0;
        } else if (p) {
            return 0;
        } else {
    err:
            nld_error("unsupported linker option '%s'", option);
        }

        if (ignoring && s->warn_unsupported)
            nld_warning("unsupported linker option '%s'", option);

        option = skip_linker_arg(&p);
    }
    return 1;
}

typedef struct NILDOOption {
    const char *name;
    uint16_t index;
    uint16_t flags;
} NILDOOption;

enum {
    NILDO_OPTION_HELP,
    NILDO_OPTION_HELP2,
    NILDO_OPTION_v,
    NILDO_OPTION_I,
    NILDO_OPTION_D,
    NILDO_OPTION_U,
    NILDO_OPTION_P,
    NILDO_OPTION_L,
    NILDO_OPTION_B,
    NILDO_OPTION_l,
    NILDO_OPTION_bench,
    NILDO_OPTION_bt,
    NILDO_OPTION_b,
    NILDO_OPTION_g,
    NILDO_OPTION_c,
    NILDO_OPTION_dumpversion,
    NILDO_OPTION_d,
    NILDO_OPTION_static,
    NILDO_OPTION_std,
    NILDO_OPTION_shared,
    NILDO_OPTION_soname,
    NILDO_OPTION_o,
    NILDO_OPTION_r,
    NILDO_OPTION_s,
    NILDO_OPTION_traditional,
    NILDO_OPTION_Wl,
    NILDO_OPTION_Wp,
    NILDO_OPTION_W,
    NILDO_OPTION_O,
    NILDO_OPTION_mfloat_abi,
    NILDO_OPTION_m,
    NILDO_OPTION_f,
    NILDO_OPTION_isystem,
    NILDO_OPTION_iwithprefix,
    NILDO_OPTION_include,
    NILDO_OPTION_nostdinc,
    NILDO_OPTION_nostdlib,
    NILDO_OPTION_print_search_dirs,
    NILDO_OPTION_rdynamic,
    NILDO_OPTION_param,
    NILDO_OPTION_pedantic,
    NILDO_OPTION_pthread,
    NILDO_OPTION_run,
    NILDO_OPTION_w,
    NILDO_OPTION_pipe,
    NILDO_OPTION_E,
    NILDO_OPTION_MD,
    NILDO_OPTION_MF,
    NILDO_OPTION_x,
    NILDO_OPTION_ar,
    NILDO_OPTION_impdef
};

#define NILDO_OPTION_HAS_ARG 0x0001
#define NILDO_OPTION_NOSEP   0x0002 /* cannot have space before option and arg */

static const NILDOOption nld_options[] = {
    { "h", NILDO_OPTION_HELP, 0 },
    { "-help", NILDO_OPTION_HELP, 0 },
    { "?", NILDO_OPTION_HELP, 0 },
    { "hh", NILDO_OPTION_HELP2, 0 },
    { "v", NILDO_OPTION_v, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
    { "I", NILDO_OPTION_I, NILDO_OPTION_HAS_ARG },
    { "D", NILDO_OPTION_D, NILDO_OPTION_HAS_ARG },
    { "U", NILDO_OPTION_U, NILDO_OPTION_HAS_ARG },
    { "P", NILDO_OPTION_P, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
    { "L", NILDO_OPTION_L, NILDO_OPTION_HAS_ARG },
    { "B", NILDO_OPTION_B, NILDO_OPTION_HAS_ARG },
    { "l", NILDO_OPTION_l, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
    { "bench", NILDO_OPTION_bench, 0 },
#ifdef CONFIG_NILDO_BACKTRACE
    { "bt", NILDO_OPTION_bt, NILDO_OPTION_HAS_ARG },
#endif
#ifdef CONFIG_NILDO_BCHECK
    { "b", NILDO_OPTION_b, 0 },
#endif
    { "g", NILDO_OPTION_g, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
    { "c", NILDO_OPTION_c, 0 },
    { "dumpversion", NILDO_OPTION_dumpversion, 0},
    { "d", NILDO_OPTION_d, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
    { "static", NILDO_OPTION_static, 0 },
    { "std", NILDO_OPTION_std, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
    { "shared", NILDO_OPTION_shared, 0 },
    { "soname", NILDO_OPTION_soname, NILDO_OPTION_HAS_ARG },
    { "o", NILDO_OPTION_o, NILDO_OPTION_HAS_ARG },
    { "-param", NILDO_OPTION_param, NILDO_OPTION_HAS_ARG },
    { "pedantic", NILDO_OPTION_pedantic, 0},
    { "pthread", NILDO_OPTION_pthread, 0},
    { "run", NILDO_OPTION_run, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
    { "rdynamic", NILDO_OPTION_rdynamic, 0 },
    { "r", NILDO_OPTION_r, 0 },
    { "s", NILDO_OPTION_s, 0 },
    { "traditional", NILDO_OPTION_traditional, 0 },
    { "Wl,", NILDO_OPTION_Wl, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
    { "Wp,", NILDO_OPTION_Wp, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
    { "W", NILDO_OPTION_W, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
    { "O", NILDO_OPTION_O, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
#ifdef NILDO_TARGET_ARM
    { "mfloat-abi", NILDO_OPTION_mfloat_abi, NILDO_OPTION_HAS_ARG },
#endif
    { "m", NILDO_OPTION_m, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
    { "f", NILDO_OPTION_f, NILDO_OPTION_HAS_ARG | NILDO_OPTION_NOSEP },
    { "isystem", NILDO_OPTION_isystem, NILDO_OPTION_HAS_ARG },
    { "include", NILDO_OPTION_include, NILDO_OPTION_HAS_ARG },
    { "nostdinc", NILDO_OPTION_nostdinc, 0 },
    { "nostdlib", NILDO_OPTION_nostdlib, 0 },
    { "print-search-dirs", NILDO_OPTION_print_search_dirs, 0 },
    { "w", NILDO_OPTION_w, 0 },
    { "pipe", NILDO_OPTION_pipe, 0},
    { "E", NILDO_OPTION_E, 0},
    { "MD", NILDO_OPTION_MD, 0},
    { "MF", NILDO_OPTION_MF, NILDO_OPTION_HAS_ARG },
    { "x", NILDO_OPTION_x, NILDO_OPTION_HAS_ARG },
    { "ar", NILDO_OPTION_ar, 0},
#ifdef NILDO_TARGET_PE
    { "impdef", NILDO_OPTION_impdef, 0},
#endif
    { NULL, 0, 0 },
};

static const FlagDef options_W[] = {
    { 0, 0, "all" },
    { offsetof(NILDOState, warn_unsupported), 0, "unsupported" },
    { offsetof(NILDOState, warn_write_strings), 0, "write-strings" },
    { offsetof(NILDOState, warn_error), 0, "error" },
    { offsetof(NILDOState, warn_gcc_compat), 0, "gcc-compat" },
    { offsetof(NILDOState, warn_implicit_function_declaration), WD_ALL,
      "implicit-function-declaration" },
    { 0, 0, NULL }
};

static const FlagDef options_f[] = {
    { offsetof(NILDOState, char_is_unsigned), 0, "unsigned-char" },
    { offsetof(NILDOState, char_is_unsigned), FD_INVERT, "signed-char" },
    { offsetof(NILDOState, nocommon), FD_INVERT, "common" },
    { offsetof(NILDOState, leading_underscore), 0, "leading-underscore" },
    { offsetof(NILDOState, ms_extensions), 0, "ms-extensions" },
    { offsetof(NILDOState, dollars_in_identifiers), 0, "dollars-in-identifiers" },
    { 0, 0, NULL }
};

static const FlagDef options_m[] = {
    { offsetof(NILDOState, ms_bitfields), 0, "ms-bitfields" },
#ifdef NILDO_TARGET_X86_64
    { offsetof(NILDOState, nosse), FD_INVERT, "sse" },
#endif
    { 0, 0, NULL }
};

static void parse_option_D(NILDOState *s1, const char *optarg)
{
    char *sym = nld_strdup(optarg);
    char *value = strchr(sym, '=');
    if (value)
        *value++ = '\0';
    nld_define_symbol(s1, sym, value);
    nld_free(sym);
}

static void args_parser_add_file(NILDOState *s, const char* filename, int filetype)
{
    struct filespec *f = nld_malloc(sizeof *f + strlen(filename));
    f->type = filetype;
    f->alacarte = s->alacarte_link;
    strcpy(f->name, filename);
    dynarray_add(&s->files, &s->nb_files, f);
}

static int args_parser_make_argv(const char *r, int *argc, char ***argv)
{
    int ret = 0, q, c;
    CString str;
    for(;;) {
        while (c = (unsigned char)*r, c && c <= ' ')
	    ++r;
        if (c == 0)
            break;
        q = 0;
        cstr_new(&str);
        while (c = (unsigned char)*r, c) {
            ++r;
            if (c == '\\' && (*r == '"' || *r == '\\')) {
                c = *r++;
            } else if (c == '"') {
                q = !q;
                continue;
            } else if (q == 0 && c <= ' ') {
                break;
            }
            cstr_ccat(&str, c);
        }
        cstr_ccat(&str, 0);
        //printf("<%s>\n", str.data), fflush(stdout);
        dynarray_add(argv, argc, nld_strdup(str.data));
        cstr_free(&str);
        ++ret;
    }
    return ret;
}

/* read list file */
static void args_parser_listfile(NILDOState *s,
    const char *filename, int optind, int *pargc, char ***pargv)
{
    int fd, i;
    size_t len;
    char *p;
    int argc = 0;
    char **argv = NULL;

    fd = open(filename, O_RDONLY | O_BINARY);
    if (fd < 0)
        nld_error("listfile '%s' not found", filename);

    len = lseek(fd, 0, SEEK_END);
    p = nld_malloc(len + 1), p[len] = 0;
    lseek(fd, 0, SEEK_SET), read(fd, p, len), close(fd);

    for (i = 0; i < *pargc; ++i)
        if (i == optind)
            args_parser_make_argv(p, &argc, &argv);
        else
            dynarray_add(&argv, &argc, nld_strdup((*pargv)[i]));

    nld_free(p);
    dynarray_reset(&s->argv, &s->argc);
    *pargc = s->argc = argc, *pargv = s->argv = argv;
}

PUB_FUNC int nld_parse_args(NILDOState *s, int *pargc, char ***pargv, int optind)
{
    const NILDOOption *popt;
    const char *optarg, *r;
    const char *run = NULL;
    int last_o = -1;
    int x;
    CString linker_arg; /* collect -Wl options */
    int tool = 0, arg_start = 0, noaction = optind;
    char **argv = *pargv;
    int argc = *pargc;

    cstr_new(&linker_arg);

    while (optind < argc) {
        r = argv[optind];
        if (r[0] == '@' && r[1] != '\0') {
            args_parser_listfile(s, r + 1, optind, &argc, &argv);
	    continue;
        }
        optind++;
        if (tool) {
            if (r[0] == '-' && r[1] == 'v' && r[2] == 0)
                ++s->verbose;
            continue;
        }
reparse:
        if (r[0] != '-' || r[1] == '\0') {
            if (r[0] != '@') /* allow "nld file(s) -run @ args ..." */
                args_parser_add_file(s, r, s->filetype);
            if (run) {
                nld_set_options(s, run);
                arg_start = optind - 1;
                break;
            }
            continue;
        }

        /* find option in table */
        for(popt = nld_options; ; ++popt) {
            const char *p1 = popt->name;
            const char *r1 = r + 1;
            if (p1 == NULL)
                nld_error("invalid option -- '%s'", r);
            if (!strstart(p1, &r1))
                continue;
            optarg = r1;
            if (popt->flags & NILDO_OPTION_HAS_ARG) {
                if (*r1 == '\0' && !(popt->flags & NILDO_OPTION_NOSEP)) {
                    if (optind >= argc)
                arg_err:
                        nld_error("argument to '%s' is missing", r);
                    optarg = argv[optind++];
                }
            } else if (*r1 != '\0')
                continue;
            break;
        }

        switch(popt->index) {
        case NILDO_OPTION_HELP:
            return OPT_HELP;
        case NILDO_OPTION_HELP2:
            return OPT_HELP2;
        case NILDO_OPTION_I:
            nld_add_include_path(s, optarg);
            break;
        case NILDO_OPTION_D:
            parse_option_D(s, optarg);
            break;
        case NILDO_OPTION_U:
            nld_undefine_symbol(s, optarg);
            break;
        case NILDO_OPTION_L:
            nld_add_library_path(s, optarg);
            break;
        case NILDO_OPTION_B:
            /* set nld utilities path (mainly for nld development) */
            nld_set_lib_path(s, optarg);
            break;
        case NILDO_OPTION_l:
            args_parser_add_file(s, optarg, AFF_TYPE_LIB);
            s->nb_libraries++;
            break;
        case NILDO_OPTION_pthread:
            parse_option_D(s, "_REENTRANT");
            s->option_pthread = 1;
            break;
        case NILDO_OPTION_bench:
            s->do_bench = 1;
            break;
#ifdef CONFIG_NILDO_BACKTRACE
        case NILDO_OPTION_bt:
            nld_set_num_callers(atoi(optarg));
            break;
#endif
#ifdef CONFIG_NILDO_BCHECK
        case NILDO_OPTION_b:
            s->do_bounds_check = 1;
            s->do_debug = 1;
            break;
#endif
        case NILDO_OPTION_g:
            s->do_debug = 1;
            break;
        case NILDO_OPTION_c:
            x = NILDO_OUTPUT_OBJ;
        set_output_type:
            if (s->output_type)
                nld_warning("-%s: overriding compiler action already specified", popt->name);
            s->output_type = x;
            break;
        case NILDO_OPTION_d:
            if (*optarg == 'D')
                s->dflag = 3;
            else if (*optarg == 'M')
                s->dflag = 7;
            else if (*optarg == 't')
                s->dflag = 16;
            else if (isnum(*optarg))
                g_debug = atoi(optarg);
            else
                goto unsupported_option;
            break;
        case NILDO_OPTION_static:
            s->static_link = 1;
            break;
        case NILDO_OPTION_std:
    	    /* silently ignore, a current purpose:
    	       allow to use a nld as a reference compiler for "make test" */
            break;
        case NILDO_OPTION_shared:
            x = NILDO_OUTPUT_DLL;
            goto set_output_type;
        case NILDO_OPTION_soname:
            s->soname = nld_strdup(optarg);
            break;
        case NILDO_OPTION_o:
            if (s->outfile) {
                nld_warning("multiple -o option");
                nld_free(s->outfile);
            }
            s->outfile = nld_strdup(optarg);
            break;
        case NILDO_OPTION_r:
            /* generate a .o merging several output files */
            s->option_r = 1;
            x = NILDO_OUTPUT_OBJ;
            goto set_output_type;
        case NILDO_OPTION_isystem:
            nld_add_sysinclude_path(s, optarg);
            break;
	case NILDO_OPTION_include:
	    dynarray_add(&s->cmd_include_files,
			 &s->nb_cmd_include_files, nld_strdup(optarg));
	    break;
        case NILDO_OPTION_nostdinc:
            s->nostdinc = 1;
            break;
        case NILDO_OPTION_nostdlib:
            s->nostdlib = 1;
            break;
        case NILDO_OPTION_run:
#ifndef NILDO_IS_NATIVE
            nld_error("-run is not available in a cross compiler");
#endif
            run = optarg;
            x = NILDO_OUTPUT_MEMORY;
            goto set_output_type;
        case NILDO_OPTION_v:
            do ++s->verbose; while (*optarg++ == 'v');
            ++noaction;
            break;
        case NILDO_OPTION_f:
            if (set_flag(s, options_f, optarg) < 0)
                goto unsupported_option;
            break;
#ifdef NILDO_TARGET_ARM
        case NILDO_OPTION_mfloat_abi:
            /* nld doesn't support soft float yet */
            if (!strcmp(optarg, "softfp")) {
                s->float_abi = ARM_SOFTFP_FLOAT;
                nld_undefine_symbol(s, "__ARM_PCS_VFP");
            } else if (!strcmp(optarg, "hard"))
                s->float_abi = ARM_HARD_FLOAT;
            else
                nld_error("unsupported float abi '%s'", optarg);
            break;
#endif
        case NILDO_OPTION_m:
            if (set_flag(s, options_m, optarg) < 0) {
                if (x = atoi(optarg), x != 32 && x != 64)
                    goto unsupported_option;
                if (PTR_SIZE != x/8)
                    return x;
                ++noaction;
            }
            break;
        case NILDO_OPTION_W:
            if (set_flag(s, options_W, optarg) < 0)
                goto unsupported_option;
            break;
        case NILDO_OPTION_w:
            s->warn_none = 1;
            break;
        case NILDO_OPTION_rdynamic:
            s->rdynamic = 1;
            break;
        case NILDO_OPTION_Wl:
            if (linker_arg.size)
                --linker_arg.size, cstr_ccat(&linker_arg, ',');
            cstr_cat(&linker_arg, optarg, 0);
            if (nld_set_linker(s, linker_arg.data))
                cstr_free(&linker_arg);
            break;
	case NILDO_OPTION_Wp:
	    r = optarg;
	    goto reparse;
        case NILDO_OPTION_E:
            x = NILDO_OUTPUT_PREPROCESS;
            goto set_output_type;
        case NILDO_OPTION_P:
            s->Pflag = atoi(optarg) + 1;
            break;
        case NILDO_OPTION_MD:
            s->gen_deps = 1;
            break;
        case NILDO_OPTION_MF:
            s->deps_outfile = nld_strdup(optarg);
            break;
        case NILDO_OPTION_dumpversion:
            printf ("%s\n", NILDO_VERSION);
            exit(0);
            break;
        case NILDO_OPTION_x:
            if (*optarg == 'c')
                s->filetype = AFF_TYPE_C;
            else if (*optarg == 'a')
                s->filetype = AFF_TYPE_ASMPP;
            else if (*optarg == 'n')
                s->filetype = AFF_TYPE_NONE;
            else
                nld_warning("unsupported language '%s'", optarg);
            break;
        case NILDO_OPTION_O:
            last_o = atoi(optarg);
            break;
        case NILDO_OPTION_print_search_dirs:
            x = OPT_PRINT_DIRS;
            goto extra_action;
        case NILDO_OPTION_impdef:
            x = OPT_IMPDEF;
            goto extra_action;
        case NILDO_OPTION_ar:
            x = OPT_AR;
        extra_action:
            arg_start = optind - 1;
            if (arg_start != noaction)
                nld_error("cannot parse %s here", r);
            tool = x;
            break;
        case NILDO_OPTION_traditional:
        case NILDO_OPTION_pedantic:
        case NILDO_OPTION_pipe:
        case NILDO_OPTION_s:
            /* ignored */
            break;
        default:
unsupported_option:
            if (s->warn_unsupported)
                nld_warning("unsupported option '%s'", r);
            break;
        }
    }
    if (last_o > 0)
        nld_define_symbol(s, "__OPTIMIZE__", NULL);
    if (linker_arg.size) {
        r = linker_arg.data;
        goto arg_err;
    }
    *pargc = argc - arg_start;
    *pargv = argv + arg_start;
    if (tool)
        return tool;
    if (optind != noaction)
        return 0;
    if (s->verbose == 2)
        return OPT_PRINT_DIRS;
    if (s->verbose)
        return OPT_V;
    return OPT_HELP;
}

LIBNILDOAPI void nld_set_options(NILDOState *s, const char *r)
{
    char **argv = NULL;
    int argc = 0;
    args_parser_make_argv(r, &argc, &argv);
    nld_parse_args(s, &argc, &argv, 0);
    dynarray_reset(&argv, &argc);
}

PUB_FUNC void nld_print_stats(NILDOState *s, unsigned total_time)
{
    if (total_time < 1)
        total_time = 1;
    if (total_bytes < 1)
        total_bytes = 1;
    fprintf(stderr, "* %d idents, %d lines, %d bytes\n"
                    "* %0.3f s, %u lines/s, %0.1f MB/s\n",
           tok_ident - TOK_IDENT, total_lines, total_bytes,
           (double)total_time/1000,
           (unsigned)total_lines*1000/total_time,
           (double)total_bytes/1000/total_time);
#ifdef MEM_DEBUG
    fprintf(stderr, "* %d bytes memory used\n", mem_max_size);
#endif
}
