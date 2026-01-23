/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_TCHAR_S
#Defina _INC_TCHAR_S

#Inclua <tchar.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeDefinido _UNICODE

#Defina _tprintf_s wprintf_s
#Defina _tprintf_s_l _wprintf_s_l
#Defina _tcprintf_s _cwprintf_s
#Defina _tcprintf_s_l _cwprintf_s_l
#Defina _vtcprintf_s _vcwprintf_s
#Defina _vtcprintf_s_l _vcwprintf_s_l
#Defina _ftprintf_s fwprintf_s
#Defina _ftprintf_s_l _fwprintf_s_l
#Defina _stprintf_s swprintf_s
#Defina _stprintf_s_l _swprintf_s_l
#Defina _sntprintf_s _snwprintf_s
#Defina _sntprintf_s_l _snwprintf_s_l
#Defina _vtprintf_s vwprintf_s
#Defina _vtprintf_s_l _vwprintf_s_l
#Defina _vftprintf_s vfwprintf_s
#Defina _vftprintf_s_l _vfwprintf_s_l
#Defina _vstprintf_s vswprintf_s
#Defina _vstprintf_s_l _vswprintf_s_l
#Defina _vsntprintf_s _vsnwprintf_s
#Defina _vsntprintf_s_l _vsnwprintf_s_l

#Defina _tscanf_s wscanf_s
#Defina _tscanf_s_l _wscanf_s_l
#Defina _tcscanf_s _cwscanf_s
#Defina _tcscanf_s_l _cwscanf_s_l
#Defina _ftscanf_s fwscanf_s
#Defina _ftscanf_s_l _fwscanf_s_l
#Defina _stscanf_s swscanf_s
#Defina _stscanf_s_l _swscanf_s_l
#Defina _sntscanf_s _snwscanf_s
#Defina _sntscanf_s_l _snwscanf_s_l

#Defina _cgetts_s _cgetws_s
#Defina _getts_s _getws_s

#Defina _itot_s _itow_s
#Defina _ltot_s _ltow_s
#Defina _ultot_s _ultow_s
#Defina _i64tot_s _i64tow_s
#Defina _ui64tot_s _ui64tow_s

#Defina _tcscat_s wcscat_s
#Defina _tcscpy_s wcscpy_s
#Defina _tcsncat_s wcsncat_s
#Defina _tcsncat_s_l _wcsncat_s_l
#Defina _tcsncpy_s wcsncpy_s
#Defina _tcsncpy_s_l _wcsncpy_s_l
#Defina _tcstok_s wcstok_s
#Defina _tcstok_s_l _wcstok_s_l
#Defina _tcserror_s _wcserror_s
#Defina __tcserror_s __wcserror_s

#Defina _tcsnset_s _wcsnset_s
#Defina _tcsnset_s_l _wcsnset_s_l
#Defina _tcsset_s _wcsset_s
#Defina _tcsset_s_l _wcsset_s_l

#Defina _tasctime_s _wasctime_s
#Defina _tctime_s _wctime_s
#Defina _tctime32_s _wctime32_s
#Defina _tctime64_s _wctime64_s
#Defina _tstrdate_s _wstrdate_s
#Defina _tstrtime_s _wstrtime_s

#Defina _tgetenv_s _wgetenv_s
#Defina _tdupenv_s _wdupenv_s
#Defina _tmakepath_s _wmakepath_s
#Defina _tputenv_s _wputenv_s
#Defina _tsearchenv_s _wsearchenv_s
#Defina _tsplitpath_s _wsplitpath_s

#Defina _tfopen_s _wfopen_s
#Defina _tfreopen_s _wfreopen_s
#Defina _ttmpnam_s _wtmpnam_s
#Defina _taccess_s _waccess_s
#Defina _tmktemp_s _wmktemp_s

#Defina _tcsnccat_s wcsncat_s
#Defina _tcsnccat_s_l _wcsncat_s_l
#Defina _tcsnccpy_s wcsncpy_s
#Defina _tcsnccpy_s_l _wcsncpy_s_l

#Defina _tcslwr_s _wcslwr_s
#Defina _tcslwr_s_l _wcslwr_s_l
#Defina _tcsupr_s _wcsupr_s
#Defina _tcsupr_s_l _wcsupr_s_l

