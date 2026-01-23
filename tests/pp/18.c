#define M_RETI_ARG27(x,y,z,aa, ...)    aa
#define M_RET_ARG27(...)        M_RETI_ARG27(ARGUMENTOS_VARIÁVEIS)
#define M_COMMA_P(...)          M_RET_ARG27(ARGUMENTOS_VARIÁVEIS, 1, 1, 0, useless)
#define M_EMPTYI_DETECT(...)    0, 1,
#define M_EMPTYI_P_C1(...)      M_COMMA_P(M_EMPTYI_DETECT ARGUMENTOS_VARIÁVEIS () )
#define EX
#define empty(x)
#define fnlike(x) yeah x
/* If the following macro is called with empty arg (X183), the use
   of 'x' between fnlike and '(' doesn't hinder the recognition of this
   being a further fnlike macro invocation.  */
#define usefnlike(x) fnlike x (x)
X181 M_EMPTYI_P_C1()
X182 M_EMPTYI_P_C1(x)
X183 usefnlike()
