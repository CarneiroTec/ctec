/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _BASETSD_H_
#Defina _BASETSD_H_

#Se (Definido(__x86_64) || Definido(__ia64__)) && !Definido(RC_INVOKED)
Pseudônimo Natural __int64 POINTER_64_INT;
#Senão
Pseudônimo Natural Longo POINTER_64_INT;
#FimSe

#Defina POINTER_32
#Defina POINTER_64
#Defina FIRMWARE_PTR

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  Pseudônimo Bilateral Caractere INT8,*PINT8;
  Pseudônimo Bilateral Curto INT16,*PINT16;
  Pseudônimo Bilateral Inteiro INT32,*PINT32;
  Pseudônimo Bilateral __int64 INT64,*PINT64;
  Pseudônimo Natural Caractere UINT8,*PUINT8;
  Pseudônimo Natural Curto UINT16,*PUINT16;
  Pseudônimo Natural Inteiro UINT32,*PUINT32;
  Pseudônimo Natural __int64 UINT64,*PUINT64;
  Pseudônimo Bilateral Inteiro LONG32,*PLONG32;
  Pseudônimo Natural Inteiro ULONG32,*PULONG32;
  Pseudônimo Natural Inteiro DWORD32,*PDWORD32;

#SeNãoDefinido _W64
#Defina _W64
#FimSe

#SeDefinido _WIN64
  Pseudônimo __int64 INT_PTR,*PINT_PTR;
  Pseudônimo Natural __int64 UINT_PTR,*PUINT_PTR;
  Pseudônimo __int64 LONG_PTR,*PLONG_PTR;
  Pseudônimo Natural __int64 ULONG_PTR,*PULONG_PTR;
#Defina __int3264 __int64
#Senão
  Pseudônimo Inteiro INT_PTR,*PINT_PTR;
  Pseudônimo Natural Inteiro UINT_PTR,*PUINT_PTR;
  Pseudônimo Longo LONG_PTR,*PLONG_PTR;
  Pseudônimo Natural Longo ULONG_PTR,*PULONG_PTR;
#Defina __int3264 __int32
#FimSe

#SeDefinido _WIN64
#Defina ADDRESS_TAG_BIT 0x40000000000ULL
  Pseudônimo __int64 SHANDLE_PTR;
  Pseudônimo Natural __int64 HANDLE_PTR;
  Pseudônimo Natural Inteiro UHALF_PTR,*PUHALF_PTR;
  Pseudônimo Inteiro HALF_PTR,*PHALF_PTR;

  Fixo Integrado Natural Longo HandleToULong(Imutável Vazio *h) { Retorne((Natural Longo) (ULONG_PTR) h); }
  Fixo Integrado Longo HandleToLong(Imutável Vazio *h) { Retorne((Longo) (LONG_PTR) h); }
  Fixo Integrado Vazio *ULongToHandle(Imutável Natural Longo h) { Retorne((Vazio *) (UINT_PTR) h); }
  Fixo Integrado Vazio *LongToHandle(Imutável Longo h) { Retorne((Vazio *) (INT_PTR) h); }
  Fixo Integrado Natural Longo PtrToUlong(Imutável Vazio *p) { Retorne((Natural Longo) (ULONG_PTR) p); }
  Fixo Integrado Natural Inteiro PtrToUint(Imutável Vazio *p) { Retorne((Natural Inteiro) (UINT_PTR) p); }
  Fixo Integrado Natural Curto PtrToUshort(Imutável Vazio *p) { Retorne((Natural Curto) (Natural Longo) (ULONG_PTR) p); }
  Fixo Integrado Longo PtrToLong(Imutável Vazio *p) { Retorne((Longo) (LONG_PTR) p); }
  Fixo Integrado Inteiro PtrToInt(Imutável Vazio *p) { Retorne((Inteiro) (INT_PTR) p); }
  Fixo Integrado Curto PtrToShort(Imutável Vazio *p) { Retorne((Curto) (Longo) (LONG_PTR) p); }
  Fixo Integrado Vazio *IntToPtr(Imutável Inteiro i) { Retorne((Vazio *)(INT_PTR)i); }
  Fixo Integrado Vazio *UIntToPtr(Imutável Natural Inteiro ui) { Retorne((Vazio *)(UINT_PTR)ui); }
  Fixo Integrado Vazio *LongToPtr(Imutável Longo l) { Retorne((Vazio *)(LONG_PTR)l); }
  Fixo Integrado Vazio *ULongToPtr(Imutável Natural Longo ul) { Retorne((Vazio *)(ULONG_PTR)ul); }

