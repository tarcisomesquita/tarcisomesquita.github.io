# clear ; rm -f ./teste_instrucoes ; as --64 -n -o teste_instrucoes.o teste_instrucoes.asm && objcopy -O binary teste_instrucoes.o teste_instrucoes && rm teste_instrucoes.o && chmod +x teste_instrucoes && ./teste_instrucoes | hexdump -C

.include "000_ehdr.asm"

tt  = text_i - ehdr   + 0x400000

text_i:
mov    rax, text_f - ehdr + 0x400000
mov    rax,0x0102030405060708
mov    eax,0x11223344
mov    esi, 0x00401000  # endereço da memória
mov    QWORD PTR [esi], rax

mov    edx, 0x00000008  # quantidade de bytes da string
mov    esi, 0x00401000  # endereço da string
mov    edi, 0x00000001  # file descriptor ; stdout = 1 ; err = 2
mov    eax, 0x00000001  # syscall write
syscall                 # return errno em eax.

mov    edi, 0x00000001  # valor a ser retornado
mov    eax, 0x000000e7  # syscall exit_group
syscall
.align 0x1000, 0x90
text_f:

data_i:
.byte 0x54
.align 0x10, 0x00
data_f:

# return 	eax 	no. of sent bytes (if POSIX conforming f.s.)
# errors 	eax 	EAGAIN, EBADF, EFAULT, EINTR, EINVAL, EIO, ENOSPC, EPIPE

