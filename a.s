	.file	"a.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB39:
	.cfi_startproc
	endbr64
	pushq	%r12
	.cfi_def_cfa_offset 16
	.cfi_offset 12, -16
	pushq	%rbp
	.cfi_def_cfa_offset 24
	.cfi_offset 6, -24
	pushq	%rbx
	.cfi_def_cfa_offset 32
	.cfi_offset 3, -32
	movl	$4, %esi
	movl	$20, %edi
	call	calloc@PLT
	movq	%rax, matrix(%rip)
	movl	$0, %r12d
	jmp	.L2
.L4:
	movslq	%ebx, %rax
	salq	$2, %rax
	movq	matrix(%rip), %rdx
	movq	%rax, %rsi
	addq	(%rdx,%rbp), %rsi
	leal	(%r12,%rbx), %ecx
	movl	%ecx, (%rsi)
	movq	matrix(%rip), %rdx
	addq	(%rdx,%rbp), %rax
	movl	(%rax), %edx
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	movl	$0, %eax
	call	__printf_chk@PLT
	addl	$1, %ebx
.L3:
	cmpl	$19, %ebx
	jle	.L4
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, %r12d
.L2:
	cmpl	$19, %r12d
	jg	.L7
	movslq	%r12d, %rbp
	salq	$3, %rbp
	movq	%rbp, %rbx
	addq	matrix(%rip), %rbx
	movl	$4, %esi
	movl	$20, %edi
	call	calloc@PLT
	movq	%rax, (%rbx)
	movl	$0, %ebx
	jmp	.L3
.L7:
	movl	$0, %eax
	popq	%rbx
	.cfi_def_cfa_offset 24
	popq	%rbp
	.cfi_def_cfa_offset 16
	popq	%r12
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE39:
	.size	main, .-main
	.comm	matrix,8,8
	.ident	"GCC: (Ubuntu 9.4.0-1ubuntu1~20.04.1) 9.4.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
