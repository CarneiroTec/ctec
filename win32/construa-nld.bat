@rem ------------------------------------------------------
@rem batch file to build nld using mingw, msvc or nld itself
@rem ------------------------------------------------------

@echo off
setlocal
if (%1)==(-clean) goto :cleanup
set CC=gcc
set /p VERSION= < ..\VERSION
set INST=
set BIN=
set DOC=no
set EXES_ONLY=no
goto :a0
:a2
shift
:a3
shift
:a0
if not (%1)==(-c) goto :a1
set CC=%~2
if (%2)==(cl) set CC=@call :cl
goto :a2
:a1
if (%1)==(-t) set T=%2&& goto :a2
if (%1)==(-v) set VERSION=%~2&& goto :a2
if (%1)==(-i) set INST=%2&& goto :a2
if (%1)==(-b) set BIN=%2&& goto :a2
if (%1)==(-d) set DOC=yes&& goto :a3
if (%1)==(-x) set EXES_ONLY=yes&& goto :a3
if (%1)==() goto :p1
:usage
echo usage: build-nld.bat [ options ... ]
echo options:
echo   -c prog              use prog (gcc/nld/cl) to compile nld
echo   -c "prog options"    use prog with options to compile nld
echo   -t 32/64             force 32/64 bit default target
echo   -v "version"         set nld version
echo   -i nlddir            install nld into nlddir
echo   -b bindir            optionally install binaries into bindir elsewhere
echo   -d                   create nld-doc.html too (needs makeinfo)
echo   -x                   just create the executables
echo   -clean               delete all previously produced files and directories
exit /B 1

@rem ------------------------------------------------------
@rem sub-routines

:cleanup
set LOG=echo
%LOG% removing files:
for %%f in (*nld.exe libnld.dll lib\*.a) do call :del_file %%f
for %%f in (..\config.h ..\config.texi) do call :del_file %%f
for %%f in (include\*.h) do @if exist ..\%%f call :del_file %%f
for %%f in (include\nldlib.h examples\libnld_test.c) do call :del_file %%f
for %%f in (*.o *.obj *.def *.pdb *.lib *.exp *.ilk) do call :del_file %%f
%LOG% removing directories:
for %%f in (doc libnld) do call :del_dir %%f
%LOG% done.
exit /B 0
:del_file
if exist %1 del %1 && %LOG%   %1
exit /B 0
:del_dir
if exist %1 rmdir /Q/S %1 && %LOG%   %1
exit /B 0

:cl
@echo off
set CMD=cl
:c0
set ARG=%1
set ARG=%ARG:.dll=.lib%
if (%1)==(-shared) set ARG=-LD
if (%1)==(-o) shift && set ARG=-Fe%2
set CMD=%CMD% %ARG%
shift
if not (%1)==() goto :c0
echo on
%CMD% -O1 -W2 -Zi -MT -GS- -nologo -link -opt:ref,icf
@exit /B %ERRORLEVEL%

@rem ------------------------------------------------------
@rem main program

:p1
if not %T%_==_ goto :p2
set T=32
if %PROCESSOR_ARCHITECTURE%_==AMD64_ set T=64
if %PROCESSOR_ARCHITEW6432%_==AMD64_ set T=64
:p2
if "%CC:~-3%"=="gcc" set CC=%CC% -Os -s -static
set D32=-DNILDO_TARGET_PE -DNILDO_TARGET_I386
set D64=-DNILDO_TARGET_PE -DNILDO_TARGET_X86_64
set P32=i386-win32
set P64=x86_64-win32
if %T%==64 goto :t64
set D=%D32%
set DX=%D64%
set PX=%P64%
goto :p3
:t64
set D=%D64%
set DX=%D32%
set PX=%P32%
goto :p3

:p3
@echo on

:config.h
echo>..\config.h #define NILDO_VERSION "%VERSION%"
echo>> ..\config.h #ifdef NILDO_TARGET_X86_64
echo>> ..\config.h #define NILDO_libnld1 "libnld1-64.a"
echo>> ..\config.h #else
echo>> ..\config.h #define NILDO_libnld1 "libnld1-32.a"
echo>> ..\config.h #endif

for %%f in (*nld.exe *nld.dll) do @del %%f

:compiler
%CC% -o libnld.dll -shared ..\libnld.c %D% -Dlibnld_AS_DLL
@if errorlevel 1 goto :the_end
%CC% -o nld.exe ..\nld.c libnld.dll %D% -DONE_SOURCE"=0"
%CC% -o %PX%-nld.exe ..\nld.c %DX%

@if (%EXES_ONLY%)==(yes) goto :files-done

if not exist libnld mkdir libnld
if not exist doc mkdir doc
copy>nul ..\include\*.h include
copy>nul ..\nldlib.h include
copy>nul ..\libnld.h libnld
copy>nul ..\tests\libnld_test.c examples
copy>nul nld-win32.txt doc

.\nld -impdef libnld.dll -o libnld\libnld.def
@if errorlevel 1 goto :the_end

:libnld1.a
@set O1=libnld1.o crt1.o crt1w.o wincrt1.o wincrt1w.o dllcrt1.o dllmain.o chkstk.o bcheck.o
.\nld -m32 -c ../lib/libnld1.nld
.\nld -m32 -c lib/crt1.nld
.\nld -m32 -c lib/crt1w.nld
.\nld -m32 -c lib/wincrt1.nld
.\nld -m32 -c lib/wincrt1w.nld
.\nld -m32 -c lib/dllcrt1.nld
.\nld -m32 -c lib/dllmain.nld
.\nld -m32 -c lib/chkstk.S
.\nld -m32 -w -c ../lib/bcheck.nld
.\nld -m32 -c ../lib/alloca86.S
.\nld -m32 -c ../lib/alloca86-bt.S
.\nld -m32 -ar lib/libnld1-32.a %O1% alloca86.o alloca86-bt.o
@if errorlevel 1 goto :the_end
.\nld -m64 -c ../lib/libnld1.nld
.\nld -m64 -c lib/crt1.nld
.\nld -m64 -c lib/crt1w.nld
.\nld -m64 -c lib/wincrt1.nld
.\nld -m64 -c lib/wincrt1w.nld
.\nld -m64 -c lib/dllcrt1.nld
.\nld -m64 -c lib/dllmain.nld
.\nld -m64 -c lib/chkstk.S
.\nld -m64 -w -c ../lib/bcheck.nld
.\nld -m64 -c ../lib/alloca86_64.S
.\nld -m64 -c ../lib/alloca86_64-bt.S
.\nld -m64 -ar lib/libnld1-64.a %O1% alloca86_64.o alloca86_64-bt.o
@if errorlevel 1 goto :the_end

:nld-doc.html
@if not (%DOC%)==(yes) goto :doc-done
echo>..\config.texi @set VERSION %VERSION%
cmd /c makeinfo --html --no-split ../nld-doc.texi -o doc/nld-doc.html
:doc-done

:files-done
for %%f in (*.o *.def) do @del %%f

:copy-install
@if (%INST%)==() goto :the_end
if not exist %INST% mkdir %INST%
@if (%BIN%)==() set BIN=%INST%
if not exist %BIN% mkdir %BIN%
for %%f in (*nld.exe *nld.dll) do @copy>nul %%f %BIN%\%%f
@if not exist %INST%\lib mkdir %INST%\lib
for %%f in (lib\*.a lib\*.def) do @copy>nul %%f %INST%\%%f
for %%f in (include examples libnld doc) do @xcopy>nul /s/i/q/y %%f %INST%\%%f

:the_end
exit /B %ERRORLEVEL%

copy lib\libnld1-64.a lib\libnld1.a