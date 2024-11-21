   .text

   .code32

// altera os registradores eax, esp, ebp, todos os de segmento, cr0

.globl prot_to_real ; prot_to_real:
   // just in case, set GDT
   lgdt   gdtdesc

   // save the protected mode stack
   movl   %esp, %eax
   movl   %eax, protstack

   // get the return address
   movl   (%esp), %eax
   movl   %eax, ret_point

   // set up new stack
   movl   $0x1000, %eax
   movl   %eax, %esp
   movl   %eax, %ebp
   pushl  ret_point
   
   // set up segment limits
   movw   $0x20, %ax // PSEUDO_RM_DSEG = 0x20
   movw   %ax, %ds
   movw   %ax, %es
   movw   %ax, %fs
   movw   %ax, %gs
   movw   %ax, %ss

   // this might be an extra step
   ljmp   $0x18, $tmpcseg   // jump to a 16 bit segment // PSEUDO_RM_CSEG = 0x18

tmpcseg:
   .code16

   // clear the PE bit of CR0
   movl   %cr0, %eax
   andl    $0xfffffffe, %eax  // CR0_PE_OFF = 0xfffffffe
   movl   %eax, %cr0

   data32  ljmp   $0, $realcseg   // flush prefetch queue, reload %cs

realcseg:
   xorl   %eax, %eax

   movw   %ax, %ds
   movw   %ax, %es
   movw   %ax, %fs
   movw   %ax, %gs
   movw   %ax, %ss

   sti

   // return on new stack!
   data32   ret

