   .code32
   .text

// int console_getkey (void)
// "INT 16H Function 00H" to read character from keyboard
//  Return:      %ah = keyboard scan code
//         %al = ASCII character

.globl console_getkey
console_getkey:
   push   %ebp
   
   call   prot_to_real
   .code16
   
   int   $0x16

   data32   call   real_to_prot
   .code32
   
   pop   %ebp
   ret

