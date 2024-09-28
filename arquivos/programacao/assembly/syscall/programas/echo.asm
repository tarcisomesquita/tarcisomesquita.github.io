# clear ; rm -f ./echo && as --64 -n -o echo.o echo.asm && objcopy -O binary echo.o echo && rm echo.o && chmod +x ./echo && ./echo " 12 12 12"; echo $? && strace -f -i ./echo " 12 12 12"

.include "0_ehdr.asm"

# main(int argc, char **argv)
# argc    = [ESP]
# argv[0] = [ESP + 0x08]
# argv[1] = [ESP + 0x10]

text_i:
push   rbp
mov    rbp, rsp

mov    r12, [rbp+0x08]  # argc
mov    rbx, rbp  
add    rbx, 0x10        # argv[0]

write:
cmp    r12, 1
je     fim

add    rbx, 0x08        # próximo argv[]

push   [rbx]
call   strlen
pop    rdx

mov    rdi, 0x00000001          # file descriptor ; stdout = 1 ; err = 2
mov    rsi, [rbx]               # endereço da string
mov    rax, 0x00000001          # syscall write
syscall                         # return errno em eax.

dec    r12
loop   write

fim:
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
.align 0x10, 0x00
data_f:

# -n     do not output the trailing newline
# -e     enable interpretation of backslash escapes
# \\     backslash
# \n     new line
# \r     carriage return
# \t     horizontal tab
# --help display this help and exit
# \xHH   byte with hexadecimal value HH

