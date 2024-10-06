	.file	"printf.c"
	.text
.globl tprintf
	.type	tprintf, @function
tprintf:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$40, %esp
	leal	12(%ebp), %eax
	movl	%eax, -4(%ebp)
	movl	-4(%ebp), %eax
	movl	stdout, %edx
	movl	%eax, 8(%esp)
	movl	8(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	%edx, (%esp)
	call	vfprintf
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	leave
	ret
	.size	tprintf, .-tprintf
	.section	.rodata
.LC0:
	.string	"1 2 3 testando \n"
	.text
.globl main
	.type	main, @function
main:
	leal	4(%esp), %ecx
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ecx
	subl	$4, %esp
	movl	$.LC0, (%esp)
	call	tprintf
	movl	$0, %eax
	addl	$4, %esp
	popl	%ecx
	popl	%ebp
	leal	-4(%ecx), %esp
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.3.3-5ubuntu4) 4.3.3"
	.section	.note.GNU-stack,"",@progbits
