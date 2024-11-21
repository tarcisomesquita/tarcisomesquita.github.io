# clear ; rm -f ./000_read && as --64 -n -o 000_read.o 000_read.asm && objcopy -O binary 000_read.o 000_read && rm 000_read.o && chmod +x 000_read && ./000_read ; echo $? && strace -f -i -X verbose ./000_read

.include "000_ehdr.asm"

# long sys_read(unsigned int fd, char *buf, size_t count)

buf = buf_i - ehdr + 0x400000

text_i:
mov    rdx, buf_f - buf_i       # quantidade de bytes
mov    rsi, buf                 # endereço do buf
mov    rdi, 0x0000000000000000  # file descriptor ; stdout = 1 ; err = 2
mov    rax, 0x0000000000000000  # syscall read
syscall                         # return errno em eax.

dec    rax
mov    [buf+rax], BYTE PTR 0x00
mov    rdx, rax                 # quantidade de bytes da string
mov    rsi, buf                 # endereço da string
mov    rdi, 0x0000000000000001  # file descriptor ; stdout = 1 ; err = 2
mov    rax, 0x0000000000000001  # syscall write
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000001  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall
.align 0x1000, 0x90
text_f:

data_i:
buf_i:
.rept 15 .byte 0x00
.endr
buf_f:

.align 0x10, 0x00
data_f:
