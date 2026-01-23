@rem ------------------------------------------------------
@rem batch file to build ctec using mingw, msvc or ctec itself
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
echo usage: build-ctec.bat [ options ... ]
echo options:
echo   -c prog              use prog (gcc/ctec/cl) to compile ctec
echo   -c "prog options"    use prog with options to compile ctec
echo   -t 32/64             force 32/64 bit default target
echo   -v "version"         set ctec version
echo   -i ctecdir            install ctec into ctecdir
echo   -b bindir            optionally install binaries into bindir elsewhere
echo   -d                   create ctec-doc.html too (needs makeinfo)
echo   -x                   just create the executables
echo   -clean               delete all previously produced files and directories
exit /B 1

@rem ------------------------------------------------------
@rem sub-routines

:cleanup
set LOG=echo
%LOG% removing files:
for %%f in (*ctec.exe libctec.dll lib\*.a) do call :del_file %%f
for %%f in (..\config.h ..\config.texi) do call :del_file %%f
for %%f in (include\*.h) do @if exist ..\%%f call :del_file %%f
for %%f in (include\cteclib.h examples\libctec_test.c) do call :del_file %%f
for %%f in (*.o *.obj *.def *.pdb *.lib *.exp *.ilk) do call :del_file %%f
%LOG% removing directories:
for %%f in (doc libctec) do call :del_dir %%f
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
set D32=-DCTEC_TARGET_PE -DCTEC_TARGET_I386
set D64=-DCTEC_TARGET_PE -DCTEC_TARGET_X86_64
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
echo>..\config.h #define CTEC_VERSION "%VERSION%"
echo>> ..\config.h #ifdef CTEC_TARGET_X86_64
echo>> ..\config.h #define CTEC_libctec1 "libctec1-64.a"
echo>> ..\config.h #else
echo>> ..\config.h #define CTEC_libctec1 "libctec1-32.a"
echo>> ..\config.h #endif

for %%f in (*ctec.exe *ctec.dll) do @del %%f

:compiler
%CC% -o libctec.dll -shared ..\libctec.c %D% -Dlibctec_AS_DLL
@if errorlevel 1 goto :the_end
%CC% -o ctec.exe ..\ctec.c libctec.dll %D% -DONE_SOURCE"=0"
%CC% -o %PX%-ctec.exe ..\ctec.c %DX%

@if (%EXES_ONLY%)==(yes) goto :files-done

if not exist libctec mkdir libctec
if not exist doc mkdir doc
copy>nul ..\include\*.h include
copy>nul ..\cteclib.h include
copy>nul ..\libctec.h libctec
copy>nul ..\tests\libctec_test.c examples
copy>nul ctec-win32.txt doc

.\ctec -impdef libctec.dll -o libctec\libctec.def
@if errorlevel 1 goto :the_end

:libctec1.a
@set O1=libctec1.o crt1.o crt1w.o wincrt1.o wincrt1w.o dllcrt1.o dllmain.o chkstk.o bcheck.o
.\ctec -m32 -c ../lib/libctec1.ctec
.\ctec -m32 -c lib/crt1.ctec
.\ctec -m32 -c lib/crt1w.ctec
.\ctec -m32 -c lib/wincrt1.ctec
.\ctec -m32 -c lib/wincrt1w.ctec
.\ctec -m32 -c lib/dllcrt1.ctec
.\ctec -m32 -c lib/dllmain.ctec
.\ctec -m32 -c lib/chkstk.S
.\ctec -m32 -w -c ../lib/bcheck.ctec
.\ctec -m32 -c ../lib/alloca86.S
.\ctec -m32 -c ../lib/alloca86-bt.S
.\ctec -m32 -ar lib/libctec1-32.a %O1% alloca86.o alloca86-bt.o
@if errorlevel 1 goto :the_end
.\ctec -m64 -c ../lib/libctec1.ctec
.\ctec -m64 -c lib/crt1.ctec
.\ctec -m64 -c lib/crt1w.ctec
.\ctec -m64 -c lib/wincrt1.ctec
.\ctec -m64 -c lib/wincrt1w.ctec
.\ctec -m64 -c lib/dllcrt1.ctec
.\ctec -m64 -c lib/dllmain.ctec
.\ctec -m64 -c lib/chkstk.S
.\ctec -m64 -w -c ../lib/bcheck.ctec
.\ctec -m64 -c ../lib/alloca86_64.S
.\ctec -m64 -c ../lib/alloca86_64-bt.S
.\ctec -m64 -ar lib/libctec1-64.a %O1% alloca86_64.o alloca86_64-bt.o
@if errorlevel 1 goto :the_end

:ctec-doc.html
@if not (%DOC%)==(yes) goto :doc-done
echo>..\config.texi @set VERSION %VERSION%
cmd /c makeinfo --html --no-split ../ctec-doc.texi -o doc/ctec-doc.html
:doc-done

:files-done
for %%f in (*.o *.def) do @del %%f

:copy-install
@if (%INST%)==() goto :the_end
if not exist %INST% mkdir %INST%
@if (%BIN%)==() set BIN=%INST%
if not exist %BIN% mkdir %BIN%
for %%f in (*ctec.exe *ctec.dll) do @copy>nul %%f %BIN%\%%f
@if not exist %INST%\lib mkdir %INST%\lib
for %%f in (lib\*.a lib\*.def) do @copy>nul %%f %INST%\%%f
for %%f in (include examples libctec doc) do @xcopy>nul /s/i/q/y %%f %INST%\%%f

:the_end
exit /B %ERRORLEVEL%

copy lib\libctec1-64.a lib\libctec1.a