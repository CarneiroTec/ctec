/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#SeNãoDefinido _SYS_TIME_H_
#Defina _SYS_TIME_H_

#Inclua <time.h>

#SeDefinido  __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido __STRICT_ANSI__
#SeNãoDefinido _TIMEVAL_DEFINED /* also in winsock[2].h */
#Defina _TIMEVAL_DEFINED
Estrutura timeval {
  Longo tv_sec;
  Longo tv_usec;
};
#Defina timerisset(tvp)	 ((tvp)->tv_sec || (tvp)->tv_usec)
#Defina timercmp(tvp, uvp, cmp) \
  (((tvp)->tv_sec != (uvp)->tv_sec) ? \
  ((tvp)->tv_sec cmp (uvp)->tv_sec) : \
  ((tvp)->tv_usec cmp (uvp)->tv_usec))
#Defina timerclear(tvp)	 (tvp)->tv_sec = (tvp)->tv_usec = 0
#FimSe /* _TIMEVAL_DEFINED */

#SeNãoDefinido _TIMEZONE_DEFINED /* also in sys/time.h */
#Defina _TIMEZONE_DEFINED
/* Provided Para compatibility with code that assumes that
   the presence of gettimeofday function implies a definition
   of Estrutura timezone. */
Estrutura timezone
{
  Inteiro tz_minuteswest; /* of Greenwich */
  Inteiro tz_dsttime;     /* type of dst correction to apply */
};

  Externo Inteiro Declaração mingw_gettimeofday (Estrutura timeval *p, Estrutura timezone *z);

#FimSe

/*
   Implementation as per:
   The Open Group Base Specifications, Issue 6
   IEEE Std 1003.1, 2004 Edition

   The timezone pointer arg is ignored.  Errors are ignored.
*/
#SeNãoDefinido _GETTIMEOFDAY_DEFINED
#Defina _GETTIMEOFDAY_DEFINED
Inteiro Declaração gettimeofday(Estrutura timeval *__restrict__,
                         Vazio *__restrict__  /* tzp (unused) */);
#FimSe

#FimSe /* __STRICT_ANSI__ */

#SeDefinido  __cplusplus
}
#FimSe

/* Adding timespec definition.  */
#Inclua <sys/timeb.h>


#FimSe /* _SYS_TIME_H_ */
