; /media/SD/www/linguas/Assembly/compiladores/NASM/nasm.elf -f bin vdi_HD.asm -o vdi_HD.vdi
; dd if=/dev/zero of=vdi_HD.vdi bs=1024 seek=1 count=1024
; dd if=tabela_de_particao.bin of=vdi_HD.vdi bs=1 seek=$((1024 + 0x01BE)) conv=notrunc

; VBoxManage createvm -name "x" -register && VBoxManage storagectl "x" --name teste --add sata && VBoxManage storageattach "x" --storagectl teste --medium  $(pwd)/vdi_HD.vdi --port 0 --type hdd
; VBoxManage startvm "x"

%define HD_OFFSET  0x00000400
%define HD_SIZE    0x0000000000100000
%define HD_MiB     0x00000001             ; HD de 1 MiB

x000:    db "vdi_HD_meu", 0x0a ;  0x00000000 máximo 63 caracteres
x001:
TENHO equ x001 - x000
FALTA equ 0x40 - TENHO
times FALTA db 0x00    ; zero padding

         db 0x7f, 0x10, 0xda, 0xbe, 0x01, 0x00, 0x01, 0x00 ;    0x00000040 = 64
         dw 0x0190 ;    0x00000048  mudou para 190 de pois de escrever a MBR
         dw 0x0000
         dw 0x0002 ; disco de tamanho dinâmico é 0x0001
         dw 0x0000
times 0x100 db 0x00 ;   0x00000050

         dd 0x00000000 ;   0x00000150
         dd 0x00000200
         dd HD_OFFSET  ;   0x00000158  offset de onde termina o cabeçalho e começa o HD.
         dd 0x00000000

         dd 0x00000000 ;   0x00000160
         dd 0x00000000
         dd 0x00000200 ;   0x00000168
         dd 0x00000000

         dq HD_SIZE    ;   0x00000170 tamanho do HD 4 GiB = 0x0000 0001  0000 0000

         dd 0x00100000 ;   0x00000178  1 MiB = 0x00100000
         dd 0x00000000

         dd HD_MiB     ;   0x00000180  4 GiB = 0x00001000 * 1 MiB
         dd HD_MiB     ;               4 GiB = 0x00001000 * 1 MiB
         
         ; HardDisk uuid ;   0x00000188
         dd 0xe8d10b94
         dw 0xf8c2
         dw 0x4a03
         db 0x00, 0x00,   0x20, 0x12, 0x06, 0x17, 0x00, 0x00 ;  AQUI

         ; não sei o que é isso ;   0x00000198
         dd 0x927fd20d
         dw 0x86a3
         dw 0x4804
         db 0x83, 0xeb,   0x52, 0xa9, 0xf8, 0xec, 0x25, 0xdf

         dd 0x00000000 ;   0x000001a8
         dd 0x00000000 

times 0x10 db 0x00     ;   0x000001b0

         dd 0x00000000 ;   0x000001c0
         dd 0x00000000
         dd 0x0000020a ; após escrever o winnt signature
         dd 0x000000ff ; após escrever o winnt signature

         dd 0x0000003f ;   0x000001d0  ; após escrever o winnt signature
         dd 0x00000200
         dd 0x00000000
         dd 0x00000000

times 0x20 db 0x00     ;   0x000001e0

; Cada double equivale a 1 MiB
dd 0x00000000

times 0x01FC db 0x00

