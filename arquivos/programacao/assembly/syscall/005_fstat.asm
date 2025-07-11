# clear ; rm -f ./005_fstat.elf && as --64 -n -o 005_fstat.o 005_fstat.asm && objcopy -O binary 005_fstat.o 005_fstat.elf && rm 005_fstat.o && chmod +x 005_fstat.elf && strace -v -f -i ./005_fstat.elf 005_fstat.elf

# long sys_fstat(unsigned int fd, struct __old_kernel_stat __user *statbuf);

.set AT_FDCWD, -100   # indicate openat should use the current working directory.

.include "0_ehdr.asm"

struct = struct_i - ehdr + 0x400000

data_i:
struct_i: .rept 144; .byte 0x00; .endr 
data_f:

text_i:
mov    r10, 0x0000000000000000  # mode
mov    rdx, 0x0000000000000000  # flags RONLY = 0x00, WONLY = 0x01, RDWR = 0x02
mov    rsi, [rsp + 0x10]        # filename
mov    rdi, AT_FDCWD            # dfd
mov    rax, 0x0000000000000101  # syscall openat
syscall                         # return fd em eax.

mov    rsi, struct              # statbuf
mov    rdi, rax                 # fd
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

mov    rdi, 0x0000000000000001  # valor a ser retornado
mov    rax, 0x00000000000000e7  # syscall exit_group
syscall
text_f:


