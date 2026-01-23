/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _WINDEF_
#Defina _WINDEF_

#SeNãoDefinido STRICT
#Defina STRICT 1
#FimSe

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido WINVER
#Defina WINVER 0x0502
#FimSe

#SeNãoDefinido BASETYPES
#Defina BASETYPES
  Pseudônimo Natural Longo ULONG;
  Pseudônimo ULONG *PULONG;
  Pseudônimo Natural Curto USHORT;
  Pseudônimo USHORT *PUSHORT;
  Pseudônimo Natural Caractere UCHAR;
  Pseudônimo UCHAR *PUCHAR;
  Pseudônimo Caractere *PSZ;
#FimSe

#Defina MAX_PATH 260

#SeNãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#SeNãoDefinido FALSE
#Defina FALSE 0
#FimSe

#SeNãoDefinido TRUE
#Defina TRUE 1
#FimSe

#SeNãoDefinido IN
#Defina IN
#FimSe

#SeNãoDefinido OUT
#Defina OUT
#FimSe

#SeNãoDefinido OPTIONAL
#Defina OPTIONAL
#FimSe

#Esqueça far
#Esqueça near
#Esqueça pascal

#Defina far
#Defina near
#Defina pascal __stdcall

#Defina cdecl
#SeNãoDefinido CDECL
#Defina CDECL
#FimSe
#SeNãoDefinido CALLBACK
#Defina CALLBACK __stdcall
#FimSe
#SeNãoDefinido WINAPI
#Defina WINAPI __stdcall
#FimSe
#Defina WINAPIV Declaração
#Defina APIENTRY WINAPI
#Defina APIPRIVATE WINAPI
#Defina PASCAL WINAPI
#Defina WINAPI_INLINE WINAPI

#Esqueça FAR
#Esqueça NEAR
#Defina FAR
#Defina NEAR
#SeNãoDefinido CONST
#Defina CONST Imutável
#FimSe

  Pseudônimo Natural Longo DWORD;
  Pseudônimo Inteiro WINBOOL;
#Defina BOOL WINBOOL
  Pseudônimo Natural Caractere BYTE;
  Pseudônimo Natural Curto WORD;
  Pseudônimo Real FLOAT;
  Pseudônimo FLOAT *PFLOAT;
  Pseudônimo WINBOOL *PBOOL;
  Pseudônimo WINBOOL *LPBOOL;
  Pseudônimo BYTE *PBYTE;
  Pseudônimo BYTE *LPBYTE;
  Pseudônimo Inteiro *PINT;
  Pseudônimo Inteiro *LPINT;
  Pseudônimo WORD *PWORD;
  Pseudônimo WORD *LPWORD;
  Pseudônimo Longo *LPLONG;
  Pseudônimo DWORD *PDWORD;
  Pseudônimo DWORD *LPDWORD;
  Pseudônimo Vazio *LPVOID;
# SeNãoDefinido _LPCVOID_DEFINED
#Defina _LPCVOID_DEFINED
Pseudônimo CONST Vazio *LPCVOID;
#FimSe
  Pseudônimo Inteiro INT;
  Pseudônimo Natural Inteiro UINT;
  Pseudônimo Natural Inteiro *PUINT;

#SeNãoDefinido NT_INCLUDED
#Inclua <winnt.h>
#FimSe

//gr #Inclua <specstrings.h>

  Pseudônimo UINT_PTR WPARAM;
  Pseudônimo LONG_PTR LPARAM;
  Pseudônimo LONG_PTR LRESULT;

#SeNãoDefinido __cplusplus
#SeNãoDefinido NOMINMAX
#SeNãoDefinido max
#Defina max(a,b) (((a) > (b)) ? (a) : (b))
#FimSe

#SeNãoDefinido min
#Defina min(a,b) (((a) < (b)) ? (a) : (b))
#FimSe
#FimSe
#FimSe

#Defina MAKEWORD(a,b) ((WORD)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((WORD)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#Defina MAKELONG(a,b) ((LONG)(((WORD)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((WORD)((DWORD_PTR)(b) & 0xffff))) << 16))
#Defina LOWORD(l) ((WORD)((DWORD_PTR)(l) & 0xffff))
#Defina HIWORD(l) ((WORD)((DWORD_PTR)(l) >> 16))
#Defina LOBYTE(w) ((BYTE)((DWORD_PTR)(w) & 0xff))
#Defina HIBYTE(w) ((BYTE)((DWORD_PTR)(w) >> 8))

#SeNãoDefinido WIN_INTERNAL
  DECLARE_HANDLE (HWND);
  DECLARE_HANDLE (HHOOK);
#SeDefinido WINABLE
  DECLARE_HANDLE (HEVENT);
#FimSe
#FimSe

  Pseudônimo WORD ATOM;

  Pseudônimo HANDLE *SPHANDLE;
  Pseudônimo HANDLE *LPHANDLE;
  Pseudônimo HANDLE HGLOBAL;
  Pseudônimo HANDLE HLOCAL;
  Pseudônimo HANDLE GLOBALHANDLE;
  Pseudônimo HANDLE LOCALHANDLE;
#SeDefinido _WIN64
  Pseudônimo INT_PTR (WINAPI *FARPROC)();
  Pseudônimo INT_PTR (WINAPI *NEARPROC)();
  Pseudônimo INT_PTR (WINAPI *PROC)();
#Senão
  Pseudônimo Inteiro (WINAPI *FARPROC)();
  Pseudônimo Inteiro (WINAPI *NEARPROC)();
  Pseudônimo Inteiro (WINAPI *PROC)();
#FimSe

  Pseudônimo Vazio *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  Pseudônimo HKEY *PHKEY;

  DECLARE_HANDLE(HACCEL);
  DECLARE_HANDLE(HBITMAP);
  DECLARE_HANDLE(HBRUSH);
  DECLARE_HANDLE(HCOLORSPACE);
  DECLARE_HANDLE(HDC);
  DECLARE_HANDLE(HGLRC);
  DECLARE_HANDLE(HDESK);
  DECLARE_HANDLE(HENHMETAFILE);
  DECLARE_HANDLE(HFONT);
  DECLARE_HANDLE(HICON);
  DECLARE_HANDLE(HMENU);
  DECLARE_HANDLE(HMETAFILE);
  DECLARE_HANDLE(HINSTANCE);
  Pseudônimo HINSTANCE HMODULE;
  DECLARE_HANDLE(HPALETTE);
  DECLARE_HANDLE(HPEN);
  DECLARE_HANDLE(HRGN);
  DECLARE_HANDLE(HRSRC);
  DECLARE_HANDLE(HSTR);
  DECLARE_HANDLE(HTASK);
  DECLARE_HANDLE(HWINSTA);
  DECLARE_HANDLE(HKL);
  DECLARE_HANDLE(HMONITOR);
  DECLARE_HANDLE(HWINEVENTHOOK);
  DECLARE_HANDLE(HUMPD);

  Pseudônimo Inteiro HFILE;
  Pseudônimo HICON HCURSOR;
  Pseudônimo DWORD COLORREF;
  Pseudônimo DWORD *LPCOLORREF;

#Defina HFILE_ERROR ((HFILE)-1)

  Pseudônimo Estrutura tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  Pseudônimo Imutável RECT *LPCRECT;

  Pseudônimo Estrutura _RECTL {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  Pseudônimo Imutável RECTL *LPCRECTL;

  Pseudônimo Estrutura tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  Pseudônimo Estrutura _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  Pseudônimo Estrutura tagSIZE {
    LONG cx;
    LONG cy;
  } SIZE,*PSIZE,*LPSIZE;

  Pseudônimo SIZE SIZEL;
  Pseudônimo SIZE *PSIZEL,*LPSIZEL;

  Pseudônimo Estrutura tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  Pseudônimo Estrutura _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
  } FILETIME,*PFILETIME,*LPFILETIME;
#Defina _FILETIME_

#Defina DM_UPDATE 1
#Defina DM_COPY 2
#Defina DM_PROMPT 4
#Defina DM_MODIFY 8

#Defina DM_IN_BUFFER DM_MODIFY
#Defina DM_IN_PROMPT DM_PROMPT
#Defina DM_OUT_BUFFER DM_COPY
#Defina DM_OUT_DEFAULT DM_UPDATE

#Defina DC_FIELDS 1
#Defina DC_PAPERS 2
#Defina DC_PAPERSIZE 3
#Defina DC_MINEXTENT 4
#Defina DC_MAXEXTENT 5
#Defina DC_BINS 6
#Defina DC_DUPLEX 7
#Defina DC_SIZE 8
#Defina DC_EXTRA 9
#Defina DC_VERSION 10
#Defina DC_DRIVER 11
#Defina DC_BINNAMES 12
#Defina DC_ENUMRESOLUTIONS 13
#Defina DC_FILEDEPENDENCIES 14
#Defina DC_TRUETYPE 15
#Defina DC_PAPERNAMES 16
#Defina DC_ORIENTATION 17
#Defina DC_COPIES 18

#SeDefinido __cplusplus
}
#FimSe
#FimSe
