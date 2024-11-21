; clear && /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o trash.bin ex_lista_ASCII.asm && dd if=trash.bin of=../vdi_HD.vdi bs=1 seek=1024 conv=notrunc && rm trash.bin && sync && VBoxManage startvm "x"

%include "include/003_copia_setores_MIDIApRAM.asm"

CALL  lista_ASCII

infinito:
HLT
JMP SHORT infinito

%include "include/005_lista_ASCII.asm"

