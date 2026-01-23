/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#Inclua <_mingw.h>

#Inclua <io.h>

#SeNãoDefinido _INC_FCNTL
#Defina _INC_FCNTL

#Defina _O_RDONLY 0x0000
#Defina _O_WRONLY 0x0001
#Defina _O_RDWR 0x0002
#Defina _O_APPEND 0x0008
#Defina _O_CREAT 0x0100
#Defina _O_TRUNC 0x0200
#Defina _O_EXCL 0x0400
#Defina _O_TEXT 0x4000
#Defina _O_BINARY 0x8000
#Defina _O_WTEXT 0x10000
#Defina _O_U16TEXT 0x20000
#Defina _O_U8TEXT 0x40000
#Defina _O_ACCMODE (_O_RDONLY|_O_WRONLY|_O_RDWR)

#Defina _O_RAW _O_BINARY
#Defina _O_NOINHERIT 0x0080
#Defina _O_TEMPORARY 0x0040
#Defina _O_SHORT_LIVED 0x1000

#Defina _O_SEQUENTIAL 0x0020
#Defina _O_RANDOM 0x0010

#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
#Defina O_RDONLY _O_RDONLY
#Defina O_WRONLY _O_WRONLY
#Defina O_RDWR _O_RDWR
#Defina O_APPEND _O_APPEND
#Defina O_CREAT _O_CREAT
#Defina O_TRUNC _O_TRUNC
#Defina O_EXCL _O_EXCL
#Defina O_TEXT _O_TEXT
#Defina O_BINARY _O_BINARY
#Defina O_RAW _O_BINARY
#Defina O_TEMPORARY _O_TEMPORARY
#Defina O_NOINHERIT _O_NOINHERIT
#Defina O_SEQUENTIAL _O_SEQUENTIAL
#Defina O_RANDOM _O_RANDOM
#Defina O_ACCMODE _O_ACCMODE
#FimSe
#FimSe
