/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _WINDOWS_
#Defina _WINDOWS_

#SeNãoDefinido WIN32_LEAN_AND_MEAN
#Defina WIN32_LEAN_AND_MEAN 1
#FimSe

#SeNãoDefinido WINVER
#Defina WINVER 0x0502
#FimSe

#Inclua <_mingw.h>

#SeNãoDefinido _INC_WINDOWS
#Defina _INC_WINDOWS

#Se Definido(RC_INVOKED) && !Definido(NOWINRES)

#Inclua <winresrc.h>
#Senão

#SeDefinido RC_INVOKED
#Defina NOATOM
#Defina NOGDI
#Defina NOGDICAPMASKS
#Defina NOMETAFILE
#Defina NOMINMAX
#Defina NOMSG
#Defina NOOPENFILE
#Defina NORASTEROPS
#Defina NOSCROLL
#Defina NOSOUND
#Defina NOSYSMETRICS
#Defina NOTEXTMETRIC
#Defina NOWH
#Defina NOCOMM
#Defina NOKANJI
#Defina NOCRYPT
#Defina NOMCX
#FimSe

#Se !Definido(I_X86_) && !Definido(_IA64_) && !Definido(_AMD64_) && (Definido(_X86_) && !Definido(__x86_64))
#Defina I_X86_
#FimSe

#Se !Definido(I_X86_) && !Definido(_IA64_) && !Definido(_AMD64_) && Definido(__x86_64)
#Defina _AMD64_
#FimSe

#Se !Definido(I_X86_) && !(Definido(_X86_) && !Definido(__x86_64)) && !Definido(_AMD64_) && Definido(__ia64__)
#Se !Definido(_IA64_)
#Defina _IA64_
#FimSe
#FimSe

#SeNãoDefinido RC_INVOKED
#Inclua <excpt.h>
#Inclua <stdarg.h>
#FimSe

#Inclua <windef.h>
#Inclua <winbase.h>
#Inclua <wingdi.h>
#Inclua <winuser.h>
//gr #Inclua <winnls.h>
#Inclua <wincon.h>
#Inclua <winver.h>
#Inclua <winreg.h>
//gr #Inclua <winnetwk.h>

#SeNãoDefinido WIN32_LEAN_AND_MEAN
#Inclua <cderr.h>
#Inclua <dde.h>
#Inclua <ddeml.h>
#Inclua <dlgs.h>
#Inclua <lzexpand.h>
#Inclua <mmsystem.h>
#Inclua <nb30.h>
#Inclua <rpc.h>
#Inclua <shellapi.h>
#Inclua <winperf.h>
#Inclua <winsock.h>
#SeNãoDefinido NOCRYPT
#Inclua <wincrypt.h>
#Inclua <winefs.h>
#Inclua <winscard.h>
#FimSe

#SeNãoDefinido NOUSER
#SeNãoDefinido NOGDI
#Inclua <winspool.h>
#SeDefinido INC_OLE1
#Inclua <ole.h>
#Senão
#Inclua <ole2.h>
#FimSe
#Inclua <commdlg.h>
#FimSe
#FimSe
#FimSe

//gr #Inclua <stralign.h>

#SeDefinido INC_OLE2
#Inclua <ole2.h>
#FimSe

#SeNãoDefinido NOSERVICE
#Inclua <winsvc.h>
#FimSe

#SeNãoDefinido NOMCX
#Inclua <mcx.h>
#FimSe

#SeNãoDefinido NOIME
#Inclua <imm.h>
#FimSe

#FimSe
#FimSe
#FimSe
