	.file	"main.c"
	.text
	.globl	fAdd
	.def	fAdd;	.scl	2;	.type	32;	.endef
	.seh_proc	fAdd
fAdd:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movss	16(%rbp), %xmm0
	addss	24(%rbp), %xmm0
	movss	%xmm0, 16(%rbp)
	movss	16(%rbp), %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.globl	fSub
	.def	fSub;	.scl	2;	.type	32;	.endef
	.seh_proc	fSub
fSub:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movss	16(%rbp), %xmm0
	subss	24(%rbp), %xmm0
	movss	%xmm0, 16(%rbp)
	movss	16(%rbp), %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.globl	fMul
	.def	fMul;	.scl	2;	.type	32;	.endef
	.seh_proc	fMul
fMul:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	movss	16(%rbp), %xmm0
	mulss	24(%rbp), %xmm0
	movss	%xmm0, 16(%rbp)
	movss	16(%rbp), %xmm0
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC1:
	.ascii "Erro!!!Divisao por Zero nao e possivel!!!\12\0"
	.text
	.globl	fDiv
	.def	fDiv;	.scl	2;	.type	32;	.endef
	.seh_proc	fDiv
fDiv:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$32, %rsp
	.seh_stackalloc	32
	.seh_endprologue
	movss	%xmm0, 16(%rbp)
	movss	%xmm1, 24(%rbp)
	pxor	%xmm0, %xmm0
	ucomiss	24(%rbp), %xmm0
	jb	.L8
	leaq	.LC1(%rip), %rcx
	call	puts
.L8:
	movss	16(%rbp), %xmm0
	divss	24(%rbp), %xmm0
	movss	%xmm0, 16(%rbp)
	movss	16(%rbp), %xmm0
	addq	$32, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	fFib
	.def	fFib;	.scl	2;	.type	32;	.endef
	.seh_proc	fFib
fFib:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movl	%ecx, -64(%rbp)
	cmpl	$0, -64(%rbp)
	jne	.L13
	movl	$0, %eax
	jmp	.L14
.L13:
	cmpl	$1, -64(%rbp)
	je	.L15
	cmpl	$2, -64(%rbp)
	jne	.L16
.L15:
	movl	$1, %eax
	jmp	.L14
.L16:
	movl	-64(%rbp), %eax
	subl	$1, %eax
	movl	%eax, %ecx
	call	fFib
	movl	%eax, %ebx
	movl	-64(%rbp), %eax
	subl	$2, %eax
	movl	%eax, %ecx
	call	fFib
	addl	%ebx, %eax
.L14:
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC2:
	.ascii "\12Entre com o valor de 'A': \0"
.LC3:
	.ascii "%f\0"
	.text
	.globl	inserirA
	.def	inserirA;	.scl	2;	.type	32;	.endef
	.seh_proc	inserirA
