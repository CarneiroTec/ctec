/*
 *  CTEC - Compilador CTEC
 * 
 *  Copyright (c) 2001-2004 Fabrice Bellard
 *
 * Esta biblioteca é software livre; você pode redistribuí-la e/ou
 * modificá-la sob os termos da Licença Pública Geral Menor GNU publicada
 * pela Free Software Foundation; tanto a versão 2 da Licença, como (a seu critério)
 * qualquer versão posterior.
 *
 * Esta biblioteca é distribuída na esperança de que seja útil,
 * mas SEM NENHUMA GARANTIA; sem mesmo a garantia implícita de
 * COMERCIALIZAÇÃO ou ADEQUAÇÃO A UM PROPÓSITO EM PARTICULAR. Veja a
 * Licença Pública Geral Menor GNU para mais detalhes.
 *
 * Você deve ter recebido uma cópia da Licença Pública Geral Menor GNU
 * junto com esta biblioteca; se não, escreva para a Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ctec.h"
#if ONE_SOURCE
# include "libctec.c"
#endif
#include "ctectools.c"

static const char help[] =
    "Compilador CTEC "CTEC_VERSION" - Copyright (C) 2024-2026 Anildo Carneiro\n"
    "Uso: ctec [opções...] [-o arquivo_saida] [-c] arquivo(s)...\n"
    "     ctec [opções...] -run arquivo_entrada [argumentos...]\n"
    "Opções gerais:\n"
    "  -c          compilar apenas - gerar um arquivo objeto\n"
    "  -o arquivo  definir nome do arquivo de saída\n"
    "  -run        executar fonte compilado\n"
    "  -fflag      ativa ou desativa (com prefixo 'no-') a 'flag' (veja ctec -hh)\n"
    "  -Wwarning   ativa ou desativa (com prefixo 'no-') o 'aviso' (veja ctec -hh)\n"
    "  -w          desabilita todos os avisos\n"
    "  -v -vv      mostrar versão, mostrar caminhos de busca ou arquivos carregados\n"
    "  -h -hh      mostrar esta ajuda, mostrar mais ajuda\n"
    "  -bench      mostrar estatísticas de compilação\n"
    "  -           usar stdin como arquivo de entrada\n"
    "  @listfile   ler argumentos de listfile\n"
    "Opções do pré-processador:\n"
    "  -Idir       adicionar caminho de inclusão 'dir'\n"
    "  -Dsim[=val] definir 'sim' com valor 'val'\n"
    "  -Usim       remover definição de 'sim'\n"
    "  -E          apenas pré-processar\n"
    "Opções do vinculador:\n"
    "  -Ldir       adicionar caminho de biblioteca 'dir'\n"
    "  -llib       vincular com biblioteca dinâmica ou estática 'lib'\n"
    "  -r          gerar arquivo objeto (relocável)\n"
    "  -shared     gerar uma biblioteca compartilhada/dll\n"
    "  -rdynamic   exportar todos os símbolos globais para o vinculador dinâmico\n"
    "  -soname     definir nome para biblioteca compartilhada em tempo de execução\n"
    "  -Wl,-opt[=val]  definir opção do vinculador (veja ctec -hh)\n"
    "Opções do depurador:\n"
    "  -g          gerar informações de depuração em tempo de execução\n"
#ifdef CONFIG_CTEC_BCHECK
    "  -b          compilar com verificador de memória e limites embutido (implica -g)\n"
#endif
#ifdef CONFIG_CTEC_BACKTRACE
    "  -bt N       mostrar N chamadas na pilha de execução\n"
#endif
    "Outras opções:\n"
    "  -x[c|a|n]   especificar tipo do próximo arquivo de entrada\n"
    "  -nostdinc   não usar caminhos de inclusão padrão do sistema\n"
    "  -nostdlib   não vincular com bibliotecas/crt padrão\n"
    "  -Bdir       definir diretório privado de inclusão/biblioteca do ctec\n"
    "  -MD         gerar arquivo de dependência para make\n"
    "  -MF arquivo especificar nome do arquivo de dependência\n"
    "  -m32/64     delegar para compilador cruzado i386/x86_64\n"
    "Ferramentas:\n"
    "  criar biblioteca  : ctec -ar [rcsv] lib.a arquivos\n"
#ifdef CTEC_TARGET_PE
    "  criar arquivo def : ctec -impdef lib.dll [-v] [-o lib.def]\n"
#endif
    ;

static const char help2[] =
    "Compilador CTEC "CTEC_VERSION" - Mais Opções\n"
    "Opções especiais:\n"
    "  -P -P1                        com -E: sem/alternativa para saída #line\n"
    "  -dD -dM                       com -E: saída de diretivas #define\n"
    "  -pthread                      igual a -D_REENTRANT e -lpthread\n"
    "  -On                           igual a -D__OPTIMIZE__ para n > 0\n"
    "  -Wp,-opt                      igual a -opt\n"
    "  -include arquivo              inclui 'arquivo' acima de cada arquivo de entrada\n"
    "  -isystem dir                  adiciona 'dir' ao caminho de inclusão do sistema\n"
    "  -static                       vincular a bibliotecas estáticas (não recomendado)\n"
    "  -dumpversion                  mostrar versão\n"
    "  -print-search-dirs            mostrar caminhos de busca\n"
    "  -dt                           com -run/-E: auto-define macros 'test_...'\n"
    "Opções ignoradas:\n"
    "  --param  -pedantic  -pipe  -s  -std  -traditional\n"
    "Avisos -W...:\n"
    "  all                           ativa alguns (*) avisos\n"
    "  error                         parar após o primeiro aviso\n"
    "  unsupported                   avisar sobre opções/pragmas ignorados\n"
    "  write-strings                 strings são const\n"
    "  implicit-function-declaration avisar sobre protótipo ausente (*)\n"
    "Flags -f[no-]... :\n"
    "  unsigned-char                 char padrão é unsigned\n"
    "  signed-char                   char padrão é signed\n"
    "  common                        usar seção common ao invés de bss\n"
    "  leading-underscore            decorar símbolos extern\n"
    "  ms-extensions                 permitir struct anônima em struct\n"
    "  dollars-in-identifiers        permitir '$' em símbolos C\n"
    "Opções específicas de alvo -m... :\n"
    "  ms-bitfields                  usar layout MSVC para bitfield\n"
#ifdef CTEC_TARGET_ARM
    "  float-abi                     hard/softfp em arm\n"
#endif
#ifdef CTEC_TARGET_X86_64
    "  no-sse                        desabilitar floats em x86_64\n"
#endif
    "Opções do vinculador -Wl,... :\n"
    "  -nostdlib                     não vincular com bibliotecas/crt padrão\n"
    "  -[no-]whole-archive           carregar libs totalmente/somente se necessário\n"
    "  -export-all-symbols           igual a -rdynamic\n"
    "  -image-base= -Ttext=          definir endereço base do executável\n"
    "  -section-alignment=           definir alinhamento de seção no executável\n"
#ifdef CTEC_TARGET_PE
    "  -file-alignment=              definir alinhamento de arquivo PE\n"
    "  -stack=                       definir reserva de pilha PE\n"
    "  -large-address-aware          definir opção PE relacionada\n"
    "  -subsystem=[console/windows]  definir subsistema PE\n"
    "  -oformat=[pe-* binary]        definir formato de saída do executável\n"
    "Macros pré-definidas:\n"
    "  ctec -E -dM - < nul\n"
#else
    "  -rpath=                       definir caminho de busca de biblioteca dinâmica\n"
    "  -enable-new-dtags             definir DT_RUNPATH ao invés de DT_RPATH\n"
    "  -soname=                      definir tag DT_SONAME elf\n"
    "  -Bsymbolic                    definir tag DT_SYMBOLIC elf\n"
    "  -oformat=[elf32/64-* binary]  definir formato de saída do executável\n"
    "  -init= -fini= -as-needed -O   (ignorado)\n"
    "Macros pré-definidas:\n"
    "  ctec -E -dM - < /dev/null\n"
#endif
    "Veja também o manual para mais detalhes.\n"
    ;

static const char version[] =
    "ctec version "CTEC_VERSION" ("
#ifdef CTEC_TARGET_I386
        "i386"
#elif defined CTEC_TARGET_X86_64
        "x86_64"
#elif defined CTEC_TARGET_C67
        "C67"
#elif defined CTEC_TARGET_ARM
        "ARM"
#elif defined CTEC_TARGET_ARM64
        "AArch64"
#endif
#ifdef CTEC_ARM_HARDFLOAT
        " Hard Float"
#endif
#ifdef CTEC_TARGET_PE
        " Windows"
#elif defined(CTEC_TARGET_MACHO)
        " Darwin"
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
        " FreeBSD"
#else
        " Linux"
#endif
    ")\n"
    ;

static void print_dirs(const char *msg, char **paths, int nb_paths)
{
    int i;
    printf("%s:\n%s", msg, nb_paths ? "" : "  -\n");
    for(i = 0; i < nb_paths; i++)
        printf("  %s\n", paths[i]);
}

static void print_search_dirs(CTECState *s)
{
    printf("install: %s\n", s->ctec_lib_path);
    /* print_dirs("programs", NULL, 0); */
    print_dirs("include", s->sysinclude_paths, s->nb_sysinclude_paths);
    print_dirs("libraries", s->library_paths, s->nb_library_paths);
    printf("libctec1:\n  %s/"CTEC_LIBCTEC1"\n", s->ctec_lib_path);
