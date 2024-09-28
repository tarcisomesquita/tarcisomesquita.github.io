
erro_msg:
db "Instrucao nao programada.", 0x00

o1001_0000:
db "NOP   ",0x00

; /media/SD/www/linguas/Assembly/compiladores/NASM/ndisasm.elf ../vdi_HD.vdi -b 16 -e $((1024+512)) | less
; 00000005  B80000            mov ax,0x0
; 00000018  B91E00            mov cx,0x1e
; 00000000  BA5354            mov dx,0x5453
; 00000008  BB007E            mov bx,0x7e00
; 00000000  BC007C            mov sp,0x7c00

