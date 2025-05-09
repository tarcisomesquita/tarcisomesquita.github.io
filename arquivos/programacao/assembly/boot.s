# boot/boot.S

# Start the CPU: switch to 32-bit protected mode, jump into C.
# The BIOS loads this code from the first sector of the hard disk into
# memory at physical address 0x7c00 and starts executing in real mode
# with %cs=0 %ip=7c00.

.set PROT_MODE_CSEG, 0x8  # kernel code segment selector
.set PROT_MODE_DSEG, 0x10 # kernel data segment selector
.set CR0_PE_ON, 0x1       # protected mode enable flag

.globl start
start:
  .code16 # Assemble for 16-bit mode
  cli     # Disable interrupts
  cld     # String operations increment

  # Set up the important data segment registers (DS, ES, SS).
  xorw %ax,%ax # Segment number zero
  movw %ax,%ds # -> Data Segment
  movw %ax,%es # -> Extra Segment
  movw %ax,%ss # -> Stack Segment

  # Enable A20:
  # For backwards compatibility with the earliest PCs, physical
  # address line 20 is tied low, so that addresses higher than
  # 1MB wrap around to zero by default. This code undoes this.
seta20.1:
  inb $0x64,%al   # Wait for not busy
  testb $0x2,%al
  jnz seta20.1

  movb $0xd1,%al # 0xd1 -> port 0x64
  outb %al,$0x64

seta20.2:
  inb $0x64,%al # Wait for not busy
  testb $0x2,%al
  jnz seta20.2

  movb $0xdf,%al # 0xdf -> port 0x60
  outb %al,$0x60

  # Switch from real to protected mode, using a bootstrap GDT
  # and segment translation that makes virtual addresses
  # identical to their physical addresses, so that the
  # effective memory map does not change during the switch.
  lgdt gdtdesc
  movl %cr0, %eax
  orl $CR0_PE_ON, %eax
  movl %eax, %cr0
  
  # Jump to next instruction, but in 32-bit code segment.
  # Switches processor into 32-bit mode.
  ljmp $PROT_MODE_CSEG, $protcseg

  .code32 # Assemble for 32-bit mode
protcseg:
  # Set up the protected-mode data segment registers
  movw $PROT_MODE_DSEG, %ax # Our data segment selector
  movw %ax, %ds # -> DS: Data Segment
  movw %ax, %es # -> ES: Extra Segment
  movw %ax, %fs # -> FS
  movw %ax, %gs # -> GS
  movw %ax, %ss # -> SS: Stack Segment
  
  # Set up the stack pointer and call into C.
  movl $start, %esp
  call bootmain

  # If bootmain returns (it shouldn't), loop.
spin:
  jmp spin

# Bootstrap GDT
.p2align 2 # force 4 byte alignment
gdt:
// Application segment type bits
#define STA_X 0x8 // Executable segment
#define STA_E 0x4 // Expand down (non-executable segments)
#define STA_C 0x4 // Conforming code segment (executable only)
#define STA_W 0x2 // Writeable (non-executable segments)
#define STA_R 0x2 // Readable (executable segments)
#define STA_A 0x1 // Accessed

// System segment type bits
#define STS_T16A 0x1 // Available 16-bit TSS
#define STS_LDT 0x2 // Local Descriptor Table
#define STS_T16B 0x3 // Busy 16-bit TSS
#define STS_CG16 0x4 // 16-bit Call Gate
#define STS_TG 0x5 // Task Gate / Coum Transmitions
#define STS_IG16 0x6 // 16-bit Interrupt Gate
#define STS_TG16 0x7 // 16-bit Trap Gate
#define STS_T32A 0x9 // Available 32-bit TSS
#define STS_T32B 0xB // Busy 32-bit TSS
#define STS_CG32 0xC // 32-bit Call Gate
#define STS_IG32 0xE // 32-bit Interrupt Gate
#define STS_TG32 0xF // 32-bit Trap Gate

#define SEG_NULL \
.word 0, 0; \
.byte 0, 0, 0, 0
#define SEG(type,base,lim) \
.word (((lim) >> 12) & 0xffff), ((base) & 0xffff); \
.byte (((base) >> 16) & 0xff), (0x90 | (type)), \
(0xC0 | (((lim) >> 28) & 0xf)), (((base) >> 24) & 0xff)

  SEG_NULL                          # null seg
  SEG(STA_X|STA_R, 0x0, 0xffffffff) # code seg
  SEG(STA_W,       0x0, 0xffffffff) # data seg

gdtdesc:
  .word 0x17 # sizeof(gdt) - 1
  .long gdt  # address gdt


