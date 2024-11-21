# clear ; rm -f ./clear && as --64 -n -o clear.o clear.asm && objcopy -O binary clear.o clear && rm clear.o && chmod +x clear && ./clear ; echo $? && strace -f -i ./clear

.include "0_ehdr.asm"

msg = msg_i - ehdr + 0x400000

text_i:
mov    rdi, 0x00000001          # file descriptor ; stdout = 1 ; err = 2
mov    rsi, msg                 # endereço da string
mov    rdx, msg_f - msg_i       # quantidade de bytes da string
mov    rax, 0x00000001          # syscall write
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000000  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall
.align 0x10, 0x90
text_f:

data_i:
msg_i:
.ascii "\33[3;J\33[H\33[2J"
msg_f:

.align 0x10, 0x00
data_f:

