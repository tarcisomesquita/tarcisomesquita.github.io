
write the integer contents of a register to a text file in ARM Assembly.

Example :
.global main
.func main

main:
    mov r1, #19
    mov r2, #11
    add r0, r1, r2
    bx lr
In the above case, r0 would hold the value 30. I want to write that value to a text file.



$ as open_e.s -o open_e.o
$ ld open_e.o -o open_e
$ cat open_e.s
.global _start

_start:
@open syscall 
ldr r0, =filename
mov r1, #0101 @ O_WRONLY | O_CREAT
ldr r2, =0666 @ permissions
mov r7, #5 @ 5 is system call number for open
svc #0
cmp r0, #0
blt exit

@r0 contains fd (file descriptor, an integer)
mov r5, r0

@write syscall
@use stack as buffer
sub sp, #8 @ stack is full descending, this is how we leave some space
mov r1, #'4'
strb r1, [sp]
mov r1, #'2'
strb r1, [sp, #1]
mov r1, #'\n'
strb r1, [sp, #2]
mov r1, sp
mov r2, #3
mov r7, #4 @ 4 is write
svc #0

@fsync syscall
mov r0, r5
mov r7, #118
svc #0

@close syscall
mov r7, #6 @ 6 is close
svc #0

exit:
mov r0, #0
mov r7, #1
svc #0

.data
.align 2
filename: .asciz "out.txt"

