# as --64 file2.s -o file2.o

.section .rodata
msg:
.string	"file2: T\n"
len = . - msg

.section .text
.intel_syntax noprefix
.globl	print2
print2:
mov    edx, len               # quantidade de bytes da string
lea	rax, msg[rip]
mov	rsi, rax                  # endereço da string
mov    edi, 0x00000001        # file descriptor ; stdout = 1 ; err = 2
mov    eax, 0x00000001        # syscall write
syscall                       # return errno em eax.
ret
