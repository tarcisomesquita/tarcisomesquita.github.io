; clear && /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o trash.bin ex_0.asm && dd if=trash.bin of=../vdi_HD.vdi bs=1 seek=1024 conv=notrunc && rm trash.bin && sync && VBoxManage startvm "x"

%include "include/003_copia_setores_MIDIApRAM.asm"
%include "include/002_estado_anterior.asm"

PUSHF
CALL  escreve_linha_tela

POPF
CALL  escreve_FLAG_16_horizontal

CALL  escreve_linha_tela

CALL  escreve_registradores_tela_horizontal

CALL  escreve_linha_tela

CALL  escreve_pilha_tela_horizontal

CALL  escreve_linha_tela

infinito:
HLT
JMP SHORT infinito

%include "include/005_escreve_linha_tela.asm"
%include "include/005_escreve_FLAG_16_horizontal.asm"
%include "include/006_escreve_registradores_tela_horizontal.asm"
%include "include/007_escreve_pilha_tela_horizontal.asm"

