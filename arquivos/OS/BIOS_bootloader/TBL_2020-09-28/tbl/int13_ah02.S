// int int13_ah02(int ah, int drive, int coff, int hoff, int soff, int nsec, int segment)
// Call standard and old INT13 (int 13 %ah=AH) for DRIVE.
// Read/write NSEC sectors from COFF/HOFF/SOFF into SEGMENT.
// If an error occurs, return non-zero, otherwise zero.

   .code32
   .text

.globl int13_ah02
int13_ah02:
   pushl   %ebp
   movl   %esp, %ebp
   
   pushl   %ebx
   pushl   %edi
   pushl   %esi
   
   movl   0x08(%ebp), %eax   // Cylinder_offset
   movb   %al, %ch
   
   movb   0x0C(%ebp), %dh    // Head_offset
   movb   current_drive, %dl
   
   movb   0x10(%ebp), %al    // Sector_offset
   andw   $0x003F, %ax
   movb   %al, %cl
   
   movb   $0x02, %ah         
   movb   0x14(%ebp), %al    // nsec  0x1C // o valor máximo deve ser 0x48
   movw   %ax, %di
   
   movw   0x18(%ebp), %bx    // segment, depois muda para %es

   call   prot_to_real
   .code16
   
   movw   %bx, %es
   movw   $3, %si            // try read again at least three times
   
1:   
   movw   $0x0000, %bx
   movw   %di, %ax           // %al tem o número de setores a ser lido
//   movb   $0x02, %ah
   int    $0x13
   jnc    2f                 // %bl = 0, significa OK
   
   movb   $0x01, %bl         // retorna 1 se persistir o erro
   
   xorw   %ax, %ax           // if fail, reset the disk system ...
   int   $0x13
   
   decw   %si
   cmpw   $0, %si
   je     2f
   jmp    1b                 // ... and try again.
2:   
   
   data32   call   real_to_prot
   .code32
   
   movb   %bl, %al           // return value in %eax
   
   popl   %esi
   popl   %edi
   popl   %ebx
   popl   %ebp
   
   ret

   

