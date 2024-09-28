# clear ; rm -f ./061_wait && as --64 -n -o 061_wait.o 061_wait.asm && objcopy -O binary 061_wait.o 061_wait && rm 061_wait.o && chmod +x 061_wait && ./061_wait ; echo $? && strace -f -i ./061_wait

.include "0_ehdr.asm"

# long sys_wait4(pid_t pid, int *stat_addr, int options, struct rusage *ru)

text_i:
mov    r10, 0x0000000000000000  # 
mov    rdx, 0x0000000000000000  # 
mov    rsi, 0x0000000000000000  # 
mov    rdi, 4590                # child PID
mov    rax, 0x0000003D          # syscall wait
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000001  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall
.align 0x10, 0x90
text_f:

data_i:

.align 0x10, 0x00
data_f:

