.byte 0xFA                                # cli
.byte 0x31, 0xC0                          # xor ax,ax
.byte 0x8E, 0xD8                          # mov ds,ax
.byte 0x8E, 0xD0                          # mov ss,ax
.byte 0x8E, 0xC0                          # mov es,ax
.byte 0xBD, 0xf0, 0x1f                    # mov bp,0x1ff0
.byte 0x89, 0xEC                          # mov sp,bp
.byte 0xFB                                # sti

.byte 0xB0, 0x54                          # mov al,0x54  # character T
.byte 0xBB, 0x01, 0x00                    # mov bx,0x01
.byte 0xB4, 0x0E                          # mov ah,0x0e
.byte 0xCD, 0x10                          # int 0x10

.byte 0xE8, 0x5c, 0x00                    # call word _207e

2022:
.byte 0xbf, 0x48, 0x2b, 0x00, 0x00, 0xb9, 0xc4, 0x2b, 0x00, 0x00, 0x29, 0xf9, 0x30, 0xc0
2030:
.byte 0xfc, 0xf3, 0xaa, 0xb8, 0xc4, 0x2b, 0x00, 0x00, 0xa3, 0x50, 0x2b, 0x00, 0x00, 0x89, 0x15, 0x4c
2040:
.byte 0x2b, 0x00, 0x00, 0xe8, 0xb8, 0x02, 0x00, 0x00, 0xe8, 0xcf, 0x00, 0x00, 0x00, 0x90, 0x90, 0x90

.align 16, 0

# altera os registradores: eax, esp, ebp, todos os de segmento e cr0

# Global Descriptor Table
# 31          24         19   16                 7           0
# ------------------------------------------------------------
# |             | |B| |A|       | |   |1|0|E|W|A|            |
# | BASE 31..24 |G|/|0|V| LIMIT |P|DPL|  TYPE   | BASE 23:16 |
# |             | |D| |L| 19..16| |   |1|1|C|R|A|            |
# ------------------------------------------------------------
# |                             |                            |
# |        BASE 15..0           |       LIMIT 15..0          |
# |                             |                            |
# ------------------------------------------------------------

2050:
gdt:
   .word   0x0000, 0x0000
   .byte   0x00, 0x00, 0x00, 0x00

   # code segment
   .word   0xFFFF, 0x0000
   .byte   0x00, 0x9A, 0xCF, 0x00

   # data segment
   .word   0xFFFF, 0x0000
   .byte   0x00, 0x92, 0xCF, 0x00

   # 16 bit real mode CS
   .word   0xFFFF, 0x0000
   .byte   0x00, 0x9E, 0x00, 0x00

   # 16 bit real mode DS
   .word   0xFFFF, 0x0000
   .byte   0x00, 0x92, 0x00, 0x00


# this is the GDT descriptor
gdtdesc:
   .word   0x0027      # limit
   .long   0x00002050  #gdt     # addr

207e:


0000207E  FA                cli
0000207F  67660F0115782000  o32 lgdt [dword 0x2078]
         -00
00002088  0F20C0            mov eax,cr0
0000208B  6683C801          or eax,byte +0x1
0000208F  0F22C0            mov cr0,eax
00002092  66EA9A2000000800  jmp dword 0x8:0x209a
0000209A  66B810008ED8      mov eax,0xd88e0010
000020A0  8EC0              mov es,ax
000020A2  8EE0              mov fs,ax
000020A4  8EE8              mov gs,ax
000020A6  8ED0              mov ss,ax
000020A8  8B04              mov ax,[si]
000020AA  24A3              and al,0xa3
000020AC  F01F              lock pop ds
000020AE  0000              add [bx+si],al
000020B0  A1442B            mov ax,[0x2b44]
000020B3  0000              add [bx+si],al
000020B5  89C4              mov sp,ax
000020B7  89C5              mov bp,ax
000020B9  A1F01F            mov ax,[0x1ff0]
000020BC  0000              add [bx+si],al
000020BE  8904              mov [si],ax
000020C0  2431              and al,0x31
000020C2  C0C30F            rol bl,byte 0xf
000020C5  0115              add [di],dx
000020C7  7820              js 0x20e9
000020C9  0000              add [bx+si],al
000020CB  89E0              mov ax,sp
000020CD  A3442B            mov [0x2b44],ax
000020D0  0000              add [bx+si],al
000020D2  8B04              mov ax,[si]
000020D4  24A3              and al,0xa3
000020D6  F01F              lock pop ds
000020D8  0000              add [bx+si],al
000020DA  B8F01F            mov ax,0x1ff0
000020DD  0000              add [bx+si],al
000020DF  89C4              mov sp,ax
000020E1  89C5              mov bp,ax
000020E3  66B820008ED8      mov eax,0xd88e0020
000020E9  8EC0              mov es,ax
000020EB  8EE0              mov fs,ax
000020ED  8EE8              mov gs,ax
000020EF  8ED0              mov ss,ax
000020F1  EAF8200000        jmp word 0x0:0x20f8
000020F6  1800              sbb [bx+si],al
000020F8  0F20C0            mov eax,cr0
000020FB  6683E0FE          and eax,byte -0x2
000020FF  0F22C0            mov cr0,eax
00002102  66EA0A2100000000  jmp dword 0x0:0x210a
0000210A  6631C0            xor eax,eax
0000210D  8ED8              mov ds,ax
0000210F  8EC0              mov es,ax
00002111  8EE0              mov fs,ax
00002113  8EE8              mov gs,ax
00002115  8ED0              mov ss,ax
00002117  FB                sti
00002118  66C3              o32 ret
0000211A  90                nop
0000211B  90                nop
0000211C  E8A3FF            call word 0x20c2
0000211F  FF                db 0xff
00002120  FFF4              push sp
00002122  EBFD              jmp short 0x2121
00002124  55                push bp
00002125  A1482B            mov ax,[0x2b48]
00002128  0000              add [bx+si],al
0000212A  89E5              mov bp,sp
0000212C  8B15              mov dx,[di]
0000212E  40                inc ax
0000212F  2B00              sub ax,[bx+si]
00002131  008B4D08          add [bp+di+0x84d],cl
00002135  80F90A            cmp cl,0xa
00002138  7508              jnz 0x2142
0000213A  40                inc ax
0000213B  A3482B            mov [0x2b48],ax
0000213E  0000              add [bx+si],al
00002140  EB2F              jmp short 0x2171
00002142  69C0A000          imul ax,ax,word 0xa0
00002146  0000              add [bx+si],al
00002148  01D0              add ax,dx
0000214A  88880080          mov [bx+si-0x8000],cl
0000214E  0B00              or ax,[bx+si]
00002150  C68001800B        mov byte [bx+si-0x7fff],0xb
00002155  0007              add [bx],al
00002157  A1402B            mov ax,[0x2b40]
0000215A  0000              add [bx+si],al
0000215C  83C002            add ax,byte +0x2
0000215F  3D9F00            cmp ax,0x9f
00002162  0000              add [bx+si],al
00002164  A3402B            mov [0x2b40],ax
00002167  0000              add [bx+si],al
00002169  7610              jna 0x217b
0000216B  FF05              inc word [di]
0000216D  48                dec ax
0000216E  2B00              sub ax,[bx+si]
00002170  00C7              add bh,al
00002172  05402B            add ax,0x2b40
00002175  0000              add [bx+si],al
00002177  0000              add [bx+si],al
00002179  0000              add [bx+si],al
0000217B  5D                pop bp
0000217C  C3                ret
0000217D  55                push bp
0000217E  89E5              mov bp,sp
00002180  56                push si
00002181  8B7508            mov si,[di+0x8]
00002184  53                push bx
00002185  31DB              xor bx,bx
00002187  EB0B              jmp short 0x2194
00002189  0FB6C0            movzx ax,al
0000218C  43                inc bx
0000218D  50                push ax
0000218E  E891FF            call word 0x2122
00002191  FF                db 0xff
00002192  FF588A            call word far [bx+si-0x76]
00002195  041E              add al,0x1e
00002197  84C0              test al,al
00002199  75EE              jnz 0x2189
0000219B  8D65F8            lea sp,[di-0x8]
0000219E  89D8              mov ax,bx
000021A0  5B                pop bx
000021A1  5E                pop si
000021A2  5D                pop bp
000021A3  C3                ret
000021A4  55                push bp
000021A5  89E5              mov bp,sp
000021A7  57                push di
000021A8  56                push si
000021A9  53                push bx
000021AA  83EC08            sub sp,byte +0x8
000021AD  8B550C            mov dx,[di+0xc]
000021B0  8B4D10            mov cx,[di+0x10]
000021B3  8B7D08            mov di,[di+0x8]
000021B6  83FA78            cmp dx,byte +0x78
000021B9  0F94C3            setz bl
000021BC  83FA58            cmp dx,byte +0x58
000021BF  0F94C0            setz al
000021C2  09C3              or bx,ax
000021C4  80FB01            cmp bl,0x1
000021C7  19C0              sbb ax,ax
000021C9  83E0FA            and ax,byte -0x6
000021CC  83C010            add ax,byte +0x10
000021CF  85C9              test cx,cx
000021D1  8945EC            mov [di-0x14],ax
000021D4  7905              jns 0x21db
000021D6  83FA64            cmp dx,byte +0x64
000021D9  7404              jz 0x21df
000021DB  89FE              mov si,di
000021DD  EB0A              jmp short 0x21e9
000021DF  8D7701            lea si,[bx+0x1]
000021E2  F7D9              neg cx
000021E4  C6072D            mov byte [bx],0x2d
000021E7  89F7              mov di,si
000021E9  31D2              xor dx,dx
000021EB  89C8              mov ax,cx
000021ED  F775EC            div word [di-0x14]
000021F0  83FA09            cmp dx,byte +0x9
000021F3  7E05              jng 0x21fa
000021F5  83C257            add dx,byte +0x57
000021F8  EB03              jmp short 0x21fd
000021FA  83C230            add dx,byte +0x30
000021FD  881689C8          mov [0xc889],dl
00002201  31D2              xor dx,dx
00002203  F775EC            div word [di-0x14]
00002206  46                inc si
00002207  85C0              test ax,ax
00002209  89C1              mov cx,ax
0000220B  75DC              jnz 0x21e9
0000220D  84DB              test bl,bl
0000220F  7410              jz 0x2221
00002211  89F0              mov ax,si
00002213  29F8              sub ax,di
00002215  EB05              jmp short 0x221c
00002217  C606304046        mov byte [0x4030],0x46
0000221C  83F807            cmp ax,byte +0x7
0000221F  7EF6              jng 0x2217
00002221  8D5EFF            lea bx,[bp-0x1]
00002224  89F9              mov cx,di
00002226  EB0A              jmp short 0x2232
00002228  8A13              mov dl,[bp+di]
0000222A  8A01              mov al,[bx+di]
0000222C  8803              mov [bp+di],al
0000222E  4B                dec bx
0000222F  8811              mov [bx+di],dl
00002231  41                inc cx
00002232  39CB              cmp bx,cx
00002234  77F2              ja 0x2228
00002236  C606005A59        mov byte [0x5a00],0x59
0000223B  5B                pop bx
0000223C  5E                pop si
0000223D  5F                pop di
0000223E  5D                pop bp
0000223F  C3                ret
00002240  55                push bp
00002241  89E5              mov bp,sp
00002243  56                push si
00002244  53                push bx
00002245  83EC10            sub sp,byte +0x10
00002248  8D5D0C            lea bx,[di+0xc]
0000224B  8D75E8            lea si,[di-0x18]
0000224E  E98700            jmp word 0x22d8
00002251  0000              add [bx+si],al
00002253  8D4101            lea ax,[bx+di+0x1]
00002256  80FA25            cmp dl,0x25
00002259  894508            mov [di+0x8],ax
0000225C  0FB6C2            movzx ax,dl
0000225F  754B              jnz 0x22ac
00002261  8A5101            mov dl,[bx+di+0x1]
00002264  8D4102            lea ax,[bx+di+0x2]
00002267  894508            mov [di+0x8],ax
0000226A  80FA64            cmp dl,0x64
0000226D  741F              jz 0x228e
0000226F  7F0C              jg 0x227d
00002271  80FA58            cmp dl,0x58
00002274  7418              jz 0x228e
00002276  80FA63            cmp dl,0x63
00002279  7547              jnz 0x22c2
0000227B  EB29              jmp short 0x22a6
0000227D  80FA75            cmp dl,0x75
00002280  740C              jz 0x228e
00002282  80FA78            cmp dl,0x78
00002285  7407              jz 0x228e
00002287  80FA73            cmp dl,0x73
0000228A  7536              jnz 0x22c2
0000228C  EB26              jmp short 0x22b4
0000228E  8B03              mov ax,[bp+di]
00002290  83C304            add bx,byte +0x4
00002293  50                push ax
00002294  0FBEC2            movsx ax,dl
00002297  50                push ax
00002298  56                push si
00002299  E806FF            call word 0x21a2
0000229C  FF                db 0xff
0000229D  FF56E8            call word [bp-0x18]
000022A0  D9FE              fsin
000022A2  FF                db 0xff
000022A3  FF                db 0xff
000022A4  EB31              jmp short 0x22d7
000022A6  0FB603            movzx ax,[bp+di]
000022A9  83C304            add bx,byte +0x4
000022AC  50                push ax
000022AD  E872FE            call word 0x2122
000022B0  FF                db 0xff
000022B1  FF                db 0xff
000022B2  EB0B              jmp short 0x22bf
000022B4  8B03              mov ax,[bp+di]
000022B6  83C304            add bx,byte +0x4
000022B9  50                push ax
000022BA  E8BEFE            call word 0x217b
000022BD  FF                db 0xff
000022BE  FF58EB            call word far [bx+si-0x15]
000022C1  185050            sbb [bx+si+0x50],dl
000022C4  0FBEC2            movsx ax,dl
000022C7  50                push ax
000022C8  681729            push word 0x2917
000022CB  0000              add [bx+si],al
000022CD  E86EFF            call word 0x223e
000022D0  FF                db 0xff
000022D1  FF                db 0xff
000022D2  E845FE            call word 0x211a
000022D5  FF                db 0xff
000022D6  FF83C410          inc word [bp+di+0x10c4]
000022DA  8B4D08            mov cx,[di+0x8]
000022DD  8A11              mov dl,[bx+di]
000022DF  84D2              test dl,dl
000022E1  0F856CFF          jnz word 0x2251
000022E5  FF                db 0xff
000022E6  FF8D65F8          dec word [di-0x79b]
000022EA  5B                pop bx
000022EB  5E                pop si
000022EC  5D                pop bp
000022ED  C3                ret
000022EE  90                nop
000022EF  90                nop
000022F0  55                push bp
000022F1  E8CEFD            call word 0x20c2
000022F4  FF                db 0xff
000022F5  FFCD              dec bp
000022F7  16                push ss
000022F8  66E880FDFFFF      call dword 0x207e
000022FE  5D                pop bp
000022FF  C3                ret
00002300  55                push bp
00002301  89E5              mov bp,sp
00002303  53                push bx
00002304  83EC04            sub sp,byte +0x4
00002307  E88400            call word 0x238e
0000230A  0000              add [bx+si],al
0000230C  85C0              test ax,ax
0000230E  757B              jnz 0x238b
00002310  8B1D              mov bx,[di]
00002312  50                push ax
00002313  2B00              sub ax,[bx+si]
00002315  00C7              add bh,al
00002317  05802B            add ax,0x2b80
0000231A  0000              add [bx+si],al
0000231C  0000              add [bx+si],al
0000231E  0000              add [bx+si],al
00002320  891D              mov [di],bx
00002322  842B              test [bp+di],ch
00002324  0000              add [bx+si],al
00002326  52                push dx
00002327  52                push dx
00002328  50                push ax
00002329  53                push bx
0000232A  E89500            call word 0x23c2
0000232D  0000              add [bx+si],al
0000232F  83C410            add sp,byte +0x10
00002332  833B00            cmp word [bp+di],byte +0x0
00002335  7410              jz 0x2347
00002337  830580            add word [di],byte -0x80
0000233A  2B00              sub ax,[bx+si]
0000233C  0018              add [bx+si],bl
0000233E  85C0              test ax,ax
00002340  7405              jz 0x2347
00002342  83C318            add bx,byte +0x18
00002345  EBDF              jmp short 0x2326
00002347  833D80            cmp word [di],byte -0x80
0000234A  2B00              sub ax,[bx+si]
0000234C  0000              add [bx+si],al
0000234E  7429              jz 0x2379
00002350  83EC0C            sub sp,byte +0xc
00002353  6A00              push byte +0x0
00002355  E8CA00            call word 0x2422
00002358  0000              add [bx+si],al
0000235A  C1E80A            shr ax,byte 0xa
0000235D  A3582B            mov [0x2b58],ax
00002360  0000              add [bx+si],al
00002362  C7042400          mov word [si],0x24
00002366  0010              add [bx+si],dl
00002368  00E8              add al,ch
0000236A  B600              mov dh,0x0
0000236C  0000              add [bx+si],al
0000236E  83C410            add sp,byte +0x10
00002371  C1E80A            shr ax,byte 0xa
00002374  A35C2B            mov [0x2b5c],ax
00002377  0000              add [bx+si],al
00002379  E81E01            call word 0x249a
0000237C  0000              add [bx+si],al
0000237E  85C0              test ax,ax
00002380  7509              jnz 0x238b
00002382  8B5DFC            mov bx,[di-0x4]
00002385  C9                leave
00002386  E90D02            jmp word 0x2596
00002389  0000              add [bx+si],al
0000238B  8B5DFC            mov bx,[di-0x4]
0000238E  C9                leave
0000238F  C3                ret
00002390  55                push bp
00002391  E82EFD            call word 0x20c2
00002394  FF                db 0xff
00002395  FF                db 0xff
00002396  B80124            mov ax,0x2401
00002399  F9                stc
0000239A  CD15              int 0x15
0000239C  B80000            mov ax,0x0
0000239F  7303              jnc 0x23a4
000023A1  B80100            mov ax,0x1
000023A4  66E8D4FCFFFF      call dword 0x207e
000023AA  5D                pop bp
000023AB  C3                ret
000023AC  3E206573          and [ds:di+0x73],ah
000023B0  693A6564          imul di,[bp+si],word 0x6465
000023B4  69203D20          imul sp,[bx+si],word 0x203d
000023B8  307825            xor [bx+si+0x25],bh
000023BB  58                pop ax
000023BC  3A30              cmp dh,[bx+si]
000023BE  7825              js 0x23e5
000023C0  58                pop ax
000023C1  0A00              or al,[bx+si]
000023C3  90                nop
000023C4  55                push bp
000023C5  53                push bx
000023C6  57                push di
000023C7  56                push si
000023C8  8B4424            mov ax,[si+0x24]
000023CB  1483              adc al,0x83
000023CD  C00489            rol byte [si],byte 0x89
000023D0  C7                db 0xc7
000023D1  B80000            mov ax,0x0
000023D4  0000              add [bx+si],al
000023D6  89C6              mov si,ax
000023D8  8B5C24            mov bx,[si+0x24]
000023DB  18B91400          sbb [bx+di+0x14],bh
000023DF  0000              add [bx+si],al
000023E1  BA5041            mov dx,0x4150
000023E4  4D                dec bp
000023E5  53                push bx
000023E6  E8D9FC            call word 0x20c2
000023E9  FF                db 0xff
000023EA  FF8EC666          dec word [bp+0x66c6]
000023EE  B820E8            mov ax,0xe820
000023F1  0000              add [bx+si],al
000023F3  CD15              int 0x15
000023F5  667210            o32 jc 0x2408
000023F8  663D50414D53      cmp eax,0x534d4150
000023FE  667507            o32 jnz 0x2408
00002401  6683F914          cmp ecx,byte +0x14
00002405  667406            o32 jz 0x240e
00002408  66B900000000      mov ecx,0x0
0000240E  66E86AFCFFFF      call dword 0x207e
00002414  8B4424            mov ax,[si+0x24]
00002417  1489              adc al,0x89
00002419  0889D85E          or [bx+di+0x5ed8],cl
0000241D  5F                pop di
0000241E  5B                pop bx
0000241F  5D                pop bp
00002420  C3                ret
00002421  90                nop
00002422  90                nop
00002423  90                nop
00002424  55                push bp
00002425  89E5              mov bp,sp
00002427  57                push di
00002428  56                push si
00002429  53                push bx
0000242A  31DB              xor bx,bx
0000242C  83EC08            sub sp,byte +0x8
0000242F  A1842B            mov ax,[0x2b84]
00002432  0000              add [bx+si],al
00002434  8B4D08            mov cx,[di+0x8]
00002437  8945F0            mov [di-0x10],ax
0000243A  0305              add ax,[di]
0000243C  802B00            sub byte [bp+di],0x0
0000243F  008945EC          add [bx+di-0x13bb],cl
00002443  8B75F0            mov si,[di-0x10]
00002446  31FF              xor di,di
00002448  EB34              jmp short 0x247e
0000244A  837E1401          cmp word [bp+0x14],byte +0x1
0000244E  7523              jnz 0x2473
00002450  8B5608            mov dx,[bp+0x8]
00002453  8B4604            mov ax,[bp+0x4]
00002456  39DA              cmp dx,bx
00002458  7719              ja 0x2473
0000245A  7204              jc 0x2460
0000245C  39C8              cmp ax,cx
0000245E  7713              ja 0x2473
00002460  03460C            add ax,[bp+0xc]
00002463  135610            adc dx,[bp+0x10]
00002466  39DA              cmp dx,bx
00002468  7209              jc 0x2473
0000246A  7704              ja 0x2470
0000246C  39C8              cmp ax,cx
0000246E  7603              jna 0x2473
00002470  47                inc di
00002471  EB04              jmp short 0x2477
00002473  89C8              mov ax,cx
00002475  89DA              mov dx,bx
00002477  83C618            add si,byte +0x18
0000247A  89C1              mov cx,ax
0000247C  89D3              mov bx,dx
0000247E  3B75EC            cmp si,[di-0x14]
00002481  72C7              jc 0x244a
00002483  85FF              test di,di
00002485  75BC              jnz 0x2443
00002487  83FB00            cmp bx,byte +0x0
0000248A  7603              jna 0x248f
0000248C  83C9FF            or cx,byte -0x1
0000248F  89C8              mov ax,cx
00002491  2B4508            sub ax,[di+0x8]
00002494  5A                pop dx
00002495  59                pop cx
00002496  5B                pop bx
00002497  5E                pop si
00002498  5F                pop di
00002499  5D                pop bp
0000249A  C3                ret
0000249B  90                nop
0000249C  55                push bp
0000249D  89E5              mov bp,sp
0000249F  83EC08            sub sp,byte +0x8
000024A2  A14C2B            mov ax,[0x2b4c]
000024A5  0000              add [bx+si],al
000024A7  C705BC2B          mov word [di],0x2bbc
000024AB  0000              add [bx+si],al
000024AD  0002              add [bp+si],al
000024AF  0000              add [bx+si],al
000024B1  C705C02B          mov word [di],0x2bc0
000024B5  0000              add [bx+si],al
000024B7  0000              add [bx+si],al
000024B9  0000              add [bx+si],al
000024BB  84C0              test al,al
000024BD  780A              js 0x24c9
000024BF  83EC0C            sub sp,byte +0xc
000024C2  683F29            push word 0x293f
000024C5  0000              add [bx+si],al
000024C7  EB64              jmp short 0x252d
000024C9  68B42B            push word 0x2bb4
000024CC  0000              add [bx+si],al
000024CE  68B02B            push word 0x2bb0
000024D1  0000              add [bx+si],al
000024D3  68AC2B            push word 0x2bac
000024D6  0000              add [bx+si],al
000024D8  50                push ax
000024D9  E86A03            call word 0x2846
000024DC  0000              add [bx+si],al
000024DE  83C410            add sp,byte +0x10
000024E1  85C0              test ax,ax
000024E3  740A              jz 0x24ef
000024E5  83EC0C            sub sp,byte +0xc
000024E8  685F29            push word 0x295f
000024EB  0000              add [bx+si],al
000024ED  EB3E              jmp short 0x252d
000024EF  6B15B0            imul dx,[di],byte -0x50
000024F2  2B00              sub ax,[bx+si]
000024F4  003F              add [bx],bh
000024F6  6905AC2B          imul ax,[di],word 0x2bac
000024FA  0000              add [bx+si],al
000024FC  C13E00008B        sar word [0x0],byte 0x8b
00002501  0DB42B            or ax,0x2bb4
00002504  0000              add [bx+si],al
00002506  01D0              add ax,dx
00002508  31D2              xor dx,dx
0000250A  01C8              add ax,cx
0000250C  A3B82B            mov [0x2bb8],ax
0000250F  0000              add [bx+si],al
00002511  8D41FF            lea ax,[bx+di-0x1]
00002514  83F83E            cmp ax,byte +0x3e
00002517  7621              jna 0x253a
00002519  50                push ax
0000251A  50                push ax
0000251B  51                push cx
0000251C  687A29            push word 0x297a
0000251F  0000              add [bx+si],al
00002521  E81AFD            call word 0x223e
00002524  FF                db 0xff
00002525  FFC7              inc di
00002527  0424              add al,0x24
00002529  91                xchg ax,cx
0000252A  2900              sub [bx+si],ax
0000252C  00E8              add al,ch
0000252E  0E                push cs
0000252F  FD                std
00002530  FF                db 0xff
00002531  FF                db 0xff
00002532  BA0100            mov dx,0x1
00002535  0000              add [bx+si],al
00002537  83C410            add sp,byte +0x10
0000253A  89D0              mov ax,dx
0000253C  C9                leave
0000253D  C3                ret
0000253E  90                nop
0000253F  90                nop
00002540  55                push bp
00002541  89E5              mov bp,sp
00002543  53                push bx
00002544  57                push di
00002545  56                push si
00002546  8B4508            mov ax,[di+0x8]
00002549  88C5              mov ch,al
0000254B  8A750C            mov dh,[di+0xc]
0000254E  8A15              mov dl,[di]
00002550  4C                dec sp
00002551  2B00              sub ax,[bx+si]
00002553  008A4510          add [bp+si+0x1045],cl
00002557  6683E03F          and eax,byte +0x3f
0000255B  88C1              mov cl,al
0000255D  B402              mov ah,0x2
0000255F  8A4514            mov al,[di+0x14]
00002562  6689C7            mov edi,eax
00002565  668B5D18          mov ebx,[di+0x18]
00002569  E856FB            call word 0x20c2
0000256C  FF                db 0xff
0000256D  FF8EC3BE          dec word [bp-0x413d]
00002571  0300              add ax,[bx+si]
00002573  BB0000            mov bx,0x0
00002576  89F8              mov ax,di
00002578  CD13              int 0x13
0000257A  730E              jnc 0x258a
0000257C  B301              mov bl,0x1
0000257E  31C0              xor ax,ax
00002580  CD13              int 0x13
00002582  4E                dec si
00002583  83FE00            cmp si,byte +0x0
00002586  7402              jz 0x258a
00002588  EBE9              jmp short 0x2573
0000258A  66E8EEFAFFFF      call dword 0x207e
00002590  88D8              mov al,bl
00002592  5E                pop si
00002593  5F                pop di
00002594  5B                pop bx
00002595  5D                pop bp
00002596  C3                ret
00002597  90                nop
00002598  55                push bp
00002599  B90900            mov cx,0x9
0000259C  0000              add [bx+si],al
0000259E  89E5              mov bp,sp
000025A0  57                push di
000025A1  56                push si
000025A2  BEA42A            mov si,0x2aa4
000025A5  0000              add [bx+si],al
000025A7  53                push bx
000025A8  83EC40            sub sp,byte +0x40
000025AB  8D7DD0            lea di,[di-0x30]
000025AE  F3A5              rep movsw
000025B0  680000            push word 0x0
000025B3  0100              add [bx+si],ax
000025B5  680004            push word 0x400
000025B8  0000              add [bx+si],al
000025BA  6A16              push byte +0x16
000025BC  E86F01            call word 0x272e
000025BF  0000              add [bx+si],al
000025C1  83C410            add sp,byte +0x10
000025C4  66813DFE010100    cmp dword [di],0x101fe
000025CB  55                push bp
000025CC  AA                stosb
000025CD  740D              jz 0x25dc
000025CF  83EC0C            sub sp,byte +0xc
000025D2  68D729            push word 0x29d7
000025D5  0000              add [bx+si],al
000025D7  E9B900            jmp word 0x2693
000025DA  0000              add [bx+si],al
000025DC  803DF1            cmp byte [di],0xf1
000025DF  0101              add [bx+di],ax
000025E1  004076            add [bx+si+0x76],al
000025E4  0D83EC            or ax,0xec83
000025E7  0C68              or al,0x68
000025E9  FB                sti
000025EA  2900              sub [bx+si],ax
000025EC  00E9              add cl,ch
000025EE  A30000            mov [0x0],ax
000025F1  00813D02          add [bx+di+0x23d],al
000025F5  0201              add al,[bx+di]
000025F7  004864            add [bx+si+0x64],cl
000025FA  7253              jc 0x264f
000025FC  740D              jz 0x260b
000025FE  83EC0C            sub sp,byte +0xc
00002601  68242A            push word 0x2a24
00002604  0000              add [bx+si],al
00002606  E98A00            jmp word 0x2693
00002609  0000              add [bx+si],al
0000260B  66813D06020100    cmp dword [di],0x10206
00002612  0202              add al,[bp+si]
00002614  770A              ja 0x2620
00002616  83EC0C            sub sp,byte +0xc
00002619  68492A            push word 0x2a49
0000261C  0000              add [bx+si],al
0000261E  EB75              jmp short 0x2695
00002620  F60511            test byte [di],0x11
00002623  0201              add al,[bx+di]
00002625  0001              add [bx+di],al
00002627  750A              jnz 0x2633
00002629  83EC0C            sub sp,byte +0xc
0000262C  68602A            push word 0x2a60
0000262F  0000              add [bx+si],al
00002631  EB62              jmp short 0x2695
00002633  66C705FA010100    mov dword [di],0x101fa
0000263A  FF                db 0xff
0000263B  FF                db 0xff
0000263C  BA0000            mov dx,0x0
0000263F  0200              add al,[bx+si]
00002641  C60510            mov byte [di],0x10
00002644  0201              add al,[bx+di]
00002646  00FF              add bh,bh
00002648  8D4DD0            lea cx,[di-0x30]
0000264B  66C70524020100    mov dword [di],0x10224
00002652  007EC6            add [bp-0x3a],bh
00002655  051102            add ax,0x211
00002658  0100              add [bx+si],ax
0000265A  81C70528          add di,0x2805
0000265E  0201              add al,[bx+di]
00002660  0000              add [bx+si],al
00002662  0002              add [bp+si],al
00002664  00EB              add bl,ch
00002666  0488              add al,0x88
00002668  024142            add al,[bx+di+0x42]
0000266B  A12802            mov ax,[0x228]
0000266E  0100              add [bx+si],ax
00002670  05FF00            add ax,0xff
00002673  0000              add [bx+si],al
00002675  39C2              cmp dx,ax
00002677  7306              jnc 0x267f
00002679  8A01              mov al,[bx+di]
0000267B  84C0              test al,al
0000267D  75E8              jnz 0x2667
0000267F  C60200            mov byte [bp+si],0x0
00002682  0FB605            movzx ax,[di]
00002685  F1                int1
00002686  0101              add [bx+di],ax
00002688  0085C075          add [di+0x75c0],al
0000268C  1283EC0C          adc al,[bp+di+0xcec]
00002690  686D2A            push word 0x2a6d
00002693  0000              add [bx+si],al
00002695  E8A6FB            call word 0x223e
00002698  FF                db 0xff
00002699  FF                db 0xff
0000269A  E98300            jmp word 0x2720
0000269D  0000              add [bx+si],al
0000269F  8D5801            lea bx,[bx+si+0x1]
000026A2  C1E309            shl bx,byte 0x9
000026A5  52                push dx
000026A6  680004            push word 0x400
000026A9  0100              add [bx+si],ax
000026AB  8D8300FC          lea ax,[bp+di-0x400]
000026AF  FF                db 0xff
000026B0  FF506A            call word [bx+si+0x6a]
000026B3  18E8              sbb al,ch
000026B5  7700              ja 0x26b7
000026B7  0000              add [bx+si],al
000026B9  83C40C            add sp,byte +0xc
000026BC  B80000            mov ax,0x0
000026BF  A00068            mov al,[0x6800]
000026C2  0000              add [bx+si],al
000026C4  1000              adc [bx+si],al
000026C6  29D8              sub ax,bx
000026C8  C1EB09            shr bx,byte 0x9
000026CB  50                push ax
000026CC  83C316            add bx,byte +0x16
000026CF  53                push bx
000026D0  E85B00            call word 0x272e
000026D3  0000              add [bx+si],al
000026D5  A12C02            mov ax,[0x22c]
000026D8  0100              add [bx+si],ax
000026DA  83C410            add sp,byte +0x10
000026DD  C7051802          mov word [di],0x218
000026E1  0100              add [bx+si],ax
000026E3  0000              add [bx+si],al
000026E5  80023D            add byte [bp+si],0x3d
000026E8  0000              add [bx+si],al
000026EA  0005              add [di],al
000026EC  770F              ja 0x26fd
000026EE  2D0000            sub ax,0x0
000026F1  800225            add byte [bp+si],0x25
000026F4  00F0              add al,dh
000026F6  FF                db 0xff
000026F7  FFA31802          jmp word [bp+di+0x218]
000026FB  0100              add [bx+si],ax
000026FD  C7051C02          mov word [di],0x21c
00002701  0100              add [bx+si],ax
00002703  0000              add [bx+si],al
00002705  800250            add byte [bp+si],0x50
00002708  FF35              push word [di]
0000270A  1802              sbb [bp+si],al
0000270C  0100              add [bx+si],ax
0000270E  680000            push word 0x0
00002711  800268            add byte [bp+si],0x68
00002714  16                push ss
00002715  50                push ax
00002716  0000              add [bx+si],al
00002718  E81300            call word 0x272e
0000271B  0000              add [bx+si],al
0000271D  E8BE01            call word 0x28de
00002720  0000              add [bx+si],al
00002722  83C410            add sp,byte +0x10
00002725  8D65F4            lea sp,[di-0xc]
00002728  5B                pop bx
00002729  5E                pop si
0000272A  5F                pop di
0000272B  5D                pop bp
0000272C  C3                ret
0000272D  90                nop
0000272E  90                nop
0000272F  90                nop
00002730  55                push bp
00002731  89E5              mov bp,sp
00002733  57                push di
00002734  56                push si
00002735  53                push bx
00002736  83EC0C            sub sp,byte +0xc
00002739  8B550C            mov dx,[di+0xc]
0000273C  837D0800          cmp word [di+0x8],byte +0x0
00002740  790A              jns 0x274c
00002742  83EC0C            sub sp,byte +0xc
00002745  68C82A            push word 0x2ac8
00002748  0000              add [bx+si],al
0000274A  EB0C              jmp short 0x2758
0000274C  85D2              test dx,dx
0000274E  7F1F              jg 0x276f
00002750  83EC0C            sub sp,byte +0xc
00002753  68DA2A            push word 0x2ada
00002756  0000              add [bx+si],al
00002758  E8E3FA            call word 0x223e
0000275B  FF                db 0xff
0000275C  FF                db 0xff
0000275D  E88EFB            call word 0x22ee
00002760  FF                db 0xff
00002761  FF                db 0xff
00002762  B80100            mov ax,0x1
00002765  0000              add [bx+si],al
00002767  83C410            add sp,byte +0x10
0000276A  E9D100            jmp word 0x283e
0000276D  0000              add [bx+si],al
0000276F  89D0              mov ax,dx
00002771  89D3              mov bx,dx
00002773  25FF01            and ax,0x1ff
00002776  0000              add [bx+si],al
00002778  29C3              sub bx,ax
0000277A  85C0              test ax,ax
0000277C  7406              jz 0x2784
0000277E  81C30002          add bx,0x200
00002782  0000              add [bx+si],al
00002784  8B4510            mov ax,[di+0x10]
00002787  8945F0            mov [di-0x10],ax
0000278A  85DB              test bx,bx
0000278C  0F84AC00          jz word 0x283c
00002790  0000              add [bx+si],al
00002792  81FBFF81          cmp bx,0x81ff
00002796  0000              add [bx+si],al
00002798  7E0D              jng 0x27a7
0000279A  81EB0080          sub bx,0x8000
0000279E  0000              add [bx+si],al
000027A0  BE4000            mov si,0x40
000027A3  0000              add [bx+si],al
000027A5  EB0E              jmp short 0x27b5
000027A7  89D8              mov ax,bx
000027A9  B90002            mov cx,0x200
000027AC  0000              add [bx+si],al
000027AE  99                cwd
000027AF  31DB              xor bx,bx
000027B1  F7F9              idiv cx
000027B3  89C6              mov si,ax
000027B5  8B4508            mov ax,[di+0x8]
000027B8  31D2              xor dx,dx
000027BA  83EC0C            sub sp,byte +0xc
000027BD  F735              div word [di]
000027BF  B42B              mov ah,0x2b
000027C1  0000              add [bx+si],al
000027C3  680008            push word 0x800
000027C6  0000              add [bx+si],al
000027C8  56                push si
000027C9  8D7A01            lea di,[bp+si+0x1]
000027CC  31D2              xor dx,dx
000027CE  F735              div word [di]
000027D0  B02B              mov al,0x2b
000027D2  0000              add [bx+si],al
000027D4  57                push di
000027D5  52                push dx
000027D6  50                push ax
000027D7  8955EC            mov [di-0x14],dx
000027DA  8945E8            mov [di-0x18],ax
000027DD  E85EFD            call word 0x253e
000027E0  FF                db 0xff
000027E1  FF83C420          inc word [bp+di+0x20c4]
000027E5  85C0              test ax,ax
000027E7  7422              jz 0x280b
000027E9  83EC0C            sub sp,byte +0xc
000027EC  56                push si
000027ED  57                push di
000027EE  FF75EC            push word [di-0x14]
000027F1  FF75E8            push word [di-0x18]
000027F4  68EF2A            push word 0x2aef
000027F7  0000              add [bx+si],al
000027F9  E842FA            call word 0x223e
000027FC  FF                db 0xff
000027FD  FF83C414          inc word [bp+di+0x14c4]
00002801  68082B            push word 0x2b08
00002804  0000              add [bx+si],al
00002806  E94DFF            jmp word 0x2756
00002809  FF                db 0xff
0000280A  FF89F7C1          dec word [bx+di-0x3e09]
0000280E  E709              out 0x9,ax
00002810  50                push ax
00002811  57                push di
00002812  680080            push word 0x8000
00002815  0000              add [bx+si],al
00002817  FF75F0            push word [di-0x10]
0000281A  E87900            call word 0x2896
0000281D  0000              add [bx+si],al
0000281F  83C410            add sp,byte +0x10
00002822  85C0              test ax,ax
00002824  750D              jnz 0x2833
00002826  83EC0C            sub sp,byte +0xc
00002829  68212B            push word 0x2b21
0000282C  0000              add [bx+si],al
0000282E  E925FF            jmp word 0x2756
00002831  FF                db 0xff
00002832  FF01              inc word [bx+di]
00002834  7DF0              jnl 0x2826
00002836  017508            add [di+0x8],si
00002839  E94CFF            jmp word 0x2788
0000283C  FF                db 0xff
0000283D  FF31              push word [bx+di]
0000283F  C08D65F45B        ror byte [di-0xb9b],byte 0x5b
00002844  5E                pop si
00002845  5F                pop di
00002846  5D                pop bp
00002847  C3                ret
00002848  55                push bp
00002849  89E5              mov bp,sp
0000284B  53                push bx
0000284C  57                push di
0000284D  8A5508            mov dl,[di+0x8]
00002850  E86FF8            call word 0x20c2
00002853  FF                db 0xff
00002854  FFB408CD          push word [si-0x32f8]
00002858  1384E475          adc ax,[si+0x75e4]
0000285C  07                pop es
0000285D  F6C13F            test cl,0x3f
00002860  7502              jnz 0x2864
00002862  B460              mov ah,0x60
00002864  88E3              mov bl,ah
00002866  66E812F8FFFF      call dword 0x207e
0000286C  8D6C24            lea bp,[si+0x24]
0000286F  0888F040          or [bx+si+0x40f0],cl
00002873  8B7D10            mov di,[di+0x10]
00002876  8907              mov [bx],ax
00002878  31C0              xor ax,ax
0000287A  88C8              mov al,cl
0000287C  243F              and al,0x3f
0000287E  8B7D14            mov di,[di+0x14]
00002881  8907              mov [bx],ax
00002883  C0E906            shr cl,byte 0x6
00002886  88CC              mov ah,cl
00002888  88E8              mov al,ch
0000288A  40                inc ax
0000288B  8B7D0C            mov di,[di+0xc]
0000288E  8907              mov [bx],ax
00002890  31C0              xor ax,ax
00002892  88D8              mov al,bl
00002894  5F                pop di
00002895  5B                pop bx
00002896  5D                pop bp
00002897  C3                ret
00002898  55                push bp
00002899  89E5              mov bp,sp
0000289B  57                push di
0000289C  56                push si
0000289D  53                push bx
0000289E  8B4D10            mov cx,[di+0x10]
000028A1  8B750C            mov si,[di+0xc]
000028A4  8B7D08            mov di,[di+0x8]
000028A7  39F7              cmp di,si
000028A9  7305              jnc 0x28b0
000028AB  FC                cld
000028AC  F3A4              rep movsb
000028AE  EB24              jmp short 0x28d4
000028B0  8B550C            mov dx,[di+0xc]
000028B3  8B4510            mov ax,[di+0x10]
000028B6  83E801            sub ax,byte +0x1
000028B9  8D1C              lea bx,[si]
000028BB  028B5508          add cl,[bp+di+0x855]
000028BF  8B4510            mov ax,[di+0x10]
000028C2  83E801            sub ax,byte +0x1
000028C5  01C2              add dx,ax
000028C7  8B4510            mov ax,[di+0x10]
000028CA  89C1              mov cx,ax
000028CC  89DE              mov si,bx
000028CE  89D7              mov di,dx
000028D0  FD                std
000028D1  F3A4              rep movsb
000028D3  FC                cld
000028D4  5B                pop bx
000028D5  5E                pop si
000028D6  5F                pop di
000028D7  5D                pop bp
000028D8  C3                ret
000028D9  90                nop
000028DA  90                nop
000028DB  90                nop
000028DC  4F                dec di
000028DD  4B                dec bx
000028DE  0A00              or al,[bx+si]
000028E0  50                push ax
000028E1  68DC28            push word 0x28dc
000028E4  0000              add [bx+si],al
000028E6  E855F9            call word 0x223e
000028E9  FF                db 0xff
000028EA  FF5858            call word far [bx+si+0x58]
000028ED  BB0000            mov bx,0x0
000028F0  0100              add [bx+si],ax
000028F2  C1EB04            shr bx,byte 0x4
000028F5  89D8              mov ax,bx
000028F7  83C020            add ax,byte +0x20
000028FA  A31529            mov [0x2915],ax
000028FD  0000              add [bx+si],al
000028FF  E8C0F7            call word 0x20c2
00002902  FF                db 0xff
00002903  FF                db 0xff
00002904  FA                cli
00002905  8ED3              mov ss,bx
00002907  BC0090            mov sp,0x9000
0000290A  8EDB              mov ds,bx
0000290C  8EC3              mov es,bx
0000290E  8EE3              mov fs,bx
00002910  8EEB              mov gs,bx
00002912  EA00000000        jmp word 0x0:0x0
00002917  7462              jz 0x297b
00002919  6C                insb
0000291A  5F                pop di
0000291B  7072              jo 0x298f
0000291D  696E746620        imul bp,[bp+0x74],word 0x2066
00002922  6E                outsb
00002923  61                popaw
00002924  6F                outsw
00002925  207265            and [bp+si+0x65],dh
00002928  636F6E            arpl [bx+0x6e],bp
0000292B  686563            push word 0x6365
0000292E  65206F20          and [gs:bx+0x20],ch
00002932  666F              outsd
00002934  726D              jc 0x29a3
00002936  61                popaw
00002937  746F              jz 0x29a8
00002939  2022              and [bp+si],ah
0000293B  256322            and ax,0x2263
0000293E  004552            add [di+0x52],al
00002941  52                push dx
00002942  4F                dec di
00002943  3A20              cmp ah,[bx+si]
00002945  2120              and [bx+si],sp
00002947  286375            sub [bp+di+0x75],ah
0000294A  7272              jc 0x29be
0000294C  656E              gs outsb
0000294E  745F              jz 0x29af
00002950  647269            fs jc 0x29bc
00002953  7665              jna 0x29ba
00002955  20262030          and [0x3020],ah
00002959  7838              js 0x2993
0000295B  3029              xor [bx+di],ch
0000295D  0A00              or al,[bx+si]
0000295F  45                inc bp
00002960  52                push dx
00002961  52                push dx
00002962  4F                dec di
00002963  3A20              cmp ah,[bx+si]
00002965  696E743133        imul bp,[bp+0x74],word 0x3331
0000296A  5F                pop di
0000296B  61                popaw
0000296C  683038            push word 0x3830
0000296F  2829              sub [bx+di],ch
00002971  206661            and [bp+0x61],ah
00002974  6C                insb
00002975  686F75            push word 0x756f
00002978  0A00              or al,[bx+si]
0000297A  627566            bound si,[di+0x66]
0000297D  5F                pop di
0000297E  67656F            gs a32 outsw
00002981  6D                insw
00002982  2E7365            cs jnc 0x29ea
00002985  63746F            arpl [si+0x6f],si
00002988  7273              jc 0x29fd
0000298A  203D              and [di],bh
0000298C  2025              and [di],ah
0000298E  640A00            or al,[fs:bx+si]
00002991  4F                dec di
00002992  206EC3            and [bp-0x3d],ch
00002995  BA6D65            mov dx,0x656d
00002998  726F              jc 0x2a09
0000299A  206465            and [si+0x65],ah
0000299D  207365            and [bp+di+0x65],dh
000029A0  746F              jz 0x2a11
000029A2  7265              jc 0x2a09
000029A4  7320              jnc 0x29c6
000029A6  706F              jo 0x2a17
000029A8  7220              jc 0x29ca
000029AA  7472              jz 0x2a1e
000029AC  696C686120        imul bp,[si+0x68],word 0x2061
000029B1  6E                outsb
000029B2  61                popaw
000029B3  6F                outsw
000029B4  20706F            and [bx+si+0x6f],dh
000029B7  6465207365        and [gs:bp+di+0x65],dh
000029BC  7220              jc 0x29de
000029BE  6D                insw
000029BF  61                popaw
000029C0  696F722071        imul bp,[bx+0x72],word 0x7120
000029C5  7565              jnz 0x2a2c
000029C7  2036332C          and [0x2c33],dh
000029CB  206E65            and [bp+0x65],ch
000029CE  6D                insw
000029CF  207A65            and [bp+si+0x65],bh
000029D2  726F              jc 0x2a43
000029D4  2E0A00            or al,[cs:bx+si]
000029D7  6C                insb
000029D8  682D3E            push word 0x3e2d
000029DB  626F6F            bound bp,[bx+0x6f]
000029DE  745F              jz 0x2a3f
000029E0  666C              o32 insb
000029E2  61                popaw
000029E3  672021            and [ecx],ah
000029E6  3D2042            cmp ax,0x4220
000029E9  4F                dec di
000029EA  4F                dec di
000029EB  54                push sp
000029EC  53                push bx
000029ED  45                inc bp
000029EE  43                inc bx
000029EF  5F                pop di
000029F0  53                push bx
000029F1  49                dec cx
000029F2  47                inc di
000029F3  4E                dec si
000029F4  41                inc cx
000029F5  54                push sp
000029F6  55                push bp
000029F7  52                push dx
000029F8  45                inc bp
000029F9  0A00              or al,[bx+si]
000029FB  6C                insb
000029FC  682D3E            push word 0x3e2d
000029FF  7365              jnc 0x2a66
00002A01  7475              jz 0x2a78
00002A03  705F              jo 0x2a64
00002A05  7365              jnc 0x2a6c
00002A07  637473            arpl [si+0x73],si
00002A0A  203E204C          and [0x4c20],bh
00002A0E  49                dec cx
00002A0F  4E                dec si
00002A10  55                push bp
00002A11  58                pop ax
00002A12  5F                pop di
00002A13  4D                dec bp
00002A14  41                inc cx
00002A15  58                pop ax
00002A16  5F                pop di
00002A17  53                push bx
00002A18  45                inc bp
00002A19  54                push sp
00002A1A  55                push bp
00002A1B  50                push ax
00002A1C  5F                pop di
00002A1D  53                push bx
00002A1E  45                inc bp
00002A1F  43                inc bx
00002A20  54                push sp
00002A21  53                push bx
00002A22  0A00              or al,[bx+si]
00002A24  6C                insb
00002A25  682D3E            push word 0x3e2d
00002A28  686561            push word 0x6165
00002A2B  64657220          gs jc 0x2a4f
00002A2F  213D              and [di],di
00002A31  204C49            and [si+0x49],cl
00002A34  4E                dec si
00002A35  55                push bp
00002A36  58                pop ax
00002A37  5F                pop di
00002A38  4D                dec bp
00002A39  41                inc cx
00002A3A  47                inc di
00002A3B  49                dec cx
00002A3C  43                inc bx
00002A3D  5F                pop di
00002A3E  53                push bx
00002A3F  49                dec cx
00002A40  47                inc di
00002A41  4E                dec si
00002A42  41                inc cx
00002A43  54                push sp
00002A44  55                push bp
00002A45  52                push dx
00002A46  45                inc bp
00002A47  0A00              or al,[bx+si]
00002A49  6C                insb
00002A4A  682D3E            push word 0x3e2d
00002A4D  7665              jna 0x2ab4
00002A4F  7273              jc 0x2ac4
00002A51  696F6E203C        imul bp,[bx+0x6e],word 0x3c20
00002A56  2030              and [bx+si],dh
00002A58  7830              js 0x2a8a
00002A5A  3230              xor dh,[bx+si]
00002A5C  3329              xor bp,[bx+di]
00002A5E  0A00              or al,[bx+si]
00002A60  2120              and [bx+si],sp
00002A62  626967            bound bp,[bx+di+0x67]
00002A65  5F                pop di
00002A66  6C                insb
00002A67  696E75780A        imul bp,[bp+0x75],word 0xa78
00002A6C  0021              add [bx+di],ah
00002A6E  207365            and [bp+di+0x65],dh
00002A71  7475              jz 0x2ae8
00002A73  705F              jo 0x2ad4
00002A75  7365              jnc 0x2adc
00002A77  637473            arpl [si+0x73],si
00002A7A  0A00              or al,[bx+si]
00002A7C  6461              fs popaw
00002A7E  7461              jz 0x2ae1
00002A80  5F                pop di
00002A81  6C                insb
00002A82  656E              gs outsb
00002A84  203E206C          and [0x6c20],bh
00002A88  656E              gs outsb
00002A8A  5F                pop di
00002A8B  766D              jna 0x2afa
00002A8D  6C                insb
00002A8E  696E757A20        imul bp,[bp+0x75],word 0x207a
00002A93  7C7C              jl 0x2b11
00002A95  206461            and [si+0x61],ah
00002A98  7461              jz 0x2afb
00002A9A  5F                pop di
00002A9B  6C                insb
00002A9C  656E              gs outsb
00002A9E  203C              and [si],bh
00002AA0  2030              and [bx+si],dh
00002AA2  0A00              or al,[bx+si]
00002AA4  626F6F            bound bp,[bx+0x6f]
00002AA7  743D              jz 0x2ae6
00002AA9  636173            arpl [bx+di+0x73],sp
00002AAC  7065              jo 0x2b13
00002AAE  7220              jc 0x2ad0
00002AB0  6C                insb
00002AB1  6F                outsw
00002AB2  63616C            arpl [bx+di+0x6c],sp
00002AB5  653D7074          gs cmp ax,0x7470
00002AB9  5F                pop di
00002ABA  42                inc dx
00002ABB  52                push dx
00002ABC  207065            and [bx+si+0x65],dh
00002ABF  7273              jc 0x2b34
00002AC1  697374656E        imul si,[bp+di+0x74],word 0x6e65
00002AC6  7400              jz 0x2ac8
00002AC8  45                inc bp
00002AC9  52                push dx
00002ACA  52                push dx
00002ACB  4F                dec di
00002ACC  3A20              cmp ah,[bx+si]
00002ACE  7365              jnc 0x2b35
00002AD0  63746F            arpl [si+0x6f],si
00002AD3  7220              jc 0x2af5
00002AD5  3C20              cmp al,0x20
00002AD7  300A              xor [bp+si],cl
00002AD9  004552            add [di+0x52],al
00002ADC  52                push dx
00002ADD  4F                dec di
00002ADE  3A20              cmp ah,[bx+si]
00002AE0  627974            bound di,[bx+di+0x74]
00002AE3  655F              gs pop di
00002AE5  6C                insb
00002AE6  656E              gs outsb
00002AE8  203C              and [si],bh
00002AEA  3D2030            cmp ax,0x3020
00002AED  0A00              or al,[bx+si]
00002AEF  43                inc bx
00002AF0  48                dec ax
00002AF1  53                push bx
00002AF2  2825              sub [di],ah
00002AF4  642C25            fs sub al,0x25
00002AF7  642C25            fs sub al,0x25
00002AFA  642920            sub [fs:bx+si],sp
00002AFD  6E                outsb
00002AFE  7365              jnc 0x2b65
00002B00  6320              arpl [bx+si],sp
00002B02  3D2025            cmp ax,0x2520
00002B05  640A00            or al,[fs:bx+si]
00002B08  45                inc bp
00002B09  52                push dx
00002B0A  52                push dx
00002B0B  4F                dec di
00002B0C  3A20              cmp ah,[bx+si]
00002B0E  696E743133        imul bp,[bp+0x74],word 0x3331
00002B13  5F                pop di
00002B14  61                popaw
00002B15  683032            push word 0x3230
00002B18  206661            and [bp+0x61],ah
00002B1B  6C                insb
00002B1C  686F75            push word 0x756f
00002B1F  0A00              or al,[bx+si]
00002B21  45                inc bp
00002B22  52                push dx
00002B23  52                push dx
00002B24  4F                dec di
00002B25  3A20              cmp ah,[bx+si]
00002B27  677275            jc 0x2b9f
00002B2A  625F6D            bound bx,[bx+0x6d]
00002B2D  656D              gs insw
00002B2F  6D                insw
00002B30  6F                outsw
00002B31  7665              jna 0x2b98
00002B33  2829              sub [bx+di],ch
00002B35  206661            and [bp+0x61],ah
00002B38  6C                insb
00002B39  686F75            push word 0x756f
00002B3C  0A00              or al,[bx+si]
00002B3E  0000              add [bx+si],al
00002B40  0E                push cs
00002B41  0000              add [bx+si],al
00002B43  00F0              add al,dh
00002B45  7B00              jpo 0x2b47
00002B47  00616C            add [bx+di+0x6c],ah
00002B4A  686F75            push word 0x756f
00002B4D  0A00              or al,[bx+si]
00002B4F  45                inc bp
00002B50  52                push dx
00002B51  52                push dx
00002B52  4F                dec di
00002B53  3A20              cmp ah,[bx+si]
00002B55  677275            jc 0x2bcd
00002B58  625F6D            bound bx,[bx+0x6d]
00002B5B  656D              gs insw
00002B5D  6D                insw
00002B5E  6F                outsw
00002B5F  7665              jna 0x2bc6
00002B61  2829              sub [bx+di],ch
00002B63  206661            and [bp+0x61],ah
00002B66  6C                insb
00002B67  686F75            push word 0x756f
00002B6A  0A00              or al,[bx+si]
00002B6C  0E                push cs
00002B6D  0000              add [bx+si],al
00002B6F  00F0              add al,dh
00002B71  7B00              jpo 0x2b73
00002B73  0000              add [bx+si],al
00002B75  0000              add [bx+si],al
00002B77  0000              add [bx+si],al

