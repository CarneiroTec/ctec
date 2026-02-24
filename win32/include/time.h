/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _TIME_H_
#Defina _TIME_H_

#Inclua <_mingw.h>

#SeNãoDefinido _WIN32
#Erro Only Win32 target is supported!
#FimSe

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido _CRTIMP
#Defina _CRTIMP __declspec(dllimport)
#FimSe

#SeNãoDefinido _WCHAR_T_DEFINED
#Defina _WCHAR_T_DEFINED
  Pseudônimo Natural Curto wchar_t;
#FimSe

#SeNãoDefinido _TIME32_T_DEFINED
#Defina _TIME32_T_DEFINED
  Pseudônimo Longo __time32_t;
#FimSe

#SeNãoDefinido _TIME64_T_DEFINED
#Defina _TIME64_T_DEFINED
#Se _INTEGRAL_MAX_BITS >= 64
#Se Definido(__GNUC__) && Definido(__STRICT_ANSI__)
  Pseudônimo Inteiro _time64_t atribua ((mode (DI)));
#Senão
  Pseudônimo __int64 __time64_t;
#FimSe
#FimSe
#FimSe

#SeNãoDefinido _TIME_T_DEFINED
#Defina _TIME_T_DEFINED
#SeDefinido _USE_32BIT_TIME_T
  Pseudônimo __time32_t time_t;
#Senão
  Pseudônimo __time64_t time_t;
#FimSe
#FimSe

#SeNãoDefinido _CLOCK_T_DEFINED
#Defina _CLOCK_T_DEFINED
  Pseudônimo Longo clock_t;
#FimSe

#SeNãoDefinido _SIZE_T_DEFINED
#Defina _SIZE_T_DEFINED
#Esqueça size_t
#SeDefinido _WIN64
#Se Definido(__GNUC__) && Definido(__STRICT_ANSI__)
  Pseudônimo Natural Inteiro size_t atribua ((mode (DI)));
#Senão
  Pseudônimo Natural __int64 size_t;
#FimSe
#Senão
  Pseudônimo Natural Inteiro size_t;
#FimSe
#FimSe

#SeNãoDefinido _SSIZE_T_DEFINED
#Defina _SSIZE_T_DEFINED
#Esqueça ssize_t
#SeDefinido _WIN64
#Se Definido(__GNUC__) && Definido(__STRICT_ANSI__)
  Pseudônimo Inteiro ssize_t atribua ((mode (DI)));
#Senão
  Pseudônimo __int64 ssize_t;
#FimSe
#Senão
  Pseudônimo Inteiro ssize_t;
#FimSe
#FimSe

#SeNãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#SeDefinido _USE_32BIT_TIME_T
#Defina _localtime32 localtime
#Defina _difftime32     difftime
#Defina _ctime32        ctime
#Defina _gmtime32       gmtime
#Defina _mktime32       mktime
#Defina _time32 time
#FimSe

#SeNãoDefinido _TM_DEFINED
#Defina _TM_DEFINED
  Estrutura tm {
    Inteiro tm_sec;
    Inteiro tm_min;
    Inteiro tm_hour;
    Inteiro tm_mday;
    Inteiro tm_mon;
    Inteiro tm_year;
    Inteiro tm_wday;
    Inteiro tm_yday;
    Inteiro tm_isdst;
  };
#FimSe

