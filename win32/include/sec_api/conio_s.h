/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#SeNãoDefinido _INC_CONIO_S
#Defina _INC_CONIO_S

#Inclua <conio.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  _CRTIMP errno_t Declaração _cgets_s(Caractere *_Buffer,size_t _Size,size_t *_SizeRead);
  _CRTIMP Inteiro Declaração _cprintf_s(Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _cscanf_s(Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _cscanf_s_l(Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcprintf_s(Imutável Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _cprintf_s_l(Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcprintf_s_l(Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);

#SeNãoDefinido _WCONIO_DEFINED_S
#Defina _WCONIO_DEFINED_S
  _CRTIMP errno_t Declaração _cgetws_s(wchar_t *_Buffer,size_t _SizeInWords,size_t *_SizeRead);
  _CRTIMP Inteiro Declaração _cwprintf_s(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _cwscanf_s(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _cwscanf_s_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcwprintf_s(Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _cwprintf_s_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcwprintf_s_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#FimSe
#FimSe
