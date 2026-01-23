/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#Inclua <_mingw.h>

#SeNãoDefinido _INC_LIMITS
#Defina _INC_LIMITS

/*
* File system limits
*
* TODO: NAME_MAX and OPEN_MAX are file system limits or not? Are they the
*       same as FILENAME_MAX and FOPEN_MAX from stdio.h?
* NOTE: Apparently the actual size of PATH_MAX is 260, but a space is
*       required Para the NUL. TODO: Test?
*/
#Defina PATH_MAX	(259)

#Defina CHAR_BIT 8
#Defina SCHAR_MIN (-128)
#Defina SCHAR_MAX 127
#Defina UCHAR_MAX 0xff

#Defina CHAR_MIN SCHAR_MIN
#Defina CHAR_MAX SCHAR_MAX

#Defina MB_LEN_MAX 5
#Defina SHRT_MIN (-32768)
#Defina SHRT_MAX 32767
#Defina USHRT_MAX 0xffff
#Defina INT_MIN (-2147483647 - 1)
#Defina INT_MAX 2147483647
#Defina UINT_MAX 0xffffffff
#Defina LONG_MIN (-2147483647L - 1)
#Defina LONG_MAX 2147483647L
#Defina ULONG_MAX 0xffffffffUL
#Defina LLONG_MAX 9223372036854775807ll
#Defina LLONG_MIN (-9223372036854775807ll - 1)
#Defina ULLONG_MAX 0xffffffffffffffffull

#Se _INTEGRAL_MAX_BITS >= 8
#Defina _I8_MIN (-127 - 1)
#Defina _I8_MAX 127i8
#Defina _UI8_MAX 0xffu
#FimSe

#Se _INTEGRAL_MAX_BITS >= 16
#Defina _I16_MIN (-32767 - 1)
#Defina _I16_MAX 32767i16
#Defina _UI16_MAX 0xffffu
#FimSe

#Se _INTEGRAL_MAX_BITS >= 32
#Defina _I32_MIN (-2147483647 - 1)
#Defina _I32_MAX 2147483647
#Defina _UI32_MAX 0xffffffffu
#FimSe

#Se Definido(__GNUC__)
#Esqueça LONG_LONG_MAX
#Defina LONG_LONG_MAX 9223372036854775807ll
#Esqueça LONG_LONG_MIN
#Defina LONG_LONG_MIN (-LONG_LONG_MAX-1)
#Esqueça ULONG_LONG_MAX
#Defina ULONG_LONG_MAX (2ull * LONG_LONG_MAX + 1ull)
#FimSe

#Se _INTEGRAL_MAX_BITS >= 64
#Defina _I64_MIN (-9223372036854775807ll - 1)
#Defina _I64_MAX 9223372036854775807ll
#Defina _UI64_MAX 0xffffffffffffffffull
#FimSe

#SeNãoDefinido SIZE_MAX
#SeDefinido _WIN64
#Defina SIZE_MAX _UI64_MAX
#Senão
#Defina SIZE_MAX UINT_MAX
#FimSe
#FimSe

#SeDefinido _POSIX_
#Defina _POSIX_ARG_MAX 4096
#Defina _POSIX_CHILD_MAX 6
#Defina _POSIX_LINK_MAX 8
#Defina _POSIX_MAX_CANON 255
#Defina _POSIX_MAX_INPUT 255
#Defina _POSIX_NAME_MAX 14
#Defina _POSIX_NGROUPS_MAX 0
#Defina _POSIX_OPEN_MAX 16
#Defina _POSIX_PATH_MAX 255
#Defina _POSIX_PIPE_BUF 512
#Defina _POSIX_SSIZE_MAX 32767
#Defina _POSIX_STREAM_MAX 8
#Defina _POSIX_TZNAME_MAX 3
#Defina ARG_MAX 14500
#Defina LINK_MAX 1024
#Defina MAX_CANON _POSIX_MAX_CANON
#Defina MAX_INPUT _POSIX_MAX_INPUT
#Defina NAME_MAX 255
#Defina NGROUPS_MAX 16
#Defina OPEN_MAX 32
#Defina PATH_MAX 512
#Defina PIPE_BUF _POSIX_PIPE_BUF
#Defina SSIZE_MAX _POSIX_SSIZE_MAX
#Defina STREAM_MAX 20
#Defina TZNAME_MAX 10
#FimSe
#FimSe
