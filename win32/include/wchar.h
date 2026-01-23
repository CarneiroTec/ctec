/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_WCHAR
#Defina _INC_WCHAR

#Inclua <_mingw.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido WCHAR_MIN  /* also at stdint.h */
#Defina WCHAR_MIN 0
#Defina WCHAR_MAX ((wchar_t) -1) /* UINT16_MAX */
#FimSe

#SeNãoDefinido __GNUC_VA_LIST
#Defina __GNUC_VA_LIST
  Pseudônimo __builtin_va_list __gnuc_va_list;
#FimSe

#SeNãoDefinido _VA_LIST_DEFINED
#Defina _VA_LIST_DEFINED
  Pseudônimo __gnuc_va_list va_list;
#FimSe

#SeNãoDefinido WEOF
#Defina WEOF (wint_t)(0xFFFF)
#FimSe

#SeNãoDefinido _FILE_DEFINED
  Estrutura _iobuf {
    Caractere *_ptr;
    Inteiro _cnt;
    Caractere *_base;
    Inteiro _flag;
    Inteiro _file;
    Inteiro _charbuf;
    Inteiro _bufsiz;
    Caractere *_tmpfname;
  };
  Pseudônimo Estrutura _iobuf FILE;
#Defina _FILE_DEFINED
#FimSe

#SeNãoDefinido _STDIO_DEFINED
#SeDefinido _WIN64
  _CRTIMP FILE *Declaração __iob_func(Vazio);
#Senão
#SeDefinido _MSVCRT_
Externo FILE _iob[];	/* A pointer to an array of FILE */
#Defina __iob_func()	(_iob)
#Senão
Externo FILE (*_imp___iob)[];	/* A pointer to an array of FILE */
#Defina __iob_func()	(*_imp___iob)
#Defina _iob __iob_func()
#FimSe
#FimSe

#Defina _iob __iob_func()
#FimSe

#SeNãoDefinido _STDSTREAM_DEFINED
#Defina stdin (&__iob_func()[0])
#Defina stdout (&__iob_func()[1])
#Defina stderr (&__iob_func()[2])
#Defina _STDSTREAM_DEFINED
#FimSe

#SeNãoDefinido _FSIZE_T_DEFINED
  Pseudônimo Natural Longo _fsize_t;
#Defina _FSIZE_T_DEFINED
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

#SeNãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#SeNãoDefinido _CONST_RETURN
#Defina _CONST_RETURN
#FimSe

#Defina _WConst_return _CONST_RETURN

#SeNãoDefinido _CRT_CTYPEDATA_DEFINED
#Defina _CRT_CTYPEDATA_DEFINED
#SeNãoDefinido _CTYPE_DISABLE_MACROS

#SeNãoDefinido __PCTYPE_FUNC
#Defina __PCTYPE_FUNC __pctype_func()
#SeDefinido _MSVCRT_
#Defina __pctype_func() (_pctype)
#Senão
#Defina __pctype_func() (*_imp___pctype)
#FimSe
#FimSe

#SeNãoDefinido _pctype
#SeDefinido _MSVCRT_
  Externo Natural Curto *_pctype;
#Senão
  Externo Natural Curto **_imp___pctype;
#Defina _pctype (*_imp___pctype)
#FimSe
#FimSe
#FimSe
#FimSe

#SeNãoDefinido _CRT_WCTYPEDATA_DEFINED
#Defina _CRT_WCTYPEDATA_DEFINED
#SeNãoDefinido _CTYPE_DISABLE_MACROS
#SeNãoDefinido _wctype
#SeDefinido _MSVCRT_
  Externo Natural Curto *_wctype;
#Senão
  Externo Natural Curto **_imp___wctype;
#Defina _wctype (*_imp___wctype)
#FimSe
#FimSe

#SeDefinido _MSVCRT_
#Defina __pwctype_func() (_pwctype)
#Senão
#Defina __pwctype_func() (*_imp___pwctype)
#FimSe

#SeNãoDefinido _pwctype
#SeDefinido _MSVCRT_
  Externo Natural Curto *_pwctype;
#Senão
  Externo Natural Curto **_imp___pwctype;
#Defina _pwctype (*_imp___pwctype)
#FimSe
#FimSe

#FimSe
#FimSe

#Defina _UPPER 0x1
#Defina _LOWER 0x2
#Defina _DIGIT 0x4
#Defina _SPACE 0x8

#Defina _PUNCT 0x10
#Defina _CONTROL 0x20
#Defina _BLANK 0x40
#Defina _HEX 0x80

#Defina _LEADBYTE 0x8000
#Defina _ALPHA (0x0100|_UPPER|_LOWER)

#SeNãoDefinido _WCTYPE_DEFINED
#Defina _WCTYPE_DEFINED

  Inteiro Declaração iswalpha(wint_t _C);
  _CRTIMP Inteiro Declaração _iswalpha_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswupper(wint_t _C);
  _CRTIMP Inteiro Declaração _iswupper_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswlower(wint_t _C);
  _CRTIMP Inteiro Declaração _iswlower_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswdigit(wint_t _C);
  _CRTIMP Inteiro Declaração _iswdigit_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswxdigit(wint_t _C);
  _CRTIMP Inteiro Declaração _iswxdigit_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswspace(wint_t _C);
  _CRTIMP Inteiro Declaração _iswspace_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswpunct(wint_t _C);
  _CRTIMP Inteiro Declaração _iswpunct_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswalnum(wint_t _C);
  _CRTIMP Inteiro Declaração _iswalnum_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswprint(wint_t _C);
  _CRTIMP Inteiro Declaração _iswprint_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswgraph(wint_t _C);
  _CRTIMP Inteiro Declaração _iswgraph_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswcntrl(wint_t _C);
  _CRTIMP Inteiro Declaração _iswcntrl_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswascii(wint_t _C);
  Inteiro Declaração isleadbyte(Inteiro _C);
  _CRTIMP Inteiro Declaração _isleadbyte_l(Inteiro _C,_locale_t _Locale);
  wint_t Declaração towupper(wint_t _C);
  _CRTIMP wint_t Declaração _towupper_l(wint_t _C,_locale_t _Locale);
  wint_t Declaração towlower(wint_t _C);
  _CRTIMP wint_t Declaração _towlower_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração iswctype(wint_t _C,wctype_t _Type);
  _CRTIMP Inteiro Declaração _iswctype_l(wint_t _C,wctype_t _Type,_locale_t _Locale);
  _CRTIMP Inteiro Declaração __iswcsymf(wint_t _C);
  _CRTIMP Inteiro Declaração _iswcsymf_l(wint_t _C,_locale_t _Locale);
  _CRTIMP Inteiro Declaração __iswcsym(wint_t _C);
  _CRTIMP Inteiro Declaração _iswcsym_l(wint_t _C,_locale_t _Locale);
  Inteiro Declaração is_wctype(wint_t _C,wctype_t _Type);
#FimSe

#SeNãoDefinido _WDIRECT_DEFINED
#Defina _WDIRECT_DEFINED

  _CRTIMP wchar_t *Declaração _wgetcwd(wchar_t *_DstBuf,Inteiro _SizeInWords);
  _CRTIMP wchar_t *Declaração _wgetdcwd(Inteiro _Drive,wchar_t *_DstBuf,Inteiro _SizeInWords);
  wchar_t *Declaração _wgetdcwd_nolock(Inteiro _Drive,wchar_t *_DstBuf,Inteiro _SizeInWords);
  _CRTIMP Inteiro Declaração _wchdir(Imutável wchar_t *_Path);
  _CRTIMP Inteiro Declaração _wmkdir(Imutável wchar_t *_Path);
  _CRTIMP Inteiro Declaração _wrmdir(Imutável wchar_t *_Path);
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

#SeNãoDefinido _WLOCALE_DEFINED
#Defina _WLOCALE_DEFINED
  _CRTIMP wchar_t *Declaração _wsetlocale(Inteiro _Category,Imutável wchar_t *_Locale);
#FimSe

#SeNãoDefinido _WPROCESS_DEFINED
#Defina _WPROCESS_DEFINED

  _CRTIMP intptr_t Declaração _wexecl(Imutável wchar_t *_Filename,Imutável wchar_t *_ArgList,...);
  _CRTIMP intptr_t Declaração _wexecle(Imutável wchar_t *_Filename,Imutável wchar_t *_ArgList,...);
  _CRTIMP intptr_t Declaração _wexeclp(Imutável wchar_t *_Filename,Imutável wchar_t *_ArgList,...);
  _CRTIMP intptr_t Declaração _wexeclpe(Imutável wchar_t *_Filename,Imutável wchar_t *_ArgList,...);
  _CRTIMP intptr_t Declaração _wexecv(Imutável wchar_t *_Filename,Imutável wchar_t *Imutável *_ArgList);
  _CRTIMP intptr_t Declaração _wexecve(Imutável wchar_t *_Filename,Imutável wchar_t *Imutável *_ArgList,Imutável wchar_t *Imutável *_Env);
  _CRTIMP intptr_t Declaração _wexecvp(Imutável wchar_t *_Filename,Imutável wchar_t *Imutável *_ArgList);
  _CRTIMP intptr_t Declaração _wexecvpe(Imutável wchar_t *_Filename,Imutável wchar_t *Imutável *_ArgList,Imutável wchar_t *Imutável *_Env);
  _CRTIMP intptr_t Declaração _wspawnl(Inteiro _Mode,Imutável wchar_t *_Filename,Imutável wchar_t *_ArgList,...);
  _CRTIMP intptr_t Declaração _wspawnle(Inteiro _Mode,Imutável wchar_t *_Filename,Imutável wchar_t *_ArgList,...);
  _CRTIMP intptr_t Declaração _wspawnlp(Inteiro _Mode,Imutável wchar_t *_Filename,Imutável wchar_t *_ArgList,...);
  _CRTIMP intptr_t Declaração _wspawnlpe(Inteiro _Mode,Imutável wchar_t *_Filename,Imutável wchar_t *_ArgList,...);
  _CRTIMP intptr_t Declaração _wspawnv(Inteiro _Mode,Imutável wchar_t *_Filename,Imutável wchar_t *Imutável *_ArgList);
  _CRTIMP intptr_t Declaração _wspawnve(Inteiro _Mode,Imutável wchar_t *_Filename,Imutável wchar_t *Imutável *_ArgList,Imutável wchar_t *Imutável *_Env);
  _CRTIMP intptr_t Declaração _wspawnvp(Inteiro _Mode,Imutável wchar_t *_Filename,Imutável wchar_t *Imutável *_ArgList);
  _CRTIMP intptr_t Declaração _wspawnvpe(Inteiro _Mode,Imutável wchar_t *_Filename,Imutável wchar_t *Imutável *_ArgList,Imutável wchar_t *Imutável *_Env);
#SeNãoDefinido _CRT_WSYSTEM_DEFINED
#Defina _CRT_WSYSTEM_DEFINED
  _CRTIMP Inteiro Declaração _wsystem(Imutável wchar_t *_Command);
#FimSe
#FimSe

#SeNãoDefinido _WCTYPE_INLINE_DEFINED
#Esqueça _CRT_WCTYPE_NOINLINE
#Se !Definido(__cplusplus) || Definido(_CRT_WCTYPE_NOINLINE)
#Defina iswalpha(_c) (iswctype(_c,_ALPHA))
#Defina iswupper(_c) (iswctype(_c,_UPPER))
#Defina iswlower(_c) (iswctype(_c,_LOWER))
#Defina iswdigit(_c) (iswctype(_c,_DIGIT))
#Defina iswxdigit(_c) (iswctype(_c,_HEX))
#Defina iswspace(_c) (iswctype(_c,_SPACE))
#Defina iswpunct(_c) (iswctype(_c,_PUNCT))
#Defina iswalnum(_c) (iswctype(_c,_ALPHA|_DIGIT))
#Defina iswprint(_c) (iswctype(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT))
#Defina iswgraph(_c) (iswctype(_c,_PUNCT|_ALPHA|_DIGIT))
#Defina iswcntrl(_c) (iswctype(_c,_CONTROL))
#Defina iswascii(_c) ((Natural)(_c) < 0x80)

#Defina _iswalpha_l(_c,_p) (_iswctype_l(_c,_ALPHA,_p))
#Defina _iswupper_l(_c,_p) (_iswctype_l(_c,_UPPER,_p))
#Defina _iswlower_l(_c,_p) (_iswctype_l(_c,_LOWER,_p))
#Defina _iswdigit_l(_c,_p) (_iswctype_l(_c,_DIGIT,_p))
#Defina _iswxdigit_l(_c,_p) (_iswctype_l(_c,_HEX,_p))
#Defina _iswspace_l(_c,_p) (_iswctype_l(_c,_SPACE,_p))
#Defina _iswpunct_l(_c,_p) (_iswctype_l(_c,_PUNCT,_p))
#Defina _iswalnum_l(_c,_p) (_iswctype_l(_c,_ALPHA|_DIGIT,_p))
#Defina _iswprint_l(_c,_p) (_iswctype_l(_c,_BLANK|_PUNCT|_ALPHA|_DIGIT,_p))
#Defina _iswgraph_l(_c,_p) (_iswctype_l(_c,_PUNCT|_ALPHA|_DIGIT,_p))
#Defina _iswcntrl_l(_c,_p) (_iswctype_l(_c,_CONTROL,_p))
#SeNãoDefinido _CTYPE_DISABLE_MACROS
#Defina isleadbyte(_c) (__PCTYPE_FUNC[(Natural Caractere)(_c)] & _LEADBYTE)
#FimSe
#FimSe
#Defina _WCTYPE_INLINE_DEFINED
#FimSe

