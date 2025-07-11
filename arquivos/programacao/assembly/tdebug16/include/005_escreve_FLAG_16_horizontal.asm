
; input:  
; output: 

; OBS.: não altera os FLAGs

; Exemplo:
; Se FLAG = 0000 1100  0000 0010 b = 0x0E02, escreve na tela:
; rs=0      NT=0      IO=0      IO=0      OF=1      DF=1      IF=1      TF=0
; SF=0      ZF=0      rs=0      AF=0      rs=0      PF=0      rs=1      CF=0

%ifndef _escreve_FLAG_16_horizontal
   %define _escreve_FLAG_16_horizontal

escreve_FLAG_16_horizontal:
PUSH  AX
PUSH  BX
PUSH  CX
PUSH  SI

PUSHF
MOV   BX, SP
MOV   CX, [BX]

MOV   SI, escreve_FLAG_16_horizontal_flags
MOV   BX,0x0010

escreve_FLAG_16_horizontal_loop:
CALL  escreve_string_tela            ; escreve xF=

MOV    AL,0x31                       ; escreve 0 ou 1
DEC    BX
BT     CX,BX
JC     escreve_FLAG_16_horizontal_agora
MOV    AL,0x30
escreve_FLAG_16_horizontal_agora:
CALL   escreve_caracter_tela


CMP     BX, 0x08                     ; decide se escreve espaços ou enter.
JZ      escreve_FLAG_16_horizontal_enter
CMP     BX, 0x00
JZ      escreve_FLAG_16_horizontal_enter
CALL    escreve_FLAG_16_horizontal_espacos
JMP SHORT escreve_FLAG_16_horizontal_continue
escreve_FLAG_16_horizontal_enter:
CALL   escreve_enter_tela
escreve_FLAG_16_horizontal_continue:

TEST   BX,BX
JNZ    escreve_FLAG_16_horizontal_loop

POPF
POP   SI
POP   CX
POP   BX
POP   AX

RET

escreve_FLAG_16_horizontal_espacos:
PUSH SI
MOV  SI, escreve_FLAG_16_horizontal_espacos2
CALL escreve_string_tela
POP  SI
RET

escreve_FLAG_16_horizontal_espacos2:
db "      ", 0x00

escreve_FLAG_16_horizontal_flags:
db  "rs=", 0x00, "NT=", 0x00, "IO=", 0x00, "IO=", 0x00, "OF=", 0x00, "DF=", 0x00, "IF=", 0x00, "TF=", 0x00,\
    "SF=", 0x00, "ZF=", 0x00, "rs=", 0x00, "AF=", 0x00, "rs=", 0x00, "PF=", 0x00, "rs=", 0x00, "CF=", 0x00

%include "include/003_escreve_caracter_tela.asm"
%include "include/004_escreve_string_tela.asm"
%include "include/004_escreve_enter_tela.asm"

%endif


