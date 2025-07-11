
MOV     AX,0x0E54
MOV     BX,0x0001

pushfw
push es
push ds
pushaw
mov bx,0x0000 ; no original 0xc000
mov ds,bx
call funcao
func_ret:

; ==-----------------


jmp sucesso
jmp erro

; ==-----------------

popaw
pop ds
pop es
popfw 
jmp continue
; -----------------

sucesso:
MOV     AX,0x0E53 ; imprime S
MOV     BX,0x0001
INT     0x10
CALL imprime_enter
jmp  continue

erro:
MOV     AX,0x0E46 ; imprime F
MOV     BX,0x0001
INT     0x10
CALL imprime_enter
jmp  continue

funcao:
push bp
mov bp,sp
mov ax,[bp+0x12]
mov al,ah
xor ah,ah

C3C6D  D1E0              shl ax,1
C3C6F  89C3              mov bx,ax
C3C71  2EFFA7763C        jmp word near [cs:bx+0x3c76]


ret

continue:

