# clear ; rm -f ./000_mmap && as --64 -n -o 000_mmap.o 000_mmap.asm && objcopy -O binary 000_mmap.o 000_mmap && rm 000_mmap.o && chmod +x 000_mmap && ./000_mmap ; echo $? && strace -f -i ./000_mmap

.include "0_ehdr.asm"

#include <sys/mman.h>
# void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

# Alocar 1 GiB = 1073741824
# mmap(NULL, 1073741824, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f77c63e2000

# Realocar para 1,5 GiB = 1610612736
# mremap(0x7f77c63e2000, 1073741824, 1610612736, MREMAP_MAYMOVE) = 0x7f77c63e2000

# Liberar a memória
#munmap(0x7f77c63e2000, 1610612736) = 0


buf = buf_i - ehdr + 0x400000
text_i:
mov     r9, 0x0000000000000000  # offset
mov     r8, 0xFFFFFFFFFFFFFFFF  # fd
mov    r10, 0x0000000000000022  # flags  MAP_PRIVATE|MAP_ANONYMOUS
mov    rdx, 0x0000000000000003  # prot   PROT_READ|PROT_WRITE
mov    rsi, 0x0000000040000000  # length 1 GiB = 1073741824
mov    rdi, 0x0000000000000000  # *addr
mov    rax, 0x0000000000000009  # syscall mmap
syscall                         # return errno em eax.

mov    rbx, rax

mov    r10, 0x0000000000000001  # flags   MREMAP_MAYMOVE
mov    rdx, 0x0000000060000000  # new_len 1,5 GiB
mov    rsi, 0x0000000040000000  # old_len 1,5 GiB
mov    rdi, rbx                 # *addr
mov    rax, 0x0000000000000019  # syscall mremap
syscall                         # return errno em eax.

mov    rbx, rax

mov    rsi, 0x0000000060000000  # length 1 GiB = 1073741824
mov    rdi, rbx                 # *addr
mov    rax, 0x000000000000000B  # syscall munmap
syscall                         # return errno em eax.

mov    rdx, buf_f - buf_i       # quantidade de bytes
mov    rsi, buf                 # endereço do buf
mov    rdi, 0x0000000000000000  # file descriptor ; stdout = 1 ; err = 2
mov    rax, 0x0000000000000000  # syscall read
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000001  # valor a ser retornado
mov    rax, 0x00000000000000e7  # syscall exit_group
syscall
.align 0x10, 0x90
text_f:

data_i:
buf_i:
.rept 15 .byte 0x00 ; .endr
buf_f:

.align 0x10, 0x00
data_f:

# Map addresses starting near ADDR and extending for LEN bytes.
# From OFFSET into the file FD describes according to PROT and FLAGS.
# If ADDR is nonzero, it is the desired mapping address.
# If the MAP_FIXED bit is set in FLAGS, the mapping will be at ADDR exactly (which must be page-aligned); otherwise the system chooses a convenient nearby address.
# The return value is the actual mapping address chosen or MAP_FAILED for errors (in which case `errno' is set).  A successful `mmap' call deallocates any previous mapping for the affected region.


# Alocar 1 GiB = 1073741824
# mmap(NULL, 1073745920, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0) = 0x7f1440081000
# 
# Realocar para 1,5 GiB = 1610612736
# mremap(0x7f1440081000, 1073745920, 1610616832, MREMAP_MAYMOVE) = 0x7f1440081000
# 
# Liberar a memória
# munmap(0x7f1440081000, 1610616832)      = 0
# 
# 1073745920 = 1073741824 + 4096 
# 
# 
# #define PROT_READ    0x1   // page can be read
# #define PROT_WRITE   0x2   // page can be written
# #define PROT_EXEC    0x4   // page can be executed
# #define PROT_SEM     0x8   // page may be used for atomic ops
# #define PROT_NONE    0x0   // page can not be accessed
# 
# #define MAP_SHARED      0x01   // Share changes
# #define MAP_PRIVATE     0x02   // Changes are private
# #define MAP_TYPE        0x0f   // Mask for type of mapping
# #define MAP_FIXED       0x10   // Interpret addr exactly
# #define MAP_ANONYMOUS   0x20   // don't use a file
# 
# #define MREMAP_MAYMOVE   1
# #define MREMAP_FIXED   2

