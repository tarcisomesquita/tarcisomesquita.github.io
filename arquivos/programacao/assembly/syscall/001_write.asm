# clear ; rm -f ./001_writeb ; as --64 -n -o 001_writeb.o 001_writeb.asm && objcopy -O binary 001_writeb.o 001_writeb && rm 001_writeb.o && chmod +x 001_writeb && ./001_writeb ; echo $? && strace -f -i -X verbose ./001_writeb

.include "000_ehdr.asm"

msg = m_i - ehdr + 0x400000

text_i:
mov    edx, m_f - m_i   # quantidade de bytes da string
mov    esi, msg         # endereço da string
mov    edi, 0x00000001  # file descriptor ; stdout = 1 ; err = 2
mov    eax, 0x00000001  # syscall write
syscall                 # return errno em eax.

mov    edi, 0x00000001  # valor a ser retornado
mov    eax, 0x000000e7  # syscall exit_group
syscall
.align 0x1000, 0x90
text_f:

data_i:
m_i:
.string "Hello world\n"
m_f:

.align 0x10, 0x00
data_f:

# return 	eax 	no. of sent bytes (if POSIX conforming f.s.)
# errors 	eax 	EAGAIN, EBADF, EFAULT, EINTR, EINVAL, EIO, ENOSPC, EPIPE
