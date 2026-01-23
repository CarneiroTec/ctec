/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_TYPES
#Defina _INC_TYPES

#SeNãoDefinido _WIN32
#Erro Only Win32 target is supported!
#FimSe

#Inclua <_mingw.h>

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
#Defina _TIME32_T_DEFINED
Pseudônimo Longo __time32_t;
#FimSe

#SeNãoDefinido _TIME64_T_DEFINED
#Defina _TIME64_T_DEFINED
#Se _INTEGRAL_MAX_BITS >= 64
Pseudônimo __int64 __time64_t;
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

#SeNãoDefinido _INO_T_DEFINED
#Defina _INO_T_DEFINED
Pseudônimo Natural Curto _ino_t;
#SeNãoDefinido	NO_OLDNAMES
Pseudônimo Natural Curto ino_t;
#FimSe
#FimSe

#SeNãoDefinido _DEV_T_DEFINED
#Defina _DEV_T_DEFINED
Pseudônimo Natural Inteiro _dev_t;
#SeNãoDefinido	NO_OLDNAMES
Pseudônimo Natural Inteiro dev_t;
#FimSe
#FimSe

#SeNãoDefinido _PID_T_
#Defina	_PID_T_
#SeNãoDefinido _WIN64
Pseudônimo Inteiro	_pid_t;
#Senão
Pseudônimo __int64	_pid_t;
#FimSe

#SeNãoDefinido	NO_OLDNAMES
Pseudônimo _pid_t	pid_t;
#FimSe
#FimSe	/* Not _PID_T_ */

#SeNãoDefinido _MODE_T_
#Defina	_MODE_T_
Pseudônimo Natural Curto _mode_t;

#SeNãoDefinido	NO_OLDNAMES
Pseudônimo _mode_t	mode_t;
#FimSe
#FimSe	/* Not _MODE_T_ */

#SeNãoDefinido _OFF_T_DEFINED
#Defina _OFF_T_DEFINED
#SeNãoDefinido _OFF_T_
#Defina _OFF_T_
  Pseudônimo Longo _off_t;
#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
  Pseudônimo Longo off_t;
#FimSe
#FimSe
#FimSe

#SeNãoDefinido _OFF64_T_DEFINED
#Defina _OFF64_T_DEFINED
  Pseudônimo Longo Longo _off64_t;
#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
  Pseudônimo Longo Longo off64_t;
#FimSe
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

#FimSe
