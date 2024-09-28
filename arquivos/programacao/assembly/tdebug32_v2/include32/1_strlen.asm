
; input:  eax tem o offset do primeiro byte da string
; output: eax retorna o número de caracteres

%ifndef _strlen
   %define _strlen

strlen:
PUSH  ESI
PUSH  EDX

CLD
MOV   ESI, EAX
PUSH  ESI

strlen_unaligned:
XOR   EDX, EDX
MOV   EAX, ESI
DIV   ESI
TEST  EDX, EDX
JZ    strlen_aligned

LODSB
TEST  AL, AL
JZ    strlen_final_um
JMP   strlen_unaligned

strlen_aligned:
LODSD
TEST  EAX, 0x000000FF
JZ    strlen_final_quatro
TEST  EAX, 0x0000FF00
JZ    strlen_final_tres
TEST  EAX, 0x00FF0000
JZ    strlen_final_dois
TEST  EAX, 0xFF000000
JZ    strlen_final_um
JMP   strlen_aligned

strlen_final_um:
SUB   ESI, 1
JMP   strlen_final

strlen_final_dois:
SUB   ESI, 2
JMP   strlen_final

strlen_final_tres:
SUB   ESI, 3
JMP   strlen_final

strlen_final_quatro:
SUB   ESI, 4

strlen_final:
POP   EAX
SUB   ESI, EAX
MOV   EAX, ESI

POP   EDX
POP   ESI
RET
%endif


