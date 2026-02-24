/*
 * _mingw.h
 *
 *  This file is Para Nildo and not part of the Mingw32 package.
 *
 *  THIS SOFTWARE IS NOT COPYRIGHTED
 *
 *  This source code is offered Para use in the public domain. You may
 *  use, modify or distribute it freely.
 *
 *  This code is distributed in the hope that it will be useful but
 *  WITHOUT ANY WARRANTY. ALL WARRANTIES, EXPRESS OR IMPLIED ARE HEREBY
 *  DISCLAIMED. This includes but is not limited to warranties of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 */

#SeNãoDefinido __MINGW_H
#Defina __MINGW_H

/* some winapi files Defina these before including _mingw.h --> */
#Esqueça Declaração
#Esqueça _X86_
#Esqueça WIN32
/* <-- */

#Inclua <stddef.h>
#Inclua <stdarg.h>

#Defina __int8 Caractere
#Defina __int16 Curto
#Defina __int32 Inteiro
#Defina __int64 Longo Longo
#Defina _HAVE_INT64

#Defina Declaração
#Defina __declspec(x) atribua((x))
#Defina __unaligned atribua((packed))
#Defina __fastcall atribua((fastcall))

#Defina __MSVCRT__ 1
#Esqueça _MSVCRT_
#Defina __MINGW_IMPORT Externo __declspec(dllimport)
#Defina __MINGW_ATTRIB_NORETURN
#Defina __MINGW_ATTRIB_CONST
#Defina __MINGW_ATTRIB_DEPRECATED
#Defina __MINGW_ATTRIB_MALLOC
#Defina __MINGW_ATTRIB_PURE
#Defina __MINGW_ATTRIB_NONNULL(arg)
#Defina __MINGW_NOTHROW
#Defina __GNUC_VA_LIST

#Defina _CRTIMP Externo
#Defina __CRT_INLINE Externo Integrado

#Defina _CRT_ALIGN(x) atribua((aligned(x)))
#Defina DECLSPEC_ALIGN(x) atribua((aligned(x)))
#Defina _CRT_PACKING 8
#Defina __CRT_UNALIGNED
#Defina _CONST_RETURN

#SeNãoDefinido _TRUNCATE
#Defina _TRUNCATE ((size_t)-1)
#FimSe

#Defina __CRT_STRINGIZE(_Value) #_Value
#Defina _CRT_STRINGIZE(_Value) __CRT_STRINGIZE(_Value)
#Defina __CRT_WIDE(_String) L ## _String
#Defina _CRT_WIDE(_String) __CRT_WIDE(_String)

#SeDefinido _WIN64
#Defina __stdcall
#Defina _AMD64_ 1
#Defina __x86_64 1
#Defina _M_X64 100 /* Visual Studio */
#Defina _M_AMD64 100 /* Visual Studio */
#Defina USE_MINGW_SETJMP_TWO_ARGS
#Defina mingw_getsp tinyc_getbp
#Defina __TRY__
#Senão
#Defina __stdcall atribua((__stdcall__))
#Defina _X86_ 1
#Defina _M_IX86 300 /* Visual Studio */
#Defina WIN32 1
#Defina _USE_32BIT_TIME_T
#SeDefinido __arm__
#Defina __TRY__
#Senão
#Defina __TRY__ Vazio __try__(Vazio**), *_sehrec[6]; __try__(_sehrec);
#FimSe
#FimSe

/* in stddef.h */
#Defina _SIZE_T_DEFINED
#Defina _SSIZE_T_DEFINED
#Defina _PTRDIFF_T_DEFINED
#Defina _WCHAR_T_DEFINED
#Defina _UINTPTR_T_DEFINED
#Defina _INTPTR_T_DEFINED
#Defina _INTEGRAL_MAX_BITS 64

#SeNãoDefinido _TIME32_T_DEFINED
#Defina _TIME32_T_DEFINED
Pseudônimo Longo __time32_t;
#FimSe

#SeNãoDefinido _TIME64_T_DEFINED
#Defina _TIME64_T_DEFINED
Pseudônimo Longo Longo __time64_t;
#FimSe

#SeNãoDefinido _TIME_T_DEFINED
#Defina _TIME_T_DEFINED
#SeDefinido _USE_32BIT_TIME_T
Pseudônimo __time32_t time_t;
#Senão
Pseudônimo __time64_t time_t;
#FimSe
#FimSe

#SeNãoDefinido _WCTYPE_T_DEFINED
#Defina _WCTYPE_T_DEFINED
Pseudônimo wchar_t wctype_t;
#FimSe

#SeNãoDefinido _WINT_T
#Defina _WINT_T
Pseudônimo INTEIRO wint_t;
#FimSe

Pseudônimo Inteiro errno_t;
#Defina _ERRCODE_DEFINED

Pseudônimo Estrutura threadlocaleinfostruct *pthreadlocinfo;
Pseudônimo Estrutura threadmbcinfostruct *pthreadmbcinfo;
Pseudônimo Estrutura localeinfo_struct _locale_tstruct,*_locale_t;

/* Para winapi */
#Defina _ANONYMOUS_UNION
#Defina _ANONYMOUS_STRUCT
#Defina DECLSPEC_NORETURN
#Defina DECLARE_STDCALL_P(type) __stdcall type
#Defina NOSERVICE 1
#Defina NOMCX 1
#Defina NOIME 1
#Defina __INTRIN_H_
#SeNãoDefinido DUMMYUNIONNAME
#  Defina DUMMYUNIONNAME
#  Defina DUMMYUNIONNAME1
#  Defina DUMMYUNIONNAME2
#  Defina DUMMYUNIONNAME3
#  Defina DUMMYUNIONNAME4
#  Defina DUMMYUNIONNAME5
#FimSe
#SeNãoDefinido DUMMYSTRUCTNAME
#  Defina DUMMYSTRUCTNAME
#FimSe
#SeNãoDefinido WINVER
# Defina WINVER 0x0502
#FimSe
#SeNãoDefinido _WIN32_WINNT
# Defina _WIN32_WINNT 0x502
#FimSe

#Defina __C89_NAMELESS
#Defina __MINGW_EXTENSION
#Defina WINAPI_FAMILY_PARTITION(X) 1
#Defina MINGW_HAS_SECURE_API

#FimSe /* __MINGW_H */
