# clear ; rm -f ./085_creat && as --64 -n -o 085_creat.o 085_creat.asm && objcopy -O binary 085_creat.o 085_creat && rm 085_creat.o && chmod +x 085_creat && ./085_creat ; echo $? && strace -f -i ./085_creat

.include "0_ehdr.asm"

# CUIDADO apaga o arquivo anterior sem avisar

# long sys_creat(char *pathname, umode_t mode)

file = file_i - ehdr + 0x400000

text_i:
mov    rsi, 00644        # arg2  # Read/write permissions in octal (rw_rw_rw_)
mov    rdi, file         # arg0
mov    rax, 0x00000055   # syscall creat
syscall

mov    rdi, rax
mov    rax, 0x00000003          # syscall close
syscall

mov    rdi, 0x0000000000000007  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall
.align 0x10, 0x90
text_f:

data_i:
file_i:
.string "teste_scratch.txt"
data_f:

