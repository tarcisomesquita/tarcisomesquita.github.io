
; input:  DL tem o byte a ser impresso
; output: 

; Exemplo:
; input:  DL = 0000 1100 b = 0x0C = 12
; output: escreve 0C na tela.

%ifndef _escreve_byte_inHex_tela
   %define _escreve_byte_inHex_tela

escreve_byte_inHex_tela:

PUSH  AX
PUSH  DX
PUSH  DX

ROR   DL,0x4
CALL  converte_NUMpASCIIhex
MOV   AL,DL
CALL  escreve_caracter_tela

POP   DX
CALL  converte_NUMpASCIIhex
MOV   AL,DL
CALL  escreve_caracter_tela

POP   DX
POP   AX

RET

%include "include/002_converte_NUMpASCIIhex.asm"
%include "include/003_escreve_caracter_tela.asm"

%endif

