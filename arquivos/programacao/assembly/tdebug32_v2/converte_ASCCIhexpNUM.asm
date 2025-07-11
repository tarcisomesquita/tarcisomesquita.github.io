

converte_ASCCIhexpNUM:

; Recebe o código ASCII do número na base hexadecimal em DL e retorna o número nos nbits 0-3 de DL.
;
; Retorna DH = 0x53 para Sucesso na conversão e DH = 0x46 se Falhar.
;
; o codigo recebido de estar em um dos intervalos 30-39 ou 41-46
;
; Altera apenas os valores dos registradores DX e FLAGS

MOV  DH,DL

AND  DH,0xF0
CMP  DH, 0x30
JNZ  naonumero

MOV DH,0x53

BT    DX,0x03
JC SHORT nbits_1

BT    DX,0x02
JC SHORT nbits_01

BT    DX,0x01
JC SHORT nbits_001

BT    DX,0x00
JC SHORT nbits_0001

MOV   DL,0x00
RET


nbits_1
BT    DX,0x02
JC SHORT nerro

BT    DX,0x01
JC SHORT nerro

BT    DX,0x00
JC SHORT nbits_1001

MOV   DL,0x08
RET



nbits_01:
BT    DX,0x01
JC SHORT nbits_011

BT    DX,0x00
JC SHORT nbits_0101

MOV   DL,0x04
RET


nbits_001:
BT    DX,0x00
JC SHORT nbits_0011

MOV   DL,0x02
RET


nbits_0001:
MOV   DL,0x01
RET


nbits_0011:
MOV   DL,0x03
RET


nbits_0101:
MOV   DL,0x05
RET


nbits_011:
BT    DX,0x00
JC SHORT nbits_0111

MOV   DL,0x06
RET


nbits_0111:
MOV   DL,0x07
RET


nbits_1001:
MOV   DL,0x09
RET


nerro:
MOV DH,0x46
RET

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

naonumero:

MOV  DH,DL

AND  DH,0xF0
CMP  DH, 0x40
JNZ SHORT nerro

MOV DH,0x53


BT    DX,0x03
JC SHORT nerro

BT    DX,0x02
JC SHORT abits_01

BT    DX,0x01
JC SHORT abits_001

BT    DX,0x00
JC SHORT abits_0001

MOV DH,0x46
RET


abits_01:
BT    DX,0x01
JC SHORT abits_011

BT    DX,0x00
JC SHORT abits_0101

MOV   DL,0x0D
RET


abits_001:
BT    DX,0x00
JC SHORT abits_0011

MOV   DL,0x0B
RET


abits_0001:
MOV   DL,0x0A
RET


abits_0011:
MOV   DL,0x0C
RET


abits_0101:
MOV   DL,0x0E
RET


abits_011:
BT    DX,0x00
JC SHORT nerro

MOV   DL,0x0F
RET



