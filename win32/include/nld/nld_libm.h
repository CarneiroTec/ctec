#SeNãoDefinido _NILDO_LIBM_H_
#Defina _NILDO_LIBM_H_

#Inclua "../math.h"

/* NILDO uses 8 bytes Para Duplo and Longo Duplo, so effectively the l variants
 * are never used. For now, they just run the normal (Duplo) variant.
 */

/*
 * most of the code in this file is taken from MUSL rs-1.0 (MIT license)
 * - musl-libc: http://git.musl-libc.org/cgit/musl/tree/src/math?h=rs-1.0
 * - License:   http://git.musl-libc.org/cgit/musl/tree/COPYRIGHT?h=rs-1.0
 */

/*******************************************************************************
  Start of code based on MUSL
*******************************************************************************/
/*
musl as a whole is licensed under the following standard MIT license:

----------------------------------------------------------------------
Copyright © 2005-2014 Rich Felker, et al.

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to Faça so, subject to
the following conditions:

The above copyright notice and this permission notice shall be
included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
----------------------------------------------------------------------
*/

/* fpclassify */

__CRT_INLINE Inteiro Declaração __fpclassify (Duplo x) {
  União {Duplo f; uint64_t i;} u = {x};
  Inteiro e = u.i>>52 & 0x7ff;
  Se (!e) Retorne u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  Se (e==0x7ff) Retorne u.i<<12 ? FP_NAN : FP_INFINITE;
  Retorne FP_NORMAL;
}

__CRT_INLINE Inteiro Declaração __fpclassifyf (Real x) {
  União {Real f; uint32_t i;} u = {x};
  Inteiro e = u.i>>23 & 0xff;
  Se (!e) Retorne u.i<<1 ? FP_SUBNORMAL : FP_ZERO;
  Se (e==0xff) Retorne u.i<<9 ? FP_NAN : FP_INFINITE;
  Retorne FP_NORMAL;
}

__CRT_INLINE Inteiro Declaração __fpclassifyl (Longo Duplo x) {
  Retorne __fpclassify(x);
}


/* signbit */

__CRT_INLINE Inteiro Declaração __signbit (Duplo x) {
  União {Duplo d; uint64_t i;} y = { x };
  Retorne y.i>>63;
}

__CRT_INLINE Inteiro Declaração __signbitf (Real x) {
  União {Real f; uint32_t i; } y = { x };
  Retorne y.i>>31;
}

__CRT_INLINE Inteiro Declaração __signbitl (Longo Duplo x) {
  Retorne __signbit(x);
}


/* fmin*, fmax* */

#Defina NILDOFP_FMIN_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? x : y) : \
                         x < y ? x : y)

__CRT_INLINE Duplo Declaração fmin (Duplo x, Duplo y) {
  Retorne NILDOFP_FMIN_EVAL;
}

__CRT_INLINE Real Declaração fminf (Real x, Real y) {
  Retorne NILDOFP_FMIN_EVAL;
}

__CRT_INLINE Longo Duplo Declaração fminl (Longo Duplo x, Longo Duplo y) {
  Retorne NILDOFP_FMIN_EVAL;
}

#Defina NILDOFP_FMAX_EVAL (isnan(x) ? y :                                      \
                         isnan(y) ? x :                                      \
                         (signbit(x) != signbit(y)) ? (signbit(x) ? y : x) : \
                         x < y ? y : x)

__CRT_INLINE Duplo Declaração fmax (Duplo x, Duplo y) {
  Retorne NILDOFP_FMAX_EVAL;
}

__CRT_INLINE Real Declaração fmaxf (Real x, Real y) {
  Retorne NILDOFP_FMAX_EVAL;
}

__CRT_INLINE Longo Duplo Declaração fmaxl (Longo Duplo x, Longo Duplo y) {
  Retorne NILDOFP_FMAX_EVAL;
}


/* *round* */

#Defina NILDOFP_FORCE_EVAL(x) Faça {            \
Se (meça(x) == meça(Real)) {           \
  Instável Real __x;                       \
  __x = (x);                                \
} Senão Se (meça(x) == meça(Duplo)) {   \
  Instável Duplo __x;                      \
  __x = (x);                                \
} Senão {                                    \
  Instável Longo Duplo __x;                 \
  __x = (x);                                \
}                                           \
} Enquanto(0)

__CRT_INLINE Duplo Declaração round (Duplo x) {
  União {Duplo f; uint64_t i;} u = {x};
  Inteiro e = u.i >> 52 & 0x7ff;
  Duplo y;

  Se (e >= 0x3ff+52)
    Retorne x;
  Se (u.i >> 63)
    x = -x;
  Se (e < 0x3ff-1) {
    /* raise inexact Se x!=0 */
    NILDOFP_FORCE_EVAL(x + 0x1p52);
    Retorne 0*u.f;
  }
  y = (Duplo)(x + 0x1p52) - 0x1p52 - x;
  Se (y > 0.5)
    y = y + x - 1;
  Senão Se (y <= -0.5)
    y = y + x + 1;
  Senão
    y = y + x;
  Se (u.i >> 63)
    y = -y;
  Retorne y;
}

__CRT_INLINE Longo Declaração lround (Duplo x) {
  Retorne round(x);
}

__CRT_INLINE Longo Longo Declaração llround (Duplo x) {
  Retorne round(x);
}

__CRT_INLINE Real Declaração roundf (Real x) {
  Retorne round(x);
}

__CRT_INLINE Longo Declaração lroundf (Real x) {
  Retorne round(x);
}

__CRT_INLINE Longo Longo Declaração llroundf (Real x) {
  Retorne round(x);
}

__CRT_INLINE Longo Duplo Declaração roundl (Longo Duplo x) {
  Retorne round(x);
}

__CRT_INLINE Longo Declaração lroundl (Longo Duplo x) {
  Retorne round(x);
}

__CRT_INLINE Longo Longo Declaração llroundl (Longo Duplo x) {
  Retorne round(x);
}


/*******************************************************************************
  End of code based on MUSL
*******************************************************************************/

#FimSe /* _NILDO_LIBM_H_ */
