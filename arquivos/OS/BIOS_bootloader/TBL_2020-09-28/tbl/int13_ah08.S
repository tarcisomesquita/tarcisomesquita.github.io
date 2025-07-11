// int int13_ah08(int drive, unsigned int *cylinders, unsigned int *heads, unsigned int *sectors)
// Return the geometry of DRIVE in CYLINDERS, HEADS and SECTORS.
// If an error occurs, then return non-zero, otherwise zero.

   .code32
   .text

.globl int13_ah08
int13_ah08:
   pushl   %ebp
   movl    %esp, %ebp
   
   pushl   %ebx
   pushl   %edi
   
   movb    0x08(%ebp), %dl  // driver
   
   call   prot_to_real
   .code16
   
   movb   $0x08, %ah
   int    $0x13
   
   testb   %ah, %ah
   jnz     1f
   
   testb   $0x3f, %cl       // 0 sectors means no disk
   jnz     1f
   
   movb    $0x60, %ah       // 0x60 is one of the unused error numbers
1:
   movb    %ah, %bl         // save return value in %bl
   
   data32  call   real_to_prot
   .code32
   
   leal   0x08(%esp), %ebp  // restore %ebp
   
   // heads
   movb   %dh, %al
   incl   %eax              // the number of heads is counted from zero
   movl   0x10(%ebp), %edi
   movl   %eax, (%edi)
   
   // sectors
   xorl   %eax, %eax
   movb   %cl, %al
   andb   $0x3f, %al
   movl   0x14(%ebp), %edi
   movl   %eax, (%edi)
   
   // cylinders
   shrb   $6, %cl
   movb   %cl, %ah
   movb   %ch, %al
   incl   %eax              // the number of cylinders is counted from zero
   movl   0x0C(%ebp), %edi
   movl   %eax, (%edi)
   
   xorl   %eax, %eax
   movb   %bl, %al          // return value in %eax
   
   popl   %edi
   popl   %ebx
   popl   %ebp
   
   ret

