
; input:  AL tem o número nos bits 0-3.
; output: AX tem o código ASCII do número.

; Exemplo:
; input:  AL = 0000 1100 b = 0x0C = 12
; output: AX = 0100 0011 b = 0x43 = 67 = C ASCII

%ifndef _num_to_hex
%define _num_to_hex

num_to_hex:
AND   AX,0x000F

BT    AX,0x03
JC SHORT num_to_hex_bits_1

BT    AX,0x02
JC SHORT num_to_hex_bits_01

BT    AX,0x01
JC SHORT num_to_hex_bits_001

BT    AX,0x00
JC SHORT num_to_hex_bits_0001

MOV   AL,0x30
RET


num_to_hex_bits_1:
BT    AX,0x02
JC SHORT num_to_hex_bits_11

BT    AX,0x01
JC SHORT num_to_hex_bits_101

BT    AX,0x00
JC SHORT num_to_hex_bits_1001

MOV   AL,0x38
RET


num_to_hex_bits_01:
BT    AX,0x01
JC SHORT num_to_hex_bits_011

BT    AX,0x00
JC SHORT num_to_hex_bits_0101

MOV   AL,0x34
RET


num_to_hex_bits_001:
BT    AX,0x00
JC SHORT num_to_hex_bits_0011

MOV   AL,0x32
RET


num_to_hex_bits_0001:
MOV   AL,0x31
RET


num_to_hex_bits_0011:
MOV   AL,0x33
RET


num_to_hex_bits_0101:
MOV   AL,0x35
RET


num_to_hex_bits_011:
BT    AX,0x00
JC SHORT num_to_hex_bits_0111

MOV   AL,0x36
RET


num_to_hex_bits_0111:
MOV   AL,0x37
RET


num_to_hex_bits_1001:
MOV   AL,0x39
RET


num_to_hex_bits_101:
BT    AX,0x00
JC SHORT num_to_hex_bits_1011

MOV   AL,0x41
RET


num_to_hex_bits_1011:
MOV   AL,0x42
RET


num_to_hex_bits_11:
BT    AX,0x01
JC SHORT num_to_hex_bits_111

BT    AX,0x00
JC SHORT num_to_hex_bits_1101

MOV   AL,0x43
RET


num_to_hex_bits_1101:
MOV   AL,0x44
RET


num_to_hex_bits_111:
BT    AX,0x00
JC SHORT num_to_hex_bits_1111

MOV   AL,0x45
RET


num_to_hex_bits_1111:
MOV   AL,0x46
RET

%endif

