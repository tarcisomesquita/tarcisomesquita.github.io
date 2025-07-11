; cria uma lista como a abaixo
; 20 = 
; 21 = !
; 22 = "
; 23 = #
; 24 = $
; 25 = %
; Aperte uma tecla para continuar

; input:  
; output:

%ifndef _lista_ASCII
   %define _lista_ASCII

lista_ASCII:
MOV  DL,0xFF
MOV  CL,0x10

lista_ASCII_1:
INC  DL

CALL escreve_byte_inHex_tela
MOV  AL,' '
CALL escreve_caracter_tela
MOV  AL,'='
CALL escreve_caracter_tela
MOV  AL,' '
CALL escreve_caracter_tela
MOV  AL,DL
CALL escreve_caracter_tela
CALL escreve_enter_tela

CMP  CL,DL
JNZ  lista_ASCII_2

PUSH DX
MOV  AH,0x00
INT  0x16
POP  DX
ADD  CL,0x10

lista_ASCII_2:
CMP  DL,0xFF
JNZ  lista_ASCII_1

RET

%include "include/003_escreve_caracter_tela.asm"
%include "include/004_escreve_byte_inHex_tela.asm"
%include "include/004_escreve_enter_tela.asm"

%endif

