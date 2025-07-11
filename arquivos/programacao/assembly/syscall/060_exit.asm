# clear ; rm -f ./060_exit && as --64 -n -o 060_exit.o 060_exit.asm && objcopy -O binary 060_exit.o 060_exit && rm 060_exit.o && chmod +x 060_exit && ./060_exit ; echo $? && strace -f -i ./060_exit

.include "0_ehdr.asm"

text_i:
mov    rdi, 0x0000000000000007  # valor a ser retornado
mov    rax, 0x0000003c          # syscall exit
syscall
.align 0x1000, 0x90
text_f:

data_i:
data_f:

