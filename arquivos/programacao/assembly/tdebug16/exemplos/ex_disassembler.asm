; clear && /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin -o trash.bin ex_disassembler.asm && dd if=trash.bin of=../vdi_HD.vdi bs=1 seek=1024 conv=notrunc && rm trash.bin && sync && VBoxManage startvm "x"

%include "include/003_copia_setores_MIDIApRAM.asm"

;NOP
MOV   DX, 0x5453 ; instrução a ser decodificada

MOV   SP, 0x7C00
MOV   BP, SP

MOV   AX, 0x0000
MOV   BX, 0x7E00
CALL  disassembler
CALL  escreve_memoria_bytes_tela

IMUL  CX, 3       ; para cada byte são impressos duas letras e um espaço
DEC   CX          ; não há espaço para o último byte
MOV   AX, CX  
MOV   CX, 0x001E  ; 0x1E = 30, que é o espaço para 10 bytes
SUB   CX, AX

ex_disassembler_1:
MOV   AL,0x20
CALL  escreve_caracter_tela
LOOP ex_disassembler_1

CALL  escreve_string_tela

infinito:
HLT
JMP SHORT infinito

%include "include/003_escreve_caracter_tela.asm"
%include "include/004_escreve_string_tela.asm"
%include "include/006_disassembler.asm"
%include "include/006_escreve_memoria_bytes_tela.asm"

