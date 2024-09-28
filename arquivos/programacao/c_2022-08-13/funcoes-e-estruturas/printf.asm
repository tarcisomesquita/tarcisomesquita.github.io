
#gcc -S -masm=intel teste.c -o teste.asm
#extern int printf(const char *, ...);
#char y[] = "Isso é um teste";
#int main()
#{
#   int x = 10;
#   printf("x = %d\ny = %s\n", x, y);
#   return 0;
#}

#as teste.asm -o teste.o
	.intel_syntax noprefix

.globl y
	.data
y:
	.string	"Isso \303\251 um teste"

	.section	.rodata
.LC0:
	.string	"x = %d\ny = %s\n"

	.text
.globl main
main:
	lea	ecx, [esp+4]
	and	esp, -16
	push	DWORD PTR [ecx-4]
	push	ebp
	mov	ebp, esp
	push	ecx
	sub	esp, 36

	mov	DWORD PTR [ebp-8], 10

	mov	DWORD PTR [esp+8], OFFSET FLAT:y
	mov	eax, DWORD PTR [ebp-8]
	mov	DWORD PTR [esp+4], eax
	mov	DWORD PTR [esp], OFFSET FLAT:.LC0
	call	printf

	mov	eax, 0
	add	esp, 36
	pop	ecx
	pop	ebp
	lea	esp, [ecx-4]
	ret

#/usr/bin/ld \
#-m elf_i386 \
#-static \
#-o teste.elf \
#-z relro \
#/usr/lib/crt1.o \
#/usr/lib/crti.o \
#/usr/lib/gcc/i486-linux-gnu/4.3.3/crtbeginT.o \
#-L/usr/lib/gcc/i486-linux-gnu/4.3.3 \
#-L/usr/lib/ \
#./teste.o \
#\
#--start-group \
#-lgcc \
#-lgcc_eh \
#-lc \
#--end-group \
#\
#/usr/lib/gcc/i486-linux-gnu/4.3.3/crtend.o \
#/usr/lib/crtn.o

