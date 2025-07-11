
; Para compilar
; $ nasm -f elf hello.asm -o hello.o

; para linkar
; $ ld -s -o hello.elf hello.o # pacote binutils-x86-64-linux-gnu

section .text	  ; section declaration

global _start	  ; export the entry point
_start:

; write our string to stdout
mov     edx,len ;third argument: message length
mov     ecx,msg ;second argument: pointer to message to write
mov     ebx,1   ;first argument: file handle (stdout)
mov     eax,4   ;system call number (sys_write)
int     0x80	;call kernel

; exit
mov	ebx,0	;first syscall argument: exit code
mov     eax,1   ;system call number (sys_exit)
int     0x80	;call kernel

section .data   ; section declaration

msg     db      "Hello, world!",0xa	  ; our string
len     equ     $ - msg               ; length of our string