inserirA:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	leaq	.LC2(%rip), %rcx
	call	printf
	leaq	-4(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rcx
	call	scanf
	movss	-4(%rbp), %xmm0
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC4:
	.ascii "\12Entre com o valor de 'B': \0"
	.text
	.globl	inserirB
	.def	inserirB;	.scl	2;	.type	32;	.endef
	.seh_proc	inserirB
inserirB:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	leaq	.LC4(%rip), %rcx
	call	printf
	leaq	-4(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC3(%rip), %rcx
	call	scanf
	movss	-4(%rbp), %xmm0
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	menuOperacao
	.def	menuOperacao;	.scl	2;	.type	32;	.endef
	.seh_proc	menuOperacao
menuOperacao:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, -64(%rbp)
	movq	%rdx, %rbx
	movl	20(%rbx), %eax
	cmpl	$1, %eax
	jne	.L22
	movss	4(%rbx), %xmm0
	movl	(%rbx), %eax
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	fAdd
	movd	%xmm0, %eax
	movl	%eax, 8(%rbx)
	jmp	.L23
.L22:
	movl	20(%rbx), %eax
	cmpl	$2, %eax
	jne	.L24
	movss	4(%rbx), %xmm0
	movl	(%rbx), %eax
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	fSub
	movd	%xmm0, %eax
	movl	%eax, 8(%rbx)
	jmp	.L23
.L24:
	movl	20(%rbx), %eax
	cmpl	$3, %eax
	jne	.L25
	movss	4(%rbx), %xmm0
	movl	(%rbx), %eax
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	fMul
	movd	%xmm0, %eax
	movl	%eax, 8(%rbx)
	jmp	.L23
.L25:
	movl	20(%rbx), %eax
	cmpl	$4, %eax
	jne	.L23
	movss	4(%rbx), %xmm0
	movl	(%rbx), %eax
	movaps	%xmm0, %xmm1
	movd	%eax, %xmm0
	call	fDiv
	movd	%xmm0, %eax
	movl	%eax, 8(%rbx)
.L23:
	movq	-64(%rbp), %rax
	movq	(%rbx), %rdx
	movq	%rdx, (%rax)
	movq	8(%rbx), %rdx
	movq	%rdx, 8(%rax)
	movq	16(%rbx), %rdx
	movq	%rdx, 16(%rax)
	movq	-64(%rbp), %rax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC5:
	.ascii "\12\11*****CASIO S3.X*****\0"
	.align 8
.LC6:
	.ascii "\12\12Operacoes para o limite de 32 bits\0"
.LC7:
	.ascii "1 - Soma\0"
.LC8:
	.ascii "2 - Subtracao\0"
.LC9:
	.ascii "3 - Multiplicacao\0"
.LC10:
	.ascii "4 - Divisao\0"
.LC11:
	.ascii "\12Escolha a operacao:\0"
.LC12:
	.ascii "%d\0"
.LC13:
	.ascii "\12Opcao invalida!!!\0"
.LC14:
	.ascii "'A' = %f\0"
	.text
	.globl	menu
	.def	menu;	.scl	2;	.type	32;	.endef
	.seh_proc	menu
menu:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$104, %rsp
	.seh_stackalloc	104
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, 0(%rbp)
	movq	%rdx, %rbx
.L30:
	leaq	.LC5(%rip), %rcx
	call	printf
	leaq	.LC6(%rip), %rcx
	call	puts
	leaq	.LC7(%rip), %rcx
	call	puts
	leaq	.LC8(%rip), %rcx
	call	puts
	leaq	.LC9(%rip), %rcx
	call	puts
	leaq	.LC10(%rip), %rcx
	call	puts
	leaq	.LC11(%rip), %rcx
	call	printf
	leaq	20(%rbx), %rax
	movq	%rax, %rdx
	leaq	.LC12(%rip), %rcx
	call	scanf
	movl	20(%rbx), %eax
	testl	%eax, %eax
	jle	.L28
	movl	20(%rbx), %eax
	cmpl	$4, %eax
	jle	.L29
.L28:
	leaq	.LC13(%rip), %rcx
	call	printf
.L29:
	movl	20(%rbx), %eax
	testl	%eax, %eax
	jle	.L30
	movl	20(%rbx), %eax
	cmpl	$4, %eax
	jg	.L30
	movl	12(%rbx), %eax
	leal	1(%rax), %edx
	movl	%edx, 12(%rbx)
	testl	%eax, %eax
	jne	.L31
	call	inserirA
	movd	%xmm0, %eax
	movl	%eax, (%rbx)
	jmp	.L32
.L31:
	movss	(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm0, %rax
	movq	%rax, %rdx
	movq	%rdx, %xmm1
	movq	%rax, %rdx
	leaq	.LC14(%rip), %rcx
	call	printf
.L32:
	call	inserirB
	movd	%xmm0, %eax
	movl	%eax, 4(%rbx)
	movss	4(%rbx), %xmm0
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jp	.L33
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jne	.L33
	movq	0(%rbp), %rax
	movq	(%rbx), %rdx
	movq	%rdx, (%rax)
	movq	8(%rbx), %rdx
	movq	%rdx, 8(%rax)
	movq	16(%rbx), %rdx
	movq	%rdx, 16(%rax)
	jmp	.L27
.L33:
	movl	20(%rbx), %eax
	movl	%eax, 16(%rbx)
	leaq	-64(%rbp), %rax
	movq	(%rbx), %rdx
	movq	%rdx, -96(%rbp)
	movq	8(%rbx), %rdx
	movq	%rdx, -88(%rbp)
	movq	16(%rbx), %rdx
	movq	%rdx, -80(%rbp)
	leaq	-96(%rbp), %rdx
	movq	%rax, %rcx
	call	menuOperacao
	movq	-64(%rbp), %rax
	movq	%rax, (%rbx)
	movq	-56(%rbp), %rax
	movq	%rax, 8(%rbx)
	movq	-48(%rbp), %rax
	movq	%rax, 16(%rbx)
	movq	0(%rbp), %rax
	movq	(%rbx), %rdx
	movq	%rdx, (%rax)
	movq	8(%rbx), %rdx
	movq	%rdx, 8(%rax)
	movq	16(%rbx), %rdx
	movq	%rdx, 16(%rax)
.L27:
	movq	0(%rbp), %rax
	addq	$104, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
.LC15:
	.ascii "Resultado\0"
.LC16:
	.ascii "Operacao n: %d\12\0"
.LC17:
	.ascii "\11'A' + 'B' = 'C'\0"
.LC18:
	.ascii "%f + %f = %f\0"
.LC19:
	.ascii "%f - %f = %f\0"
.LC20:
	.ascii "%f * %f = %f\0"
.LC21:
	.ascii "%f / %f = %f\0"
	.text
	.globl	resPrint
	.def	resPrint;	.scl	2;	.type	32;	.endef
	.seh_proc	resPrint
resPrint:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	128(%rsp), %rbp
	.seh_setframe	%rbp, 128
	.seh_endprologue
	movq	%rcx, %rbx
	leaq	.LC15(%rip), %rcx
	call	puts
	movl	12(%rbx), %eax
	movl	%eax, %edx
	leaq	.LC16(%rip), %rcx
	call	printf
	leaq	.LC17(%rip), %rcx
	call	puts
	movl	20(%rbx), %eax
	cmpl	$1, %eax
	jne	.L38
	movss	8(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm2
	movss	4(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm1
	movss	(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm2, %rax
	movq	%rax, %rdx
	movq	%rdx, %r8
	movq	%rax, %xmm2
	movq	%xmm1, %rax
	movq	%rax, %rdx
	movq	%rdx, %rcx
	movq	%rax, %xmm1
	movq	%xmm0, %rax
	movq	%rax, %rdx
	movq	%r8, %xmm3
	movq	%xmm2, %r9
	movq	%rcx, %xmm2
	movq	%xmm1, %r8
	movq	%rdx, %xmm1
	movq	%rax, %rdx
	leaq	.LC18(%rip), %rcx
	call	printf
	jmp	.L42
.L38:
	movl	20(%rbx), %eax
	cmpl	$2, %eax
	jne	.L40
	movss	8(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm2
	movss	4(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm1
	movss	(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm2, %rax
	movq	%rax, %rdx
	movq	%rdx, %r8
	movq	%rax, %xmm2
	movq	%xmm1, %rax
	movq	%rax, %rdx
	movq	%rdx, %rcx
	movq	%rax, %xmm1
	movq	%xmm0, %rax
	movq	%rax, %rdx
	movq	%r8, %xmm3
	movq	%xmm2, %r9
	movq	%rcx, %xmm2
	movq	%xmm1, %r8
	movq	%rdx, %xmm1
	movq	%rax, %rdx
	leaq	.LC19(%rip), %rcx
	call	printf
	jmp	.L42
.L40:
	movl	20(%rbx), %eax
	cmpl	$3, %eax
	jne	.L41
	movss	8(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm2
	movss	4(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm1
	movss	(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm2, %rax
	movq	%rax, %rdx
	movq	%rdx, %r8
	movq	%rax, %xmm2
	movq	%xmm1, %rax
	movq	%rax, %rdx
	movq	%rdx, %rcx
	movq	%rax, %xmm1
	movq	%xmm0, %rax
	movq	%rax, %rdx
	movq	%r8, %xmm3
	movq	%xmm2, %r9
	movq	%rcx, %xmm2
	movq	%xmm1, %r8
	movq	%rdx, %xmm1
	movq	%rax, %rdx
	leaq	.LC20(%rip), %rcx
	call	printf
	jmp	.L42
.L41:
	movl	20(%rbx), %eax
	cmpl	$4, %eax
	jne	.L42
	movss	8(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm2
	movss	4(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm1
	movss	(%rbx), %xmm0
	cvtss2sd	%xmm0, %xmm0
	movq	%xmm2, %rax
	movq	%rax, %rdx
	movq	%rdx, %r8
	movq	%rax, %xmm2
	movq	%xmm1, %rax
	movq	%rax, %rdx
	movq	%rdx, %rcx
	movq	%rax, %xmm1
	movq	%xmm0, %rax
	movq	%rax, %rdx
	movq	%r8, %xmm3
	movq	%xmm2, %r9
	movq	%rcx, %xmm2
	movq	%xmm1, %r8
	movq	%rdx, %xmm1
	movq	%rax, %rdx
	leaq	.LC21(%rip), %rcx
	call	printf
.L42:
	nop
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
.LC23:
	.ascii "\12\12\12\0"
.LC24:
	.ascii "In the End!!!\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$96, %rsp
	.seh_stackalloc	96
	.seh_endprologue
	call	__main
	pxor	%xmm0, %xmm0
	movss	%xmm0, -32(%rbp)
	movss	.LC22(%rip), %xmm0
	movss	%xmm0, -28(%rbp)
	movl	$0, -20(%rbp)
	movl	$0, -16(%rbp)
	movl	$0, -12(%rbp)
.L46:
	leaq	-32(%rbp), %rax
	movq	-32(%rbp), %rdx
	movq	%rdx, -64(%rbp)
	movq	-24(%rbp), %rdx
	movq	%rdx, -56(%rbp)
	movq	-16(%rbp), %rdx
	movq	%rdx, -48(%rbp)
	leaq	-64(%rbp), %rdx
	movq	%rax, %rcx
	call	menu
	movss	-28(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jp	.L48
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	je	.L44
.L48:
	movq	-32(%rbp), %rax
	movq	%rax, -64(%rbp)
	movq	-24(%rbp), %rax
	movq	%rax, -56(%rbp)
	movq	-16(%rbp), %rax
	movq	%rax, -48(%rbp)
	leaq	-64(%rbp), %rax
	movq	%rax, %rcx
	call	resPrint
	movss	-24(%rbp), %xmm0
	movss	%xmm0, -32(%rbp)
.L44:
	leaq	.LC23(%rip), %rcx
	call	puts
	movss	-28(%rbp), %xmm0
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jp	.L46
	pxor	%xmm1, %xmm1
	ucomiss	%xmm1, %xmm0
	jne	.L46
	leaq	.LC24(%rip), %rcx
	call	printf
	movl	$0, %eax
	addq	$96, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 4
.LC22:
	.long	1065353216
	.ident	"GCC: (x86_64-posix-sjlj-rev0, Built by MinGW-W64 project) 7.2.0"
	.def	puts;	.scl	2;	.type	32;	.endef
	.def	printf;	.scl	2;	.type	32;	.endef
	.def	scanf;	.scl	2;	.type	32;	.endef
