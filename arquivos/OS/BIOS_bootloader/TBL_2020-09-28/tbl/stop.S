   .align 4

   .code32
   .text

.globl stop
stop:

// byte ordering of this intructions on the x86 to work in either 16-bit or 32-bit
hard_stop:
   hlt
   jmp hard_stop

