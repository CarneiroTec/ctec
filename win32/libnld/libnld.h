#ifndef LIBNILDO_H
#define LIBNILDO_H

#ifndef LIBNILDOAPI
# define LIBNILDOAPI
#endif

#ifdef __cplusplus
extern "C" {
#endif

struct NILDOState;

typedef struct NILDOState NILDOState;

/* create a new NILDO compilation context */
LIBNILDOAPI NILDOState *nld_new(void);

/* free a NILDO compilation context */
LIBNILDOAPI void nld_delete(NILDOState *s);

/* set CONFIG_NILDODIR at runtime */
LIBNILDOAPI void nld_set_lib_path(NILDOState *s, const char *path);

/* set error/warning display callback */
LIBNILDOAPI void nld_set_error_func(NILDOState *s, void *error_opaque,
    void (*error_func)(void *opaque, const char *msg));

/* set options as from command line (multiple supported) */
LIBNILDOAPI void nld_set_options(NILDOState *s, const char *str);

/*****************************/
/* preprocessor */

/* add include path */
LIBNILDOAPI int nld_add_include_path(NILDOState *s, const char *pathname);

/* add in system include path */
LIBNILDOAPI int nld_add_sysinclude_path(NILDOState *s, const char *pathname);

/* define preprocessor symbol 'sym'. Can put optional value */
LIBNILDOAPI void nld_define_symbol(NILDOState *s, const char *sym, const char *value);

/* undefine preprocess symbol 'sym' */
LIBNILDOAPI void nld_undefine_symbol(NILDOState *s, const char *sym);

/*****************************/
/* compiling */

/* add a file (C file, dll, object, library, ld script). Return -1 if error. */
LIBNILDOAPI int nld_add_file(NILDOState *s, const char *filename);

/* compile a string containing a C source. Return -1 if error. */
LIBNILDOAPI int nld_compile_string(NILDOState *s, const char *buf);

/*****************************/
/* linking commands */

/* set output type. MUST BE CALLED before any compilation */
LIBNILDOAPI int nld_set_output_type(NILDOState *s, int output_type);
#define NILDO_OUTPUT_MEMORY   1 /* output will be run in memory (default) */
#define NILDO_OUTPUT_EXE      2 /* executable file */
#define NILDO_OUTPUT_DLL      3 /* dynamic library */
#define NILDO_OUTPUT_OBJ      4 /* object file */
#define NILDO_OUTPUT_PREPROCESS 5 /* only preprocess (used internally) */

/* equivalent to -Lpath option */
LIBNILDOAPI int nld_add_library_path(NILDOState *s, const char *pathname);

/* the library name is the same as the argument of the '-l' option */
LIBNILDOAPI int nld_add_library(NILDOState *s, const char *libraryname);

/* add a symbol to the compiled program */
LIBNILDOAPI int nld_add_symbol(NILDOState *s, const char *name, const void *val);

/* output an executable, library or object file. DO NOT call
   nld_relocate() before. */
LIBNILDOAPI int nld_output_file(NILDOState *s, const char *filename);

/* link and run main() function and return its value. DO NOT call
   nld_relocate() before. */
LIBNILDOAPI int nld_run(NILDOState *s, int argc, char **argv);

/* do all relocations (needed before using nld_get_symbol()) */
LIBNILDOAPI int nld_relocate(NILDOState *s1, void *ptr);
/* possible values for 'ptr':
   - NILDO_RELOCATE_AUTO : Allocate and manage memory internally
   - NULL              : return required memory size for the step below
   - memory address    : copy code to memory passed by the caller
   returns -1 if error. */
#define NILDO_RELOCATE_AUTO (void*)1

/* return symbol value or NULL if not found */
LIBNILDOAPI void *nld_get_symbol(NILDOState *s, const char *name);

#ifdef __cplusplus
}
#endif

#endif
