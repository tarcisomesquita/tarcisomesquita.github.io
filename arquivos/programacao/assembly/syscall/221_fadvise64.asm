# clear ; rm -f ./221_fadvise64.elf && as --64 -n -o 221_fadvise64.o 221_fadvise64.asm && objcopy -O binary 221_fadvise64.o 221_fadvise64.elf && rm 221_fadvise64.o && chmod +x 221_fadvise64.elf && strace -v -f -i ./221_fadvise64.elf 221_fadvise64.elf

# long sys_fadvise64(int fd, loff_t offset, size_t len, int advice);

.set AT_FDCWD, -100   # indicate openat should use the current working directory.

.include "0_ehdr.asm"

struct = struct_i - ehdr + 0x400000
fd = fd_i - ehdr + 0x400000

data_i:
struct_i: .rept 144; .byte 0x00; .endr 
fd_i: .quad 0x0000000000000000
data_f:

text_i:
mov    r10, 0x0000000000000000  # mode
mov    rdx, 0x0000000000000000  # flags RONLY = 0x00, WONLY = 0x01, RDWR = 0x02
mov    rsi, [rsp + 0x10]        # filename
mov    rdi, AT_FDCWD            # dfd
mov    rax, 0x0000000000000101  # syscall openat
syscall                         # return fd em eax.

mov    [fd],eax

mov    rsi, struct              # struct
mov    rdi, [fd]                # fd
mov    rax, 0x0000000000000005  # syscall fstat
syscall

.set POSIX_FADV_SEQUENTIAL,2    #  Expect sequential page references

# long sys_fadvise64(int fd, loff_t offset, size_t len, int advice);

mov    r10, 0x0000000000000002  # advice   POSIX_FADV_SEQUENTIAL
mov    rdx, 0x0000000000000000  # len
mov    rsi, 0x0000000000000000  # offset
mov    rdi, [fd]                # fd
mov    rax, 0x00000000000000DD  # syscall fadvise64
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


