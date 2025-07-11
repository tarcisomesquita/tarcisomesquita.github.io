.intel_syntax noprefix
.text

.global sair
sair:

   mov   ebx, 3      # first argument: exit code
   mov   eax, 1      # system call number (sys_exit)
   int   0x80        # call kernel

