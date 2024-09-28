# clear ; rm -f ./050_listen ; (unset TERM ORBIT_SOCKETDIR SSH_AGENT_PID GPG_AGENT_INFO SHELL XDG_SESSION_COOKIE GTK_RC_FILES WINDOWID GTK_MODULES USER LS_COLORS GNOME_KEYRING_SOCKET SSH_AUTH_SOCK SESSION_MANAGER USERNAME DESKTOP_SESSION GDM_XSERVER_LOCATION PWD LANG GDM_LANG GDMSESSION HISTCONTROL SHLVL HOME GNOME_DESKTOP_SESSION_ID LOGNAME XDG_DATA_DIRS DBUS_SESSION_BUS_ADDRESS LESSOPEN WINDOWPATH LESSCLOSE RUNNING_UNDER_GDM XAUTHORITY DISPLAY COLORTERM _ ; PATH=/bin:/usr/bin ; as --64 -n -O0 -o 050_listen.o 050_listen.asm && objcopy -O binary 050_listen.o 050_listen && rm 050_listen.o && chmod +x 050_listen && ./050_listen ; echo $? && strace -f -i ./050_listen)

.include "0_ehdr.asm"

yes = yes_i - ehdr + 0x400000
sockaddr = sockaddr_i - ehdr + 0x400000

text_i:

# socket(PF_INET,SOCK_STREAM,IPPROTO_IP);
# definida em net/socket.c
mov    rdx, 0x00000006   # IPPROTO_IP
mov    rsi, 0x00000001   # SOCK_STREAM
mov    rdi, 0x00000002   # PF_INET
mov    rax, 0x00000029   # syscall socket # 41
syscall


mov    r9, rax # fd

# setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &yes, sizeof(yes));
mov    r8, 4             # sizeof(yes)
mov    r10, yes          # &yes
mov    rdx, 0x00000002   # SO_REUSEADDR
mov    rsi, 0x00000001   # SOL_SOCKET
mov    rdi, rax          # fd
mov    rax, 0x00000036   # syscall setsockopt # 54
syscall


# bind(3, {sa_family=0x2 /* AF_INET */, sin_port="\x23\x82" /* htons(9090) */, sin_addr="\x00\x00\x00\x00" /* inet_addr("0.0.0.0") */}, 16) = 0
# bind(3, {sa_family=AF_INET, sin_port=htons(8080), sin_addr=inet_addr("127.0.0.1")}, 16) = 0
mov    rdx, 16           # sizeof(sockaddr)
mov    rsi, sockaddr     # &sockaddr
mov    rdi, r9           # fd
mov    rax, 0x00000031   # syscall bind # 49
syscall


# listen(3, 1) // socket fd 3, 1 conexões
mov    rsi, 1            # 
mov    rdi, r9           # fd
mov    rax, 0x00000032   # syscall bind # 50
syscall


mov    rdi, 0x00000009  # valor a ser retornado
mov    rax, 0x000000e7  # syscall exit_group
syscall

.align 0x1000, 0x00
text_f:



data_i:
yes_i:
.long 0x00000001

sockaddr_i:
sa_family:  .word 0x0002      # PF_INET
sin_port:   .word 0x901F      # htons(8080)
sin_addr:   .long 0x00000000  #  0x0100007F  # inet_addr("127.0.0.1")
.rept 8     .byte 0x00
.endr

.align 0x1000, 0x00
data_f:
