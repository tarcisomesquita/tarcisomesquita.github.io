# clear ; rm -f ./001_write && as --64 -n -o 001_write.o 001_write.asm && objcopy -O binary 001_write.o 001_write && rm 001_write.o && chmod +x 001_write && ./001_write ; echo $? && strace -f -i -X verbose ./001_write

.include "000_ehdr.asm"

msg = msg_i - ehdr + 0x400000

text_i:
mov    rdx, msg_f - msg_i       # quantidade de bytes da string
mov    rsi, msg                 # endereço da string
mov    rdi, 0x0000000000000001  # file descriptor ; stdout = 1 ; err = 2
mov    rax, 0x0000000000000001  # syscall write
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000001  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall
.align 0x1000, 0x90
text_f:

data_i:
msg_i:
.string "Hello world\n"
msg_f:

.align 0x10, 0x00
data_f:

# return 	eax 	no. of sent bytes (if POSIX conforming f.s.)
# errors 	eax 	EAGAIN, EBADF, EFAULT, EINTR, EINVAL, EIO, ENOSPC, EPIPE
