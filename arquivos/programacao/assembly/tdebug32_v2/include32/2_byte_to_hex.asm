
; input:  AL tem o byte.
; output: AX tem o código ASCII do byte.

; Ex.: recebe AL=0x54 e retorna AX=0x3435

%ifndef _byte_to_hex
%define _byte_to_hex

byte_to_hex:
PUSH  EBX
XOR   EBX, EBX

AND   EAX, 0x000000FF
PUSH  EAX

CALL  num_to_hex

MOV   BH,AL

POP   EAX
ROR   AL,0x04 
CALL  num_to_hex

MOV   AH,BH

POP   EBX
RET

%include "include32/1_num_to_hex.asm"
%endif

