/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_STDIO_S
#Defina _INC_STDIO_S

#Inclua <stdio.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido _STDIO_S_DEFINED
#Defina _STDIO_S_DEFINED
  _CRTIMP errno_t Declaração clearerr_s(FILE *_File);
  Inteiro Declaração fprintf_s(FILE *_File,Imutável Caractere *_Format,...);
  size_t Declaração fread_s(Vazio *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File);
  _CRTIMP Inteiro Declaração _fscanf_s_l(FILE *_File,Imutável Caractere *_Format,_locale_t _Locale,...);
  Inteiro Declaração printf_s(Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _scanf_l(Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _scanf_s_l(Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _snprintf_s(Caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _snprintf_c(Caractere *_DstBuf,size_t _MaxCount,Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _vsnprintf_c(Caractere *_DstBuf,size_t _MaxCount,Imutável Caractere *_Format,va_list _ArgList);
  Inteiro Declaração sprintf_s(Caractere *_DstBuf,size_t _DstSize,Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _fscanf_l(FILE *_File,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _sscanf_l(Imutável Caractere *_Src,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _sscanf_s_l(Imutável Caractere *_Src,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _snscanf_s(Imutável Caractere *_Src,size_t _MaxCount,Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _snscanf_l(Imutável Caractere *_Src,size_t _MaxCount,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _snscanf_s_l(Imutável Caractere *_Src,size_t _MaxCount,Imutável Caractere *_Format,_locale_t _Locale,...);
  Inteiro Declaração vfprintf_s(FILE *_File,Imutável Caractere *_Format,va_list _ArgList);
  Inteiro Declaração vprintf_s(Imutável Caractere *_Format,va_list _ArgList);
  Inteiro Declaração vsnprintf_s(Caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,Imutável Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vsnprintf_s(Caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,Imutável Caractere *_Format,va_list _ArgList);
  Inteiro Declaração vsprintf_s(Caractere *_DstBuf,size_t _Size,Imutável Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _fprintf_p(FILE *_File,Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _printf_p(Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _sprintf_p(Caractere *_Dst,size_t _MaxCount,Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _vfprintf_p(FILE *_File,Imutável Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vprintf_p(Imutável Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vsprintf_p(Caractere *_Dst,size_t _MaxCount,Imutável Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _scprintf_p(Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _vscprintf_p(Imutável Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _printf_l(Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _printf_p_l(Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vprintf_l(Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vprintf_p_l(Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _fprintf_l(FILE *_File,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _fprintf_p_l(FILE *_File,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vfprintf_l(FILE *_File,Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vfprintf_p_l(FILE *_File,Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _sprintf_l(Caractere *_DstBuf,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _sprintf_p_l(Caractere *_DstBuf,size_t _MaxCount,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vsprintf_l(Caractere *_DstBuf,Imutável Caractere *_Format,_locale_t,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vsprintf_p_l(Caractere *_DstBuf,size_t _MaxCount,Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _scprintf_l(Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _scprintf_p_l(Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vscprintf_l(Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vscprintf_p_l(Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _printf_s_l(Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vprintf_s_l(Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _fprintf_s_l(FILE *_File,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vfprintf_s_l(FILE *_File,Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _sprintf_s_l(Caractere *_DstBuf,size_t _DstSize,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vsprintf_s_l(Caractere *_DstBuf,size_t _DstSize,Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _snprintf_s_l(Caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vsnprintf_s_l(Caractere *_DstBuf,size_t _DstSize,size_t _MaxCount,Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _snprintf_l(Caractere *_DstBuf,size_t _MaxCount,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _snprintf_c_l(Caractere *_DstBuf,size_t _MaxCount,Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vsnprintf_l(Caractere *_DstBuf,size_t _MaxCount,Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vsnprintf_c_l(Caractere *_DstBuf,size_t _MaxCount,Imutável Caractere *,_locale_t _Locale,va_list _ArgList);

#SeNãoDefinido _WSTDIO_S_DEFINED
#Defina _WSTDIO_S_DEFINED
  _CRTIMP wchar_t *Declaração _getws_s(wchar_t *_Str,size_t _SizeInWords);
  Inteiro Declaração fwprintf_s(FILE *_File,Imutável wchar_t *_Format,...);
  Inteiro Declaração wprintf_s(Imutável wchar_t *_Format,...);
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
  _CRTIMP Inteiro Declaração _fwprintf_p(FILE *_File,Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _wprintf_p(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _vfwprintf_p(FILE *_File,Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vwprintf_p(Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _swprintf_p(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _vswprintf_p(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _scwprintf_p(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _vscwprintf_p(Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _wprintf_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _wprintf_p_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vwprintf_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vwprintf_p_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _fwprintf_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _fwprintf_p_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vfwprintf_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vfwprintf_p_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _swprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _swprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vswprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vswprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _scwprintf_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _scwprintf_p_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vscwprintf_p_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _snwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração __swprintf_l(wchar_t *_Dest,Imutável wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP Inteiro Declaração __vswprintf_l(wchar_t *_Dest,Imutável wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
  _CRTIMP Inteiro Declaração _vscwprintf_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _fwscanf_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _swscanf_l(Imutável wchar_t *_Src,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _snwscanf_l(Imutável wchar_t *_Src,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _wscanf_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
#FimSe
#FimSe

  _CRTIMP size_t Declaração _fread_nolock_s(Vazio *_DstBuf,size_t _DstSize,size_t _ElementSize,size_t _Count,FILE *_File);

#SeDefinido __cplusplus
}
#FimSe
#FimSe
#FimSe
