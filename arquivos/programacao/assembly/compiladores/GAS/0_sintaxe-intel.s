# gcc -S -masm=intel sintaxe-intel.c -o 0_sintaxe-intel.s
# gcc -Wall 0_sintaxe-intel.s -o sintaxe-intel.elf && ./sintaxe-intel.elf ; echo $?

# signed long int var_global = 5;
# int main() {
#    return 7;
# }

	.intel_syntax noprefix

	.data
	.align 4
.globl var_global
var_global:
	.long	5

	.text
.globl main
main:
	lea	ecx, [esp+4]
	and	esp, 0xFFFFFFF0   # isso é um comentário
	push	DWORD PTR [ecx-4]
	push	ebp
	mov	ebp, esp
	push	ecx
        
	mov	eax, 7
        
	pop	ecx
	pop	ebp
	lea	esp, [ecx-4]
	ret

