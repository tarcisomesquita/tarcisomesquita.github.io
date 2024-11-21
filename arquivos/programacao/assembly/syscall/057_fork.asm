# clear ; rm -f ./057_fork && as --64 -n -o 057_fork.o 057_fork.asm && objcopy -O binary 057_fork.o 057_fork && rm 057_fork.o && chmod +x 057_fork && ./057_fork ; echo $? && strace -f -i ./057_fork

.include "0_ehdr.asm"

# long sys_fork(void)

text_i:
mov    rax, 0x0000000000000039  # syscall fork
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000001  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall
.align 0x10, 0x90
text_f:

data_i:

.align 0x10, 0x00
data_f:

