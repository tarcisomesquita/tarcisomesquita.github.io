
BITS 16

org   0x7C00


; = = =  LOCAL DA ESCRITA = = = = = = = = = = = = = = = = = = = = = = = = = = 

MOV   AX,0x0000 ; segmento_onde_escrever
MOV   ES,AX

MOV   BX,0x7E00 ; offset_de_onde_escrever

; o este programa saltará para ES:BX, MUDE O FINAL SO PROGRAMA

; = = =  LOCAL DA CÓPIA = = = = = = = = = = = = = = = = = = = = = = = = = 

MOV   AL,0x40 ; n_setores_a_copiar (máximo 0x48) (0x40 eh meio segmento)

MOV   CH,0x00 ; Bottom 8 bits of track (cylinder) number (0-based).

MOV   CL,0x02 ; ttssssss, as follows:
              ;    tt = top two bits of 10-bit track number,
              ;    ssssss = 6-bit sector number (1-based).

MOV   DH,0x00 ; Head number (0-based).

MOV   DL,0x80 ; Drive number.


; = = =  ESCRITA = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

MOV   AH,0x02 ; Function Read Sectors
INT   0x13


; = = =  RESULTADO = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
;        CF - Set if failure, else clear if success.
;        AH - Disk status code (00h if success).
;        AL - Number of sectors actually written.

JC    loop_infinito

jmp word 0x0000:0x7E00 ; salto para o programa carregado

loop_infinito:
HLT
JMP SHORT loop_infinito

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

codesize equ $ - $$
falta equ 0x1FE - codesize

times falta db      0x00   
db 0x55, 0xaa   ; minha maquina requer que tenha isso no final do setor 1.


