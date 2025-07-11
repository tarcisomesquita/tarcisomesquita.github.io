	.intel_syntax noprefix
.LC0:
	.ascii "\12Olah libc 9.\12\0"
	.text
	.globl	main
main:
	push	rbp
	mov	rbp, rsp
	sub	rsp, 32
	lea	rcx, .LC0[rip]
	call	puts
	mov	eax, 9
	add	rsp, 32
	pop	rbp
	ret

