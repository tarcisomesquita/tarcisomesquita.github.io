
; input:  SI tem o offset do primeiro caracter da string
; output: SI tem o offset do próximo byte depois do 0x00 do final da string

; Exemplo:
; Se o primeiro byte da string está em 0x7CE1 e o 0x00 está em 0x7CE4
; retorna 0x7CE5

%ifndef _escreve_string_tela
   %define _escreve_string_tela

escreve_string_tela:

PUSH  AX

escreve_string_tela_3:
CLD
LODSB             ; Load byte at address DS:SI into AL.
CMP   AL,0x00
JZ   escreve_string_tela_2

CALL  escreve_caracter_tela
JMP SHORT escreve_string_tela_3

escreve_string_tela_2:
POP   AX

RET

%include "include/003_escreve_caracter_tela.asm"

%endif

