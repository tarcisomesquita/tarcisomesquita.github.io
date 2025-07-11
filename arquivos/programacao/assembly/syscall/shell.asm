; $ clear && (unset TERM ORBIT_SOCKETDIR SSH_AGENT_PID GPG_AGENT_INFO SHELL XDG_SESSION_COOKIE GTK_RC_FILES WINDOWID GTK_MODULES USER LS_COLORS GNOME_KEYRING_SOCKET SSH_AUTH_SOCK SESSION_MANAGER USERNAME DESKTOP_SESSION GDM_XSERVER_LOCATION PWD LANG GDM_LANG GDMSESSION HISTCONTROL SHLVL HOME GNOME_DESKTOP_SESSION_ID LOGNAME XDG_DATA_DIRS DBUS_SESSION_BUS_ADDRESS LESSOPEN WINDOWPATH LESSCLOSE RUNNING_UNDER_GDM XAUTHORITY DISPLAY COLORTERM _ ; PATH=/bin:/usr/bin ; /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o shell.elf shell.asm && chmod +x ./shell.elf && strace -s 100 -i -f -v ./shell.elf )

%ifndef _shell
%define _shell
shell:

%include "/media/SD/www/linguas/Assembly/tdebug32_v2/include32/0_cabecalho.asm"

prompt:

mov    ecx, 0xCA
mov    edx, comando
dec    edx
limpa_comando:
inc    edx
mov  byte [edx], 0x00
loop limpa_comando

mov    ecx, 0xCA
mov    edx, argv
sub    edx, 4
limpa_argv:
add    edx, 4
mov  dword [edx], 0x00000000
loop limpa_argv


mov    edx, ps1_len      ; quantidade de bytes da string
mov    ecx, ps1          ; endereço da string
mov    ebx, 0x00000001   ; file descriptor ; stdout = 1 ; err = 2
mov    eax, 0x00000004   ; syscall write
int    0x80              ; return errno em eax.

xor    esi, esi
mov    edi, argv
mov    dword [edi], comando   ; o primeiro argumento é o próprio comando
mov    edx, 0x00000001   ; quantidade de bytes da string
mov    ecx, comando      ; endereço da string
mov    ebx, 0x00000000   ; file descriptor ; stdin = 0
entrada:
mov    eax, 0x00000003   ; syscall read
int    0x80              ; return errno em eax.

inc    esi
cmp    esi, 0xC9
je     entrada_over

cmp byte [comando],0x20
je entrada

cmp byte [ecx],0x20
jne    nespaco
mov byte [ecx],0x00
inc    ecx
add    edi, 4
mov dword [edi], ecx
jmp entrada

nespaco:
cmp byte [ecx],0x0A
jz entrada_end
inc ecx
jmp entrada

entrada_end:
mov byte [ecx],0x00

mov    ebx,0x00000000
mov    eax,0x00000002   ; syscall fork
int    0x80

test eax,eax
jnz esperar

; EXECVE
mov    edx, envp
mov    ecx, argv
mov    ebx, comando
mov    eax,0x0000000b   ; syscall execve
int    0x80

; return 8;
mov    ebx, 0x00000008   ; error_code
mov    eax, 0x000000fc   ; syscall exit_group ; 252
int    0x80              ; 



jmp fim

esperar:
xor    edi, edi
mov    esi, edi
mov    edx, edi
mov    ecx, edi          ; 
mov    ebx, eax          ; pid
mov    eax, 0x00000007   ; syscall wait
int    0x80              ; return em eax
jmp prompt

entrada_over:
mov    edx, erro_in_over_len      ; quantidade de bytes da string
mov    ecx, erro_in_over          ; endereço da string
mov    ebx, 0x00000001   ; file descriptor ; stdout = 1 ; err = 2
mov    eax, 0x00000004   ; syscall write
int    0x80              ; return errno em eax.
jmp prompt

arg_over:
mov    edx, erro_arg_over_len      ; quantidade de bytes da string
mov    ecx, erro_arg_over          ; endereço da string
mov    ebx, 0x00000001   ; file descriptor ; stdout = 1 ; err = 2
mov    eax, 0x00000004   ; syscall write
int    0x80              ; return errno em eax.
jmp prompt

fim:
; return 8;
mov    ebx, 0x00000008   ; error_code
mov    eax, 0x000000fc   ; syscall exit_group ; 252
int    0x80              ; 



ps1:
db '0 '
ps1_len  equ	$ - ps1

erro_in_over:
db 'ERRO: A entrada foi maior que 202 bytes', 0x0A
erro_in_over_len  equ	$ - ps1

erro_arg_over:
db 'ERRO: A quantidade de argumentos passou de 10', 0x0A
erro_arg_over_len  equ	$ - ps1

argv:
times 0x0B dd 0x00000000

envp:
dd 0x00000000

comando:
times 0xCA db 0x00  ; 0xCA = 202
comando_len  equ	$ - comando

loadsize equ $ - $$
%endif

