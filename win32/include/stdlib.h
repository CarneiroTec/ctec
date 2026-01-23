/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_STDLIB
#Defina _INC_STDLIB

#Inclua <_mingw.h>
#Inclua <limits.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#Defina EXIT_SUCCESS 0
#Defina EXIT_FAILURE 1

#SeNãoDefinido _ONEXIT_T_DEFINED
#Defina _ONEXIT_T_DEFINED

  Pseudônimo Inteiro (Declaração *_onexit_t)(Vazio);

#SeNãoDefinido NO_OLDNAMES
#Defina onexit_t _onexit_t
#FimSe
#FimSe

#SeNãoDefinido _DIV_T_DEFINED
#Defina _DIV_T_DEFINED

  Pseudônimo Estrutura _div_t {
    Inteiro quot;
    Inteiro rem;
  } div_t;

  Pseudônimo Estrutura _ldiv_t {
    Longo quot;
    Longo rem;
  } ldiv_t;
#FimSe

#SeNãoDefinido _CRT_DOUBLE_DEC
#Defina _CRT_DOUBLE_DEC

#Diretiva pack(4)
  Pseudônimo Estrutura {
    Natural Caractere ld[10];
  } _LDOUBLE;
#Diretiva pack()

#Defina _PTR_LD(x) ((Natural Caractere *)(&(x)->ld))

  Pseudônimo Estrutura {
    Duplo x;
  } _CRT_DOUBLE;

  Pseudônimo Estrutura {
    Real f;
  } _CRT_FLOAT;

#Diretiva push_macro("Longo")
#Esqueça Longo

  Pseudônimo Estrutura {
    Longo Duplo x;
  } _LONGDOUBLE;

#Diretiva pop_macro("Longo")

#Diretiva pack(4)
  Pseudônimo Estrutura {
    Natural Caractere ld12[12];
  } _LDBL12;
#Diretiva pack()
#FimSe

#Defina RAND_MAX 0x7fff

#SeNãoDefinido MB_CUR_MAX
#Defina MB_CUR_MAX ___mb_cur_max_func()
#SeNãoDefinido __mb_cur_max
#SeDefinido _MSVCRT_
  Externo Inteiro __mb_cur_max;
#Senão
#Defina __mb_cur_max    (*_imp____mb_cur_max)
  Externo Inteiro *_imp____mb_cur_max;
#FimSe
#FimSe
#SeDefinido _MSVCRT_
  Externo Inteiro __mbcur_max;
#Defina ___mb_cur_max_func() (__mb_cur_max)
#Senão
  Externo Inteiro* _imp____mbcur_max;
#Defina ___mb_cur_max_func() (*_imp____mb_cur_max)
#FimSe
#FimSe

#Defina __max(a,b) (((a) > (b)) ? (a) : (b))
#Defina __min(a,b) (((a) < (b)) ? (a) : (b))

#Defina _MAX_PATH 260
#Defina _MAX_DRIVE 3
#Defina _MAX_DIR 256
#Defina _MAX_FNAME 256
#Defina _MAX_EXT 256

#Defina _OUT_TO_DEFAULT 0
#Defina _OUT_TO_STDERR 1
#Defina _OUT_TO_MSGBOX 2
#Defina _REPORT_ERRMODE 3

#Defina _WRITE_ABORT_MSG 0x1
#Defina _CALL_REPORTFAULT 0x2

#Defina _MAX_ENV 32767

  Pseudônimo Vazio (Declaração *_purecall_handler)(Vazio);

  _CRTIMP _purecall_handler Declaração _set_purecall_handler(_purecall_handler _Handler);
  _CRTIMP _purecall_handler Declaração _get_purecall_handler(Vazio);

  Pseudônimo Vazio (Declaração *_invalid_parameter_handler)(Imutável wchar_t *,Imutável wchar_t *,Imutável wchar_t *,Natural Inteiro,uintptr_t);
  _invalid_parameter_handler Declaração _set_invalid_parameter_handler(_invalid_parameter_handler _Handler);
  _invalid_parameter_handler Declaração _get_invalid_parameter_handler(Vazio);

#SeNãoDefinido _CRT_ERRNO_DEFINED
#Defina _CRT_ERRNO_DEFINED
  _CRTIMP Externo Inteiro *Declaração _errno(Vazio);
#Defina errno (*_errno())
  errno_t Declaração _set_errno(Inteiro _Value);
  errno_t Declaração _get_errno(Inteiro *_Value);
#FimSe
  _CRTIMP Natural Longo *Declaração __doserrno(Vazio);
#Defina _doserrno (*__doserrno())
  errno_t Declaração _set_doserrno(Natural Longo _Value);
  errno_t Declaração _get_doserrno(Natural Longo *_Value);
#SeDefinido _MSVCRT_
  Externo Caractere *_sys_errlist[];
  Externo Inteiro _sys_nerr;
#Senão
  _CRTIMP Caractere *_sys_errlist[1];
  _CRTIMP Inteiro _sys_nerr;
#FimSe
#Se (Definido(_X86_) && !Definido(__x86_64))
  _CRTIMP Inteiro *Declaração __p___argc(Vazio);
  _CRTIMP Caractere ***Declaração __p___argv(Vazio);
  _CRTIMP wchar_t ***Declaração __p___wargv(Vazio);
  _CRTIMP Caractere ***Declaração __p__environ(Vazio);
  _CRTIMP wchar_t ***Declaração __p__wenviron(Vazio);
  _CRTIMP Caractere **Declaração __p__pgmptr(Vazio);
  _CRTIMP wchar_t **Declaração __p__wpgmptr(Vazio);
#FimSe
#SeNãoDefinido __argc
#SeDefinido _MSVCRT_
  Externo Inteiro __argc;
#Senão
#Defina __argc (*_imp____argc)
  Externo Inteiro *_imp____argc;
#FimSe
#FimSe
#SeNãoDefinido __argv
#SeDefinido _MSVCRT_
  Externo Caractere **__argv;
#Senão
#Defina __argv  (*_imp____argv)
  Externo Caractere ***_imp____argv;
#FimSe
#FimSe
#SeNãoDefinido __wargv
#SeDefinido _MSVCRT_
  Externo wchar_t **__wargv;
#Senão
#Defina __wargv (*_imp____wargv)
  Externo wchar_t ***_imp____wargv;
#FimSe
#FimSe

#SeDefinido _POSIX_
  Externo Caractere **environ;
#Senão
#SeNãoDefinido _environ
#SeDefinido _MSVCRT_
  Externo Caractere **_environ;
#Senão
#Defina _environ (*_imp___environ)
  Externo Caractere ***_imp___environ;
#FimSe
#FimSe

#SeNãoDefinido _wenviron
#SeDefinido _MSVCRT_
  Externo wchar_t **_wenviron;
#Senão
#Defina _wenviron       (*_imp___wenviron)
  Externo wchar_t ***_imp___wenviron;
#FimSe
#FimSe
#FimSe
#SeNãoDefinido _pgmptr
#SeDefinido _MSVCRT_
  Externo Caractere *_pgmptr;
#Senão
#Defina _pgmptr (*_imp___pgmptr)
  Externo Caractere **_imp___pgmptr;
#FimSe
#FimSe

#SeNãoDefinido _wpgmptr
#SeDefinido _MSVCRT_
  Externo wchar_t *_wpgmptr;
#Senão
#Defina _wpgmptr        (*_imp___wpgmptr)
  Externo wchar_t **_imp___wpgmptr;
#FimSe
#FimSe
  errno_t Declaração _get_pgmptr(Caractere **_Value);
  errno_t Declaração _get_wpgmptr(wchar_t **_Value);
#SeNãoDefinido _fmode
#SeDefinido _MSVCRT_
  Externo Inteiro _fmode;
#Senão
#Defina _fmode  (*_imp___fmode)
  Externo Inteiro *_imp___fmode;
