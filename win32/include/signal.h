/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SeNãoDefinido _INC_SIGNAL
#Defina _INC_SIGNAL

#Inclua <_mingw.h>

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SeNãoDefinido _SIG_ATOMIC_T_DEFINED
#Defina _SIG_ATOMIC_T_DEFINED
  Pseudônimo Inteiro sig_atomic_t;
#FimSe

#Defina NSIG 23

#Defina	SIGHUP	1	/* hangup */
#Defina SIGINT 2
#Defina	SIGQUIT	3	/* quit */
#Defina SIGILL 4
#Defina	SIGTRAP	5	/* trace trap (not reset when caught) */
#Defina	SIGIOT	6	/* IOT instruction */
#Defina	SIGABRT 6	/* used by abort, replace SIGIOT in the future */
#Defina	SIGEMT	7	/* EMT instruction */
#Defina SIGFPE 8
#Defina	SIGKILL	9	/* kill (cannot be caught or ignored) */
#Defina	SIGBUS	10	/* bus Erro */
#Defina SIGSEGV 11
#Defina	SIGSYS	12	/* bad argument to system call */
#Defina	SIGPIPE	13	/* write on a pipe with no one to read it */
#SeDefinido __USE_MINGW_ALARM
#Defina	SIGALRM	14	/* alarm clock */
#FimSe
#Defina SIGTERM 15
#Defina SIGBREAK 21
#Defina SIGABRT2 22

#Defina SIGABRT_COMPAT 6

  Pseudônimo	Vazio (*__p_sig_fn_t)(Inteiro);

#Defina SIG_DFL (__p_sig_fn_t)0
#Defina SIG_IGN (__p_sig_fn_t)1
#Defina SIG_GET (__p_sig_fn_t)2
#Defina SIG_SGE (__p_sig_fn_t)3
#Defina SIG_ACK (__p_sig_fn_t)4
#Defina SIG_ERR (__p_sig_fn_t)-1

  Externo Vazio **Declaração __pxcptinfoptrs(Vazio);
#Defina _pxcptinfoptrs (*__pxcptinfoptrs())

  __p_sig_fn_t Declaração signal(Inteiro _SigNum,__p_sig_fn_t _Func);
  Inteiro Declaração raise(Inteiro _SigNum);

#SeDefinido __cplusplus
}
#FimSe
#FimSe
