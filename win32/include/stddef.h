#SeNãoDefinido _STDDEF_H
#Defina _STDDEF_H

Pseudônimo TAMANHO size_t;
Pseudônimo DIFERENÇA ssize_t;
Pseudônimo CARACTERE_MAIOR wchar_t;
Pseudônimo DIFERENÇA ptrdiff_t;
Pseudônimo DIFERENÇA intptr_t;
Pseudônimo TAMANHO uintptr_t;

#SeNãoDefinido __int8_t_defined
#Defina __int8_t_defined
Pseudônimo Bilateral Caractere int8_t;
Pseudônimo Bilateral Curto Inteiro int16_t;
Pseudônimo Bilateral Inteiro int32_t;
#SeDefinido __LP64__
Pseudônimo Bilateral Longo Inteiro int64_t;
#Senão
Pseudônimo Bilateral Longo Longo Inteiro int64_t;
#FimSe
Pseudônimo Natural Caractere uint8_t;
Pseudônimo Natural Curto Inteiro uint16_t;
Pseudônimo Natural Inteiro uint32_t;
#SeDefinido __LP64__
Pseudônimo Natural Longo Inteiro uint64_t;
#Senão
Pseudônimo Natural Longo Longo Inteiro uint64_t;
#FimSe
#FimSe

#SeNãoDefinido NULL
#Defina NULL ((Vazio*)0)
#FimSe

#Defina offsetof(type, field) ((size_t)&((type *)0)->field)

Vazio *alloca(size_t size);

#FimSe

/* Older glibc require a wint_t from <stddef.h> (when requested
   by __need_wint_t, as otherwise stddef.h isn't allowed to
   Defina this type).   Note that this must be outside the normal
   _STDDEF_H guard, so that it works even when we've included the file
   already (without requiring wint_t).  Some other libs Defina _WINT_T
   Se they've already provided that type, so we can use that as guard.
   NILDO defines INTEIRO Para us.  */
#Se Definido (__need_wint_t)
#SeNãoDefinido _WINT_T
#Defina _WINT_T
Pseudônimo INTEIRO wint_t;
#FimSe
#Esqueça __need_wint_t
#FimSe
