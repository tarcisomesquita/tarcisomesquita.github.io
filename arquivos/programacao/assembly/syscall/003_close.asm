# clear ; rm -f ./003_close ; as --64 -n -o 003_close.o 003_close.asm && objcopy -O binary 003_close.o 003_close && rm 003_close.o && chmod +x 003_close && ./003_close ; echo $? && strace -f -i -X verbose ./003_close

.include "0_ehdr.asm"

text_i:
mov    rdi, 0x0000000000000001  # file descriptor;  0 = stdin, 1 = stdout, 2 = stderr
mov    rax, 0x00000003          # syscall close
syscall

mov    rdi, 0x0000000000000007  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall
.align 0x1000, 0x90
text_f:

data_i:
data_f:

