
; input:  BP tem o offset do início da pilha e SP tem o offset do final da pilha.
; output: 

; Exemplo:
; Se BP = 0x7C00  e  SP = 0x7BFC, escreve na tela:
; 7C00 = 00BC
; 7BFE = ABCD
; 7BFC = 0123

; cada programa deve executar as intruções PUSH BP ; MOV BP,SP no início do código.

%ifndef _escreve_pilha_tela_vertical
   %define _escreve_pilha_tela_vertical

escreve_pilha_tela_vertical:

PUSH  BP
PUSH  BX
PUSH  DX
PUSH  SI

MOV   BX,BP     ; BX tem o topo  da pilha
MOV   BP,SP
ADD   BP,0x0A   ; BP tem o fundo da pilha

CMP   BX,BP
JC    fim_escreve_pilha_tela_vertical

proximo_escreve_pilha_tela_vertical:

MOV   DX,BX
CALL  escreve_word_inHex_tela

MOV   SI,string_escreve_pilha_tela_vertical
CALL  escreve_string_tela

MOV   DX,[BX]
CALL  escreve_word_inHex_tela
CALL  escreve_enter_tela

SUB   BX,0x02
CMP   BX,BP
JNC   proximo_escreve_pilha_tela_vertical


fim_escreve_pilha_tela_vertical:

POP   SI
POP   DX
POP   BX
POP   BP

RET

string_escreve_pilha_tela_vertical:
db      " = ", 0x00

%include "include/005_escreve_word_inHex_tela.asm"
%include "include/004_escreve_string_tela.asm"
%include "include/004_escreve_enter_tela.asm"

%endif

