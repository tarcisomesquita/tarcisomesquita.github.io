; $ /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o setsockopt.elf setsockopt.asm && chmod +x setsockopt.elf && strace -s 100 -i -f -v ./setsockopt.elf

%ifndef _setsockopt
%define _setsockopt
setsockopt:

%include "/media/SD/linguas/Assembly/tdebug32_v2/include32/0_cabecalho.asm"

; socket(PF_INET,SOCK_STREAM,IPPROTO_IP);
; definida em net/socket.c
mov    ecx, sock
mov    ebx, 0x00000001   ; parece ser uma constante
mov    eax, 0x00000066   ; syscall socketcall ; 102
int    0x80

mov    [fd], eax

; setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
mov    ecx, sockopt
mov    ebx, 0x0000000e   ; parece ser uma constante
mov    eax, 0x00000066   ; syscall setsockopt ; 102
int    0x80

mov    ebx, DWORD [fd]

; close syscall é definida em fs/open.c:969
;mov ebx, 0x00000001   ; file descriptor;  0 = stdin, 1 = stdout, 2 = stderr
mov eax, 0x00000006   ; syscall close
int 0x80              ; return the errno in eax. EBADF (-1)


; return 9;
mov    ebx, 0x00000009   ; error_code
mov    eax, 0x000000fc   ; syscall exit_group ; 252
int    0x80              ; 

sock:
dd 0x00000002        ; PF_INET
dd 0x00000001        ; SOCK_STREAM
dd 0x00000000        ; IPPROTO_IP

sockopt:
fd:
dd 0x00000000        ; file descriptor
dd 0x00000001        ; SOL_SOCKET
dd 0x00000002        ; SO_REUSEADDR
dd yes               ; &yes
dd 0x00000004        ; sizeof(yes)

yes:
dd 0x00000001

loadsize equ $ - $$
%endif

