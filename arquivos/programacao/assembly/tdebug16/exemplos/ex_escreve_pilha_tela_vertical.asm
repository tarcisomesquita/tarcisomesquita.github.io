; clear && /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o trash.bin ex_escreve_pilha_tela_vertical.asm && dd if=trash.bin of=../vdi_HD.vdi bs=1 seek=1024 conv=notrunc && rm trash.bin && sync && VBoxManage startvm "x"

%include "include/003_copia_setores_MIDIApRAM.asm"

MOV   SP,0x7C00
MOV   BP, SP

PUSH  0x5454
CALL  escreve_pilha_tela_vertical

infinito:
HLT
JMP SHORT infinito

%include "include/006_escreve_pilha_tela_vertical.asm"

