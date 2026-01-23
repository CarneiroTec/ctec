/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_WCHAR_S
#Defina _INC_WCHAR_S

#Inclua <wchar.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido _WIO_S_DEFINED
#Defina _WIO_S_DEFINED
  _CRTIMP errno_t Declaração _waccess_s(Imutável wchar_t *_Filename,Inteiro _AccessMode);
  _CRTIMP errno_t Declaração _wmktemp_s(wchar_t *_TemplateName,size_t _SizeInWords);
#FimSe

#SeNãoDefinido _WCONIO_S_DEFINED
#Defina _WCONIO_S_DEFINED
  _CRTIMP errno_t Declaração _cgetws_s(wchar_t *_Buffer,size_t _SizeInWords,size_t *_SizeRead);
  _CRTIMP Inteiro Declaração _cwprintf_s(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _cwscanf_s(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _cwscanf_s_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcwprintf_s(Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _cwprintf_s_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcwprintf_s_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
#FimSe

#SeNãoDefinido _WSTDIO_S_DEFINED
#Defina _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *Declaração _getws_s(wchar_t *_Str,size_t _SizeInWords);
  Inteiro Declaração fwprintf_s(FILE *_File,Imutável wchar_t *_Format,...);
  Inteiro Declaração wprintf_s(Imutável wchar_t *_Format,...);
  Inteiro Declaração vfwprintf_s(FILE *_File,Imutável wchar_t *_Format,va_list _ArgList);
  Inteiro Declaração vwprintf_s(Imutável wchar_t *_Format,va_list _ArgList);
  Inteiro Declaração swprintf_s(wchar_t *_Dst,size_t _SizeInWords,Imutável wchar_t *_Format,...);
  Inteiro Declaração vswprintf_s(wchar_t *_Dst,size_t _SizeInWords,Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _snwprintf_s(wchar_t *_DstBuf,size_t _DstSizeInWords,size_t _MaxCount,Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _vsnwprintf_s(wchar_t *_DstBuf,size_t _DstSizeInWords,size_t _MaxCount,Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _wprintf_s_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vwprintf_s_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _fwprintf_s_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vfwprintf_s_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _swprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vswprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _snwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vsnwprintf_s_l(wchar_t *_DstBuf,size_t _DstSize,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _fwscanf_s_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _swscanf_s_l(Imutável wchar_t *_Src,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _snwscanf_s(Imutável wchar_t *_Src,size_t _MaxCount,Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _snwscanf_s_l(Imutável wchar_t *_Src,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _wscanf_s_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP errno_t Declaração _wfopen_s(FILE **_File,Imutável wchar_t *_Filename,Imutável wchar_t *_Mode);
  _CRTIMP errno_t Declaração _wfreopen_s(FILE **_File,Imutável wchar_t *_Filename,Imutável wchar_t *_Mode,FILE *_OldFile);
  _CRTIMP errno_t Declaração _wtmpnam_s(wchar_t *_DstBuf,size_t _SizeInWords);
#FimSe

#SeNãoDefinido _WSTDLIB_S_DEFINED
#Defina _WSTDLIB_S_DEFINED
  _CRTIMP errno_t Declaração _itow_s (Inteiro _Val,wchar_t *_DstBuf,size_t _SizeInWords,Inteiro _Radix);
  _CRTIMP errno_t Declaração _ltow_s (Longo _Val,wchar_t *_DstBuf,size_t _SizeInWords,Inteiro _Radix);
  _CRTIMP errno_t Declaração _ultow_s (Natural Longo _Val,wchar_t *_DstBuf,size_t _SizeInWords,Inteiro _Radix);
  _CRTIMP errno_t Declaração _wgetenv_s(size_t *_ReturnSize,wchar_t *_DstBuf,size_t _DstSizeInWords,Imutável wchar_t *_VarName);
  _CRTIMP errno_t Declaração _wdupenv_s(wchar_t **_Buffer,size_t *_BufferSizeInWords,Imutável wchar_t *_VarName);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t Declaração _i64tow_s(__int64 _Val,wchar_t *_DstBuf,size_t _SizeInWords,Inteiro _Radix);
  _CRTIMP errno_t Declaração _ui64tow_s(Natural __int64 _Val,wchar_t *_DstBuf,size_t _SizeInWords,Inteiro _Radix);
#FimSe
#FimSe

#SeNãoDefinido _POSIX_
#SeNãoDefinido _WSTDLIBP_S_DEFINED
#Defina _WSTDLIBP_S_DEFINED
  _CRTIMP errno_t Declaração _wmakepath_s(wchar_t *_PathResult,size_t _SizeInWords,Imutável wchar_t *_Drive,Imutável wchar_t *_Dir,Imutável wchar_t *_Filename,Imutável wchar_t *_Ext);
  _CRTIMP errno_t Declaração _wputenv_s(Imutável wchar_t *_Name,Imutável wchar_t *_Value);
  _CRTIMP errno_t Declaração _wsearchenv_s(Imutável wchar_t *_Filename,Imutável wchar_t *_EnvVar,wchar_t *_ResultPath,size_t _SizeInWords);
  _CRTIMP errno_t Declaração _wsplitpath_s(Imutável wchar_t *_FullPath,wchar_t *_Drive,size_t _DriveSizeInWords,wchar_t *_Dir,size_t _DirSizeInWords,wchar_t *_Filename,size_t _FilenameSizeInWords,wchar_t *_Ext,size_t _ExtSizeInWords);
#FimSe
#FimSe

#SeNãoDefinido _WSTRING_S_DEFINED
#Defina _WSTRING_S_DEFINED
  _CRTIMP wchar_t *Declaração wcstok_s(wchar_t *_Str,Imutável wchar_t *_Delim,wchar_t **_Context);
  _CRTIMP errno_t Declaração _wcserror_s(wchar_t *_Buf,size_t _SizeInWords,Inteiro _ErrNum);
  _CRTIMP errno_t Declaração __wcserror_s(wchar_t *_Buffer,size_t _SizeInWords,Imutável wchar_t *_ErrMsg);
  _CRTIMP errno_t Declaração _wcsnset_s(wchar_t *_Dst,size_t _DstSizeInWords,wchar_t _Val,size_t _MaxCount);
  _CRTIMP errno_t Declaração _wcsset_s(wchar_t *_Str,size_t _SizeInWords,wchar_t _Val);
  _CRTIMP errno_t Declaração _wcslwr_s(wchar_t *_Str,size_t _SizeInWords);
  _CRTIMP errno_t Declaração _wcslwr_s_l(wchar_t *_Str,size_t _SizeInWords,_locale_t _Locale);
  _CRTIMP errno_t Declaração _wcsupr_s(wchar_t *_Str,size_t _Size);
  _CRTIMP errno_t Declaração _wcsupr_s_l(wchar_t *_Str,size_t _Size,_locale_t _Locale);
#FimSe

#SeNãoDefinido _WTIME_S_DEFINED
#Defina _WTIME_S_DEFINED
  _CRTIMP errno_t Declaração _wasctime_s(wchar_t *_Buf,size_t _SizeInWords,Imutável Estrutura tm *_Tm);
  _CRTIMP errno_t Declaração _wctime32_s(wchar_t *_Buf,size_t _SizeInWords,Imutável __time32_t *_Time);
  _CRTIMP errno_t Declaração _wstrdate_s(wchar_t *_Buf,size_t _SizeInWords);
  _CRTIMP errno_t Declaração _wstrtime_s(wchar_t *_Buf,size_t _SizeInWords);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP errno_t Declaração _wctime64_s(wchar_t *_Buf,size_t _SizeInWords,Imutável __time64_t *_Time);
#FimSe

#Se !Definido (RC_INVOKED) && !Definido (_INC_WTIME_S_INL)
#Defina _INC_WTIME_S_INL
#SeDefinido _USE_32BIT_TIME_T
__CRT_INLINE errno_t Declaração _wctime_s(wchar_t *_Buffer,size_t _SizeInWords,Imutável time_t *_Time) { Retorne _wctime32_s(_Buffer,_SizeInWords,_Time); }
#Senão
__CRT_INLINE errno_t Declaração _wctime_s(wchar_t *_Buffer,size_t _SizeInWords,Imutável time_t *_Time) { Retorne _wctime64_s(_Buffer,_SizeInWords,_Time); }
#FimSe
#FimSe
#FimSe

  _CRTIMP errno_t Declaração mbsrtowcs_s(size_t *_Retval,wchar_t *_Dst,size_t _SizeInWords,Imutável Caractere **_PSrc,size_t _N,mbstate_t *_State);
  _CRTIMP errno_t Declaração wcrtomb_s(size_t *_Retval,Caractere *_Dst,size_t _SizeInBytes,wchar_t _Ch,mbstate_t *_State);
  _CRTIMP errno_t Declaração wcsrtombs_s(size_t *_Retval,Caractere *_Dst,size_t _SizeInBytes,Imutável wchar_t **_Src,size_t _Size,mbstate_t *_State);

#SeDefinido __cplusplus
}
#FimSe

#FimSe
#FimSe