#Se !Definido(_POSIX_) || Definido(__GNUC__)
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

#SeNãoDefinido _STAT_DEFINED
#Defina _STAT_DEFINED

#SeDefinido _USE_32BIT_TIME_T
#SeDefinido WIN64
#Defina _fstat _fstat32
#Defina _stat _stat32
#Defina _wstat _wstat32
#Senão
#Defina _fstat32 _fstat
#Defina _stat32 _stat
#Defina _wstat32 _wstat
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
#FimSe

#SeNãoDefinido _WCONIO_DEFINED
#Defina _WCONIO_DEFINED

#SeNãoDefinido WEOF
#Defina WEOF (wint_t)(0xFFFF)
#FimSe

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t Declaração _getwch(Vazio);
  _CRTIMP wint_t Declaração _getwche(Vazio);
  _CRTIMP wint_t Declaração _putwch(wchar_t _WCh);
  _CRTIMP wint_t Declaração _ungetwch(wint_t _WCh);
  _CRTIMP Inteiro Declaração _cputws(Imutável wchar_t *_String);
  _CRTIMP Inteiro Declaração _cwprintf(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _cwscanf(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _cwscanf_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcwprintf(Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _cwprintf_p(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _vcwprintf_p(Imutável wchar_t *_Format,va_list _ArgList);

  _CRTIMP Inteiro Declaração _cwprintf_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcwprintf_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _cwprintf_p_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcwprintf_p_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  wint_t Declaração _putwch_nolock(wchar_t _WCh);
  wint_t Declaração _getwch_nolock(Vazio);
  wint_t Declaração _getwche_nolock(Vazio);
  wint_t Declaração _ungetwch_nolock(wint_t _WCh);
#FimSe

#SeNãoDefinido _WSTDIO_DEFINED
#Defina _WSTDIO_DEFINED

#SeNãoDefinido WEOF
#Defina WEOF (wint_t)(0xFFFF)
#FimSe

#SeDefinido _POSIX_
  _CRTIMP FILE *Declaração _wfsopen(Imutável wchar_t *_Filename,Imutável wchar_t *_Mode);
#Senão
  _CRTIMP FILE *Declaração _wfsopen(Imutável wchar_t *_Filename,Imutável wchar_t *_Mode,Inteiro _ShFlag);
#FimSe

  wint_t Declaração fgetwc(FILE *_File);
  _CRTIMP wint_t Declaração _fgetwchar(Vazio);
  wint_t Declaração fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t Declaração _fputwchar(wchar_t _Ch);
  wint_t Declaração getwc(FILE *_File);
  wint_t Declaração getwchar(Vazio);
  wint_t Declaração putwc(wchar_t _Ch,FILE *_File);
  wint_t Declaração putwchar(wchar_t _Ch);
  wint_t Declaração ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *Declaração fgetws(wchar_t *_Dst,Inteiro _SizeInWords,FILE *_File);
  Inteiro Declaração fputws(Imutável wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *Declaração _getws(wchar_t *_String);
  _CRTIMP Inteiro Declaração _putws(Imutável wchar_t *_Str);
  Inteiro Declaração fwprintf(FILE *_File,Imutável wchar_t *_Format,...);
  Inteiro Declaração wprintf(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _scwprintf(Imutável wchar_t *_Format,...);
  Inteiro Declaração vfwprintf(FILE *_File,Imutável wchar_t *_Format,va_list _ArgList);
  Inteiro Declaração vwprintf(Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração swprintf(wchar_t*, Imutável wchar_t*, ...);
  _CRTIMP Inteiro Declaração vswprintf(wchar_t*, Imutável wchar_t*,va_list);
  _CRTIMP Inteiro Declaração _swprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _vswprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _snwprintf(wchar_t *_Dest,size_t _Count,Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _vsnwprintf(wchar_t *_Dest,size_t _Count,Imutável wchar_t *_Format,va_list _Args);
#SeNãoDefinido __NO_ISOCEXT  /* externs in libmingwex.a */
  Inteiro Declaração snwprintf (wchar_t *s, size_t n, Imutável wchar_t * format, ...);
  __CRT_INLINE Inteiro Declaração vsnwprintf (wchar_t *s, size_t n, Imutável wchar_t *format, va_list arg) { Retorne _vsnwprintf(s,n,format,arg); }
  Inteiro Declaração vwscanf (Imutável wchar_t *, va_list);
  Inteiro Declaração vfwscanf (FILE *,Imutável wchar_t *,va_list);
  Inteiro Declaração vswscanf (Imutável wchar_t *,Imutável wchar_t *,va_list);
#FimSe
  _CRTIMP Inteiro Declaração _fwprintf_p(FILE *_File,Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _wprintf_p(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _vfwprintf_p(FILE *_File,Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vwprintf_p(Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _swprintf_p(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _vswprintf_p(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _scwprintf_p(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _vscwprintf_p(Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _wprintf_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _wprintf_p_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vwprintf_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vwprintf_p_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _fwprintf_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _fwprintf_p_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vfwprintf_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vfwprintf_p_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _swprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _swprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vswprintf_c_l(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vswprintf_p_l(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _scwprintf_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _scwprintf_p_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vscwprintf_p_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _snwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vsnwprintf_l(wchar_t *_DstBuf,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _swprintf(wchar_t *_Dest,Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _vswprintf(wchar_t *_Dest,Imutável wchar_t *_Format,va_list _Args);
  _CRTIMP Inteiro Declaração __swprintf_l(wchar_t *_Dest,Imutável wchar_t *_Format,_locale_t _Plocinfo,...);
  _CRTIMP Inteiro Declaração __vswprintf_l(wchar_t *_Dest,Imutável wchar_t *_Format,_locale_t _Plocinfo,va_list _Args);
#SeNãoDefinido RC_INVOKED
#Inclua <vadefs.h>
#FimSe

#SeDefinido _CRT_NON_CONFORMING_SWPRINTFS
#SeNãoDefinido __cplusplus
#Defina swprintf _swprintf
#Defina vswprintf _vswprintf
#Defina _swprintf_l __swprintf_l
#Defina _vswprintf_l __vswprintf_l
#FimSe
#FimSe

  _CRTIMP wchar_t *Declaração _wtempnam(Imutável wchar_t *_Directory,Imutável wchar_t *_FilePrefix);
  _CRTIMP Inteiro Declaração _vscwprintf(Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _vscwprintf_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  Inteiro Declaração fwscanf(FILE *_File,Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _fwscanf_l(FILE *_File,Imutável wchar_t *_Format,_locale_t _Locale,...);
  Inteiro Declaração swscanf(Imutável wchar_t *_Src,Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _swscanf_l(Imutável wchar_t *_Src,Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _snwscanf(Imutável wchar_t *_Src,size_t _MaxCount,Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _snwscanf_l(Imutável wchar_t *_Src,size_t _MaxCount,Imutável wchar_t *_Format,_locale_t _Locale,...);
  Inteiro Declaração wscanf(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _wscanf_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP FILE *Declaração _wfdopen(Inteiro _FileHandle ,Imutável wchar_t *_Mode);
  _CRTIMP FILE *Declaração _wfopen(Imutável wchar_t *_Filename,Imutável wchar_t *_Mode);
  _CRTIMP FILE *Declaração _wfreopen(Imutável wchar_t *_Filename,Imutável wchar_t *_Mode,FILE *_OldFile);

#SeNãoDefinido _CRT_WPERROR_DEFINED
#Defina _CRT_WPERROR_DEFINED
  _CRTIMP Vazio Declaração _wperror(Imutável wchar_t *_ErrMsg);
#FimSe
  _CRTIMP FILE *Declaração _wpopen(Imutável wchar_t *_Command,Imutável wchar_t *_Mode);
#Se !Definido(NO_OLDNAMES) && !Definido(wpopen)
#Defina wpopen	_wpopen
#FimSe
  _CRTIMP Inteiro Declaração _wremove(Imutável wchar_t *_Filename);
  _CRTIMP wchar_t *Declaração _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t Declaração _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t Declaração _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t Declaração _ungetwc_nolock(wint_t _Ch,FILE *_File);

#Esqueça _CRT_GETPUTWCHAR_NOINLINE

#Se !Definido(__cplusplus) || Definido(_CRT_GETPUTWCHAR_NOINLINE)
#Defina getwchar() fgetwc(stdin)
#Defina putwchar(_c) fputwc((_c),stdout)
#Senão
  __CRT_INLINE wint_t Declaração getwchar() {Retorne (fgetwc(stdin)); }
  __CRT_INLINE wint_t Declaração putwchar(wchar_t _C) {Retorne (fputwc(_C,stdout)); }
#FimSe

#Defina getwc(_stm) fgetwc(_stm)
#Defina putwc(_c,_stm) fputwc(_c,_stm)
#Defina _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#Defina _getwc_nolock(_c) _fgetwc_nolock(_c)
#FimSe

#SeNãoDefinido _WSTDLIB_DEFINED
#Defina _WSTDLIB_DEFINED

  _CRTIMP wchar_t *Declaração _itow(Inteiro _Value,wchar_t *_Dest,Inteiro _Radix);
  _CRTIMP wchar_t *Declaração _ltow(Longo _Value,wchar_t *_Dest,Inteiro _Radix);
  _CRTIMP wchar_t *Declaração _ultow(Natural Longo _Value,wchar_t *_Dest,Inteiro _Radix);
  Duplo Declaração wcstod(Imutável wchar_t *_Str,wchar_t **_EndPtr);
  _CRTIMP Duplo Declaração _wcstod_l(Imutável wchar_t *_Str,wchar_t **_EndPtr,_locale_t _Locale);
  Real Declaração wcstof( Imutável wchar_t *nptr, wchar_t **endptr);
#Se !Definido __NO_ISOCEXT /* in libmingwex.a */
  Real Declaração wcstof (Imutável wchar_t * __restrict__, wchar_t ** __restrict__);
  Longo Duplo Declaração wcstold (Imutável wchar_t * __restrict__, wchar_t ** __restrict__);
#FimSe /* __NO_ISOCEXT */
  Longo Declaração wcstol(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix);
  _CRTIMP Longo Declaração _wcstol_l(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  Natural Longo Declaração wcstoul(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix);
  _CRTIMP Natural Longo Declaração _wcstoul_l(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  _CRTIMP wchar_t *Declaração _wgetenv(Imutável wchar_t *_VarName);
#SeNãoDefinido _CRT_WSYSTEM_DEFINED
#Defina _CRT_WSYSTEM_DEFINED
  _CRTIMP Inteiro Declaração _wsystem(Imutável wchar_t *_Command);
#FimSe
  _CRTIMP Duplo Declaração _wtof(Imutável wchar_t *_Str);
  _CRTIMP Duplo Declaração _wtof_l(Imutável wchar_t *_Str,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _wtoi(Imutável wchar_t *_Str);
  _CRTIMP Inteiro Declaração _wtoi_l(Imutável wchar_t *_Str,_locale_t _Locale);
  _CRTIMP Longo Declaração _wtol(Imutável wchar_t *_Str);
  _CRTIMP Longo Declaração _wtol_l(Imutável wchar_t *_Str,_locale_t _Locale);

#Se _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *Declaração _i64tow(__int64 _Val,wchar_t *_DstBuf,Inteiro _Radix);
  _CRTIMP wchar_t *Declaração _ui64tow(Natural __int64 _Val,wchar_t *_DstBuf,Inteiro _Radix);
  _CRTIMP __int64 Declaração _wtoi64(Imutável wchar_t *_Str);
  _CRTIMP __int64 Declaração _wtoi64_l(Imutável wchar_t *_Str,_locale_t _Locale);
  _CRTIMP __int64 Declaração _wcstoi64(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix);
  _CRTIMP __int64 Declaração _wcstoi64_l(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
  _CRTIMP Natural __int64 Declaração _wcstoui64(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix);
  _CRTIMP Natural __int64 Declaração _wcstoui64_l(Imutável wchar_t *_Str,wchar_t **_EndPtr,Inteiro _Radix,_locale_t _Locale);
#FimSe
#FimSe

#SeNãoDefinido _POSIX_
#SeNãoDefinido _WSTDLIBP_DEFINED
#Defina _WSTDLIBP_DEFINED
  _CRTIMP wchar_t *Declaração _wfullpath(wchar_t *_FullPath,Imutável wchar_t *_Path,size_t _SizeInWords);
  _CRTIMP Vazio Declaração _wmakepath(wchar_t *_ResultPath,Imutável wchar_t *_Drive,Imutável wchar_t *_Dir,Imutável wchar_t *_Filename,Imutável wchar_t *_Ext);
#SeNãoDefinido _CRT_WPERROR_DEFINED
#Defina _CRT_WPERROR_DEFINED
  _CRTIMP Vazio Declaração _wperror(Imutável wchar_t *_ErrMsg);
#FimSe
  _CRTIMP Inteiro Declaração _wputenv(Imutável wchar_t *_EnvString);
  _CRTIMP Vazio Declaração _wsearchenv(Imutável wchar_t *_Filename,Imutável wchar_t *_EnvVar,wchar_t *_ResultPath);
  _CRTIMP Vazio Declaração _wsplitpath(Imutável wchar_t *_FullPath,wchar_t *_Drive,wchar_t *_Dir,wchar_t *_Filename,wchar_t *_Ext);
#FimSe
#FimSe

#SeNãoDefinido _WSTRING_DEFINED
#Defina _WSTRING_DEFINED
  _CRTIMP wchar_t *Declaração _wcsdup(Imutável wchar_t *_Str);
  wchar_t *Declaração wcscat(wchar_t *_Dest,Imutável wchar_t *_Source);
  _CONST_RETURN wchar_t *Declaração wcschr(Imutável wchar_t *_Str,wchar_t _Ch);
  Inteiro Declaração wcscmp(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2);
  wchar_t *Declaração wcscpy(wchar_t *_Dest,Imutável wchar_t *_Source);
  size_t Declaração wcscspn(Imutável wchar_t *_Str,Imutável wchar_t *_Control);
  size_t Declaração wcslen(Imutável wchar_t *_Str);
  size_t Declaração wcsnlen(Imutável wchar_t *_Src,size_t _MaxCount);
  wchar_t *Declaração wcsncat(wchar_t *_Dest,Imutável wchar_t *_Source,size_t _Count);
  Inteiro Declaração wcsncmp(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount);
  wchar_t *Declaração wcsncpy(wchar_t *_Dest,Imutável wchar_t *_Source,size_t _Count);
  _CONST_RETURN wchar_t *Declaração wcspbrk(Imutável wchar_t *_Str,Imutável wchar_t *_Control);
  _CONST_RETURN wchar_t *Declaração wcsrchr(Imutável wchar_t *_Str,wchar_t _Ch);
  size_t Declaração wcsspn(Imutável wchar_t *_Str,Imutável wchar_t *_Control);
  _CONST_RETURN wchar_t *Declaração wcsstr(Imutável wchar_t *_Str,Imutável wchar_t *_SubStr);
  wchar_t *Declaração wcstok(wchar_t *_Str,Imutável wchar_t *_Delim);
  _CRTIMP wchar_t *Declaração _wcserror(Inteiro _ErrNum);
  _CRTIMP wchar_t *Declaração __wcserror(Imutável wchar_t *_Str);
  _CRTIMP Inteiro Declaração _wcsicmp(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2);
  _CRTIMP Inteiro Declaração _wcsicmp_l(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _wcsnicmp(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _wcsnicmp_l(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP wchar_t *Declaração _wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  _CRTIMP wchar_t *Declaração _wcsrev(wchar_t *_Str);
  _CRTIMP wchar_t *Declaração _wcsset(wchar_t *_Str,wchar_t _Val);
  _CRTIMP wchar_t *Declaração _wcslwr(wchar_t *_String);
  _CRTIMP wchar_t *_wcslwr_l(wchar_t *_String,_locale_t _Locale);
  _CRTIMP wchar_t *Declaração _wcsupr(wchar_t *_String);
  _CRTIMP wchar_t *_wcsupr_l(wchar_t *_String,_locale_t _Locale);
  size_t Declaração wcsxfrm(wchar_t *_Dst,Imutável wchar_t *_Src,size_t _MaxCount);
  _CRTIMP size_t Declaração _wcsxfrm_l(wchar_t *_Dst,Imutável wchar_t *_Src,size_t _MaxCount,_locale_t _Locale);
  Inteiro Declaração wcscoll(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2);
  _CRTIMP Inteiro Declaração _wcscoll_l(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _wcsicoll(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2);
  _CRTIMP Inteiro Declaração _wcsicoll_l(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _wcsncoll(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _wcsncoll_l(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _wcsnicoll(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _wcsnicoll_l(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount,_locale_t _Locale);

#SeNãoDefinido	NO_OLDNAMES
  wchar_t *Declaração wcsdup(Imutável wchar_t *_Str);
#Defina wcswcs wcsstr
  Inteiro Declaração wcsicmp(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2);
  Inteiro Declaração wcsnicmp(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2,size_t _MaxCount);
  wchar_t *Declaração wcsnset(wchar_t *_Str,wchar_t _Val,size_t _MaxCount);
  wchar_t *Declaração wcsrev(wchar_t *_Str);
  wchar_t *Declaração wcsset(wchar_t *_Str,wchar_t _Val);
  wchar_t *Declaração wcslwr(wchar_t *_Str);
  wchar_t *Declaração wcsupr(wchar_t *_Str);
  Inteiro Declaração wcsicoll(Imutável wchar_t *_Str1,Imutável wchar_t *_Str2);
#FimSe
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

#SeNãoDefinido _WTIME_DEFINED
#Defina _WTIME_DEFINED

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
#FimSe

  Pseudônimo Inteiro mbstate_t;
  Pseudônimo wchar_t _Wint_t;

  wint_t Declaração btowc(Inteiro);
  size_t Declaração mbrlen(Imutável Caractere *_Ch,size_t _SizeInBytes,mbstate_t *_State);
  size_t Declaração mbrtowc(wchar_t *_DstCh,Imutável Caractere *_SrcCh,size_t _SizeInBytes,mbstate_t *_State);
  size_t Declaração mbsrtowcs(wchar_t *_Dest,Imutável Caractere **_PSrc,size_t _Count,mbstate_t *_State);
  size_t Declaração wcrtomb(Caractere *_Dest,wchar_t _Source,mbstate_t *_State);
  size_t Declaração wcsrtombs(Caractere *_Dest,Imutável wchar_t **_PSource,size_t _Count,mbstate_t *_State);
  Inteiro Declaração wctob(wint_t _WCh);

#SeNãoDefinido __NO_ISOCEXT /* these need Fixo lib libmingwex.a */
  wchar_t *Declaração wmemset(wchar_t *s, wchar_t c, size_t n);
  _CONST_RETURN wchar_t *Declaração wmemchr(Imutável wchar_t *s, wchar_t c, size_t n);
  Inteiro wmemcmp(Imutável wchar_t *s1, Imutável wchar_t *s2,size_t n);
  wchar_t *Declaração wmemcpy(wchar_t *s1,Imutável wchar_t *s2,size_t n);
  wchar_t *Declaração wmemmove(wchar_t *s1, Imutável wchar_t *s2, size_t n);
  Longo Longo Declaração wcstoll(Imutável wchar_t *nptr,wchar_t **endptr, Inteiro base);
  Natural Longo Longo Declaração wcstoull(Imutável wchar_t *nptr,wchar_t **endptr, Inteiro base);
#FimSe /* __NO_ISOCEXT */

  Vazio *Declaração memmove(Vazio *_Dst,Imutável Vazio *_Src,size_t _MaxCount);
  Vazio *Declaração memcpy(Vazio *_Dst,Imutável Vazio *_Src,size_t _MaxCount);
  __CRT_INLINE Inteiro Declaração fwide(FILE *_F,Inteiro _M) { (Vazio)_F; Retorne (_M); }
  __CRT_INLINE Inteiro Declaração mbsinit(Imutável mbstate_t *_P) { Retorne (!_P || *_P==0); }
  __CRT_INLINE _CONST_RETURN wchar_t *Declaração wmemchr(Imutável wchar_t *_S,wchar_t _C,size_t _N) { Para (;0<_N;++_S,--_N) Se (*_S==_C) Retorne (_CONST_RETURN wchar_t *)(_S); Retorne (0); }
  __CRT_INLINE Inteiro Declaração wmemcmp(Imutável wchar_t *_S1,Imutável wchar_t *_S2,size_t _N) { Para (; 0 < _N; ++_S1,++_S2,--_N) Se (*_S1!=*_S2) Retorne (*_S1 < *_S2 ? -1 : +1); Retorne (0); }
  __CRT_INLINE wchar_t *Declaração wmemcpy(wchar_t *_S1,Imutável wchar_t *_S2,size_t _N) { Retorne (wchar_t *)memcpy(_S1,_S2,_N*Meça(wchar_t)); }
  __CRT_INLINE wchar_t *Declaração wmemmove(wchar_t *_S1,Imutável wchar_t *_S2,size_t _N) { Retorne (wchar_t *)memmove(_S1,_S2,_N*Meça(wchar_t)); }
  __CRT_INLINE wchar_t *Declaração wmemset(wchar_t *_S,wchar_t _C,size_t _N) {
    wchar_t *_Su = _S;
    Para (;0<_N;++_Su,--_N) {
      *_Su = _C;
    }
    Retorne (_S);
  }
#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)

#Inclua <sec_api/wchar_s.h>
#FimSe
