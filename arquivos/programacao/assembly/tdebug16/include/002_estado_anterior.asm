; = = = = = = = = = = = =  ESTADO ANTERIOR = = = = = = = = = = = = = = = = = = = 

CLI
MOV   AX,0x0000

MOV   SS,AX
MOV   DS,AX

JMP estado_anterior

; ==================
estado_anterior_pilha:
dw  0x0202 ; FLAGS
dw  0x0000 ; DI
dw  0x0000 ; SI
dw  0x7C00 ; BP
estado_anterior_sp:
dw  0x7C00 ; SP
dw  0x0000 ; BX
dw  0x0080 ; DX
dw  0x0000 ; CX
dw  0x0000 ; AX

estado_anterior_segmento:
dw  0x0000 ; FS
dw  0x0000 ; ES
dw  0x0000 ; SS
dw  0x0000 ; DS
dw  0x0000 ; CS (Este nao muda de estado)
; ==================


estado_anterior:
MOV   SP, estado_anterior_pilha
POPF
POPA
MOV   SP,[estado_anterior_sp]

MOV   FS,[estado_anterior_segmento+0]
MOV   ES,[estado_anterior_segmento+2]
MOV   SS,[estado_anterior_segmento+4]
MOV   DS,[estado_anterior_segmento+6]

