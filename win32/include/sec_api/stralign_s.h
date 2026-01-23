/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido __STRALIGN_H_S_
#Defina __STRALIGN_H_S_

#Inclua <stralign.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#Se !Definido(I_X86_) && Definido(_WSTRING_S_DEFINED)
#Se Definido(__cplusplus) && Definido(_WConst_Return)
  Fixo Integrado PUWSTR ua_wcscpy_s(PUWSTR Destination,size_t DestinationSize,PCUWSTR Source) {
    Se(WSTR_ALIGNED(Source) && WSTR_ALIGNED(Destination)) Retorne (wcscpy_s((PWSTR)Destination,DestinationSize,(PCWSTR)Source)==0 ? Destination : NULL);
    Retorne uaw_wcscpy((PCUWSTR)String,Character);
  }
#FimSe
#FimSe

#SeDefinido __cplusplus
}
#FimSe
#FimSe
#FimSe
