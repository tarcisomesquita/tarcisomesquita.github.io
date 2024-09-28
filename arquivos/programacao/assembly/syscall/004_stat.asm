# clear ; rm -f ./004_stat && as --64 -n -o 004_stat.o 004_stat.asm && objcopy -O binary 004_stat.o 004_stat && rm 004_stat.o && chmod +x 004_stat && strace -v -f -i -X verbose ./004_stat

.include "0_ehdr.asm"

# stat("stat_64.elf", {st_dev=makedev(0, 22), st_ino=384, st_mode=S_IFREG|0775, st_nlink=1, st_uid=999, st_gid=999, st_blksize=4096, st_blocks=32, st_size=12968, st_atime=2017/04/16-18:34:02.400339877, st_mtime=2017/04/16-18:34:02.416339876, st_ctime=2017/04/16-18:34:02.416339876}) = 0


file = file_i - ehdr + 0x400000
stat = stat_i - ehdr + 0x400000

text_i:
mov    rsi, stat                # struct_stat
mov    rdi, file                # path_to_file
mov    rax, 0x0000000000000004  # syscall stat
syscall                         # return errno em eax.

mov rbx, stat

mov    rdx, 0x0000000000000008  # quantidade de bytes da string
mov    rsi, stat + 42         # endereço da string
mov    rdi, 0x0000000000000001  # file descriptor ; stdout = 1 ; err = 2
mov    rax, 0x0000000000000001  # syscall write
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000001  # valor a ser retornado
mov    rax, 0x00000000000000e7  # syscall exit_group
syscall
.align 0x10, 0x90
text_f:

data_i:

file_i: .string "004_stat.asm"; file_f:
.align 0x10, 0x00
stat_i: .rept 144 .byte 0x00 ; .endr ; stat_f:

data_f:

#16*8 = 80 + 64 = 144

# //#include<time.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
# struct timespec {
#    long int tv_sec;   // Seconds
#    long int tv_nsec;  // Nanoseconds
# };
# 
# 
# //#include<x86_64-linux-gnu/bits/stat.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
# struct stat {
#    unsigned long int st_dev;        // device
#    unsigned long int st_ino;        // 
#    unsigned long int st_nlink;      // Link count.
#    unsigned int st_mode;            // File mode.
#    unsigned int st_uid;             // User ID of the file's owner.
#    unsigned int st_gid;             // Group ID of the file's owner.
#    int __pad0;
#    unsigned long int st_rdev;       // Device number, if device.
#    long int st_size;                // Size of file, in bytes.
#    long int st_blksize;             // Optimal block size for I/O.
#    long int st_blocks;              // Number 512-byte blocks allocated.
#    struct timespec st_atim;         // Time of last access.
#    struct timespec st_mtim;         // Time of last modification.
#    struct timespec st_ctim;         // Time of last status change. (criação)
#    long int __glibc_reserved[3];    // 
# };