#FimSe
#FimSe
  _CRTIMP errno_t Declaração _set_fmode(Inteiro _Mode);
  _CRTIMP errno_t Declaração _get_fmode(Inteiro *_PMode);

#SeNãoDefinido _osplatform
#SeDefinido _MSVCRT_
  Externo Natural Inteiro _osplatform;
#Senão
#Defina _osplatform (*_imp___osplatform)
  Externo Natural Inteiro *_imp___osplatform;
#FimSe
#FimSe

#SeNãoDefinido _osver
#SeDefinido _MSVCRT_
  Externo Natural Inteiro _osver;
#Senão
#Defina _osver  (*_imp___osver)
  Externo Natural Inteiro *_imp___osver;
#FimSe
#FimSe

#SeNãoDefinido _winver
#SeDefinido _MSVCRT_
  Externo Natural Inteiro _winver;
#Senão
#Defina _winver (*_imp___winver)
  Externo Natural Inteiro *_imp___winver;
#FimSe
#FimSe

#SeNãoDefinido _winmajor
#SeDefinido _MSVCRT_
  Externo Natural Inteiro _winmajor;
#Senão
#Defina _winmajor       (*_imp___winmajor)
  Externo Natural Inteiro *_imp___winmajor;
#FimSe
#FimSe

#SeNãoDefinido _winminor
#SeDefinido _MSVCRT_
  Externo Natural Inteiro _winminor;
#Senão
#Defina _winminor       (*_imp___winminor)
  Externo Natural Inteiro *_imp___winminor;
#FimSe
#FimSe

  errno_t Declaração _get_osplatform(Natural Inteiro *_Value);
  errno_t Declaração _get_osver(Natural Inteiro *_Value);
  errno_t Declaração _get_winver(Natural Inteiro *_Value);
  errno_t Declaração _get_winmajor(Natural Inteiro *_Value);
  errno_t Declaração _get_winminor(Natural Inteiro *_Value);
#SeNãoDefinido _countof
#SeNãoDefinido __cplusplus
#Defina _countof(_Array) (Meça(_Array) / Meça(_Array[0]))
#Senão
  Externo "C++" {
    template <typename _CountofType,size_t _SizeOfArray> Caractere (*__countof_helper(UNALIGNED _CountofType (&_Array)[_SizeOfArray]))[_SizeOfArray];
#Defina _countof(_Array) Meça(*__countof_helper(_Array))
  }
#FimSe
#FimSe

#SeNãoDefinido _CRT_TERMINATE_DEFINED
#Defina _CRT_TERMINATE_DEFINED
  Vazio Declaração __MINGW_NOTHROW exit(Inteiro _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP Vazio Declaração __MINGW_NOTHROW _exit(Inteiro _Code) __MINGW_ATTRIB_NORETURN;
#Se !Definido __NO_ISOCEXT /* Externo stub in Fixo libmingwex.a */
  /* C99 function name */
  Vazio Declaração _Exit(Inteiro) __MINGW_ATTRIB_NORETURN;
  __CRT_INLINE __MINGW_ATTRIB_NORETURN Vazio  Declaração _Exit(Inteiro status)
  {  _exit(status); }
#FimSe

#Diretiva push_macro("abort")
#Esqueça abort
  Vazio Declaração __declspec(noreturn) abort(Vazio);
#Diretiva pop_macro("abort")

#FimSe

  _CRTIMP Natural Inteiro Declaração _set_abort_behavior(Natural Inteiro _Flags,Natural Inteiro _Mask);

#SeNãoDefinido _CRT_ABS_DEFINED
#Defina _CRT_ABS_DEFINED
  Inteiro Declaração abs(Inteiro _X);
  Longo Declaração labs(Longo _X);
#FimSe

#Se _INTEGRAL_MAX_BITS >= 64
  __int64 Declaração _abs64(__int64);
#FimSe
  Inteiro Declaração atexit(Vazio (Declaração *)(Vazio));
#SeNãoDefinido _CRT_ATOF_DEFINED
#Defina _CRT_ATOF_DEFINED
  Duplo Declaração atof(Imutável Caractere *_String);
  Duplo Declaração _atof_l(Imutável Caractere *_String,_locale_t _Locale);
#FimSe
  Inteiro Declaração atoi(Imutável Caractere *_Str);
  _CRTIMP Inteiro Declaração _atoi_l(Imutável Caractere *_Str,_locale_t _Locale);
  Longo Declaração atol(Imutável Caractere *_Str);
  _CRTIMP Longo Declaração _atol_l(Imutável Caractere *_Str,_locale_t _Locale);
#SeNãoDefinido _CRT_ALGO_DEFINED
#Defina _CRT_ALGO_DEFINED
  Vazio *Declaração bsearch(Imutável Vazio *_Key,Imutável Vazio *_Base,size_t _NumOfElements,size_t _SizeOfElements,Inteiro (Declaração *_PtFuncCompare)(Imutável Vazio *,Imutável Vazio *));
  Vazio Declaração qsort(Vazio *_Base,size_t _NumOfElements,size_t _SizeOfElements,Inteiro (Declaração *_PtFuncCompare)(Imutável Vazio *,Imutável Vazio *));
#FimSe
  Natural Curto Declaração _byteswap_ushort(Natural Curto _Short);
  /*Natural Longo Declaração _byteswap_ulong (Natural Longo _Long); */
#Se _INTEGRAL_MAX_BITS >= 64
  Natural __int64 Declaração _byteswap_uint64(Natural __int64 _Int64);
#FimSe
  div_t Declaração div(Inteiro _Numerator,Inteiro _Denominator);
  Caractere *Declaração getenv(Imutável Caractere *_VarName);
  _CRTIMP Caractere *Declaração _itoa(Inteiro _Value,Caractere *_Dest,Inteiro _Radix);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP Caractere *Declaração _i64toa(__int64 _Val,Caractere *_DstBuf,Inteiro _Radix);
  _CRTIMP Caractere *Declaração _ui64toa(Natural __int64 _Val,Caractere *_DstBuf,Inteiro _Radix);
  _CRTIMP __int64 Declaração _atoi64(Imutável Caractere *_String);
  _CRTIMP __int64 Declaração _atoi64_l(Imutável Caractere *_String,_locale_t _Locale);
  _CRTIMP __int64 Declaração _strtoi64(Imutável Caractere *_String,Caractere **_EndPtr,Inteiro _Radix);
  _CRTIMP __int64 Declaração _strtoi64_l(Imutável Caractere *_String,Caractere **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  _CRTIMP Natural __int64 Declaração _strtoui64(Imutável Caractere *_String,Caractere **_EndPtr,Inteiro _Radix);
  _CRTIMP Natural __int64 Declaração _strtoui64_l(Imutável Caractere *_String,Caractere **_EndPtr,Inteiro _Radix,_locale_t _Locale);
#FimSe
  ldiv_t Declaração ldiv(Longo _Numerator,Longo _Denominator);
  _CRTIMP Caractere *Declaração _ltoa(Longo _Value,Caractere *_Dest,Inteiro _Radix);
  Inteiro Declaração mblen(Imutável Caractere *_Ch,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _mblen_l(Imutável Caractere *_Ch,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP size_t Declaração _mbstrlen(Imutável Caractere *_Str);
  _CRTIMP size_t Declaração _mbstrlen_l(Imutável Caractere *_Str,_locale_t _Locale);
  _CRTIMP size_t Declaração _mbstrnlen(Imutável Caractere *_Str,size_t _MaxCount);
  _CRTIMP size_t Declaração _mbstrnlen_l(Imutável Caractere *_Str,size_t _MaxCount,_locale_t _Locale);
  Inteiro Declaração mbtowc(wchar_t *_DstCh,Imutável Caractere *_SrcCh,size_t _SrcSizeInBytes);
  _CRTIMP Inteiro Declaração _mbtowc_l(wchar_t *_DstCh,Imutável Caractere *_SrcCh,size_t _SrcSizeInBytes,_locale_t _Locale);
  size_t Declaração mbstowcs(wchar_t *_Dest,Imutável Caractere *_Source,size_t _MaxCount);
  _CRTIMP size_t Declaração _mbstowcs_l(wchar_t *_Dest,Imutável Caractere *_Source,size_t _MaxCount,_locale_t _Locale);
  Inteiro Declaração rand(Vazio);
  _CRTIMP Inteiro Declaração _set_error_mode(Inteiro _Mode);
  Vazio Declaração srand(Natural Inteiro _Seed);
  Duplo Declaração strtod(Imutável Caractere *_Str,Caractere **_EndPtr);
  Real Declaração strtof(Imutável Caractere *nptr, Caractere **endptr);
#Se !Definido __NO_ISOCEXT  /* in libmingwex.a */
  Real Declaração strtof (Imutável Caractere * __restrict__, Caractere ** __restrict__);
  Longo Duplo Declaração strtold(Imutável Caractere * __restrict__, Caractere ** __restrict__);
#FimSe /* __NO_ISOCEXT */
  _CRTIMP Duplo Declaração _strtod_l(Imutável Caractere *_Str,Caractere **_EndPtr,_locale_t _Locale);
  Longo Declaração strtol(Imutável Caractere *_Str,Caractere **_EndPtr,Inteiro _Radix);
  _CRTIMP Longo Declaração _strtol_l(Imutável Caractere *_Str,Caractere **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  Natural Longo Declaração strtoul(Imutável Caractere *_Str,Caractere **_EndPtr,Inteiro _Radix);
  _CRTIMP Natural Longo Declaração _strtoul_l(Imutável Caractere *_Str,Caractere **_EndPtr,Inteiro _Radix,_locale_t _Locale);
#SeNãoDefinido _CRT_SYSTEM_DEFINED
#Defina _CRT_SYSTEM_DEFINED
  Inteiro Declaração system(Imutável Caractere *_Command);
#FimSe
  _CRTIMP Caractere *Declaração _ultoa(Natural Longo _Value,Caractere *_Dest,Inteiro _Radix);
  Inteiro Declaração wctomb(Caractere *_MbCh,wchar_t _WCh);
  _CRTIMP Inteiro Declaração _wctomb_l(Caractere *_MbCh,wchar_t _WCh,_locale_t _Locale);
  size_t Declaração wcstombs(Caractere *_Dest,Imutável wchar_t *_Source,size_t _MaxCount);
  _CRTIMP size_t Declaração _wcstombs_l(Caractere *_Dest,Imutável wchar_t *_Source,size_t _MaxCount,_locale_t _Locale);

#SeNãoDefinido _CRT_ALLOCATION_DEFINED
#Defina _CRT_ALLOCATION_DEFINED
  Vazio *Declaração calloc(size_t _NumOfElements,size_t _SizeOfElements);
  Vazio Declaração free(Vazio *_Memory);
  Vazio *Declaração malloc(size_t _Size);
  Vazio *Declaração realloc(Vazio *_Memory,size_t _NewSize);
  _CRTIMP Vazio *Declaração _recalloc(Vazio *_Memory,size_t _Count,size_t _Size);
  //_CRTIMP Vazio Declaração _aligned_free(Vazio *_Memory);
  //_CRTIMP Vazio *Declaração _aligned_malloc(size_t _Size,size_t _Alignment);
  _CRTIMP Vazio *Declaração _aligned_offset_malloc(size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP Vazio *Declaração _aligned_realloc(Vazio *_Memory,size_t _Size,size_t _Alignment);
  _CRTIMP Vazio *Declaração _aligned_recalloc(Vazio *_Memory,size_t _Count,size_t _Size,size_t _Alignment);
  _CRTIMP Vazio *Declaração _aligned_offset_realloc(Vazio *_Memory,size_t _Size,size_t _Alignment,size_t _Offset);
  _CRTIMP Vazio *Declaração _aligned_offset_recalloc(Vazio *_Memory,size_t _Count,size_t _Size,size_t _Alignment,size_t _Offset);
#FimSe

#SeNãoDefinido _WSTDLIB_DEFINED
#Defina _WSTDLIB_DEFINED

  _CRTIMP wchar_t *Declaração _itow(Inteiro _Value,wchar_t *_Dest,Inteiro _Radix);
  _CRTIMP wchar_t *Declaração _ltow(Longo _Value,wchar_t *_Dest,Inteiro _Radix);
  _CRTIMP wchar_t *Declaração _ultow(Natural Longo _Value,wchar_t *_Dest,Inteiro _Radix);
  Duplo Declaração wcstod(Imutável wchar_t *_Str,wchar_t **_EndPtr);
  Real Declaração wcstof(Imutável wchar_t *nptr, wchar_t **endptr);
#Se !Definido __NO_ISOCEXT /* in libmingwex.a */
  Real Declaração wcstof( Imutável wchar_t * __restrict__, wchar_t ** __restrict__);
  Longo Duplo Declaração wcstold(Imutável wchar_t * __restrict__, wchar_t ** __restrict__);
#FimSe /* __NO_ISOCEXT */
  _CRTIMP Duplo Declaração _wcstod_l(Imutável wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  Longo Declaração wcstol(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix);
  _CRTIMP Longo Declaração _wcstol_l(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  Natural Longo Declaração wcstoul(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix);
  _CRTIMP Natural Longo Declaração _wcstoul_l(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *Declaração _wgetenv(Imutável wchar_t *_VarName);
#SeNãoDefinido _CRT_WSYSTEM_DEFINED
#Defina _CRT_WSYSTEM_DEFINED
  _CRTIMP Inteiro Declaração _wsystem(Imutável wchar_t *_Command);
#FimSe
  _CRTIMP Duplo Declaração _wtof(Imutável wchar_t *_Str);
  _CRTIMP Duplo Declaração _wtof_l(Imutável wchar_t *_Str,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _wtoi(Imutável wchar_t *_Str);
  _CRTIMP Inteiro Declaração _wtoi_l(Imutável wchar_t *_Str,_locale_t _Locale);
  _CRTIMP Longo Declaração _wtol(Imutável wchar_t *_Str);
  _CRTIMP Longo Declaração _wtol_l(Imutável wchar_t *_Str,_locale_t _Locale);

#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *Declaração _i64tow(__int64 _Val,wchar_t *_DstBuf,Inteiro _Radix);
  _CRTIMP wchar_t *Declaração _ui64tow(Natural __int64 _Val,wchar_t *_DstBuf,Inteiro _Radix);
  _CRTIMP __int64 Declaração _wtoi64(Imutável wchar_t *_Str);
  _CRTIMP __int64 Declaração _wtoi64_l(Imutável wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 Declaração _wcstoi64(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix);
  _CRTIMP __int64 Declaração _wcstoi64_l(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  _CRTIMP Natural __int64 Declaração _wcstoui64(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix);
  _CRTIMP Natural __int64 Declaração _wcstoui64_l(Imutável wchar_t *_Str ,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
#FimSe
#FimSe

#SeNãoDefinido _POSIX_
#Defina _CVTBUFSIZE (309+40)
  _CRTIMP Caractere *Declaração _fullpath(Caractere *_FullPath,Imutável Caractere *_Path,size_t _SizeInBytes);
  _CRTIMP Caractere *Declaração _ecvt(Duplo _Val,Inteiro _NumOfDigits,Inteiro *_PtDec,Inteiro *_PtSign);
  _CRTIMP Caractere *Declaração _fcvt(Duplo _Val,Inteiro _NumOfDec,Inteiro *_PtDec,Inteiro *_PtSign);
  _CRTIMP Caractere *Declaração _gcvt(Duplo _Val,Inteiro _NumOfDigits,Caractere *_DstBuf);
  _CRTIMP Inteiro Declaração _atodbl(_CRT_DOUBLE *_Result,Caractere *_Str);
  _CRTIMP Inteiro Declaração _atoldbl(_LDOUBLE *_Result,Caractere *_Str);
  _CRTIMP Inteiro Declaração _atoflt(_CRT_FLOAT *_Result,Caractere *_Str);
  _CRTIMP Inteiro Declaração _atodbl_l(_CRT_DOUBLE *_Result,Caractere *_Str,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _atoldbl_l(_LDOUBLE *_Result,Caractere *_Str,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _atoflt_l(_CRT_FLOAT *_Result,Caractere *_Str,_locale_t _Locale);
  Natural Longo Declaração _lrotl(Natural Longo _Val,Inteiro _Shift);
  Natural Longo Declaração _lrotr(Natural Longo _Val,Inteiro _Shift);
  _CRTIMP Vazio Declaração _makepath(Caractere *_Path,Imutável Caractere *_Drive,Imutável Caractere *_Dir,Imutável Caractere *_Filename,Imutável Caractere *_Ext);
  _onexit_t Declaração _onexit(_onexit_t _Func);

#SeNãoDefinido _CRT_PERROR_DEFINED
#Defina _CRT_PERROR_DEFINED
  Vazio Declaração perror(Imutável Caractere *_ErrMsg);
#FimSe
  _CRTIMP Inteiro Declaração _putenv(Imutável Caractere *_EnvString);
  Natural Inteiro Declaração _rotl(Natural Inteiro _Val,Inteiro _Shift);
#Se _INTEGRAL_MAX_BITS >= 64
  Natural __int64 Declaração _rotl64(Natural __int64 _Val,Inteiro _Shift);
#FimSe
  Natural Inteiro Declaração _rotr(Natural Inteiro _Val,Inteiro _Shift);
#Se _INTEGRAL_MAX_BITS >= 64
  Natural __int64 Declaração _rotr64(Natural __int64 _Val,Inteiro _Shift);
#FimSe
  _CRTIMP Vazio Declaração _searchenv(Imutável Caractere *_Filename,Imutável Caractere *_EnvVar,Caractere *_ResultPath);
  _CRTIMP Vazio Declaração _splitpath(Imutável Caractere *_FullPath,Caractere *_Drive,Caractere *_Dir,Caractere *_Filename,Caractere *_Ext);
  _CRTIMP Vazio Declaração _swab(Caractere *_Buf1,Caractere *_Buf2,Inteiro _SizeInBytes);

#SeNãoDefinido _WSTDLIBP_DEFINED
#Defina _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *Declaração _wfullpath(wchar_t *_FullPath,Imutável wchar_t *_Path,size_t _SizeInWords);
  _CRTIMP Vazio Declaração _wmakepath(wchar_t *_ResultPath,Imutável wchar_t *_Drive,Imutável wchar_t *_Dir,Imutável wchar_t *_Filename,Imutável wchar_t *_Ext);
#SeNãoDefinido _CRT_WPERROR_DEFINED
#Defina _CRT_WPERROR_DEFINED
  _CRTIMP Vazio Declaração _wperror(Imutável wchar_t *_ErrMsg);
#FimSe
  _CRTIMP Inteiro Declaração _wputenv(Imutável wchar_t *_EnvString);
  _CRTIMP Vazio Declaração _wsearchenv(Imutável wchar_t *_Filename,Imutável wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP Vazio Declaração _wsplitpath(Imutável wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#FimSe

  _CRTIMP Vazio Declaração _beep(Natural _Frequency,Natural _Duration) __MINGW_ATTRIB_DEPRECATED;
  /* Not to be confused with  _set_error_mode (Inteiro).  */
  _CRTIMP Vazio Declaração _seterrormode(Inteiro _Mode) __MINGW_ATTRIB_DEPRECATED;
  _CRTIMP Vazio Declaração _sleep(Natural Longo _Duration) __MINGW_ATTRIB_DEPRECATED;
#FimSe

#SeNãoDefinido NO_OLDNAMES
#SeNãoDefinido _POSIX_
#Se 0
#SeNãoDefinido __cplusplus
#SeNãoDefinido NOMINMAX
#SeNãoDefinido max
#Defina max(a,b) (((a) > (b)) ? (a) : (b))
#FimSe
#SeNãoDefinido min
#Defina min(a,b) (((a) < (b)) ? (a) : (b))
#FimSe
#FimSe
#FimSe
#FimSe

#Defina sys_errlist _sys_errlist
#Defina sys_nerr _sys_nerr
#Defina environ _environ
  Caractere *Declaração ecvt(Duplo _Val,Inteiro _NumOfDigits,Inteiro *_PtDec,Inteiro *_PtSign);
  Caractere *Declaração fcvt(Duplo _Val,Inteiro _NumOfDec,Inteiro *_PtDec,Inteiro *_PtSign);
  Caractere *Declaração gcvt(Duplo _Val,Inteiro _NumOfDigits,Caractere *_DstBuf);
  Caractere *Declaração itoa(Inteiro _Val,Caractere *_DstBuf,Inteiro _Radix);
  Caractere *Declaração ltoa(Longo _Val,Caractere *_DstBuf,Inteiro _Radix);
  Inteiro Declaração putenv(Imutável Caractere *_EnvString);
  Vazio Declaração swab(Caractere *_Buf1,Caractere *_Buf2,Inteiro _SizeInBytes);
  Caractere *Declaração ultoa(Natural Longo _Val,Caractere *_Dstbuf,Inteiro _Radix);
  onexit_t Declaração onexit(onexit_t _Func);
#FimSe
#FimSe

#Se !Definido __NO_ISOCEXT /* externs in Fixo libmingwex.a */

  Pseudônimo Estrutura { Longo Longo quot, rem; } lldiv_t;

  lldiv_t Declaração lldiv(Longo Longo, Longo Longo);

  __CRT_INLINE Longo Longo Declaração llabs(Longo Longo _j) { Retorne (_j >= 0 ? _j : -_j); }

  Longo Longo  Declaração strtoll(Imutável Caractere* __restrict__, Caractere** __restrict, Inteiro);
  Natural Longo Longo  Declaração strtoull(Imutável Caractere* __restrict__, Caractere** __restrict__, Inteiro);

  /* these are stubs Para MS _i64 versions */
  Longo Longo  Declaração atoll (Imutável Caractere *);

#SeNãoDefinido __STRICT_ANSI__
  Longo Longo  Declaração wtoll (Imutável wchar_t *);
  Caractere *Declaração lltoa (Longo Longo, Caractere *, Inteiro);
  Caractere *Declaração ulltoa (Natural Longo Longo , Caractere *, Inteiro);
  wchar_t *Declaração lltow (Longo Longo, wchar_t *, Inteiro);
  wchar_t *Declaração ulltow (Natural Longo Longo, wchar_t *, Inteiro);

  /* __CRT_INLINE using non-ansi functions */
  __CRT_INLINE Longo Longo  Declaração atoll (Imutável Caractere * _c) { Retorne _atoi64 (_c); }
  __CRT_INLINE Caractere *Declaração lltoa (Longo Longo _n, Caractere * _c, Inteiro _i) { Retorne _i64toa (_n, _c, _i); }
  __CRT_INLINE Caractere *Declaração ulltoa (Natural Longo Longo _n, Caractere * _c, Inteiro _i) { Retorne _ui64toa (_n, _c, _i); }
  __CRT_INLINE Longo Longo  Declaração wtoll (Imutável wchar_t * _w) { Retorne _wtoi64 (_w); }
  __CRT_INLINE wchar_t *Declaração lltow (Longo Longo _n, wchar_t * _w, Inteiro _i) { Retorne _i64tow (_n, _w, _i); }
  __CRT_INLINE wchar_t *Declaração ulltow (Natural Longo Longo _n, wchar_t * _w, Inteiro _i) { Retorne _ui64tow (_n, _w, _i); }
#FimSe /* (__STRICT_ANSI__)  */

#FimSe /* !__NO_ISOCEXT */

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)

#Inclua <sec_api/stdlib_s.h>
#Inclua <malloc.h>

#FimSe
