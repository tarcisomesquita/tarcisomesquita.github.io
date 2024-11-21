; $ /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o socket.elf socket.asm && chmod +x socket.elf && strace -s 100 -i -f -v ./socket.elf

%ifndef _socket
%define _socket
socket:

%include "/media/SD/linguas/Assembly/tdebug32_v2/include32/0_cabecalho.asm"

; socket(PF_INET,SOCK_STREAM,IPPROTO_IP);
; definida em net/socket.c
mov    ecx, sock
mov    ebx, 0x00000001   ; parece ser uma constante
mov    eax, 0x00000066   ; syscall socketcall ; 102
int    0x80

mov    ebx, eax

; close syscall é definida em fs/open.c:969
;mov ebx, 0x00000001   ; file descriptor;  0 = stdin, 1 = stdout, 2 = stderr
mov eax, 0x00000006   ; syscall close
int 0x80              ; return the errno in eax. EBADF (-1)

; return 7;
mov    ebx, 0x00000007   ; error_code
mov    eax, 0x000000fc   ; syscall exit_group ; 252
int    0x80              ; 

sock:
dd 0x00000002        ; PF_INET
dd 0x00000001        ; SOCK_STREAM
dd 0x00000000        ; IPPROTO_IP

loadsize equ $ - $$
%endif

