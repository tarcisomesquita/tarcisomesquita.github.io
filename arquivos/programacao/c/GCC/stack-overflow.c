/*
/usr/lib/gcc/i486-linux-gnu/4.3.3/cc1 -quiet teste.c -masm=intel -Wall -fstack-protector -o teste.s

as teste.s -o teste.o

/usr/lib/gcc/i486-linux-gnu/4.3.3/collect2 \
-m elf_i386 \
-static  \
-z relro \
/usr/lib/crt1.o \
/usr/lib/crti.o \
/usr/lib/gcc/i486-linux-gnu/4.3.3/crtbeginT.o \
-L/usr/lib \
-L/usr/lib/gcc/i486-linux-gnu/4.3.3 \
teste.o \
--start-group -lgcc -lgcc_eh -lc --end-group \
/usr/lib/gcc/i486-linux-gnu/4.3.3/crtend.o \
/usr/lib/crtn.o \
-o teste.elf

./teste.elf 100000/
*/

//#include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int sprintf(char *string, char *format, ...);

extern int printf(char *, ...);

int main(int n, char **argv) {
   char address[15];
   unsigned long int representacao = 0x00000002;
   
   sprintf(address, "%s%08X", argv[1], (unsigned int)representacao);
   return 0;
}

/*
	.file	"teste.c"
	.intel_syntax noprefix
	.section .rodata
.LC0:
	.string	"%s%08X"
	.section .text
.globl main
	.type	main, @function
main:
	lea	ecx, [esp+4]
	and	esp, 0xFFFFFFF0
	push	DWORD PTR [ecx-4]
	push	ebp
	mov	ebp, esp
	push	ecx
	sub	esp, 52
	mov	eax, DWORD PTR [ecx+4]
	mov	DWORD PTR [ebp-40], eax
	mov	eax, DWORD PTR gs:20
	mov	DWORD PTR [ebp-8], eax
	xor	eax, eax
	mov	DWORD PTR [ebp-28], 2
	mov	eax, DWORD PTR [ebp-40]
	add	eax, 4
	mov	edx, DWORD PTR [eax]
	mov	eax, DWORD PTR [ebp-28]
	mov	DWORD PTR [esp+12], eax
	mov	DWORD PTR [esp+8], edx
	mov	DWORD PTR [esp+4], OFFSET FLAT:.LC0
	lea	eax, [ebp-23]
	mov	DWORD PTR [esp], eax
	call	sprintf
	mov	eax, 0
	mov	edx, DWORD PTR [ebp-8]
	xor	edx, DWORD PTR gs:20
	je	.L3
	call	__stack_chk_fail
.L3:
	add	esp, 52
	pop	ecx
	pop	ebp
	lea	esp, [ecx-4]
	ret
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.3.3-5ubuntu4) 4.3.3"
	.section	.note.GNU-stack,"",@progbits

*/
