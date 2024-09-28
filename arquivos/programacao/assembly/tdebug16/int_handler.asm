
; input:  
; output: 

%ifndef _int_handler
   %define _int_handler
int_handler:

PUSH DS
PUSH AX
PUSH SI

CLI

MOV AX,0x0000
MOV DS,AX

%include "include/IVT_maq_teste.asm"

STI

MOV SI, msg1_int_handler
CALL escreve_string_tela

POP SI
POP AX
POP DS

RET



int00_handler:
MOV SI, msg1_int00_handler
CALL escreve_string_tela
JMP infinito_handler

int0D_handler:
MOV SI, msg1_int0D_handler
CALL escreve_string_tela
JMP infinito_handler


handler_nao_definido:
MOV SI, msg1_handler_nao_definido
CALL escreve_string_tela
JMP infinito_handler


infinito_handler:
MOV SI, msg1_infinito
CALL escreve_string_tela
a2_infinito_handler:
HLT
JMP SHORT a2_infinito_handler


msg1_int_handler:
db "Ja preparei os handlers para:", 0x0D, 0x0A, \
"INT 0x00    #DE", 0x0D, 0x0A, \
"INT 0x0D    #GP", 0x0D, 0x0A, \
0x00


msg1_int00_handler:
db "ERRO: #DE: Divisao por zero.", 0x0D, 0x0A, 0x00

msg1_int0D_handler:
db "ERRO: #GP: General protection.", 0x0D, 0x0A, 0x00

msg1_handler_nao_definido:
db "ERRO: Handler nao definido para o erro ocorrido.", 0x0D, 0x0A, 0x00

msg1_infinito:
db "Estou entrando em um loop infinito.", 0x0D, 0x0A, 0x00

%include "include/escreve_string_tela.asm"

%endif

