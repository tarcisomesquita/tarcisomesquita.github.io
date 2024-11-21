; $ clear && (unset TERM ORBIT_SOCKETDIR SSH_AGENT_PID GPG_AGENT_INFO SHELL XDG_SESSION_COOKIE GTK_RC_FILES WINDOWID GTK_MODULES USER LS_COLORS GNOME_KEYRING_SOCKET SSH_AUTH_SOCK SESSION_MANAGER USERNAME DESKTOP_SESSION GDM_XSERVER_LOCATION PWD LANG GDM_LANG GDMSESSION HISTCONTROL SHLVL HOME GNOME_DESKTOP_SESSION_ID LOGNAME XDG_DATA_DIRS DBUS_SESSION_BUS_ADDRESS LESSOPEN WINDOWPATH LESSCLOSE RUNNING_UNDER_GDM XAUTHORITY DISPLAY COLORTERM _ ; PATH=/bin:/usr/bin ; /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o accept.elf accept.asm && chmod +x ./accept.elf && strace -s 100 -i -f -v ./accept.elf)

%ifndef _accept
%define _accept
socket:

%include "/media/SD/www/linguas/Assembly/tdebug32_v2/include32/0_cabecalho.asm"

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

mov    eax, DWORD [fd]
mov    [fd2], eax
mov    eax, sockaddr
mov    [sockaddr_add], eax


; bind(3, {sa_family=AF_INET, sin_port=htons(8080), sin_addr=inet_addr("127.0.0.1")}, 16) = 0
mov    ecx, bind_args
mov    ebx, 0x00000002   ; parece ser uma constante
mov    eax, 0x00000066   ; syscall bind ; 102
int    0x80


mov    eax, DWORD [fd]
mov    [fd3], eax

; listen(3, 2) // socket fd 3, 2 conexões
mov    ecx, listen_args
mov    ebx, 0x00000004   ; parece ser uma constante
mov    eax, 0x00000066   ; syscall listen ; 102
int    0x80


mov    eax, DWORD [fd]
mov    [fd4], eax

; ns = accept(s, &fsaun, &fromlen);
mov    ecx, accept_args
mov    ebx, 0x00000005   ; parece ser uma constante
mov    eax, 0x00000066   ; syscall accept ; 102
int    0x80


mov ebx, eax

; close syscall é definida em fs/open.c:969
;mov ebx, 0x00000001   ; file descriptor;  0 = stdin, 1 = stdout, 2 = stderr
mov eax, 0x00000006   ; syscall close
int 0x80              ; return the errno in eax. EBADF (-1)


mov ebx, DWORD [fd]

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

sockopt:
fd:
dd 0x00000000        ; file descriptor
dd 0x00000001        ; SOL_SOCKET
dd 0x00000002        ; SO_REUSEADDR
dd yes               ; &yes
dd 0x00000004        ; sizeof(yes)

yes:
dd 0x00000001

sockaddr:
sa_family:  dw 0x0002      ; PF_INET
sin_port:   dw 0x901F      ; htons(8080)
sin_addr:   dd 0x0100007F  ; inet_addr("127.0.0.1")
times 8     db 0x00

bind_args:
fd2:          dd 0x00000000
sockaddr_add: dd 0x00000000
              dd 0x00000010 ;  sockaddr_len

listen_args:
fd3:          dd 0x00000000
conexoes:     dd 0x00000002

accept_args:
fd4:          dd 0x00000000
dd remoteaddr
dd addrlen

remoteaddr:   
remoteaddr_sa_family:  dw 0x0000      ; PF_INET
remoteaddr_sin_port:   dw 0x0000      ; htons(8080)
remoteaddr_sin_addr:   dd 0x00000000  ; inet_addr("127.0.0.1")
times 8                db 0x00
addrlen:      dd 0x00000000

loadsize equ $ - $$
%endif

