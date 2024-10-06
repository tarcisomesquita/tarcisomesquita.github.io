   .text

   .code16

// altera os registradores: eax, esp, ebp, todos os de segmento e cr0

/*
 * This is the Global Descriptor Table
 *  An entry, a "Segment Descriptor", looks like this:
 *
 * 31          24         19   16                 7           0
 * ------------------------------------------------------------
 * |             | |B| |A|       | |   |1|0|E|W|A|            |
 * | BASE 31..24 |G|/|0|V| LIMIT |P|DPL|  TYPE   | BASE 23:16 |
 * |             | |D| |L| 19..16| |   |1|1|C|R|A|            |
 * ------------------------------------------------------------
 * |                             |                            |
 * |        BASE 15..0           |       LIMIT 15..0          |
 * |                             |                            |
 * ------------------------------------------------------------
 *
 *  Note the ordering of the data items is reversed from the above description.
 */

   .p2align   2   // force 4-byte alignment
gdt:
   .word   0, 0
   .byte   0, 0, 0, 0

   // code segment
   .word   0xFFFF, 0
   .byte   0, 0x9A, 0xCF, 0

   // data segment
   .word   0xFFFF, 0
   .byte   0, 0x92, 0xCF, 0

   // 16 bit real mode CS
   .word   0xFFFF, 0
   .byte   0, 0x9E, 0, 0

   // 16 bit real mode DS
   .word   0xFFFF, 0
   .byte   0, 0x92, 0, 0


// this is the GDT descriptor
.globl gdtdesc ; gdtdesc:
   .word   0x27    // limit
   .long   gdt     // addr


	.globl real_to_prot
real_to_prot:

	cli
	
	// load the GDT register
	data32	addr32	lgdt	gdtdesc
	
	// turn on protected mode
	movl	%cr0, %eax
	orl	$0x00000001, %eax  // CR0_PE_ON
	movl	%eax, %cr0
	
	// jump to relocation, flush prefetch queue, and reload %cs
	data32	ljmp	$0x0008, $protcseg
	
	.code32
protcseg:
	// reload other segment registers
	movw	$0x10, %ax
	movw	%ax, %ds
	movw	%ax, %es
	movw	%ax, %fs
	movw	%ax, %gs
	movw	%ax, %ss
	
	// put the return address in a known safe location
	movl	(%esp), %eax
	movl	%eax, ret_point
	
	// get protected mode stack
	movl	protstack, %eax
	movl	%eax, %esp
	movl	%eax, %ebp
	
	// get return address onto the right stack
	movl	ret_point, %eax
	movl	%eax, (%esp)
	
	// zero %eax
	xorl	%eax, %eax
	
	// return on the old (or initialized) stack!
	ret

