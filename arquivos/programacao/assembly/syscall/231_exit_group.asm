# clear ; rm -f ./231_exit_group && as --64 -n -o 231_exit_group.o 231_exit_group.asm && objcopy -O binary 231_exit_group.o 231_exit_group && rm 231_exit_group.o && chmod +x 231_exit_group && ./231_exit_group ; echo $? && strace -f -i ./231_exit_group

.include "0_ehdr.asm"

text_i:
mov    rdi, 0x0000000000000007  # valor a ser retornado
mov    eax, 0x000000e7          # syscall exit_group
syscall
.align 0x10, 0x90
text_f:

data_i:
data_f:

# exit all threads in a process
# terminates not only the calling thread, but all threads in the calling process’s thread group.

