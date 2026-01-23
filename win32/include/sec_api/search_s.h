/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_SEARCH_S
#Defina _INC_SEARCH_S

#Inclua <search.h>

#Se Definido(MINGW_HAS_SECURE_API)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  _CRTIMP Vazio *Declaração _lfind_s(Imutável Vazio *_Key,Imutável Vazio *_Base,Natural Inteiro *_NumOfElements,size_t _SizeOfElements,Inteiro (Declaração *_PtFuncCompare)(Vazio *,Imutável Vazio *,Imutável Vazio *),Vazio *_Context);
  _CRTIMP Vazio *Declaração _lsearch_s(Imutável Vazio *_Key,Vazio *_Base,Natural Inteiro *_NumOfElements,size_t _SizeOfElements,Inteiro (Declaração *_PtFuncCompare)(Vazio *,Imutável Vazio *,Imutável Vazio *),Vazio *_Context);

#SeDefinido __cplusplus
}
#FimSe

#FimSe
#FimSe
