# as --32 -o TBL_mbr.o TBL_mbr.asm && objcopy -O binary TBL_mbr.o TBL_mbr.bin && rm TBL_mbr.o

.intel_syntax noprefix

.text
.code16
_start:

.byte 0xFA                                # cli
.byte 0xEA, 0x06, 0x7C, 0x00, 0x00        # jmp word 0x0000:_7c06

_7c06:
.byte 0x31, 0xC0                          # xor ax,ax
.byte 0x8E, 0xD8                          # mov ds,ax
.byte 0x8E, 0xD0                          # mov ss,ax
.byte 0xBD, 0x00, 0x10                    # mov bp,0x1000
.byte 0x89, 0xEC                          # mov sp,bp

.byte 0xBE, 0x3A, 0x7C                    # mov si,_7c3a
.byte 0xE8, 0x46, 0x00                    # call word _7c5d # .byte 0x9A, 0x5D, 0x7C, 0x00, 0x00    # call 0x0000:0x7c5d

.byte 0xB8, 0x00, 0x00                    # mov ax,0x0000  # segmento_onde_escrever
.byte 0x8E, 0xC0                          # mov es,ax
.byte 0xBB, 0x00, 0x20                    # mov bx,0x2000  # offset_de_onde_escrever
.byte 0xB0, 0x14                          # mov al,0x14    # n_setores_a_copiar (máximo 0x48) (0x40 eh meio segmento)
.byte 0xB5, 0x00                          # mov ch,0x00    # Bottom 8 bits of cylinder number (0-based)
.byte 0xB1, 0x03                          # mov cl,0x03    # setor. (bits 6-7 are high bits of "cylinder")
.byte 0xB6, 0x00                          # mov dh,0x00    # Head number (0-based).
                                          # mov dl,0x80    # Drive number.
.byte 0xB4, 0x02                          # mov ah,0x02    # Function Read Sectors
.byte 0xCD, 0x13                          # int 0x13       

.byte 0x72, 0x05                          # jc _7c32
.byte 0xEA, 0x00, 0x20, 0x00, 0x00        # jmp word 0x0000:0x2000

_7c32:
.byte 0xBE, 0x42, 0x7C                    # mov si,_7c42
.byte 0xE8, 0x25, 0x00                    # call word _7c5d
_7c38:
.byte 0xEB, 0xFE                          # jmp short _7c38

# é melhor terminar o programa com cli and hlt

_7c3a:
.string "TBL... "

_7c42:
.string "int 13 AH 02 falhou"

_7c56:
                                          # mov al,0x54  # character T
.byte 0xBB, 0x01, 0x00                    # mov bx,0x01
.byte 0xB4, 0x0E                          # mov ah,0x0e
.byte 0xCD, 0x10                          # int 0x10
_7c5d:
.byte 0xAC                                # lodsb
.byte 0x3C, 0x00                          # cmp al,0x00
.byte 0x75, 0xF4                          # jnz _7c56
.byte 0xC3                                # ret


# tabela de partição
. = _start + 0x01be
.byte 0x00              # 0x80             #   partition flag ou boot indicator (se for 80h, é a partição ativa, se 00h, não é)
.byte 0x00, 0x00, 0x00  # 0xFE, 0xFF, 0xFF #   start CHS
.byte 0x00              # 0x0C             #   Partition byte (Descrição do tipo da partição) # 0x0C = FAT32 (LBA)
.byte 0x00, 0x00, 0x00  # 0xFE, 0xFF, 0xFF #   End CHS
                                           # (mbr + bootloader + kernel    + initrd    + reserva) * 512 # Start LBA
.long 0x00000000        # 0x00019018       #  2   + 10*2       + 10*1024*2 + 40*1024*2 + 2              # kernel: 10 MiB, initrd: 40 MiB 
.long 0x00000000        # 0x01000000       #  32 MiB

. = _start + 0x01fe
.word  0xaa55


