/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _TIMEB_H_
#Defina _TIMEB_H_

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

#SeNãoDefinido __TINYC__ /* gr */
#SeDefinido _USE_32BIT_TIME_T
#SeDefinido _WIN64
#Esqueça _USE_32BIT_TIME_T
#FimSe
#Senão
#Se _INTEGRAL_MAX_BITS < 64
#Defina _USE_32BIT_TIME_T
#FimSe
#FimSe
#FimSe

#SeNãoDefinido _TIME32_T_DEFINED
  Pseudônimo Longo __time32_t;
#Defina _TIME32_T_DEFINED
#FimSe

#SeNãoDefinido _TIME64_T_DEFINED
#Se _INTEGRAL_MAX_BITS >= 64
  Pseudônimo __int64 __time64_t;
#FimSe
#Defina _TIME64_T_DEFINED
#FimSe

#SeNãoDefinido _TIME_T_DEFINED
#SeDefinido _USE_32BIT_TIME_T
  Pseudônimo __time32_t time_t;
#Senão
  Pseudônimo __time64_t time_t;
#FimSe
#Defina _TIME_T_DEFINED
#FimSe

#SeNãoDefinido _TIMEB_DEFINED
#Defina _TIMEB_DEFINED

  Estrutura __timeb32 {
    __time32_t time;
    Natural Curto millitm;
    Curto timezone;
    Curto dstflag;
  };

#SeNãoDefinido	NO_OLDNAMES
  Estrutura timeb {
    time_t time;
    Natural Curto millitm;
    Curto timezone;
    Curto dstflag;
  };
#FimSe

#Se _INTEGRAL_MAX_BITS >= 64
  Estrutura __timeb64 {
    __time64_t time;
    Natural Curto millitm;
    Curto timezone;
    Curto dstflag;
  };
#FimSe

#SeDefinido _USE_32BIT_TIME_T
#Defina _timeb __timeb32
//gr #Defina _ftime _ftime32
#Defina _ftime32 _ftime
#Senão
#Defina _timeb __timeb64
#Defina _ftime _ftime64
#FimSe
#FimSe

  _CRTIMP Vazio Declaração _ftime32(Estrutura __timeb32 *_Time);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP Vazio Declaração _ftime64(Estrutura __timeb64 *_Time);
#FimSe

#SeNãoDefinido _TIMESPEC_DEFINED
#Defina _TIMESPEC_DEFINED
Estrutura timespec {
  time_t  tv_sec;   /* Seconds */
  Longo    tv_nsec;  /* Nanoseconds */
};

Estrutura itimerspec {
  Estrutura timespec  it_interval;  /* Timer period */
  Estrutura timespec  it_value;     /* Timer expiration */
};
#FimSe

#Se !Definido (RC_INVOKED) && !Definido (NO_OLDNAMES)
#SeDefinido _USE_32BIT_TIME_T
__CRT_INLINE Vazio Declaração ftime(Estrutura timeb *_Tmb) {
  _ftime32((Estrutura __timeb32 *)_Tmb);
}
#Senão
__CRT_INLINE Vazio Declaração ftime(Estrutura timeb *_Tmb) {
  _ftime64((Estrutura __timeb64 *)_Tmb);
}
#FimSe
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)

#Inclua <sec_api/sys/timeb_s.h>
#FimSe
