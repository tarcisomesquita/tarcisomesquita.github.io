.data
nome: .string   "OK\n"

   .intel_syntax noprefix
   .code32
   .text


   .align 4

.globl big_linux_boot
big_linux_boot:
   push   eax
   push   OFFSET FLAT: nome
   call   tbl_printf
#   call   console_getkey
   add    esp, 4
   
   mov    ebx, 0x0001000   // segment of ADDRESS_X
   mov    eax, ebx
   add    eax, 0x20         // Isto está em linux-3.17.4/Documentation/x86/boot.txt
   mov    [linux_setup_seg], eax
   
   call   prot_to_real
   .code16
   
   cli
   mov   ss, bx
   mov   sp, 0x1000
   
   mov   ds, bx
   mov   es, bx
   mov   fs, bx
   mov   gs, bx
   
   // jump to start
   .byte   0xea  // ljmp
   .word   0x0000

linux_setup_seg:   
   .word   0x0000


/*
// EA cp    JMP ptr16:32    Jump far, absolute, address given in operand
// EA00909090        jmp word 0x9090:0x9000

// FF /5    JMP m16:32      Jump far, absolute indirect, address given in m16:32. Parece melhor por ser suportado também em 64 bits.
// FF2F     jmp word far [bx]
// FF28     jmp word far [bx+si]
// FF2E9090 jmp word far [0x9090]

The address-size override prefix (67H) allows programs to switch between 16- and 32-bit addressing.
// 67FF2E   jmp word far [esi]
// 67FF2F   jmp word far [edi]

When executing a far jump in real-address, the processor jumps to the code segment and offset specified with the target operand.
Here the target operand specifies an absolute far address either directly with a pointer (ptr16:16 or ptr16:32) or indirectly with a memory location (m16:16 or m16:32).
With the pointer method, the segment and address of the called procedure is encoded in the instruction, using a 4-byte (16-bit operand size) or 6-byte (32-bit operand size) far address immediate.
With the indirect method, the target operand specifies a memory location that contains a 4-byte (16-bit operand size) or 6-byte (32-bit operand size) far address. The far address is loaded directly into the CS and EIP registers.
If the operand-size attribute is 16, the upper two bytes of the EIP register are cleared.


                              64bits
        FF /5   JMP m16:16    Valid    Valid    Jump far, absolute indirect, address given in m16:16
        FF /5   JMP m16:32    Valid    Valid    Jump far, absolute indirect, address given in m16:32.
REX.W + FF /5   JMP m16:64    Valid    N.E.     Jump far, absolute indirect, address given in m16:64.

/digit — A digit between 0 and 7 indicates that the ModR/M byte of the instruction uses only the r/m (register or memory) operand.
The reg field contains the digit that provides an extension to the instruction's opcode.

Ver "A.4.2 Opcode Extension Tables" em /media/SD/linguas/Assembly/processador_Intel/253667_Instruction Set Reference N-Z.pdf
// Encoding of Bits 5,4,3 of the ModR/M Byte:  101 (binario) JMPF Ep
// Mod mem, 11 (binario)

Me parece que a instrução JMP far [bx] seria assim: 0xFF 0xEB, mas o ndisasm não identifica desse modo.
*/

