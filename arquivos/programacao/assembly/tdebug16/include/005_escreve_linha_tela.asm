
; input:  
; output: 

%ifndef _escreve_linha_tela
   %define _escreve_linha_tela
escreve_linha_tela:

PUSH  SI
MOV   SI,escreve_linha_tela_1
CALL  escreve_string_tela
POP   SI
RET

escreve_linha_tela_1:
db "==============================================================================", 0x0D, 0x0A, 0x00

%include "include/004_escreve_string_tela.asm"
%endif


