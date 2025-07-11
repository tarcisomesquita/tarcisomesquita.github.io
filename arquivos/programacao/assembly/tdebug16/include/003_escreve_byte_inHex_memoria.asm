; input:
;         AX tem o SEGMENTO
;         BX tem o OFFSET
;         DL tem o byte a ser escrito

; output:

%ifndef _escreve_byte_inHex_memoria
   %define _escreve_byte_inHex_memoria

escreve_byte_inHex_memoria:
PUSHA
MOV   DS, AX

PUSH  DX

ROR   DL,0x4
CALL  converte_NUMpASCIIhex
MOV   [BX], DL

POP   DX
CALL  converte_NUMpASCIIhex
INC   BX
MOV   [BX], DL

POPA
RET

%endif

%include "include/002_converte_NUMpASCIIhex.asm"

