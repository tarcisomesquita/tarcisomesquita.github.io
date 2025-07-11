
; input:  
; output: 

; OBS.: não altera os FLAGs

; Exemplo:
; IP=0000   CS=0000   DS=0000   SS=0000   ES=0000   FS=0000
; AX=0000   CX=0000   DX=0000   BX=0000   SP=0000   BP=0000   SI=0000   DI=0000


%ifndef _escreve_registradores_tela_horizontal
   %define _escreve_registradores_tela_horizontal

escreve_registradores_tela_horizontal:

PUSH  CS
PUSH  DS
PUSH  SS
PUSH  ES
PUSH  FS
PUSHA     ; repito duas vezes para poder alterar o valor de SP nesta.
PUSHA     ; Push AX, CX, DX, BX, original SP, BP, SI, and DI.
PUSHF

MOV   BP, SP
ADD   BP, 46  ; Deixa BP com o valor de entrada de SP.

MOV   [BP-22],BP  ; Corrige o valor de SP a ser escrito para o de entrada.

MOV   SI, escreve_registradores_tela_horizontal_registradores


MOV   CL,0x00
escreve_registradores_tela_horizontal_proximo:
INC   CL

CALL  escreve_string_tela
MOV   DX, [BP-0x02]
CALL  escreve_word_inHex_tela

CMP   CL,14    ; verifica se terminou de escrever tudo e suprime o espaço
JZ    escreve_registradores_tela_horizontal_fim
PUSH SI
MOV SI, escreve_registradores_tela_horizontal_espacos2
CALL escreve_string_tela
POP  SI
escreve_registradores_tela_horizontal_fim:

CMP   CL,0x06    ; verifica se terminou de escrever a primeira linha e passa para a segunda
JNZ   escreve_registradores_tela_horizontal_primeira
CALL  escreve_enter_tela
escreve_registradores_tela_horizontal_primeira:

SUB   BP, 0x02
CMP   CL,14
JNZ   escreve_registradores_tela_horizontal_proximo
CALL  escreve_enter_tela

POPF
POPA
ADD   SP,26 ; Retorna SP para o valor quando ele entrou na
RET


escreve_registradores_tela_horizontal_espacos2:
db "   ", 0x00

escreve_registradores_tela_horizontal_registradores:
db  "IP=", 0x00, "CS=", 0x00, "DS=", 0x00, "SS=", 0x00, "ES=", 0x00, "FS=", 0x00, "AX=", 0x00, "CX=", 0x00, "DX=", 0x00, "BX=", 0x00, "SP=", 0x00, "BP=", 0x00, "SI=", 0x00, "DI=", 0x00

%include "include/005_escreve_word_inHex_tela.asm"
%include "include/004_escreve_string_tela.asm"
%include "include/004_escreve_enter_tela.asm"

%endif

