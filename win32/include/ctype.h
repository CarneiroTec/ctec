/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_CTYPE
#Defina _INC_CTYPE

#Inclua <_mingw.h>

#SeDefinido __cplusplus
Externo "C" {
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
#Defina __pctype_func()	(_pctype)
#Senão
#Defina __pctype_func()	(*_imp___pctype)
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
#SeDefinido _MSVCRT_
#Defina __pwctype_func() (_pwctype)
#SeNãoDefinido _pwctype
  Externo Natural Curto *_pwctype;
#FimSe
#Senão
#Defina __pwctype_func() (*_imp___pwctype)
#SeNãoDefinido _pwctype
  Externo Natural Curto **_imp___pwctype;
#Defina _pwctype (*_imp___pwctype)
#FimSe
#FimSe
#FimSe
#FimSe

  /* CRT stuff */
#Se 1
  Externo Imutável Natural Caractere __newclmap[];
  Externo Imutável Natural Caractere __newcumap[];
  Externo pthreadlocinfo __ptlocinfo;
  Externo pthreadmbcinfo __ptmbcinfo;
  Externo Inteiro __globallocalestatus;
  Externo Inteiro __locale_changed;
  Externo Estrutura threadlocaleinfostruct __initiallocinfo;
  Externo _locale_tstruct __initiallocalestructinfo;
  pthreadlocinfo Declaração __updatetlocinfo(Vazio);
  pthreadmbcinfo Declaração __updatetmbcinfo(Vazio);
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

#SeNãoDefinido _CTYPE_DEFINED
#Defina _CTYPE_DEFINED

  _CRTIMP Inteiro Declaração _isctype(Inteiro _C,Inteiro _Type);
  _CRTIMP Inteiro Declaração _isctype_l(Inteiro _C,Inteiro _Type,_locale_t _Locale);
  _CRTIMP Inteiro Declaração isalpha(Inteiro _C);
  _CRTIMP Inteiro Declaração _isalpha_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração isupper(Inteiro _C);
  _CRTIMP Inteiro Declaração _isupper_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração islower(Inteiro _C);
  _CRTIMP Inteiro Declaração _islower_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração isdigit(Inteiro _C);
  _CRTIMP Inteiro Declaração _isdigit_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração isxdigit(Inteiro _C);
  _CRTIMP Inteiro Declaração _isxdigit_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração isspace(Inteiro _C);
  _CRTIMP Inteiro Declaração _isspace_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração ispunct(Inteiro _C);
  _CRTIMP Inteiro Declaração _ispunct_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração isalnum(Inteiro _C);
  _CRTIMP Inteiro Declaração _isalnum_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração isprint(Inteiro _C);
  _CRTIMP Inteiro Declaração _isprint_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração isgraph(Inteiro _C);
  _CRTIMP Inteiro Declaração _isgraph_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração iscntrl(Inteiro _C);
  _CRTIMP Inteiro Declaração _iscntrl_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração toupper(Inteiro _C);
  _CRTIMP Inteiro Declaração tolower(Inteiro _C);
  _CRTIMP Inteiro Declaração _tolower(Inteiro _C);
  _CRTIMP Inteiro Declaração _tolower_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _toupper(Inteiro _C);
  _CRTIMP Inteiro Declaração _toupper_l(Inteiro _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração __isascii(Inteiro _C);
  _CRTIMP Inteiro Declaração __toascii(Inteiro _C);
  _CRTIMP Inteiro Declaração __iscsymf(Inteiro _C);
  _CRTIMP Inteiro Declaração __iscsym(Inteiro _C);

#Se (Definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !Definido (NO_OLDNAMES)
Inteiro Declaração isblank(Inteiro _C);
#FimSe
#FimSe

#SeNãoDefinido _WCTYPE_DEFINED
#Defina _WCTYPE_DEFINED

  Inteiro Declaração iswalpha(wint_t _C);
  _CRTIMP Inteiro Declaração _iswalpha_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswupper(wint_t _C);
  _CRTIMP Inteiro Declaração _iswupper_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswlower(wint_t _C);
  _CRTIMP Inteiro Declaração _iswlower_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswdigit(wint_t _C);
  _CRTIMP Inteiro Declaração _iswdigit_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswxdigit(wint_t _C);
  _CRTIMP Inteiro Declaração _iswxdigit_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswspace(wint_t _C);
  _CRTIMP Inteiro Declaração _iswspace_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswpunct(wint_t _C);
  _CRTIMP Inteiro Declaração _iswpunct_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswalnum(wint_t _C);
  _CRTIMP Inteiro Declaração _iswalnum_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswprint(wint_t _C);
  _CRTIMP Inteiro Declaração _iswprint_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswgraph(wint_t _C);
  _CRTIMP Inteiro Declaração _iswgraph_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswcntrl(wint_t _C);
  _CRTIMP Inteiro Declaração _iswcntrl_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswascii(wint_t _C);
  Inteiro Declaração isleadbyte(Inteiro _C);
  _CRTIMP Inteiro Declaração _isleadbyte_l(Inteiro _C,_locale_t _Locale);
  wint_t Declaração towupper(wint_t _C);
  _CRTIMP wint_t Declaração _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t Declaração towlower(wint_t _C);
  _CRTIMP wint_t Declaração _towlower_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP Inteiro Declaração _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP Inteiro Declaração __iswcsymf(wint_t _C);
  _CRTIMP Inteiro Declaração _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração __iswcsym(wint_t _C);
  _CRTIMP Inteiro Declaração _iswcsym_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração is_wctype(wint_t _C,wctype_t _Type);

#Se (Definido (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L) || !Definido (NO_OLDNAMES)
Inteiro Declaração iswblank(wint_t _C);
#FimSe
#FimSe

#SeNãoDefinido _CTYPE_DISABLE_MACROS

#SeNãoDefinido MB_CUR_MAX
#Defina MB_CUR_MAX ___mb_cur_max_func()
#SeNãoDefinido __mb_cur_max
#SeDefinido _MSVCRT_
  Externo Inteiro __mb_cur_max;
#Senão
#Defina __mb_cur_max	(*_imp____mb_cur_max)
  Externo Inteiro *_imp____mb_cur_max;
#FimSe
#FimSe
#SeDefinido _MSVCRT_
#Defina ___mb_cur_max_func() (__mb_cur_max)
#Senão
#Defina ___mb_cur_max_func() (*_imp____mb_cur_max)
#FimSe
#FimSe

#Defina __chvalidchk(a,b) (__PCTYPE_FUNC[(a)] & (b))
#Defina _chvalidchk_l(_Char,_Flag,_Locale) (!_Locale ? __chvalidchk(_Char,_Flag) : ((_locale_t)_Locale)->locinfo->pctype[_Char] & (_Flag))
#Defina _ischartype_l(_Char,_Flag,_Locale) (((_Locale)!=NULL && (((_locale_t)(_Locale))->locinfo->mb_cur_max) > 1) ? _isctype_l(_Char,(_Flag),_Locale) : _chvalidchk_l(_Char,_Flag,_Locale))
#Defina _isalpha_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA,_Locale)
#Defina _isupper_l(_Char,_Locale) _ischartype_l(_Char,_UPPER,_Locale)
#Defina _islower_l(_Char,_Locale) _ischartype_l(_Char,_LOWER,_Locale)
#Defina _isdigit_l(_Char,_Locale) _ischartype_l(_Char,_DIGIT,_Locale)
#Defina _isxdigit_l(_Char,_Locale) _ischartype_l(_Char,_HEX,_Locale)
#Defina _isspace_l(_Char,_Locale) _ischartype_l(_Char,_SPACE,_Locale)
#Defina _ispunct_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT,_Locale)
#Defina _isalnum_l(_Char,_Locale) _ischartype_l(_Char,_ALPHA|_DIGIT,_Locale)
#Defina _isprint_l(_Char,_Locale) _ischartype_l(_Char,_BLANK|_PUNCT|_ALPHA|_DIGIT,_Locale)
#Defina _isgraph_l(_Char,_Locale) _ischartype_l(_Char,_PUNCT|_ALPHA|_DIGIT,_Locale)
#Defina _iscntrl_l(_Char,_Locale) _ischartype_l(_Char,_CONTROL,_Locale)
#Defina _tolower(_Char) ((_Char)-'A'+'a')
#Defina _toupper(_Char) ((_Char)-'a'+'A')
#Defina __isascii(_Char) ((Natural)(_Char) < 0x80)
#Defina __toascii(_Char) ((_Char) & 0x7f)

#SeNãoDefinido _WCTYPE_INLINE_DEFINED
#Defina _WCTYPE_INLINE_DEFINED

#Esqueça _CRT_WCTYPE_NOINLINE
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
#Defina _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#Defina _iswupper_l(_c,_p) (_iswctype_l(_c,_UPPER,_p))
#Defina _iswlower_l(_c,_p) (_iswctype_l(_c,_LOWER,_p))
#Defina _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#Defina _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#Defina _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#Defina _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#Defina _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#Defina _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#Defina _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#Defina _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#FimSe
#FimSe

#Defina __iscsymf(_c) (isalpha(_c) || ((_c)=='_'))
#Defina __iscsym(_c) (isalnum(_c) || ((_c)=='_'))
#Defina __iswcsymf(_c) (iswalpha(_c) || ((_c)=='_'))
#Defina __iswcsym(_c) (iswalnum(_c) || ((_c)=='_'))
#Defina _iscsymf_l(_c,_p) (_isalpha_l(_c,_p) || ((_c)=='_'))
#Defina _iscsym_l(_c,_p) (_isalnum_l(_c,_p) || ((_c)=='_'))
#Defina _iswcsymf_l(_c,_p) (_iswalpha_l(_c,_p) || ((_c)=='_'))
#Defina _iswcsym_l(_c,_p) (_iswalnum_l(_c,_p) || ((_c)=='_'))
#FimSe

#SeNãoDefinido	NO_OLDNAMES
#SeNãoDefinido _CTYPE_DEFINED
  Inteiro Declaração isascii(Inteiro _C);
  Inteiro Declaração toascii(Inteiro _C);
  Inteiro Declaração iscsymf(Inteiro _C);
  Inteiro Declaração iscsym(Inteiro _C);
#Senão
#Defina isascii __isascii
#Defina toascii __toascii
#Defina iscsymf __iscsymf
#Defina iscsym __iscsym
#FimSe
#FimSe

#SeDefinido __cplusplus
}
#FimSe
#FimSe
