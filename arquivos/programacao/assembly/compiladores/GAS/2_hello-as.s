# as 2_hello-as.s -o 2_hello-as.o && ld -s 2_hello-as.o -o 2_hello-as.elf && ./2_hello-as.elf ; echo $?

.intel_syntax noprefix

.data   # section declaration
msg:
   .ascii   "Hello, world!\n"   # our dear string
   len = . - msg         # length of our dear string

.text   # section declaration

.global _start   # ld conventionally recognize _start as entry point. Use ld -e foo to override the default.
_start:

# write our string to stdout
   mov   edx, len   # third argument: message length
   mov   ecx, OFFSET FLAT:msg   # second argument: pointer to message to write
   mov   ebx, 1     # first argument: file handle (stdout)
   mov   eax, 4     # system call number (sys_write)
   int   0x80       # call kernel

# and exit
   mov   ebx, 9      # first argument: exit code
   mov   eax, 1      # system call number (sys_exit)
   int   0x80        # call kernel


