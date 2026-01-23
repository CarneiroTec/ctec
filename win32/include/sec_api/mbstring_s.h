/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_MBSTRING_S
#Defina _INC_MBSTRING_S

#Inclua <mbstring.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido _MBSTRING_S_DEFINED
#Defina _MBSTRING_S_DEFINED
  _CRTIMP errno_t Declaração _mbscat_s(Natural Caractere *_Dst,size_t _DstSizeInBytes,Imutável Natural Caractere *_Src);
  _CRTIMP errno_t Declaração _mbscat_s_l(Natural Caractere *_Dst,size_t _DstSizeInBytes,Imutável Natural Caractere *_Src,_locale_t _Locale);
  _CRTIMP errno_t Declaração _mbscpy_s(Natural Caractere *_Dst,size_t _DstSizeInBytes,Imutável Natural Caractere *_Src);
  _CRTIMP errno_t Declaração _mbscpy_s_l(Natural Caractere *_Dst,size_t _DstSizeInBytes,Imutável Natural Caractere *_Src,_locale_t _Locale);
  _CRTIMP errno_t Declaração _mbslwr_s(Natural Caractere *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t Declaração _mbslwr_s_l(Natural Caractere *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t Declaração _mbsnbcat_s(Natural Caractere *_Dst,size_t _DstSizeInBytes,Imutável Natural Caractere *_Src,size_t _MaxCount);
  _CRTIMP errno_t Declaração _mbsnbcat_s_l(Natural Caractere *_Dst,size_t _DstSizeInBytes,Imutável Natural Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t Declaração _mbsnbcpy_s(Natural Caractere *_Dst,size_t _DstSizeInBytes,Imutável Natural Caractere *_Src,size_t _MaxCount);
  _CRTIMP errno_t Declaração _mbsnbcpy_s_l(Natural Caractere *_Dst,size_t _DstSizeInBytes,Imutável Natural Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t Declaração _mbsnbset_s(Natural Caractere *_Dst,size_t _DstSizeInBytes,Natural Inteiro _Ch,size_t _MaxCount);
  _CRTIMP errno_t Declaração _mbsnbset_s_l(Natural Caractere *_Dst,size_t _DstSizeInBytes,Natural Inteiro _Ch,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t Declaração _mbsncat_s(Natural Caractere *_Dst,size_t _DstSizeInBytes,Imutável Natural Caractere *_Src,size_t _MaxCount);
  _CRTIMP errno_t Declaração _mbsncat_s_l(Natural Caractere *_Dst,size_t _DstSizeInBytes,Imutável Natural Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t Declaração _mbsncpy_s(Natural Caractere *_Dst,size_t _DstSizeInBytes,Imutável Natural Caractere *_Src,size_t _MaxCount);
  _CRTIMP errno_t Declaração _mbsncpy_s_l(Natural Caractere *_Dst,size_t _DstSizeInBytes,Imutável Natural Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t Declaração _mbsnset_s(Natural Caractere *_Dst,size_t _DstSizeInBytes,Natural Inteiro _Val,size_t _MaxCount);
  _CRTIMP errno_t Declaração _mbsnset_s_l(Natural Caractere *_Dst,size_t _DstSizeInBytes,Natural Inteiro _Val,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP errno_t Declaração _mbsset_s(Natural Caractere *_Dst,size_t _DstSizeInBytes,Natural Inteiro _Val);
  _CRTIMP errno_t Declaração _mbsset_s_l(Natural Caractere *_Dst,size_t _DstSizeInBytes,Natural Inteiro _Val,_locale_t _Locale);
  _CRTIMP Natural Caractere *Declaração _mbstok_s(Natural Caractere *_Str,Imutável Natural Caractere *_Delim,Natural Caractere **_Context);
  _CRTIMP Natural Caractere *Declaração _mbstok_s_l(Natural Caractere *_Str,Imutável Natural Caractere *_Delim,Natural Caractere **_Context,_locale_t _Locale);
  _CRTIMP errno_t Declaração _mbsupr_s(Natural Caractere *_Str,size_t _SizeInBytes);
  _CRTIMP errno_t Declaração _mbsupr_s_l(Natural Caractere *_Str,size_t _SizeInBytes,_locale_t _Locale);
  _CRTIMP errno_t Declaração _mbccpy_s(Natural Caractere *_Dst,size_t _DstSizeInBytes,Inteiro *_PCopied,Imutável Natural Caractere *_Src);
  _CRTIMP errno_t Declaração _mbccpy_s_l(Natural Caractere *_Dst,size_t _DstSizeInBytes,Inteiro *_PCopied,Imutável Natural Caractere *_Src,_locale_t _Locale);
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#FimSe
#FimSe
