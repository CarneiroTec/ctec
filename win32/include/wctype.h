/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_WCTYPE
#Defina _INC_WCTYPE

#SeNãoDefinido _WIN32
#Erro Only Win32 target is supported!
#FimSe

#Inclua <_mingw.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido _CRTIMP
#Defina _CRTIMP __declspec(dllimport)
#FimSe

#SeNãoDefinido _WCHAR_T_DEFINED
  Pseudônimo Natural Curto wchar_t;
#Defina _WCHAR_T_DEFINED
#FimSe

#SeNãoDefinido _WCTYPE_T_DEFINED
  Pseudônimo Natural Curto wint_t;
  Pseudônimo Natural Curto wctype_t;
#Defina _WCTYPE_T_DEFINED
#FimSe

#SeNãoDefinido WEOF
#Defina WEOF (wint_t)(0xFFFF)
#FimSe

#SeNãoDefinido _CRT_CTYPEDATA_DEFINED
#Defina _CRT_CTYPEDATA_DEFINED
#SeNãoDefinido _CTYPE_DISABLE_MACROS

#SeNãoDefinido __PCTYPE_FUNC
#Defina __PCTYPE_FUNC __pctype_func()
#SeDefinido _MSVCRT_
#Defina __pctype_func() (_pctype)
#Senão
#Defina __pctype_func() (*_imp___pctype)
#FimSe
#FimSe

#SeNãoDefinido _pctype
#SeDefinido _MSVCRT_
  Externo Natural Curto *_pctype;
#Senão
  Externo Natural Curto **_imp___pctype;
#Defina _pctype (*_imp___pctype)
#FimSe
#FimSe

#FimSe
#FimSe

#SeNãoDefinido _CRT_WCTYPEDATA_DEFINED
#Defina _CRT_WCTYPEDATA_DEFINED
#SeNãoDefinido _CTYPE_DISABLE_MACROS
#SeNãoDefinido _wctype
#SeDefinido _MSVCRT_
  Externo Natural Curto *_wctype;
#Senão
  Externo Natural Curto **_imp___wctype;
#Defina _wctype (*_imp___wctype)
#FimSe
#FimSe

#SeNãoDefinido _pwctype
#SeDefinido _MSVCRT_
  Externo Natural Curto *_pwctype;
#Senão
  Externo Natural Curto **_imp___pwctype;
#Defina _pwctype (*_imp___pwctype)
#Defina __pwctype_func() (*_imp___pwctype)
#FimSe
#FimSe
#FimSe
#FimSe

#Defina _UPPER 0x1
#Defina _LOWER 0x2
#Defina _DIGIT 0x4
#Defina _SPACE 0x8

#Defina _PUNCT 0x10
#Defina _CONTROL 0x20
#Defina _BLANK 0x40
#Defina _HEX 0x80

#Defina _LEADBYTE 0x8000
#Defina _ALPHA (0x0100|_UPPER|_LOWER)

#SeNãoDefinido _WCTYPE_DEFINED
#Defina _WCTYPE_DEFINED

  Inteiro Declaração iswalpha(wint_t);
  Inteiro Declaração iswupper(wint_t);
  Inteiro Declaração iswlower(wint_t);
  Inteiro Declaração iswdigit(wint_t);
  Inteiro Declaração iswxdigit(wint_t);
  Inteiro Declaração iswspace(wint_t);
  Inteiro Declaração iswpunct(wint_t);
  Inteiro Declaração iswalnum(wint_t);
  Inteiro Declaração iswprint(wint_t);
  Inteiro Declaração iswgraph(wint_t);
  Inteiro Declaração iswcntrl(wint_t);
  Inteiro Declaração iswascii(wint_t);
  Inteiro Declaração isleadbyte(Inteiro);
  wint_t Declaração towupper(wint_t);
  wint_t Declaração towlower(wint_t);
  Inteiro Declaração iswctype(wint_t,wctype_t);
  _CRTIMP Inteiro Declaração __iswcsymf(wint_t);
  _CRTIMP Inteiro Declaração __iswcsym(wint_t);
  Inteiro Declaração is_wctype(wint_t,wctype_t);
#Se (Definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !Definido (NO_OLDNAMES)
Inteiro Declaração isblank(Inteiro _C);
#FimSe
#FimSe

#SeNãoDefinido _WCTYPE_INLINE_DEFINED
#Defina _WCTYPE_INLINE_DEFINED
#SeNãoDefinido __cplusplus
#Defina iswalpha(_c) (iswctype(_c,_ALPHA))
#Defina iswupper(_c) (iswctype(_c,_UPPER))
#Defina iswlower(_c) (iswctype(_c,_LOWER))
#Defina iswdigit(_c) (iswctype(_c,_DIGIT))
#Defina iswxdigit(_c) (iswctype(_c,_HEX))
#Defina iswspace(_c) (iswctype(_c,_SPACE))
#Defina iswpunct(_c) (iswctype(_c,_PUNCT))
#Defina iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#Defina iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#Defina iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#Defina iswcntrl(_c) (iswctype(_c,_CONTROL))
#Defina iswascii(_c) ((Natural)(_c) < 0x80)
#Defina isleadbyte(c) (__pctype_func()[(Natural Caractere)(c)] & _LEADBYTE)
#Senão
  __CRT_INLINE Inteiro Declaração iswalpha(wint_t _C) {Retorne (iswctype(_C,_ALPHA)); }
  __CRT_INLINE Inteiro Declaração iswupper(wint_t _C) {Retorne (iswctype(_C,_UPPER)); }
  __CRT_INLINE Inteiro Declaração iswlower(wint_t _C) {Retorne (iswctype(_C,_LOWER)); }
  __CRT_INLINE Inteiro Declaração iswdigit(wint_t _C) {Retorne (iswctype(_C,_DIGIT)); }
  __CRT_INLINE Inteiro Declaração iswxdigit(wint_t _C) {Retorne (iswctype(_C,_HEX)); }
  __CRT_INLINE Inteiro Declaração iswspace(wint_t _C) {Retorne (iswctype(_C,_SPACE)); }
  __CRT_INLINE Inteiro Declaração iswpunct(wint_t _C) {Retorne (iswctype(_C,_PUNCT)); }
  __CRT_INLINE Inteiro Declaração iswalnum(wint_t _C) {Retorne (iswctype(_C,_ALPHA|_DIGIT)); }
  __CRT_INLINE Inteiro Declaração iswprint(wint_t _C) {Retorne (iswctype(_C,_BLANK|_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE Inteiro Declaração iswgraph(wint_t _C) {Retorne (iswctype(_C,_PUNCT|_ALPHA|_DIGIT)); }
  __CRT_INLINE Inteiro Declaração iswcntrl(wint_t _C) {Retorne (iswctype(_C,_CONTROL)); }
  __CRT_INLINE Inteiro Declaração iswascii(wint_t _C) {Retorne ((Natural)(_C) < 0x80); }
  __CRT_INLINE Inteiro Declaração isleadbyte(Inteiro _C) {Retorne (__pctype_func()[(Natural Caractere)(_C)] & _LEADBYTE); }
#FimSe
#FimSe

  Pseudônimo wchar_t wctrans_t;
  wint_t Declaração towctrans(wint_t,wctrans_t);
  wctrans_t Declaração wctrans(Imutável Caractere *);
  wctype_t Declaração wctype(Imutável Caractere *);

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)
#FimSe
