
; input:  DL tem o número nos bits 0-3.
; output: DX tem o código ASCII do número.

; Exemplo:
; input:  DL = 0000 1100 b = 0x0C = 12
; output: DX = 0100 0011 b = 0x43 = 67 = C ASCII

%ifndef _converte_NUMpASCIIhex
   %define _converte_NUMpASCIIhex

converte_NUMpASCIIhex:


AND   DX,0x000F

BT    DX,0x03
JC SHORT bits_1

BT    DX,0x02
JC SHORT bits_01

BT    DX,0x01
JC SHORT bits_001

BT    DX,0x00
JC SHORT bits_0001

MOV   DL,0x30
RET


bits_1:
BT    DX,0x02
JC SHORT bits_11

BT    DX,0x01
JC SHORT bits_101

BT    DX,0x00
JC SHORT bits_1001

MOV   DL,0x38
RET


bits_01:
BT    DX,0x01
JC SHORT bits_011

BT    DX,0x00
JC SHORT bits_0101

MOV   DL,0x34
RET


bits_001:
BT    DX,0x00
JC SHORT bits_0011

MOV   DL,0x32
RET


bits_0001:
MOV   DL,0x31
RET


bits_0011:
MOV   DL,0x33
RET


bits_0101:
MOV   DL,0x35
RET


bits_011:
BT    DX,0x00
JC SHORT bits_0111

MOV   DL,0x36
RET


bits_0111:
MOV   DL,0x37
RET


bits_1001:
MOV   DL,0x39
RET


bits_101:
BT    DX,0x00
JC SHORT bits_1011

MOV   DL,0x41
RET


bits_1011:
MOV   DL,0x42
RET


bits_11:
BT    DX,0x01
JC SHORT bits_111

BT    DX,0x00
JC SHORT bits_1101

MOV   DL,0x43
RET


bits_1101:
MOV   DL,0x44
RET


bits_111:
BT    DX,0x00
JC SHORT bits_1111

MOV   DL,0x45
RET


bits_1111:
MOV   DL,0x46
RET

%endif

