# clear ; rm -f ./sh && as --64 -n -o sh.o sh.asm && objcopy -O binary sh.o sh && rm sh.o && chmod +x sh && strace -f -i ./sh 
# ./echo "cada macaco" " no seu" " galho"

# Implementar isso para o initram
# Lê comandos digitados no prompt
# Executa script contendo um comando por linha

.include "0_ehdr.asm"

# long sys_execve(char *filename, char **argv, char **envp);

argv = argv_i - ehdr + 0x400000
envp = envp_i - ehdr + 0x400000
cmd  = cmd_i  - ehdr + 0x400000
ps1  = ps1_i  - ehdr + 0x400000

text_i:
mov    rcx, 0xCA
mov    rdx, cmd
limpa_cmd:
mov    [rdx], BYTE PTR 0x00
inc    rdx
loop   limpa_cmd
dec    rdx

mov    rcx, 0x0B
mov    rdx, argv
limpa_argv:
mov    [rdx], QWORD PTR 0x0000000000000000
add    rdx, 8
loop   limpa_argv
sub    rdx, 8

mov    rdx, 0x0000000000000002  # quantidade de bytes da string
mov    rsi, ps1                 # endereço da string
mov    rdi, 0x0000000000000001  # file descriptor ; stdout = 1 ; err = 2
mov    rax, 0x0000000000000001  # syscall write
syscall                         # return errno em eax.

mov    rbx, argv                # endereço do próximo argumento
mov    [rbx], QWORD PTR cmd     # o primeiro argumento é o próprio comando
add    rbx, 8

mov    r12, 0                   # conta os bytes lidos

mov    rdx, 1                   # quantidade de bytes
mov    rsi, cmd                 # endereço do buf
mov    rdi, 0x0000000000000000  # file descriptor ; stdout = 1 ; err = 2
entrada:
mov    rax, 0x0000000000000000  # syscall read
syscall                         # return errno em eax.

inc    r12
cmp    r12, cmd_f - cmd_i
ja     entrada_over

cmp    [rsi], BYTE PTR 0x20
jne    nespaco

mov    [rsi], BYTE PTR 0x00
inc    rsi
mov    [rbx], rsi
add    rbx, 8
jmp    entrada

nespaco:
inc    rsi
cmp    [rsi - 1], BYTE PTR 0x0A
jne    entrada

entrada_end:
mov    [rsi - 1], BYTE PTR 0x00

mov    rax, 0x0000000000000039  # syscall fork
syscall                         # return errno em eax.

test   rax,rax
jnz esperar

mov    rdx, envp                # envp
mov    rsi, argv                # argv
mov    rdi, cmd                 # cmd
mov    rax, 0x0000003B          # syscall execve
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000007  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall

jmp fim

esperar:
mov    r10, 0x0000000000000000  # 
mov    rdx, 0x0000000000000000  # 
mov    rsi, 0x0000000000000000  # 
mov    rdi, rax                 # child PID
mov    rax, 0x0000003D          # syscall wait
syscall                         # return errno em eax.
jmp    text_i

erro_in_over = erro_in_over_i - ehdr + 0x400000
entrada_over:
mov    rdx, 41  # quantidade de bytes da string
mov    rsi, erro_in_over        # endereço da string
mov    rdi, 0x0000000000000001  # file descriptor ; stdout = 1 ; err = 2
mov    rax, 0x0000000000000001  # syscall write
syscall                         # return errno em eax.
jmp    text_i


fim:
mov    rdi, 0x0000000000000008  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall
.align 0x10, 0x90

text_f:

data_i:
cmd_i:     .rept 0xCA .byte 0x00               ; .endr ; cmd_f:  # 0xCA = 202
argv_i:    .rept 0x0B .quad 0x0000000000000000 ; .endr
envp_i:    .rept 0x01 .quad 0x0000000000000000 ; .endr

ps1_i:
.byte 0x23, 0x20

erro_in_over_i:
.string "ERRO: A entrada foi maior que 202 bytes\n"

erro_arg_over_i:
.string "ERRO: A quantidade de argumentos passou de 10"

.align 0x10, 0x00
data_f:

