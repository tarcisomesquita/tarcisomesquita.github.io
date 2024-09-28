
; input:  AX, BX e CX possuem, respectivamente, o SEGMENTO, o OFFSET e o número de bytes a ser excrito.
; output: 

%ifndef _escreve_memoria_bytes_tela
   %define _escreve_memoria_bytes_tela

escreve_memoria_bytes_tela:
PUSHA

MOV   DX, AX
CALL  escreve_word_inHex_invertido_tela

MOV   AL,0x20
CALL  escreve_caracter_tela

MOV   DX, BX
CALL  escreve_word_inHex_invertido_tela

MOV   AL,0x20
CALL  escreve_caracter_tela

escreve_memoria_bytes_tela_1:

MOV   AL,0x20
CALL  escreve_caracter_tela

MOV   DL,[BX]
CALL  escreve_byte_inHex_tela
INC   BX
LOOP escreve_memoria_bytes_tela_1

POPA
RET

%include "include/003_escreve_caracter_tela.asm"
%include "include/004_escreve_byte_inHex_tela.asm"
%include "include/005_escreve_word_inHex_invertido_tela.asm"
%endif

