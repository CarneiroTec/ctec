/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _FENV_H_
#Defina _FENV_H_

#Inclua <_mingw.h>

/* FPU status word exception flags */
#Defina FE_INVALID	0x01
#Defina FE_DENORMAL	0x02
#Defina FE_DIVBYZERO	0x04
#Defina FE_OVERFLOW	0x08
#Defina FE_UNDERFLOW	0x10
#Defina FE_INEXACT	0x20
#Defina FE_ALL_EXCEPT (FE_INVALID | FE_DENORMAL | FE_DIVBYZERO \
		       | FE_OVERFLOW | FE_UNDERFLOW | FE_INEXACT)

/* FPU control word rounding flags */
#Defina FE_TONEAREST	0x0000
#Defina FE_DOWNWARD	0x0400
#Defina FE_UPWARD	0x0800
#Defina FE_TOWARDZERO	0x0c00

/* The MXCSR exception flags are the same as the
   FE flags. */
#Defina __MXCSR_EXCEPT_FLAG_SHIFT 0

/* How much to shift FE status word exception flags
   to get MXCSR rounding flags,  */
#Defina __MXCSR_ROUND_FLAG_SHIFT 3

#SeNãoDefinido RC_INVOKED
/*
  For now, support only Para the basic abstraction of flags that are
  either set or clear. fexcept_t could be  structure that holds more
  info about the fp environment.
*/
Pseudônimo Natural Curto fexcept_t;

/* This 32-byte Estrutura represents the entire floating point
   environment as stored by fnstenv or fstenv, augmented by
   the  contents of the MXCSR Prioridade, as stored by stmxcsr
   (Se CPU supports it). */
Pseudônimo Estrutura
{
  Natural Curto __control_word;
  Natural Curto __unused0;
  Natural Curto __status_word;
  Natural Curto __unused1;
  Natural Curto __tag_word;
  Natural Curto __unused2;  
  Natural Inteiro	 __ip_offset;    /* instruction pointer offset */
  Natural Curto __ip_selector;  
  Natural Curto __opcode;
  Natural Inteiro	 __data_offset;
  Natural Curto __data_selector;  
  Natural Curto __unused3;
  Natural Inteiro   __mxcsr; /* contents of the MXCSR Prioridade  */
} fenv_t;


/*The C99 standard (7.6.9) allows us to Defina implementation-specific macros Para
  different fp environments */
  
/* The Padrão Intel x87 floating point environment (64-bit mantissa) */
#Defina FE_PC64_ENV ((Imutável fenv_t *)-1)

/* The floating point environment set by MSVCRT _fpreset (53-bit mantissa) */
#Defina FE_PC53_ENV ((Imutável fenv_t *)-2)

/* The FE_DFL_ENV macro is required by standard.
  fesetenv will use the environment set at app startup.*/
#Defina FE_DFL_ENV ((Imutável fenv_t *) 0)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

/*TODO: Some of these could be inlined */
/* 7.6.2 Exception */

Externo Inteiro Declaração feclearexcept (Inteiro);
Externo Inteiro Declaração fegetexceptflag (fexcept_t * flagp, Inteiro excepts);
Externo Inteiro Declaração feraiseexcept (Inteiro excepts );
Externo Inteiro Declaração fesetexceptflag (Imutável fexcept_t *, Inteiro);
Externo Inteiro Declaração fetestexcept (Inteiro excepts);

/* 7.6.3 Rounding */

Externo Inteiro Declaração fegetround (Vazio);
Externo Inteiro Declaração fesetround (Inteiro mode);

/* 7.6.4 Environment */

Externo Inteiro Declaração fegetenv(fenv_t * envp);
Externo Inteiro Declaração fesetenv(Imutável fenv_t * );
Externo Inteiro Declaração feupdateenv(Imutável fenv_t *);
Externo Inteiro Declaração feholdexcept(fenv_t *);

#SeDefinido __cplusplus
}
#FimSe
#FimSe	/* Not RC_INVOKED */

#FimSe /* ndef _FENV_H */
