# clear ; rm -f ./load && as --64 -n -o load.o load.asm && objcopy -O binary load.o load && rm load.o && chmod +x load && strace -f -i ./load

.include "0_ehdr.asm"
.set AT_FDCWD, -100   # indicate openat should use the current working directory.

struct = struct_i - ehdr + 0x400000

text_i:
mov    r10, 0x0000000000000000  # mode
mov    rdx, 0x0000000000000000  # flags RONLY = 0x00, WONLY = 0x01, RDWR = 0x02
mov    rsi, [rsp + 0x10]        # filename
mov    rdi, AT_FDCWD            # dfd
mov    rax, 0x0000000000000101  # syscall openat
syscall                         # return fd em eax.

mov    r12, rax

mov    rsi, struct              # statbuf
mov    rdi, r12                 # fd
mov    rax, 0x0000000000000005  # syscall fstat
syscall

mov     r9, 0x0000000000000000  # offset
mov     r8, 0xFFFFFFFFFFFFFFFF  # fd
mov    r10, 0x0000000000000022  # flags  MAP_PRIVATE|MAP_ANONYMOUS
mov    rdx, 0x0000000000000003  # prot   PROT_READ|PROT_WRITE
mov    rsi, [struct + 0x30]     # length 1 GiB = 1073741824
mov    rdi, 0x0000000000000000  # *addr
mov    rax, 0x0000000000000009  # syscall mmap
syscall                         # return offset em eax.

mov    rdx, [struct + 0x30]     # quantidade de bytes
mov    rsi, rax                 # endereço do buf
mov    rdi, r12                 # file descriptor ; stdout = 1 ; err = 2
mov    rax, 0x0000000000000000  # syscall read
syscall                         # return errno em eax.

mov    rdi, r12
mov    rax, 0x00000003           # syscall close
syscall

mov    rdi, 0x0000000000000000   # valor a ser retornado
mov    rax, 0x000000e7           # syscall exit_group
syscall

.align 0x10, 0x90
text_f:

data_i:
struct_i: .rept 144; .byte 0x00; .endr 
.align 0x10, 0x00

data_f:

