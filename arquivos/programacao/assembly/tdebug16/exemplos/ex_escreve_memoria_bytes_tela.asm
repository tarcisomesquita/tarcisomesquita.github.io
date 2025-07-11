; clear && /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o trash.bin ex_escreve_memoria_bytes_tela.asm && dd if=trash.bin of=../vdi_HD.vdi bs=1 seek=1024 conv=notrunc && rm trash.bin && sync && VBoxManage startvm "x"

%include "include/003_copia_setores_MIDIApRAM.asm"

MOV   SP,0x7C00
MOV   BP, SP

MOV   AX, 0x0000
MOV   BX, 0x7E00
MOV   CX, 0x0004
CALL  escreve_memoria_bytes_tela

infinito:
HLT
JMP SHORT infinito

%include "include/006_escreve_memoria_bytes_tela.asm"

