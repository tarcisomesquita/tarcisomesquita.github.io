
posicao:
dw 0xA400

escreve_estado_registradores_na_RAM:


; deixado IP acessivel
MOV BX,SP
ADD BX,0x001E
MOV DX,[BX]
PUSH DX

MOV BP,[posicao]
MOV SI,0x0005

MOV DL,DH
CALL converte_BYTEpASCCI
mov [bp+si+0x00],dx
POP DX
CALL converte_BYTEpASCCI
mov [bp+si+0x02],dx


MOV BX,SP
ADD BX,0x0004
MOV CX,0x0005
add si,0x000a

loop1:

MOV DX,[BX]
PUSH DX
MOV DL,DH
CALL converte_BYTEpASCCI
mov [bp+si+0x00],dx
POP DX
CALL converte_BYTEpASCCI
mov [bp+si+0x02],dx
add si,0x000a
add bx,0x0002
loop loop1


SUB si,0x0001
MOV CX,0x0008


loop2:

MOV DX,[BX]
PUSH DX
MOV DL,DH
CALL converte_BYTEpASCCI
mov [bp+si+0x00],dx
POP DX
CALL converte_BYTEpASCCI
mov [bp+si+0x02],dx
add si,0x000a
add bx,0x0002
loop loop2


RET

