/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#Inclua <_mingw.h>

#SeNãoDefinido _INC_TCHAR
#Defina _INC_TCHAR

#SeDefinido _STRSAFE_H_INCLUDED_
#Erro Need to Inclua strsafe.h after tchar.h
#FimSe

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#Defina _ftcscat _tcscat
#Defina _ftcschr _tcschr
#Defina _ftcscpy _tcscpy
#Defina _ftcscspn _tcscspn
#Defina _ftcslen _tcslen
#Defina _ftcsncat _tcsncat
#Defina _ftcsncpy _tcsncpy
#Defina _ftcspbrk _tcspbrk
#Defina _ftcsrchr _tcsrchr
#Defina _ftcsspn _tcsspn
#Defina _ftcsstr _tcsstr
#Defina _ftcstok _tcstok

#Defina _ftcsdup _tcsdup
#Defina _ftcsnset _tcsnset
#Defina _ftcsrev _tcsrev
#Defina _ftcsset _tcsset

#Defina _ftcscmp _tcscmp
#Defina _ftcsicmp _tcsicmp
#Defina _ftcsnccmp _tcsnccmp
#Defina _ftcsncmp _tcsncmp
#Defina _ftcsncicmp _tcsncicmp
#Defina _ftcsnicmp _tcsnicmp

#Defina _ftcscoll _tcscoll
#Defina _ftcsicoll _tcsicoll
#Defina _ftcsnccoll _tcsnccoll
#Defina _ftcsncoll _tcsncoll
#Defina _ftcsncicoll _tcsncicoll
#Defina _ftcsnicoll _tcsnicoll

#Defina _ftcsclen _tcsclen
#Defina _ftcsnccat _tcsnccat
#Defina _ftcsnccpy _tcsnccpy
#Defina _ftcsncset _tcsncset

#Defina _ftcsdec _tcsdec
#Defina _ftcsinc _tcsinc
#Defina _ftcsnbcnt _tcsnbcnt
#Defina _ftcsnccnt _tcsnccnt
#Defina _ftcsnextc _tcsnextc
#Defina _ftcsninc _tcsninc
#Defina _ftcsspnp _tcsspnp

#Defina _ftcslwr _tcslwr
#Defina _ftcsupr _tcsupr

#Defina _ftclen _tclen
#Defina _fctecpy _ctecpy
#Defina _fctecmp _ctecmp

#SeNãoDefinido _CONST_RETURN
#SeDefinido __cplusplus
#Defina _CONST_RETURN Imutável
#Defina _CRT_CONST_CORRECT_OVERLOADS
#Senão
#Defina _CONST_RETURN
#FimSe
#FimSe

#Defina _WConst_return _CONST_RETURN

#SeDefinido _UNICODE

#SeDefinido __cplusplus
}
#FimSe

#Inclua <wchar.h>

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido _WCTYPE_T_DEFINED
#Defina _WCTYPE_T_DEFINED
  Pseudônimo Natural Curto wint_t;
  Pseudônimo Natural Curto wctype_t;
#FimSe

#SeNãoDefinido __TCHAR_DEFINED
#Defina __TCHAR_DEFINED
  Pseudônimo wchar_t _TCHAR;
  Pseudônimo wchar_t _TSCHAR;
  Pseudônimo wchar_t _TUCHAR;
  Pseudônimo wchar_t _TXCHAR;
  Pseudônimo wint_t _TINT;
#FimSe

#SeNãoDefinido _TCHAR_DEFINED
#Defina _TCHAR_DEFINED
#SeNãoDefinido	NO_OLDNAMES
  Pseudônimo wchar_t TCHAR;
#FimSe
#FimSe

#Defina _TEOF WEOF

#Defina __T(x) L##x

#Defina _tmain wmain
#Defina _tWinMain wWinMain
#Defina _tenviron _wenviron
#Defina __targv __wargv

#Defina _tprintf wprintf
#Defina _tprintf_l _wprintf_l
#Defina _tprintf_p _wprintf_p
#Defina _tprintf_p_l _wprintf_p_l
#Defina _tcprintf _cwprintf
#Defina _tcprintf_l _cwprintf_l
#Defina _tcprintf_p _cwprintf_p
#Defina _tcprintf_p_l _cwprintf_p_l
#Defina _vtcprintf _vcwprintf
#Defina _vtcprintf_l _vcwprintf_l
#Defina _vtcprintf_p _vcwprintf_p
#Defina _vtcprintf_p_l _vcwprintf_p_l
#Defina _ftprintf fwprintf
#Defina _ftprintf_l _fwprintf_l
#Defina _ftprintf_p _fwprintf_p
#Defina _ftprintf_p_l _fwprintf_p_l
#Defina _stprintf swprintf
#Defina _stprintf_l __swprintf_l
#Defina _stprintf_p _swprintf_p
#Defina _stprintf_p_l _swprintf_p_l
#Defina _sctprintf _scwprintf
#Defina _sctprintf_l _scwprintf_l
#Defina _sctprintf_p _scwprintf_p
#Defina _sctprintf_p_l _scwprintf_p_l
#Defina _sntprintf _snwprintf
#Defina _sntprintf_l _snwprintf_l
#Defina _vtprintf vwprintf
#Defina _vtprintf_l _vwprintf_l
#Defina _vtprintf_p _vwprintf_p
#Defina _vtprintf_p_l _vwprintf_p_l
#Defina _vftprintf vfwprintf
#Defina _vftprintf_l _vfwprintf_l
#Defina _vftprintf_p _vfwprintf_p
#Defina _vftprintf_p_l _vfwprintf_p_l
#Defina _vstprintf vswprintf
#Defina _vstprintf_l _vswprintf_l
#Defina _vstprintf_p _vswprintf_p
#Defina _vstprintf_p_l _vswprintf_p_l
#Defina _vsctprintf _vscwprintf
#Defina _vsctprintf_l _vscwprintf_l
#Defina _vsctprintf_p _vscwprintf_p
#Defina _vsctprintf_p_l _vscwprintf_p_l
#Defina _vsntprintf _vsnwprintf
#Defina _vsntprintf_l _vsnwprintf_l

#Defina _tscanf wscanf
#Defina _tscanf_l _wscanf_l
#Defina _tcscanf _cwscanf
#Defina _tcscanf_l _cwscanf_l
#Defina _ftscanf fwscanf
#Defina _ftscanf_l _fwscanf_l
#Defina _stscanf swscanf
#Defina _stscanf_l _swscanf_l
#Defina _sntscanf _snwscanf
#Defina _sntscanf_l _snwscanf_l

#Defina _fgettc fgetwc
#Defina _fgettc_nolock _fgetwc_nolock
#Defina _fgettchar _fgetwchar
#Defina _fgetts fgetws
#Defina _fputtc fputwc
#Defina _fputtc_nolock _fputwc_nolock
#Defina _fputtchar _fputwchar
#Defina _fputts fputws
#Defina _cputts _cputws
#Defina _cgetts _cgetws
#Defina _gettc getwc
#Defina _gettc_nolock _getwc_nolock
#Defina _gettch _getwch
#Defina _gettch_nolock _getwch_nolock
#Defina _gettche _getwche
#Defina _gettche_nolock _getwche_nolock
#Defina _gettchar getwchar
#Defina _gettchar_nolock _getwchar_nolock
#Defina _getts _getws
#Defina _puttc putwc
#Defina _puttc_nolock _putwc_nolock
#Defina _puttchar putwchar
#Defina _puttchar_nolock _putwchar_nolock
#Defina _puttch _putwch
#Defina _puttch_nolock _putwch_nolock
#Defina _putts _putws
#Defina _ungettc ungetwc
#Defina _ungettc_nolock _ungetwc_nolock
#Defina _ungettch _ungetwch
#Defina _ungettch_nolock _ungetwch_nolock

#Defina _tcstod wcstod
#Defina _tcstol wcstol
#Defina _tcstoul wcstoul
#Defina _tcstoi64 _wcstoi64
#Defina _tcstoui64 _wcstoui64
#Defina _tstof _wtof
#Defina _tstol _wtol
#Defina _tstoi _wtoi
#Defina _tstoi64 _wtoi64
#Defina _tcstod_l _wcstod_l
#Defina _tcstol_l _wcstol_l
#Defina _tcstoul_l _wcstoul_l
#Defina _tcstoi64_l _wcstoi64_l
#Defina _tcstoui64_l _wcstoui64_l
#Defina _tstof_l _wtof_l
#Defina _tstol_l _wtol_l
#Defina _tstoi_l _wtoi_l
#Defina _tstoi64_l _wtoi64_l

#Defina _itot _itow
#Defina _ltot _ltow
#Defina _ultot _ultow
#Defina _ttoi _wtoi
#Defina _ttol _wtol

#Defina _ttoi64 _wtoi64
#Defina _i64tot _i64tow
#Defina _ui64tot _ui64tow

#Defina _tcscat wcscat
#Defina _tcschr wcschr
#Defina _tcscpy wcscpy
#Defina _tcscspn wcscspn
#Defina _tcslen wcslen
#Defina _tcsnlen wcsnlen
#Defina _tcsncat wcsncat
#Defina _tcsncat_l _wcsncat_l
#Defina _tcsncpy wcsncpy
#Defina _tcsncpy_l _wcsncpy_l
#Defina _tcspbrk wcspbrk
#Defina _tcsrchr wcsrchr
#Defina _tcsspn wcsspn
#Defina _tcsstr wcsstr
#Defina _tcstok wcstok
#Defina _tcstok_l _wcstok_l
#Defina _tcserror _wcserror
#Defina __tcserror __wcserror

#Defina _tcsdup _wcsdup
#Defina _tcsnset _wcsnset
#Defina _tcsnset_l _wcsnset_l
#Defina _tcsrev _wcsrev
#Defina _tcsset _wcsset
#Defina _tcsset_l _wcsset_l

#Defina _tcscmp wcscmp
#Defina _tcsicmp _wcsicmp
#Defina _tcsicmp_l _wcsicmp_l
#Defina _tcsnccmp wcsncmp
#Defina _tcsncmp wcsncmp
#Defina _tcsncicmp _wcsnicmp
#Defina _tcsncicmp_l _wcsnicmp_l
#Defina _tcsnicmp _wcsnicmp
#Defina _tcsnicmp_l _wcsnicmp_l

#Defina _tcscoll wcscoll
#Defina _tcscoll_l _wcscoll_l
#Defina _tcsicoll _wcsicoll
#Defina _tcsicoll_l _wcsicoll_l
#Defina _tcsnccoll _wcsncoll
#Defina _tcsnccoll_l _wcsncoll_l
#Defina _tcsncoll _wcsncoll
#Defina _tcsncoll_l _wcsncoll_l
#Defina _tcsncicoll _wcsnicoll
#Defina _tcsncicoll_l _wcsnicoll_l
#Defina _tcsnicoll _wcsnicoll
#Defina _tcsnicoll_l _wcsnicoll_l

#Defina _texecl _wexecl
#Defina _texecle _wexecle
#Defina _texeclp _wexeclp
#Defina _texeclpe _wexeclpe
#Defina _texecv _wexecv
#Defina _texecve _wexecve
#Defina _texecvp _wexecvp
#Defina _texecvpe _wexecvpe

#Defina _tspawnl _wspawnl
#Defina _tspawnle _wspawnle
#Defina _tspawnlp _wspawnlp
#Defina _tspawnlpe _wspawnlpe
#Defina _tspawnv _wspawnv
#Defina _tspawnve _wspawnve
#Defina _tspawnvp _wspawnvp
#Defina _tspawnvp _wspawnvp
#Defina _tspawnvpe _wspawnvpe

#Defina _tsystem _wsystem

#Defina _tasctime _wasctime
#Defina _tctime _wctime
#Defina _tctime32 _wctime32
#Defina _tctime64 _wctime64
#Defina _tstrdate _wstrdate
#Defina _tstrtime _wstrtime
#Defina _tutime _wutime
#Defina _tutime32 _wutime32
#Defina _tutime64 _wutime64
#Defina _tcsftime wcsftime
#Defina _tcsftime_l _wcsftime_l

#Defina _tchdir _wchdir
#Defina _tgetcwd _wgetcwd
#Defina _tgetdcwd _wgetdcwd
#Defina _tgetdcwd_nolock _wgetdcwd_nolock
#Defina _tmkdir _wmkdir
#Defina _trmdir _wrmdir

#Defina _tfullpath _wfullpath
#Defina _tgetenv _wgetenv
#Defina _tmakepath _wmakepath
#Defina _tpgmptr _wpgmptr
#Defina _get_tpgmptr _get_wpgmptr
#Defina _tputenv _wputenv
#Defina _tsearchenv _wsearchenv
#Defina _tsplitpath _wsplitpath

#Defina _tfdopen _wfdopen
#Defina _tfsopen _wfsopen
#Defina _tfopen _wfopen
#Defina _tfreopen _wfreopen
#Defina _tperror _wperror
#Defina _tpopen _wpopen
#Defina _ttempnam _wtempnam
#Defina _ttmpnam _wtmpnam

#Defina _taccess _waccess
#Defina _tchmod _wchmod
#Defina _tcreat _wcreat
#Defina _tfindfirst _wfindfirst
#Defina _tfindfirst32 _wfindfirst32
#Defina _tfindfirst64 _wfindfirst64
#Defina _tfindfirsti64 _wfindfirsti64
#Defina _tfindfirst32i64 _wfindfirst32i64
#Defina _tfindfirst64i32 _wfindfirst64i32
#Defina _tfindnext _wfindnext
#Defina _tfindnext32 _wfindnext32
#Defina _tfindnext64 _wfindnext64
#Defina _tfindnexti64 _wfindnexti64
#Defina _tfindnext32i64 _wfindnext32i64
#Defina _tfindnext64i32 _wfindnext64i32
#Defina _tmktemp _wmktemp
#Defina _topen _wopen
#Defina _tremove _wremove
#Defina _trename _wrename
#Defina _tsopen _wsopen
#Defina _tunlink _wunlink

#Defina _tfinddata_t _wfinddata_t
#Defina _tfinddata32_t _wfinddata32_t
#Defina _tfinddata64_t _wfinddata64_t
#Defina _tfinddatai64_t _wfinddatai64_t
#Defina _tfinddata32i64_t _wfinddata32i64_t
#Defina _tfinddata64i32_t _wfinddata64i32_t

#Defina _tstat _wstat
#Defina _tstat32 _wstat32
#Defina _tstat32i64 _wstat32i64
#Defina _tstat64 _wstat64
#Defina _tstat64i32 _wstat64i32
#Defina _tstati64 _wstati64

#Defina _tsetlocale _wsetlocale

#Defina _tcsclen wcslen
#Defina _tcscnlen wcsnlen
#Defina _tcsclen_l(_String,_Locale) wcslen(_String)
#Defina _tcscnlen_l(_String,_Max_count,_Locale) wcsnlen_l((_String),(_Max_count))
#Defina _tcsnccat wcsncat
#Defina _tcsnccat_l _wcsncat_l
#Defina _tcsnccpy wcsncpy
#Defina _tcsnccpy_l _wcsncpy_l
#Defina _tcsncset _wcsnset

#Defina _tcsdec _wcsdec
#Defina _tcsinc _wcsinc
#Defina _tcsnbcnt _wcsncnt
#Defina _tcsnccnt _wcsncnt
#Defina _tcsnextc _wcsnextc
#Defina _tcsninc _wcsninc
#Defina _tcsspnp _wcsspnp

#Defina _tcslwr _wcslwr
#Defina _tcslwr_l _wcslwr_l
#Defina _tcsupr _wcsupr
#Defina _tcsupr_l _wcsupr_l
#Defina _tcsxfrm wcsxfrm
#Defina _tcsxfrm_l _wcsxfrm_l

#Defina _tclen(_pc) (1)
#Defina _ctecpy(_pc1,_cpc2) ((*(_pc1) = *(_cpc2)))
#Defina _ctecmp(_cpc1,_cpc2) ((*(_cpc1))-(*(_cpc2)))

#Defina _istalnum iswalnum
#Defina _istalnum_l _iswalnum_l
#Defina _istalpha iswalpha
#Defina _istalpha_l _iswalpha_l
#Defina _istascii iswascii
#Defina _istcntrl iswcntrl
#Defina _istcntrl_l _iswcntrl_l
#Defina _istdigit iswdigit
#Defina _istdigit_l _iswdigit_l
#Defina _istgraph iswgraph
#Defina _istgraph_l _iswgraph_l
#Defina _istlower iswlower
#Defina _istlower_l _iswlower_l
#Defina _istprint iswprint
#Defina _istprint_l _iswprint_l
#Defina _istpunct iswpunct
#Defina _istpunct_l _iswpunct_l
#Defina _istspace iswspace
#Defina _istspace_l _iswspace_l
#Defina _istupper iswupper
#Defina _istupper_l _iswupper_l
#Defina _istxdigit iswxdigit
#Defina _istxdigit_l _iswxdigit_l

#Defina _totupper towupper
#Defina _totupper_l _towupper_l
#Defina _totlower towlower
#Defina _totlower_l _towlower_l

#Defina _istlegal(_Char) (1)
#Defina _istlead(_Char) (0)
#Defina _istleadbyte(_Char) (0)
#Defina _istleadbyte_l(_Char,_Locale) (0)

#Defina _wcsdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? NULL : (_cpc2)-1)
#Defina _wcsinc(_pc) ((_pc)+1)
#Defina _wcsnextc(_cpc) ((Natural Inteiro) *(_cpc))
#Defina _wcsninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP size_t Declaração __wcsncnt(Imutável wchar_t *_Str,size_t _MaxCount);
#Defina _wcsncnt(_cpc,_sz) (__wcsncnt(_cpc,_sz))
#Defina _wcsspnp(_cpc1,_cpc2) (!_cpc1 ? NULL : ((*((_cpc1)+wcsspn(_cpc1,_cpc2))) ? ((_cpc1)+wcsspn(_cpc1,_cpc2)) : NULL))
#Defina _wcsncpy_l(_Destination,_Source,_Count,_Locale) (wcsncpy(_Destination,_Source,_Count))
#Defina _wcsncat_l(_Destination,_Source,_Count,_Locale) (wcsncat(_Destination,_Source,_Count))
#Defina _wcstok_l(_String,_Delimiters,_Locale) (wcstok(_String,_Delimiters))
#Defina _wcsnset_l(_Destination,_Value,_Count,_Locale) (_wcsnset(_Destination,_Value,_Count))
#Defina _wcsset_l(_Destination,_Value,_Locale) (_wcsset(_Destination,_Value))

  /* dirent structures and functions */
#Defina _tdirent	_wdirent
#Defina _TDIR 		_WDIR
#Defina _topendir	_wopendir
#Defina _tclosedir	_wclosedir
#Defina _treaddir	_wreaddir
#Defina _trewinddir	_wrewinddir
#Defina _ttelldir	_wtelldir
#Defina _tseekdir	_wseekdir

#Senão

#SeDefinido __cplusplus
}
#FimSe

#Inclua <string.h>

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#Defina _TEOF EOF

#Defina __T(x) x

#Defina _tmain Início
#Defina _tWinMain WinMain
#SeDefinido _POSIX_
#Defina _tenviron environ
#Senão
#Defina _tenviron _environ
#FimSe
#Defina __targv __argv

#Defina _tprintf printf
#Defina _tprintf_l _printf_l
#Defina _tprintf_p _printf_p
#Defina _tprintf_p_l _printf_p_l
#Defina _tcprintf _cprintf
#Defina _tcprintf_l _cprintf_l
#Defina _tcprintf_p _cprintf_p
#Defina _tcprintf_p_l _cprintf_p_l
#Defina _vtcprintf _vcprintf
#Defina _vtcprintf_l _vcprintf_l
#Defina _vtcprintf_p _vcprintf_p
#Defina _vtcprintf_p_l _vcprintf_p_l
#Defina _ftprintf fprintf
#Defina _ftprintf_l _fprintf_l
#Defina _ftprintf_p _fprintf_p
#Defina _ftprintf_p_l _fprintf_p_l
#Defina _stprintf sprintf
#Defina _stprintf_l _sprintf_l
#Defina _stprintf_p _sprintf_p
#Defina _stprintf_p_l _sprintf_p_l
#Defina _sctprintf _scprintf
#Defina _sctprintf_l _scprintf_l
#Defina _sctprintf_p _scprintf_p
#Defina _sctprintf_p_l _scprintf_p_l
#Defina _sntprintf _snprintf
#Defina _sntprintf_l _snprintf_l
#Defina _vtprintf vprintf
#Defina _vtprintf_l _vprintf_l
#Defina _vtprintf_p _vprintf_p
#Defina _vtprintf_p_l _vprintf_p_l
#Defina _vftprintf vfprintf
#Defina _vftprintf_l _vfprintf_l
#Defina _vftprintf_p _vfprintf_p
#Defina _vftprintf_p_l _vfprintf_p_l
#Defina _vstprintf vsprintf
#Defina _vstprintf_l _vsprintf_l
#Defina _vstprintf_p _vsprintf_p
#Defina _vstprintf_p_l _vsprintf_p_l
#Defina _vsctprintf _vscprintf
#Defina _vsctprintf_l _vscprintf_l
#Defina _vsctprintf_p _vscprintf_p
#Defina _vsctprintf_p_l _vscprintf_p_l
#Defina _vsntprintf _vsnprintf
#Defina _vsntprintf_l _vsnprintf_l

#Defina _tscanf scanf
#Defina _tscanf_l _scanf_l
#Defina _tcscanf _cscanf
#Defina _tcscanf_l _cscanf_l
#Defina _ftscanf fscanf
#Defina _ftscanf_l _fscanf_l
#Defina _stscanf sscanf
#Defina _stscanf_l _sscanf_l
#Defina _sntscanf _snscanf
#Defina _sntscanf_l _snscanf_l

#Defina _fgettc fgetc
#Defina _fgettc_nolock _fgetc_nolock
#Defina _fgettchar _fgetchar
#Defina _fgetts fgets
#Defina _fputtc fputc
#Defina _fputtc_nolock _fputc_nolock
#Defina _fputtchar _fputchar
#Defina _fputts fputs
#Defina _cputts _cputs
#Defina _gettc getc
#Defina _gettc_nolock _getc_nolock
#Defina _gettch _getch
#Defina _gettch_nolock _getch_nolock
#Defina _gettche _getche
#Defina _gettche_nolock _getche_nolock
#Defina _gettchar getchar
#Defina _gettchar_nolock _getchar_nolock
#Defina _getts gets
#Defina _cgetts _cgets
#Defina _puttc putc
#Defina _puttc_nolock _putc_nolock
#Defina _puttchar putchar
#Defina _puttchar_nolock _putchar_nolock
#Defina _puttch _putch
#Defina _puttch_nolock _putch_nolock
#Defina _putts puts
#Defina _ungettc ungetc
#Defina _ungettc_nolock _ungetc_nolock
#Defina _ungettch _ungetch
#Defina _ungettch_nolock _ungetch_nolock

#Defina _tcstod strtod
#Defina _tcstol strtol
#Defina _tcstoul strtoul
#Defina _tstof atof
#Defina _tstol atol
#Defina _tstoi atoi
#Defina _tstoi64 _atoi64
#Defina _tcstod_l _strtod_l
#Defina _tcstol_l _strtol_l
#Defina _tcstoul_l _strtoul_l
#Defina _tstof_l _atof_l
#Defina _tstol_l _atol_l
#Defina _tstoi_l _atoi_l
#Defina _tstoi64_l _atoi64_l

#Defina _itot _itoa
#Defina _ltot _ltoa
#Defina _ultot _ultoa
#Defina _ttoi atoi
#Defina _ttol atol

#Defina _ttoi64 _atoi64
#Defina _tcstoi64 _strtoi64
#Defina _tcstoi64_l _strtoi64_l
#Defina _tcstoui64 _strtoui64
#Defina _tcstoui64_l _strtoui64_l
#Defina _i64tot _i64toa
#Defina _ui64tot _ui64toa

#Defina _tcscat strcat
#Defina _tcscpy strcpy
#Defina _tcsdup _strdup
#Defina _tcslen strlen
#Se 0
#Defina _tcsnlen strnlen
#FimSe
#Defina _tcsxfrm strxfrm
#Defina _tcsxfrm_l _strxfrm_l
#Defina _tcserror strerror
#Defina __tcserror _strerror

#Defina _texecl _execl
#Defina _texecle _execle
#Defina _texeclp _execlp
#Defina _texeclpe _execlpe
#Defina _texecv _execv
#Defina _texecve _execve
#Defina _texecvp _execvp
#Defina _texecvpe _execvpe

#Defina _tspawnl _spawnl
#Defina _tspawnle _spawnle
#Defina _tspawnlp _spawnlp
#Defina _tspawnlpe _spawnlpe
#Defina _tspawnv _spawnv
#Defina _tspawnve _spawnve
#Defina _tspawnvp _spawnvp
#Defina _tspawnvpe _spawnvpe

#Defina _tsystem system

#Defina _tasctime asctime
#Defina _tctime ctime
#Defina _tctime32 _ctime32
#Defina _tctime64 _ctime64
#Defina _tstrdate _strdate
#Defina _tstrtime _strtime
#Defina _tutime _utime
#Defina _tutime32 _utime32
#Defina _tutime64 _utime64
#Defina _tcsftime strftime
#Defina _tcsftime_l _strftime_l

#Defina _tchdir _chdir
#Defina _tgetcwd _getcwd
#Defina _tgetdcwd _getdcwd
#Defina _tgetdcwd_nolock _getdcwd_nolock
#Defina _tmkdir _mkdir
#Defina _trmdir _rmdir

#Defina _tfullpath _fullpath
#Defina _tgetenv getenv
#Defina _tmakepath _makepath
#Defina _tpgmptr _pgmptr
#Defina _get_tpgmptr _get_pgmptr
#Defina _tputenv _putenv
#Defina _tsearchenv _searchenv
#Defina _tsplitpath _splitpath

#SeDefinido _POSIX_
#Defina _tfdopen fdopen
#Senão
#Defina _tfdopen _fdopen
#FimSe
#Defina _tfsopen _fsopen
#Defina _tfopen fopen
#Defina _tfreopen freopen
#Defina _tperror perror
#Defina _tpopen _popen
#Defina _ttempnam _tempnam
#Defina _ttmpnam tmpnam

#Defina _tchmod _chmod
#Defina _tcreat _creat
#Defina _tfindfirst _findfirst
#Defina _tfindfirst32 _findfirst32
#Defina _tfindfirst64 _findfirst64
#Defina _tfindfirsti64 _findfirsti64
#Defina _tfindfirst32i64 _findfirst32i64
#Defina _tfindfirst64i32 _findfirst64i32
#Defina _tfindnext _findnext
#Defina _tfindnext32 _findnext32
#Defina _tfindnext64 _findnext64
#Defina _tfindnexti64 _findnexti64
#Defina _tfindnext32i64 _findnext32i64
#Defina _tfindnext64i32 _findnext64i32
#Defina _tmktemp _mktemp

#SeDefinido _POSIX_
#Defina _topen open
#Defina _taccess access
#Senão
#Defina _topen _open
#Defina _taccess _access
#FimSe

#Defina _tremove remove
#Defina _trename rename
#Defina _tsopen _sopen
#Defina _tunlink _unlink

#Defina _tfinddata_t _finddata_t
#Defina _tfinddata32_t _finddata32_t
#Defina _tfinddata64_t __finddata64_t
#Defina _tfinddatai64_t _finddatai64_t
#Defina _tfinddata32i64_t _finddata32i64_t
#Defina _tfinddata64i32_t _finddata64i32_t

#Defina _istascii __isascii
#Defina _istcntrl iscntrl
#Defina _istcntrl_l _iscntrl_l
#Defina _istxdigit isxdigit
#Defina _istxdigit_l _isxdigit_l

#Defina _tstat _stat
#Defina _tstat32 _stat32
#Defina _tstat32i64 _stat32i64
#Defina _tstat64 _stat64
#Defina _tstat64i32 _stat64i32
#Defina _tstati64 _stati64

#Defina _tsetlocale setlocale

#SeDefinido _MBCS

#SeDefinido __cplusplus
}
#FimSe

#Inclua <mbstring.h>

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido __TCHAR_DEFINED
  Pseudônimo Caractere _TCHAR;
  Pseudônimo Bilateral Caractere _TSCHAR;
  Pseudônimo Natural Caractere _TUCHAR;
  Pseudônimo Natural Caractere _TXCHAR;
  Pseudônimo Natural Inteiro _TINT;
#Defina __TCHAR_DEFINED
#FimSe

#SeNãoDefinido _TCHAR_DEFINED
#SeNãoDefinido	NO_OLDNAMES
  Pseudônimo Caractere TCHAR;
#FimSe
#Defina _TCHAR_DEFINED
#FimSe

#SeDefinido _MB_MAP_DIRECT

#Defina _tcschr _mbschr
#Defina _tcscspn _mbscspn
#Defina _tcsncat _mbsnbcat
#Defina _tcsncat_l _mbsnbcat_l
#Defina _tcsncpy _mbsnbcpy
#Defina _tcsncpy_l _mbsnbcpy_l
#Defina _tcspbrk _mbspbrk
#Defina _tcsrchr _mbsrchr
#Defina _tcsspn _mbsspn
#Defina _tcsstr _mbsstr
#Defina _tcstok _mbstok
#Defina _tcstok_l _mbstok_l

#Defina _tcsnset _mbsnbset
#Defina _tcsnset_l _mbsnbset_l
#Defina _tcsrev _mbsrev
#Defina _tcsset _mbsset
#Defina _tcsset_l _mbsset_l

#Defina _tcscmp _mbscmp
#Defina _tcsicmp _mbsicmp
#Defina _tcsicmp_l _mbsicmp_l
#Defina _tcsnccmp _mbsncmp
#Defina _tcsncmp _mbsnbcmp
#Defina _tcsncicmp _mbsnicmp
#Defina _tcsncicmp_l _mbsnicmp_l
#Defina _tcsnicmp _mbsnbicmp
#Defina _tcsnicmp_l _mbsnbicmp_l

#Defina _tcscoll _mbscoll
#Defina _tcscoll_l _mbscoll_l
#Defina _tcsicoll _mbsicoll
#Defina _tcsicoll_l _mbsicoll_l
#Defina _tcsnccoll _mbsncoll
#Defina _tcsnccoll_l _mbsncoll_l
#Defina _tcsncoll _mbsnbcoll
#Defina _tcsncoll_l _mbsnbcoll_l
#Defina _tcsncicoll _mbsnicoll
#Defina _tcsncicoll_l _mbsnicoll_l
#Defina _tcsnicoll _mbsnbicoll
#Defina _tcsnicoll_l _mbsnbicoll_l

#Defina _tcsclen _mbslen
#Defina _tcscnlen _mbsnlen
#Defina _tcsclen_l _mbslen_l
#Defina _tcscnlen_l _mbsnlen_l
#Defina _tcsnccat _mbsncat
#Defina _tcsnccat_l _mbsncat_l
#Defina _tcsnccpy _mbsncpy
#Defina _tcsnccpy_l _mbsncpy_l
#Defina _tcsncset _mbsnset
#Defina _tcsncset_l _mbsnset_l

#Defina _tcsdec _mbsdec
#Defina _tcsinc _mbsinc
#Defina _tcsnbcnt _mbsnbcnt
#Defina _tcsnccnt _mbsnccnt
#Defina _tcsnextc _mbsnextc
#Defina _tcsninc _mbsninc
#Defina _tcsspnp _mbsspnp

#Defina _tcslwr _mbslwr
#Defina _tcslwr_l _mbslwr_l
#Defina _tcsupr _mbsupr
#Defina _tcsupr_l _mbsupr_l

#Defina _tclen _mbclen
#Defina _ctecpy _mbccpy
#Defina _ctecpy_l _mbccpy_l
#Senão

  _CRTIMP _CONST_RETURN Caractere *Declaração _tcschr(Imutável Caractere *_Str,Natural Inteiro _Val);
  _CRTIMP size_t Declaração _tcscspn(Imutável Caractere *_Str,Imutável Caractere *_Control);
  _CRTIMP Caractere *Declaração _tcsncat(Caractere *_Dst,Imutável Caractere *_Src,size_t _MaxCount);
  _CRTIMP Caractere *Declaração _tcsncat_l(Caractere *_Dst,Imutável Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _tcsncpy(Caractere *_Dst,Imutável Caractere *_Src,size_t _MaxCount);
  _CRTIMP Caractere *Declaração _tcsncpy_l(Caractere *_Dst,Imutável Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP _CONST_RETURN Caractere *Declaração _tcspbrk(Imutável Caractere *_Str,Imutável Caractere *_Control);
  _CRTIMP _CONST_RETURN Caractere *Declaração _tcsrchr(Imutável Caractere *_Str,Natural Inteiro _Ch);
  _CRTIMP size_t Declaração _tcsspn(Imutável Caractere *_Str,Imutável Caractere *_Control);
  _CRTIMP _CONST_RETURN Caractere *Declaração _tcsstr(Imutável Caractere *_Str,Imutável Caractere *_Substr);
  _CRTIMP Caractere *Declaração _tcstok(Caractere *_Str,Imutável Caractere *_Delim);
  _CRTIMP Caractere *Declaração _tcstok_l(Caractere *_Str,Imutável Caractere *_Delim,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _tcsnset(Caractere *_Str,Natural Inteiro _Val,size_t _MaxCount);
  _CRTIMP Caractere *Declaração _tcsrev(Caractere *_Str);
  _CRTIMP Caractere *Declaração _tcsset(Caractere *_Str,Natural Inteiro _Val);
  _CRTIMP Caractere *Declaração _tcsset_l(Caractere *_Str,Natural Inteiro _Val,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _tcscmp(Imutável Caractere *_Str1,Imutável Caractere *_Str);
  _CRTIMP Inteiro Declaração _tcsicmp(Imutável Caractere *_Str1,Imutável Caractere *_Str2);
  _CRTIMP Inteiro Declaração _tcsicmp_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _tcsnccmp(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _tcsncmp(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _tcsncicmp(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _tcsncicmp_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _tcsnicmp(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _tcsnicmp_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _tcscoll(Imutável Caractere *_Str1,Imutável Caractere *_Str2);
  _CRTIMP Inteiro Declaração _tcscoll_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _tcsicoll(Imutável Caractere *_Str1,Imutável Caractere *_Str2);
  _CRTIMP Inteiro Declaração _tcsicoll_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _tcsnccoll(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _tcsnccoll_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _tcsncoll(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _tcsncoll_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _tcsncicoll(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _tcsncicoll_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Inteiro Declaração _tcsnicoll(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount);
  _CRTIMP Inteiro Declaração _tcsnicoll_l(Imutável Caractere *_Str1,Imutável Caractere *_Str2,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP size_t Declaração _tcsclen(Imutável Caractere *_Str);
  _CRTIMP size_t Declaração _tcscnlen(Imutável Caractere *_Str,size_t _MaxCount);
  _CRTIMP size_t Declaração _tcsclen_l(Imutável Caractere *_Str,_locale_t _Locale);
  _CRTIMP size_t Declaração _tcscnlen_l(Imutável Caractere *_Str,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _tcsnccat(Caractere *_Dst,Imutável Caractere *_Src,size_t _MaxCount);
  _CRTIMP Caractere *Declaração _tcsnccat_l(Caractere *_Dst,Imutável Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _tcsnccpy(Caractere *_Dst,Imutável Caractere *_Src,size_t _MaxCount);
  _CRTIMP Caractere *Declaração _tcsnccpy_l(Caractere *_Dst,Imutável Caractere *_Src,size_t _MaxCount,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _tcsncset(Caractere *_Str,Natural Inteiro _Val,size_t _MaxCount);
  _CRTIMP Caractere *Declaração _tcsdec(Imutável Caractere *_Start,Imutável Caractere *_Pos);
  _CRTIMP Caractere *Declaração _tcsinc(Imutável Caractere *_Ptr);
  _CRTIMP size_t Declaração _tcsnbcnt(Imutável Caractere *_Str,size_t _MaxCount);
  _CRTIMP size_t Declaração _tcsnccnt(Imutável Caractere *_Str,size_t _MaxCount);
  _CRTIMP Natural Inteiro Declaração _tcsnextc (Imutável Caractere *_Str);
  _CRTIMP Caractere *Declaração _tcsninc(Imutável Caractere *_Ptr,size_t _Count);
  _CRTIMP Caractere *Declaração _tcsspnp(Imutável Caractere *_Str1,Imutável Caractere *_Str2);
  _CRTIMP Caractere *Declaração _tcslwr(Caractere *_Str);
  _CRTIMP Caractere *Declaração _tcslwr_l(Caractere *_Str,_locale_t _Locale);
  _CRTIMP Caractere *Declaração _tcsupr(Caractere *_Str);
  _CRTIMP Caractere *Declaração _tcsupr_l(Caractere *_Str,_locale_t _Locale);
  _CRTIMP size_t Declaração _tclen(Imutável Caractere *_Str);
  _CRTIMP Vazio Declaração _ctecpy(Caractere *_DstCh,Imutável Caractere *_SrcCh);

#SeDefinido __cplusplus
#SeNãoDefinido _CPP_TCHAR_INLINES_DEFINED
#Defina _CPP_TCHAR_INLINES_DEFINED
  Externo "C++" {
    Externo Integrado Caractere *Declaração _tcschr(Caractere *_S,Natural Inteiro _C) { Retorne ((Caractere *)_tcschr((Imutável Caractere *)_S,_C)); }
    Externo Integrado Caractere *Declaração _tcspbrk(Caractere *_S,Imutável Caractere *_P) { Retorne ((Caractere *)_tcspbrk((Imutável Caractere *)_S,_P)); }
    Externo Integrado Caractere *Declaração _tcsrchr(Caractere *_S,Natural Inteiro _C) { Retorne ((Caractere *)_tcsrchr((Imutável Caractere *)_S,_C)); }
    Externo Integrado Caractere *Declaração _tcsstr(Caractere *_S,Imutável Caractere *_P) { Retorne ((Caractere *)_tcsstr((Imutável Caractere *)_S,_P)); }
  }
#FimSe
#FimSe
#FimSe

#Defina _ctecmp(_cp1,_cp2) _tcsnccmp(_cp1,_cp2,1)

#Defina _istalnum _ismbcalnum
#Defina _istalnum_l _ismbcalnum_l
#Defina _istalpha _ismbcalpha
#Defina _istalpha_l _ismbcalpha_l
#Defina _istdigit _ismbcdigit
#Defina _istdigit_l _ismbcdigit_l
#Defina _istgraph _ismbcgraph
#Defina _istgraph_l _ismbcgraph_l
#Defina _istlegal _ismbclegal
#Defina _istlegal_l _ismbclegal_l
#Defina _istlower _ismbclower
#Defina _istlower_l _ismbclower_l
#Defina _istprint _ismbcprint
#Defina _istprint_l _ismbcprint_l
#Defina _istpunct _ismbcpunct
#Defina _istpunct_l _ismbcpunct_l
#Defina _istspace _ismbcspace
#Defina _istspace_l _ismbcspace_l
#Defina _istupper _ismbcupper
#Defina _istupper_l _ismbcupper_l

#Defina _totupper _mbctoupper
#Defina _totupper_l _mbctoupper_l
#Defina _totlower _mbctolower
#Defina _totlower_l _mbctolower_l

#Defina _istlead _ismbblead
#Defina _istleadbyte isleadbyte
#Defina _istleadbyte_l _isleadbyte_l
#Senão

#SeNãoDefinido __TCHAR_DEFINED
#Defina __TCHAR_DEFINED
  Pseudônimo Caractere _TCHAR;
  Pseudônimo Bilateral Caractere _TSCHAR;
  Pseudônimo Natural Caractere _TUCHAR;
  Pseudônimo Caractere _TXCHAR;
  Pseudônimo Inteiro _TINT;
#FimSe

#SeNãoDefinido _TCHAR_DEFINED
#Defina _TCHAR_DEFINED
#SeNãoDefinido	NO_OLDNAMES
  Pseudônimo Caractere TCHAR;
#FimSe
#FimSe

#Defina _tcschr strchr
#Defina _tcscspn strcspn
#Defina _tcsncat strncat
#Defina _tcsncat_l _strncat_l
#Defina _tcsncpy strncpy
#Defina _tcsncpy_l _strncpy_l
#Defina _tcspbrk strpbrk
#Defina _tcsrchr strrchr
#Defina _tcsspn strspn
#Defina _tcsstr strstr
#Defina _tcstok strtok
#Defina _tcstok_l _strtok_l

#Defina _tcsnset _strnset
#Defina _tcsnset_l _strnset_l
#Defina _tcsrev _strrev
#Defina _tcsset _strset

#Defina _tcscmp strcmp
#Defina _tcsicmp _stricmp
#Defina _tcsicmp_l _stricmp_l
#Defina _tcsnccmp strncmp
#Defina _tcsncmp strncmp
#Defina _tcsncicmp _strnicmp
#Defina _tcsncicmp_l _strnicmp_l
#Defina _tcsnicmp _strnicmp
#Defina _tcsnicmp_l _strnicmp_l

#Defina _tcscoll strcoll
#Defina _tcscoll_l _strcoll_l
#Defina _tcsicoll _stricoll
#Defina _tcsicoll_l _stricoll_l
#Defina _tcsnccoll _strncoll
#Defina _tcsnccoll_l _strncoll_l
#Defina _tcsncoll _strncoll
#Defina _tcsncoll_l _strncoll_l
#Defina _tcsncicoll _strnicoll
#Defina _tcsncicoll_l _strnicoll_l
#Defina _tcsnicoll _strnicoll
#Defina _tcsnicoll_l _strnicoll_l

#Defina _tcsclen strlen
#Defina _tcscnlen strnlen
#Defina _tcsclen_l(_String,_Locale) strlen(_String)
#Defina _tcscnlen_l(_String,_Max_count,_Locale) strnlen_l((_String),(_Max_count))
#Defina _tcsnccat strncat
#Defina _tcsnccat_l _strncat_l
#Defina _tcsnccpy strncpy
#Defina _tcsnccpy_l _strncpy_l
#Defina _tcsncset _strnset

#Defina _tcsdec _strdec
#Defina _tcsinc _strinc
#Defina _tcsnbcnt _strncnt
#Defina _tcsnccnt _strncnt
#Defina _tcsnextc _strnextc
#Defina _tcsninc _strninc
#Defina _tcsspnp _strspnp

#Defina _tcslwr _strlwr
#Defina _tcslwr_l _strlwr_l
#Defina _tcsupr _strupr
#Defina _tcsupr_l _strupr_l
#Defina _tcsxfrm strxfrm
#Defina _tcsxfrm_l _strxfrm_l

#Defina _istlead(_Char) (0)
#Defina _istleadbyte(_Char) (0)
#Defina _istleadbyte_l(_Char,_Locale) (0)

#Defina _tclen(_pc) (1)
#Defina _ctecpy(_pc1,_cpc2) (*(_pc1) = *(_cpc2))
#Defina _ctecmp(_cpc1,_cpc2) (((Natural Caractere)*(_cpc1))-((Natural Caractere)*(_cpc2)))

  /* dirent structures and functions */
#Defina _tdirent	dirent
#Defina _TDIR 		DIR
#Defina _topendir	opendir
#Defina _tclosedir	closedir
#Defina _treaddir	readdir
#Defina _trewinddir	rewinddir
#Defina _ttelldir	telldir
#Defina _tseekdir	seekdir

#Defina _istalnum isalnum
#Defina _istalnum_l _isalnum_l
#Defina _istalpha isalpha
#Defina _istalpha_l _isalpha_l
#Defina _istdigit isdigit
#Defina _istdigit_l _isdigit_l
#Defina _istgraph isgraph
#Defina _istgraph_l _isgraph_l
#Defina _istlower islower
#Defina _istlower_l _islower_l
#Defina _istprint isprint
#Defina _istprint_l _isprint_l
#Defina _istpunct ispunct
#Defina _istpunct_l _ispunct_l
#Defina _istspace isspace
#Defina _istspace_l _isspace_l
#Defina _istupper isupper
#Defina _istupper_l _isupper_l

#Defina _totupper toupper
#Defina _totupper_l _toupper_l
#Defina _totlower tolower
#Defina _totlower_l _tolower_l

#Defina _istlegal(_c) (1)

#SeNãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#Defina _strdec(_cpc1,_cpc2) ((_cpc1)>=(_cpc2) ? NULL : (_cpc2)-1)
#Defina _strinc(_pc) ((_pc)+1)
#Defina _strnextc(_cpc) ((Natural Inteiro) *(Imutável Natural Caractere *)(_cpc))
#Defina _strninc(_pc,_sz) (((_pc)+(_sz)))
  _CRTIMP size_t Declaração __strncnt(Imutável Caractere *_Str,size_t _Cnt);
#Defina _strncnt(_cpc,_sz) (__strncnt(_cpc,_sz))
#Defina _strspnp(_cpc1,_cpc2) (!_cpc1 ? NULL : ((*((_cpc1)+strspn(_cpc1,_cpc2))) ? ((_cpc1)+strspn(_cpc1,_cpc2)) : NULL))

#Defina _strncpy_l(_Destination,_Source,_Count,_Locale) (strncpy(_Destination,_Source,_Count))
#Defina _strncat_l(_Destination,_Source,_Count,_Locale) (strncat(_Destination,_Source,_Count))
#Defina _strtok_l(_String,_Delimiters,_Locale) (strtok(_String,_Delimiters))
#Defina _strnset_l(_Destination,_Value,_Count,_Locale) (_strnset(_Destination,_Value,_Count))
#Defina _strset_l(_Destination,_Value,_Locale) (_strset(_Destination,_Value))
#FimSe
#FimSe

#Defina _T(x) __T(x)
#Defina _TEXT(x) __T(x)

#SeDefinido __cplusplus
}
#FimSe

#Inclua <sec_api/tchar_s.h>
#FimSe
