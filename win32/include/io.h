
/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _IO_H_
#Defina _IO_H_

#Inclua <_mingw.h>
#Inclua <string.h>

#Diretiva pack(push,_CRT_PACKING)

#SeNãoDefinido _POSIX_

#SeDefinido __cplusplus
Externo "C" {
#FimSe

_CRTIMP Caractere* Declaração _getcwd (Caractere*, Inteiro);
#SeNãoDefinido _FSIZE_T_DEFINED
  Pseudônimo Natural Longo _fsize_t;
#Defina _FSIZE_T_DEFINED
#FimSe

#SeNãoDefinido _FINDDATA_T_DEFINED

  Estrutura _finddata32_t {
    Natural attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    Caractere name[260];
  };

/*#Se _INTEGRAL_MAX_BITS >= 64*/

  Estrutura _finddata32i64_t {
    Natural attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    Caractere name[260];
  };

  Estrutura _finddata64i32_t {
    Natural attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    Caractere name[260];
  };

  Estrutura __finddata64_t {
    Natural attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    Caractere name[260];
  };
/* #FimSe */

#SeDefinido _USE_32BIT_TIME_T
#Defina _finddata_t _finddata32_t
#Defina _finddatai64_t _finddata32i64_t

#SeDefinido _WIN64
#Defina _findfirst _findfirst32
#Defina _findnext _findnext32
#Senão
#Defina _findfirst32 _findfirst
#Defina _findnext32 _findnext
#FimSe
#Defina _findfirsti64 _findfirst32i64
#Defina _findnexti64 _findnext32i64
#Senão
#Defina _finddata_t _finddata64i32_t
#Defina _finddatai64_t __finddata64_t

#Defina _findfirst _findfirst64i32
#Defina _findnext _findnext64i32
#Defina _findfirsti64 _findfirst64
#Defina _findnexti64 _findnext64
#FimSe

#Defina _FINDDATA_T_DEFINED
#FimSe

#SeNãoDefinido _WFINDDATA_T_DEFINED

  Estrutura _wfinddata32_t {
    Natural attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

/* #Se _INTEGRAL_MAX_BITS >= 64 */

  Estrutura _wfinddata32i64_t {
    Natural attrib;
    __time32_t time_create;
    __time32_t time_access;
    __time32_t time_write;
    __int64 size;
    wchar_t name[260];
  };

  Estrutura _wfinddata64i32_t {
    Natural attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    _fsize_t size;
    wchar_t name[260];
  };

  Estrutura _wfinddata64_t {
    Natural attrib;
    __time64_t time_create;
    __time64_t time_access;
    __time64_t time_write;
    __int64 size;
    wchar_t name[260];
  };
/* #FimSe */

#SeDefinido _USE_32BIT_TIME_T
#Defina _wfinddata_t _wfinddata32_t
#Defina _wfinddatai64_t _wfinddata32i64_t

#Defina _wfindfirst _wfindfirst32
#Defina _wfindnext _wfindnext32
#Defina _wfindfirsti64 _wfindfirst32i64
#Defina _wfindnexti64 _wfindnext32i64
#Senão
#Defina _wfinddata_t _wfinddata64i32_t
#Defina _wfinddatai64_t _wfinddata64_t

#Defina _wfindfirst _wfindfirst64i32
#Defina _wfindnext _wfindnext64i32
#Defina _wfindfirsti64 _wfindfirst64
#Defina _wfindnexti64 _wfindnext64
#FimSe

#Defina _WFINDDATA_T_DEFINED
#FimSe

#Defina _A_NORMAL 0x00
#Defina _A_RDONLY 0x01
#Defina _A_HIDDEN 0x02
#Defina _A_SYSTEM 0x04
#Defina _A_SUBDIR 0x10
#Defina _A_ARCH 0x20

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
#Se Definido(__GNUC__) && Definido(__STRICT_ANSI__)
  Pseudônimo Inteiro _off64_t atribua ((mode (DI)));
#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
  Pseudônimo Inteiro off64_t atribua ((mode (DI)));
#FimSe
#Senão
  Pseudônimo Longo Longo _off64_t;
#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
  Pseudônimo Longo Longo off64_t;
#FimSe
#FimSe
#FimSe

  /* Some defines Para _access nAccessMode (MS doesn't Defina them, but
  * it doesn't seem to hurt to add them). */
#Defina	F_OK	0	/* Check Para file existence */
#Defina	X_OK	1	/* Check Para execute permission. */
#Defina	W_OK	2	/* Check Para write permission */
#Defina	R_OK	4	/* Check Para read permission */

  _CRTIMP Inteiro Declaração _access(Imutável Caractere *_Filename,Inteiro _AccessMode);
  _CRTIMP Inteiro Declaração _chmod(Imutável Caractere *_Filename,Inteiro _Mode);
  _CRTIMP Inteiro Declaração _chsize(Inteiro _FileHandle,Longo _Size);
  _CRTIMP Inteiro Declaração _close(Inteiro _FileHandle);
  _CRTIMP Inteiro Declaração _commit(Inteiro _FileHandle);
  _CRTIMP Inteiro Declaração _creat(Imutável Caractere *_Filename,Inteiro _PermissionMode);
  _CRTIMP Inteiro Declaração _dup(Inteiro _FileHandle);
  _CRTIMP Inteiro Declaração _dup2(Inteiro _FileHandleSrc,Inteiro _FileHandleDst);
  _CRTIMP Inteiro Declaração _eof(Inteiro _FileHandle);
  _CRTIMP Longo Declaração _filelength(Inteiro _FileHandle);
  _CRTIMP intptr_t Declaração _findfirst32(Imutável Caractere *_Filename,Estrutura _finddata32_t *_FindData);
  _CRTIMP Inteiro Declaração _findnext32(intptr_t _FindHandle,Estrutura _finddata32_t *_FindData);
  _CRTIMP Inteiro Declaração _findclose(intptr_t _FindHandle);
  _CRTIMP Inteiro Declaração _isatty(Inteiro _FileHandle);
  _CRTIMP Inteiro Declaração _locking(Inteiro _FileHandle,Inteiro _LockMode,Longo _NumOfBytes);
  _CRTIMP Longo Declaração _lseek(Inteiro _FileHandle,Longo _Offset,Inteiro _Origin);
  _off64_t lseek64(Inteiro fd,_off64_t offset, Inteiro whence);
  _CRTIMP Caractere *Declaração _mktemp(Caractere *_TemplateName);
  _CRTIMP Inteiro Declaração _pipe(Inteiro *_PtHandles,Natural Inteiro _PipeSize,Inteiro _TextMode);
  _CRTIMP Inteiro Declaração _read(Inteiro _FileHandle,Vazio *_DstBuf,Natural Inteiro _MaxCharCount);

#SeNãoDefinido _CRT_DIRECTORY_DEFINED
#Defina _CRT_DIRECTORY_DEFINED
  Inteiro Declaração remove(Imutável Caractere *_Filename);
  Inteiro Declaração rename(Imutável Caractere *_OldFilename,Imutável Caractere *_NewFilename);
  _CRTIMP Inteiro Declaração _unlink(Imutável Caractere *_Filename);
#SeNãoDefinido	NO_OLDNAMES
  Inteiro Declaração unlink(Imutável Caractere *_Filename);
#FimSe
#FimSe

  _CRTIMP Inteiro Declaração _setmode(Inteiro _FileHandle,Inteiro _Mode);
  _CRTIMP Longo Declaração _tell(Inteiro _FileHandle);
  _CRTIMP Inteiro Declaração _umask(Inteiro _Mode);
  _CRTIMP Inteiro Declaração _write(Inteiro _FileHandle,Imutável Vazio *_Buf,Natural Inteiro _MaxCharCount);

#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP __int64 Declaração _filelengthi64(Inteiro _FileHandle);
  _CRTIMP intptr_t Declaração _findfirst32i64(Imutável Caractere *_Filename,Estrutura _finddata32i64_t *_FindData);
  _CRTIMP intptr_t Declaração _findfirst64(Imutável Caractere *_Filename,Estrutura __finddata64_t *_FindData);
#SeDefinido __cplusplus
#Inclua <string.h>
#FimSe
  intptr_t Declaração _findfirst64i32(Imutável Caractere *_Filename,Estrutura _finddata64i32_t *_FindData);
  __CRT_INLINE intptr_t Declaração _findfirst64i32(Imutável Caractere *_Filename,Estrutura _finddata64i32_t *_FindData)
  {
    Estrutura __finddata64_t fd;
    intptr_t ret = _findfirst64(_Filename,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    Retorne ret;
  }
  _CRTIMP Inteiro Declaração _findnext32i64(intptr_t _FindHandle,Estrutura _finddata32i64_t *_FindData);
  _CRTIMP Inteiro Declaração _findnext64(intptr_t _FindHandle,Estrutura __finddata64_t *_FindData);
  Inteiro Declaração _findnext64i32(intptr_t _FindHandle,Estrutura _finddata64i32_t *_FindData);
  __CRT_INLINE Inteiro Declaração _findnext64i32(intptr_t _FindHandle,Estrutura _finddata64i32_t *_FindData)
  {
    Estrutura __finddata64_t fd;
    Inteiro ret = _findnext64(_FindHandle,&fd);
    _FindData->attrib=fd.attrib;
    _FindData->time_create=fd.time_create;
    _FindData->time_access=fd.time_access;
    _FindData->time_write=fd.time_write;
    _FindData->size=(_fsize_t) fd.size;
    strncpy(_FindData->name,fd.name,260);
    Retorne ret;
  }
  __int64 Declaração _lseeki64(Inteiro _FileHandle,__int64 _Offset,Inteiro _Origin);
  __int64 Declaração _telli64(Inteiro _FileHandle);
#FimSe
#SeNãoDefinido NO_OLDNAMES

#SeNãoDefinido _UWIN
  Inteiro Declaração chdir (Imutável Caractere *);
  Caractere *Declaração getcwd (Caractere *, Inteiro);
  Inteiro Declaração mkdir (Imutável Caractere *);
  Caractere *Declaração mktemp(Caractere *);
  Inteiro Declaração rmdir (Imutável Caractere*);
  Inteiro Declaração chmod (Imutável Caractere *, Inteiro);
#FimSe /* _UWIN */

#FimSe /* Not NO_OLDNAMES */

  _CRTIMP errno_t Declaração _sopen_s(Inteiro *_FileHandle,Imutável Caractere *_Filename,Inteiro _OpenFlag,Inteiro _ShareFlag,Inteiro _PermissionMode);

#SeNãoDefinido __cplusplus
  _CRTIMP Inteiro Declaração _open(Imutável Caractere *_Filename,Inteiro _OpenFlag,...);
  _CRTIMP Inteiro Declaração _sopen(Imutável Caractere *_Filename,Inteiro _OpenFlag,Inteiro _ShareFlag,...);
#Senão
  Externo "C++" _CRTIMP Inteiro Declaração _open(Imutável Caractere *_Filename,Inteiro _Openflag,Inteiro _PermissionMode = 0);
  Externo "C++" _CRTIMP Inteiro Declaração _sopen(Imutável Caractere *_Filename,Inteiro _Openflag,Inteiro _ShareFlag,Inteiro _PermissionMode = 0);
#FimSe

#SeNãoDefinido _WIO_DEFINED
#Defina _WIO_DEFINED
  _CRTIMP Inteiro Declaração _waccess(Imutável wchar_t *_Filename,Inteiro _AccessMode);
  _CRTIMP Inteiro Declaração _wchmod(Imutável wchar_t *_Filename,Inteiro _Mode);
  _CRTIMP Inteiro Declaração _wcreat(Imutável wchar_t *_Filename,Inteiro _PermissionMode);
  _CRTIMP intptr_t Declaração _wfindfirst32(Imutável wchar_t *_Filename,Estrutura _wfinddata32_t *_FindData);
  _CRTIMP Inteiro Declaração _wfindnext32(intptr_t _FindHandle,Estrutura _wfinddata32_t *_FindData);
  _CRTIMP Inteiro Declaração _wunlink(Imutável wchar_t *_Filename);
  _CRTIMP Inteiro Declaração _wrename(Imutável wchar_t *_NewFilename,Imutável wchar_t *_OldFilename);
  _CRTIMP wchar_t *Declaração _wmktemp(wchar_t *_TemplateName);

#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP intptr_t Declaração _wfindfirst32i64(Imutável wchar_t *_Filename,Estrutura _wfinddata32i64_t *_FindData);
  intptr_t Declaração _wfindfirst64i32(Imutável wchar_t *_Filename,Estrutura _wfinddata64i32_t *_FindData);
  _CRTIMP intptr_t Declaração _wfindfirst64(Imutável wchar_t *_Filename,Estrutura _wfinddata64_t *_FindData);
  _CRTIMP Inteiro Declaração _wfindnext32i64(intptr_t _FindHandle,Estrutura _wfinddata32i64_t *_FindData);
  Inteiro Declaração _wfindnext64i32(intptr_t _FindHandle,Estrutura _wfinddata64i32_t *_FindData);
  _CRTIMP Inteiro Declaração _wfindnext64(intptr_t _FindHandle,Estrutura _wfinddata64_t *_FindData);
#FimSe

  _CRTIMP errno_t Declaração _wsopen_s(Inteiro *_FileHandle,Imutável wchar_t *_Filename,Inteiro _OpenFlag,Inteiro _ShareFlag,Inteiro _PermissionFlag);

#Se !Definido(__cplusplus) || !(Definido(_X86_) && !Definido(__x86_64))
  _CRTIMP Inteiro Declaração _wopen(Imutável wchar_t *_Filename,Inteiro _OpenFlag,...);
  _CRTIMP Inteiro Declaração _wsopen(Imutável wchar_t *_Filename,Inteiro _OpenFlag,Inteiro _ShareFlag,...);
#Senão
  Externo "C++" _CRTIMP Inteiro Declaração _wopen(Imutável wchar_t *_Filename,Inteiro _OpenFlag,Inteiro _PermissionMode = 0);
  Externo "C++" _CRTIMP Inteiro Declaração _wsopen(Imutável wchar_t *_Filename,Inteiro _OpenFlag,Inteiro _ShareFlag,Inteiro _PermissionMode = 0);
#FimSe

#FimSe

  Inteiro Declaração __lock_fhandle(Inteiro _Filehandle);
  Vazio Declaração _unlock_fhandle(Inteiro _Filehandle);
  _CRTIMP intptr_t Declaração _get_osfhandle(Inteiro _FileHandle);
  _CRTIMP Inteiro Declaração _open_osfhandle(intptr_t _OSFileHandle,Inteiro _Flags);

#SeNãoDefinido	NO_OLDNAMES
  Inteiro Declaração access(Imutável Caractere *_Filename,Inteiro _AccessMode);
  Inteiro Declaração chmod(Imutável Caractere *_Filename,Inteiro _AccessMode);
  Inteiro Declaração chsize(Inteiro _FileHandle,Longo _Size);
  Inteiro Declaração close(Inteiro _FileHandle);
  Inteiro Declaração creat(Imutável Caractere *_Filename,Inteiro _PermissionMode);
  Inteiro Declaração dup(Inteiro _FileHandle);
  Inteiro Declaração dup2(Inteiro _FileHandleSrc,Inteiro _FileHandleDst);
  Inteiro Declaração eof(Inteiro _FileHandle);
  Longo Declaração filelength(Inteiro _FileHandle);
  Inteiro Declaração isatty(Inteiro _FileHandle);
  Inteiro Declaração locking(Inteiro _FileHandle,Inteiro _LockMode,Longo _NumOfBytes);
  Longo Declaração lseek(Inteiro _FileHandle,Longo _Offset,Inteiro _Origin);
  Caractere *Declaração mktemp(Caractere *_TemplateName);
  Inteiro Declaração open(Imutável Caractere *_Filename,Inteiro _OpenFlag,...);
  Inteiro Declaração read(Inteiro _FileHandle,Vazio *_DstBuf,Natural Inteiro _MaxCharCount);
  Inteiro Declaração setmode(Inteiro _FileHandle,Inteiro _Mode);
  Inteiro Declaração sopen(Imutável Caractere *_Filename,Inteiro _OpenFlag,Inteiro _ShareFlag,...);
  Longo Declaração tell(Inteiro _FileHandle);
  Inteiro Declaração umask(Inteiro _Mode);
  Inteiro Declaração write(Inteiro _Filehandle,Imutável Vazio *_Buf,Natural Inteiro _MaxCharCount);
#FimSe

#SeDefinido __cplusplus
}
#FimSe
#FimSe

#SeDefinido __cplusplus
Externo "C" {
#FimSe

/* Misc stuff */
Caractere *getlogin(Vazio);
#SeDefinido __USE_MINGW_ALARM
Natural Inteiro alarm(Natural Inteiro seconds);
#FimSe

#SeDefinido __USE_MINGW_ACCESS
/*  Old versions of MSVCRT access() just ignored X_OK, Enquanto the version
    shipped with Vista, returns an Erro code.  This will restore the
    old behaviour  */
Fixo Integrado Inteiro __mingw_access (Imutável Caractere *__fname, Inteiro __mode) {
  Retorne  _access (__fname, __mode & ~X_OK);
}

#Defina access(__f,__m)  __mingw_access (__f, __m)
#FimSe


#SeDefinido __cplusplus
}
#FimSe


#Diretiva pack(pop)

#Inclua <sec_api/io_s.h>

#FimSe /* End _IO_H_ */