#ifndef CTEC_TARGET_PE
    print_dirs("crt", s->crt_paths, s->nb_crt_paths);
    printf("elfinterp:\n  %s\n",  DEFAULT_ELFINTERP(s));
#endif
}

static void set_environment(CTECState *s)
{
    char * path;

    path = getenv("C_INCLUDE_PATH");
    if(path != NULL) {
        ctec_add_sysinclude_path(s, path);
    }
    path = getenv("CPATH");
    if(path != NULL) {
        ctec_add_include_path(s, path);
    }
    path = getenv("LIBRARY_PATH");
    if(path != NULL) {
        ctec_add_library_path(s, path);
    }
}

static char *default_outputfile(CTECState *s, const char *first_file)
{
    char buf[1024];
    char *ext;
    const char *name = "a";

    if (first_file && strcmp(first_file, "-"))
        name = ctec_basename(first_file);
    snprintf(buf, sizeof(buf), "%s", name);
    ext = ctec_fileextension(buf);
#ifdef CTEC_TARGET_PE
    if (s->output_type == CTEC_OUTPUT_DLL)
        strcpy(ext, ".dll");
    else
    if (s->output_type == CTEC_OUTPUT_EXE)
        strcpy(ext, ".exe");
    else
#endif
    if (s->output_type == CTEC_OUTPUT_OBJ && !s->option_r && *ext)
        strcpy(ext, ".o");
    else
        strcpy(buf, "a.out");
    return ctec_strdup(buf);
}

