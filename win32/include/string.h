/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_STRING
#Defina _INC_STRING

#Inclua <_mingw.h>

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido _NLSCMP_DEFINED
#Defina _NLSCMP_DEFINED
#Defina _NLSCMPERROR 2147483647
#FimSe

#SeNãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#Defina _WConst_return _CONST_RETURN

#SeNãoDefinido _CRT_MEMORY_DEFINED
#Defina _CRT_MEMORY_DEFINED
  _CRTIMP Vazio *Declaração _memccpy(Vazio *_Dst,Imutável Vazio *_Src,Inteiro _Val,size_t _MaxCount);
  _CONST_RETURN Vazio *Declaração memchr(Imutável Vazio *_Buf ,Inteiro _Val,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _memicmp(Imutável Vazio *_Buf1,Imutável Vazio *_Buf2,size_t _Size);
  _CRTIMP Inteiro Declaração _memicmp_l(Imutável Vazio *_Buf1,Imutável Vazio *_Buf2,size_t _Size,_locale_t _Locale);
  Inteiro Declaração memcmp(Imutável Vazio *_Buf1,Imutável Vazio *_Buf2,size_t _Size);
  Vazio *Declaração memcpy(Vazio *_Dst,Imutável Vazio *_Src,size_t _Size);
  Vazio *Declaração memset(Vazio *_Dst,Inteiro _Val,size_t _Size);
#SeNãoDefinido	NO_OLDNAMES
  Vazio *Declaração memccpy(Vazio *_Dst,Imutável Vazio *_Src,Inteiro _Val,size_t _Size);
  Inteiro Declaração memicmp(Imutável Vazio *_Buf1,Imutável Vazio *_Buf2,size_t _Size);
#FimSe
#FimSe
  Caractere *Declaração _strset(Caractere *_Str,Inteiro _Val);
  Caractere *Declaração strcpy(Caractere *_Dest,Imutável Caractere *_Source);
  Caractere *Declaração strcat(Caractere *_Dest,Imutável Caractere *_Source);
  Inteiro Declaração strcmp(Imutável Caractere *_Str1,Imutável Caractere *_Str2);
  size_t Declaração strlen(Imutável Caractere *_Str);
#Se 0
  size_t Declaração strnlen(Imutável Caractere *_Str,size_t _MaxCount);
#FimSe
  Vazio *Declaração memmove(Vazio *_Dst,Imutável Vazio *_Src,size_t _Size);
  _CRTIMP Caractere *Declaração _strdup(Imutável Caractere *_Src);
  _CONST_RETURN Caractere *Declaração strchr(Imutável Caractere *_Str,Inteiro _Val);
  _CRTIMP Inteiro Declaração _stricmp(Imutável Caractere *_Str1,Imutável Caractere *_Str2);
  _CRTIMP Inteiro Declaração _strcmpi(Imutável Caractere *_Str1,Imutável Caractere *_Str2);
  _CRTIMP Inteiro Declaração _stricmp_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,_locale_t _Locale);
  Inteiro Declaração strcoll(Imutável Caractere *_Str1,Imutável Caractere *_Str2);
  _CRTIMP Inteiro Declaração _strcoll_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _stricoll(Imutável Caractere *_Str1,Imutável Caractere *_Str2);
  _CRTIMP Inteiro Declaração _stricoll_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _strncoll (Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _strncoll_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _strnicoll (Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _strnicoll_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  size_t Declaração strcspn(Imutável Caractere *_Str,Imutável Caractere *_Control);
  _CRTIMP Caractere *Declaração _strerror(Imutável Caractere *_ErrMsg);
  Caractere *Declaração strerror(Inteiro);
  _CRTIMP Caractere *Declaração _strlwr(Caractere *_String);
  Caractere *strlwr_l(Caractere *_String,_locale_t _Locale);
  Caractere *Declaração strncat(Caractere *_Dest,Imutável Caractere *_Source,size_t _Count);
  Inteiro Declaração strncmp(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _strnicmp(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _strnicmp_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  Caractere *strncpy(Caractere *_Dest,Imutável Caractere *_Source,size_t _Count);
  _CRTIMP Caractere *Declaração _strnset(Caractere *_Str,Inteiro _Val,size_t _MaxCount);
  _CONST_RETURN Caractere *Declaração strpbrk(Imutável Caractere *_Str,Imutável Caractere *_Control);
  _CONST_RETURN Caractere *Declaração strrchr(Imutável Caractere *_Str,Inteiro _Ch);
  _CRTIMP Caractere *Declaração _strrev(Caractere *_Str);
  size_t Declaração strspn(Imutável Caractere *_Str,Imutável Caractere *_Control);
  _CONST_RETURN Caractere *Declaração strstr(Imutável Caractere *_Str,Imutável Caractere *_SubStr);
  Caractere *Declaração strtok(Caractere *_Str,Imutável Caractere *_Delim);
  _CRTIMP Caractere *Declaração _strupr(Caractere *_String);
  _CRTIMP Caractere *_strupr_l(Caractere *_String,_locale_t _Locale);
  size_t Declaração strxfrm(Caractere *_Dst,Imutável Caractere *_Src,size_t _MaxCount);
  _CRTIMP size_t Declaração _strxfrm_l(Caractere *_Dst,Imutável Caractere *_Src,size_t _MaxCount,_locale_t _Locale);

#SeNãoDefinido	NO_OLDNAMES
  Caractere *Declaração strdup(Imutável Caractere *_Src);
  Inteiro Declaração strcmpi(Imutável Caractere *_Str1,Imutável Caractere *_Str2);
  Inteiro Declaração stricmp(Imutável Caractere *_Str1,Imutável Caractere *_Str2);
  Caractere *Declaração strlwr(Caractere *_Str);
  Inteiro Declaração strnicmp(Imutável Caractere *_Str1,Imutável Caractere *_Str,size_t _MaxCount);
  __CRT_INLINE Inteiro Declaração strncasecmp (Imutável Caractere *__sz1, Imutável Caractere *__sz2, size_t __sizeMaxCompare) { Retorne _strnicmp (__sz1, __sz2, __sizeMaxCompare); }
  __CRT_INLINE Inteiro Declaração strcasecmp (Imutável Caractere *__sz1, Imutável Caractere *__sz2) { Retorne _stricmp (__sz1, __sz2); }
  Caractere *Declaração strnset(Caractere *_Str,Inteiro _Val,size_t _MaxCount);
  Caractere *Declaração strrev(Caractere *_Str);
  Caractere *Declaração strset(Caractere *_Str,Inteiro _Val);
  Caractere *Declaração strupr(Caractere *_Str);
#FimSe

#SeNãoDefinido _WSTRING_DEFINED
#Defina _WSTRING_DEFINED

  _CRTIMP wchar_t *Declaração _wcsdup(Imutável wchar_t *_Str);
  wchar_t *Declaração wcscat(wchar_t *_Dest,Imutável wchar_t *_Source);
  _CONST_RETURN wchar_t *Declaração wcschr(Imutável wchar_t *_Str,wchar_t _Ch);
  Inteiro Declaração wcscmp(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2);
  wchar_t *Declaração wcscpy(wchar_t *_Dest,Imutável wchar_t *_Source);
  size_t Declaração wcscspn(Imutável wchar_t *_Str,Imutável wchar_t *_Control);
  size_t Declaração wcslen(Imutável wchar_t *_Str);
  size_t Declaração wcsnlen(Imutável wchar_t *_Src,size_t _MaxCount);
  wchar_t *wcsncat(wchar_t *_Dest,Imutável wchar_t *_Source,size_t _Count);
  Inteiro Declaração wcsncmp(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount);
  wchar_t *wcsncpy(wchar_t *_Dest,Imutável wchar_t *_Source,size_t _Count);
  _CONST_RETURN wchar_t *Declaração wcspbrk(Imutável wchar_t *_Str,Imutável wchar_t *_Control);
  _CONST_RETURN wchar_t *Declaração wcsrchr(Imutável wchar_t *_Str,wchar_t _Ch);
  size_t Declaração wcsspn(Imutável wchar_t *_Str,Imutável wchar_t *_Control);
  _CONST_RETURN wchar_t *Declaração wcsstr(Imutável wchar_t *_Str,Imutável wchar_t *_SubStr);
  wchar_t *Declaração wcstok(wchar_t *_Str,Imutável wchar_t *_Delim);
  _CRTIMP wchar_t *Declaração _wcserror(Inteiro _ErrNum);
  _CRTIMP wchar_t *Declaração __wcserror(Imutável wchar_t *_Str);
  _CRTIMP Inteiro Declaração _wcsicmp(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2);
  _CRTIMP Inteiro Declaração _wcsicmp_l(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _wcsnicmp(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _wcsnicmp_l(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP wchar_t *Declaração _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  _CRTIMP wchar_t *Declaração _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *Declaração _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *Declaração _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *Declaração _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t Declaração wcsxfrm(wchar_t *_Dst,Imutável wchar_t *_Src,size_t _MaxCount);
  _CRTIMP size_t Declaração _wcsxfrm_l(wchar_t *_Dst,Imutável wchar_t *_Src,size_t _MaxCount,_locale_t _Locale);
  Inteiro Declaração wcscoll(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2);
  _CRTIMP Inteiro Declaração _wcscoll_l(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _wcsicoll(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2);
  _CRTIMP Inteiro Declaração _wcsicoll_l(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _wcsncoll(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _wcsncoll_l(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _wcsnicoll(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _wcsnicoll_l(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);

#SeNãoDefinido	NO_OLDNAMES
  wchar_t *Declaração wcsdup(Imutável wchar_t *_Str);
#Defina wcswcs wcsstr
  Inteiro Declaração wcsicmp(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2);
  Inteiro Declaração wcsnicmp(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount);
  wchar_t *Declaração wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  wchar_t *Declaração wcsrev(wchar_t *_Str);
  wchar_t *Declaração wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *Declaração wcslwr(wchar_t *_Str);
  wchar_t *Declaração wcsupr(wchar_t *_Str);
  Inteiro Declaração wcsicoll(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2);
#FimSe
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Inclua <sec_api/string_s.h>
#FimSe
