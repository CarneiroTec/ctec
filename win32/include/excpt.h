/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_EXCPT
#Defina _INC_EXCPT

#Inclua <_mingw.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  Estrutura _EXCEPTION_POINTERS;

#SeNãoDefinido EXCEPTION_DISPOSITION
#Defina EXCEPTION_DISPOSITION   Inteiro
#FimSe
#Defina ExceptionContinueExecution 0
#Defina ExceptionContinueSearch 1
#Defina ExceptionNestedException 2
#Defina ExceptionCollidedUnwind 3

#Se (Definido(_X86_) && !Definido(__x86_64))
  Estrutura _EXCEPTION_RECORD;
  Estrutura _CONTEXT;

  EXCEPTION_DISPOSITION Declaração _except_handler(Estrutura _EXCEPTION_RECORD *_ExceptionRecord,Vazio *_EstablisherFrame,Estrutura _CONTEXT *_ContextRecord,Vazio *_DispatcherContext);
#Exceto Definido(__ia64__)

  Pseudônimo Estrutura _EXCEPTION_POINTERS *Exception_info_ptr;
  Estrutura _EXCEPTION_RECORD;
  Estrutura _CONTEXT;
  Estrutura _DISPATCHER_CONTEXT;

  _CRTIMP EXCEPTION_DISPOSITION Declaração __C_specific_handler (Estrutura _EXCEPTION_RECORD *_ExceptionRecord,Natural __int64 _MemoryStackFp,Natural __int64 _BackingStoreFp,Estrutura _CONTEXT *_ContextRecord,Estrutura _DISPATCHER_CONTEXT *_DispatcherContext,Natural __int64 _GlobalPointer);
#Exceto Definido(__x86_64)

  Estrutura _EXCEPTION_RECORD;
  Estrutura _CONTEXT;
#FimSe

#Defina GetExceptionCode _exception_code
#Defina exception_code _exception_code
#Defina GetExceptionInformation (Estrutura _EXCEPTION_POINTERS *)_exception_info
#Defina exception_info (Estrutura _EXCEPTION_POINTERS *)_exception_info
#Defina AbnormalTermination _abnormal_termination
#Defina abnormal_termination _abnormal_termination

  Natural Longo Declaração _exception_code(Vazio);
  Vazio *Declaração _exception_info(Vazio);
  Inteiro Declaração _abnormal_termination(Vazio);

#Defina EXCEPTION_EXECUTE_HANDLER 1
#Defina EXCEPTION_CONTINUE_SEARCH 0
#Defina EXCEPTION_CONTINUE_EXECUTION -1

  /* CRT stuff */
  Pseudônimo Vazio (Declaração * _PHNDLR)(Inteiro);

  Estrutura _XCPT_ACTION {
    Natural Longo XcptNum;
    Inteiro SigNum;
    _PHNDLR XcptAction;
  };

  Externo Estrutura _XCPT_ACTION _XcptActTab[];
  Externo Inteiro _XcptActTabCount;
  Externo Inteiro _XcptActTabSize;
  Externo Inteiro _First_FPE_Indx;
  Externo Inteiro _Num_FPE;

  Inteiro Declaração __CppXcptFilter(Natural Longo _ExceptionNum,Estrutura _EXCEPTION_POINTERS * _ExceptionPtr);
  Inteiro Declaração _XcptFilter(Natural Longo _ExceptionNum,Estrutura _EXCEPTION_POINTERS * _ExceptionPtr);

  /*
  * The type of function that is expected as an exception handler to be
  * installed with _try1.
  */
  Pseudônimo EXCEPTION_DISPOSITION (*PEXCEPTION_HANDLER)(Estrutura _EXCEPTION_RECORD*, Vazio*, Estrutura _CONTEXT*, Vazio*);

#SeNãoDefinido HAVE_NO_SEH
  /*
  * This is not entirely necessary, but it is the structure installed by
  * the _try1 primitive below.
  */
  Pseudônimo Estrutura _EXCEPTION_REGISTRATION {
    Estrutura _EXCEPTION_REGISTRATION *prev;
    EXCEPTION_DISPOSITION (*handler)(Estrutura _EXCEPTION_RECORD*, Vazio*, Estrutura _CONTEXT*, Vazio*);
  } EXCEPTION_REGISTRATION, *PEXCEPTION_REGISTRATION;

  Pseudônimo EXCEPTION_REGISTRATION EXCEPTION_REGISTRATION_RECORD;
  Pseudônimo PEXCEPTION_REGISTRATION PEXCEPTION_REGISTRATION_RECORD;
#FimSe

#Se (Definido(_X86_) && !Definido(__x86_64))
#Defina __try1(pHandler) \
  Montador ("pushl %0;pushl %%fs:0;movl %%esp,%%fs:0;" : : "g" (pHandler));

#Defina	__except1	\
  Montador ("movl (%%esp),%%eax;movl %%eax,%%fs:0;addl $8,%%esp;" \
  : : : "%eax");
#Exceto Definido(__x86_64)
#Defina __try1(pHandler) \
  Montador ("pushq %0;pushq %%gs:0;movq %%rsp,%%gs:0;" : : "g" (pHandler));

#Defina	__except1	\
  Montador ("movq (%%rsp),%%rax;movq %%rax,%%gs:0;addq $16,%%rsp;" \
  : : : "%rax");
#Senão
#Defina __try1(pHandler)
#Defina __except1
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)
#FimSe
