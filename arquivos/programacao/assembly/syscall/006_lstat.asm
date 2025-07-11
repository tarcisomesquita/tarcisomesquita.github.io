# clear ; rm -f ./006_lstat.elf && as --64 -n -o 006_lstat.o 006_lstat.asm && objcopy -O binary 006_lstat.o 006_lstat.elf && rm 006_lstat.o && chmod +x 006_lstat.elf && strace -f -i ./006_lstat.elf 006_lstat.elf

.include "0_ehdr.asm"

struct = struct_i - ehdr + 0x400000
file = file_i - ehdr + 0x400000

# lstat("./004_stat", {st_dev=0x803 /* makedev(0x8, 0x3) */, st_ino=262339, st_mode=0100775 /* S_IFREG|0775 */, st_nlink=1, st_uid=999, st_gid=999, st_blksize=4096, st_blocks=8, st_size=416, st_atime=1623783656 /* 2021-06-15T19:00:56.118265467+0000 */, st_atime_nsec=118265467, st_mtime=1623783656 /* 2021-06-15T19:00:56.114265467+0000 */, st_mtime_nsec=114265467, st_ctime=1623783656 /* 2021-06-15T19:00:56.114265467+0000 */, st_ctime_nsec=114265467}) = 0

text_i:
mov    rsi, struct              # struct
#mov    rdi, [rsp + 0x10]        # nome do arquivo
mov    rdi, file        # nome do arquivo
mov    rax, 0x00000006          # syscall lstat
syscall

#mov    rdx, 144  # quantidade de bytes da string
#mov    rsi, struct              # endereço da string
#mov    rdi, 1                   # file descriptor ; stdout = 1 ; err = 2
#mov    rax, 0x0000000000000001  # syscall write
#syscall                         # return errno em eax.

#mov     r9, 0x0000000000000000  # offset
#mov     r8, 0xFFFFFFFFFFFFFFFF  # fd
#mov    r10, 0x0000000000000022  # flags  MAP_PRIVATE|MAP_ANONYMOUS
#mov    rdx, 0x0000000000000003  # prot   PROT_READ|PROT_WRITE
#mov    rsi, [struct + 0x30]     # length 1 GiB = 1073741824
#mov    rdi, 0x0000000000000000  # *addr
#mov    rax, 0x0000000000000009  # syscall mmap
#syscall                         # return errno em eax.

mov    rdi, 0x0000000000000001  # valor a ser retornado
mov    rax, 0x00000000000000e7  # syscall exit_group
syscall
text_f:


data_i:
struct_i: .rept 144; .byte 0x00; .endr

file_i:
.byte "006_lstat.elf", 0x00;
data_f:
