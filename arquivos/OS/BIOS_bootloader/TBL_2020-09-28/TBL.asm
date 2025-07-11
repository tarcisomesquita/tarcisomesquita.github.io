coincide com o dia d_2015-03-08

/media/ubuntu/SD/www/linguas/Assembly/compiladores/NASM/64bits/ndisasm -b 16 -o $((0x2000)) -e $((0)) TBL.bin >> TBL.asm
00002000  FA                cli
00002001  31C0              xor ax,ax
00002003  8ED8              mov ds,ax
00002005  8ED0              mov ss,ax
00002007  8EC0              mov es,ax

00002009  66BDF01F0000      mov ebp,0x1ff0
0000200F  6689EC            mov esp,ebp
00002012  FB                sti

00002013  B054              mov al,0x54
00002015  BB0100            mov bx,0x1
00002018  B40E              mov ah,0xe
0000201A  CD10              int 0x10

0000201C  66E85C000000      call dword 0x207e    real_to_prot

/media/ubuntu/SD/www/linguas/Assembly/compiladores/NASM/64bits/ndisasm -b 32 -o $((0x2022)) -e $((0x22)) TBL.bin >> TBL.asm

00002022  BF482B0000        mov edi,0x2b48
00002027  B9C42B0000        mov ecx,0x2bc4
0000202C  29F9              sub ecx,edi
0000202E  30C0              xor al,al
00002030  FC                cld
00002031  F3AA              rep stosb
00002033  B8C42B0000        mov eax,0x2bc4
00002038  A3502B0000        mov [0x2b50],eax
0000203D  89154C2B0000      mov [dword 0x2b4c],edx
00002043  E8B8020000        call dword 0x2300          init_bios_info
00002048  E8CF000000        call dword 0x211c          stop
0000204D  90                nop
0000204E  90                nop
0000204F  90                nop

stop:
0000211C  E8A3FFFFFF        call dword 0x20c4        prot_to_real
00002121  F4                hlt
00002122  EBFD              jmp short 0x2121

/media/ubuntu/SD/www/linguas/Assembly/compiladores/NASM/64bits/ndisasm -b 32 -o $((0x2300)) -e $((0x300)) TBL.bin >> TBL.asm

init_bios_info:
00002300  55                push ebp
00002301  89E5              mov ebp,esp
00002303  53                push ebx
00002304  83EC04            sub esp,byte +0x4
00002307  E884000000        call dword 0x2390          gateA20
0000230C  85C0              test eax,eax
0000230E  757B              jnz 0x238b
00002310  8B1D502B0000      mov ebx,[dword 0x2b50]
00002316  C705802B00000000  mov dword [dword 0x2b80],0x0
         -0000
00002320  891D842B0000      mov [dword 0x2b84],ebx
00002326  52                push edx
00002327  52                push edx
00002328  50                push eax
00002329  53                push ebx
0000232A  E895000000        call dword 0x23c4           get_mmap_entry
0000232F  83C410            add esp,byte +0x10
00002332  833B00            cmp dword [ebx],byte +0x0
00002335  7410              jz 0x2347
00002337  8305802B000018    add dword [dword 0x2b80],byte +0x18
0000233E  85C0              test eax,eax
00002340  7405              jz 0x2347
00002342  83C318            add ebx,byte +0x18
00002345  EBDF              jmp short 0x2326
00002347  833D802B000000    cmp dword [dword 0x2b80],byte +0x0
0000234E  7429              jz 0x2379
00002350  83EC0C            sub esp,byte +0xc
00002353  6A00              push byte +0x0
00002355  E8CA000000        call dword 0x2424              mmap_avail_at
0000235A  C1E80A            shr eax,byte 0xa
0000235D  A3582B0000        mov [0x2b58],eax
00002362  C7042400001000    mov dword [esp],0x100000
00002369  E8B6000000        call dword 0x2424             mmap_avail_at
0000236E  83C410            add esp,byte +0x10
00002371  C1E80A            shr eax,byte 0xa
00002374  A35C2B0000        mov [0x2b5c],eax
00002379  E81E010000        call dword 0x249c            get_diskinfo   
0000237E  85C0              test eax,eax
00002380  7509              jnz 0x238b
00002382  8B5DFC            mov ebx,[ebp-0x4]
00002385  C9                leave
00002386  E90D020000        jmp dword 0x2598           cmain
0000238B  8B5DFC            mov ebx,[ebp-0x4]
0000238E  C9                leave
0000238F  C3                ret

gateA20
00002390  55                push ebp
00002391  E82EFDFFFF        call dword 0x20c4          prot_to_real
00002396  B80124F9CD        mov eax,0xcdf92401
0000239B  15B8000073        adc eax,0x730000b8
000023A0  03B8010066E8      add edi,[eax-0x1799ffff]
000023A6  D4FC              aam 0xfc
000023A8  FF                db 0xff
000023A9  FF5DC3            call dword far [ebp-0x3d]
000023AC  3E206573          and [ds:ebp+0x73],ah
000023B0  693A65646920      imul edi,[edx],dword 0x20696465
000023B6  3D20307825        cmp eax,0x25783020
000023BB  58                pop eax
000023BC  3A30              cmp dh,[eax]
000023BE  7825              js 0x23e5
000023C0  58                pop eax
000023C1  0A00              or al,[eax]
000023C3  90                nop

/media/ubuntu/SD/www/linguas/Assembly/compiladores/NASM/64bits/ndisasm -b 32 -o $((0x2598)) -e $((0x598)) TBL.bin >> TBL.asm

cmain
00002598  55                push ebp
00002599  B909000000        mov ecx,0x9
0000259E  89E5              mov ebp,esp
000025A0  57                push edi
000025A1  56                push esi
000025A2  BEA42A0000        mov esi,0x2aa4
000025A7  53                push ebx
000025A8  83EC40            sub esp,byte +0x40
000025AB  8D7DD0            lea edi,[ebp-0x30]
000025AE  F3A5              rep movsd
000025B0  6800000100        push dword 0x10000
000025B5  6800040000        push dword 0x400
000025BA  6A16              push byte +0x16
000025BC  E86F010000        call dword 0x2730                devread_my
000025C1  83C410            add esp,byte +0x10
000025C4  66813DFE01010055  cmp word [dword 0x101fe],0xaa55
         -AA
000025CD  740D              jz 0x25dc
000025CF  83EC0C            sub esp,byte +0xc
000025D2  68D7290000        push dword 0x29d7
000025D7  E9B9000000        jmp dword 0x2695
000025DC  803DF101010040    cmp byte [dword 0x101f1],0x40
000025E3  760D              jna 0x25f2
000025E5  83EC0C            sub esp,byte +0xc
000025E8  68FB290000        push dword 0x29fb
000025ED  E9A3000000        jmp dword 0x2695
000025F2  813D020201004864  cmp dword [dword 0x10202],0x53726448
         -7253
000025FC  740D              jz 0x260b
000025FE  83EC0C            sub esp,byte +0xc
00002601  68242A0000        push dword 0x2a24
00002606  E98A000000        jmp dword 0x2695
0000260B  66813D0602010002  cmp word [dword 0x10206],0x202
         -02
00002614  770A              ja 0x2620
00002616  83EC0C            sub esp,byte +0xc
00002619  68492A0000        push dword 0x2a49
0000261E  EB75              jmp short 0x2695
00002620  F6051102010001    test byte [dword 0x10211],0x1
00002627  750A              jnz 0x2633
00002629  83EC0C            sub esp,byte +0xc
0000262C  68602A0000        push dword 0x2a60
00002631  EB62              jmp short 0x2695
00002633  66C705FA010100FF  mov word [dword 0x101fa],0xffff
         -FF
0000263C  BA00000200        mov edx,0x20000
00002641  C60510020100FF    mov byte [dword 0x10210],0xff
00002648  8D4DD0            lea ecx,[ebp-0x30]
0000264B  66C7052402010000  mov word [dword 0x10224],0x7e00
         -7E
00002654  C6051102010081    mov byte [dword 0x10211],0x81
0000265B  C705280201000000  mov dword [dword 0x10228],0x20000
         -0200
00002665  EB04              jmp short 0x266b
00002667  8802              mov [edx],al
00002669  41                inc ecx
0000266A  42                inc edx
0000266B  A128020100        mov eax,[0x10228]
00002670  05FF000000        add eax,0xff
00002675  39C2              cmp edx,eax
00002677  7306              jnc 0x267f
00002679  8A01              mov al,[ecx]
0000267B  84C0              test al,al
0000267D  75E8              jnz 0x2667
0000267F  C60200            mov byte [edx],0x0
00002682  0FB605F1010100    movzx eax,byte [dword 0x101f1]
00002689  85C0              test eax,eax
0000268B  7512              jnz 0x269f
0000268D  83EC0C            sub esp,byte +0xc
00002690  686D2A0000        push dword 0x2a6d
00002695  E8A6FBFFFF        call dword 0x2240

0000269A  E983000000        jmp dword 0x2722
0000269F  8D5801            lea ebx,[eax+0x1]
000026A2  C1E309            shl ebx,byte 0x9
000026A5  52                push edx
000026A6  6800040100        push dword 0x10400
000026AB  8D8300FCFFFF      lea eax,[ebx-0x400]
000026B1  50                push eax
000026B2  6A18              push byte +0x18
000026B4  E877000000        call dword 0x2730                devread_my
000026B9  83C40C            add esp,byte +0xc
000026BC  B80000A000        mov eax,0xa00000
000026C1  6800001000        push dword 0x100000
000026C6  29D8              sub eax,ebx
000026C8  C1EB09            shr ebx,byte 0x9
000026CB  50                push eax
000026CC  83C316            add ebx,byte +0x16
000026CF  53                push ebx
000026D0  E85B000000        call dword 0x2730                devread_my
000026D5  A12C020100        mov eax,[0x1022c]
000026DA  83C410            add esp,byte +0x10
000026DD  C705180201000000  mov dword [dword 0x10218],0x2800000
         -8002
000026E7  3D00000005        cmp eax,0x5000000
000026EC  770F              ja 0x26fd
000026EE  2D00008002        sub eax,0x2800000
000026F3  2500F0FFFF        and eax,0xfffff000
000026F8  A318020100        mov [0x10218],eax
000026FD  C7051C0201000000  mov dword [dword 0x1021c],0x2800000
         -8002
00002707  50                push eax
00002708  FF3518020100      push dword [dword 0x10218]
0000270E  6800008002        push dword 0x2800000
00002713  6816500000        push dword 0x5016
00002718  E813000000        call dword 0x2730                devread_my
0000271D  E8BE010000        call dword 0x28e0                big_linux_boot
00002722  83C410            add esp,byte +0x10
00002725  8D65F4            lea esp,[ebp-0xc]
00002728  5B                pop ebx
00002729  5E                pop esi
0000272A  5F                pop edi
0000272B  5D                pop ebp
0000272C  C3                ret
0000272D  90                nop


000028E0  50                push eax
000028E1  68DC280000        push dword 0x28dc
000028E6  E855F9FFFF        call dword 0x2240     tbl_printf
000028EB  58                pop eax
000028EC  58                pop eax
000028ED  BB00000100        mov ebx,0x10000
000028F2  C1EB04            shr ebx,byte 0x4
000028F5  89D8              mov eax,ebx
000028F7  83C020            add eax,byte +0x20
000028FA  A315290000        mov [0x2915],eax
000028FF  E8C0F7FFFF        call dword 0x20c4    prot_to_real

/media/ubuntu/SD/www/linguas/Assembly/compiladores/NASM/64bits/ndisasm -b 16 -o $((0x2904)) -e $((0x904)) TBL.bin >> TBL.asm

00002904  FA                cli
00002905  8ED3              mov ss,bx
00002907  BC0090            mov sp,0x9000
0000290A  8EDB              mov ds,bx
0000290C  8EC3              mov es,bx
0000290E  8EE3              mov fs,bx
00002910  8EEB              mov gs,bx
00002912  EA00000000        jmp word 0x0:0x0

