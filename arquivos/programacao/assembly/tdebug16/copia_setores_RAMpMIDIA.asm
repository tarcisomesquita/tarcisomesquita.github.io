
; Parece me que o driver number do disquete é 0x00 e de um hd é 0x80


; = = =  LOCAL DA COPIA = = = = = = = = = = = = = = = = = = = = = = = = = = 

MOV   AX,0xc000 ; segmento_de_onde_copiar
MOV   ES,AX

MOV   BX,0x3e00 ; offset_de_onde_copiar

MOV   AL,0x05 ; n_setores_a_copiar (máximo 0x48) (0x40 eh meio segmento)


; = = =  LOCAL DA ESCRITA = = = = = = = = = = = = = = = = = = = = = = = = = 

MOV   CH,0x00 ; Bottom 8 bits of track (cylinder) number (0-based).

MOV   CL,0x02 ; ttssssss, as follows:
              ;    tt = top two bits of 10-bit track number,
              ;    ssssss = 6-bit sector number (1-based).

MOV   DH,0x00 ; Head number (0-based).

MOV   DL,0x80 ; Drive number.


; = = =  ESCRITA = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

MOV   AH,0x03 ; Function Write Sectors
INT   0x13


; = = =  RESULTADO = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
;        CF - Set if failure, else clear if success.
;        AH - Disk status code (00h if success).
;        AL - Number of sectors actually written.

MOV   AX,0x0E46 ; imprime F ; Falha
JC    salta
MOV   AX,0x0E53 ; imprime S ; Sucesso
salta:
MOV   BX,0x0001
INT   0x10

loop_infinito:
HLT
JMP   loop_infinito

; = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