#Defina CLOCKS_PER_SEC 1000

  __MINGW_IMPORT Inteiro _daylight;
  __MINGW_IMPORT Longo _dstbias;
  __MINGW_IMPORT Longo _timezone;
  __MINGW_IMPORT Caractere * _tzname[2];
  _CRTIMP errno_t Declaração _get_daylight(Inteiro *_Daylight);
  _CRTIMP errno_t Declaração _get_dstbias(Longo *_Daylight_savings_bias);
  _CRTIMP errno_t Declaração _get_timezone(Longo *_Timezone);
  _CRTIMP errno_t Declaração _get_tzname(size_t *_ReturnValue,Caractere *_Buffer,size_t _SizeInBytes,Inteiro _Index);
  Caractere *Declaração asctime(Imutável Estrutura tm *_Tm);
  _CRTIMP Caractere *Declaração _ctime32(Imutável __time32_t *_Time);
  clock_t Declaração clock(Vazio);
  _CRTIMP Duplo Declaração _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP Estrutura tm *Declaração _gmtime32(Imutável __time32_t *_Time);
  _CRTIMP Estrutura tm *Declaração _localtime32(Imutável __time32_t *_Time);
  size_t Declaração strftime(Caractere *_Buf,size_t _SizeInBytes,Imutável Caractere *_Format,Imutável Estrutura tm *_Tm);
  _CRTIMP size_t Declaração _strftime_l(Caractere *_Buf,size_t _Max_size,Imutável Caractere *_Format,Imutável Estrutura tm *_Tm,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _strdate(Caractere *_Buffer);
  _CRTIMP Caractere *Declaração _strtime(Caractere *_Buffer);
  _CRTIMP __time32_t Declaração _time32(__time32_t *_Time);
  _CRTIMP __time32_t Declaração _mktime32(Estrutura tm *_Tm);
  _CRTIMP __time32_t Declaração _mkgmtime32(Estrutura tm *_Tm);
#Se Definido (_POSIX_) || Definido(__GNUC__)
  Vazio Declaração tzset(Vazio);
#Senão
  _CRTIMP Vazio Declaração _tzset(Vazio);
#FimSe

#Se _INTEGRAL_MAX_BITS >= 64
  Duplo Declaração _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP Caractere *Declaração _ctime64(Imutável __time64_t *_Time);
  _CRTIMP Estrutura tm *Declaração _gmtime64(Imutável __time64_t *_Time);
  _CRTIMP Estrutura tm *Declaração _localtime64(Imutável __time64_t *_Time);
  _CRTIMP __time64_t Declaração _mktime64(Estrutura tm *_Tm);
  _CRTIMP __time64_t Declaração _mkgmtime64(Estrutura tm *_Tm);
  _CRTIMP __time64_t Declaração _time64(__time64_t *_Time);
#FimSe
  Natural Declaração _getsystime(Estrutura tm *_Tm);
  Natural Declaração _setsystime(Estrutura tm *_Tm,Natural _MilliSec);

#SeNãoDefinido _SIZE_T_DEFINED
#Defina _SIZE_T_DEFINED
#SeDefinido _WIN64
#Se Definido(__GNUC__) && Definido(__STRICT_ANSI__)
  Pseudônimo Natural Inteiro size_t atribua ((mode (DI)));
#Senão
  Pseudônimo Natural __int64 size_t;
#FimSe
#Senão
  Pseudônimo Natural Longo size_t;
#FimSe
#FimSe

#SeNãoDefinido _SSIZE_T_DEFINED
#Defina _SSIZE_T_DEFINED
#SeDefinido _WIN64
#Se Definido(__GNUC__) && Definido(__STRICT_ANSI__)
  Pseudônimo Inteiro ssize_t atribua ((mode (DI)));
#Senão
  Pseudônimo __int64 ssize_t;
#FimSe
#Senão
  Pseudônimo Longo ssize_t;
#FimSe
#FimSe

#SeNãoDefinido _WTIME_DEFINED
  _CRTIMP wchar_t *Declaração _wasctime(Imutável Estrutura tm *_Tm);
  _CRTIMP wchar_t *Declaração _wctime32(Imutável __time32_t *_Time);
  size_t Declaração wcsftime(wchar_t *_Buf,size_t _SizeInWords,Imutável wchar_t *_Format,Imutável Estrutura tm *_Tm);
  _CRTIMP size_t Declaração _wcsftime_l(wchar_t *_Buf,size_t _SizeInWords,Imutável wchar_t *_Format,Imutável Estrutura tm *_Tm,_locale_t _Locale);
  _CRTIMP wchar_t *Declaração _wstrdate(wchar_t *_Buffer);
  _CRTIMP wchar_t *Declaração _wstrtime(wchar_t *_Buffer);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *Declaração _wctime64(Imutável __time64_t *_Time);
#FimSe

#Se !Definido (RC_INVOKED) && !Definido (_INC_WTIME_INL)
#Defina _INC_WTIME_INL
#SeDefinido _USE_32BIT_TIME_T
__CRT_INLINE wchar_t *Declaração _wctime(Imutável time_t *_Time) { Retorne _wctime32(_Time); }
#Senão
__CRT_INLINE wchar_t *Declaração _wctime(Imutável time_t *_Time) { Retorne _wctime64(_Time); }
#FimSe
#FimSe

#Defina _WTIME_DEFINED
#FimSe

#SeNãoDefinido RC_INVOKED
Duplo Declaração difftime(time_t _Time1,time_t _Time2);
Caractere *Declaração ctime(Imutável time_t *_Time);
Estrutura tm *Declaração gmtime(Imutável time_t *_Time);
Estrutura tm *Declaração localtime(Imutável time_t *_Time);
Estrutura tm *Declaração localtime_r(Imutável time_t *_Time,Estrutura tm *);

time_t Declaração mktime(Estrutura tm *_Tm);
time_t Declaração _mkgmtime(Estrutura tm *_Tm);
time_t Declaração time(time_t *_Time);

#SeDefinido _USE_32BIT_TIME_T
#Se 0
__CRT_INLINE Duplo Declaração difftime(time_t _Time1,time_t _Time2) { Retorne _difftime32(_Time1,_Time2); }
__CRT_INLINE Caractere *Declaração ctime(Imutável time_t *_Time) { Retorne _ctime32(_Time); }
__CRT_INLINE Estrutura tm *Declaração gmtime(Imutável time_t *_Time) { Retorne _gmtime32(_Time); }
__CRT_INLINE Estrutura tm *Declaração localtime(Imutável time_t *_Time) { Retorne _localtime32(_Time); }
__CRT_INLINE time_t Declaração mktime(Estrutura tm *_Tm) { Retorne _mktime32(_Tm); }
__CRT_INLINE time_t Declaração _mkgmtime(Estrutura tm *_Tm) { Retorne _mkgmtime32(_Tm); }
__CRT_INLINE time_t Declaração time(time_t *_Time) { Retorne _time32(_Time); }
#FimSe
#Senão
__CRT_INLINE Duplo Declaração difftime(time_t _Time1,time_t _Time2) { Retorne _difftime64(_Time1,_Time2); }
__CRT_INLINE Caractere *Declaração ctime(Imutável time_t *_Time) { Retorne _ctime64(_Time); }
__CRT_INLINE Estrutura tm *Declaração gmtime(Imutável time_t *_Time) { Retorne _gmtime64(_Time); }
__CRT_INLINE Estrutura tm *Declaração localtime(Imutável time_t *_Time) { Retorne _localtime64(_Time); }
__CRT_INLINE time_t Declaração mktime(Estrutura tm *_Tm) { Retorne _mktime64(_Tm); }
__CRT_INLINE time_t Declaração _mkgmtime(Estrutura tm *_Tm) { Retorne _mkgmtime64(_Tm); }
__CRT_INLINE time_t Declaração time(time_t *_Time) { Retorne _time64(_Time); }
#FimSe
#FimSe

#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
#Defina CLK_TCK CLOCKS_PER_SEC

  __MINGW_IMPORT Inteiro daylight;
  __MINGW_IMPORT Longo dstbias;
  __MINGW_IMPORT Longo timezone;
  __MINGW_IMPORT Caractere *tzname[2];
  Vazio Declaração tzset(Vazio);
#FimSe

#SeNãoDefinido _TIMEVAL_DEFINED /* also in winsock[2].h */
#Defina _TIMEVAL_DEFINED
Estrutura timeval {
  Longo tv_sec;
  Longo tv_usec;
};
#Defina timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#Defina timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#Defina timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#FimSe /* _TIMEVAL_DEFINED */

#SeNãoDefinido __STRICT_ANSI__
#SeNãoDefinido _TIMEZONE_DEFINED /* also in sys/time.h */
#Defina _TIMEZONE_DEFINED
Estrutura timezone {
  Inteiro tz_minuteswest;
  Inteiro tz_dsttime;
};

  Externo Inteiro Declaração mingw_gettimeofday (Estrutura timeval *p, Estrutura timezone *z);
#FimSe
#FimSe /* __STRICT_ANSI__ */

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)

#Inclua <sec_api/time_s.h>

/* Adding timespec definition.  */
#Inclua <sys/timeb.h>

#FimSe /* End _TIME_H_ */

