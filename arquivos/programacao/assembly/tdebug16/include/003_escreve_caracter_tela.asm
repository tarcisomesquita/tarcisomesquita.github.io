
; input:  AL tem o código ASCII do caracter
; output: 

; Exemplo:
; input:  AL = 0100 0011 b = 0x43 = 67 = C ASCII
; output: escreve C na tela.

%ifndef _escreve_caracter_tela
   %define _escreve_caracter_tela

escreve_caracter_tela:

PUSH  BX
PUSH  AX

STI

MOV   AH,0x0E
MOV   BX,0x0001
INT   0x10

POP   AX
POP   BX

RET

%endif

