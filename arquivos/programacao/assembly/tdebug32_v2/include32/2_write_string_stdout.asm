
; input:  eax tem o offset do primeiro byte da string
; output: eax retorna o número de bytes escritos

%ifndef _write_string_stdout
%define _write_string_stdout

write_string_stdout:
push ebx
push ecx
push edx

mov  ebx, 0x00000001   ; file descriptor ; stdout = 1 ; err = 2
mov  ecx, eax          ; endereço da string
call strlen
mov  edx, eax          ; quantidade de bytes da string
mov  eax, 0x00000004   ; syscall write
int  0x80              ; ? return errno em eax.

pop  edx
pop  ecx
pop  ebx
ret

%include "include32/1_strlen.asm"
%endif

