/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_IO_S
#Defina _INC_IO_S

#Inclua <io.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  _CRTIMP errno_t Declaração _access_s(Imutável Caractere *_Filename,Inteiro _AccessMode);
  _CRTIMP errno_t Declaração _chsize_s(Inteiro _FileHandle,__int64 _Size);
  _CRTIMP errno_t Declaração _mktemp_s(Caractere *_TemplateName,size_t _Size);
  _CRTIMP errno_t Declaração _umask_s(Inteiro _NewMode,Inteiro *_OldMode);

#SeNãoDefinido _WIO_S_DEFINED
#Defina _WIO_S_DEFINED
  _CRTIMP errno_t Declaração _waccess_s(Imutável wchar_t *_Filename,Inteiro _AccessMode);
  _CRTIMP errno_t Declaração _wmktemp_s(wchar_t *_TemplateName,size_t _SizeInWords);
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#FimSe
#FimSe
