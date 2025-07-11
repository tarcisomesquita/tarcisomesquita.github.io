
; input:  
; output: 

%ifndef _escreve_pilha_tela_horizontal
   %define _escreve_pilha_tela_horizontal

escreve_pilha_tela_horizontal:
PUSH  DX
MOV   DX,SP
ADD   DX,0x02

PUSH  CX
MOV   CX,BP

AND   DX,0xFFF0

CALL  escreve_memoria_tela

POP   CX
POP   DX
RET

%include "include/006_escreve_memoria_tela.asm"

%endif


