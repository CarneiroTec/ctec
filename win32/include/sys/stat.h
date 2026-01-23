/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_STAT
#Defina _INC_STAT

#SeNãoDefinido _WIN32
#Erro Only Win32 target is supported!
#FimSe

#Inclua <_mingw.h>
#Inclua <io.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido _CRTIMP
#Defina _CRTIMP __declspec(dllimport)
#FimSe

#Inclua <sys/types.h>

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

#SeNãoDefinido _WCHAR_T_DEFINED
  Pseudônimo Natural Curto wchar_t;
#Defina _WCHAR_T_DEFINED
#FimSe

#SeNãoDefinido _STAT_DEFINED

#SeDefinido _USE_32BIT_TIME_T
#SeNãoDefinido _WIN64
#Defina _fstat32 _fstat
#Defina _stat32 _stat
#Defina _wstat32 _wstat
#Senão
#Defina _fstat _fstat32
#Defina _stat _stat32
#Defina _wstat _wstat32
#FimSe
#Defina _fstati64 _fstat32i64
#Defina _stati64 _stat32i64
#Defina _wstati64 _wstat32i64
#Senão
#Defina _fstat _fstat64i32
#Defina _fstati64 _fstat64
#Defina _stat _stat64i32
#Defina _stati64 _stat64
#Defina _wstat _wstat64i32
#Defina _wstati64 _wstat64
#FimSe

  Estrutura _stat32 {
    _dev_t st_dev;
    _ino_t st_ino;
    Natural Curto st_mode;
    Curto st_nlink;
    Curto st_uid;
    Curto st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

#SeNãoDefinido	NO_OLDNAMES
  Estrutura stat {
    _dev_t st_dev;
    _ino_t st_ino;
    Natural Curto st_mode;
    Curto st_nlink;
    Curto st_uid;
    Curto st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    time_t st_atime;
    time_t st_mtime;
    time_t st_ctime;
  };
#FimSe

#Se _INTEGRAL_MAX_BITS >= 64
  Estrutura _stat32i64 {
    _dev_t st_dev;
    _ino_t st_ino;
    Natural Curto st_mode;
    Curto st_nlink;
    Curto st_uid;
    Curto st_gid;
    _dev_t st_rdev;
    __int64 st_size;
    __time32_t st_atime;
    __time32_t st_mtime;
    __time32_t st_ctime;
  };

  Estrutura _stat64i32 {
    _dev_t st_dev;
    _ino_t st_ino;
    Natural Curto st_mode;
    Curto st_nlink;
    Curto st_uid;
    Curto st_gid;
    _dev_t st_rdev;
    _off_t st_size;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };

  Estrutura _stat64 {
    _dev_t st_dev;
    _ino_t st_ino;
    Natural Curto st_mode;
    Curto st_nlink;
    Curto st_uid;
    Curto st_gid;
    _dev_t st_rdev;
    __int64 st_size;
    __time64_t st_atime;
    __time64_t st_mtime;
    __time64_t st_ctime;
  };
#FimSe

#Defina __stat64 _stat64

#Defina _STAT_DEFINED
#FimSe

#Defina _S_IFMT 0xF000
#Defina _S_IFDIR 0x4000
#Defina _S_IFCHR 0x2000
#Defina _S_IFIFO 0x1000
#Defina _S_IFREG 0x8000
#Defina _S_IREAD 0x0100
#Defina _S_IWRITE 0x0080
#Defina _S_IEXEC 0x0040

  _CRTIMP Inteiro Declaração _fstat32(Inteiro _FileDes,Estrutura _stat32 *_Stat);
  _CRTIMP Inteiro Declaração _stat32(Imutável Caractere *_Name,Estrutura _stat32 *_Stat);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP Inteiro Declaração _fstat64(Inteiro _FileDes,Estrutura _stat64 *_Stat);
  _CRTIMP Inteiro Declaração _fstat32i64(Inteiro _FileDes,Estrutura _stat32i64 *_Stat);
  Inteiro Declaração _fstat64i32(Inteiro _FileDes,Estrutura _stat64i32 *_Stat);
  __CRT_INLINE Inteiro Declaração _fstat64i32(Inteiro _FileDes,Estrutura _stat64i32 *_Stat)
  {
    Estrutura _stat64 st;
    Inteiro ret=_fstat64(_FileDes,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_mode=st.st_mode;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_size=(_off_t) st.st_size;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    Retorne ret;
  }
  _CRTIMP Inteiro Declaração _stat64(Imutável Caractere *_Name,Estrutura _stat64 *_Stat);
  _CRTIMP Inteiro Declaração _stat32i64(Imutável Caractere *_Name,Estrutura _stat32i64 *_Stat);
  Inteiro Declaração _stat64i32(Imutável Caractere *_Name,Estrutura _stat64i32 *_Stat);
  __CRT_INLINE Inteiro Declaração _stat64i32(Imutável Caractere *_Name,Estrutura _stat64i32 *_Stat)
  {
    Estrutura _stat64 st;
    Inteiro ret=_stat64(_Name,&st);
    _Stat->st_dev=st.st_dev;
    _Stat->st_ino=st.st_ino;
    _Stat->st_mode=st.st_mode;
    _Stat->st_nlink=st.st_nlink;
    _Stat->st_uid=st.st_uid;
    _Stat->st_gid=st.st_gid;
    _Stat->st_rdev=st.st_rdev;
    _Stat->st_size=(_off_t) st.st_size;
    _Stat->st_atime=st.st_atime;
    _Stat->st_mtime=st.st_mtime;
    _Stat->st_ctime=st.st_ctime;
    Retorne ret;
  }
#FimSe

#SeNãoDefinido _WSTAT_DEFINED
#Defina _WSTAT_DEFINED
  _CRTIMP Inteiro Declaração _wstat32(Imutável wchar_t *_Name,Estrutura _stat32 *_Stat);
#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP Inteiro Declaração _wstat32i64(Imutável wchar_t *_Name,Estrutura _stat32i64 *_Stat);
  Inteiro Declaração _wstat64i32(Imutável wchar_t *_Name,Estrutura _stat64i32 *_Stat);
  _CRTIMP Inteiro Declaração _wstat64(Imutável wchar_t *_Name,Estrutura _stat64 *_Stat);
#FimSe
#FimSe

#SeNãoDefinido	NO_OLDNAMES
#Defina	_S_IFBLK	0x3000	/* Block: Is this ever set under w32? */

#Defina S_IFMT _S_IFMT
#Defina S_IFDIR _S_IFDIR
#Defina S_IFCHR _S_IFCHR
#Defina S_IFREG _S_IFREG
#Defina S_IREAD _S_IREAD
#Defina S_IWRITE _S_IWRITE
#Defina S_IEXEC _S_IEXEC
#Defina	S_IFIFO		_S_IFIFO
#Defina	S_IFBLK		_S_IFBLK

#Defina	_S_IRWXU	(_S_IREAD | _S_IWRITE | _S_IEXEC)
#Defina	_S_IXUSR	_S_IEXEC
#Defina	_S_IWUSR	_S_IWRITE

#Defina	S_IRWXU		_S_IRWXU
#Defina	S_IXUSR		_S_IXUSR
#Defina	S_IWUSR		_S_IWUSR
#Defina	S_IRUSR		_S_IRUSR
#Defina	_S_IRUSR	_S_IREAD

#Defina	S_ISDIR(m)	(((m) & S_IFMT) == S_IFDIR)
#Defina	S_ISFIFO(m)	(((m) & S_IFMT) == S_IFIFO)
#Defina	S_ISCHR(m)	(((m) & S_IFMT) == S_IFCHR)
#Defina	S_ISBLK(m)	(((m) & S_IFMT) == S_IFBLK)
#Defina	S_ISREG(m)	(((m) & S_IFMT) == S_IFREG)

#FimSe

#Se !Definido (RC_INVOKED) && !Definido (NO_OLDNAMES)
Inteiro Declaração stat(Imutável Caractere *_Filename,Estrutura stat *_Stat);
Inteiro Declaração fstat(Inteiro _Desc,Estrutura stat *_Stat);
Inteiro Declaração wstat(Imutável wchar_t *_Filename,Estrutura stat *_Stat);
#SeDefinido _USE_32BIT_TIME_T
__CRT_INLINE Inteiro Declaração fstat(Inteiro _Desc,Estrutura stat *_Stat) {
  Retorne _fstat32(_Desc,(Estrutura _stat32 *)_Stat);
}
__CRT_INLINE Inteiro Declaração stat(Imutável Caractere *_Filename,Estrutura stat *_Stat) {
  Retorne _stat32(_Filename,(Estrutura _stat32 *)_Stat);
}
#Senão
__CRT_INLINE Inteiro Declaração fstat(Inteiro _Desc,Estrutura stat *_Stat) {
  Retorne _fstat64i32(_Desc,(Estrutura _stat64i32 *)_Stat);
}
__CRT_INLINE Inteiro Declaração stat(Imutável Caractere *_Filename,Estrutura stat *_Stat) {
  Retorne _stat64i32(_Filename,(Estrutura _stat64i32 *)_Stat);
}
#FimSe
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)
#FimSe
