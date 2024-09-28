# clear ; rm -f ./035_nanosleep && as --64 -n -o 035_nanosleep.o 035_nanosleep.asm && objcopy -O binary 035_nanosleep.o 035_nanosleep && rm 035_nanosleep.o && chmod +x 035_nanosleep && ./035_nanosleep ; echo $? && strace -f -i ./035_nanosleep

.include "0_ehdr.asm"

# long sys_nanosleep(struct timespec *rqtp, struct timespec *rmtp);

time = timespec - ehdr + 0x400000

text_i:
mov    rsi, 0x00000000                # struct timespec *rmtp   ; este valor também pode ser 0x00000000
mov    rdi, time                # struct timespec *rqtp
mov    rax, 0x00000023          # syscall nanosleep
syscall                         # return errno em eax.

mov    rdi, 0x0000000000000002  # valor a ser retornado
mov    rax, 0x000000e7          # syscall exit_group
syscall
.align 0x10, 0x90
text_f:

data_i:
timespec:
   tv_sec:  .long 0x00000000 # 5 segundos
   tv_nsec: .long 0x00000000
   tv_nsec2: .long 250000000

.align 0x10, 0x00
data_f:

# return 	eax 	no. of sent bytes (if POSIX conforming f.s.)
# errors 	eax 	EAGAIN, EBADF, EFAULT, EINTR, EINVAL, EIO, ENOSPC, EPIPE

