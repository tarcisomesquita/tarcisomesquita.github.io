# clear ; rm -f ./strlen && as --64 -n -o strlen.o strlen.asm && objcopy -O binary strlen.o strlen && rm strlen.o && chmod +x strlen && ./strlen ; echo $? && strace -f -i ./strlen && ./strlen | hexdump -C

.include "0_ehdr.asm"

msg = msg_i - ehdr + 0x400000

text_i:
push   msg
call   strlen

mov    rdi, 0x00000001          # file descriptor ; stdout = 1 ; err = 2
mov    rsi, rsp                 # endereço da string
mov    rdx, 8                   # quantidade de bytes da string
mov    rax, 0x00000001          # syscall write
syscall                         # return errno em eax.


mov    rdi, 0x0000000000000000  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall

# input: endereço da string em [rsp+8]
# output: tamanho da string em [rsp+8]
# não altera nenhum registrador
strlen:
push   rbp
mov    rbp, rsp
push   rax
push   rcx
push   rdi
mov    ax, es
push   rax
       
mov    ax, ds
mov    es, ax
mov    rdi, [rbp+16]
mov    rcx, 0x000000010000000  # tamanho máximo + 1 = 4 GiB
mov    al, 0x00
cld    
repne  scasb
mov    rax, [rbp+16]
sub    rdi, rax
dec    rdi
mov    [rbp+16], rdi

pop    rax
mov    es, ax
pop    rdi
pop    rcx
pop    rax
pop    rbp
ret

.align 0x10, 0x90
text_f:

data_i:
msg_i:
.string " 12 12 12"
msg_f:

.align 0x10, 0x00
data_f:

# return 	eax 	no. of sent bytes (if POSIX conforming f.s.)
# errors 	eax 	EAGAIN, EBADF, EFAULT, EINTR, EINVAL, EIO, ENOSPC, EPIPE

