
; input:  
; output: 

%ifndef _escreve_enter_tela
   %define _escreve_enter_tela

escreve_enter_tela:

PUSH  AX

MOV   AL,0x0D
CALL  escreve_caracter_tela

MOV   AL,0x0A
CALL  escreve_caracter_tela

POP   AX

RET

%include "include/003_escreve_caracter_tela.asm"

%endif