#Defina _wcstok_s_l(_String,_Delimiters,_Current_position,_Locale) (wcstok_s(_String,_Delimiters,_Current_position))
#Defina _wcsnset_s_l(_Destination,_Destination_size_chars,_Value,_Count,_Locale) (_wcsnset_s(_Destination,_Destination_size_chars,_Value,_Count))
#Defina _wcsset_s_l(_Destination,_Destination_size_chars,_Value,_Locale) (_wcsset_s(_Destination,_Destination_size_chars,_Value))

#Senão

#Defina _tprintf_s printf_s
#Defina _tprintf_s_l _printf_s_l
#Defina _tcprintf_s _cprintf_s
#Defina _tcprintf_s_l _cprintf_s_l
#Defina _vtcprintf_s _vcprintf_s
#Defina _vtcprintf_s_l _vcprintf_s_l
#Defina _ftprintf_s fprintf_s
#Defina _ftprintf_s_l _fprintf_s_l
#Defina _stprintf_s sprintf_s
#Defina _stprintf_s_l _sprintf_s_l
#Defina _sntprintf_s _snprintf_s
#Defina _sntprintf_s_l _snprintf_s_l
#Defina _vtprintf_s vprintf_s
#Defina _vtprintf_s_l _vprintf_s_l
#Defina _vftprintf_s vfprintf_s
#Defina _vftprintf_s_l _vfprintf_s_l
#Defina _vstprintf_s vsprintf_s
#Defina _vstprintf_s_l _vsprintf_s_l
#Defina _vsntprintf_s _vsnprintf_s
#Defina _vsntprintf_s_l _vsnprintf_s_l
#Defina _tscanf_s scanf_s
#Defina _tscanf_s_l _scanf_s_l
#Defina _tcscanf_s _cscanf_s
#Defina _tcscanf_s_l _cscanf_s_l
#Defina _ftscanf_s fscanf_s
#Defina _ftscanf_s_l _fscanf_s_l
#Defina _stscanf_s sscanf_s
#Defina _stscanf_s_l _sscanf_s_l
#Defina _sntscanf_s _snscanf_s
#Defina _sntscanf_s_l _snscanf_s_l

#Defina _getts_s gets_s
#Defina _cgetts_s _cgets_s
#Defina _itot_s _itoa_s
#Defina _ltot_s _ltoa_s
#Defina _ultot_s _ultoa_s
#Defina _i64tot_s _i64toa_s
#Defina _ui64tot_s _ui64toa_s

#Defina _tcscat_s strcat_s
#Defina _tcscpy_s strcpy_s
#Defina _tcserror_s strerror_s
#Defina __tcserror_s _strerror_s

#Defina _tasctime_s asctime_s
#Defina _tctime_s ctime_s
#Defina _tctime32_s _ctime32_s
#Defina _tctime64_s _ctime64_s
#Defina _tstrdate_s _strdate_s
#Defina _tstrtime_s _strtime_s

#Defina _tgetenv_s getenv_s
#Defina _tdupenv_s _dupenv_s
#Defina _tmakepath_s _makepath_s
#Defina _tputenv_s _putenv_s
#Defina _tsearchenv_s _searchenv_s
#Defina _tsplitpath_s _splitpath_s

#Defina _tfopen_s fopen_s
#Defina _tfreopen_s freopen_s
#Defina _ttmpnam_s tmpnam_s
#Defina _tmktemp_s _mktemp_s

#SeNãoDefinido _POSIX_
#Defina _taccess_s _access_s
#FimSe

#Defina _tsopen_s _sopen_s

#SeDefinido _MBCS

#SeDefinido _MB_MAP_DIRECT

#Defina _tcsncat_s _mbsnbcat_s
#Defina _tcsncat_s_l _mbsnbcat_s_l
#Defina _tcsncpy_s _mbsnbcpy_s
#Defina _tcsncpy_s_l _mbsnbcpy_s_l
#Defina _tcstok_s _mbstok_s
#Defina _tcstok_s_l _mbstok_s_l

#Defina _tcsnset_s _mbsnbset_s
#Defina _tcsnset_s_l _mbsnbset_s_l
#Defina _tcsset_s _mbsset_s
#Defina _tcsset_s_l _mbsset_s_l

#Defina _tcsnccat_s _mbsncat_s
#Defina _tcsnccat_s_l _mbsncat_s_l
#Defina _tcsnccpy_s _mbsncpy_s
#Defina _tcsnccpy_s_l _mbsncpy_s_l
#Defina _tcsncset_s _mbsnset_s
#Defina _tcsncset_s_l _mbsnset_s_l

#Defina _tcslwr_s _mbslwr_s
#Defina _tcslwr_s_l _mbslwr_s_l
#Defina _tcsupr_s _mbsupr_s
#Defina _tcsupr_s_l _mbsupr_s_l

#Defina _ctecpy_s _mbccpy_s
#Defina _ctecpy_s_l _mbccpy_s_l
#Senão

  _CRTIMP Caractere *Declaração _tcsncat_s(Caractere *_Dst,size_t _DstSizeInChars,Imutável Caractere *_Src,size_t _MaxCount);
  _CRTIMP Caractere *Declaração _tcsncat_s_l(Caractere *_Dst,size_t _DstSizeInChars,Imutável Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _tcsncpy_s(Caractere *_Dst,size_t _DstSizeInChars,Imutável Caractere *_Src,size_t _MaxCount);
  _CRTIMP Caractere *Declaração _tcsncpy_s_l(Caractere *_Dst,size_t _DstSizeInChars,Imutável Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _tcstok_s(Caractere *_Str,Imutável Caractere *_Delim,Caractere **_Context);
  _CRTIMP Caractere *Declaração _tcstok_s_l(Caractere *_Str,Imutável Caractere *_Delim,Caractere **_Context,_locale_t _Locale);
  _CRTIMP errno_t Declaração _tcsset_s(Caractere *_Str,size_t _SizeInChars,Natural Inteiro _Val);
  _CRTIMP errno_t Declaração _tcsset_s_l(Caractere *_Str,size_t _SizeInChars,Natural Inteiro,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _tcsnccat_s(Caractere *_Dst,size_t _DstSizeInChars,Imutável Caractere *_Src,size_t _MaxCount);
  _CRTIMP Caractere *Declaração _tcsnccat_s_l(Caractere *_Dst,size_t _DstSizeInChars,Imutável Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _tcsnccpy_s(Caractere *_Dst,size_t _DstSizeInChars,Imutável Caractere *_Src,size_t _MaxCount);
  _CRTIMP Caractere *Declaração _tcsnccpy_s_l(Caractere *_Dst,size_t _DstSizeInChars,Imutável Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _tcslwr_s(Caractere *_Str,size_t _SizeInChars);
  _CRTIMP Caractere *Declaração _tcslwr_s_l(Caractere *_Str,size_t _SizeInChars,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _tcsupr_s(Caractere *_Str,size_t _SizeInChars);
  _CRTIMP Caractere *Declaração _tcsupr_s_l(Caractere *_Str,size_t _SizeInChars,_locale_t _Locale);

#FimSe

#Senão

#Defina _tcsncat_s strncat_s
#Defina _tcsncat_s_l _strncat_s_l
#Defina _tcsncpy_s strncpy_s
#Defina _tcsncpy_s_l _strncpy_s_l
#Defina _tcstok_s strtok_s
#Defina _tcstok_s_l _strtok_s_l

#Defina _tcsnset_s _strnset_s
#Defina _tcsnset_s_l _strnset_s_l
#Defina _tcsset_s _strset_s
#Defina _tcsset_s _strset_s
#Defina _tcsset_s_l _strset_s_l

#Defina _tcsnccat_s strncat_s
#Defina _tcsnccat_s_l _strncat_s_l
#Defina _tcsnccpy_s strncpy_s
#Defina _tcsnccpy_s_l _strncpy_s_l

#Defina _tcslwr_s _strlwr_s
#Defina _tcslwr_s_l _strlwr_s_l
#Defina _tcsupr_s _strupr_s
#Defina _tcsupr_s_l _strupr_s_l

#Defina _strnset_s_l(_Destination,_Destination_size_chars,_Value,_Count,_Locale) (_strnset_s(_Destination,_Destination_size_chars,_Value,_Count))
#Defina _strset_s_l(_Destination,_Destination_size_chars,_Value,_Locale) (_strset_s(_Destination,_Destination_size_chars,_Value))
#FimSe
#FimSe

#SeDefinido __cplusplus
}
#FimSe
#FimSe
#FimSe
