// void *grub_memmove(void *to, const void *from, int len);

   .text
.globl grub_memmove
grub_memmove:
   pushl   %ebp
   movl    %esp, %ebp
   pushl   %edi
   pushl   %esi
   pushl   %ebx
   
   movl    0x10(%ebp), %ecx       // len
   movl    0x0C(%ebp), %esi       // from
   movl    0x08(%ebp), %edi       // to
   
   cmpl    %esi, %edi             // from >= to
   jae     .L3                    
   
   cld
   rep
   movsb

   jmp     .L4
   
.L3:
   movl    0x0C(%ebp), %edx
   movl    0x10(%ebp), %eax
   subl    $1, %eax
   leal    (%edx,%eax), %ebx
   movl    0x08(%ebp), %edx
   movl    0x10(%ebp), %eax
   subl    $1, %eax
   addl    %eax, %edx
   movl    0x10(%ebp), %eax
   movl    %eax, %ecx
   movl    %ebx, %esi
   movl    %edx, %edi

   std
   rep
   movsb
   cld

.L4:
   popl    %ebx
   popl    %esi
   popl    %edi
   popl    %ebp
   ret

