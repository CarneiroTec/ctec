/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_CONIO
#Defina _INC_CONIO

#Inclua <_mingw.h>

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  _CRTIMP Caractere *_cgets(Caractere *_Buffer);
  _CRTIMP Inteiro Declaração _cprintf(Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _cputs(Imutável Caractere *_Str);
  _CRTIMP Inteiro Declaração _cscanf(Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _cscanf_l(Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _getch(Vazio);
  _CRTIMP Inteiro Declaração _getche(Vazio);
  _CRTIMP Inteiro Declaração _vcprintf(Imutável Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _cprintf_p(Imutável Caractere *_Format,...);
  _CRTIMP Inteiro Declaração _vcprintf_p(Imutável Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _cprintf_l(Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcprintf_l(Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _cprintf_p_l(Imutável Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcprintf_p_l(Imutável Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _kbhit(Vazio);

#Se Definido(_X86_) && !Definido(__x86_64)
  Inteiro Declaração _inp(Natural Curto);
  Natural Curto Declaração _inpw(Natural Curto);
  Natural Longo Declaração _inpd(Natural Curto);
  Inteiro Declaração _outp(Natural Curto,Inteiro);
  Natural Curto Declaração _outpw(Natural Curto,Natural Curto);
  Natural Longo Declaração _outpd(Natural Curto,Natural Longo);
#FimSe

  _CRTIMP Inteiro Declaração _putch(Inteiro _Ch);
  _CRTIMP Inteiro Declaração _ungetch(Inteiro _Ch);
  _CRTIMP Inteiro Declaração _getch_nolock(Vazio);
  _CRTIMP Inteiro Declaração _getche_nolock(Vazio);
  _CRTIMP Inteiro Declaração _putch_nolock(Inteiro _Ch);
  _CRTIMP Inteiro Declaração _ungetch_nolock(Inteiro _Ch);

#SeNãoDefinido _WCONIO_DEFINED
#Defina _WCONIO_DEFINED

#SeNãoDefinido WEOF
#Defina WEOF (wint_t)(0xFFFF)
#FimSe

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t Declaração _getwch(Vazio);
  _CRTIMP wint_t Declaração _getwche(Vazio);
  _CRTIMP wint_t Declaração _putwch(wchar_t _WCh);
  _CRTIMP wint_t Declaração _ungetwch(wint_t _WCh);
  _CRTIMP Inteiro Declaração _cputws(Imutável wchar_t *_String);
  _CRTIMP Inteiro Declaração _cwprintf(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _cwscanf(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _cwscanf_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcwprintf(Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _cwprintf_p(Imutável wchar_t *_Format,...);
  _CRTIMP Inteiro Declaração _vcwprintf_p(Imutável wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro Declaração _cwprintf_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcwprintf_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro Declaração _cwprintf_p_l(Imutável wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro Declaração _vcwprintf_p_l(Imutável wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t Declaração _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t Declaração _getwch_nolock(Vazio);
  _CRTIMP wint_t Declaração _getwche_nolock(Vazio);
  _CRTIMP wint_t Declaração _ungetwch_nolock(wint_t _WCh);
#FimSe

#SeNãoDefinido	NO_OLDNAMES
  Caractere *Declaração cgets(Caractere *_Buffer);
  Inteiro Declaração cprintf(Imutável Caractere *_Format,...);
  Inteiro Declaração cputs(Imutável Caractere *_Str);
  Inteiro Declaração cscanf(Imutável Caractere *_Format,...);
  Inteiro Declaração getch(Vazio);
  Inteiro Declaração getche(Vazio);
  Inteiro Declaração kbhit(Vazio);
  Inteiro Declaração putch(Inteiro _Ch);
  Inteiro Declaração ungetch(Inteiro _Ch);

#Se (Definido(_X86_) && !Definido(__x86_64))
  Inteiro Declaração inp(Natural Curto);
  Natural Curto Declaração inpw(Natural Curto);
  Inteiro Declaração outp(Natural Curto,Inteiro);
  Natural Curto Declaração outpw(Natural Curto,Natural Curto);
#FimSe

  /* I/O intrin functions.  */
  __CRT_INLINE Natural Caractere __inbyte(Natural Curto Port)
  {
      Natural Caractere value;
      Montador __volatile__ ("inb %w1,%b0"
          : "=a" (value)
          : "Nd" (Port));
      Retorne value;
  }
  __CRT_INLINE Natural Curto __inword(Natural Curto Port)
  {
      Natural Curto value;
      Montador __volatile__ ("inw %w1,%w0"
          : "=a" (value)
          : "Nd" (Port));
      Retorne value;
  }
  __CRT_INLINE Natural Longo __indword(Natural Curto Port)
  {
      Natural Longo value;
      Montador __volatile__ ("inl %w1,%0"
          : "=a" (value)
          : "Nd" (Port));
      Retorne value;
  }
  __CRT_INLINE Vazio __outbyte(Natural Curto Port,Natural Caractere Data)
  {
      Montador __volatile__ ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE Vazio __outword(Natural Curto Port,Natural Curto Data)
  {
      Montador __volatile__ ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE Vazio __outdword(Natural Curto Port,Natural Longo Data)
  {
      Montador __volatile__ ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE Vazio __inbytestring(Natural Curto Port,Natural Caractere *Buffer,Natural Longo Count)
  {
	Montador __volatile__ (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }
  __CRT_INLINE Vazio __inwordstring(Natural Curto Port,Natural Curto *Buffer,Natural Longo Count)
  {
	Montador __volatile__ (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }
  __CRT_INLINE Vazio __indwordstring(Natural Curto Port,Natural Longo *Buffer,Natural Longo Count)
  {
	Montador __volatile__ (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }

  __CRT_INLINE Vazio __outbytestring(Natural Curto Port,Natural Caractere *Buffer,Natural Longo Count)
  {
      Montador __volatile__ (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }
  __CRT_INLINE Vazio __outwordstring(Natural Curto Port,Natural Curto *Buffer,Natural Longo Count)
  {
      Montador __volatile__ (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }
  __CRT_INLINE Vazio __outdwordstring(Natural Curto Port,Natural Longo *Buffer,Natural Longo Count)
  {
      Montador __volatile__ (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }

  __CRT_INLINE Natural __int64 __readcr0(Vazio)
  {
      Natural __int64 value;
      Montador __volatile__ (
          "mov %%cr0, %[value]" 
          : [value] "=q" (value));
      Retorne value;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to Faça this Para _WIN64 and _WIN32
     separately.  */
 
#SeDefinido _WIN64
  __CRT_INLINE Vazio __writecr0(Natural __int64 Data)
  {
   Montador __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE Natural __int64 __readcr2(Vazio)
  {
      Natural __int64 value;
      Montador __volatile__ (
          "mov %%cr2, %[value]" 
          : [value] "=q" (value));
      Retorne value;
  }

 __CRT_INLINE Vazio __writecr2(Natural __int64 Data)
 {
   Montador __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE Natural __int64 __readcr3(Vazio)
  {
      Natural __int64 value;
      Montador __volatile__ (
          "mov %%cr3, %[value]" 
          : [value] "=q" (value));
      Retorne value;
  }

 __CRT_INLINE Vazio __writecr3(Natural __int64 Data)
 {
   Montador __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE Natural __int64 __readcr4(Vazio)
  {
      Natural __int64 value;
      Montador __volatile__ (
          "mov %%cr4, %[value]" 
          : [value] "=q" (value));
      Retorne value;
  }

 __CRT_INLINE Vazio __writecr4(Natural __int64 Data)
 {
     Montador __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE Natural __int64 __readcr8(Vazio)
  {
      Natural __int64 value;
      Montador __volatile__ (
          "mov %%cr8, %[value]" 
          : [value] "=q" (value));
      Retorne value;
  }

 __CRT_INLINE Vazio __writecr8(Natural __int64 Data)
 {
   Montador __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#Exceto Definido(_WIN32)

  __CRT_INLINE Vazio __writecr0(Natural Data)
  {
    Montador __volatile__ (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE Natural Longo __readcr2(Vazio)
  {
      Natural Longo value;
      Montador __volatile__ (
          "mov %%cr2, %[value]" 
          : [value] "=q" (value));
      Retorne value;
  }

 __CRT_INLINE Vazio __writecr2(Natural Data)
 {
   Montador __volatile__ (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE Natural Longo __readcr3(Vazio)
  {
      Natural Longo value;
      Montador __volatile__ (
          "mov %%cr3, %[value]" 
          : [value] "=q" (value));
      Retorne value;
  }

 __CRT_INLINE Vazio __writecr3(Natural Data)
 {
   Montador __volatile__ (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE Natural Longo __readcr4(Vazio)
  {
      Natural Longo value;
      Montador __volatile__ (
          "mov %%cr4, %[value]" 
          : [value] "=q" (value));
      Retorne value;
  }

 __CRT_INLINE Vazio __writecr4(Natural Data)
 {
     Montador __volatile__ (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE Natural Longo __readcr8(Vazio)
 {
   Natural Longo value;      Montador __volatile__ (
          "mov %%cr8, %[value]" 
          : [value] "=q" (value));
     Retorne value;
 }

 __CRT_INLINE Vazio __writecr8(Natural Data)
 {
   Montador __volatile__ (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#FimSe

  __CRT_INLINE Natural __int64 __readmsr(Natural Longo msr)
  {
      Natural __int64 val1, val2;
       Montador __volatile__(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      Retorne val1 | (val2 << 32);
  }

 __CRT_INLINE Vazio __writemsr (Natural Longo msr, Natural __int64 Value)
 {
    Natural Longo val1 = Value, val2 = Value >> 32;
   Montador __volatile__ (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE Natural __int64 __rdtsc(Vazio)
  {
      Natural __int64 val1, val2;
      Montador __volatile__ (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      Retorne val1 | (val2 << 32);
  }

  __CRT_INLINE Vazio __cpuid(Inteiro CPUInfo[4], Inteiro InfoType)
  {
      Montador __volatile__ (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }

#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Inclua <sec_api/conio_s.h>

#FimSe
