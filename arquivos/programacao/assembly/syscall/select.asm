; $ clear && (unset TERM ORBIT_SOCKETDIR SSH_AGENT_PID GPG_AGENT_INFO SHELL XDG_SESSION_COOKIE GTK_RC_FILES WINDOWID GTK_MODULES USER LS_COLORS GNOME_KEYRING_SOCKET SSH_AUTH_SOCK SESSION_MANAGER USERNAME DESKTOP_SESSION GDM_XSERVER_LOCATION PWD LANG GDM_LANG GDMSESSION HISTCONTROL SHLVL HOME GNOME_DESKTOP_SESSION_ID LOGNAME XDG_DATA_DIRS DBUS_SESSION_BUS_ADDRESS LESSOPEN WINDOWPATH LESSCLOSE RUNNING_UNDER_GDM XAUTHORITY DISPLAY COLORTERM _ ; PATH=/bin:/usr/bin ; /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o select.elf select.asm && chmod +x ./select.elf && strace -s 100 -i -f -v ./select.elf)

%ifndef _select
%define _select
select:

%include "/media/SD/www/linguas/Assembly/tdebug32_v2/include32/0_cabecalho.asm"

mov    eax, 0x00000000
mov    [fd], eax

mov    eax, DWORD [fd]
and    eax, 1
test   al, al
je     .L2
mov    eax, DWORD [fd]
shr    eax,1
mov    DWORD [fd_set + eax*4], 2
jmp    .L3
.L2:
mov    eax, DWORD [fd]
shr    eax,1
mov    DWORD [fd_set + eax*4], 1
.L3:

; int select(int nfds, fd_set *readfds, fd_set *writefds, fd_set *exceptfds, struct timeval *timeout);
mov    edi, DWORD [timeout]
mov    esi, 0x0
mov    edx, 0x0
mov    ecx, DWORD [readfds]
mov    ebx, DWORD [fd_size]
mov    eax,0x8e         ; syscall select ; 142
int    0x80


; return 7;
mov    ebx, 0x00000007   ; error_code
mov    eax, 0x000000fc   ; syscall exit_group ; 252
int    0x80              ; 



fd: dd 0x00000000

select_args:
fd_size:        dd 0x00000400  ; o tamanho do fd_set só funciona se for 1024 = 0x400
readfds:     dd fd_set
writefds:    dd 0x00000000
exceptfds:   dd 0x00000000
timeout:     dd timeval

fd_set:
times 512 dd 0x00000000   ; typedef struct { long int __fds_bits[512]; } fd_set;

timeval:           ; 5,5 segundos
sec:   dd 5        ; // Seconds
usec:  dd 500000   ; // Microseconds


loadsize equ $ - $$
%endif

