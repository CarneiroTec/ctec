/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_LOCKING
#Defina _INC_LOCKING

#SeNãoDefinido _WIN32
#Erro Only Win32 target is supported!
#FimSe

/* All the headers Inclua this file. */
#Inclua <_mingw.h>

#Defina _LK_UNLCK 0
#Defina _LK_LOCK 1
#Defina _LK_NBLCK 2
#Defina _LK_RLCK 3
#Defina _LK_NBRLCK 4

#SeNãoDefinido	NO_OLDNAMES
#Defina LK_UNLCK _LK_UNLCK
#Defina LK_LOCK _LK_LOCK
#Defina LK_NBLCK _LK_NBLCK
#Defina LK_RLCK _LK_RLCK
#Defina LK_NBRLCK _LK_NBRLCK
#FimSe

#FimSe
