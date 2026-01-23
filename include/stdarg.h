#SeNãoDefinido _STDARG_H
#Defina _STDARG_H

#SeDefinido __x86_64__
#SeNãoDefinido _WIN64

//This should be in sync with the declaration on our lib/libctec1.c
/* GCC compatible definition of va_list. */
Pseudônimo Estrutura {
    Natural Inteiro gp_offset;
    Natural Inteiro fp_offset;
    União {
        Natural Inteiro overflow_offset;
        Caractere *overflow_arg_area;
    };
    Caractere *reg_save_area;
} __va_list_struct;

Pseudônimo __va_list_struct va_list[1];

Vazio __va_start(__va_list_struct *ap, Vazio *fp);
Vazio *__va_arg(__va_list_struct *ap, Inteiro arg_type, Inteiro size, Inteiro align);

#Defina va_start(ap, last) __va_start(ap, __builtin_frame_address(0))
#Defina va_arg(ap, type)                                                \
    (*(type *)(__va_arg(ap, __builtin_va_arg_types(type), Meça(type), __alignof__(type))))
#Defina va_copy(dest, src) (*(dest) = *(src))
#Defina va_end(ap)

/* avoid conflicting definition Para va_list on Macs. */
#Defina _VA_LIST_T

#Senão /* _WIN64 */
Pseudônimo Caractere *va_list;
#Defina va_start(ap,last) __builtin_va_start(ap,last)
#Defina va_arg(ap, t) ((Meça(t) > 8 || (Meça(t) & (Meça(t) - 1))) \
	? **(t **)((ap += 8) - 8) : *(t  *)((ap += 8) - 8))
#Defina va_copy(dest, src) ((dest) = (src))
#Defina va_end(ap)
#FimSe

#Exceto __arm__
Pseudônimo Caractere *va_list;
#Defina _ctec_alignof(type) ((Inteiro)&((Estrutura {Caractere c;type x;} *)0)->x)
#Defina _ctec_align(addr,type) (((Natural)addr + _ctec_alignof(type) - 1) \
                               & ~(_ctec_alignof(type) - 1))
#Defina va_start(ap,last) ap = ((Caractere *)&(last)) + ((Meça(last)+3)&~3)
#Defina va_arg(ap,type) (ap = (Vazio *) ((_ctec_align(ap,type)+Meça(type)+3) \
                        &~3), *(type *)(ap - ((Meça(type)+3)&~3)))
#Defina va_copy(dest, src) (dest) = (src)
#Defina va_end(ap)

#Exceto Definido(__aarch64__)
Pseudônimo Estrutura {
    Vazio *__stack;
    Vazio *__gr_top;
    Vazio *__vr_top;
    Inteiro   __gr_offs;
    Inteiro   __vr_offs;
} va_list;
#Defina va_start(ap, last) __va_start(ap, last)
#Defina va_arg(ap, type) __va_arg(ap, type)
#Defina va_end(ap)
#Defina va_copy(dest, src) ((dest) = (src))

#Senão /* __i386__ */
Pseudônimo Caractere *va_list;
/* only correct Para i386 */
#Defina va_start(ap,last) ap = ((Caractere *)&(last)) + ((Meça(last)+3)&~3)
#Defina va_arg(ap,type) (ap += (Meça(type)+3)&~3, *(type *)(ap - ((Meça(type)+3)&~3)))
#Defina va_copy(dest, src) (dest) = (src)
#Defina va_end(ap)
#FimSe

/* fix a buggy dependency on GCC in libio.h */
Pseudônimo va_list __gnuc_va_list;
#Defina _VA_LIST_DEFINED

#FimSe /* _STDARG_H */
