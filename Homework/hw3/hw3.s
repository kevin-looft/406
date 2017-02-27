	.file	"hw3.c"
	.text
	.globl	sum
	.type	sum, @function
sum:
.LFB20:
	.cfi_startproc
	movl	$0, %edx
	movl	$0, %eax
	jmp	.L2
.L3:
	addq	(%rdi,%rdx,8), %rax
	addq	$1, %rdx
.L2:
	cmpq	%rsi, %rdx
	jl	.L3
	rep ret
	.cfi_endproc
.LFE20:
	.size	sum, .-sum
	.globl	decode2
	.type	decode2, @function
decode2:
.LFB21:
	.cfi_startproc
	movq	%rdi, %rax
	subq	%rdx, %rax
	imulq	%rax, %rdi
	salq	$63, %rax
	sarq	$63, %rax
	xorq	%rdi, %rax
	addq	%rsi, %rax
	ret
	.cfi_endproc
.LFE21:
	.size	decode2, .-decode2
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"sum(a, 8) = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB22:
	.cfi_startproc
	subq	$72, %rsp
	.cfi_def_cfa_offset 80
	movq	$10, (%rsp)
	movq	$8, 8(%rsp)
	movq	$6, 16(%rsp)
	movq	$4, 24(%rsp)
	movq	$2, 32(%rsp)
	movq	$0, 40(%rsp)
	movq	$-2, 48(%rsp)
	movq	$-4, 56(%rsp)
	movl	$8, %esi
	movq	%rsp, %rdi
	call	sum
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	addq	$72, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE22:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-4)"
	.section	.note.GNU-stack,"",@progbits
