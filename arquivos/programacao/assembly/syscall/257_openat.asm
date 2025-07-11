# clear ; rm -f ./257_openat.elf ; as --64 -n -o 257_openat.o 257_openat.asm && objcopy -O binary 257_openat.o 257_openat.elf && rm 257_openat.o && chmod +x 257_openat.elf && strace -v -f -i ./257_openat.elf 257_openat.elf

# sys_openat(int dfd, const char __user *filename, int flags, umode_t mode);

.set AT_FDCWD, -100   # indicate openat should use the current working directory.

.include "0_ehdr.asm"

data_i:
data_f:

text_i:
mov    r10, 0x0000000000000000  # mode
mov    rdx, 0x0000000000000000  # flags RONLY = 0x00, WONLY = 0x01, RDWR = 0x02
mov    rsi, [rsp + 0x10]        # filename
mov    rdi, AT_FDCWD            # dfd
mov    rax, 0x0000000000000101  # syscall openat
syscall                         # return fd em eax.

mov    rdi, 0x0000000000000001  # valor a ser retornado
mov    rax, 0x00000000000000e7  # syscall exit_group
syscall
text_f:


