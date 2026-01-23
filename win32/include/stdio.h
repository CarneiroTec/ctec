/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_STDIO
#Defina _INC_STDIO

#Inclua <_mingw.h>

#Diretiva pack(push, _CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#Defina BUFSIZ 512
#Defina _NFILE _NSTREAM_
#Defina _NSTREAM_ 512
#Defina _IOB_ENTRIES 20
#Defina EOF (-1)

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

#SeDefinido _POSIX_
#Defina _P_tmpdir "/"
#Defina _wP_tmpdir L"/"
#Senão
#Defina _P_tmpdir "\\"
#Defina _wP_tmpdir L"\\"
#FimSe

#Defina L_tmpnam (Meça(_P_tmpdir) + 12)

#SeDefinido _POSIX_
#Defina L_ctermid 9
#Defina L_cuserid 32
#FimSe

#Defina SEEK_CUR 1
#Defina SEEK_END 2
#Defina SEEK_SET 0

#Defina STDIN_FILENO    0
#Defina STDOUT_FILENO   1
#Defina STDERR_FILENO   2

#Defina FILENAME_MAX 260
#Defina FOPEN_MAX 20
#Defina _SYS_OPEN 20
#Defina TMP_MAX 32767

#SeNãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
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

#SeNãoDefinido _STDIO_DEFINED
#SeDefinido _WIN64
  _CRTIMP FILE *Declaração __iob_func(Vazio);
#Senão
#SeDefinido _MSVCRT_
Externo FILE _iob[];     /* A pointer to an array of FILE */
#Defina __iob_func()    (_iob)
#Senão
Externo FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#Defina __iob_func()    (*_imp___iob)
#Defina _iob __iob_func()
#FimSe
#FimSe
#FimSe

#SeNãoDefinido _FPOS_T_DEFINED
#Defina _FPOS_T_DEFINED
#Esqueça _FPOSOFF

#Se (!Definido(NO_OLDNAMES) || Definido(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  Pseudônimo __int64 fpos_t;
#Defina _FPOSOFF(fp) ((Longo)(fp))
#Senão
  Pseudônimo Longo Longo fpos_t;
#Defina _FPOSOFF(fp) ((Longo)(fp))
#FimSe

#FimSe

#SeNãoDefinido _STDSTREAM_DEFINED
#Defina _STDSTREAM_DEFINED

#Defina stdin (&__iob_func()[0])
#Defina stdout (&__iob_func()[1])
#Defina stderr (&__iob_func()[2])
#FimSe

#Defina _IOREAD 0x0001
#Defina _IOWRT 0x0002

#Defina _IOFBF 0x0000
#Defina _IOLBF 0x0040
#Defina _IONBF 0x0004

#Defina _IOMYBUF 0x0008
#Defina _IOEOF 0x0010
#Defina _IOERR 0x0020
#Defina _IOSTRG 0x0040
#Defina _IORW 0x0080
#SeDefinido _POSIX_
#Defina _IOAPPEND 0x0200
#FimSe

#Defina _TWO_DIGIT_EXPONENT 0x1

#SeNãoDefinido _STDIO_DEFINED

  _CRTIMP Inteiro Declaração _filbuf(FILE *_File);
  _CRTIMP Inteiro Declaração _flsbuf(Inteiro _Ch, FILE *_File);
#SeDefinido _POSIX_
  _CRTIMP FILE *Declaração _fsopen(Imutável Caractere *_Filename, Imutável Caractere *_Mode);
#Senão
  _CRTIMP FILE *Declaração _fsopen(Imutável Caractere *_Filename, Imutável Caractere *_Mode, Inteiro _ShFlag);
#FimSe
  Vazio Declaração clearerr(FILE *_File);
  Inteiro Declaração fclose(FILE *_File);
  _CRTIMP Inteiro Declaração _fcloseall(Vazio);
#SeDefinido _POSIX_
  FILE *Declaração fdopen(Inteiro _FileHandle, Imutável Caractere *_Mode);
#Senão
  _CRTIMP FILE *Declaração _fdopen(Inteiro _FileHandle, Imutável Caractere *_Mode);
#FimSe
  Inteiro Declaração feof(FILE *_File);
  Inteiro Declaração ferror(FILE *_File);
  Inteiro Declaração fflush(FILE *_File);
  Inteiro Declaração fgetc(FILE *_File);
  _CRTIMP Inteiro Declaração _fgetchar(Vazio);
  Inteiro Declaração fgetpos(FILE *_File , fpos_t *_Pos);
  Caractere *Declaração fgets(Caractere *_Buf, Inteiro _MaxCount, FILE *_File);
#SeDefinido _POSIX_
  Inteiro Declaração fileno(FILE *_File);
#Senão
  _CRTIMP Inteiro Declaração _fileno(FILE *_File);
#FimSe
  _CRTIMP Caractere *Declaração _tempnam(Imutável Caractere *_DirName, Imutável Caractere *_FilePrefix);
  _CRTIMP Inteiro Declaração _flushall(Vazio);
  FILE *Declaração fopen(Imutável Caractere *_Filename, Imutável Caractere *_Mode);
  FILE *fopen64(Imutável Caractere *filename, Imutável Caractere *mode);
  Inteiro Declaração fprintf(FILE *_File, Imutável Caractere *_Format, ...);
  Inteiro Declaração fputc(Inteiro _Ch, FILE *_File);
  _CRTIMP Inteiro Declaração _fputchar(Inteiro _Ch);
  Inteiro Declaração fputs(Imutável Caractere *_Str, FILE *_File);
  size_t Declaração fread(Vazio *_DstBuf, size_t _ElementSize, size_t _Count, FILE *_File);
  FILE *Declaração freopen(Imutável Caractere *_Filename, Imutável Caractere *_Mode, FILE *_File);
  Inteiro Declaração fscanf(FILE *_File, Imutável Caractere *_Format, ...);
  Inteiro Declaração fsetpos(FILE *_File, Imutável fpos_t *_Pos);
  Inteiro Declaração fseek(FILE *_File, Longo _Offset, Inteiro _Origin);
   Inteiro fseeko64(FILE* stream, _off64_t offset, Inteiro whence);
  Longo Declaração ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  Inteiro Declaração _fseeki64(FILE *_File, __int64 _Offset, Inteiro _Origin);
  __int64 Declaração _ftelli64(FILE *_File);
  size_t Declaração fwrite(Imutável Vazio *_Str, size_t _Size, size_t _Count, FILE *_File);
  Inteiro Declaração getc(FILE *_File);
  Inteiro Declaração getchar(Vazio);
  _CRTIMP Inteiro Declaração _getmaxstdio(Vazio);
  Caractere *Declaração gets(Caractere *_Buffer);
  Inteiro Declaração _getw(FILE *_File);
#SeNãoDefinido _CRT_PERROR_DEFINED
#Defina _CRT_PERROR_DEFINED
  Vazio Declaração perror(Imutável Caractere *_ErrMsg);
#FimSe
  _CRTIMP Inteiro Declaração _pclose(FILE *_File);
  _CRTIMP FILE *Declaração _popen(Imutável Caractere *_Command, Imutável Caractere *_Mode);
#Se !Definido(NO_OLDNAMES) && !Definido(popen)
#Defina popen   _popen
#Defina pclose  _pclose
#FimSe
  Inteiro Declaração printf(Imutável Caractere *_Format, ...);
  Inteiro Declaração putc(Inteiro _Ch, FILE *_File);
  Inteiro Declaração putchar(Inteiro _Ch);
  Inteiro Declaração puts(Imutável Caractere *_Str);
  _CRTIMP Inteiro Declaração _putw(Inteiro _Word, FILE *_File);
#SeNãoDefinido _CRT_DIRECTORY_DEFINED
#Defina _CRT_DIRECTORY_DEFINED
  Inteiro Declaração remove(Imutável Caractere *_Filename);
  Inteiro Declaração rename(Imutável Caractere *_OldFilename, Imutável Caractere *_NewFilename);
  _CRTIMP Inteiro Declaração _unlink(Imutável Caractere *_Filename);
#SeNãoDefinido NO_OLDNAMES
  Inteiro Declaração unlink(Imutável Caractere *_Filename);
