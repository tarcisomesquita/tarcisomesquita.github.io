; clear && /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o trash.bin ex_escreve_byte_inHex_memoria.asm && dd if=trash.bin of=../vdi_HD.vdi bs=1 seek=1024 conv=notrunc && rm trash.bin && sync && VBoxManage startvm "x"

%include "include/003_copia_setores_MIDIApRAM.asm"

MOV   SP,0x7C00
MOV   BP, SP

MOV   AX, DS
MOV   DL, 0x32
MOV   BX, teste
CALL  escreve_byte_inHex_memoria

MOV   CX, 0x0002
CALL  escreve_memoria_bytes_tela

infinito:
HLT
JMP SHORT infinito

teste: db 0x53, 0x00

%include "include/003_escreve_byte_inHex_memoria.asm"
%include "include/006_escreve_memoria_bytes_tela.asm"

