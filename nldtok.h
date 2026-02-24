/* ------------------------------------------------------------------ */
/* C keywords: tipos básicos, controle e declaração                 */
/* ------------------------------------------------------------------ */
     DEF(TOK_VOID, "Vazio")
     DEF(TOK_BOOL, "Lógico")
     DEF(TOK_SHORT, "Curto")
     DEF(TOK_LONG, "Longo")
     DEF(TOK_INT, "Inteiro")
     DEF(TOK_FLOAT, "Real")
     DEF(TOK_DOUBLE, "Duplo")
     DEF(TOK_CHAR, "Caractere")

     /* Controle de fluxo */
     DEF(TOK_GOTO, "Execute")
     DEF(TOK_RETURN, "Retorne")
     DEF(TOK_IF, "Se")
     DEF(TOK_ELSE, "Senão")
     DEF(TOK_FOR, "Para")
     DEF(TOK_DO, "Faça")
     DEF(TOK_WHILE, "Enquanto")
     DEF(TOK_SWITCH, "Troque")
     DEF(TOK_CASE, "Caso")
     DEF(TOK_CONTINUE, "Continue")
     DEF(TOK_DEFAULT, "Padrão")
     DEF(TOK_BREAK, "Interrompa")

     /* Declaração / especificadores de tipo */
     DEF(TOK_ENUM, "Enumeração")
     DEF(TOK_STRUCT, "Estrutura")
     DEF(TOK_TYPEDEF, "Pseudônimo")
     DEF(TOK_UNION, "União")
     
     /* ------------------------------------------------------------------ */
     /* Qualificadores de tipo e palavras-chave do compilador (extensões) */
     /* ------------------------------------------------------------------ */
     DEF(TOK_CONST, "Imutável")
     DEF(TOK_EXTENSION, "Extensão") /* gcc keyword */
     DEF(TOK_GENERIC, "Genérico")
     DEF(TOK_INLINE, "Integrado")
     DEF(TOK_RESTRICT, "Exclusivo")
     DEF(TOK_SIGNED, "Bilateral")
     DEF(TOK_VOLATILE, "Instável")
     DEF(TOK_UNSIGNED, "Natural")
     
     /* ------------------------------------------------------------------ */
     /* Especificadores de armazenamento / linkage                          */
     /* ------------------------------------------------------------------ */
     DEF(TOK_AUTO, "Local")
     DEF(TOK_EXTERN, "Externo")
     DEF(TOK_REGISTER, "Prioridade")
     DEF(TOK_STATIC, "Fixo")

/* ------------------------------------------------------------------ */
/* atribuas e construções do compilador (atributos, typeof, alignof)  */
/* ------------------------------------------------------------------ */
     DEF(TOK_ALIGNOF, "obtenha_alinhamento")
     DEF(TOK_ASM, "Montador")
     DEF(TOK_ATTRIBUTE, "atribua")
     DEF(TOK_LABEL, "rotule")
     DEF(TOK_SIZEOF, "meça")
     DEF(TOK_TYPEOF, "identifique")

     
#ifdef NILDO_TARGET_ARM64
     DEF(TOK_UINT128, "__uint128_t")
#endif

/* ------------------------------------------------------------------ */
/* Pré-processador (não são palavras-chave do C; usados pelo preproc)  */
/* ------------------------------------------------------------------ */
     DEF(TOK_DEFINE, "Defina")
     DEF(TOK_INCLUDE, "Inclua")
     DEF(TOK_INCLUDE_NEXT, "Inclua_Próximo")
     DEF(TOK_IFDEF, "SeDefinido")
     DEF(TOK_IFNDEF, "SeNãoDefinido")
     DEF(TOK_ELIF, "Exceto")
     DEF(TOK_ENDIF, "FimSe")
     DEF(TOK_DEFINED, "Definido")
     DEF(TOK_UNDEF, "Esqueça")
     DEF(TOK_ERROR, "Erro")
     DEF(TOK_WARNING, "Aviso")
     DEF(TOK_LINE, "Linha")
     DEF(TOK_PRAGMA, "Diretiva")
     DEF(TOK___LINE__, "LINHA")
     DEF(TOK___FILE__, "ARQUIVO")
     DEF(TOK___DATE__, "DATA")
     DEF(TOK___TIME__, "HORA")
     DEF(TOK___FUNCTION__, "FUNÇÃO")
     DEF(TOK___VA_ARGS__, "ARGUMENTOS_VARIÁVEIS")
     DEF(TOK___COUNTER__, "CONTADOR")

/* ------------------------------------------------------------------ */
/* Identificadores especiais e valores mágicos                         */
/* ------------------------------------------------------------------ */
     DEF(TOK___FUNC__, "__func__")
     DEF(TOK___NAN__, "__nan__")
     DEF(TOK___SNAN__, "__snan__")
     DEF(TOK___INF__, "__inf__")

/* ------------------------------------------------------------------ */
/* Identificadores de atributos (section, aligned, packed, etc.)       */
/* ------------------------------------------------------------------ */
     DEF(TOK_SECTION, "Seção")
     DEF(TOK_ALIGNED, "Alinhado")
     DEF(TOK_PACKED, "Compactado")
     DEF(TOK_WEAK, "Fraco")
     DEF(TOK_ALIAS, "Apelido")
     DEF(TOK_UNUSED, "Inutilizado")

     DEF(TOK_CDECL, "Declaração")
     DEF(TOK_STDCALL, "Chamada")
     DEF(TOK_FASTCALL, "ChamadaRápida")
     DEF(TOK_REGPARM, "RegistroParâmetro")

     DEF(TOK_MODE, "__mode__")
     DEF(TOK_MODE_QI, "__QI__")
     DEF(TOK_MODE_DI, "__DI__")
     DEF(TOK_MODE_HI, "__HI__")
     DEF(TOK_MODE_SI, "__SI__")
     DEF(TOK_MODE_word, "__word__")

     DEF(TOK_DLLEXPORT, "Exporte")
     DEF(TOK_DLLIMPORT, "Importe")
     DEF(TOK_NORETURN, "SemRetorno")
     DEF(TOK_VISIBILITY, "Visibilidade")

/* ------------------------------------------------------------------ */
/* Builtins do compilador e intrínsecos                                */
/* ------------------------------------------------------------------ */
     DEF(TOK_builtin_types_compatible_p, "compare_tipo_compatível")
     DEF(TOK_builtin_choose_expr, "escolha_expressão")
     DEF(TOK_builtin_constant_p, "afirme_constante")
     DEF(TOK_builtin_frame_address, "obtenha_endereço_pilha")
     DEF(TOK_builtin_return_address, "obtenha_endereço_retorno")
     DEF(TOK_builtin_expect, "deduza")
     /*DEF(TOK_builtin_va_list, "__builtin_va_list")*/
#if defined NILDO_TARGET_PE && defined NILDO_TARGET_X86_64
     DEF(TOK_builtin_va_start, "__builtin_va_start")
#elif defined NILDO_TARGET_X86_64
     DEF(TOK_builtin_va_arg_types, "__builtin_va_arg_types")
#elif defined NILDO_TARGET_ARM64
     DEF(TOK___va_start, "__va_start")
     DEF(TOK___va_arg, "__va_arg")
#endif

/* ------------------------------------------------------------------ */
/* Pragmas e diretivas específicos do pré-processador                   */
/* ------------------------------------------------------------------ */
     DEF(TOK_pack, "pack")
#if !defined(NILDO_TARGET_I386) && !defined(NILDO_TARGET_X86_64)
     /* already defined for assembler */
     DEF(TOK_ASM_push, "push")
     DEF(TOK_ASM_pop, "pop")
#endif
     DEF(TOK_comment, "comment")
     DEF(TOK_lib, "lib")
     DEF(TOK_push_macro, "push_macro")
     DEF(TOK_pop_macro, "pop_macro")
     DEF(TOK_once, "once")
     DEF(TOK_option, "option")

/* ------------------------------------------------------------------ */
/* Funções/variáveis builtin disponíveis por plataforma                  */
/* ------------------------------------------------------------------ */
#ifndef NILDO_ARM_EABI
     DEF(TOK_memcpy, "memcpy")
     DEF(TOK_memmove, "memmove")
     DEF(TOK_memset, "memset")
     DEF(TOK___divdi3, "__divdi3")
     DEF(TOK___moddi3, "__moddi3")
     DEF(TOK___udivdi3, "__udivdi3")
     DEF(TOK___umoddi3, "__umoddi3")
     DEF(TOK___ashrdi3, "__ashrdi3")
     DEF(TOK___lshrdi3, "__lshrdi3")
     DEF(TOK___ashldi3, "__ashldi3")
     DEF(TOK___floatundisf, "__floatundisf")
     DEF(TOK___floatundidf, "__floatundidf")
