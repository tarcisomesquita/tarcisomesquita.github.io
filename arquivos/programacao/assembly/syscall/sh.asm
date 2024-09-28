# clear ; rm -f ./sh && as --64 -n -o sh.o sh.asm && objcopy -O binary sh.o sh && rm sh.o && chmod +x sh && ./sh ./echo  "cada macaco" " no seu" " galho"; echo $? && strace -f -i ./sh ./echo "cada macaco" " no seu" " galho"

.include "0_ehdr.asm"

# long sys_execve(char *filename, char **argv, char **envp);

cmd  = cmd_i  - ehdr + 0x400000
argv = argv_i - ehdr + 0x400000
envp = envp_i - ehdr + 0x400000

text_i:
push   rbp
mov    rbp, rsp

mov    r12, [rbp+0x08]  # argc
mov    rbx, rbp  
add    rbx, 0x18        # argv[1]

mov    rdx, envp                # 
mov    rsi, rbp                 # 
add    rsi, 0x18                # 
mov    rdi, [rbp+0x18]          # 
mov    rax, 0x0000003B          # syscall execve
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000003  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall
.align 0x10, 0x90
text_f:

data_i:
arg1:    .string "argumento1"
arg2:    .string "argumento1"
var_amb: .string "VAR_AMB=teste"
cmd_i:   .string "./echo"
argv_i:  .quad   arg1, arg2, 0x0000000000000000
envp_i:  .quad   0x0000000000000000

.align 0x10, 0x00
data_f:

