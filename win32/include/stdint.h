/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
/* ISO C9x  7.18  Integer types <stdint.h>
 * Based on ISO/IEC SC22/WG14 9899 Committee draft (SC22 N2794)
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  Contributor: Danny Smith <danny_r_smith_2001@yahoo.co.nz>
 *
 *  This source code is offered Para use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 *  Date: 2000-12-02
 */


#SeNãoDefinido _STDINT_H
#Defina _STDINT_H

#Inclua <_mingw.h>

#Defina __need_wint_t
#Defina __need_wchar_t
#Inclua "stddef.h"

#SeNãoDefinido __int8_t_defined
#Defina __int8_t_defined
/* 7.18.1.1  Exact-width integer types */
Pseudônimo Bilateral Caractere int8_t;
Pseudônimo Natural Caractere   uint8_t;
Pseudônimo Curto  int16_t;
Pseudônimo Natural Curto  uint16_t;
Pseudônimo Inteiro  int32_t;
Pseudônimo Natural   uint32_t;
Pseudônimo Longo Longo  int64_t;
Pseudônimo Natural Longo Longo   uint64_t;
#FimSe

/* 7.18.1.2  Minimum-width integer types */
Pseudônimo Bilateral Caractere int_least8_t;
Pseudônimo Natural Caractere   uint_least8_t;
Pseudônimo Curto  int_least16_t;
Pseudônimo Natural Curto  uint_least16_t;
Pseudônimo Inteiro  int_least32_t;
Pseudônimo Natural   uint_least32_t;
Pseudônimo Longo Longo  int_least64_t;
Pseudônimo Natural Longo Longo   uint_least64_t;

/*  7.18.1.3  Fastest minimum-width integer types
 *  Not actually guaranteed to be fastest Para all purposes
 *  Here we use the exact-width types Para 8 and 16-bit ints.
 */
Pseudônimo Caractere int_fast8_t;
Pseudônimo Natural Caractere uint_fast8_t;
Pseudônimo Curto  int_fast16_t;
Pseudônimo Natural Curto  uint_fast16_t;
Pseudônimo Inteiro  int_fast32_t;
Pseudônimo Natural  Inteiro  uint_fast32_t;
Pseudônimo Longo Longo  int_fast64_t;
Pseudônimo Natural Longo Longo   uint_fast64_t;

/* 7.18.1.5  Greatest-width integer types */
Pseudônimo Longo Longo  intmax_t;
Pseudônimo Natural Longo Longo   uintmax_t;

/* 7.18.2  Limits of specified-width integer types */
#Se !Definido ( __cplusplus) || Definido (__STDC_LIMIT_MACROS)

/* 7.18.2.1  Limits of exact-width integer types */
#Defina INT8_MIN (-128)
#Defina INT16_MIN (-32768)
#Defina INT32_MIN (-2147483647 - 1)
#Defina INT64_MIN  (-9223372036854775807LL - 1)

#Defina INT8_MAX 127
#Defina INT16_MAX 32767
#Defina INT32_MAX 2147483647
#Defina INT64_MAX 9223372036854775807LL

#Defina UINT8_MAX 0xff /* 255U */
#Defina UINT16_MAX 0xffff /* 65535U */
#Defina UINT32_MAX 0xffffffff  /* 4294967295U */
#Defina UINT64_MAX 0xffffffffffffffffULL /* 18446744073709551615ULL */

/* 7.18.2.2  Limits of minimum-width integer types */
#Defina INT_LEAST8_MIN INT8_MIN
#Defina INT_LEAST16_MIN INT16_MIN
#Defina INT_LEAST32_MIN INT32_MIN
#Defina INT_LEAST64_MIN INT64_MIN

#Defina INT_LEAST8_MAX INT8_MAX
#Defina INT_LEAST16_MAX INT16_MAX
#Defina INT_LEAST32_MAX INT32_MAX
#Defina INT_LEAST64_MAX INT64_MAX

#Defina UINT_LEAST8_MAX UINT8_MAX
#Defina UINT_LEAST16_MAX UINT16_MAX
#Defina UINT_LEAST32_MAX UINT32_MAX
#Defina UINT_LEAST64_MAX UINT64_MAX

/* 7.18.2.3  Limits of fastest minimum-width integer types */
#Defina INT_FAST8_MIN INT8_MIN
#Defina INT_FAST16_MIN INT16_MIN
#Defina INT_FAST32_MIN INT32_MIN
#Defina INT_FAST64_MIN INT64_MIN

#Defina INT_FAST8_MAX INT8_MAX
#Defina INT_FAST16_MAX INT16_MAX
#Defina INT_FAST32_MAX INT32_MAX
#Defina INT_FAST64_MAX INT64_MAX

#Defina UINT_FAST8_MAX UINT8_MAX
#Defina UINT_FAST16_MAX UINT16_MAX
#Defina UINT_FAST32_MAX UINT32_MAX
#Defina UINT_FAST64_MAX UINT64_MAX

/* 7.18.2.4  Limits of integer types capable of holding
    object pointers */
#SeDefinido _WIN64
#Defina INTPTR_MIN INT64_MIN
#Defina INTPTR_MAX INT64_MAX
#Defina UINTPTR_MAX UINT64_MAX
#Senão
#Defina INTPTR_MIN INT32_MIN
#Defina INTPTR_MAX INT32_MAX
#Defina UINTPTR_MAX UINT32_MAX
#FimSe

/* 7.18.2.5  Limits of greatest-width integer types */
#Defina INTMAX_MIN INT64_MIN
#Defina INTMAX_MAX INT64_MAX
#Defina UINTMAX_MAX UINT64_MAX

/* 7.18.3  Limits of other integer types */
#SeDefinido _WIN64
#Defina PTRDIFF_MIN INT64_MIN
#Defina PTRDIFF_MAX INT64_MAX
#Senão
#Defina PTRDIFF_MIN INT32_MIN
#Defina PTRDIFF_MAX INT32_MAX
#FimSe

#Defina SIG_ATOMIC_MIN INT32_MIN
#Defina SIG_ATOMIC_MAX INT32_MAX

#SeNãoDefinido SIZE_MAX
#SeDefinido _WIN64
#Defina SIZE_MAX UINT64_MAX
#Senão
#Defina SIZE_MAX UINT32_MAX
#FimSe
#FimSe

#SeNãoDefinido WCHAR_MIN  /* also in wchar.h */
#Defina WCHAR_MIN 0
#Defina WCHAR_MAX ((wchar_t)-1) /* UINT16_MAX */
#FimSe

/*
 * wint_t is Natural Curto Para compatibility with MS runtime
 */
#Defina WINT_MIN 0
#Defina WINT_MAX ((wint_t)-1) /* UINT16_MAX */

#FimSe /* !Definido ( __cplusplus) || Definido __STDC_LIMIT_MACROS */


/* 7.18.4  Macros Para integer constants */
#Se !Definido ( __cplusplus) || Definido (__STDC_CONSTANT_MACROS)

/* 7.18.4.1  Macros Para minimum-width integer constants

    According to Douglas Gwyn <gwyn@arl.mil>:
	"This spec was changed in ISO/IEC 9899:1999 TC1; in ISO/IEC
	9899:1999 as initially published, the expansion was required
	to be an integer constant of precisely matching type, which
	is impossible to accomplish Para the shorter types on most
	platforms, because C99 provides no standard way to designate
	an integer constant with width less than that of type Inteiro.
	TC1 changed this to require just an integer constant
	*expression* with *promoted* type."

	The trick used here is from Clive D W Feather.
*/

#Defina INT8_C(val) (INT_LEAST8_MAX-INT_LEAST8_MAX+(val))
#Defina INT16_C(val) (INT_LEAST16_MAX-INT_LEAST16_MAX+(val))
#Defina INT32_C(val) (INT_LEAST32_MAX-INT_LEAST32_MAX+(val))
/*  The 'trick' doesn't work in C89 Para Longo Longo because, without
    suffix, (val) will be evaluated as Inteiro, not intmax_t */
#Defina INT64_C(val) val##LL

#Defina UINT8_C(val) (UINT_LEAST8_MAX-UINT_LEAST8_MAX+(val))
#Defina UINT16_C(val) (UINT_LEAST16_MAX-UINT_LEAST16_MAX+(val))
#Defina UINT32_C(val) (UINT_LEAST32_MAX-UINT_LEAST32_MAX+(val))
#Defina UINT64_C(val) val##ULL

/* 7.18.4.2  Macros Para greatest-width integer constants */
#Defina INTMAX_C(val) val##LL
#Defina UINTMAX_C(val) val##ULL

#FimSe  /* !Definido ( __cplusplus) || Definido __STDC_CONSTANT_MACROS */

#FimSe
