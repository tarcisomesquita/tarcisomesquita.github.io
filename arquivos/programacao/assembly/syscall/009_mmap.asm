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

# man 2 mmap

# void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset);

# If 'addr' is NULL, then the kernel chooses the virtual address at which to create the mapping.

# The contents of a file mapping are initialized using 'length' bytes starting at 'offset' in the file referred to by the file descriptor 'fd'.
# offset must be a multiple of the page size (4kiB), but 'length' need not be.

# The 'prot' argument describes the desired memory protection of the mapping (and must not conflict with the open mode of the file)
# PROT_EXEC  Pages may be executed.
# PROT_READ  Pages may be read.
# PROT_WRITE Pages may be written.
# PROT_NONE  Pages may not be accessed.

# The 'flags' argument determines whether updates to the mapping are visible to other processes mapping the same region
# MAP_SHARED
#   Share  this  mapping.   Updates  to the mapping are visible to other processes mapping the same region, and (in the case of file-backed mappings) are carried through to the underlying file.  (To precisely control when updates are carried through to the underlying file requires the use of msync(2).)
# MAP_PRIVATE
#   Create a private copy-on-write mapping.  Updates to the mapping are not visible to other processes mapping the same file, and are not carried through to the underlying file.
# MAP_ANONYMOUS
#   The mapping is not backed by any file; its contents are initialized to zero.  The fd argument is ignored; however, some implementations require fd to be -1. The offset argument should be zero.  The use of MAP_ANONYMOUS in conjunction with MAP_SHARED is supported.
# MAP_FIXED
# Don't interpret addr as a hint: place the mapping at exactly that address.  addr must be a multiple of the page size.  If the memory region specified by addr and len overlaps pages of any existing mapping(s), then the overlapped part of the existing mapping(s) will be discarded.  If  the  specified address cannot be used, mmap() will fail.  Because requiring a fixed address for a mapping is less portable, the use of this option is discouraged.
# MAP_NORESERVE
#   Do not reserve swap space for this mapping.  When swap space is reserved, one has the guarantee that it is possible to modify the mapping.  When swap space is not reserved one might get SIGSEGV upon a write if no physical memory is available
# MAP_UNINITIALIZED
# Don't clear anonymous pages. This flag is intended to improve performance on embedded devices. This flag is honored only if the kernel was configured with the CONFIG_MMAP_ALLOW_UNINITIALIZED option. Have security implications.

# Memory mapped by mmap() is preserved across fork(2), with the same attributes.

# A file is mapped in multiples of the page size.  For a file that is not a multiple of the page size, the remaining memory is zeroed when mapped, and  writes to  that  region are not written out to the file.

# On  success,  mmap()  returns a pointer to the mapped area.  On error, the value MAP_FAILED (that is, (void *) -1) is returned, and errno is set to indicate the cause of the error. (veja lista de erros em man 2 mmap)












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

