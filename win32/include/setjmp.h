/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_SETJMP
#Defina _INC_SETJMP

#Inclua <_mingw.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#Se (Definido(_X86_) && !Definido(__x86_64))

#Defina _JBLEN 16
#Defina _JBTYPE Inteiro

  Pseudônimo Estrutura __JUMP_BUFFER {
    Natural Longo Ebp;
    Natural Longo Ebx;
    Natural Longo Edi;
    Natural Longo Esi;
    Natural Longo Esp;
    Natural Longo Eip;
    Natural Longo Registration;
    Natural Longo TryLevel;
    Natural Longo Cookie;
    Natural Longo UnwindFunc;
    Natural Longo UnwindData[6];
  } _JUMP_BUFFER;
#Exceto Definido(__ia64__)
  Pseudônimo _CRT_ALIGN(16) Estrutura _SETJMP_FLOAT128 {
    __int64 LowPart;
    __int64 HighPart;
  } SETJMP_FLOAT128;

#Defina _JBLEN 33
  Pseudônimo SETJMP_FLOAT128 _JBTYPE;

  Pseudônimo Estrutura __JUMP_BUFFER {

    Natural Longo iAReserved[6];

    Natural Longo Registration;
    Natural Longo TryLevel;
    Natural Longo Cookie;
    Natural Longo UnwindFunc;

    Natural Longo UnwindData[6];

    SETJMP_FLOAT128 FltS0;
    SETJMP_FLOAT128 FltS1;
    SETJMP_FLOAT128 FltS2;
    SETJMP_FLOAT128 FltS3;
    SETJMP_FLOAT128 FltS4;
    SETJMP_FLOAT128 FltS5;
    SETJMP_FLOAT128 FltS6;
    SETJMP_FLOAT128 FltS7;
    SETJMP_FLOAT128 FltS8;
    SETJMP_FLOAT128 FltS9;
    SETJMP_FLOAT128 FltS10;
    SETJMP_FLOAT128 FltS11;
    SETJMP_FLOAT128 FltS12;
    SETJMP_FLOAT128 FltS13;
    SETJMP_FLOAT128 FltS14;
    SETJMP_FLOAT128 FltS15;
    SETJMP_FLOAT128 FltS16;
    SETJMP_FLOAT128 FltS17;
    SETJMP_FLOAT128 FltS18;
    SETJMP_FLOAT128 FltS19;
    __int64 FPSR;
    __int64 StIIP;
    __int64 BrS0;
    __int64 BrS1;
    __int64 BrS2;
    __int64 BrS3;
    __int64 BrS4;
    __int64 IntS0;
    __int64 IntS1;
    __int64 IntS2;
    __int64 IntS3;
    __int64 RsBSP;
    __int64 RsPFS;
    __int64 ApUNAT;
    __int64 ApLC;
    __int64 IntSp;
    __int64 IntNats;
    __int64 Preds;

  } _JUMP_BUFFER;
#Exceto Definido(__x86_64)
  Pseudônimo _CRT_ALIGN(16) Estrutura _SETJMP_FLOAT128 {
    Natural __int64 Part[2];
  } SETJMP_FLOAT128;

#Defina _JBLEN 16
  Pseudônimo SETJMP_FLOAT128 _JBTYPE;

  Pseudônimo Estrutura _JUMP_BUFFER {
    Natural __int64 Frame;
    Natural __int64 Rbx;
    Natural __int64 Rsp;
    Natural __int64 Rbp;
    Natural __int64 Rsi;
    Natural __int64 Rdi;
    Natural __int64 R12;
    Natural __int64 R13;
    Natural __int64 R14;
    Natural __int64 R15;
    Natural __int64 Rip;
    Natural __int64 Spare;
    SETJMP_FLOAT128 Xmm6;
    SETJMP_FLOAT128 Xmm7;
    SETJMP_FLOAT128 Xmm8;
    SETJMP_FLOAT128 Xmm9;
    SETJMP_FLOAT128 Xmm10;
    SETJMP_FLOAT128 Xmm11;
    SETJMP_FLOAT128 Xmm12;
    SETJMP_FLOAT128 Xmm13;
    SETJMP_FLOAT128 Xmm14;
    SETJMP_FLOAT128 Xmm15;
  } _JUMP_BUFFER;
#FimSe
#SeNãoDefinido _JMP_BUF_DEFINED
  Pseudônimo _JBTYPE jmp_buf[_JBLEN];
#Defina _JMP_BUF_DEFINED
#FimSe

  Vazio * Declaração Atributo ((__nothrow__)) mingw_getsp(Vazio);

#SeDefinido USE_MINGW_SETJMP_TWO_ARGS
#SeNãoDefinido _INC_SETJMPEX
#Defina setjmp(BUF) _setjmp((BUF),mingw_getsp())
  Inteiro Declaração Atributo ((__nothrow__)) _setjmp(jmp_buf _Buf,Vazio *_Ctx);
#Senão
#Esqueça setjmp
#Defina setjmp(BUF) _setjmpex((BUF),mingw_getsp())
#Defina setjmpex(BUF) _setjmpex((BUF),mingw_getsp())
  Inteiro Declaração Atributo ((__nothrow__)) _setjmpex(jmp_buf _Buf,Vazio *_Ctx);
#FimSe
#Senão
#SeNãoDefinido _INC_SETJMPEX
#Defina setjmp _setjmp
#FimSe
  Inteiro Declaração Atributo ((__nothrow__)) setjmp(jmp_buf _Buf);
#FimSe

  __declspec(noreturn) Atributo ((__nothrow__)) Vazio Declaração ms_longjmp(jmp_buf _Buf,Inteiro _Value)/* throw(...)*/;
  __declspec(noreturn) Atributo ((__nothrow__)) Vazio Declaração longjmp(jmp_buf _Buf,Inteiro _Value);

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)
#FimSe
