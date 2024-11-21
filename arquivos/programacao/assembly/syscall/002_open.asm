# clear ; rm -f ./002_open ; as --64 -n -o 002_open.o 002_open.asm && objcopy -O binary 002_open.o 002_open && rm 002_open.o && chmod +x 002_open && ./002_open ; echo $? && strace -f -i -X verbose ./002_open

.include "0_ehdr.asm"

# main(int argc, char **argv)
# argc    = [ESP]
# argv[0] = [ESP + 0x04]
# argv[1] = [ESP + 0x08]

# long sys_open(char *filename, int flags, umode_t mode)#

file = file_i - ehdr + 0x400000

text_i:
mov    rdx, 0x00000000   # arg2 # modo
mov    rsi, 0x00000002   # RONLY = 0x00, WONLY = 0x01, RDWR = 0x02
mov    rdi, file         # arg0
mov    rax, 0x00000002   # syscall open
syscall

mov    rdi, rax
mov    rax, 0x00000003          # syscall close
syscall

mov    rdi, 0x0000000000000007  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall
.align 0x1000, 0x90
text_f:

data_i:
file_i:
.string "002_open.asm"

data_f:


# errors eax   ACCESS, EXIST, FAULT, ISDIR, LOOP, MFILE, NAMETOOLONG, NFILE, NOENT, NODEV, NODIR, NOMEM, NOSPC, NXIO, ROFS, TXTBSY
 
# O_CREAT 0100
# O_EXCL 0200
# O_NOCTTY 0400
# O_TRUNC 01000
# O_APPEND 02000
# O_NONBLOCK 04000
# O_NDELAY O_NONBLOCK
# O_SYNC 010000 specific to ext2 fs and block devices
# O_LARGEFILE 0100000
# O_DIRECTORY 0200000 must be a directory
# O_NOFOLLOW 0400000 don't follow links

# file permissions flags 	 
# S_ISUID 04000 set user ID on execution
# S_ISGID 02000 set group ID on execution
# S_ISVTX 01000 sticky bit
# S_IRUSR 00400 read by owner (S_IREAD)
# S_IWUSR 00200 write by owner (S_IWRITE)
# S_IXUSR 00100 execute/search by owner (S_IEXEC)
# S_IRGRP 00040 read by group
# S_IWGRP 00020 write by group
# S_IXGRP 00010 execute/search by group
# S_IROTH 00004 read by others (R_OK)
# S_IWOTH 00002 write by others (W_OK)
# S_IXOTH 00001 execute/search by others (X_OK)

