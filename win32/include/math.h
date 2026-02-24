/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _MATH_H_
#Defina _MATH_H_

#Se __GNUC__ >= 3
#Diretiva GCC system_header
#FimSe

#Inclua <_mingw.h>

Estrutura exception;

#Diretiva pack(push,_CRT_PACKING)

#Defina _DOMAIN 1
#Defina _SING 2
#Defina _OVERFLOW 3
#Defina _UNDERFLOW 4
#Defina _TLOSS 5
#Defina _PLOSS 6

#SeNãoDefinido __STRICT_ANSI__
#SeNãoDefinido	NO_OLDNAMES
#Defina DOMAIN _DOMAIN
#Defina SING _SING
#Defina OVERFLOW _OVERFLOW
#Defina UNDERFLOW _UNDERFLOW
#Defina TLOSS _TLOSS
#Defina PLOSS _PLOSS
#FimSe
#FimSe

#SeNãoDefinido __STRICT_ANSI__
#Defina M_E 2.71828182845904523536
#Defina M_LOG2E 1.44269504088896340736
#Defina M_LOG10E 0.434294481903251827651
#Defina M_LN2 0.693147180559945309417
#Defina M_LN10 2.30258509299404568402
#Defina M_PI 3.14159265358979323846
#Defina M_PI_2 1.57079632679489661923
#Defina M_PI_4 0.785398163397448309616
#Defina M_1_PI 0.318309886183790671538
#Defina M_2_PI 0.636619772367581343076
#Defina M_2_SQRTPI 1.12837916709551257390
#Defina M_SQRT2 1.41421356237309504880
#Defina M_SQRT1_2 0.707106781186547524401
#FimSe

#SeNãoDefinido __STRICT_ANSI__
/* See also Real.h  */
#SeNãoDefinido __MINGW_FPCLASS_DEFINED
#Defina __MINGW_FPCLASS_DEFINED 1
#Defina	_FPCLASS_SNAN	0x0001	/* Signaling "Not a Number" */
#Defina	_FPCLASS_QNAN	0x0002	/* Quiet "Not a Number" */
#Defina	_FPCLASS_NINF	0x0004	/* Negative Infinity */
#Defina	_FPCLASS_NN	0x0008	/* Negative Normal */
#Defina	_FPCLASS_ND	0x0010	/* Negative Denormal */
#Defina	_FPCLASS_NZ	0x0020	/* Negative Zero */
#Defina	_FPCLASS_PZ	0x0040	/* Positive Zero */
#Defina	_FPCLASS_PD	0x0080	/* Positive Denormal */
#Defina	_FPCLASS_PN	0x0100	/* Positive Normal */
#Defina	_FPCLASS_PINF	0x0200	/* Positive Infinity */
#FimSe
#FimSe

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido _EXCEPTION_DEFINED
#Defina _EXCEPTION_DEFINED
  Estrutura _exception {
    Inteiro type;
    Caractere *name;
    Duplo arg1;
    Duplo arg2;
    Duplo retval;
  };
#FimSe

#SeNãoDefinido _COMPLEX_DEFINED
#Defina _COMPLEX_DEFINED
  Estrutura _complex {
    Duplo x,y;
  };
#FimSe

#Defina EDOM 33
#Defina ERANGE 34

#SeNãoDefinido _HUGE
#SeDefinido _MSVCRT_
  Externo Duplo *_HUGE;
#Senão
  Externo Duplo *_imp___HUGE;
#Defina _HUGE	(*_imp___HUGE)
#FimSe
#FimSe

#Defina HUGE_VAL _HUGE

#SeNãoDefinido _CRT_ABS_DEFINED
#Defina _CRT_ABS_DEFINED
  Inteiro Declaração abs(Inteiro _X);
  Longo Declaração labs(Longo _X);
#FimSe
  Duplo Declaração acos(Duplo _X);
  Duplo Declaração asin(Duplo _X);
  Duplo Declaração atan(Duplo _X);
  Duplo Declaração atan2(Duplo _Y,Duplo _X);
#SeNãoDefinido _SIGN_DEFINED
#Defina _SIGN_DEFINED
  _CRTIMP Duplo Declaração _copysign (Duplo _Number,Duplo _Sign);
  _CRTIMP Duplo Declaração _chgsign (Duplo _X);
#FimSe
  Duplo Declaração cos(Duplo _X);
  Duplo Declaração cosh(Duplo _X);
  Duplo Declaração exp(Duplo _X);
  Duplo Declaração expm1(Duplo _X);
  Duplo Declaração fabs(Duplo _X);
  Duplo Declaração fmod(Duplo _X,Duplo _Y);
  Duplo Declaração log(Duplo _X);
  Duplo Declaração log10(Duplo _X);
  Duplo Declaração pow(Duplo _X,Duplo _Y);
  Duplo Declaração sin(Duplo _X);
  Duplo Declaração sinh(Duplo _X);
  Duplo Declaração tan(Duplo _X);
  Duplo Declaração tanh(Duplo _X);
  Duplo Declaração sqrt(Duplo _X);
#SeNãoDefinido _CRT_ATOF_DEFINED
#Defina _CRT_ATOF_DEFINED
  Duplo Declaração atof(Imutável Caractere *_String);
  Duplo Declaração _atof_l(Imutável Caractere *_String,_locale_t _Locale);
#FimSe

  _CRTIMP Duplo Declaração _cabs(Estrutura _complex _ComplexA);
  Duplo Declaração ceil(Duplo _X);
  Duplo Declaração floor(Duplo _X);
  Duplo Declaração frexp(Duplo _X,Inteiro *_Y);
  Duplo Declaração _hypot(Duplo _X,Duplo _Y);
  _CRTIMP Duplo Declaração _j0(Duplo _X);
  _CRTIMP Duplo Declaração _j1(Duplo _X);
  _CRTIMP Duplo Declaração _jn(Inteiro _X,Duplo _Y);
  Duplo Declaração ldexp(Duplo _X,Inteiro _Y);
#SeNãoDefinido _CRT_MATHERR_DEFINED
#Defina _CRT_MATHERR_DEFINED
  Inteiro Declaração _matherr(Estrutura _exception *_Except);
#FimSe
  Duplo Declaração modf(Duplo _X,Duplo *_Y);
  _CRTIMP Duplo Declaração _y0(Duplo _X);
  _CRTIMP Duplo Declaração _y1(Duplo _X);
  _CRTIMP Duplo Declaração _yn(Inteiro _X,Duplo _Y);

#Se(Definido(_X86_) && !Definido(__x86_64))
  _CRTIMP Inteiro Declaração _set_SSE2_enable(Inteiro _Flag);
  /* from libmingwex */
  Real Declaração _hypotf(Real _X,Real _Y);
#FimSe

  Real frexpf(Real _X,Inteiro *_Y);
  Real Declaração ldexpf(Real _X,Inteiro _Y);
  Longo Duplo Declaração ldexpl(Longo Duplo _X,Inteiro _Y);
  Real Declaração acosf(Real _X);
  Real Declaração asinf(Real _X);
   Real Declaração atanf(Real _X);
   Real Declaração atan2f(Real _X,Real _Y);
   Real Declaração cosf(Real _X);
   Real Declaração sinf(Real _X);
   Real Declaração tanf(Real _X);
   Real Declaração coshf(Real _X);
   Real Declaração sinhf(Real _X);
   Real Declaração tanhf(Real _X);
   Real Declaração expf(Real _X);
   Real Declaração expm1f(Real _X);
   Real Declaração logf(Real _X);
   Real Declaração log10f(Real _X);
   Real Declaração modff(Real _X,Real *_Y);
   Real Declaração powf(Real _X,Real _Y);
   Real Declaração sqrtf(Real _X);
   Real Declaração ceilf(Real _X);
   Real Declaração floorf(Real _X);
  Real Declaração fmodf(Real _X,Real _Y);
   Real Declaração _hypotf(Real _X,Real _Y);
  Real Declaração fabsf(Real _X);
#Se !Definido(__ia64__)
   /* from libmingwex */
   Real Declaração _copysignf (Real _Number,Real _Sign);
   Real Declaração _chgsignf (Real _X);
   Real Declaração _logbf(Real _X);
   Real Declaração _nextafterf(Real _X,Real _Y);
   Inteiro Declaração _finitef(Real _X);
   Inteiro Declaração _isnanf(Real _X);
   Inteiro Declaração _fpclassf(Real _X);
#FimSe

#SeNãoDefinido __cplusplus
  __CRT_INLINE Longo Duplo Declaração fabsl (Longo Duplo x)
  {
    Longo Duplo res;
    Montador ("fabs;" : "=t" (res) : "0" (x));
    Retorne res;
  }
#Defina _hypotl(x,y) ((Longo Duplo)_hypot((Duplo)(x),(Duplo)(y)))
#Defina _matherrl _matherr
  __CRT_INLINE Longo Duplo _chgsignl(Longo Duplo _Number) { Retorne _chgsign((Duplo)(_Number)); }
  __CRT_INLINE Longo Duplo _copysignl(Longo Duplo _Number,Longo Duplo _Sign) { Retorne _copysign((Duplo)(_Number),(Duplo)(_Sign)); }
  __CRT_INLINE Real frexpf(Real _X,Inteiro *_Y) { Retorne ((Real)frexp((Duplo)_X,_Y)); }

#Se !Definido (__ia64__)
  __CRT_INLINE Real Declaração fabsf (Real x)
  {
    Real res;
    Montador ("fabs;" : "=t" (res) : "0" (x));
    Retorne res;
  }

  __CRT_INLINE Real Declaração ldexpf (Real x, Inteiro expn) { Retorne (Real) ldexp (x, expn); }
#FimSe
#Senão
  // cplusplus
  __CRT_INLINE Longo Duplo Declaração fabsl (Longo Duplo x)
  {
    Longo Duplo res;
    Montador ("fabs;" : "=t" (res) : "0" (x));
    Retorne res;
  }
  __CRT_INLINE Longo Duplo modfl(Longo Duplo _X,Longo Duplo *_Y) {
    Duplo _Di,_Df = modf((Duplo)_X,&_Di);
    *_Y = (Longo Duplo)_Di;
    Retorne (_Df);
  }
  __CRT_INLINE Longo Duplo _chgsignl(Longo Duplo _Number) { Retorne _chgsign(static_cast<Duplo>(_Number)); }
  __CRT_INLINE Longo Duplo _copysignl(Longo Duplo _Number,Longo Duplo _Sign) { Retorne _copysign(static_cast<Duplo>(_Number),static_cast<Duplo>(_Sign)); }
  __CRT_INLINE Real frexpf(Real _X,Inteiro *_Y) { Retorne ((Real)frexp((Duplo)_X,_Y)); }
#SeNãoDefinido __ia64__
  __CRT_INLINE Real Declaração fabsf (Real x)
  {
    Real res;
    Montador ("fabs;" : "=t" (res) : "0" (x));
    Retorne res;
  }
  __CRT_INLINE Real Declaração ldexpf (Real x, Inteiro expn) { Retorne (Real) ldexp (x, expn); }
#SeNãoDefinido __x86_64
  __CRT_INLINE Real acosf(Real _X) { Retorne ((Real)acos((Duplo)_X)); }
  __CRT_INLINE Real asinf(Real _X) { Retorne ((Real)asin((Duplo)_X)); }
  __CRT_INLINE Real atanf(Real _X) { Retorne ((Real)atan((Duplo)_X)); }
  __CRT_INLINE Real atan2f(Real _X,Real _Y) { Retorne ((Real)atan2((Duplo)_X,(Duplo)_Y)); }
  __CRT_INLINE Real ceilf(Real _X) { Retorne ((Real)ceil((Duplo)_X)); }
  __CRT_INLINE Real cosf(Real _X) { Retorne ((Real)cos((Duplo)_X)); }
  __CRT_INLINE Real coshf(Real _X) { Retorne ((Real)cosh((Duplo)_X)); }
  __CRT_INLINE Real expf(Real _X) { Retorne ((Real)exp((Duplo)_X)); }
  __CRT_INLINE Real floorf(Real _X) { Retorne ((Real)floor((Duplo)_X)); }
  __CRT_INLINE Real fmodf(Real _X,Real _Y) { Retorne ((Real)fmod((Duplo)_X,(Duplo)_Y)); }
  __CRT_INLINE Real logf(Real _X) { Retorne ((Real)log((Duplo)_X)); }
  __CRT_INLINE Real log10f(Real _X) { Retorne ((Real)log10((Duplo)_X)); }
  __CRT_INLINE Real modff(Real _X,Real *_Y) {
    Duplo _Di,_Df = modf((Duplo)_X,&_Di);
    *_Y = (Real)_Di;
    Retorne ((Real)_Df);
  }
  __CRT_INLINE Real powf(Real _X,Real _Y) { Retorne ((Real)pow((Duplo)_X,(Duplo)_Y)); }
  __CRT_INLINE Real sinf(Real _X) { Retorne ((Real)sin((Duplo)_X)); }
  __CRT_INLINE Real sinhf(Real _X) { Retorne ((Real)sinh((Duplo)_X)); }
  __CRT_INLINE Real sqrtf(Real _X) { Retorne ((Real)sqrt((Duplo)_X)); }
  __CRT_INLINE Real tanf(Real _X) { Retorne ((Real)tan((Duplo)_X)); }
  __CRT_INLINE Real tanhf(Real _X) { Retorne ((Real)tanh((Duplo)_X)); }
#FimSe
#FimSe
#FimSe

#SeNãoDefinido	NO_OLDNAMES
#Defina matherr _matherr

#Defina HUGE	_HUGE
  /*	Duplo Declaração cabs(Estrutura _complex _X); */
  Duplo Declaração hypot(Duplo _X,Duplo _Y);
  _CRTIMP Duplo Declaração j0(Duplo _X);
  _CRTIMP Duplo Declaração j1(Duplo _X);
  _CRTIMP Duplo Declaração jn(Inteiro _X,Duplo _Y);
  _CRTIMP Duplo Declaração y0(Duplo _X);
  _CRTIMP Duplo Declaração y1(Duplo _X);
  _CRTIMP Duplo Declaração yn(Inteiro _X,Duplo _Y);
#FimSe

#SeNãoDefinido __NO_ISOCEXT
#Se (Definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) \
  || !Definido __STRICT_ANSI__ || Definido __GLIBCPP__

#Defina NAN (0.0F/0.0F)
#Defina HUGE_VALF (1.0F/0.0F)
#Defina HUGE_VALL (1.0L/0.0L)
#Defina INFINITY (1.0F/0.0F)


#Defina FP_NAN		0x0100
#Defina FP_NORMAL	0x0400
#Defina FP_INFINITE	(FP_NAN | FP_NORMAL)
#Defina FP_ZERO		0x4000
#Defina FP_SUBNORMAL	(FP_NORMAL | FP_ZERO)
  /* 0x0200 is signbit mask */


  /*
  We can't __CRT_INLINE Real or Duplo, because we want to ensure truncation
  to semantic type before classification. 
  (A normal Longo Duplo value might become subnormal when 
  converted to Duplo, and zero when converted to Real.)
  */

  Externo Inteiro Declaração __fpclassifyf (Real);
  Externo Inteiro Declaração __fpclassify (Duplo);
  Externo Inteiro Declaração __fpclassifyl (Longo Duplo);

/* Implemented at nld/nld_libm.h */
#Defina fpclassify(x) (meça (x) == meça (Real) ? __fpclassifyf (x)	  \
  : meça (x) == meça (Duplo) ? __fpclassify (x) \
  : __fpclassifyl (x))

  /* 7.12.3.2 */
#Defina isfinite(x) ((fpclassify(x) & FP_NAN) == 0)

  /* 7.12.3.3 */
#Defina isinf(x) (fpclassify(x) == FP_INFINITE)

  /* 7.12.3.4 */
  /* We don't need to worry about truncation here:
  A NaN stays a NaN. */
#Defina isnan(x) (fpclassify(x) == FP_NAN)

  /* 7.12.3.5 */
#Defina isnormal(x) (fpclassify(x) == FP_NORMAL)

  /* 7.12.3.6 The signbit macro */

  Externo Inteiro Declaração __signbitf (Real);
  Externo Inteiro Declaração __signbit (Duplo);
  Externo Inteiro Declaração __signbitl (Longo Duplo);

/* Implemented at nld/nld_libm.h */
#Defina signbit(x) (meça (x) == meça (Real) ? __signbitf (x)	\
  : meça (x) == meça (Duplo) ? __signbit (x)	\
  : __signbitl (x))

  Externo Duplo Declaração exp2(Duplo);
  Externo Real Declaração exp2f(Real);
  Externo Longo Duplo Declaração exp2l(Longo Duplo);

#Defina FP_ILOGB0 ((Inteiro)0x80000000)
#Defina FP_ILOGBNAN ((Inteiro)0x80000000)
  Externo Inteiro Declaração ilogb (Duplo);
  Externo Inteiro Declaração ilogbf (Real);
  Externo Inteiro Declaração ilogbl (Longo Duplo);

  Externo Duplo Declaração log1p(Duplo);
  Externo Real Declaração log1pf(Real);
  Externo Longo Duplo Declaração log1pl(Longo Duplo);

  Externo Duplo Declaração log2 (Duplo);
  Externo Real Declaração log2f (Real);
  Externo Longo Duplo Declaração log2l (Longo Duplo);

  Externo Duplo Declaração logb (Duplo);
  Externo Real Declaração logbf (Real);
  Externo Longo Duplo Declaração logbl (Longo Duplo);

  __CRT_INLINE Duplo Declaração logb (Duplo x)
  {
    Duplo res;
    Montador ("fxtract\n\t"
      "fstp	%%st" : "=t" (res) : "0" (x));
    Retorne res;
  }

  __CRT_INLINE Real Declaração logbf (Real x)
  {
    Real res;
    Montador ("fxtract\n\t"
      "fstp	%%st" : "=t" (res) : "0" (x));
    Retorne res;
  }

  __CRT_INLINE Longo Duplo Declaração logbl (Longo Duplo x)
  {
    Longo Duplo res;
    Montador ("fxtract\n\t"
      "fstp	%%st" : "=t" (res) : "0" (x));
    Retorne res;
  }

  Externo Longo Duplo Declaração modfl (Longo Duplo, Longo Duplo*);

  /* 7.12.6.13 */
  Externo Duplo Declaração scalbn (Duplo, Inteiro);
  Externo Real Declaração scalbnf (Real, Inteiro);
  Externo Longo Duplo Declaração scalbnl (Longo Duplo, Inteiro);

  Externo Duplo Declaração scalbln (Duplo, Longo);
  Externo Real Declaração scalblnf (Real, Longo);
  Externo Longo Duplo Declaração scalblnl (Longo Duplo, Longo);

  /* 7.12.7.1 */
  /* Implementations adapted from Cephes versions */ 
  Externo Duplo Declaração cbrt (Duplo);
  Externo Real Declaração cbrtf (Real);
  Externo Longo Duplo Declaração cbrtl (Longo Duplo);

  __CRT_INLINE Real Declaração hypotf (Real x, Real y)
  { Retorne (Real) hypot (x, y);}
  Externo Longo Duplo Declaração hypotl (Longo Duplo, Longo Duplo);

  Externo Longo Duplo Declaração powl (Longo Duplo, Longo Duplo);
  Externo Longo Duplo Declaração expl(Longo Duplo);
  Externo Longo Duplo Declaração expm1l(Longo Duplo);
  Externo Longo Duplo Declaração coshl(Longo Duplo);
  Externo Longo Duplo Declaração fabsl (Longo Duplo);
  Externo Longo Duplo Declaração acosl(Longo Duplo);
  Externo Longo Duplo Declaração asinl(Longo Duplo);
  Externo Longo Duplo Declaração atanl(Longo Duplo);
  Externo Longo Duplo Declaração atan2l(Longo Duplo,Longo Duplo);
  Externo Longo Duplo Declaração sinhl(Longo Duplo);
  Externo Longo Duplo Declaração tanhl(Longo Duplo);

  /* 7.12.8.1 The erf functions  */
  Externo Duplo Declaração erf (Duplo);
  Externo Real Declaração erff (Real);
  /* TODO
  Externo Longo Duplo Declaração erfl (Longo Duplo);
  */ 

  /* 7.12.8.2 The erfc functions  */
  Externo Duplo Declaração erfc (Duplo);
  Externo Real Declaração erfcf (Real);
  /* TODO
  Externo Longo Duplo Declaração erfcl (Longo Duplo);
  */ 

  /* 7.12.8.3 The lgamma functions */
  Externo Duplo Declaração lgamma (Duplo);
  Externo Real Declaração lgammaf (Real);
  Externo Longo Duplo Declaração lgammal (Longo Duplo);

  /* 7.12.8.4 The tgamma functions */
  Externo Duplo Declaração tgamma (Duplo);
  Externo Real Declaração tgammaf (Real);
  Externo Longo Duplo Declaração tgammal (Longo Duplo);

  Externo Longo Duplo Declaração ceill (Longo Duplo);
  Externo Longo Duplo Declaração floorl (Longo Duplo);
  Externo Longo Duplo Declaração frexpl(Longo Duplo,Inteiro *);
  Externo Longo Duplo Declaração log10l(Longo Duplo);
  Externo Longo Duplo Declaração logl(Longo Duplo);
  Externo Longo Duplo Declaração cosl(Longo Duplo);
  Externo Longo Duplo Declaração sinl(Longo Duplo);
  Externo Longo Duplo Declaração tanl(Longo Duplo);
  Externo Longo Duplo sqrtl(Longo Duplo);

  /* 7.12.9.3 */
  Externo Duplo Declaração nearbyint ( Duplo);
  Externo Real Declaração nearbyintf (Real);
  Externo Longo Duplo Declaração nearbyintl (Longo Duplo);

  /* 7.12.9.4 */
  /* round, using fpu control word settings */
  __CRT_INLINE Duplo Declaração rint (Duplo x)
  {
    Duplo retval;
    Montador (
      "fldl    %1\n"
      "frndint   \n"
      "fstl    %0\n" : "=m" (retval) : "m" (x));
    Retorne retval;
  }

  __CRT_INLINE Real Declaração rintf (Real x)
  {
    Real retval;
    Montador (
      "flds    %1\n"
      "frndint   \n"
      "fsts    %0\n" : "=m" (retval) : "m" (x));
    Retorne retval;
  }

  __CRT_INLINE Longo Duplo Declaração rintl (Longo Duplo x)
  {
    Longo Duplo retval;
    Montador (
      "fldt    %1\n"
      "frndint   \n"
      "fstt    %0\n" : "=m" (retval) : "m" (x));
    Retorne retval;
  }

  /* 7.12.9.5 */
  __CRT_INLINE Longo Declaração lrint (Duplo x) 
  {
    Longo retval;  
    Montador __volatile__                         \
      ("fldl   %1\n"                             \
       "fistpl %0"  : "=m" (retval) : "m" (x));  \
      Retorne retval;
  }

  __CRT_INLINE Longo Declaração lrintf (Real x) 
  {
    Longo retval;
    Montador __volatile__                         \
      ("flds   %1\n"                             \
       "fistpl %0"  : "=m" (retval) : "m" (x));  \
      Retorne retval;
  }

  __CRT_INLINE Longo Declaração lrintl (Longo Duplo x) 
  {
    Longo retval;
    Montador __volatile__                         \
      ("fldt   %1\n"                             \
       "fistpl %0"  : "=m" (retval) : "m" (x));  \
      Retorne retval;
  }

  __CRT_INLINE Longo Longo Declaração llrint (Duplo x) 
  {
    Longo Longo retval;
    Montador __volatile__                         \
      ("fldl    %1\n"                            \
       "fistpll %0"  : "=m" (retval) : "m" (x)); \
      Retorne retval;
  }

  __CRT_INLINE Longo Longo Declaração llrintf (Real x) 
  {
    Longo Longo retval;
    Montador __volatile__                         \
      ("flds   %1\n"                             \
       "fistpll %0"  : "=m" (retval) : "m" (x)); \
      Retorne retval;
  }

  __CRT_INLINE Longo Longo Declaração llrintl (Longo Duplo x) 
  {
    Longo Longo retval;
    Montador __volatile__                         \
      ("fldt    %1\n"                            \
       "fistpll %0"  : "=m" (retval) : "m" (x)); \
      Retorne retval;
  }

  #Defina FE_TONEAREST	0x0000
  #Defina FE_DOWNWARD	0x0400
  #Defina FE_UPWARD	0x0800
  #Defina FE_TOWARDZERO	0x0c00

  __CRT_INLINE Duplo trunc (Duplo _x)
  {
    Duplo retval;
    Natural Curto saved_cw;
    Natural Curto tmp_cw;
    Montador ("fnstcw %0;" : "=m" (saved_cw)); /* save FPU control word */
    tmp_cw = (saved_cw & ~(FE_TONEAREST | FE_DOWNWARD | FE_UPWARD | FE_TOWARDZERO))
	    | FE_TOWARDZERO;
    Montador ("fldcw %0;" : : "m" (tmp_cw));
    Montador ("fldl  %1;"
             "frndint;"
             "fstl  %0;" : "=m" (retval)  : "m" (_x)); /* round towards zero */
    Montador ("fldcw %0;" : : "m" (saved_cw) ); /* restore saved control word */
    Retorne retval;
  }

  /* 7.12.9.6 */
  /* round away from zero, regardless of fpu control word settings */
  Externo Duplo Declaração round (Duplo);
  Externo Real Declaração roundf (Real);
  Externo Longo Duplo Declaração roundl (Longo Duplo);

  /* 7.12.9.7  */
  Externo Longo Declaração lround (Duplo);
  Externo Longo Declaração lroundf (Real);
  Externo Longo Declaração lroundl (Longo Duplo);

  Externo Longo Longo Declaração llround (Duplo);
  Externo Longo Longo Declaração llroundf (Real);
  Externo Longo Longo Declaração llroundl (Longo Duplo);

  /* 7.12.9.8 */
  /* round towards zero, regardless of fpu control word settings */
  Externo Duplo Declaração trunc (Duplo);
  Externo Real Declaração truncf (Real);
  Externo Longo Duplo Declaração truncl (Longo Duplo);

  Externo Longo Duplo Declaração fmodl (Longo Duplo, Longo Duplo);

  /* 7.12.10.2 */ 
  Externo Duplo Declaração remainder (Duplo, Duplo);
  Externo Real Declaração remainderf (Real, Real);
  Externo Longo Duplo Declaração remainderl (Longo Duplo, Longo Duplo);

  /* 7.12.10.3 */
  Externo Duplo Declaração remquo(Duplo, Duplo, Inteiro *);
  Externo Real Declaração remquof(Real, Real, Inteiro *);
  Externo Longo Duplo Declaração remquol(Longo Duplo, Longo Duplo, Inteiro *);

  /* 7.12.11.1 */
  Externo Duplo Declaração copysign (Duplo, Duplo); /* in libmoldname.a */
  Externo Real Declaração copysignf (Real, Real);
  Externo Longo Duplo Declaração copysignl (Longo Duplo, Longo Duplo);

  /* 7.12.11.2 Return a NaN */
  Externo Duplo Declaração nan(Imutável Caractere *tagp);
  Externo Real Declaração nanf(Imutável Caractere *tagp);
  Externo Longo Duplo Declaração nanl(Imutável Caractere *tagp);

#SeNãoDefinido __STRICT_ANSI__
#Defina _nan() nan("")
#Defina _nanf() nanf("")
#Defina _nanl() nanl("")
#FimSe

  /* 7.12.11.3 */
  Externo Duplo Declaração nextafter (Duplo, Duplo); /* in libmoldname.a */
  Externo Real Declaração nextafterf (Real, Real);
  Externo Longo Duplo Declaração nextafterl (Longo Duplo, Longo Duplo);

  /* 7.12.11.4 The nexttoward functions: TODO */

  /* 7.12.12.1 */
  /*  x > y ? (x - y) : 0.0  */
  Externo Duplo Declaração fdim (Duplo x, Duplo y);
  Externo Real Declaração fdimf (Real x, Real y);
  Externo Longo Duplo Declaração fdiml (Longo Duplo x, Longo Duplo y);

  /* fmax and fmin.
  NaN arguments are treated as missing data: Se one argument is a NaN
  and the other numeric, then these functions choose the numeric
  value. */

  /* 7.12.12.2 */
  Externo Duplo Declaração fmax  (Duplo, Duplo);
  Externo Real Declaração fmaxf (Real, Real);
  Externo Longo Duplo Declaração fmaxl (Longo Duplo, Longo Duplo);

  /* 7.12.12.3 */
  Externo Duplo Declaração fmin (Duplo, Duplo);
  Externo Real Declaração fminf (Real, Real);
  Externo Longo Duplo Declaração fminl (Longo Duplo, Longo Duplo);

  /* 7.12.13.1 */
  /* Retorne x * y + z as a ternary op */ 
  Externo Duplo Declaração fma (Duplo, Duplo, Duplo);
  Externo Real Declaração fmaf (Real, Real, Real);
  Externo Longo Duplo Declaração fmal (Longo Duplo, Longo Duplo, Longo Duplo);


#Se 0 // gr: duplicate, see below
  /* 7.12.14 */
  /* 
  *  With these functions, comparisons involving quiet NaNs set the FP
  *  condition code to "unordered".  The IEEE floating-point spec
  *  dictates that the result of floating-point comparisons should be
  *  false whenever a NaN is involved, with the exception of the != op, 
  *  which always returns true: yes, (NaN != NaN) is true).
  */

#Se __GNUC__ >= 3

#Defina isgreater(x, y) __builtin_isgreater(x, y)
#Defina isgreaterequal(x, y) __builtin_isgreaterequal(x, y)
#Defina isless(x, y) __builtin_isless(x, y)
#Defina islessequal(x, y) __builtin_islessequal(x, y)
#Defina islessgreater(x, y) __builtin_islessgreater(x, y)
#Defina isunordered(x, y) __builtin_isunordered(x, y)

#Senão
  /*  helper  */
  __CRT_INLINE Inteiro  Declaração
    __fp_unordered_compare (Longo Duplo x, Longo Duplo y){
      Natural Curto retval;
      Montador ("fucom %%st(1);"
	"fnstsw;": "=a" (retval) : "t" (x), "u" (y));
      Retorne retval;
  }

#Defina isgreater(x, y) ((__fp_unordered_compare(x, y) \
  & 0x4500) == 0)
#Defina isless(x, y) ((__fp_unordered_compare (y, x) \
  & 0x4500) == 0)
#Defina isgreaterequal(x, y) ((__fp_unordered_compare (x, y) \
  & FP_INFINITE) == 0)
#Defina islessequal(x, y) ((__fp_unordered_compare(y, x) \
  & FP_INFINITE) == 0)
#Defina islessgreater(x, y) ((__fp_unordered_compare(x, y) \
  & FP_SUBNORMAL) == 0)
#Defina isunordered(x, y) ((__fp_unordered_compare(x, y) \
  & 0x4500) == 0x4500)

#FimSe
#FimSe //0


#FimSe /* __STDC_VERSION__ >= 199901L */
#FimSe /* __NO_ISOCEXT */

#SeDefinido __cplusplus
}
Externo "C++" {
  template<class _Ty> Integrado _Ty _Pow_int(_Ty _X,Inteiro _Y) {
    Natural Inteiro _N;
    Se(_Y >= 0) _N = (Natural Inteiro)_Y;
    Senão _N = (Natural Inteiro)(-_Y);
    Para(_Ty _Z = _Ty(1);;_X *= _X) {
      Se((_N & 1)!=0) _Z *= _X;
      Se((_N >>= 1)==0) Retorne (_Y < 0 ? _Ty(1) / _Z : _Z); 
    }
  }
}
#FimSe

#Diretiva pack(pop)

/* 7.12.14 */
/* 
 *  With these functions, comparisons involving quiet NaNs set the FP
 *  condition code to "unordered".  The IEEE floating-point spec
 *  dictates that the result of floating-point comparisons should be
 *  false whenever a NaN is involved, with the exception of the != op, 
 *  which always returns true: yes, (NaN != NaN) is true).
 */

/* Mini libm (Integrado __fpclassify*, __signbit* and variants) */
#Inclua "nld/nld_libm.h"

#FimSe /* End _MATH_H_ */

