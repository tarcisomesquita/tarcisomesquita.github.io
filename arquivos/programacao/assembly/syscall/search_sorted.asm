# clear ; rm -f ./search_sorted.elf && as --64 -n -o search_sorted.o search_sorted.asm && objcopy -O binary search_sorted.o search_sorted.elf && rm search_sorted.o && chmod +x search_sorted.elf && strace -v -f -i ./search_sorted.elf search_sorted.elf

# clear ; rm -f ./search_sorted.elf && as --64 -n -o search_sorted.o search_sorted.asm && objcopy -O binary search_sorted.o search_sorted.elf && rm search_sorted.o && chmod +x search_sorted.elf && strace -v -f -i ./search_sorted.elf search_sorted.elf | hexdump -C

.set AT_FDCWD, -100   # indicate openat should use the current working directory.

.include "0_ehdr.asm"

struct = struct_i - ehdr + 0x400000
fd     = fd_i     - ehdr + 0x400000
fm     = fm_i     - ehdr + 0x400000
rmd    = rmd_i    - ehdr + 0x400000

data_i:
struct_i: .rept 144; .byte 0x00; .endr 
fd_i:  .quad 0x0000000000000000
fm_i:  .quad 0x0000000000000000
rmd_i: .quad 0x0000000000000000
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

mov    [fm], rax

mov    rdx, [struct + 0x30]     # file lenght
mov    rsi, [fm]                # endereço do buf
mov    rdi, [fd]                # file descriptor ;
mov    rax, 0x0000000000000000  # syscall read
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000001  # valor a ser retornado
mov    rax, 0x00000000000000e7  # syscall exit_group
syscall
text_f:

