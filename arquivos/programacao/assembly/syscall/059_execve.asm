# clear ; rm -f ./059_execve && as --64 -n -o 059_execve.o 059_execve.asm && objcopy -O binary 059_execve.o 059_execve && rm 059_execve.o && chmod +x 059_execve && ./059_execve ; echo $? && strace -f -i ./059_execve

.include "000_ehdr.asm"

# long sys_execve(char *filename, char **argv, char **envp);

cmd  = cmd_i  - ehdr + 0x400000
argv = argv_i - ehdr + 0x400000
envp = envp_i - ehdr + 0x400000

text_i:
mov    rdx, envp                # 
mov    rsi, argv                # 
mov    rdi, cmd                 # 
mov    rax, 0x0000003B          # syscall execve
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000003  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall
.align 0x1000, 0x90
text_f:

data_i:
arg1:    .string "argumento1"
arg2:    .string "argumento1"
var_amb: .string "VAR_AMB=teste"
cmd_i:   .string "./001_write"
argv_i:  .quad   arg1, arg2, 0x0000000000000000
envp_i:  .quad   var_amb, 0x0000000000000000

.align 0x10, 0x00
data_f:

# return   no return, executed prog inherits resources and overwrites caller
# errors   eax: 2big, acces, inval, io, isdir, libbad loop, nfile, noexec, noent, nomem, notdir, fault, nametoolong, perm, txtbusy