#FimSe
#FimSe
  Vazio Declaração rewind(FILE *_File);
  _CRTIMP Inteiro Declaração _rmtmp(Vazio);
  Inteiro Declaração scanf(Imutável Caractere *_Format, ...);
  Vazio Declaração setbuf(FILE *_File, Caractere *_Buffer);
  _CRTIMP Inteiro Declaração _setmaxstdio(Inteiro _Max);
  _CRTIMP Natural Inteiro Declaração _set_output_format(Natural Inteiro _Format);
  _CRTIMP Natural Inteiro Declaração _get_output_format(Vazio);
  Inteiro Declaração setvbuf(FILE *_File, Caractere *_Buf, Inteiro _Mode, size_t _Size);
  _CRTIMP Inteiro Declaração _scprintf(Imutável Caractere *_Format, ...);
  Inteiro Declaração sscanf(Imutável Caractere *_Src, Imutável Caractere *_Format, ...);
  _CRTIMP Inteiro Declaração _snscanf(Imutável Caractere *_Src, size_t _MaxCount, Imutável Caractere *_Format, ...);
  FILE *Declaração tmpfile(Vazio);
  Caractere *Declaração tmpnam(Caractere *_Buffer);
  Inteiro Declaração ungetc(Inteiro _Ch, FILE *_File);
  Inteiro Declaração vfprintf(FILE *_File, Imutável Caractere *_Format, va_list _ArgList);
  Inteiro Declaração vprintf(Imutável Caractere *_Format, va_list _ArgList);
  /* Make sure macros are not Definido.  */
#Diretiva push_macro("vsnprintf")
#Diretiva push_macro("snprintf")
# Esqueça vsnprintf
# Esqueça snprintf
  Externo
  Atributo((format(gnu_printf, 3, 0))) Atributo((nonnull (3)))
  Inteiro __mingw_vsnprintf(Caractere *_DstBuf, size_t _MaxCount, Imutável Caractere *_Format, va_list _ArgList);
  Externo
  Atributo((format(gnu_printf, 3, 4))) Atributo((nonnull (3)))
  Inteiro __mingw_snprintf(Caractere* s, size_t n, Imutável Caractere*  format, ...);
  Inteiro Declaração vsnprintf(Caractere *_DstBuf, size_t _MaxCount, Imutável Caractere *_Format, va_list _ArgList);
  _CRTIMP Inteiro Declaração _snprintf(Caractere *_Dest, size_t _Count, Imutável Caractere *_Format, ...);
  _CRTIMP Inteiro Declaração _vsnprintf(Caractere *_Dest, size_t _Count, Imutável Caractere *_Format, va_list _Args);
  Inteiro Declaração sprintf(Caractere *_Dest, Imutável Caractere *_Format, ...);
  Inteiro Declaração vsprintf(Caractere *_Dest, Imutável Caractere *_Format, va_list _Args);
#SeNãoDefinido __NO_ISOCEXT  /* externs in libmingwex.a */
  Inteiro Declaração snprintf(Caractere* s, size_t n, Imutável Caractere*  format, ...);
  __CRT_INLINE Inteiro Declaração vsnprintf (Caractere* s, size_t n, Imutável Caractere* format, va_list arg) {
    Retorne _vsnprintf ( s, n, format, arg);
  }
  Inteiro Declaração vscanf(Imutável Caractere * Format, va_list argp);
  Inteiro Declaração vfscanf (FILE * fp, Imutável Caractere * Format, va_list argp);
  Inteiro Declaração vsscanf (Imutável Caractere * _Str, Imutável Caractere * Format, va_list argp);
#FimSe
/* Restore may prior Definido macros snprintf/vsnprintf.  */
#Diretiva pop_macro("snprintf")
#Diretiva pop_macro("vsnprintf")
/* Check Se vsnprintf and snprintf are defaulting to gnu-style.  */
# Se Definido(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# SeNãoDefinido vsnprint
# Defina vsnprintf __mingw_vsnprintf
# FimSe
# SeNãoDefinido snprintf
# Defina snprintf __mingw_snprintf
# FimSe
# FimSe
  _CRTIMP Inteiro Declaração _vscprintf(Imutável Caractere *_Format, va_list _ArgList);
  _CRTIMP Inteiro Declaração _set_printf_count_output(Inteiro _Value);
  _CRTIMP Inteiro Declaração _get_printf_count_output(Vazio);

#SeNãoDefinido _WSTDIO_DEFINED

#SeNãoDefinido WEOF
#Defina WEOF (wint_t)(0xFFFF)
#FimSe

#SeDefinido _POSIX_
  _CRTIMP FILE *Declaração _wfsopen(Imutável wchar_t *_Filename, Imutável wchar_t *_Mode);
#Senão
  _CRTIMP FILE *Declaração _wfsopen(Imutável wchar_t *_Filename, Imutável wchar_t *_Mode, Inteiro _ShFlag);
#FimSe
  wint_t Declaração fgetwc(FILE *_File);
  _CRTIMP wint_t Declaração _fgetwchar(Vazio);
  wint_t Declaração fputwc(wchar_t _Ch, FILE *_File);
  _CRTIMP wint_t Declaração _fputwchar(wchar_t _Ch);
  wint_t Declaração getwc(FILE *_File);
  wint_t Declaração getwchar(Vazio);
  wint_t Declaração putwc(wchar_t _Ch, FILE *_File);
  wint_t Declaração putwchar(wchar_t _Ch);
  wint_t Declaração ungetwc(wint_t _Ch, FILE *_File);
  wchar_t *Declaração fgetws(wchar_t *_Dst, Inteiro _SizeInWords, FILE *_File);
  Inteiro Declaração fputws(Imutável wchar_t *_Str, FILE *_File);
  _CRTIMP wchar_t *Declaração _getws(wchar_t *_String);
  _CRTIMP Inteiro Declaração _putws(Imutável wchar_t *_Str);
  Inteiro Declaração fwprintf(FILE *_File, Imutável wchar_t *_Format, ...);
  Inteiro Declaração wprintf(Imutável wchar_t *_Format, ...);
  _CRTIMP Inteiro Declaração _scwprintf(Imutável wchar_t *_Format, ...);
  Inteiro Declaração vfwprintf(FILE *_File, Imutável wchar_t *_Format, va_list _ArgList);
  Inteiro Declaração vwprintf(Imutável wchar_t *_Format, va_list _ArgList);
  _CRTIMP Inteiro Declaração swprintf(wchar_t*, Imutável wchar_t*, ...);
  _CRTIMP Inteiro Declaração vswprintf(wchar_t*, Imutável wchar_t*, va_list);
  _CRTIMP Inteiro Declaração _swprintf_c(wchar_t *_DstBuf, size_t _SizeInWords, Imutável wchar_t *_Format, ...);
  _CRTIMP Inteiro Declaração _vswprintf_c(wchar_t *_DstBuf, size_t _SizeInWords, Imutável wchar_t *_Format, va_list _ArgList);
  _CRTIMP Inteiro Declaração _snwprintf(wchar_t *_Dest, size_t _Count, Imutável wchar_t *_Format, ...);
  _CRTIMP Inteiro Declaração _vsnwprintf(wchar_t *_Dest, size_t _Count, Imutável wchar_t *_Format, va_list _Args);
#SeNãoDefinido __NO_ISOCEXT  /* externs in libmingwex.a */
  Inteiro Declaração snwprintf (wchar_t* s, size_t n, Imutável wchar_t*  format, ...);
  __CRT_INLINE Inteiro Declaração vsnwprintf (wchar_t* s, size_t n, Imutável wchar_t* format, va_list arg) { Retorne _vsnwprintf(s, n, format, arg); }
  Inteiro Declaração vwscanf (Imutável wchar_t *, va_list);
  Inteiro Declaração vfwscanf (FILE *, Imutável wchar_t *, va_list);
  Inteiro Declaração vswscanf (Imutável wchar_t *, Imutável wchar_t *, va_list);
#FimSe
  _CRTIMP Inteiro Declaração _swprintf(wchar_t *_Dest, Imutável wchar_t *_Format, ...);
  _CRTIMP Inteiro Declaração _vswprintf(wchar_t *_Dest, Imutável wchar_t *_Format, va_list _Args);

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

  _CRTIMP wchar_t *Declaração _wtempnam(Imutável wchar_t *_Directory, Imutável wchar_t *_FilePrefix);
  _CRTIMP Inteiro Declaração _vscwprintf(Imutável wchar_t *_Format, va_list _ArgList);
  Inteiro Declaração fwscanf(FILE *_File, Imutável wchar_t *_Format, ...);
  Inteiro Declaração swscanf(Imutável wchar_t *_Src, Imutável wchar_t *_Format, ...);
  _CRTIMP Inteiro Declaração _snwscanf(Imutável wchar_t *_Src, size_t _MaxCount, Imutável wchar_t *_Format, ...);
  Inteiro Declaração wscanf(Imutável wchar_t *_Format, ...);
  _CRTIMP FILE *Declaração _wfdopen(Inteiro _FileHandle , Imutável wchar_t *_Mode);
  _CRTIMP FILE *Declaração _wfopen(Imutável wchar_t *_Filename, Imutável wchar_t *_Mode);
  _CRTIMP FILE *Declaração _wfreopen(Imutável wchar_t *_Filename, Imutável wchar_t *_Mode, FILE *_OldFile);
#SeNãoDefinido _CRT_WPERROR_DEFINED
#Defina _CRT_WPERROR_DEFINED
  _CRTIMP Vazio Declaração _wperror(Imutável wchar_t *_ErrMsg);
#FimSe
  _CRTIMP FILE *Declaração _wpopen(Imutável wchar_t *_Command, Imutável wchar_t *_Mode);
#Se !Definido(NO_OLDNAMES) && !Definido(wpopen)
#Defina wpopen  _wpopen
#FimSe
  _CRTIMP Inteiro Declaração _wremove(Imutável wchar_t *_Filename);
  _CRTIMP wchar_t *Declaração _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t Declaração _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t Declaração _fputwc_nolock(wchar_t _Ch, FILE *_File);
  _CRTIMP wint_t Declaração _ungetwc_nolock(wint_t _Ch, FILE *_File);

#Esqueça _CRT_GETPUTWCHAR_NOINLINE

#Se !Definido(__cplusplus) || Definido(_CRT_GETPUTWCHAR_NOINLINE)
#Defina getwchar() fgetwc(stdin)
#Defina putwchar(_c) fputwc((_c), stdout)
#Senão
  __CRT_INLINE wint_t Declaração getwchar() { Retorne (fgetwc(stdin)); }
  __CRT_INLINE wint_t Declaração putwchar(wchar_t _C) { Retorne (fputwc(_C, stdout)); }
#FimSe

#Defina getwc(_stm) fgetwc(_stm)
#Defina putwc(_c, _stm) fputwc(_c, _stm)
#Defina _putwc_nolock(_c, _stm) _fputwc_nolock(_c, _stm)
#Defina _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#Defina _WSTDIO_DEFINED
#FimSe

#Defina _STDIO_DEFINED
#FimSe

#Defina _fgetc_nolock(_stream) (--(_stream)->_cnt >= 0 ? 0xff & *(_stream)->_ptr++ : _filbuf(_stream))
#Defina _fputc_nolock(_c, _stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (Caractere)(_c)) : _flsbuf((_c), (_stream)))
#Defina _getc_nolock(_stream) _fgetc_nolock(_stream)
#Defina _putc_nolock(_c, _stream) _fputc_nolock(_c, _stream)
#Defina _getchar_nolock() _getc_nolock(stdin)
#Defina _putchar_nolock(_c) _putc_nolock((_c), stdout)
#Defina _getwchar_nolock() _getwc_nolock(stdin)
#Defina _putwchar_nolock(_c) _putwc_nolock((_c), stdout)

  _CRTIMP Vazio Declaração _lock_file(FILE *_File);
  _CRTIMP Vazio Declaração _unlock_file(FILE *_File);
  _CRTIMP Inteiro Declaração _fclose_nolock(FILE *_File);
  _CRTIMP Inteiro Declaração _fflush_nolock(FILE *_File);
  _CRTIMP size_t Declaração _fread_nolock(Vazio *_DstBuf, size_t _ElementSize, size_t _Count, FILE *_File);
  _CRTIMP Inteiro Declaração _fseek_nolock(FILE *_File, Longo _Offset, Inteiro _Origin);
  _CRTIMP Longo Declaração _ftell_nolock(FILE *_File);
  _CRTIMP Inteiro Declaração _fseeki64_nolock(FILE *_File, __int64 _Offset, Inteiro _Origin);
  _CRTIMP __int64 Declaração _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t Declaração _fwrite_nolock(Imutável Vazio *_DstBuf, size_t _Size, size_t _Count, FILE *_File);
  _CRTIMP Inteiro Declaração _ungetc_nolock(Inteiro _Ch, FILE *_File);

#Se !Definido(NO_OLDNAMES) || !Definido(_POSIX)
#Defina P_tmpdir _P_tmpdir
#Defina SYS_OPEN _SYS_OPEN

  Caractere *Declaração tempnam(Imutável Caractere *_Directory, Imutável Caractere *_FilePrefix);
  Inteiro Declaração fcloseall(Vazio);
  FILE *Declaração fdopen(Inteiro _FileHandle, Imutável Caractere *_Format);
  Inteiro Declaração fgetchar(Vazio);
  Inteiro Declaração fileno(FILE *_File);
  Inteiro Declaração flushall(Vazio);
  Inteiro Declaração fputchar(Inteiro _Ch);
  Inteiro Declaração getw(FILE *_File);
  Inteiro Declaração putw(Inteiro _Ch, FILE *_File);
  Inteiro Declaração rmtmp(Vazio);
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)

#Inclua <sec_api/stdio_s.h>

#FimSe
