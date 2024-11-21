
; input:  DX recebe o offset do início da memória a ser escrita e CX o final.
; output: 

Exemplo:
;            0 1  2 3   4 5  6 7    8 9  A B   C D  E F
; 0000 FFF4  0000 0000  0000 0000   0000 0000  0000 0000   0123 4567  89ab cdef
; 0000 FFF4  0000 0000  0000 0000   0000 0000  0000 0000   0123 4567  89ab cdef
; 0000 FFF4  0000 0000  0000 0000   0000 0000  0000 0000   0123 4567  89ab cdef
; 0000 FFF4  0000 0000  0000 0000   0000 0000  0000 0000   0123 4567  89ab cdef

%ifndef _escreve_memoria_tela
   %define _escreve_memoria_tela

escreve_memoria_tela:

PUSH  SI
PUSH  BP
PUSH  AX
MOV   BP, DX

MOV   SI, cabecalho
CALL  escreve_string_tela

loop_memoria:
CALL  escreve_enter_tela

; = = INÍCIO DO OFFSET = = = = = = = = = = = = = = = = = = = = = = = = = = = =

MOV   DX, DS
CALL  escreve_word_inHex_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   DX, BP
CALL  escreve_word_inHex_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela
CALL  escreve_caracter_tela

; = = FINAL DO OFFSET  = = = = = = = = = = = = = = = = = = = = = = = = = = = =

MOV   DX, [BP+0x00]
CALL  escreve_word_inHex_invertido_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   DX, [BP+0x02]
CALL  escreve_word_inHex_invertido_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   DX, [BP+0x04]
CALL  escreve_word_inHex_invertido_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   DX, [BP+0x06]
CALL  escreve_word_inHex_invertido_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela
CALL  escreve_caracter_tela

MOV   DX, [BP+0x08]
CALL  escreve_word_inHex_invertido_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   DX, [BP+0x0A]
CALL  escreve_word_inHex_invertido_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   DX, [BP+0x0C]
CALL  escreve_word_inHex_invertido_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   DX, [BP+0x0E]
CALL  escreve_word_inHex_invertido_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   DX, BP
CALL  escreve_memoria_caracter_tela

ADD   BP,0x0010

CMP   CX,BP
JA    loop_memoria  ; (CF=0 and ZF=0)

CALL  escreve_enter_tela

POP   AX
POP   BP
POP   SI
RET

%include "include/005_escreve_word_inHex_tela.asm"
%include "include/005_escreve_word_inHex_invertido_tela.asm"
%include "include/004_escreve_memoria_caracter_tela.asm"
%include "include/004_escreve_string_tela.asm"
%include "include/004_escreve_enter_tela.asm"
%include "include/003_escreve_caracter_tela.asm"

cabecalho:
db  "           0 1  2 3   4 5  6 7    8 9  A B   C D  E F", 0x00

%endif