# ifndef NILDO_ARM_VFP
     DEF(TOK___floatundixf, "__floatundixf")
     DEF(TOK___fixunsxfdi, "__fixunsxfdi")
# endif
     DEF(TOK___fixunssfdi, "__fixunssfdi")
     DEF(TOK___fixunsdfdi, "__fixunsdfdi")
#endif

#if defined NILDO_TARGET_ARM
# ifdef NILDO_ARM_EABI
     DEF(TOK_memcpy, "__aeabi_memcpy")
     DEF(TOK_memcpy4, "__aeabi_memcpy4")
     DEF(TOK_memcpy8, "__aeabi_memcpy8")
     DEF(TOK_memmove, "__aeabi_memmove")
     DEF(TOK_memset, "__aeabi_memset")
     DEF(TOK___aeabi_ldivmod, "__aeabi_ldivmod")
     DEF(TOK___aeabi_uldivmod, "__aeabi_uldivmod")
     DEF(TOK___aeabi_idivmod, "__aeabi_idivmod")
     DEF(TOK___aeabi_uidivmod, "__aeabi_uidivmod")
     DEF(TOK___divsi3, "__aeabi_idiv")
     DEF(TOK___udivsi3, "__aeabi_uidiv")
     DEF(TOK___floatdisf, "__aeabi_l2f")
     DEF(TOK___floatdidf, "__aeabi_l2d")
     DEF(TOK___fixsfdi, "__aeabi_f2lz")
     DEF(TOK___fixdfdi, "__aeabi_d2lz")
     DEF(TOK___ashrdi3, "__aeabi_lasr")
     DEF(TOK___lshrdi3, "__aeabi_llsr")
     DEF(TOK___ashldi3, "__aeabi_llsl")
     DEF(TOK___floatundisf, "__aeabi_ul2f")
     DEF(TOK___floatundidf, "__aeabi_ul2d")
     DEF(TOK___fixunssfdi, "__aeabi_f2ulz")
     DEF(TOK___fixunsdfdi, "__aeabi_d2ulz")
# else
     DEF(TOK___modsi3, "__modsi3")
     DEF(TOK___umodsi3, "__umodsi3")
     DEF(TOK___divsi3, "__divsi3")
     DEF(TOK___udivsi3, "__udivsi3")
     DEF(TOK___floatdisf, "__floatdisf")
     DEF(TOK___floatdidf, "__floatdidf")
#  ifndef NILDO_ARM_VFP
     DEF(TOK___floatdixf, "__floatdixf")
     DEF(TOK___fixunssfsi, "__fixunssfsi")
     DEF(TOK___fixunsdfsi, "__fixunsdfsi")
     DEF(TOK___fixunsxfsi, "__fixunsxfsi")
     DEF(TOK___fixxfdi, "__fixxfdi")
#  endif
     DEF(TOK___fixsfdi, "__fixsfdi")
     DEF(TOK___fixdfdi, "__fixdfdi")
# endif
#endif

#if defined NILDO_TARGET_C67
     DEF(TOK__divi, "_divi")
     DEF(TOK__divu, "_divu")
     DEF(TOK__divf, "_divf")
     DEF(TOK__divd, "_divd")
     DEF(TOK__remi, "_remi")
     DEF(TOK__remu, "_remu")
#endif

#if defined NILDO_TARGET_I386
     DEF(TOK___fixsfdi, "__fixsfdi")
     DEF(TOK___fixdfdi, "__fixdfdi")
     DEF(TOK___fixxfdi, "__fixxfdi")
#endif

#if defined NILDO_TARGET_I386 || defined NILDO_TARGET_X86_64
     DEF(TOK_alloca, "alloca")
#endif

#if defined NILDO_TARGET_PE
     DEF(TOK___chkstk, "__chkstk")
#endif
#ifdef NILDO_TARGET_ARM64
     DEF(TOK___arm64_clear_cache, "__arm64_clear_cache")
     DEF(TOK___addtf3, "__addtf3")
     DEF(TOK___subtf3, "__subtf3")
     DEF(TOK___multf3, "__multf3")
     DEF(TOK___divtf3, "__divtf3")
     DEF(TOK___extendsftf2, "__extendsftf2")
     DEF(TOK___extenddftf2, "__extenddftf2")
     DEF(TOK___trunctfsf2, "__trunctfsf2")
     DEF(TOK___trunctfdf2, "__trunctfdf2")
     DEF(TOK___fixtfsi, "__fixtfsi")
     DEF(TOK___fixtfdi, "__fixtfdi")
     DEF(TOK___fixunstfsi, "__fixunstfsi")
     DEF(TOK___fixunstfdi, "__fixunstfdi")
     DEF(TOK___floatsitf, "__floatsitf")
     DEF(TOK___floatditf, "__floatditf")
     DEF(TOK___floatunsitf, "__floatunsitf")
     DEF(TOK___floatunditf, "__floatunditf")
     DEF(TOK___eqtf2, "__eqtf2")
     DEF(TOK___netf2, "__netf2")
     DEF(TOK___lttf2, "__lttf2")
     DEF(TOK___letf2, "__letf2")
     DEF(TOK___gttf2, "__gttf2")
     DEF(TOK___getf2, "__getf2")
#endif

/* ------------------------------------------------------------------ */
/* Bound checking symbols (opcionais)                                 */
/* ------------------------------------------------------------------ */
#ifdef CONFIG_NILDO_BCHECK
     DEF(TOK___bound_ptr_add, "__bound_ptr_add")
     DEF(TOK___bound_ptr_indir1, "__bound_ptr_indir1")
     DEF(TOK___bound_ptr_indir2, "__bound_ptr_indir2")
     DEF(TOK___bound_ptr_indir4, "__bound_ptr_indir4")
     DEF(TOK___bound_ptr_indir8, "__bound_ptr_indir8")
     DEF(TOK___bound_ptr_indir12, "__bound_ptr_indir12")
     DEF(TOK___bound_ptr_indir16, "__bound_ptr_indir16")
     DEF(TOK___bound_main_arg, "__bound_main_arg")
     DEF(TOK___bound_local_new, "__bound_local_new")
     DEF(TOK___bound_local_delete, "__bound_local_delete")
# ifdef NILDO_TARGET_PE
     DEF(TOK_malloc, "malloc")
     DEF(TOK_free, "free")
     DEF(TOK_realloc, "realloc")
     DEF(TOK_memalign, "memalign")
     DEF(TOK_calloc, "calloc")
# endif
     DEF(TOK_strlen, "strlen")
     DEF(TOK_strcpy, "strcpy")
#endif

/* ------------------------------------------------------------------ */
/* Tiny Assembler directives (mantidas sem alteração funcional)        */
/* ------------------------------------------------------------------ */
 DEF_ASMDIR(byte)              /* must be first directive */
 DEF_ASMDIR(word)
 DEF_ASMDIR(align)
 DEF_ASMDIR(balign)
 DEF_ASMDIR(p2align)
 DEF_ASMDIR(set)
 DEF_ASMDIR(skip)
 DEF_ASMDIR(space)
 DEF_ASMDIR(string)
 DEF_ASMDIR(asciz)
 DEF_ASMDIR(ascii)
 DEF_ASMDIR(file)
 DEF_ASMDIR(globl)
 DEF_ASMDIR(global)
 DEF_ASMDIR(weak)
 DEF_ASMDIR(hidden)
 DEF_ASMDIR(ident)
 DEF_ASMDIR(size)
 DEF_ASMDIR(type)
 DEF_ASMDIR(text)
 DEF_ASMDIR(data)
 DEF_ASMDIR(bss)
 DEF_ASMDIR(previous)
 DEF_ASMDIR(pushsection)
 DEF_ASMDIR(popsection)
 DEF_ASMDIR(fill)
 DEF_ASMDIR(rept)
 DEF_ASMDIR(endr)
 DEF_ASMDIR(org)
 DEF_ASMDIR(quad)
#if defined(NILDO_TARGET_I386)
 DEF_ASMDIR(code16)
 DEF_ASMDIR(code32)
#elif defined(NILDO_TARGET_X86_64)
 DEF_ASMDIR(code64)
#endif
 DEF_ASMDIR(short)
 DEF_ASMDIR(long)
 DEF_ASMDIR(int)
 DEF_ASMDIR(section)            /* must be last directive */

#if defined NILDO_TARGET_I386 || defined NILDO_TARGET_X86_64
#include "i386-tok.h"
#endif