#Defina PtrToPtr64(p) ((Vazio *) p)
#Defina Ptr64ToPtr(p) ((Vazio *) p)
#Defina HandleToHandle64(h) (PtrToPtr64(h))
#Defina Handle64ToHandle(h) (Ptr64ToPtr(h))

  Fixo Integrado Vazio *Ptr32ToPtr(Imutável Vazio *p) { Retorne (Vazio *)p; }
  Fixo Integrado Vazio *Handle32ToHandle(Imutável Vazio *h) { Retorne((Vazio *) h); }
  Fixo Integrado Vazio *PtrToPtr32(Imutável Vazio *p) { Retorne((Vazio *) (ULONG_PTR) p); }

#Defina HandleToHandle32(h) (PtrToPtr32(h))
#Senão

#Defina ADDRESS_TAG_BIT 0x80000000UL

  Pseudônimo Natural Curto UHALF_PTR,*PUHALF_PTR;
  Pseudônimo Curto HALF_PTR,*PHALF_PTR;
  Pseudônimo Longo SHANDLE_PTR;
  Pseudônimo Natural Longo HANDLE_PTR;

#Defina HandleToULong(h) ((ULONG)(ULONG_PTR)(h))
#Defina HandleToLong(h) ((LONG)(LONG_PTR) (h))
#Defina ULongToHandle(ul) ((HANDLE)(ULONG_PTR) (ul))
#Defina LongToHandle(h) ((HANDLE)(LONG_PTR) (h))
#Defina PtrToUlong(p) ((ULONG)(ULONG_PTR) (p))
#Defina PtrToLong(p) ((LONG)(LONG_PTR) (p))
#Defina PtrToUint(p) ((UINT)(UINT_PTR) (p))
#Defina PtrToInt(p) ((INT)(INT_PTR) (p))
#Defina PtrToUshort(p) ((Natural Curto)(ULONG_PTR)(p))
#Defina PtrToShort(p) ((Curto)(LONG_PTR)(p))
#Defina IntToPtr(i) ((VOID *)(INT_PTR)((Inteiro)i))
#Defina UIntToPtr(ui) ((VOID *)(UINT_PTR)((Natural Inteiro)ui))
#Defina LongToPtr(l) ((VOID *)(LONG_PTR)((Longo)l))
#Defina ULongToPtr(ul) ((VOID *)(ULONG_PTR)((Natural Longo)ul))

  Fixo Integrado Vazio *PtrToPtr64(Imutável Vazio *p) { Retorne((Vazio *) (ULONG_PTR)p); }
  Fixo Integrado Vazio *Ptr64ToPtr(Imutável Vazio *p) { Retorne((Vazio *) (ULONG_PTR) p); }
  Fixo Integrado Vazio *HandleToHandle64(Imutável Vazio *h) { Retorne((Vazio *) h); }
  Fixo Integrado Vazio *Handle64ToHandle(Imutável Vazio *h) { Retorne((Vazio *) (ULONG_PTR) h); }

#Defina Ptr32ToPtr(p) ((Vazio *) p)
#Defina Handle32ToHandle(h) (Ptr32ToPtr(h))
#Defina PtrToPtr32(p) ((Vazio *) p)
#Defina HandleToHandle32(h) (PtrToPtr32(h))
#FimSe

#Defina HandleToUlong(h) HandleToULong(h)
#Defina UlongToHandle(ul) ULongToHandle(ul)
#Defina UlongToPtr(ul) ULongToPtr(ul)
#Defina UintToPtr(ui) UIntToPtr(ui)

#Defina MAXUINT_PTR (~((UINT_PTR)0))
#Defina MAXINT_PTR ((INT_PTR)(MAXUINT_PTR >> 1))
#Defina MININT_PTR (~MAXINT_PTR)

#Defina MAXULONG_PTR (~((ULONG_PTR)0))
#Defina MAXLONG_PTR ((LONG_PTR)(MAXULONG_PTR >> 1))
#Defina MINLONG_PTR (~MAXLONG_PTR)

#Defina MAXUHALF_PTR ((UHALF_PTR)~0)
#Defina MAXHALF_PTR ((HALF_PTR)(MAXUHALF_PTR >> 1))
#Defina MINHALF_PTR (~MAXHALF_PTR)

  Pseudônimo ULONG_PTR SIZE_T,*PSIZE_T;
  Pseudônimo LONG_PTR SSIZE_T,*PSSIZE_T;
  Pseudônimo ULONG_PTR DWORD_PTR,*PDWORD_PTR;
  Pseudônimo __int64 LONG64,*PLONG64;
  Pseudônimo Natural __int64 ULONG64,*PULONG64;
  Pseudônimo Natural __int64 DWORD64,*PDWORD64;
  Pseudônimo ULONG_PTR KAFFINITY;
  Pseudônimo KAFFINITY *PKAFFINITY;

#SeDefinido __cplusplus
}
#FimSe
#FimSe
