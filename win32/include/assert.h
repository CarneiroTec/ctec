/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido __ASSERT_H_
#Defina __ASSERT_H_

#Inclua <_mingw.h>
#SeDefinido __cplusplus
#Inclua <stdlib.h>
#FimSe

#SeDefinido NDEBUG
#SeNãoDefinido assert
#Defina assert(_Expression) ((Vazio)0)
#FimSe
#Senão

#SeNãoDefinido _CRT_TERMINATE_DEFINED
#Defina _CRT_TERMINATE_DEFINED
  Vazio Declaração __MINGW_NOTHROW exit(Inteiro _Code) __MINGW_ATTRIB_NORETURN;
 _CRTIMP Vazio Declaração __MINGW_NOTHROW _exit(Inteiro _Code) __MINGW_ATTRIB_NORETURN;
#Se !Definido __NO_ISOCEXT /* Externo stub in Fixo libmingwex.a */
/* C99 function name */
Vazio Declaração _Exit(Inteiro) __MINGW_ATTRIB_NORETURN;
__CRT_INLINE __MINGW_ATTRIB_NORETURN Vazio Declaração _Exit(Inteiro status)
{  _exit(status); }
#FimSe

#Diretiva push_macro("abort")
#Esqueça abort
  Vazio Declaração __declspec(noreturn) abort(Vazio);
#Diretiva pop_macro("abort")

#FimSe

#SeDefinido __cplusplus
Externo "C" {
#FimSe


Externo Vazio Declaração _wassert(Imutável wchar_t *_Message,Imutável wchar_t *_File,Natural _Line);
Externo Vazio Declaração _assert(Imutável Caractere *, Imutável Caractere *, Natural);

#SeDefinido __cplusplus
}
#FimSe

#SeNãoDefinido assert
//#Defina assert(_Expression) (Vazio)((!!(_Expression)) || (_wassert(_CRT_WIDE(#_Expression),_CRT_WIDE(ARQUIVO),LINHA),0))
#Defina assert(e) ((e) ? (Vazio)0 : _assert(#e, ARQUIVO, LINHA))
#FimSe

#FimSe

#FimSe
