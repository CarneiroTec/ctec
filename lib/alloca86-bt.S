/* ---------------------------------------------- */
/* alloca86-bt.S */

.globl __bound_alloca

__bound_alloca:
    pop     %edx
    pop     %eax
    mov     %eax, %ecx
    add     $3,%eax
    and     $-4,%eax
    jz      p6

#SeDefinido _WIN32
p4:
    cmp     $4096,%eax
    jbe     p5
    test    %eax,-4096(%esp)
    sub     $4096,%esp
    sub     $4096,%eax
    jmp p4

p5:
#FimSe

    sub     %eax,%esp
    mov     %esp,%eax

    push    %edx
    push    %eax
    push    %ecx
    push    %eax
    call   __bound_new_region
    add    $8, %esp
    pop     %eax
    pop     %edx

p6:
    push    %edx
    push    %edx
    ret

/* mark stack as nonexecutable */
#Se Definido __ELF__ && Definido __linux__
    .section    .note.GNU-stack,"",@progbits
#FimSe
/* ---------------------------------------------- */
