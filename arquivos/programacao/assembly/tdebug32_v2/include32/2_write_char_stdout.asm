; input:  eax tem o byte a ser escrito
; output: eax retorna o número de bytes escritos

%ifndef _write_char_stdout
%define _write_char_stdout

write_char_stdout:
push ebx
push ecx
push edx

push eax
mov  ebx, 0x00000001   ; file descriptor ; stdout = 1 ; err = 2
mov  ecx, esp          ; endereço da string
mov  edx, 0x00000001   ; quantidade de bytes da string
mov  eax, 0x00000004   ; syscall write
int  0x80              ; ? return errno em eax.

pop  ecx

pop  edx
pop  ecx
pop  ebx
ret

%endif

