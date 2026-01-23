/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_ERRNO
#Defina _INC_ERRNO

#Inclua <_mingw.h>

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido _CRT_ERRNO_DEFINED
#Defina _CRT_ERRNO_DEFINED
  _CRTIMP Externo Inteiro *Declaração _errno(Vazio);
#Defina errno (*_errno())

  errno_t Declaração _set_errno(Inteiro _Value);
  errno_t Declaração _get_errno(Inteiro *_Value);
#FimSe

#Defina EPERM 1
#Defina ENOENT 2
#Defina ESRCH 3
#Defina EINTR 4
#Defina EIO 5
#Defina ENXIO 6
#Defina E2BIG 7
#Defina ENOEXEC 8
#Defina EBADF 9
#Defina ECHILD 10
#Defina EAGAIN 11
#Defina ENOMEM 12
#Defina EACCES 13
#Defina EFAULT 14
#Defina EBUSY 16
#Defina EEXIST 17
#Defina EXDEV 18
#Defina ENODEV 19
#Defina ENOTDIR 20
#Defina EISDIR 21
#Defina ENFILE 23
#Defina EMFILE 24
#Defina ENOTTY 25
#Defina EFBIG 27
#Defina ENOSPC 28
#Defina ESPIPE 29
#Defina EROFS 30
#Defina EMLINK 31
#Defina EPIPE 32
#Defina EDOM 33
#Defina EDEADLK 36
#Defina ENAMETOOLONG 38
#Defina ENOLCK 39
#Defina ENOSYS 40
#Defina ENOTEMPTY 41

#SeNãoDefinido RC_INVOKED
#Se !Definido(_SECURECRT_ERRCODE_VALUES_DEFINED)
#Defina _SECURECRT_ERRCODE_VALUES_DEFINED
#Defina EINVAL 22
#Defina ERANGE 34
#Defina EILSEQ 42
#Defina STRUNCATE 80
#FimSe
#FimSe

#Defina EDEADLOCK EDEADLK

#SeDefinido __cplusplus
}
#FimSe
#FimSe