static unsigned getclock_ms(void)
{
#ifdef _WIN32
    return GetTickCount();
#else
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec*1000 + (tv.tv_usec+500)/1000;
#endif
}

int main(int argc0, char **argv0)
{
    CTECState *s;
    int ret, opt, n = 0, t = 0;
    unsigned start_time = 0;
    const char *first_file;
    int argc; char **argv;
    FILE *ppfp = stdout;

redo:
    argc = argc0, argv = argv0;
    s = ctec_new();
    opt = ctec_parse_args(s, &argc, &argv, 1);

    if ((n | t) == 0) {
        if (opt == OPT_HELP)
            return printf(help), 1;
        if (opt == OPT_HELP2)
            return printf(help2), 1;
        if (opt == OPT_M32 || opt == OPT_M64)
            ctec_tool_cross(s, argv, opt); /* never returns */
        if (s->verbose)
            printf(version);
        if (opt == OPT_AR)
            return ctec_tool_ar(s, argc, argv);
#ifdef CTEC_TARGET_PE
        if (opt == OPT_IMPDEF)
            return ctec_tool_impdef(s, argc, argv);
#endif
        if (opt == OPT_V)
            return 0;
        if (opt == OPT_PRINT_DIRS) {
            /* initialize search dirs */
            set_environment(s);
            ctec_set_output_type(s, CTEC_OUTPUT_MEMORY);
            print_search_dirs(s);
            return 0;
        }

        n = s->nb_files;
        if (n == 0)
            ctec_error("no input files\n");

        if (s->output_type == CTEC_OUTPUT_PREPROCESS) {
            if (s->outfile) {
                ppfp = fopen(s->outfile, "w");
                if (!ppfp)
                    ctec_error("could not write '%s'", s->outfile);
            }
        } else if (s->output_type == CTEC_OUTPUT_OBJ && !s->option_r) {
            if (s->nb_libraries)
                ctec_error("cannot specify libraries with -c");
            if (n > 1 && s->outfile)
                ctec_error("cannot specify output file with -c many files");
        } else {
            if (s->option_pthread)
                ctec_set_options(s, "-lpthread");
        }

        if (s->do_bench)
            start_time = getclock_ms();
    }

    set_environment(s);
    if (s->output_type == 0)
        s->output_type = CTEC_OUTPUT_EXE;
    ctec_set_output_type(s, s->output_type);
    s->ppfp = ppfp;

    if ((s->output_type == CTEC_OUTPUT_MEMORY
      || s->output_type == CTEC_OUTPUT_PREPROCESS) && (s->dflag & 16))
        s->dflag |= t ? 32 : 0, s->run_test = ++t, n = s->nb_files;

    /* compile or add each files or library */
    for (first_file = NULL, ret = 0;;) {
        struct filespec *f = s->files[s->nb_files - n];
        s->filetype = f->type;
        s->alacarte_link = f->alacarte;
        if (f->type == AFF_TYPE_LIB) {
            if (ctec_add_library_err(s, f->name) < 0)
                ret = 1;
        } else {
            if (1 == s->verbose)
                printf("-> %s\n", f->name);
            if (!first_file)
                first_file = f->name;
            if (ctec_add_file(s, f->name) < 0)
                ret = 1;
        }
        s->filetype = 0;
        s->alacarte_link = 1;
        if (--n == 0 || ret
            || (s->output_type == CTEC_OUTPUT_OBJ && !s->option_r))
            break;
    }

    if (s->run_test) {
        t = 0;
    } else if (s->output_type == CTEC_OUTPUT_PREPROCESS) {
        ;
    } else if (0 == ret) {
        if (s->output_type == CTEC_OUTPUT_MEMORY) {
#ifdef CTEC_IS_NATIVE
            ret = ctec_run(s, argc, argv);
#endif
        } else {
            if (!s->outfile)
                s->outfile = default_outputfile(s, first_file);
            if (ctec_output_file(s, s->outfile))
                ret = 1;
            else if (s->gen_deps)
                gen_makedeps(s, s->outfile, s->deps_outfile);
        }
    }

    if (s->do_bench && (n | t | ret) == 0)
        ctec_print_stats(s, getclock_ms() - start_time);
    ctec_delete(s);
    if (ret == 0 && n)
        goto redo; /* compile more files with -c */
    if (t)
        goto redo; /* run more tests with -dt -run */
    if (ppfp && ppfp != stdout)
        fclose(ppfp);
    return ret;
}
