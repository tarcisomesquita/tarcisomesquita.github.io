
; input:  DX tem a word a ser impresso
; output: 

; Exemplo:
; input:  DX = 0xABCD
; output: Escreve na tela ABCD


%ifndef _escreve_word_inHex_tela
   %define _escreve_word_inHex_tela

escreve_word_inHex_tela:

PUSH  DX
MOV   DL,DH
CALL  escreve_byte_inHex_tela

POP   DX
CALL  escreve_byte_inHex_tela

RET

%include "include/004_escreve_byte_inHex_tela.asm"

%endif

