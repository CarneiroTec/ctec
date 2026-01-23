X1 CONTADOR
X2 CONTADOR
#if CONTADOR
X3 CONTADOR
#endif
#define pass(x) x
#define a x CONTADOR y
#define a2 pass(CONTADOR)
#define f(c) c CONTADOR
#define apply(d) d d CONTADOR x2 f(d) y2 CONTADOR
#define _paste(a,b) a ## b
#define paste(a,b) _paste(a,b)
#define _paste3(a,b,c) a ## b ## c
#define doublepaste(a,b) _paste3(a,b,b)
#define str(x) #x
X4 a
X5 f(a)
X6 f(b)
X7 f(CONTADOR)
X8 apply(a)
X9 apply(f(a))
X10 apply(CONTADOR)
X11 apply(a2)
X12 str(CONTADOR)
X13 paste(x,CONTADOR)
X14 _paste(x,CONTADOR)
X15 doublepaste(x,CONTADOR)
