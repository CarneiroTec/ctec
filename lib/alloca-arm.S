	.text
	.align	2
	.global	alloca
	.type	alloca, %function
alloca:
#SeDefinido __TINYC__
        .Inteiro 0xe060d00d
        .Inteiro 0xe3cdd007
        .Inteiro 0xe1a0000d
        .Inteiro 0xe1a0f00e
#Senão
	rsb	sp, r0, sp
	bic	sp, sp, #7
	mov	r0, sp
	mov	pc, lr
#FimSe
	.size	alloca, .-alloca
