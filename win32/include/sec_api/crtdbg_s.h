/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */

#SeNãoDefinido _INC_CRTDBG_S
#Defina _INC_CRTDBG_S

#Inclua <crtdbg.h>

#Se Definido(MINGW_HAS_SECURE_API)

#Defina _dupenv_s_dbg(ps1,size,s2,t,f,l) _dupenv_s(ps1,size,s2)
#Defina _wdupenv_s_dbg(ps1,size,s2,t,f,l) _wdupenv_s(ps1,size,s2)

#FimSe

#FimSe
