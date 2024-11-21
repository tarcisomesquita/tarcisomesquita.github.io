   .text

   .code32

   .align 4

// gateA20(int linear)
// Gate address-line 20 for high memory.
.globl gateA20 ; gateA20:
   pushl   %ebp
   
   call   prot_to_real
   
   .code16
   movw   $0x2401, %ax
   stc
   int   $0x15
   movw   $0, %ax
   jnc   2f

   movw   $1, %ax    // set non-zero if failed

2: data32   call real_to_prot
   .code32

   popl   %ebp
   ret

