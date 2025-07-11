; ./nasm.elf -f bin -o teste.elf teste.asm && ./teste.elf ; echo $?

%include "include32/0_cabecalho.asm"

mov  eax, string
call write_string_stdout

mov ebx, eax          ; valor a ser retornado
mov eax, 0x00000001   ; syscall exit
int 0x80


%include "include32/2_write_string_stdout.asm"

string:
db "jflsfjsf flas fasjf slfjs flas f",0x00

loadsize equ $ - $$
