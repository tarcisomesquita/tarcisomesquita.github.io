// gcc -Os -fno-stack-protector -fno-builtin -nostdinc -nostdlib -Wall -Werror -falign-jumps=1 -falign-loops=1 -falign-functions=1 -Wl,-N -Wl,-Ttext -Wl,7C00 -o teste_LBA.elf teste_LBA.S && objcopy -O binary teste_LBA.elf teste_LBA && sudo dd if=teste_LBA of=16MiB.bin bs=1 conv=notrunc 2>/dev/null && sudo sync && VBoxManage startvm "lx" --type gui

   .text

   .code16

// start symbols here just to force ld quiet.
   .globl   main, start, _start
start:
_start:
main:               // "main" is loaded at 0x0000:0x7C00

// int check_LBA (int drive)
// Check if LBA is supported for DRIVE.

.globl check_LBA
check_LBA:
   .code16
   movb    $0x80, %dl
   movb    $0x00, %ah  // reset disk system
   int     $0x13
   movw    $falha_reset, %si
   jc      termina
   cmpb    $0x00, %ah
   jne     termina
   
   movw    $0x55aa, %bx
   movb    $0x41,   %ah  // instalation check
   int     $0x13
   movw    $falha_instalation, %si
   jc      termina
   cmpw    $0xaa55, %bx
   jne     termina
   
   movw    $int13,   %si
   call message
   
   movw    $bit0,   %si
   movw    %cx,     %dx
   andw    $0x0001, %dx
   jz      1f
   call message
1:
   
   movw    $bit1,   %si
   movw    %cx,     %dx
   andw    $0x0002, %dx
   jz      2f
   call message
2:
   
   movw    $bit2,   %si
   movw    %cx,     %dx
   andw    $0x0004, %dx
   jz      3f
   call message
3:
   
   movw    $sucesso, %si
   
termina:
   call message
   
hard_stop:
   hlt
   jmp hard_stop

x2:
   movw $0x0001, %bx
   movb $0x0e  , %ah //  função imprimir caracter
   int  $0x10
message:
   lodsb
   cmpb $0x00, %al
   jnz x2
   ret


read_error:

falha_reset:       .string "FALHOU int 13 reset"
falha_instalation: .string "FALHOU int 13 instalation check"
int13:   .string "int 13"
bit0:    .string " (AH=42h-44h,47h,48h)"
bit1:    .string " (AH=45h,46h,48h,49h,INT 15/AH=52h)"
bit2:    .string " (AH=48h,AH=4Eh)"
sucesso: .string "\n\rsupported"

final:
. = final + (0x1BE - (final - start))

tabela1:
.byte 0x80             //   partition flag ou boot indicator (se for 80h, é a partição ativa, se 00h, não é)
.byte 0xFE, 0xFF, 0xFF //   start CHS
.byte 0x83             //   Partition byte (Descrição do tipo da partição)
.byte 0xFE, 0xFF, 0xFF //   End CHS
.long 0x0000000E       //   Start LBA (número do setor do início da partição)  stored as little-endian
.long 0x00008000       //   Partition Size (in sectors) stored as little-endian

. = tabela1 + 4 * 16
.word  0xAA55

