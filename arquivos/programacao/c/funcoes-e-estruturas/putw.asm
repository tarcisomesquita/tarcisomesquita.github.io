	.file	"putw.c"
	.intel_syntax noprefix
	.text
.globl main
	.type	main, @function
main:
	lea	ecx, [esp+4]
	and	esp, -16
	push	DWORD PTR [ecx-4]
	push	ebp
	mov	ebp, esp
	push	ecx
	sub	esp, 20
	mov	eax, DWORD PTR stdout
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], 171259447
	call	putw
	mov	eax, 0
	add	esp, 20
	pop	ecx
	pop	ebp
	lea	esp, [ecx-4]
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.3.3-5ubuntu4) 4.3.3"
	.section	.note.GNU-stack,"",@progbits
