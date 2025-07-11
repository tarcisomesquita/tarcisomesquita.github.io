
; input:  DX recebe o offset do início da memória a ser escrita.
; output: 

; Exemplo:
; endereco: db "0123456789ABCDEF01"
; MOV DX,endereco
; CALL escreve_memoria_caracter_tela
; escreve "  0123 4567  89AB CDEF"

%ifndef _escreve_memoria_caracter_tela
   %define _escreve_memoria_caracter_tela

escreve_memoria_caracter_tela:

PUSH  BP
PUSH  AX
MOV   BP, DX

MOV   AL, 0x20
CALL  escreve_caracter_tela
CALL  escreve_caracter_tela

MOV   AL, [BP+0x00]
CMP   AL, 0x20
JL    pulo0
CMP   AL, 0x7E
JG    pulo0
JMP SHORT pulo20
pulo0:
MOV   AL, 0x2E
pulo20:
CALL  escreve_caracter_tela

MOV   AL, [BP+0x01]
CMP   AL, 0x20
JL    pulo1
CMP   AL, 0x7E
JG    pulo1
JMP SHORT pulo21
pulo1:
MOV   AL, 0x2E
pulo21:
CALL  escreve_caracter_tela

MOV   AL, [BP+0x02]
CMP   AL, 0x20
JL    pulo2
CMP   AL, 0x7E
JG    pulo2
JMP SHORT pulo22
pulo2:
MOV   AL, 0x2E
pulo22:
CALL  escreve_caracter_tela

MOV   AL, [BP+0x03]
CMP   AL, 0x20
JL    pulo3
CMP   AL, 0x7E
JG    pulo3
JMP SHORT pulo23
pulo3:
MOV   AL, 0x2E
pulo23:
CALL  escreve_caracter_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   AL, [BP+0x04]
CMP   AL, 0x20
JL    pulo4
CMP   AL, 0x7E
JG    pulo4
JMP SHORT pulo24
pulo4:
MOV   AL, 0x2E
pulo24:
CALL  escreve_caracter_tela

MOV   AL, [BP+0x05]
CMP   AL, 0x20
JL    pulo5
CMP   AL, 0x7E
JG    pulo5
JMP SHORT pulo25
pulo5:
MOV   AL, 0x2E
pulo25:
CALL  escreve_caracter_tela

MOV   AL, [BP+0x06]
CMP   AL, 0x20
JL    pulo6
CMP   AL, 0x7E
JG    pulo6
JMP SHORT pulo26
pulo6:
MOV   AL, 0x2E
pulo26:
CALL  escreve_caracter_tela

MOV   AL, [BP+0x07]
CMP   AL, 0x20
JL    pulo7
CMP   AL, 0x7E
JG    pulo7
JMP SHORT pulo27
pulo7:
MOV   AL, 0x2E
pulo27:
CALL  escreve_caracter_tela


MOV   AL, 0x20
CALL  escreve_caracter_tela
CALL  escreve_caracter_tela

MOV   AL, [BP+0x08]
CMP   AL, 0x20
JL    pulo8
CMP   AL, 0x7E
JG    pulo8
JMP SHORT pulo28
pulo8:
MOV   AL, 0x2E
pulo28:
CALL  escreve_caracter_tela

MOV   AL, [BP+0x09]
CMP   AL, 0x20
JL    pulo9
CMP   AL, 0x7E
JG    pulo9
JMP SHORT pulo29
pulo9:
MOV   AL, 0x2E
pulo29:
CALL  escreve_caracter_tela

MOV   AL, [BP+0x0A]
CMP   AL, 0x20
JL    puloA
CMP   AL, 0x7E
JG    puloA
JMP SHORT pulo2A
puloA:
MOV   AL, 0x2E
pulo2A:
CALL  escreve_caracter_tela

MOV   AL, [BP+0x0B]
CMP   AL, 0x20
JL    puloB
CMP   AL, 0x7E
JG    puloB
JMP SHORT pulo2B
puloB:
MOV   AL, 0x2E
pulo2B:
CALL  escreve_caracter_tela

MOV   AL, 0x20
CALL  escreve_caracter_tela

MOV   AL, [BP+0x0C]
CMP   AL, 0x20
JL    puloC
CMP   AL, 0x7E
JG    puloC
JMP SHORT pulo2C
puloC:
MOV   AL, 0x2E
pulo2C:
CALL  escreve_caracter_tela

MOV   AL, [BP+0x0D]
CMP   AL, 0x20
JL    puloD
CMP   AL, 0x7E
JG    puloD
JMP SHORT pulo2D
puloD:
MOV   AL, 0x2E
pulo2D:
CALL  escreve_caracter_tela

MOV   AL, [BP+0x0E]
CMP   AL, 0x20
JL    puloE
CMP   AL, 0x7E
JG    puloE
JMP SHORT pulo2E
puloE:
MOV   AL, 0x2E
pulo2E:
CALL  escreve_caracter_tela

MOV   AL, [BP+0x0F]
CMP   AL, 0x20
JL    puloF
CMP   AL, 0x7E
JG    puloF
JMP SHORT pulo2F
puloF:
MOV   AL, 0x2E
pulo2F:
CALL  escreve_caracter_tela

POP   AX
POP   BP
RET

%include "include/003_escreve_caracter_tela.asm"

%endif

