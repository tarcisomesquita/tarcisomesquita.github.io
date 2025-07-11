
; input:  
; output: 

; OBS.: Não preserva os FLAGs

; Exemplo:
; FLAGS = 0000
; DI = 0000
; SI = 0000
; BP = 0000
; SP = 0000
; BX = 0000
; DX = 0000
; CX = 0000
; AX = 0000
; FS = 0000
; ES = 0000
; SS = 0000
; DS = 0000
; CS = 0000


%ifndef _escreve_registradores_tela_vertical
   %define _escreve_registradores_tela_vertical

escreve_registradores_tela_vertical:

PUSH  BP
MOV   BP,SP

PUSH WORD 0x0000 ; CX
PUSH WORD 0x0000 ; DX
PUSH WORD 0x0000 ; SI

PUSH  CS
PUSH  DS
PUSH  SS
PUSH  ES
PUSH  FS
PUSHA     ; Push AX, CX, DX, BX, original SP, BP, SI, and DI.
PUSHF

MOV   AX,0x0000
MOV   DS,AX

MOV   [BP-0x02],CX   ; coloca CX na pilha

MOV   CX,BP          ; coloca o valor de entrada de SP para ser escrito na tela
ADD   CX,0x02
MOV   [BP-26],CX

MOV   [BP-0x06],SI   ; coloca SI na pilha
MOV   SI, dados      ; coloca em SI o endereço das strings de cabeçalho

MOV   [BP-0x04],DX   ; coloca DX na pilha
                     ; DX será usado na hora de escrever word na tela.

MOV   CX,BP          ; CX contém o offset do último valor da pilha a ser escrito na tela.
SUB   CX,6           ; Fiz isso pensando na possibilidade de usar a mesma técnica para
                     ; imprimir pilha e tabela de variaveis

escreve_registradores_tela_vertical_proximo:
CALL  escreve_string_tela

POP   DX
CALL  escreve_word_inHex_tela
CALL  escreve_enter_tela


CMP   CX,SP
JNZ   escreve_registradores_tela_vertical_proximo

POP   SI
POP   DX
POP   CX
POP   BP

RET

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
db 0x00, 0x00
dados:
db      "FLAGS = ", 0x00, "DI = ", 0x00, "SI = ", 0x00, "BP = ", 0x00, "SP = ", 0x00, \
"BX = ", 0x00, "DX = ", 0x00, "CX = ", 0x00, "AX = ", 0x00, "FS = ", 0x00, "ES = ", 0x00, \
"SS = ", 0x00, "DS = ", 0x00, "CS = ", 0x00

%include "include/005_escreve_word_inHex_tela.asm"
%include "include/004_escreve_string_tela.asm"
%include "include/004_escreve_enter_tela.asm"

%endif

