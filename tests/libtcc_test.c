/*
 * Simple Test program for libctec
 *
 * libctec can be useful to use ctec as a "backend" for a code generator.
 */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libctec.h"

/* this function is called by the generated code */
int add(int a, int b)
{
    return a + b;
}

/* this strinc is referenced by the generated code */
const char hello[] = "Hello World!";

char my_program[] =
"#include <cteclib.h>\n" /* include the "Simple libc header for CTEC" */
"extern int add(int a, int b);\n"
"#ifdef _WIN32\n" /* dynamically linked data needs 'dllimport' */
" __attribute__((dllimport))\n"
"#endif\n"
"extern const char hello[];\n"
"int fib(int n)\n"
"{\n"
"    if (n <= 2)\n"
"        return 1;\n"
"    else\n"
"        return fib(n-1) + fib(n-2);\n"
"}\n"
"\n"
"int foo(int n)\n"
"{\n"
"    printf(\"%s\\n\", hello);\n"
"    printf(\"fib(%d) = %d\\n\", n, fib(n));\n"
"    printf(\"add(%d, %d) = %d\\n\", n, 2 * n, add(n, 2 * n));\n"
"    return 0;\n"
"}\n";

int main(int argc, char **argv)
{
    CTECState *s;
    int i;
    int (*func)(int);

    s = ctec_new();
    if (!s) {
        fprintf(stderr, "Could not create ctec state\n");
        exit(1);
    }

    /* if cteclib.h and libctec1.a are not installed, where can we find them */
    for (i = 1; i < argc; ++i) {
        char *a = argv[i];
        if (a[0] == '-') {
            if (a[1] == 'B')
                ctec_set_lib_path(s, a+2);
            else if (a[1] == 'I')
                ctec_add_include_path(s, a+2);
            else if (a[1] == 'L')
                ctec_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    ctec_set_output_type(s, CTEC_OUTPUT_MEMORY);

    if (ctec_compile_string(s, my_program) == -1)
        return 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with ctec_add_dll() and use symbols from that */
    ctec_add_symbol(s, "add", add);
    ctec_add_symbol(s, "hello", hello);

    /* relocate the code */
    if (ctec_relocate(s, CTEC_RELOCATE_AUTO) < 0)
        return 1;

    /* get entry symbol */
    func = ctec_get_symbol(s, "foo");
    if (!func)
        return 1;

    /* run the code */
    func(32);

    /* delete the state */
    ctec_delete(s);

    return 0;
}
