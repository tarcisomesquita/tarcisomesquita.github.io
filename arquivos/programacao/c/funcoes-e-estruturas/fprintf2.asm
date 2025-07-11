	.file	"fprintf2.c"
	.intel_syntax noprefix
	.section	.rodata
.LC0:
	.string	"Isso \303\251 um teste"
.LC1:
	.string	"%s %u\n"
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
	mov	DWORD PTR [esp+12], 25
	mov	DWORD PTR [esp+8], OFFSET FLAT:.LC0
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC1
	mov	DWORD PTR [esp], eax
	call	fprintf           # retorna um numero em eax

	mov	eax, 0
	add	esp, 20
	pop	ecx
	pop	ebp
	lea	esp, [ecx-4]
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.3.3-5ubuntu4) 4.3.3"
	.section	.note.GNU-stack,"",@progbits
