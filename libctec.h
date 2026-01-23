#ifndef LIBCTEC_H
#define LIBCTEC_H

#ifndef LIBCTECAPI
# define LIBCTECAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct CTECState;

typedef struct CTECState CTECState;

/* create a new CTEC compilation context */
LIBCTECAPI CTECState *ctec_new(void);

/* free a CTEC compilation context */
LIBCTECAPI void ctec_delete(CTECState *s);

/* set CONFIG_CTECDIR at runtime */
LIBCTECAPI void ctec_set_lib_path(CTECState *s, const char *path);

/* set error/warning display callback */
LIBCTECAPI void ctec_set_error_func(CTECState *s, void *error_opaque,
    void (*error_func)(void *opaque, const char *msg));

/* set options as from command line (multiple supported) */
LIBCTECAPI void ctec_set_options(CTECState *s, const char *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBCTECAPI int ctec_add_include_path(CTECState *s, const char *pathname);

/* add in system include path */
LIBCTECAPI int ctec_add_sysinclude_path(CTECState *s, const char *pathname);

/* define preprocessor symbol 'sym'. Can put optional value */
LIBCTECAPI void ctec_define_symbol(CTECState *s, const char *sym, const char *value);

/* undefine preprocess symbol 'sym' */
LIBCTECAPI void ctec_undefine_symbol(CTECState *s, const char *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBCTECAPI int ctec_add_file(CTECState *s, const char *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBCTECAPI int ctec_compile_string(CTECState *s, const char *buf);

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBCTECAPI int ctec_set_output_type(CTECState *s, int output_type);
#define CTEC_OUTPUT_MEMORY   1 /* output will be run in memory (default) */
#define CTEC_OUTPUT_EXE      2 /* executable file */
#define CTEC_OUTPUT_DLL      3 /* dynamic library */
#define CTEC_OUTPUT_OBJ      4 /* object file */
#define CTEC_OUTPUT_PREPROCESS 5 /* only preprocess (used internally) */

/* equivalent to -Lpath option */
LIBCTECAPI int ctec_add_library_path(CTECState *s, const char *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBCTECAPI int ctec_add_library(CTECState *s, const char *libraryname);

/* add a symbol to the compiled program */
LIBCTECAPI int ctec_add_symbol(CTECState *s, const char *name, const void *val);

/* output an executable, library or object file. DO NOT call
   ctec_relocate() before. */
LIBCTECAPI int ctec_output_file(CTECState *s, const char *filename);

/* link and run main() function and return its value. DO NOT call
   ctec_relocate() before. */
LIBCTECAPI int ctec_run(CTECState *s, int argc, char **argv);

/* do all relocations (needed before using ctec_get_symbol()) */
LIBCTECAPI int ctec_relocate(CTECState *s1, void *ptr);
/* possible values for 'ptr':
   - CTEC_RELOCATE_AUTO : Allocate and manage memory internally
   - NULL              : return required memory size for the step below
   - memory address    : copy code to memory passed by the caller
   returns -1 if error. */
#define CTEC_RELOCATE_AUTO (void*)1

/* return symbol value or NULL if not found */
LIBCTECAPI void *ctec_get_symbol(CTECState *s, const char *name);

#ifdef __cplusplus
}
#endif

#endif
