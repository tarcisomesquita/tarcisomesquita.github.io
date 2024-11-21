
dd if=copia_setores.img of=copia_setores2.img bs=1 count=1024 skip=512

./ndisasm -b 16 -o c003eh copia_setores2.img >> int10.asm

As funcoes mais comuns estao em 0xC377f

C003E  9C                pushfw

C003F  80FC0F            cmp ah,0x0f
C0042  7506              jnz 0xC004a
C0044  E83363            call word 0xC637a
C0047  E9C500            jmp word 0xC010f

C004A  80FC1A            cmp ah,0x1a
C004D  7506              jnz 0xC0055
C004F  E87A6E            call word 0xC6ecc
C0052  E9BA00            jmp word 0xC010f

C0055  80FC0B            cmp ah,0x0b
C0058  7506              jnz 0xC0060
C005A  E83A5A            call word 0xC5a97
C005D  E9AF00            jmp word 0xC010f

C0060  3D0311            cmp ax,0x1103
C0063  7506              jnz 0xC006b
C0065  E8326A            call word 0xC6a9a
C0068  E9A400            jmp word 0xC010f

C006B  80FC12            cmp ah,0x12
C006E  753E              jnz 0xC00ae


C0070  80FB10            cmp bl,0x10
C0073  7506              jnz 0x7b
C0075  E87C6C            call word 0x6cf4
C0078  E99400            jmp word 0x010f

C007B  80FB30            cmp bl,0x30
C007E  7506              jnz 0x86
C0080  E8956C            call word 0x6d18
C0083  E98900            jmp word 0x010f

C0086  80FB31            cmp bl,0x31
C0089  7505              jnz 0xC0090
C008B  E8DD6C            call word 0xC6d6b
C008E  EB7F              jmp short 0xC010f

C0090  80FB32            cmp bl,0x32
C0093  7505              jnz 0xC009a
C0095  E8F56C            call word 0xC6d8d
C0098  EB75              jmp short 0xC010f

C009A  80FB33            cmp bl,0x33
C009D  7505              jnz 0xC00a4
C009F  E8096D            call word 0xC6dab
C00A2  EB6B              jmp short 0xC010f

C00A4  80FB34            cmp bl,0x34
C00A7  7558              jnz 0xC0101
C00A9  E8236D            call word 0xC6dcf
C00AC  EB61              jmp short 0xC010f


C00AE  3D1B10            cmp ax,0x101b
C00B1  744E              jz 0xC0101

C00B3  80FC10            cmp ah,0x10
C00B6  7505              jnz 0xC00bd
C00B8  E8E662            call word 0x63a1
C00BB  EB52              jmp short 0x010f

C00BD  80FC4F            cmp ah,0x4f
C00C0  753F              jnz 0xC0101

C00C2  3C03              cmp al,0x03
C00C4  7505              jnz 0xC00cb
C00C6  E8A68A            call word 0xC8b6f
C00C9  EB44              jmp short 0xC010f

C00CB  3C05              cmp al,0x05
C00CD  7505              jnz 0xC00d4
C00CF  E8718D            call word 0xC8e43
C00D2  EB3B              jmp short 0xC010f

C00D4  3C06              cmp al,0x06
C00D6  7505              jnz 0xC00dd
C00D8  E8958D            call word 0xC8e70
C00DB  EB32              jmp short 0xC010f

C00DD  3C07              cmp al,0x07
C00DF  7505              jnz 0xC00e6
C00E1  E8D98D            call word 0xC8ebd
C00E4  EB29              jmp short 0xC010f

C00E6  3C08              cmp al,0x08
C00E8  7505              jnz 0xC00ef
C00EA  E8FE8D            call word 0xC8eeb
C00ED  EB20              jmp short 0xC010f

C00EF  3C09              cmp al,0x09
C00F1  7505              jnz 0xC00f8
C00F3  E82C8E            call word 0xC8f22
C00F6  EB17              jmp short 0xC010f

C00F8  3C0A              cmp al,0x0a
C00FA  7505              jnz 0xC0101
C00FC  E8878E            call word 0xC8f86
C00FF  EB0E              jmp short 0xC010f

C0101  06                push es
C0102  1E                push ds
C0103  60                pushaw
C0104  BB00C0            mov bx,0xc000
C0107  8EDB              mov ds,bx
C0109  E87336            call word 0xC377f
C010C  61                popaw
C010D  1F                pop ds
C010E  07                pop es

C010F  9D                popfw
C0110  CF                iretw

 = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = 

C377F  55                push bp
C3780  89E5              mov bp,sp
C3782  8B4612            mov ax,[bp+0x12]
C3785  88E0              mov al,ah
C3787  30E4              xor ah,ah
C3789  E9D704            jmp word 0xc3c63

C378C  8A4612            mov al,[bp+0x12]
C378F  30E4              xor ah,ah
C3791  50                push ax
C3792  E82405            call word 0xc3cb9
C3795  44                inc sp
C3796  44                inc sp
C3797  8A4612            mov al,[bp+0x12]
C379A  247F              and al,0x7f
C379C  EB24              jmp short 0x37c2
C379E  8B4612            mov ax,[bp+0x12]
C37A1  30C0              xor al,al
C37A3  0C3F              or al,0x3f
C37A5  894612            mov [bp+0x12],ax
C37A8  EB3D              jmp short 0x37e7
C37AA  8B4612            mov ax,[bp+0x12]
C37AD  30C0              xor al,al
C37AF  0C30              or al,0x30
C37B1  894612            mov [bp+0x12],ax
C37B4  EB31              jmp short 0x37e7
C37B6  8B4612            mov ax,[bp+0x12]
C37B9  30C0              xor al,al
C37BB  0C20              or al,0x20
C37BD  894612            mov [bp+0x12],ax
C37C0  EB25              jmp short 0x37e7
C37C2  2C00              sub al,0x0
C37C4  72F0              jc 0x37b6
C37C6  3C07              cmp al,0x7
C37C8  771B              ja 0x37e5
C37CA  30E4              xor ah,ah
C37CC  D1E0              shl ax,1
C37CE  89C3              mov bx,ax
C37D0  2EFFA7D537        jmp word near [cs:bx+0x37d5]
C37D5  AA                stosb
C37D6  37                aaa
C37D7  AA                stosb
C37D8  37                aaa
C37D9  AA                stosb
C37DA  37                aaa
C37DB  AA                stosb
C37DC  37                aaa
C37DD  AA                stosb
C37DE  37                aaa
C37DF  AA                stosb
C37E0  37                aaa
C37E1  9E                sahf
C37E2  37                aaa
C37E3  AA                stosb
C37E4  37                aaa
C37E5  EBCF              jmp short 0x37b6
C37E7  E9CD04            jmp word 0x3cb7
C37EA  8A4610            mov al,[bp+0x10]
C37ED  30E4              xor ah,ah
C37EF  50                push ax
C37F0  8B4610            mov ax,[bp+0x10]
C37F3  88E0              mov al,ah
C37F5  30E4              xor ah,ah
C37F7  50                push ax
C37F8  E8550B            call word 0x4350
C37FB  83C404            add sp,byte +0x4
C37FE  E9B604            jmp word 0x3cb7
C3801  FF760E            push word [bp+0xe]
C3804  8B460C            mov ax,[bp+0xc]
C3807  88E0              mov al,ah
C3809  30E4              xor ah,ah
C380B  50                push ax
C380C  E85C0C            call word 0x446b
C380F  83C404            add sp,byte +0x4
C3812  E9A204            jmp word 0x3cb7
C3815  8D5E0E            lea bx,[bp+0xe]
C3818  53                push bx
C3819  8D5E10            lea bx,[bp+0x10]
C381C  53                push bx
C381D  8B460C            mov ax,[bp+0xc]
C3820  88E0              mov al,ah
C3822  30E4              xor ah,ah
C3824  50                push ax
C3825  E8430D            call word 0x456b
C3828  83C406            add sp,byte +0x6
C382B  E98904            jmp word 0x3cb7
C382E  31C0              xor ax,ax
C3830  894612            mov [bp+0x12],ax
C3833  31C0              xor ax,ax
C3835  89460C            mov [bp+0xc],ax
C3838  31C0              xor ax,ax
C383A  894610            mov [bp+0x10],ax
C383D  31C0              xor ax,ax
C383F  89460E            mov [bp+0xe],ax
C3842  E97204            jmp word 0x3cb7
C3845  8A4612            mov al,[bp+0x12]
C3848  30E4              xor ah,ah
C384A  50                push ax
C384B  E8920D            call word 0x45e0
C384E  44                inc sp
C384F  44                inc sp
C3850  E96404            jmp word 0x3cb7
C3853  B80100            mov ax,0x1
C3856  50                push ax
C3857  B8FF00            mov ax,0xff
C385A  50                push ax
C385B  8A460E            mov al,[bp+0xe]
C385E  30E4              xor ah,ah
C3860  50                push ax
C3861  8B460E            mov ax,[bp+0xe]
C3864  88E0              mov al,ah
C3866  30E4              xor ah,ah
C3868  50                push ax
C3869  8A4610            mov al,[bp+0x10]
C386C  30E4              xor ah,ah
C386E  50                push ax
C386F  8B4610            mov ax,[bp+0x10]
C3872  88E0              mov al,ah
C3874  30E4              xor ah,ah
C3876  50                push ax
C3877  8B460C            mov ax,[bp+0xc]
C387A  88E0              mov al,ah
C387C  30E4              xor ah,ah
C387E  50                push ax
C387F  8A4612            mov al,[bp+0x12]
C3882  30E4              xor ah,ah
C3884  50                push ax
C3885  E8DB11            call word 0x4a63
C3888  83C410            add sp,byte +0x10
C388B  E92904            jmp word 0x3cb7
C388E  31C0              xor ax,ax
C3890  50                push ax
C3891  B8FF00            mov ax,0xff
C3894  50                push ax
C3895  8A460E            mov al,[bp+0xe]
C3898  30E4              xor ah,ah
C389A  50                push ax
C389B  8B460E            mov ax,[bp+0xe]
C389E  88E0              mov al,ah
C38A0  30E4              xor ah,ah
C38A2  50                push ax
C38A3  8A4610            mov al,[bp+0x10]
C38A6  30E4              xor ah,ah
C38A8  50                push ax
C38A9  8B4610            mov ax,[bp+0x10]
C38AC  88E0              mov al,ah
C38AE  30E4              xor ah,ah
C38B0  50                push ax
C38B1  8B460C            mov ax,[bp+0xc]
C38B4  88E0              mov al,ah
C38B6  30E4              xor ah,ah
C38B8  50                push ax
C38B9  8A4612            mov al,[bp+0x12]
C38BC  30E4              xor ah,ah
C38BE  50                push ax
C38BF  E8A111            call word 0x4a63
C38C2  83C410            add sp,byte +0x10
C38C5  E9EF03            jmp word 0x3cb7
C38C8  8D5E12            lea bx,[bp+0x12]
C38CB  53                push bx
C38CC  8B460C            mov ax,[bp+0xc]
C38CF  88E0              mov al,ah
C38D1  30E4              xor ah,ah
C38D3  50                push ax
C38D4  E89218            call word 0x5169
C38D7  83C404            add sp,byte +0x4
C38DA  E9DA03            jmp word 0x3cb7
C38DD  FF7610            push word [bp+0x10]
C38E0  8A460C            mov al,[bp+0xc]
C38E3  30E4              xor ah,ah
C38E5  50                push ax
C38E6  8B460C            mov ax,[bp+0xc]
C38E9  88E0              mov al,ah
C38EB  30E4              xor ah,ah
C38ED  50                push ax
C38EE  8A4612            mov al,[bp+0x12]
C38F1  30E4              xor ah,ah
C38F3  50                push ax
C38F4  E8B81D            call word 0x56af
C38F7  83C408            add sp,byte +0x8
C38FA  E9BA03            jmp word 0x3cb7
C38FD  FF7610            push word [bp+0x10]
C3900  8A460C            mov al,[bp+0xc]
C3903  30E4              xor ah,ah
C3905  50                push ax
C3906  8B460C            mov ax,[bp+0xc]
C3909  88E0              mov al,ah
C390B  30E4              xor ah,ah
C390D  50                push ax
C390E  8A4612            mov al,[bp+0x12]
C3911  30E4              xor ah,ah
C3913  50                push ax
C3914  E88A1F            call word 0x58a1
C3917  83C408            add sp,byte +0x8
C391A  E99A03            jmp word 0x3cb7
C391D  FF760E            push word [bp+0xe]
C3920  FF7610            push word [bp+0x10]
C3923  8A4612            mov al,[bp+0x12]
C3926  30E4              xor ah,ah
C3928  50                push ax
C3929  8B460C            mov ax,[bp+0xc]
C392C  88E0              mov al,ah
C392E  30E4              xor ah,ah
C3930  50                push ax
C3931  E8E321            call word 0x5b17
C3934  83C408            add sp,byte +0x8
C3937  E97D03            jmp word 0x3cb7
C393A  8D5E12            lea bx,[bp+0x12]
C393D  53                push bx
C393E  FF760E            push word [bp+0xe]
C3941  FF7610            push word [bp+0x10]
C3944  8B460C            mov ax,[bp+0xc]
C3947  88E0              mov al,ah
C3949  30E4              xor ah,ah
C394B  50                push ax
C394C  E86424            call word 0x5db3
C394F  83C408            add sp,byte +0x8
C3952  E96203            jmp word 0x3cb7
C3955  B80200            mov ax,0x2
C3958  50                push ax
C3959  8A460C            mov al,[bp+0xc]
C395C  30E4              xor ah,ah
C395E  50                push ax
C395F  B8FF00            mov ax,0xff
C3962  50                push ax
C3963  8A4612            mov al,[bp+0x12]
C3966  30E4              xor ah,ah
C3968  50                push ax
C3969  E84D26            call word 0x5fb9
C396C  83C408            add sp,byte +0x8
C396F  E94503            jmp word 0x3cb7
C3972  FF7610            push word [bp+0x10]
C3975  FF760C            push word [bp+0xc]
C3978  E8AB2C            call word 0x6626
C397B  83C404            add sp,byte +0x4
C397E  E93603            jmp word 0x3cb7
C3981  8A4612            mov al,[bp+0x12]
C3984  E9E100            jmp word 0x3a68
C3987  8B460C            mov ax,[bp+0xc]
C398A  88E0              mov al,ah
C398C  30E4              xor ah,ah
C398E  50                push ax
C398F  8A460C            mov al,[bp+0xc]
C3992  30E4              xor ah,ah
C3994  50                push ax
C3995  FF760E            push word [bp+0xe]
C3998  FF7610            push word [bp+0x10]
C399B  FF7608            push word [bp+0x8]
C399E  FF7616            push word [bp+0x16]
C39A1  8A4612            mov al,[bp+0x12]
C39A4  30E4              xor ah,ah
C39A6  50                push ax
C39A7  E82C2F            call word 0x68d6
C39AA  83C40E            add sp,byte +0xe
C39AD  E90C01            jmp word 0x3abc
C39B0  8A460C            mov al,[bp+0xc]
C39B3  30E4              xor ah,ah
C39B5  50                push ax
C39B6  8A4612            mov al,[bp+0x12]
C39B9  30E4              xor ah,ah
C39BB  50                push ax
C39BC  E8B32F            call word 0x6972
C39BF  83C404            add sp,byte +0x4
C39C2  E9F700            jmp word 0x3abc
C39C5  8A460C            mov al,[bp+0xc]
C39C8  30E4              xor ah,ah
C39CA  50                push ax
C39CB  8A4612            mov al,[bp+0x12]
C39CE  30E4              xor ah,ah
C39D0  50                push ax
C39D1  E83530            call word 0x6a09
C39D4  83C404            add sp,byte +0x4
C39D7  E9E200            jmp word 0x3abc
C39DA  8A460C            mov al,[bp+0xc]
C39DD  30E4              xor ah,ah
C39DF  50                push ax
C39E0  8A4612            mov al,[bp+0x12]
C39E3  30E4              xor ah,ah
C39E5  50                push ax
C39E6  E8BE30            call word 0x6aa7
C39E9  83C404            add sp,byte +0x4
C39EC  E9CD00            jmp word 0x3abc
C39EF  FF7608            push word [bp+0x8]
C39F2  FF7616            push word [bp+0x16]
C39F5  E84031            call word 0x6b38
C39F8  83C404            add sp,byte +0x4
C39FB  E9BE00            jmp word 0x3abc
C39FE  8A460E            mov al,[bp+0xe]
C3A01  30E4              xor ah,ah
C3A03  50                push ax
C3A04  8A460C            mov al,[bp+0xc]
C3A07  30E4              xor ah,ah
C3A09  50                push ax
C3A0A  FF7610            push word [bp+0x10]
C3A0D  FF7608            push word [bp+0x8]
C3A10  FF7616            push word [bp+0x16]
C3A13  E82331            call word 0x6b39
C3A16  83C40A            add sp,byte +0xa
C3A19  E9A000            jmp word 0x3abc
C3A1C  8A460C            mov al,[bp+0xc]
C3A1F  30E4              xor ah,ah
C3A21  50                push ax
C3A22  E81531            call word 0x6b3a
C3A25  44                inc sp
C3A26  44                inc sp
C3A27  E99200            jmp word 0x3abc
C3A2A  8A460C            mov al,[bp+0xc]
C3A2D  30E4              xor ah,ah
C3A2F  50                push ax
C3A30  E80831            call word 0x6b3b
C3A33  44                inc sp
C3A34  44                inc sp
C3A35  E98400            jmp word 0x3abc
C3A38  8A460C            mov al,[bp+0xc]
C3A3B  30E4              xor ah,ah
C3A3D  50                push ax
C3A3E  E8FB30            call word 0x6b3c
C3A41  44                inc sp
C3A42  44                inc sp
C3A43  E97600            jmp word 0x3abc
C3A46  8D5E0E            lea bx,[bp+0xe]
C3A49  53                push bx
C3A4A  8D5E10            lea bx,[bp+0x10]
C3A4D  53                push bx
C3A4E  8D5E08            lea bx,[bp+0x8]
C3A51  53                push bx
C3A52  8D5E16            lea bx,[bp+0x16]
C3A55  53                push bx
C3A56  8B460C            mov ax,[bp+0xc]
C3A59  88E0              mov al,ah
C3A5B  30E4              xor ah,ah
C3A5D  50                push ax
C3A5E  E8DC30            call word 0x6b3d
C3A61  83C40A            add sp,byte +0xa
C3A64  EB56              jmp short 0x3abc
C3A66  EB54              jmp short 0x3abc
C3A68  2C00              sub al,0x0
C3A6A  0F8419FF          jz word 0x3987
C3A6E  2C01              sub al,0x1
C3A70  0F843CFF          jz word 0x39b0
C3A74  2C01              sub al,0x1
C3A76  0F844BFF          jz word 0x39c5
C3A7A  2C02              sub al,0x2
C3A7C  0F845AFF          jz word 0x39da
C3A80  2C0C              sub al,0xc
C3A82  0F8401FF          jz word 0x3987
C3A86  2C01              sub al,0x1
C3A88  0F8424FF          jz word 0x39b0
C3A8C  2C01              sub al,0x1
C3A8E  0F8433FF          jz word 0x39c5
C3A92  2C02              sub al,0x2
C3A94  0F8442FF          jz word 0x39da
C3A98  2C0C              sub al,0xc
C3A9A  0F8451FF          jz word 0x39ef
C3A9E  2C01              sub al,0x1
C3AA0  0F845AFF          jz word 0x39fe
C3AA4  2C01              sub al,0x1
C3AA6  0F8472FF          jz word 0x3a1c
C3AAA  2C01              sub al,0x1
C3AAC  0F847AFF          jz word 0x3a2a
C3AB0  2C01              sub al,0x1
C3AB2  0F8482FF          jz word 0x3a38
C3AB6  2C0C              sub al,0xc
C3AB8  0F848AFF          jz word 0x3a46
C3ABC  E9F801            jmp word 0x3cb7
C3ABF  8A460C            mov al,[bp+0xc]
C3AC2  EB3C              jmp short 0x3b00
C3AC4  E85032            call word 0x6d17
C3AC7  EB43              jmp short 0x3b0c
C3AC9  FF760E            push word [bp+0xe]
C3ACC  FF7616            push word [bp+0x16]
C3ACF  8A4612            mov al,[bp+0x12]
C3AD2  30E4              xor ah,ah
C3AD4  50                push ax
C3AD5  E81933            call word 0x6df1
C3AD8  83C406            add sp,byte +0x6
C3ADB  8B4612            mov ax,[bp+0x12]
C3ADE  30C0              xor al,al
C3AE0  0C12              or al,0x12
C3AE2  894612            mov [bp+0x12],ax
C3AE5  EB25              jmp short 0x3b0c
C3AE7  8A4612            mov al,[bp+0x12]
C3AEA  30E4              xor ah,ah
C3AEC  50                push ax
C3AED  E80233            call word 0x6df2
C3AF0  44                inc sp
C3AF1  44                inc sp
C3AF2  8B4612            mov ax,[bp+0x12]
C3AF5  30C0              xor al,al
C3AF7  0C12              or al,0x12
C3AF9  894612            mov [bp+0x12],ax
C3AFC  EB0E              jmp short 0x3b0c
C3AFE  EB0C              jmp short 0x3b0c
C3B00  2C20              sub al,0x20
C3B02  74C0              jz 0x3ac4
C3B04  2C15              sub al,0x15
C3B06  74C1              jz 0x3ac9
C3B08  2C01              sub al,0x1
C3B0A  74DB              jz 0x3ae7
C3B0C  E9A801            jmp word 0x3cb7
C3B0F  FF7608            push word [bp+0x8]
C3B12  FF7616            push word [bp+0x16]
C3B15  8A460E            mov al,[bp+0xe]
C3B18  30E4              xor ah,ah
C3B1A  50                push ax
C3B1B  8B460E            mov ax,[bp+0xe]
C3B1E  88E0              mov al,ah
C3B20  30E4              xor ah,ah
C3B22  50                push ax
C3B23  FF7610            push word [bp+0x10]
C3B26  8A460C            mov al,[bp+0xc]
C3B29  30E4              xor ah,ah
C3B2B  50                push ax
C3B2C  8B460C            mov ax,[bp+0xc]
C3B2F  88E0              mov al,ah
C3B31  30E4              xor ah,ah
C3B33  50                push ax
C3B34  8A4612            mov al,[bp+0x12]
C3B37  30E4              xor ah,ah
C3B39  50                push ax
C3B3A  E8B632            call word 0x6df3
C3B3D  83C410            add sp,byte +0x10
C3B40  E97401            jmp word 0x3cb7
C3B43  FF7604            push word [bp+0x4]
C3B46  FF7616            push word [bp+0x16]
C3B49  FF760C            push word [bp+0xc]
C3B4C  E8B033            call word 0x6eff
C3B4F  83C406            add sp,byte +0x6
C3B52  8B4612            mov ax,[bp+0x12]
C3B55  30C0              xor al,al
C3B57  0C1B              or al,0x1b
C3B59  894612            mov [bp+0x12],ax
C3B5C  E95801            jmp word 0x3cb7
C3B5F  8A4612            mov al,[bp+0x12]
C3B62  EB33              jmp short 0x3b97
C3B64  8D5E0C            lea bx,[bp+0xc]
C3B67  53                push bx
C3B68  FF7610            push word [bp+0x10]
C3B6B  E81035            call word 0x707e
C3B6E  83C404            add sp,byte +0x4
C3B71  EB30              jmp short 0x3ba3
C3B73  FF760C            push word [bp+0xc]
C3B76  FF7616            push word [bp+0x16]
C3B79  FF7610            push word [bp+0x10]
C3B7C  E82335            call word 0x70a2
C3B7F  83C406            add sp,byte +0x6
C3B82  EB1F              jmp short 0x3ba3
C3B84  FF760C            push word [bp+0xc]
C3B87  FF7616            push word [bp+0x16]
C3B8A  FF7610            push word [bp+0x10]
C3B8D  E8DC3A            call word 0x766c
C3B90  83C406            add sp,byte +0x6
C3B93  EB0E              jmp short 0x3ba3
C3B95  EB0C              jmp short 0x3ba3
C3B97  2C00              sub al,0x0
C3B99  74C9              jz 0x3b64
C3B9B  2C01              sub al,0x1
C3B9D  74D4              jz 0x3b73
C3B9F  2C01              sub al,0x1
C3BA1  74E1              jz 0x3b84
C3BA3  8B4612            mov ax,[bp+0x12]
C3BA6  30C0              xor al,al
C3BA8  0C1C              or al,0x1c
C3BAA  894612            mov [bp+0x12],ax
C3BAD  E90701            jmp word 0x3cb7
C3BB0  E83349            call word 0x84e6
C3BB3  85C0              test ax,ax
C3BB5  0F84A000          jz word 0x3c59
C3BB9  8A4612            mov al,[bp+0x12]
C3BBC  EB6E              jmp short 0x3c2c
C3BBE  FF7604            push word [bp+0x4]
C3BC1  FF7616            push word [bp+0x16]
C3BC4  8D5E12            lea bx,[bp+0x12]
C3BC7  53                push bx
C3BC8  E85349            call word 0x851e
C3BCB  83C406            add sp,byte +0x6
C3BCE  E98600            jmp word 0x3c57
C3BD1  FF7604            push word [bp+0x4]
C3BD4  FF7616            push word [bp+0x16]
C3BD7  FF7610            push word [bp+0x10]
C3BDA  8D5E12            lea bx,[bp+0x12]
C3BDD  53                push bx
C3BDE  E8A54C            call word 0x8886
C3BE1  83C408            add sp,byte +0x8
C3BE4  EB71              jmp short 0x3c57
C3BE6  FF7604            push word [bp+0x4]
C3BE9  FF7616            push word [bp+0x16]
C3BEC  FF760C            push word [bp+0xc]
C3BEF  8D5E12            lea bx,[bp+0x12]
C3BF2  53                push bx
C3BF3  E8B54D            call word 0x89ab
C3BF6  83C408            add sp,byte +0x8
C3BF9  EB5C              jmp short 0x3c57
C3BFB  8D5E0C            lea bx,[bp+0xc]
C3BFE  53                push bx
C3BFF  FF7616            push word [bp+0x16]
C3C02  FF760E            push word [bp+0xe]
C3C05  FF7610            push word [bp+0x10]
C3C08  8D5E12            lea bx,[bp+0x12]
C3C0B  53                push bx
C3C0C  E84C51            call word 0x8d5b
C3C0F  83C40A            add sp,byte +0xa
C3C12  EB43              jmp short 0x3c57
C3C14  B80001            mov ax,0x100
C3C17  894612            mov [bp+0x12],ax
C3C1A  EB3B              jmp short 0x3c57
C3C1C  B80001            mov ax,0x100
C3C1F  894612            mov [bp+0x12],ax
C3C22  EB33              jmp short 0x3c57
C3C24  B80001            mov ax,0x100
C3C27  894612            mov [bp+0x12],ax
C3C2A  EB2B              jmp short 0x3c57
C3C2C  2C00              sub al,0x0
C3C2E  72F4              jc 0x3c24
C3C30  3C0A              cmp al,0xa
C3C32  7721              ja 0x3c55
C3C34  30E4              xor ah,ah
C3C36  D1E0              shl ax,1
C3C38  89C3              mov bx,ax
C3C3A  2EFFA73F3C        jmp word near [cs:bx+0x3c3f]
C3C3F  BE3BD1            mov si,0xd13b
C3C42  3BE6              cmp sp,si
C3C44  3B24              cmp sp,[si]
C3C46  3CFB              cmp al,0xfb
C3C48  3B24              cmp sp,[si]
C3C4A  3C24              cmp al,0x24
C3C4C  3C24              cmp al,0x24
C3C4E  3C24              cmp al,0x24
C3C50  3C14              cmp al,0x14
C3C52  3C1C              cmp al,0x1c
C3C54  3CEB              cmp al,0xeb
C3C56  CDEB              int 0xeb
C3C58  06                push es
C3C59  B80001            mov ax,0x100
C3C5C  894612            mov [bp+0x12],ax
C3C5F  EB56              jmp short 0x3cb7
C3C61  EB54              jmp short 0x3cb7

C3C63  2D0000            sub ax,0x0000
C3C66  7C4F              jl 0xc3cb7 ; (SF≠ OF)
C3C68  3D1C00            cmp ax,0x001c
C3C6B  7743              ja 0xc3cb0 ; (CF=0 and ZF=0)

C3C6D  D1E0              shl ax,1
C3C6F  89C3              mov bx,ax
C3C71  2EFFA7763C        jmp word near [cs:bx+0x3c76]
C3C76  8C37              mov [bx],segr6
C3C78  EA37013815        jmp word 0x1538:0x137
C3C7D  382E3845          cmp [0x4538],ch
C3C81  385338            cmp [bp+di+0x38],dl
C3C84  8E38              mov segr7,[bx+si]
C3C86  C838DD38          enter 0xdd38,0x38
C3C8A  FD                std
C3C8B  38B73C1D          cmp [bx+0x1d3c],dh
C3C8F  393A              cmp [bp+si],di
C3C91  395539            cmp [di+0x39],dx
C3C94  B73C              mov bh,0x3c
C3C96  7239              jc 0x3cd1



00003C92  55                push bp
00003C93  AA                stosb
00003C94  48                dec ax
00003C95  EB1D              jmp short 0x3cb4
00003C97  56                push si
00003C98  6972747561        imul si,[bp+si+0x74],word 0x6175
00003C9D  6C                insb
00003C9E  42                inc dx
00003C9F  6F                outsw
00003CA0  7820              js 0x3cc2
00003CA2  56                push si
00003CA3  47                inc di
00003CA4  41                inc cx
00003CA5  204249            and [bp+si+0x49],al
00003CA8  4F                dec di
00003CA9  53                push bx
00003CAA  2000              and [bx+si],al
00003CAC  0000              add [bx+si],al
00003CAE  0000              add [bx+si],al
00003CB0  49                dec cx
00003CB1  42                inc dx
00003CB2  4D                dec bp
00003CB3  00E8              add al,ch
00003CB5  C1                db 0xc1
00003CB6  36E80237          ss call word 0x73bc
00003CBA  E8CE84            call word 0xc18b
00003CBD  1E                push ds
00003CBE  31C0              xor ax,ax
00003CC0  8ED8              mov ds,ax
00003CC2  B83E00            mov ax,0x3e
00003CC5  A34000            mov [0x40],ax
00003CC8  B800C0            mov ax,0xc000
00003CCB  A34200            mov [0x42],ax
00003CCE  1F                pop ds
00003CCF  CB                retf
00003CD0  9C                pushfw
00003CD1  80FC0F            cmp ah,0xf
00003CD4  7506              jnz 0x3cdc
00003CD6  E83363            call word 0xa00c
00003CD9  E9C500            jmp word 0x3da1
00003CDC  80FC1A            cmp ah,0x1a
00003CDF  7506              jnz 0x3ce7
00003CE1  E87A6E            call word 0xab5e
00003CE4  E9BA00            jmp word 0x3da1
00003CE7  80FC0B            cmp ah,0xb
00003CEA  7506              jnz 0x3cf2
00003CEC  E83A5A            call word 0x9729
00003CEF  E9AF00            jmp word 0x3da1
00003CF2  3D0311            cmp ax,0x1103
00003CF5  7506              jnz 0x3cfd
00003CF7  E8326A            call word 0xa72c
00003CFA  E9A400            jmp word 0x3da1
00003CFD  80FC12            cmp ah,0x12
00003D00  753E              jnz 0x3d40
00003D02  80FB10            cmp bl,0x10
00003D05  7506              jnz 0x3d0d
00003D07  E87C6C            call word 0xa986
00003D0A  E99400            jmp word 0x3da1
00003D0D  80FB30            cmp bl,0x30
00003D10  7506              jnz 0x3d18
00003D12  E8956C            call word 0xa9aa
00003D15  E98900            jmp word 0x3da1
00003D18  80FB31            cmp bl,0x31
00003D1B  7505              jnz 0x3d22
00003D1D  E8DD6C            call word 0xa9fd
00003D20  EB7F              jmp short 0x3da1
00003D22  80FB32            cmp bl,0x32
00003D25  7505              jnz 0x3d2c
00003D27  E8F56C            call word 0xaa1f
00003D2A  EB75              jmp short 0x3da1
00003D2C  80FB33            cmp bl,0x33
00003D2F  7505              jnz 0x3d36
00003D31  E8096D            call word 0xaa3d
00003D34  EB6B              jmp short 0x3da1
00003D36  80FB34            cmp bl,0x34
00003D39  7558              jnz 0x3d93
00003D3B  E8236D            call word 0xaa61
00003D3E  EB61              jmp short 0x3da1
00003D40  3D1B10            cmp ax,0x101b
00003D43  744E              jz 0x3d93
00003D45  80FC10            cmp ah,0x10
00003D48  7505              jnz 0x3d4f
00003D4A  E8E662            call word 0xa033
00003D4D  EB52              jmp short 0x3da1
00003D4F  80FC4F            cmp ah,0x4f
00003D52  753F              jnz 0x3d93
00003D54  3C03              cmp al,0x3
00003D56  7505              jnz 0x3d5d
00003D58  E8A68A            call word 0xc801
00003D5B  EB44              jmp short 0x3da1
00003D5D  3C05              cmp al,0x5
00003D5F  7505              jnz 0x3d66
00003D61  E8718D            call word 0xcad5
00003D64  EB3B              jmp short 0x3da1
00003D66  3C06              cmp al,0x6
00003D68  7505              jnz 0x3d6f
00003D6A  E8958D            call word 0xcb02
00003D6D  EB32              jmp short 0x3da1
00003D6F  3C07              cmp al,0x7
00003D71  7505              jnz 0x3d78
00003D73  E8D98D            call word 0xcb4f
00003D76  EB29              jmp short 0x3da1
00003D78  3C08              cmp al,0x8
00003D7A  7505              jnz 0x3d81
00003D7C  E8FE8D            call word 0xcb7d
00003D7F  EB20              jmp short 0x3da1
00003D81  3C09              cmp al,0x9
00003D83  7505              jnz 0x3d8a
00003D85  E82C8E            call word 0xcbb4
00003D88  EB17              jmp short 0x3da1
00003D8A  3C0A              cmp al,0xa
00003D8C  7505              jnz 0x3d93
00003D8E  E8878E            call word 0xcc18
00003D91  EB0E              jmp short 0x3da1
00003D93  06                push es
00003D94  1E                push ds
00003D95  60                pushaw
00003D96  BB00C0            mov bx,0xc000
00003D99  8EDB              mov ds,bx
00003D9B  E87336            call word 0x7411
00003D9E  61                popaw
00003D9F  1F                pop ds
00003DA0  07                pop es
00003DA1  9D                popfw
00003DA2  CF                iretw
00003DA3  0000              add [bx+si],al
00003DA5  0004              add [si],al
00003DA7  00B8FF02          add [bx+si+0x2ff],bh
00003DAB  0100              add [bx+si],ax
00003DAD  0004              add [si],al
00003DAF  00B8FF02          add [bx+si+0x2ff],bh
00003DB3  0200              add al,[bx+si]
00003DB5  0004              add [si],al
00003DB7  00B8FF02          add [bx+si+0x2ff],bh
00003DBB  0300              add ax,[bx+si]
00003DBD  0004              add [si],al
00003DBF  00B8FF02          add [bx+si+0x2ff],bh
00003DC3  0401              add al,0x1
00003DC5  0202              add al,[bp+si]
00003DC7  00B8FF01          add [bx+si+0x1ff],bh
00003DCB  050102            add ax,0x201
00003DCE  0200              add al,[bx+si]
00003DD0  B8FF01            mov ax,0x1ff
00003DD3  06                push es
00003DD4  0102              add [bp+si],ax
00003DD6  0100              add [bx+si],ax
00003DD8  B8FF01            mov ax,0x1ff
00003DDB  07                pop es
00003DDC  0001              add [bx+di],al
00003DDE  0400              add al,0x0
00003DE0  B0FF              mov al,0xff
00003DE2  000D              add [di],cl
00003DE4  0104              add [si],ax
00003DE6  0400              add al,0x0
00003DE8  A0FF01            mov al,[0x1ff]
00003DEB  0E                push cs
00003DEC  0104              add [si],ax
00003DEE  0400              add al,0x0
00003DF0  A0FF01            mov al,[0x1ff]
00003DF3  0F0103            sgdt [bp+di]
00003DF6  0100              add [bx+si],ax
00003DF8  A0FF00            mov al,[0xff]
00003DFB  1001              adc [bx+di],al
00003DFD  0404              add al,0x4
00003DFF  00A0FF02          add [bx+si+0x2ff],ah
00003E03  1101              adc [bx+di],ax
00003E05  0301              add ax,[bx+di]
00003E07  00A0FF02          add [bx+si+0x2ff],ah
00003E0B  1201              adc al,[bx+di]
00003E0D  0404              add al,0x4
00003E0F  00A0FF02          add [bx+si+0x2ff],ah
00003E13  1301              adc ax,[bx+di]
00003E15  050800            add ax,0x8
00003E18  A0FF03            mov al,[0x3ff]
00003E1B  6A01              push byte +0x1
00003E1D  0404              add al,0x4
00003E1F  00A0FF02          add [bx+si+0x2ff],ah
00003E23  17                pop ss
00003E24  17                pop ss
00003E25  1818              sbb [bx+si],bl
00003E27  0405              add al,0x5
00003E29  06                push es
00003E2A  07                pop es
00003E2B  0D0E11            or ax,0x110e
00003E2E  121A              adc bl,[bp+si]
00003E30  1B1C              sbb bx,[si]
00003E32  1D3F3F            sbb ax,0x3f3f
00003E35  3F                aas
00003E36  FF00              inc word [bx+si]
00003E38  0000              add [bx+si],al
00003E3A  0000              add [bx+si],al
00003E3C  0000              add [bx+si],al
00003E3E  0000              add [bx+si],al
00003E40  0000              add [bx+si],al
00003E42  0000              add [bx+si],al
00003E44  0000              add [bx+si],al
00003E46  0000              add [bx+si],al
00003E48  0000              add [bx+si],al
00003E4A  0000              add [bx+si],al
00003E4C  0000              add [bx+si],al
00003E4E  0000              add [bx+si],al
00003E50  0000              add [bx+si],al
00003E52  0000              add [bx+si],al
00003E54  0000              add [bx+si],al
00003E56  0000              add [bx+si],al
00003E58  0000              add [bx+si],al
00003E5A  0000              add [bx+si],al
00003E5C  0000              add [bx+si],al
00003E5E  0000              add [bx+si],al
00003E60  0000              add [bx+si],al
00003E62  0000              add [bx+si],al
00003E64  0000              add [bx+si],al
00003E66  0000              add [bx+si],al
00003E68  0000              add [bx+si],al
00003E6A  0000              add [bx+si],al
00003E6C  0000              add [bx+si],al
00003E6E  0000              add [bx+si],al
00003E70  0000              add [bx+si],al
00003E72  0000              add [bx+si],al
00003E74  0000              add [bx+si],al
00003E76  0000              add [bx+si],al
00003E78  0000              add [bx+si],al
00003E7A  0000              add [bx+si],al
00003E7C  0000              add [bx+si],al
00003E7E  0000              add [bx+si],al
00003E80  0000              add [bx+si],al
00003E82  0000              add [bx+si],al
00003E84  0000              add [bx+si],al
00003E86  0000              add [bx+si],al
00003E88  0000              add [bx+si],al
00003E8A  0000              add [bx+si],al
00003E8C  0000              add [bx+si],al
00003E8E  0000              add [bx+si],al
00003E90  0000              add [bx+si],al
00003E92  0000              add [bx+si],al
00003E94  0000              add [bx+si],al
00003E96  0000              add [bx+si],al
00003E98  0000              add [bx+si],al
00003E9A  0000              add [bx+si],al
00003E9C  0000              add [bx+si],al
00003E9E  0000              add [bx+si],al
00003EA0  0000              add [bx+si],al
00003EA2  0000              add [bx+si],al
00003EA4  0000              add [bx+si],al
00003EA6  0000              add [bx+si],al
00003EA8  0000              add [bx+si],al
00003EAA  0000              add [bx+si],al
00003EAC  0000              add [bx+si],al
00003EAE  0000              add [bx+si],al
00003EB0  0000              add [bx+si],al
00003EB2  0000              add [bx+si],al
00003EB4  0000              add [bx+si],al
00003EB6  0000              add [bx+si],al
00003EB8  0000              add [bx+si],al
00003EBA  0000              add [bx+si],al
00003EBC  0000              add [bx+si],al
00003EBE  0000              add [bx+si],al
00003EC0  0000              add [bx+si],al
00003EC2  0000              add [bx+si],al
00003EC4  0000              add [bx+si],al
00003EC6  0000              add [bx+si],al
00003EC8  0000              add [bx+si],al
00003ECA  0000              add [bx+si],al
00003ECC  0000              add [bx+si],al
00003ECE  0000              add [bx+si],al
00003ED0  0000              add [bx+si],al
00003ED2  0000              add [bx+si],al
00003ED4  0000              add [bx+si],al
00003ED6  0000              add [bx+si],al
00003ED8  0000              add [bx+si],al
00003EDA  0000              add [bx+si],al
00003EDC  0000              add [bx+si],al
00003EDE  0000              add [bx+si],al
00003EE0  0000              add [bx+si],al
00003EE2  0000              add [bx+si],al
00003EE4  0000              add [bx+si],al
00003EE6  0000              add [bx+si],al
00003EE8  0000              add [bx+si],al
00003EEA  0000              add [bx+si],al
00003EEC  0000              add [bx+si],al
00003EEE  0000              add [bx+si],al
00003EF0  0000              add [bx+si],al
00003EF2  0000              add [bx+si],al
00003EF4  0000              add [bx+si],al
00003EF6  0000              add [bx+si],al
00003EF8  0000              add [bx+si],al
00003EFA  0000              add [bx+si],al
00003EFC  0000              add [bx+si],al
00003EFE  0000              add [bx+si],al
00003F00  0000              add [bx+si],al
00003F02  0000              add [bx+si],al
00003F04  0000              add [bx+si],al
00003F06  0000              add [bx+si],al
00003F08  0000              add [bx+si],al
00003F0A  0000              add [bx+si],al
00003F0C  0000              add [bx+si],al
00003F0E  0000              add [bx+si],al
00003F10  0000              add [bx+si],al
00003F12  0000              add [bx+si],al
00003F14  0000              add [bx+si],al
00003F16  0000              add [bx+si],al
00003F18  0000              add [bx+si],al
00003F1A  0000              add [bx+si],al
00003F1C  0000              add [bx+si],al
00003F1E  0000              add [bx+si],al
00003F20  0000              add [bx+si],al
00003F22  0000              add [bx+si],al
00003F24  0000              add [bx+si],al
00003F26  0000              add [bx+si],al
00003F28  0000              add [bx+si],al
00003F2A  0000              add [bx+si],al
00003F2C  0000              add [bx+si],al
00003F2E  0000              add [bx+si],al
00003F30  0000              add [bx+si],al
00003F32  0000              add [bx+si],al
00003F34  0000              add [bx+si],al
00003F36  0028              add [bx+si],ch
00003F38  1808              sbb [bx+si],cl
00003F3A  0008              add [bx+si],cl
00003F3C  0903              or [bp+di],ax
00003F3E  0002              add [bp+si],al
00003F40  632D              arpl [di],bp
00003F42  27                daa
00003F43  28902B80          sub [bx+si-0x7fd5],dl
00003F47  BF1F00            mov di,0x1f
00003F4A  C10000            rol word [bx+si],0x0
00003F4D  0000              add [bx+si],al
00003F4F  0000              add [bx+si],al
00003F51  9C                pushfw
00003F52  8E8F1400          mov cs,[bx+0x14]
00003F56  96                xchg ax,si
00003F57  B9A2FF            mov cx,0xffa2
00003F5A  0013              add [bp+di],dl
00003F5C  151702            adc ax,0x217
00003F5F  0406              add al,0x6
00003F61  07                pop es
00003F62  1011              adc [bx+di],dl
00003F64  1213              adc dl,[bp+di]
00003F66  1415              adc al,0x15
00003F68  16                push ss
00003F69  17                pop ss
00003F6A  0100              add [bx+si],ax
00003F6C  0300              add ax,[bx+si]
00003F6E  0000              add [bx+si],al
00003F70  0000              add [bx+si],al
00003F72  0030              add [bx+si],dh
00003F74  0F                db 0x0f
00003F75  0FFF              ud0
00003F77  2818              sub [bx+si],bl
00003F79  0800              or [bx+si],al
00003F7B  0809              or [bx+di],cl
00003F7D  0300              add ax,[bx+si]
00003F7F  02632D            add ah,[bp+di+0x2d]
00003F82  27                daa
00003F83  28902B80          sub [bx+si-0x7fd5],dl
00003F87  BF1F00            mov di,0x1f
00003F8A  C10000            rol word [bx+si],0x0
00003F8D  0000              add [bx+si],al
00003F8F  0000              add [bx+si],al
00003F91  9C                pushfw
00003F92  8E8F1400          mov cs,[bx+0x14]
00003F96  96                xchg ax,si
00003F97  B9A2FF            mov cx,0xffa2
00003F9A  0013              add [bp+di],dl
00003F9C  151702            adc ax,0x217
00003F9F  0406              add al,0x6
00003FA1  07                pop es
00003FA2  1011              adc [bx+di],dl
00003FA4  1213              adc dl,[bp+di]
00003FA6  1415              adc al,0x15
00003FA8  16                push ss
00003FA9  17                pop ss
00003FAA  0100              add [bx+si],ax
00003FAC  0300              add ax,[bx+si]
00003FAE  0000              add [bx+si],al
00003FB0  0000              add [bx+si],al
00003FB2  0030              add [bx+si],dh
00003FB4  0F                db 0x0f
00003FB5  0FFF              ud0
00003FB7  50                push ax
00003FB8  1808              sbb [bx+si],cl
00003FBA  0010              add [bx+si],dl
00003FBC  0101              add [bx+di],ax
00003FBE  0006635F          add [0x5f63],al
00003FC2  4F                dec di
00003FC3  50                push ax
00003FC4  82                db 0x82
00003FC5  54                push sp
00003FC6  80BF1F00C1        cmp byte [bx+0x1f],0xc1
00003FCB  0000              add [bx+si],al
00003FCD  0000              add [bx+si],al
00003FCF  0000              add [bx+si],al
00003FD1  9C                pushfw
00003FD2  8E8F2800          mov cs,[bx+0x28]
00003FD6  96                xchg ax,si
00003FD7  B9C2FF            mov cx,0xffc2
00003FDA  0017              add [bx],dl
00003FDC  17                pop ss
00003FDD  17                pop ss
00003FDE  17                pop ss
00003FDF  17                pop ss
00003FE0  17                pop ss
00003FE1  17                pop ss
00003FE2  17                pop ss
00003FE3  17                pop ss
00003FE4  17                pop ss
00003FE5  17                pop ss
00003FE6  17                pop ss
00003FE7  17                pop ss
00003FE8  17                pop ss
00003FE9  17                pop ss
00003FEA  0100              add [bx+si],ax
00003FEC  0100              add [bx+si],ax
00003FEE  0000              add [bx+si],al
00003FF0  0000              add [bx+si],al
00003FF2  0000              add [bx+si],al
00003FF4  0D0FFF            or ax,0xff0f
00003FF7  50                push ax
00003FF8  1810              sbb [bx+si],dl
00003FFA  0010              add [bx+si],dl
00003FFC  0003              add [bp+di],al
00003FFE  0002              add [bp+si],al
00004000  665F              pop edi
00004002  4F                dec di
00004003  50                push ax
00004004  82                db 0x82
00004005  55                push bp
00004006  81BF1F004F0D      cmp word [bx+0x1f],0xd4f
0000400C  0E                push cs
0000400D  0000              add [bx+si],al
0000400F  0000              add [bx+si],al
00004011  9C                pushfw
00004012  8E8F280F          mov cs,[bx+0xf28]
00004016  96                xchg ax,si
00004017  B9A3FF            mov cx,0xffa3
0000401A  0008              add [bx+si],cl
0000401C  0808              or [bx+si],cl
0000401E  0808              or [bx+si],cl
00004020  0808              or [bx+si],cl
00004022  1018              adc [bx+si],bl
00004024  1818              sbb [bx+si],bl
00004026  1818              sbb [bx+si],bl
00004028  1818              sbb [bx+si],bl
0000402A  0E                push cs
0000402B  000F              add [bx],cl
0000402D  0800              or [bx+si],al
0000402F  0000              add [bx+si],al
00004031  0000              add [bx+si],al
00004033  100A              adc [bp+si],cl
00004035  0FFF              ud0
00004037  0000              add [bx+si],al
00004039  0000              add [bx+si],al
0000403B  0000              add [bx+si],al
0000403D  0000              add [bx+si],al
0000403F  0000              add [bx+si],al
00004041  0000              add [bx+si],al
00004043  0000              add [bx+si],al
00004045  0000              add [bx+si],al
00004047  0000              add [bx+si],al
00004049  0000              add [bx+si],al
0000404B  0000              add [bx+si],al
0000404D  0000              add [bx+si],al
0000404F  0000              add [bx+si],al
00004051  0000              add [bx+si],al
00004053  0000              add [bx+si],al
00004055  0000              add [bx+si],al
00004057  0000              add [bx+si],al
00004059  0000              add [bx+si],al
0000405B  0000              add [bx+si],al
0000405D  0000              add [bx+si],al
0000405F  0000              add [bx+si],al
00004061  0000              add [bx+si],al
00004063  0000              add [bx+si],al
00004065  0000              add [bx+si],al
00004067  0000              add [bx+si],al
00004069  0000              add [bx+si],al
0000406B  0000              add [bx+si],al
0000406D  0000              add [bx+si],al
0000406F  0000              add [bx+si],al
00004071  0000              add [bx+si],al
00004073  0000              add [bx+si],al
00004075  0000              add [bx+si],al
00004077  0000              add [bx+si],al
00004079  0000              add [bx+si],al
0000407B  0000              add [bx+si],al
0000407D  0000              add [bx+si],al
0000407F  0000              add [bx+si],al
00004081  0000              add [bx+si],al
00004083  0000              add [bx+si],al
00004085  0000              add [bx+si],al
00004087  0000              add [bx+si],al
00004089  0000              add [bx+si],al
0000408B  0000              add [bx+si],al
0000408D  0000              add [bx+si],al
0000408F  0000              add [bx+si],al
00004091  0000              add [bx+si],al
00004093  0000              add [bx+si],al
00004095  0000              add [bx+si],al
00004097  0000              add [bx+si],al
00004099  0000              add [bx+si],al
0000409B  0000              add [bx+si],al
0000409D  0000              add [bx+si],al
0000409F  0000              add [bx+si],al
000040A1  0000              add [bx+si],al
000040A3  0000              add [bx+si],al
000040A5  0000              add [bx+si],al
000040A7  0000              add [bx+si],al
000040A9  0000              add [bx+si],al
000040AB  0000              add [bx+si],al
000040AD  0000              add [bx+si],al
000040AF  0000              add [bx+si],al
000040B1  0000              add [bx+si],al
000040B3  0000              add [bx+si],al
000040B5  0000              add [bx+si],al
000040B7  0000              add [bx+si],al
000040B9  0000              add [bx+si],al
000040BB  0000              add [bx+si],al
000040BD  0000              add [bx+si],al
000040BF  0000              add [bx+si],al
000040C1  0000              add [bx+si],al
000040C3  0000              add [bx+si],al
000040C5  0000              add [bx+si],al
000040C7  0000              add [bx+si],al
000040C9  0000              add [bx+si],al
000040CB  0000              add [bx+si],al
000040CD  0000              add [bx+si],al
000040CF  0000              add [bx+si],al
000040D1  0000              add [bx+si],al
000040D3  0000              add [bx+si],al
000040D5  0000              add [bx+si],al
000040D7  0000              add [bx+si],al
000040D9  0000              add [bx+si],al
000040DB  0000              add [bx+si],al
000040DD  0000              add [bx+si],al
000040DF  0000              add [bx+si],al
000040E1  0000              add [bx+si],al
000040E3  0000              add [bx+si],al
000040E5  0000              add [bx+si],al
000040E7  0000              add [bx+si],al
000040E9  0000              add [bx+si],al
000040EB  0000              add [bx+si],al
000040ED  0000              add [bx+si],al
000040EF  0000              add [bx+si],al
000040F1  0000              add [bx+si],al
000040F3  0000              add [bx+si],al
000040F5  0000              add [bx+si],al
000040F7  0000              add [bx+si],al
000040F9  0000              add [bx+si],al
000040FB  0000              add [bx+si],al
000040FD  0000              add [bx+si],al
000040FF  0000              add [bx+si],al
00004101  0000              add [bx+si],al
00004103  0000              add [bx+si],al
00004105  0000              add [bx+si],al
00004107  0000              add [bx+si],al
00004109  0000              add [bx+si],al
0000410B  0000              add [bx+si],al
0000410D  0000              add [bx+si],al
0000410F  0000              add [bx+si],al
00004111  0000              add [bx+si],al
00004113  0000              add [bx+si],al
00004115  0000              add [bx+si],al
00004117  0000              add [bx+si],al
00004119  0000              add [bx+si],al
0000411B  0000              add [bx+si],al
0000411D  0000              add [bx+si],al
0000411F  0000              add [bx+si],al
00004121  0000              add [bx+si],al
00004123  0000              add [bx+si],al
00004125  0000              add [bx+si],al
00004127  0000              add [bx+si],al
00004129  0000              add [bx+si],al
0000412B  0000              add [bx+si],al
0000412D  0000              add [bx+si],al
0000412F  0000              add [bx+si],al
00004131  0000              add [bx+si],al
00004133  0000              add [bx+si],al
00004135  0000              add [bx+si],al
00004137  0000              add [bx+si],al
00004139  0000              add [bx+si],al
0000413B  0000              add [bx+si],al
0000413D  0000              add [bx+si],al
0000413F  0000              add [bx+si],al
00004141  0000              add [bx+si],al
00004143  0000              add [bx+si],al
00004145  0000              add [bx+si],al
00004147  0000              add [bx+si],al
00004149  0000              add [bx+si],al
0000414B  0000              add [bx+si],al
0000414D  0000              add [bx+si],al
0000414F  0000              add [bx+si],al
00004151  0000              add [bx+si],al
00004153  0000              add [bx+si],al
00004155  0000              add [bx+si],al
00004157  0000              add [bx+si],al
00004159  0000              add [bx+si],al
0000415B  0000              add [bx+si],al
0000415D  0000              add [bx+si],al
0000415F  0000              add [bx+si],al
00004161  0000              add [bx+si],al
00004163  0000              add [bx+si],al
00004165  0000              add [bx+si],al
00004167  0000              add [bx+si],al
00004169  0000              add [bx+si],al
0000416B  0000              add [bx+si],al
0000416D  0000              add [bx+si],al
0000416F  0000              add [bx+si],al
00004171  0000              add [bx+si],al
00004173  0000              add [bx+si],al
00004175  0000              add [bx+si],al
00004177  2818              sub [bx+si],bl
00004179  0800              or [bx+si],al
0000417B  2009              and [bx+di],cl
0000417D  0F0006632D        sldt [0x2d63]
00004182  27                daa
00004183  28902B80          sub [bx+si-0x7fd5],dl
00004187  BF1F00            mov di,0x1f
0000418A  C00000            rol byte [bx+si],0x0
0000418D  0000              add [bx+si],al
0000418F  0000              add [bx+si],al
00004191  9C                pushfw
00004192  8E8F1400          mov cs,[bx+0x14]
00004196  96                xchg ax,si
00004197  B9E3FF            mov cx,0xffe3
0000419A  0001              add [bx+di],al
0000419C  0203              add al,[bp+di]
0000419E  0405              add al,0x5
000041A0  06                push es
000041A1  07                pop es
000041A2  1011              adc [bx+di],dl
000041A4  1213              adc dl,[bp+di]
000041A6  1415              adc al,0x15
000041A8  16                push ss
000041A9  17                pop ss
000041AA  0100              add [bx+si],ax
000041AC  0F0000            sldt [bx+si]
000041AF  0000              add [bx+si],al
000041B1  0000              add [bx+si],al
000041B3  0005              add [di],al
000041B5  0FFF              ud0
000041B7  50                push ax
000041B8  1808              sbb [bx+si],cl
000041BA  004001            add [bx+si+0x1],al
000041BD  0F0006635F        sldt [0x5f63]
000041C2  4F                dec di
000041C3  50                push ax
000041C4  82                db 0x82
000041C5  54                push sp
000041C6  80BF1F00C0        cmp byte [bx+0x1f],0xc0
000041CB  0000              add [bx+si],al
000041CD  0000              add [bx+si],al
000041CF  0000              add [bx+si],al
000041D1  9C                pushfw
000041D2  8E8F2800          mov cs,[bx+0x28]
000041D6  96                xchg ax,si
000041D7  B9E3FF            mov cx,0xffe3
000041DA  0001              add [bx+di],al
000041DC  0203              add al,[bp+di]
000041DE  0405              add al,0x5
000041E0  06                push es
000041E1  07                pop es
000041E2  1011              adc [bx+di],dl
000041E4  1213              adc dl,[bp+di]
000041E6  1415              adc al,0x15
000041E8  16                push ss
000041E9  17                pop ss
000041EA  0100              add [bx+si],ax
000041EC  0F0000            sldt [bx+si]
000041EF  0000              add [bx+si],al
000041F1  0000              add [bx+si],al
000041F3  0005              add [di],al
000041F5  0FFF              ud0
000041F7  0000              add [bx+si],al
000041F9  0000              add [bx+si],al
000041FB  0000              add [bx+si],al
000041FD  0000              add [bx+si],al
000041FF  0000              add [bx+si],al
00004201  0000              add [bx+si],al
00004203  0000              add [bx+si],al
00004205  0000              add [bx+si],al
00004207  0000              add [bx+si],al
00004209  0000              add [bx+si],al
0000420B  0000              add [bx+si],al
0000420D  0000              add [bx+si],al
0000420F  0000              add [bx+si],al
00004211  0000              add [bx+si],al
00004213  0000              add [bx+si],al
00004215  0000              add [bx+si],al
00004217  0000              add [bx+si],al
00004219  0000              add [bx+si],al
0000421B  0000              add [bx+si],al
0000421D  0000              add [bx+si],al
0000421F  0000              add [bx+si],al
00004221  0000              add [bx+si],al
00004223  0000              add [bx+si],al
00004225  0000              add [bx+si],al
00004227  0000              add [bx+si],al
00004229  0000              add [bx+si],al
0000422B  0000              add [bx+si],al
0000422D  0000              add [bx+si],al
0000422F  0000              add [bx+si],al
00004231  0000              add [bx+si],al
00004233  0000              add [bx+si],al
00004235  0000              add [bx+si],al
00004237  0000              add [bx+si],al
00004239  0000              add [bx+si],al
0000423B  0000              add [bx+si],al
0000423D  0000              add [bx+si],al
0000423F  0000              add [bx+si],al
00004241  0000              add [bx+si],al
00004243  0000              add [bx+si],al
00004245  0000              add [bx+si],al
00004247  0000              add [bx+si],al
00004249  0000              add [bx+si],al
0000424B  0000              add [bx+si],al
0000424D  0000              add [bx+si],al
0000424F  0000              add [bx+si],al
00004251  0000              add [bx+si],al
00004253  0000              add [bx+si],al
00004255  0000              add [bx+si],al
00004257  0000              add [bx+si],al
00004259  0000              add [bx+si],al
0000425B  0000              add [bx+si],al
0000425D  0000              add [bx+si],al
0000425F  0000              add [bx+si],al
00004261  0000              add [bx+si],al
00004263  0000              add [bx+si],al
00004265  0000              add [bx+si],al
00004267  0000              add [bx+si],al
00004269  0000              add [bx+si],al
0000426B  0000              add [bx+si],al
0000426D  0000              add [bx+si],al
0000426F  0000              add [bx+si],al
00004271  0000              add [bx+si],al
00004273  0000              add [bx+si],al
00004275  0000              add [bx+si],al
00004277  50                push ax
00004278  180E0080          sbb [0x8000],cl
0000427C  010F              add [bx],cx
0000427E  0006A35F          add [0x5fa3],al
00004282  4F                dec di
00004283  50                push ax
00004284  82                db 0x82
00004285  54                push sp
00004286  80BF1F0040        cmp byte [bx+0x1f],0x40
0000428B  0000              add [bx+si],al
0000428D  0000              add [bx+si],al
0000428F  0000              add [bx+si],al
00004291  83855D280F        add word [di+0x285d],byte +0xf
00004296  63BAE3FF          arpl [bp+si-0x1d],di
0000429A  0008              add [bx+si],cl
0000429C  0000              add [bx+si],al
0000429E  1818              sbb [bx+si],bl
000042A0  0000              add [bx+si],al
000042A2  0008              add [bx+si],cl
000042A4  0000              add [bx+si],al
000042A6  0018              add [bx+si],bl
000042A8  0000              add [bx+si],al
000042AA  0100              add [bx+si],ax
000042AC  0100              add [bx+si],ax
000042AE  0000              add [bx+si],al
000042B0  0000              add [bx+si],al
000042B2  0000              add [bx+si],al
000042B4  050FFF            add ax,0xff0f
000042B7  50                push ax
000042B8  180E0080          sbb [0x8000],cl
000042BC  010F              add [bx],cx
000042BE  0006A35F          add [0x5fa3],al
000042C2  4F                dec di
000042C3  50                push ax
000042C4  82                db 0x82
000042C5  54                push sp
000042C6  80BF1F0040        cmp byte [bx+0x1f],0x40
000042CB  0000              add [bx+si],al
000042CD  0000              add [bx+si],al
000042CF  0000              add [bx+si],al
000042D1  83855D280F        add word [di+0x285d],byte +0xf
000042D6  63BAE3FF          arpl [bp+si-0x1d],di
000042DA  0001              add [bx+di],al
000042DC  0203              add al,[bp+di]
000042DE  0405              add al,0x5
000042E0  1407              adc al,0x7
000042E2  3839              cmp [bx+di],bh
000042E4  3A3B              cmp bh,[bp+di]
000042E6  3C3D              cmp al,0x3d
000042E8  3E3F              ds aas
000042EA  0100              add [bx+si],ax
000042EC  0F0000            sldt [bx+si]
000042EF  0000              add [bx+si],al
000042F1  0000              add [bx+si],al
000042F3  0005              add [di],al
000042F5  0FFF              ud0
000042F7  0000              add [bx+si],al
000042F9  0000              add [bx+si],al
000042FB  0000              add [bx+si],al
000042FD  0000              add [bx+si],al
000042FF  0000              add [bx+si],al
00004301  0000              add [bx+si],al
00004303  0000              add [bx+si],al
00004305  0000              add [bx+si],al
00004307  0000              add [bx+si],al
00004309  0000              add [bx+si],al
0000430B  0000              add [bx+si],al
0000430D  0000              add [bx+si],al
0000430F  0000              add [bx+si],al
00004311  0000              add [bx+si],al
00004313  0000              add [bx+si],al
00004315  0000              add [bx+si],al
00004317  0000              add [bx+si],al
00004319  0000              add [bx+si],al
0000431B  0000              add [bx+si],al
0000431D  0000              add [bx+si],al
0000431F  0000              add [bx+si],al
00004321  0000              add [bx+si],al
00004323  0000              add [bx+si],al
00004325  0000              add [bx+si],al
00004327  0000              add [bx+si],al
00004329  0000              add [bx+si],al
0000432B  0000              add [bx+si],al
0000432D  0000              add [bx+si],al
0000432F  0000              add [bx+si],al
00004331  0000              add [bx+si],al
00004333  0000              add [bx+si],al
00004335  0000              add [bx+si],al
00004337  0000              add [bx+si],al
00004339  0000              add [bx+si],al
0000433B  0000              add [bx+si],al
0000433D  0000              add [bx+si],al
0000433F  0000              add [bx+si],al
00004341  0000              add [bx+si],al
00004343  0000              add [bx+si],al
00004345  0000              add [bx+si],al
00004347  0000              add [bx+si],al
00004349  0000              add [bx+si],al
0000434B  0000              add [bx+si],al
0000434D  0000              add [bx+si],al
0000434F  0000              add [bx+si],al
00004351  0000              add [bx+si],al
00004353  0000              add [bx+si],al
00004355  0000              add [bx+si],al
00004357  0000              add [bx+si],al
00004359  0000              add [bx+si],al
0000435B  0000              add [bx+si],al
0000435D  0000              add [bx+si],al
0000435F  0000              add [bx+si],al
00004361  0000              add [bx+si],al
00004363  0000              add [bx+si],al
00004365  0000              add [bx+si],al
00004367  0000              add [bx+si],al
00004369  0000              add [bx+si],al
0000436B  0000              add [bx+si],al
0000436D  0000              add [bx+si],al
0000436F  0000              add [bx+si],al
00004371  0000              add [bx+si],al
00004373  0000              add [bx+si],al
00004375  0000              add [bx+si],al
00004377  0000              add [bx+si],al
00004379  0000              add [bx+si],al
0000437B  0000              add [bx+si],al
0000437D  0000              add [bx+si],al
0000437F  0000              add [bx+si],al
00004381  0000              add [bx+si],al
00004383  0000              add [bx+si],al
00004385  0000              add [bx+si],al
00004387  0000              add [bx+si],al
00004389  0000              add [bx+si],al
0000438B  0000              add [bx+si],al
0000438D  0000              add [bx+si],al
0000438F  0000              add [bx+si],al
00004391  0000              add [bx+si],al
00004393  0000              add [bx+si],al
00004395  0000              add [bx+si],al
00004397  0000              add [bx+si],al
00004399  0000              add [bx+si],al
0000439B  0000              add [bx+si],al
0000439D  0000              add [bx+si],al
0000439F  0000              add [bx+si],al
000043A1  0000              add [bx+si],al
000043A3  0000              add [bx+si],al
000043A5  0000              add [bx+si],al
000043A7  0000              add [bx+si],al
000043A9  0000              add [bx+si],al
000043AB  0000              add [bx+si],al
000043AD  0000              add [bx+si],al
000043AF  0000              add [bx+si],al
000043B1  0000              add [bx+si],al
000043B3  0000              add [bx+si],al
000043B5  0000              add [bx+si],al
000043B7  0000              add [bx+si],al
000043B9  0000              add [bx+si],al
000043BB  0000              add [bx+si],al
000043BD  0000              add [bx+si],al
000043BF  0000              add [bx+si],al
000043C1  0000              add [bx+si],al
000043C3  0000              add [bx+si],al
000043C5  0000              add [bx+si],al
000043C7  0000              add [bx+si],al
000043C9  0000              add [bx+si],al
000043CB  0000              add [bx+si],al
000043CD  0000              add [bx+si],al
000043CF  0000              add [bx+si],al
000043D1  0000              add [bx+si],al
000043D3  0000              add [bx+si],al
000043D5  0000              add [bx+si],al
000043D7  0000              add [bx+si],al
000043D9  0000              add [bx+si],al
000043DB  0000              add [bx+si],al
000043DD  0000              add [bx+si],al
000043DF  0000              add [bx+si],al
000043E1  0000              add [bx+si],al
000043E3  0000              add [bx+si],al
000043E5  0000              add [bx+si],al
000043E7  0000              add [bx+si],al
000043E9  0000              add [bx+si],al
000043EB  0000              add [bx+si],al
000043ED  0000              add [bx+si],al
000043EF  0000              add [bx+si],al
000043F1  0000              add [bx+si],al
000043F3  0000              add [bx+si],al
000043F5  0000              add [bx+si],al
000043F7  2818              sub [bx+si],bl
000043F9  1000              adc [bx+si],al
000043FB  0808              or [bx+si],cl
000043FD  0300              add ax,[bx+si]
000043FF  02672D            add ah,[bx+0x2d]
00004402  27                daa
00004403  28902BA0          sub [bx+si-0x5fd5],dl
00004407  BF1F00            mov di,0x1f
0000440A  4F                dec di
0000440B  0D0E00            or ax,0xe
0000440E  0000              add [bx+si],al
00004410  009C8E8F          add [si-0x7072],bl
00004414  141F              adc al,0x1f
00004416  96                xchg ax,si
00004417  B9A3FF            mov cx,0xffa3
0000441A  0001              add [bx+di],al
0000441C  0203              add al,[bp+di]
0000441E  0405              add al,0x5
00004420  1407              adc al,0x7
00004422  3839              cmp [bx+di],bh
00004424  3A3B              cmp bh,[bp+di]
00004426  3C3D              cmp al,0x3d
00004428  3E3F              ds aas
0000442A  0C00              or al,0x0
0000442C  0F08              invd
0000442E  0000              add [bx+si],al
00004430  0000              add [bx+si],al
00004432  0010              add [bx+si],dl
00004434  0E                push cs
00004435  0FFF              ud0
00004437  50                push ax
00004438  1810              sbb [bx+si],dl
0000443A  0010              add [bx+si],dl
0000443C  0003              add [bp+di],al
0000443E  0002              add [bp+si],al
00004440  675F              a32 pop di
00004442  4F                dec di
00004443  50                push ax
00004444  82                db 0x82
00004445  55                push bp
00004446  81BF1F004F0D      cmp word [bx+0x1f],0xd4f
0000444C  0E                push cs
0000444D  0000              add [bx+si],al
0000444F  0000              add [bx+si],al
00004451  9C                pushfw
00004452  8E8F281F          mov cs,[bx+0x1f28]
00004456  96                xchg ax,si
00004457  B9A3FF            mov cx,0xffa3
0000445A  0001              add [bx+di],al
0000445C  0203              add al,[bp+di]
0000445E  0405              add al,0x5
00004460  1407              adc al,0x7
00004462  3839              cmp [bx+di],bh
00004464  3A3B              cmp bh,[bp+di]
00004466  3C3D              cmp al,0x3d
00004468  3E3F              ds aas
0000446A  0C00              or al,0x0
0000446C  0F08              invd
0000446E  0000              add [bx+si],al
00004470  0000              add [bx+si],al
00004472  0010              add [bx+si],dl
00004474  0E                push cs
00004475  0FFF              ud0
00004477  50                push ax
00004478  1810              sbb [bx+si],dl
0000447A  0010              add [bx+si],dl
0000447C  0003              add [bp+di],al
0000447E  0002              add [bp+si],al
00004480  665F              pop edi
00004482  4F                dec di
00004483  50                push ax
00004484  82                db 0x82
00004485  55                push bp
00004486  81BF1F004F0D      cmp word [bx+0x1f],0xd4f
0000448C  0E                push cs
0000448D  0000              add [bx+si],al
0000448F  0000              add [bx+si],al
00004491  9C                pushfw
00004492  8E8F280F          mov cs,[bx+0xf28]
00004496  96                xchg ax,si
00004497  B9A3FF            mov cx,0xffa3
0000449A  0008              add [bx+si],cl
0000449C  0808              or [bx+si],cl
0000449E  0808              or [bx+si],cl
000044A0  0808              or [bx+si],cl
000044A2  1018              adc [bx+si],bl
000044A4  1818              sbb [bx+si],bl
000044A6  1818              sbb [bx+si],bl
000044A8  1818              sbb [bx+si],bl
000044AA  0E                push cs
000044AB  000F              add [bx],cl
000044AD  0800              or [bx+si],al
000044AF  0000              add [bx+si],al
000044B1  0000              add [bx+si],al
000044B3  100A              adc [bp+si],cl
000044B5  0FFF              ud0
000044B7  50                push ax
000044B8  1D1000            sbb ax,0x10
000044BB  0001              add [bx+di],al
000044BD  0F0006E35F        sldt [0x5fe3]
000044C2  4F                dec di
000044C3  50                push ax
000044C4  82                db 0x82
000044C5  54                push sp
000044C6  800B3E            or byte [bp+di],0x3e
000044C9  004000            add [bx+si+0x0],al
000044CC  0000              add [bx+si],al
000044CE  0000              add [bx+si],al
000044D0  00EA              add dl,ch
000044D2  8CDF              mov di,ds
000044D4  2800              sub [bx+si],al
000044D6  E704              out 0x4,ax
000044D8  E3FF              jcxz 0x44d9
000044DA  003F              add [bx],bh
000044DC  003F              add [bx],bh
000044DE  003F              add [bx],bh
000044E0  003F              add [bx],bh
000044E2  003F              add [bx],bh
000044E4  003F              add [bx],bh
000044E6  003F              add [bx],bh
000044E8  003F              add [bx],bh
000044EA  0100              add [bx+si],ax
000044EC  0F0000            sldt [bx+si]
000044EF  0000              add [bx+si],al
000044F1  0000              add [bx+si],al
000044F3  0005              add [di],al
000044F5  0FFF              ud0
000044F7  50                push ax
000044F8  1D1000            sbb ax,0x10
000044FB  0001              add [bx+di],al
000044FD  0F0006E35F        sldt [0x5fe3]
00004502  4F                dec di
00004503  50                push ax
00004504  82                db 0x82
00004505  54                push sp
00004506  800B3E            or byte [bp+di],0x3e
00004509  004000            add [bx+si+0x0],al
0000450C  0000              add [bx+si],al
0000450E  0000              add [bx+si],al
00004510  00EA              add dl,ch
00004512  8CDF              mov di,ds
00004514  2800              sub [bx+si],al
00004516  E704              out 0x4,ax
00004518  E3FF              jcxz 0x4519
0000451A  0001              add [bx+di],al
0000451C  0203              add al,[bp+di]
0000451E  0405              add al,0x5
00004520  1407              adc al,0x7
00004522  3839              cmp [bx+di],bh
00004524  3A3B              cmp bh,[bp+di]
00004526  3C3D              cmp al,0x3d
00004528  3E3F              ds aas
0000452A  0100              add [bx+si],ax
0000452C  0F0000            sldt [bx+si]
0000452F  0000              add [bx+si],al
00004531  0000              add [bx+si],al
00004533  0005              add [di],al
00004535  0FFF              ud0
00004537  2818              sub [bx+si],bl
00004539  0800              or [bx+si],al
0000453B  0001              add [bx+di],al
0000453D  0F000E635F        str [0x5f63]
00004542  4F                dec di
00004543  50                push ax
00004544  82                db 0x82
00004545  54                push sp
00004546  80BF1F0041        cmp byte [bx+0x1f],0x41
0000454B  0000              add [bx+si],al
0000454D  0000              add [bx+si],al
0000454F  0000              add [bx+si],al
00004551  9C                pushfw
00004552  8E8F2840          mov cs,[bx+0x4028]
00004556  96                xchg ax,si
00004557  B9A3FF            mov cx,0xffa3
0000455A  0001              add [bx+di],al
0000455C  0203              add al,[bp+di]
0000455E  0405              add al,0x5
00004560  06                push es
00004561  07                pop es
00004562  0809              or [bx+di],cl
00004564  0A0B              or cl,[bp+di]
00004566  0C0D              or al,0xd
00004568  0E                push cs
00004569  0F4100            cmovno ax,[bx+si]
0000456C  0F0000            sldt [bx+si]
0000456F  0000              add [bx+si],al
00004571  0000              add [bx+si],al
00004573  40                inc ax
00004574  050FFF            add ax,0xff0f
00004577  642410            fs and al,0x10
0000457A  0000              add [bx+si],al
0000457C  010F              add [bx],cx
0000457E  0006E37F          add [0x7fe3],al
00004582  636383            arpl [bp+di-0x7d],sp
00004585  6B1B72            imul bx,[bp+di],byte +0x72
00004588  F0006000          lock add [bx+si+0x0],ah
0000458C  0000              add [bx+si],al
0000458E  0000              add [bx+si],al
00004590  00598D            add [bx+di-0x73],bl
00004593  57                push di
00004594  3200              xor al,[bx+si]
00004596  57                push di
00004597  73E3              jnc 0x457c
00004599  FF00              inc word [bx+si]
0000459B  0102              add [bp+si],ax
0000459D  0304              add ax,[si]
0000459F  051407            add ax,0x714
000045A2  3839              cmp [bx+di],bh
000045A4  3A3B              cmp bh,[bp+di]
000045A6  3C3D              cmp al,0x3d
000045A8  3E3F              ds aas
000045AA  0100              add [bx+si],ax
000045AC  0F0000            sldt [bx+si]
000045AF  0000              add [bx+si],al
000045B1  0000              add [bx+si],al
000045B3  0005              add [di],al
000045B5  0FFF              ud0
000045B7  0000              add [bx+si],al
000045B9  0000              add [bx+si],al
000045BB  0000              add [bx+si],al
000045BD  0000              add [bx+si],al
000045BF  0000              add [bx+si],al
000045C1  0000              add [bx+si],al
000045C3  0000              add [bx+si],al
000045C5  0000              add [bx+si],al
000045C7  0000              add [bx+si],al
000045C9  0000              add [bx+si],al
000045CB  0000              add [bx+si],al
000045CD  0000              add [bx+si],al
000045CF  2A2A              sub ch,[bp+si]
000045D1  2A2A              sub ch,[bp+si]
000045D3  2A2A              sub ch,[bp+si]
000045D5  2A2A              sub ch,[bp+si]
000045D7  2A2A              sub ch,[bp+si]
000045D9  2A2A              sub ch,[bp+si]
000045DB  2A2A              sub ch,[bp+si]
000045DD  2A2A              sub ch,[bp+si]
000045DF  2A2A              sub ch,[bp+si]
000045E1  2A2A              sub ch,[bp+si]
000045E3  2A2A              sub ch,[bp+si]
000045E5  2A2A              sub ch,[bp+si]
000045E7  2A2A              sub ch,[bp+si]
000045E9  2A2A              sub ch,[bp+si]
000045EB  2A2A              sub ch,[bp+si]
000045ED  2A2A              sub ch,[bp+si]
000045EF  2A2A              sub ch,[bp+si]
000045F1  2A2A              sub ch,[bp+si]
000045F3  2A2A              sub ch,[bp+si]
000045F5  2A2A              sub ch,[bp+si]
000045F7  2A2A              sub ch,[bp+si]
000045F9  2A2A              sub ch,[bp+si]
000045FB  2A2A              sub ch,[bp+si]
000045FD  2A2A              sub ch,[bp+si]
000045FF  3F                aas
00004600  3F                aas
00004601  3F                aas
00004602  3F                aas
00004603  3F                aas
00004604  3F                aas
00004605  3F                aas
00004606  3F                aas
00004607  3F                aas
00004608  3F                aas
00004609  3F                aas
0000460A  3F                aas
0000460B  3F                aas
0000460C  3F                aas
0000460D  3F                aas
0000460E  3F                aas
0000460F  3F                aas
00004610  3F                aas
00004611  3F                aas
00004612  3F                aas
00004613  3F                aas
00004614  3F                aas
00004615  3F                aas
00004616  3F                aas
00004617  0000              add [bx+si],al
00004619  0000              add [bx+si],al
0000461B  0000              add [bx+si],al
0000461D  0000              add [bx+si],al
0000461F  0000              add [bx+si],al
00004621  0000              add [bx+si],al
00004623  0000              add [bx+si],al
00004625  0000              add [bx+si],al
00004627  0000              add [bx+si],al
00004629  0000              add [bx+si],al
0000462B  0000              add [bx+si],al
0000462D  0000              add [bx+si],al
0000462F  2A2A              sub ch,[bp+si]
00004631  2A2A              sub ch,[bp+si]
00004633  2A2A              sub ch,[bp+si]
00004635  2A2A              sub ch,[bp+si]
00004637  2A2A              sub ch,[bp+si]
00004639  2A2A              sub ch,[bp+si]
0000463B  2A2A              sub ch,[bp+si]
0000463D  2A2A              sub ch,[bp+si]
0000463F  2A2A              sub ch,[bp+si]
00004641  2A2A              sub ch,[bp+si]
00004643  2A2A              sub ch,[bp+si]
00004645  2A2A              sub ch,[bp+si]
00004647  2A2A              sub ch,[bp+si]
00004649  2A2A              sub ch,[bp+si]
0000464B  2A2A              sub ch,[bp+si]
0000464D  2A2A              sub ch,[bp+si]
0000464F  2A2A              sub ch,[bp+si]
00004651  2A2A              sub ch,[bp+si]
00004653  2A2A              sub ch,[bp+si]
00004655  2A2A              sub ch,[bp+si]
00004657  2A2A              sub ch,[bp+si]
00004659  2A2A              sub ch,[bp+si]
0000465B  2A2A              sub ch,[bp+si]
0000465D  2A2A              sub ch,[bp+si]
0000465F  3F                aas
00004660  3F                aas
00004661  3F                aas
00004662  3F                aas
00004663  3F                aas
00004664  3F                aas
00004665  3F                aas
00004666  3F                aas
00004667  3F                aas
00004668  3F                aas
00004669  3F                aas
0000466A  3F                aas
0000466B  3F                aas
0000466C  3F                aas
0000466D  3F                aas
0000466E  3F                aas
0000466F  3F                aas
00004670  3F                aas
00004671  3F                aas
00004672  3F                aas
00004673  3F                aas
00004674  3F                aas
00004675  3F                aas
00004676  3F                aas
00004677  0000              add [bx+si],al
00004679  0000              add [bx+si],al
0000467B  002A              add [bp+si],ch
0000467D  002A              add [bp+si],ch
0000467F  0000              add [bx+si],al
00004681  2A2A              sub ch,[bp+si]
00004683  2A00              sub al,[bx+si]
00004685  002A              add [bp+si],ch
00004687  002A              add [bp+si],ch
00004689  2A15              sub dl,[di]
0000468B  002A              add [bp+si],ch
0000468D  2A2A              sub ch,[bp+si]
0000468F  0000              add [bx+si],al
00004691  0000              add [bx+si],al
00004693  002A              add [bp+si],ch
00004695  002A              add [bp+si],ch
00004697  0000              add [bx+si],al
00004699  2A2A              sub ch,[bp+si]
0000469B  2A00              sub al,[bx+si]
0000469D  002A              add [bp+si],ch
0000469F  002A              add [bp+si],ch
000046A1  2A15              sub dl,[di]
000046A3  002A              add [bp+si],ch
000046A5  2A2A              sub ch,[bp+si]
000046A7  151515            adc ax,0x1515
000046AA  15153F            adc ax,0x3f15
000046AD  153F15            adc ax,0x153f
000046B0  153F3F            adc ax,0x3f3f
000046B3  3F                aas
000046B4  15153F            adc ax,0x3f15
000046B7  153F3F            adc ax,0x3f3f
000046BA  3F                aas
000046BB  153F3F            adc ax,0x3f3f
000046BE  3F                aas
000046BF  151515            adc ax,0x1515
000046C2  15153F            adc ax,0x3f15
000046C5  153F15            adc ax,0x153f
000046C8  153F3F            adc ax,0x3f3f
000046CB  3F                aas
000046CC  15153F            adc ax,0x3f15
000046CF  153F3F            adc ax,0x3f3f
000046D2  3F                aas
000046D3  153F3F            adc ax,0x3f3f
000046D6  3F                aas
000046D7  0000              add [bx+si],al
000046D9  0000              add [bx+si],al
000046DB  002A              add [bp+si],ch
000046DD  002A              add [bp+si],ch
000046DF  0000              add [bx+si],al
000046E1  2A2A              sub ch,[bp+si]
000046E3  2A00              sub al,[bx+si]
000046E5  002A              add [bp+si],ch
000046E7  002A              add [bp+si],ch
000046E9  2A15              sub dl,[di]
000046EB  002A              add [bp+si],ch
000046ED  2A2A              sub ch,[bp+si]
000046EF  0000              add [bx+si],al
000046F1  0000              add [bx+si],al
000046F3  002A              add [bp+si],ch
000046F5  002A              add [bp+si],ch
000046F7  0000              add [bx+si],al
000046F9  2A2A              sub ch,[bp+si]
000046FB  2A00              sub al,[bx+si]
000046FD  002A              add [bp+si],ch
000046FF  002A              add [bp+si],ch
00004701  2A15              sub dl,[di]
00004703  002A              add [bp+si],ch
00004705  2A2A              sub ch,[bp+si]
00004707  151515            adc ax,0x1515
0000470A  15153F            adc ax,0x3f15
0000470D  153F15            adc ax,0x153f
00004710  153F3F            adc ax,0x3f3f
00004713  3F                aas
00004714  15153F            adc ax,0x3f15
00004717  153F3F            adc ax,0x3f3f
0000471A  3F                aas
0000471B  153F3F            adc ax,0x3f3f
0000471E  3F                aas
0000471F  151515            adc ax,0x1515
00004722  15153F            adc ax,0x3f15
00004725  153F15            adc ax,0x153f
00004728  153F3F            adc ax,0x3f3f
0000472B  3F                aas
0000472C  15153F            adc ax,0x3f15
0000472F  153F3F            adc ax,0x3f3f
00004732  3F                aas
00004733  153F3F            adc ax,0x3f3f
00004736  3F                aas
00004737  0000              add [bx+si],al
00004739  0000              add [bx+si],al
0000473B  002A              add [bp+si],ch
0000473D  002A              add [bp+si],ch
0000473F  0000              add [bx+si],al
00004741  2A2A              sub ch,[bp+si]
00004743  2A00              sub al,[bx+si]
00004745  002A              add [bp+si],ch
00004747  002A              add [bp+si],ch
00004749  2A2A              sub ch,[bp+si]
0000474B  002A              add [bp+si],ch
0000474D  2A2A              sub ch,[bp+si]
0000474F  0000              add [bx+si],al
00004751  150000            adc ax,0x0
00004754  3F                aas
00004755  002A              add [bp+si],ch
00004757  15002A            adc ax,0x2a00
0000475A  3F                aas
0000475B  2A00              sub al,[bx+si]
0000475D  152A00            adc ax,0x2a
00004760  3F                aas
00004761  2A2A              sub ch,[bp+si]
00004763  152A2A            adc ax,0x2a2a
00004766  3F                aas
00004767  0015              add [di],dl
00004769  0000              add [bx+si],al
0000476B  152A00            adc ax,0x2a
0000476E  3F                aas
0000476F  0000              add [bx+si],al
00004771  3F                aas
00004772  2A2A              sub ch,[bp+si]
00004774  15002A            adc ax,0x2a00
00004777  152A2A            adc ax,0x2a2a
0000477A  3F                aas
0000477B  002A              add [bp+si],ch
0000477D  3F                aas
0000477E  2A00              sub al,[bx+si]
00004780  151500            adc ax,0x15
00004783  153F00            adc ax,0x3f
00004786  3F                aas
00004787  15003F            adc ax,0x3f00
0000478A  3F                aas
0000478B  2A15              sub dl,[di]
0000478D  152A15            adc ax,0x152a
00004790  3F                aas
00004791  2A3F              sub bh,[bx]
00004793  152A3F            adc ax,0x3f2a
00004796  3F                aas
00004797  150000            adc ax,0x0
0000479A  15002A            adc ax,0x2a00
0000479D  152A00            adc ax,0x2a
000047A0  152A2A            adc ax,0x2a2a
000047A3  3F                aas
000047A4  0000              add [bx+si],al
000047A6  3F                aas
000047A7  002A              add [bp+si],ch
000047A9  3F                aas
000047AA  2A00              sub al,[bx+si]
000047AC  3F                aas
000047AD  2A2A              sub ch,[bp+si]
000047AF  150015            adc ax,0x1500
000047B2  15003F            adc ax,0x3f00
000047B5  152A15            adc ax,0x152a
000047B8  152A3F            adc ax,0x3f2a
000047BB  3F                aas
000047BC  0015              add [di],dl
000047BE  3F                aas
000047BF  003F              add [bx],bh
000047C1  3F                aas
000047C2  2A15              sub dl,[di]
000047C4  3F                aas
000047C5  2A3F              sub bh,[bx]
000047C7  151500            adc ax,0x15
000047CA  15152A            adc ax,0x2a15
000047CD  153F00            adc ax,0x3f
000047D0  153F2A            adc ax,0x2a3f
000047D3  3F                aas
000047D4  15003F            adc ax,0x3f00
000047D7  152A3F            adc ax,0x3f2a
000047DA  3F                aas
000047DB  003F              add [bx],bh
000047DD  3F                aas
000047DE  2A15              sub dl,[di]
000047E0  151515            adc ax,0x1515
000047E3  153F15            adc ax,0x153f
000047E6  3F                aas
000047E7  15153F            adc ax,0x3f15
000047EA  3F                aas
000047EB  3F                aas
000047EC  15153F            adc ax,0x3f15
000047EF  153F3F            adc ax,0x3f3f
000047F2  3F                aas
000047F3  153F3F            adc ax,0x3f3f
000047F6  3F                aas
000047F7  0000              add [bx+si],al
000047F9  0000              add [bx+si],al
000047FB  002A              add [bp+si],ch
000047FD  002A              add [bp+si],ch
000047FF  0000              add [bx+si],al
00004801  2A2A              sub ch,[bp+si]
00004803  2A00              sub al,[bx+si]
00004805  002A              add [bp+si],ch
00004807  002A              add [bp+si],ch
00004809  2A15              sub dl,[di]
0000480B  002A              add [bp+si],ch
0000480D  2A2A              sub ch,[bp+si]
0000480F  151515            adc ax,0x1515
00004812  15153F            adc ax,0x3f15
00004815  153F15            adc ax,0x153f
00004818  153F3F            adc ax,0x3f3f
0000481B  3F                aas
0000481C  15153F            adc ax,0x3f15
0000481F  153F3F            adc ax,0x3f3f
00004822  3F                aas
00004823  153F3F            adc ax,0x3f3f
00004826  3F                aas
00004827  0000              add [bx+si],al
00004829  0005              add [di],al
0000482B  050508            add ax,0x805
0000482E  0808              or [bx+si],cl
00004830  0B0B              or cx,[bp+di]
00004832  0B0E0E0E          or cx,[0xe0e]
00004836  1111              adc [bx+di],dx
00004838  1114              adc [si],dx
0000483A  1414              adc al,0x14
0000483C  1818              sbb [bx+si],bl
0000483E  181C              sbb [si],bl
00004840  1C1C              sbb al,0x1c
00004842  2020              and [bx+si],ah
00004844  2024              and [si],ah
00004846  2424              and al,0x24
00004848  2828              sub [bx+si],ch
0000484A  282D              sub [di],ch
0000484C  2D2D32            sub ax,0x322d
0000484F  3232              xor dh,[bp+si]
00004851  3838              cmp [bx+si],bh
00004853  383F              cmp [bx],bh
00004855  3F                aas
00004856  3F                aas
00004857  0000              add [bx+si],al
00004859  3F                aas
0000485A  1000              adc [bx+si],al
0000485C  3F                aas
0000485D  1F                pop ds
0000485E  003F              add [bx],bh
00004860  2F                das
00004861  003F              add [bx],bh
00004863  3F                aas
00004864  003F              add [bx],bh
00004866  3F                aas
00004867  002F              add [bx],ch
00004869  3F                aas
0000486A  001F              add [bx],bl
0000486C  3F                aas
0000486D  0010              add [bx+si],dl
0000486F  3F                aas
00004870  0000              add [bx+si],al
00004872  3F                aas
00004873  1000              adc [bx+si],al
00004875  3F                aas
00004876  1F                pop ds
00004877  003F              add [bx],bh
00004879  2F                das
0000487A  003F              add [bx],bh
0000487C  3F                aas
0000487D  002F              add [bx],ch
0000487F  3F                aas
00004880  001F              add [bx],bl
00004882  3F                aas
00004883  0010              add [bx+si],dl
00004885  3F                aas
00004886  0000              add [bx+si],al
00004888  3F                aas
00004889  0000              add [bx+si],al
0000488B  3F                aas
0000488C  1000              adc [bx+si],al
0000488E  3F                aas
0000488F  1F                pop ds
00004890  003F              add [bx],bh
00004892  2F                das
00004893  003F              add [bx],bh
00004895  3F                aas
00004896  002F              add [bx],ch
00004898  3F                aas
00004899  001F              add [bx],bl
0000489B  3F                aas
0000489C  0010              add [bx+si],dl
0000489E  3F                aas
0000489F  1F                pop ds
000048A0  1F                pop ds
000048A1  3F                aas
000048A2  27                daa
000048A3  1F                pop ds
000048A4  3F                aas
000048A5  2F                das
000048A6  1F                pop ds
000048A7  3F                aas
000048A8  37                aaa
000048A9  1F                pop ds
000048AA  3F                aas
000048AB  3F                aas
000048AC  1F                pop ds
000048AD  3F                aas
000048AE  3F                aas
000048AF  1F                pop ds
000048B0  37                aaa
000048B1  3F                aas
000048B2  1F                pop ds
000048B3  2F                das
000048B4  3F                aas
000048B5  1F                pop ds
000048B6  27                daa
000048B7  3F                aas
000048B8  1F                pop ds
000048B9  1F                pop ds
000048BA  3F                aas
000048BB  27                daa
000048BC  1F                pop ds
000048BD  3F                aas
000048BE  2F                das
000048BF  1F                pop ds
000048C0  3F                aas
000048C1  37                aaa
000048C2  1F                pop ds
000048C3  3F                aas
000048C4  3F                aas
000048C5  1F                pop ds
000048C6  37                aaa
000048C7  3F                aas
000048C8  1F                pop ds
000048C9  2F                das
000048CA  3F                aas
000048CB  1F                pop ds
000048CC  27                daa
000048CD  3F                aas
000048CE  1F                pop ds
000048CF  1F                pop ds
000048D0  3F                aas
000048D1  1F                pop ds
000048D2  1F                pop ds
000048D3  3F                aas
000048D4  27                daa
000048D5  1F                pop ds
000048D6  3F                aas
000048D7  2F                das
000048D8  1F                pop ds
000048D9  3F                aas
000048DA  37                aaa
000048DB  1F                pop ds
000048DC  3F                aas
000048DD  3F                aas
000048DE  1F                pop ds
000048DF  37                aaa
000048E0  3F                aas
000048E1  1F                pop ds
000048E2  2F                das
000048E3  3F                aas
000048E4  1F                pop ds
000048E5  27                daa
000048E6  3F                aas
000048E7  2D2D3F            sub ax,0x3f2d
000048EA  312D              xor [di],bp
000048EC  3F                aas
000048ED  362D3F3A          ss sub ax,0x3a3f
000048F1  2D3F3F            sub ax,0x3f3f
000048F4  2D3F3F            sub ax,0x3f3f
000048F7  2D3A3F            sub ax,0x3f3a
000048FA  2D363F            sub ax,0x3f36
000048FD  2D313F            sub ax,0x3f31
00004900  2D2D3F            sub ax,0x3f2d
00004903  312D              xor [di],bp
00004905  3F                aas
00004906  362D3F3A          ss sub ax,0x3a3f
0000490A  2D3F3F            sub ax,0x3f3f
0000490D  2D3A3F            sub ax,0x3f3a
00004910  2D363F            sub ax,0x3f36
00004913  2D313F            sub ax,0x3f31
00004916  2D2D3F            sub ax,0x3f2d
00004919  2D2D3F            sub ax,0x3f2d
0000491C  312D              xor [di],bp
0000491E  3F                aas
0000491F  362D3F3A          ss sub ax,0x3a3f
00004923  2D3F3F            sub ax,0x3f3f
00004926  2D3A3F            sub ax,0x3f3a
00004929  2D363F            sub ax,0x3f36
0000492C  2D313F            sub ax,0x3f31
0000492F  0000              add [bx+si],al
00004931  1C07              sbb al,0x7
00004933  001C              add [si],bl
00004935  0E                push cs
00004936  001C              add [si],bl
00004938  15001C            adc ax,0x1c00
0000493B  1C00              sbb al,0x0
0000493D  1C1C              sbb al,0x1c
0000493F  0015              add [di],dl
00004941  1C00              sbb al,0x0
00004943  0E                push cs
00004944  1C00              sbb al,0x0
00004946  07                pop es
00004947  1C00              sbb al,0x0
00004949  001C              add [si],bl
0000494B  07                pop es
0000494C  001C              add [si],bl
0000494E  0E                push cs
0000494F  001C              add [si],bl
00004951  15001C            adc ax,0x1c00
00004954  1C00              sbb al,0x0
00004956  151C00            adc ax,0x1c
00004959  0E                push cs
0000495A  1C00              sbb al,0x0
0000495C  07                pop es
0000495D  1C00              sbb al,0x0
0000495F  001C              add [si],bl
00004961  0000              add [bx+si],al
00004963  1C07              sbb al,0x7
00004965  001C              add [si],bl
00004967  0E                push cs
00004968  001C              add [si],bl
0000496A  15001C            adc ax,0x1c00
0000496D  1C00              sbb al,0x0
0000496F  151C00            adc ax,0x1c
00004972  0E                push cs
00004973  1C00              sbb al,0x0
00004975  07                pop es
00004976  1C0E              sbb al,0xe
00004978  0E                push cs
00004979  1C11              sbb al,0x11
0000497B  0E                push cs
0000497C  1C15              sbb al,0x15
0000497E  0E                push cs
0000497F  1C18              sbb al,0x18
00004981  0E                push cs
00004982  1C1C              sbb al,0x1c
00004984  0E                push cs
00004985  1C1C              sbb al,0x1c
00004987  0E                push cs
00004988  181C              sbb [si],bl
0000498A  0E                push cs
0000498B  151C0E            adc ax,0xe1c
0000498E  111C              adc [si],bx
00004990  0E                push cs
00004991  0E                push cs
00004992  1C11              sbb al,0x11
00004994  0E                push cs
00004995  1C15              sbb al,0x15
00004997  0E                push cs
00004998  1C18              sbb al,0x18
0000499A  0E                push cs
0000499B  1C1C              sbb al,0x1c
0000499D  0E                push cs
0000499E  181C              sbb [si],bl
000049A0  0E                push cs
000049A1  151C0E            adc ax,0xe1c
000049A4  111C              adc [si],bx
000049A6  0E                push cs
000049A7  0E                push cs
000049A8  1C0E              sbb al,0xe
000049AA  0E                push cs
000049AB  1C11              sbb al,0x11
000049AD  0E                push cs
000049AE  1C15              sbb al,0x15
000049B0  0E                push cs
000049B1  1C18              sbb al,0x18
000049B3  0E                push cs
000049B4  1C1C              sbb al,0x1c
000049B6  0E                push cs
000049B7  181C              sbb [si],bl
000049B9  0E                push cs
000049BA  151C0E            adc ax,0xe1c
000049BD  111C              adc [si],bx
000049BF  1414              adc al,0x14
000049C1  1C16              sbb al,0x16
000049C3  141C              adc al,0x1c
000049C5  1814              sbb [si],dl
000049C7  1C1A              sbb al,0x1a
000049C9  141C              adc al,0x1c
000049CB  1C14              sbb al,0x14
000049CD  1C1C              sbb al,0x1c
000049CF  141A              adc al,0x1a
000049D1  1C14              sbb al,0x14
000049D3  181C              sbb [si],bl
000049D5  1416              adc al,0x16
000049D7  1C14              sbb al,0x14
000049D9  141C              adc al,0x1c
000049DB  16                push ss
000049DC  141C              adc al,0x1c
000049DE  1814              sbb [si],dl
000049E0  1C1A              sbb al,0x1a
000049E2  141C              adc al,0x1c
000049E4  1C14              sbb al,0x14
000049E6  1A1C              sbb bl,[si]
000049E8  1418              adc al,0x18
000049EA  1C14              sbb al,0x14
000049EC  16                push ss
000049ED  1C14              sbb al,0x14
000049EF  141C              adc al,0x1c
000049F1  1414              adc al,0x14
000049F3  1C16              sbb al,0x16
000049F5  141C              adc al,0x1c
000049F7  1814              sbb [si],dl
000049F9  1C1A              sbb al,0x1a
000049FB  141C              adc al,0x1c
000049FD  1C14              sbb al,0x14
000049FF  1A1C              sbb bl,[si]
00004A01  1418              adc al,0x18
00004A03  1C14              sbb al,0x14
00004A05  16                push ss
00004A06  1C00              sbb al,0x0
00004A08  0010              add [bx+si],dl
00004A0A  0400              add al,0x0
00004A0C  1008              adc [bx+si],cl
00004A0E  0010              add [bx+si],dl
00004A10  0C00              or al,0x0
00004A12  1010              adc [bx+si],dl
00004A14  0010              add [bx+si],dl
00004A16  1000              adc [bx+si],al
00004A18  0C10              or al,0x10
00004A1A  0008              add [bx+si],cl
00004A1C  1000              adc [bx+si],al
00004A1E  0410              add al,0x10
00004A20  0000              add [bx+si],al
00004A22  1004              adc [si],al
00004A24  0010              add [bx+si],dl
00004A26  0800              or [bx+si],al
00004A28  100C              adc [si],cl
00004A2A  0010              add [bx+si],dl
00004A2C  1000              adc [bx+si],al
00004A2E  0C10              or al,0x10
00004A30  0008              add [bx+si],cl
00004A32  1000              adc [bx+si],al
00004A34  0410              add al,0x10
00004A36  0000              add [bx+si],al
00004A38  1000              adc [bx+si],al
00004A3A  0010              add [bx+si],dl
00004A3C  0400              add al,0x0
00004A3E  1008              adc [bx+si],cl
00004A40  0010              add [bx+si],dl
00004A42  0C00              or al,0x0
00004A44  1010              adc [bx+si],dl
00004A46  000C              add [si],cl
00004A48  1000              adc [bx+si],al
00004A4A  0810              or [bx+si],dl
00004A4C  0004              add [si],al
00004A4E  1008              adc [bx+si],cl
00004A50  0810              or [bx+si],dl
00004A52  0A08              or cl,[bx+si]
00004A54  100C              adc [si],cl
00004A56  0810              or [bx+si],dl
00004A58  0E                push cs
00004A59  0810              or [bx+si],dl
00004A5B  1008              adc [bx+si],cl
00004A5D  1010              adc [bx+si],dl
00004A5F  080E1008          or [0x810],cl
00004A63  0C10              or al,0x10
00004A65  080A              or [bp+si],cl
00004A67  1008              adc [bx+si],cl
00004A69  0810              or [bx+si],dl
00004A6B  0A08              or cl,[bx+si]
00004A6D  100C              adc [si],cl
00004A6F  0810              or [bx+si],dl
00004A71  0E                push cs
00004A72  0810              or [bx+si],dl
00004A74  1008              adc [bx+si],cl
00004A76  0E                push cs
00004A77  1008              adc [bx+si],cl
00004A79  0C10              or al,0x10
00004A7B  080A              or [bp+si],cl
00004A7D  1008              adc [bx+si],cl
00004A7F  0810              or [bx+si],dl
00004A81  0808              or [bx+si],cl
00004A83  100A              adc [bp+si],cl
00004A85  0810              or [bx+si],dl
00004A87  0C08              or al,0x8
00004A89  100E0810          adc [0x1008],cl
00004A8D  1008              adc [bx+si],cl
00004A8F  0E                push cs
00004A90  1008              adc [bx+si],cl
00004A92  0C10              or al,0x10
00004A94  080A              or [bp+si],cl
00004A96  100B              adc [bp+di],cl
00004A98  0B10              or dx,[bx+si]
00004A9A  0C0B              or al,0xb
00004A9C  100D              adc [di],cl
00004A9E  0B10              or dx,[bx+si]
00004AA0  0F0B              ud2
00004AA2  1010              adc [bx+si],dl
00004AA4  0B10              or dx,[bx+si]
00004AA6  100B              adc [bp+di],cl
00004AA8  0F100B            movups xmm1,[bp+di]
00004AAB  0D100B            or ax,0xb10
00004AAE  0C10              or al,0x10
00004AB0  0B0B              or cx,[bp+di]
00004AB2  100C              adc [si],cl
00004AB4  0B10              or dx,[bx+si]
00004AB6  0D0B10            or ax,0x100b
00004AB9  0F0B              ud2
00004ABB  1010              adc [bx+si],dl
00004ABD  0B0F              or cx,[bx]
00004ABF  100B              adc [bp+di],cl
00004AC1  0D100B            or ax,0xb10
00004AC4  0C10              or al,0x10
00004AC6  0B0B              or cx,[bp+di]
00004AC8  100B              adc [bp+di],cl
00004ACA  0B10              or dx,[bx+si]
00004ACC  0C0B              or al,0xb
00004ACE  100D              adc [di],cl
00004AD0  0B10              or dx,[bx+si]
00004AD2  0F0B              ud2
00004AD4  1010              adc [bx+si],dl
00004AD6  0B0F              or cx,[bx]
00004AD8  100B              adc [bp+di],cl
00004ADA  0D100B            or ax,0xb10
00004ADD  0C10              or al,0x10
00004ADF  0000              add [bx+si],al
00004AE1  0000              add [bx+si],al
00004AE3  0000              add [bx+si],al
00004AE5  0000              add [bx+si],al
00004AE7  0000              add [bx+si],al
00004AE9  0000              add [bx+si],al
00004AEB  0000              add [bx+si],al
00004AED  0000              add [bx+si],al
00004AEF  0000              add [bx+si],al
00004AF1  0000              add [bx+si],al
00004AF3  0000              add [bx+si],al
00004AF5  0000              add [bx+si],al
00004AF7  FFE0              jmp ax
00004AF9  0F0000            sldt [bx+si]
00004AFC  0000              add [bx+si],al
00004AFE  07                pop es
00004AFF  0208              add cl,[bx+si]
00004B01  E70C              out 0xc,ax
00004B03  0000              add [bx+si],al
00004B05  0000              add [bx+si],al
00004B07  0000              add [bx+si],al
00004B09  0000              add [bx+si],al
00004B0B  0000              add [bx+si],al
00004B0D  0000              add [bx+si],al
00004B0F  7E81              jng 0x4a92
00004B11  A5                movsw
00004B12  81BD99817E7E      cmp word [di-0x7e67],0x7e7e
00004B18  FF                db 0xff
00004B19  DB                db 0xdb
00004B1A  FFC3              inc bx
00004B1C  E7FF              out 0xff,ax
00004B1E  7E6C              jng 0x4b8c
00004B20  FE                db 0xfe
00004B21  FE                db 0xfe
00004B22  FE                db 0xfe
00004B23  7C38              jl 0x4b5d
00004B25  1000              adc [bx+si],al
00004B27  1038              adc [bx+si],bh
00004B29  7CFE              jl 0x4b29
00004B2B  7C38              jl 0x4b65
00004B2D  1000              adc [bx+si],al
00004B2F  387C38            cmp [si+0x38],bh
00004B32  FE                db 0xfe
00004B33  FE                db 0xfe
00004B34  7C38              jl 0x4b6e
00004B36  7C10              jl 0x4b48
00004B38  1038              adc [bx+si],bh
00004B3A  7CFE              jl 0x4b3a
00004B3C  7C38              jl 0x4b76
00004B3E  7C00              jl 0x4b40
00004B40  0018              add [bx+si],bl
00004B42  3C3C              cmp al,0x3c
00004B44  1800              sbb [bx+si],al
00004B46  00FF              add bh,bh
00004B48  FFE7              jmp di
00004B4A  C3                ret
00004B4B  C3                ret
00004B4C  E7FF              out 0xff,ax
00004B4E  FF00              inc word [bx+si]
00004B50  3C66              cmp al,0x66
00004B52  42                inc dx
00004B53  42                inc dx
00004B54  663C00            o32 cmp al,0x0
00004B57  FFC3              inc bx
00004B59  99                cwd
00004B5A  BDBD99            mov bp,0x99bd
00004B5D  C3                ret
00004B5E  FF0F              dec word [bx]
00004B60  07                pop es
00004B61  0F                db 0x0f
00004B62  7DCC              jnl 0x4b30
00004B64  CC                int3
00004B65  CC                int3
00004B66  783C              js 0x4ba4
00004B68  6666663C18        o32 cmp al,0x18
00004B6D  7E18              jng 0x4b87
00004B6F  3F                aas
00004B70  333F              xor di,[bx]
00004B72  3030              xor [bx+si],dh
00004B74  70F0              jo 0x4b66
00004B76  E07F              loopne 0x4bf7
00004B78  637F63            arpl [bx+0x63],di
00004B7B  6367E6            arpl [bx-0x1a],sp
00004B7E  C0995A3CE7        rcr byte [bx+di+0x3c5a],0xe7
00004B83  E73C              out 0x3c,ax
00004B85  5A                pop dx
00004B86  99                cwd
00004B87  80E0F8            and al,0xf8
00004B8A  FE                db 0xfe
00004B8B  F8                clc
00004B8C  E080              loopne 0x4b0e
00004B8E  0002              add [bp+si],al
00004B90  0E                push cs
00004B91  3E                ss
00004B92  FE                db 0xfe
00004B93  3E0E              ds push cs
00004B95  0200              add al,[bx+si]
00004B97  183C              sbb [si],bh
00004B99  7E18              jng 0x4bb3
00004B9B  187E3C            sbb [bp+0x3c],bh
00004B9E  186666            sbb [bp+0x66],ah
00004BA1  666666006600      o32 add [bp+0x0],ah
00004BA7  7FDB              jg 0x4b84
00004BA9  DB7B1B            fstp tword [bp+di+0x1b]
00004BAC  1B1B              sbb bx,[bp+di]
00004BAE  003E6338          add [0x3863],bh
00004BB2  6C                insb
00004BB3  6C                insb
00004BB4  38CC              cmp ah,cl
00004BB6  7800              js 0x4bb8
00004BB8  0000              add [bx+si],al
00004BBA  007E7E            add [bp+0x7e],bh
00004BBD  7E00              jng 0x4bbf
00004BBF  183C              sbb [si],bh
00004BC1  7E18              jng 0x4bdb
00004BC3  7E3C              jng 0x4c01
00004BC5  18FF              sbb bh,bh
00004BC7  183C              sbb [si],bh
00004BC9  7E18              jng 0x4be3
00004BCB  1818              sbb [bx+si],bl
00004BCD  1800              sbb [bx+si],al
00004BCF  1818              sbb [bx+si],bl
00004BD1  1818              sbb [bx+si],bl
00004BD3  7E3C              jng 0x4c11
00004BD5  1800              sbb [bx+si],al
00004BD7  0018              add [bx+si],bl
00004BD9  0CFE              or al,0xfe
00004BDB  0C18              or al,0x18
00004BDD  0000              add [bx+si],al
00004BDF  0030              add [bx+si],dh
00004BE1  60                pushaw
00004BE2  FE                db 0xfe
00004BE3  60                pushaw
00004BE4  3000              xor [bx+si],al
00004BE6  0000              add [bx+si],al
00004BE8  00C0              add al,al
00004BEA  C0C0FE            rol al,0xfe
00004BED  0000              add [bx+si],al
00004BEF  0024              add [si],ah
00004BF1  66FF6624          jmp dword near [bp+0x24]
00004BF5  0000              add [bx+si],al
00004BF7  0018              add [bx+si],bl
00004BF9  3C7E              cmp al,0x7e
00004BFB  FF                db 0xff
00004BFC  FF00              inc word [bx+si]
00004BFE  0000              add [bx+si],al
00004C00  FF                db 0xff
00004C01  FF                db 0xff
00004C02  7E3C              jng 0x4c40
00004C04  1800              sbb [bx+si],al
00004C06  0000              add [bx+si],al
00004C08  0000              add [bx+si],al
00004C0A  0000              add [bx+si],al
00004C0C  0000              add [bx+si],al
00004C0E  0030              add [bx+si],dh
00004C10  7878              js 0x4c8a
00004C12  3030              xor [bx+si],dh
00004C14  0030              add [bx+si],dh
00004C16  006C6C            add [si+0x6c],ch
00004C19  6C                insb
00004C1A  0000              add [bx+si],al
00004C1C  0000              add [bx+si],al
00004C1E  006C6C            add [si+0x6c],ch
00004C21  FE                db 0xfe
00004C22  6C                insb
00004C23  FE                db 0xfe
00004C24  6C                insb
00004C25  6C                insb
00004C26  0030              add [bx+si],dh
00004C28  7CC0              jl 0x4bea
00004C2A  780C              js 0x4c38
00004C2C  F8                clc
00004C2D  3000              xor [bx+si],al
00004C2F  00C6              add dh,al
00004C31  CC                int3
00004C32  1830              sbb [bx+si],dh
00004C34  66C60038          o32 mov byte [bx+si],0x38
00004C38  6C                insb
00004C39  3876DC            cmp [bp-0x24],dh
00004C3C  CC                int3
00004C3D  7600              jna 0x4c3f
00004C3F  60                pushaw
00004C40  60                pushaw
00004C41  C00000            rol byte [bx+si],0x0
00004C44  0000              add [bx+si],al
00004C46  0018              add [bx+si],bl
00004C48  306060            xor [bx+si+0x60],ah
00004C4B  60                pushaw
00004C4C  3018              xor [bx+si],bl
00004C4E  006030            add [bx+si+0x30],ah
00004C51  1818              sbb [bx+si],bl
00004C53  1830              sbb [bx+si],dh
00004C55  60                pushaw
00004C56  0000              add [bx+si],al
00004C58  663CFF            o32 cmp al,0xff
00004C5B  3C66              cmp al,0x66
00004C5D  0000              add [bx+si],al
00004C5F  0030              add [bx+si],dh
00004C61  30FC              xor ah,bh
00004C63  3030              xor [bx+si],dh
00004C65  0000              add [bx+si],al
00004C67  0000              add [bx+si],al
00004C69  0000              add [bx+si],al
00004C6B  0030              add [bx+si],dh
00004C6D  306000            xor [bx+si+0x0],ah
00004C70  0000              add [bx+si],al
00004C72  FC                cld
00004C73  0000              add [bx+si],al
00004C75  0000              add [bx+si],al
00004C77  0000              add [bx+si],al
00004C79  0000              add [bx+si],al
00004C7B  0030              add [bx+si],dh
00004C7D  3000              xor [bx+si],al
00004C7F  06                push es
00004C80  0C18              or al,0x18
00004C82  3060C0            xor [bx+si-0x40],ah
00004C85  80007C            add byte [bx+si],0x7c
00004C88  C6                db 0xc6
00004C89  CE                into
00004C8A  DEF6              fdivrp st6
00004C8C  E67C              out 0x7c,al
00004C8E  0030              add [bx+si],dh
00004C90  7030              jo 0x4cc2
00004C92  3030              xor [bx+si],dh
00004C94  30FC              xor ah,bh
00004C96  0078CC            add [bx+si-0x34],bh
00004C99  0C38              or al,0x38
00004C9B  60                pushaw
00004C9C  CC                int3
00004C9D  FC                cld
00004C9E  0078CC            add [bx+si-0x34],bh
00004CA1  0C38              or al,0x38
00004CA3  0CCC              or al,0xcc
00004CA5  7800              js 0x4ca7
00004CA7  1C3C              sbb al,0x3c
00004CA9  6C                insb
00004CAA  CC                int3
00004CAB  FE0C              dec byte [si]
00004CAD  1E                push ds
00004CAE  00FC              add ah,bh
00004CB0  C0F80C            sar al,0xc
00004CB3  0CCC              or al,0xcc
00004CB5  7800              js 0x4cb7
00004CB7  3860C0            cmp [bx+si-0x40],ah
00004CBA  F8                clc
00004CBB  CC                int3
00004CBC  CC                int3
00004CBD  7800              js 0x4cbf
00004CBF  FC                cld
00004CC0  CC                int3
00004CC1  0C18              or al,0x18
00004CC3  3030              xor [bx+si],dh
00004CC5  3000              xor [bx+si],al
00004CC7  78CC              js 0x4c95
00004CC9  CC                int3
00004CCA  78CC              js 0x4c98
00004CCC  CC                int3
00004CCD  7800              js 0x4ccf
00004CCF  78CC              js 0x4c9d
00004CD1  CC                int3
00004CD2  7C0C              jl 0x4ce0
00004CD4  187000            sbb [bx+si+0x0],dh
00004CD7  0030              add [bx+si],dh
00004CD9  3000              xor [bx+si],al
00004CDB  0030              add [bx+si],dh
00004CDD  3000              xor [bx+si],al
00004CDF  0030              add [bx+si],dh
00004CE1  3000              xor [bx+si],al
00004CE3  0030              add [bx+si],dh
00004CE5  306018            xor [bx+si+0x18],ah
00004CE8  3060C0            xor [bx+si-0x40],ah
00004CEB  60                pushaw
00004CEC  3018              xor [bx+si],bl
00004CEE  0000              add [bx+si],al
00004CF0  00FC              add ah,bh
00004CF2  0000              add [bx+si],al
00004CF4  FC                cld
00004CF5  0000              add [bx+si],al
00004CF7  60                pushaw
00004CF8  3018              xor [bx+si],bl
00004CFA  0C18              or al,0x18
00004CFC  306000            xor [bx+si+0x0],ah
00004CFF  78CC              js 0x4ccd
00004D01  0C18              or al,0x18
00004D03  3000              xor [bx+si],al
00004D05  3000              xor [bx+si],al
00004D07  7CC6              jl 0x4ccf
00004D09  DE                db 0xde
00004D0A  DE                db 0xde
00004D0B  DEC0              faddp st0
00004D0D  7800              js 0x4d0f
00004D0F  3078CC            xor [bx+si-0x34],bh
00004D12  CC                int3
00004D13  FC                cld
00004D14  CC                int3
00004D15  CC                int3
00004D16  00FC              add ah,bh
00004D18  66667C66          o32 jl 0x4d82
00004D1C  66FC              o32 cld
00004D1E  003C              add [si],bh
00004D20  66C0C0C0          o32 rol al,0xc0
00004D24  663C00            o32 cmp al,0x0
00004D27  F8                clc
00004D28  6C                insb
00004D29  6666666C          o32 insb
00004D2D  F8                clc
00004D2E  00FE              add dh,bh
00004D30  626878            bound bp,[bx+si+0x78]
00004D33  6862FE            push word 0xfe62
00004D36  00FE              add dh,bh
00004D38  626878            bound bp,[bx+si+0x78]
00004D3B  6860F0            push word 0xf060
00004D3E  003C              add [si],bh
00004D40  66C0C0CE          o32 rol al,0xce
00004D44  663E00CC          ds o32 add ah,cl
00004D48  CC                int3
00004D49  CC                int3
00004D4A  FC                cld
00004D4B  CC                int3
00004D4C  CC                int3
00004D4D  CC                int3
00004D4E  007830            add [bx+si+0x30],bh
00004D51  3030              xor [bx+si],dh
00004D53  3030              xor [bx+si],dh
00004D55  7800              js 0x4d57
00004D57  1E                push ds
00004D58  0C0C              or al,0xc
00004D5A  0CCC              or al,0xcc
00004D5C  CC                int3
00004D5D  7800              js 0x4d5f
00004D5F  E666              out 0x66,al
00004D61  6C                insb
00004D62  786C              js 0x4dd0
00004D64  66E600            o32 out 0x0,al
00004D67  F060              lock pushaw
00004D69  60                pushaw
00004D6A  60                pushaw
00004D6B  6266FE            bound sp,[bp-0x2]
00004D6E  00C6              add dh,al
00004D70  EE                out dx,al
00004D71  FE                db 0xfe
00004D72  FE                db 0xfe
00004D73  D6                salc
00004D74  C6C600            mov dh,0x0
00004D77  C6                db 0xc6
00004D78  E6F6              out 0xf6,al
00004D7A  DECE              fmulp st6
00004D7C  C6C600            mov dh,0x0
00004D7F  386CC6            cmp [si-0x3a],ch
00004D82  C6C66C            mov dh,0x6c
00004D85  3800              cmp [bx+si],al
00004D87  FC                cld
00004D88  66667C60          o32 jl 0x4dec
00004D8C  60                pushaw
00004D8D  F00078CC          lock add [bx+si-0x34],bh
00004D91  CC                int3
00004D92  CC                int3
00004D93  DC781C            fdivr qword [bx+si+0x1c]
00004D96  00FC              add ah,bh
00004D98  66667C6C          o32 jl 0x4e08
00004D9C  66E600            o32 out 0x0,al
00004D9F  78CC              js 0x4d6d
00004DA1  E070              loopne 0x4e13
00004DA3  1CCC              sbb al,0xcc
00004DA5  7800              js 0x4da7
00004DA7  FC                cld
00004DA8  B430              mov ah,0x30
00004DAA  3030              xor [bx+si],dh
00004DAC  307800            xor [bx+si+0x0],bh
00004DAF  CC                int3
00004DB0  CC                int3
00004DB1  CC                int3
00004DB2  CC                int3
00004DB3  CC                int3
00004DB4  CC                int3
00004DB5  FC                cld
00004DB6  00CC              add ah,cl
00004DB8  CC                int3
00004DB9  CC                int3
00004DBA  CC                int3
00004DBB  CC                int3
00004DBC  7830              js 0x4dee
00004DBE  00C6              add dh,al
00004DC0  C6C6D6            mov dh,0xd6
00004DC3  FE                db 0xfe
00004DC4  EE                out dx,al
00004DC5  C600C6            mov byte [bx+si],0xc6
00004DC8  C6                db 0xc6
00004DC9  6C                insb
00004DCA  3838              cmp [bx+si],bh
00004DCC  6C                insb
00004DCD  C600CC            mov byte [bx+si],0xcc
00004DD0  CC                int3
00004DD1  CC                int3
00004DD2  7830              js 0x4e04
00004DD4  307800            xor [bx+si+0x0],bh
00004DD7  FEC6              inc dh
00004DD9  8C18              mov [bx+si],ds
00004DDB  3266FE            xor ah,[bp-0x2]
00004DDE  007860            add [bx+si+0x60],bh
00004DE1  60                pushaw
00004DE2  60                pushaw
00004DE3  60                pushaw
00004DE4  60                pushaw
00004DE5  7800              js 0x4de7
00004DE7  C0603018          shl byte [bx+si+0x30],0x18
00004DEB  0C06              or al,0x6
00004DED  0200              add al,[bx+si]
00004DEF  7818              js 0x4e09
00004DF1  1818              sbb [bx+si],bl
00004DF3  1818              sbb [bx+si],bl
00004DF5  7800              js 0x4df7
00004DF7  1038              adc [bx+si],bh
00004DF9  6C                insb
00004DFA  C60000            mov byte [bx+si],0x0
00004DFD  0000              add [bx+si],al
00004DFF  0000              add [bx+si],al
00004E01  0000              add [bx+si],al
00004E03  0000              add [bx+si],al
00004E05  00FF              add bh,bh
00004E07  3030              xor [bx+si],dh
00004E09  1800              sbb [bx+si],al
00004E0B  0000              add [bx+si],al
00004E0D  0000              add [bx+si],al
00004E0F  0000              add [bx+si],al
00004E11  780C              js 0x4e1f
00004E13  7CCC              jl 0x4de1
00004E15  7600              jna 0x4e17
00004E17  E060              loopne 0x4e79
00004E19  60                pushaw
00004E1A  7C66              jl 0x4e82
00004E1C  66DC00            o32 fadd qword [bx+si]
00004E1F  0000              add [bx+si],al
00004E21  78CC              js 0x4def
00004E23  C0CC78            ror ah,0x78
00004E26  001C              add [si],bl
00004E28  0C0C              or al,0xc
00004E2A  7CCC              jl 0x4df8
00004E2C  CC                int3
00004E2D  7600              jna 0x4e2f
00004E2F  0000              add [bx+si],al
00004E31  78CC              js 0x4dff
00004E33  FC                cld
00004E34  C0780038          sar byte [bx+si+0x0],0x38
00004E38  6C                insb
00004E39  60                pushaw
00004E3A  F060              lock pushaw
00004E3C  60                pushaw
00004E3D  F00000            lock add [bx+si],al
00004E40  0076CC            add [bp-0x34],dh
00004E43  CC                int3
00004E44  7C0C              jl 0x4e52
00004E46  F8                clc
00004E47  E060              loopne 0x4ea9
00004E49  6C                insb
00004E4A  7666              jna 0x4eb2
00004E4C  66E600            o32 out 0x0,al
00004E4F  3000              xor [bx+si],al
00004E51  7030              jo 0x4e83
00004E53  3030              xor [bx+si],dh
00004E55  7800              js 0x4e57
00004E57  0C00              or al,0x0
00004E59  0C0C              or al,0xc
00004E5B  0CCC              or al,0xcc
00004E5D  CC                int3
00004E5E  78E0              js 0x4e40
00004E60  60                pushaw
00004E61  666C              o32 insb
00004E63  786C              js 0x4ed1
00004E65  E600              out 0x0,al
00004E67  7030              jo 0x4e99
00004E69  3030              xor [bx+si],dh
00004E6B  3030              xor [bx+si],dh
00004E6D  7800              js 0x4e6f
00004E6F  0000              add [bx+si],al
00004E71  CC                int3
00004E72  FE                db 0xfe
00004E73  FE                db 0xfe
00004E74  D6                salc
00004E75  C60000            mov byte [bx+si],0x0
00004E78  00F8              add al,bh
00004E7A  CC                int3
00004E7B  CC                int3
00004E7C  CC                int3
00004E7D  CC                int3
00004E7E  0000              add [bx+si],al
00004E80  0078CC            add [bx+si-0x34],bh
00004E83  CC                int3
00004E84  CC                int3
00004E85  7800              js 0x4e87
00004E87  0000              add [bx+si],al
00004E89  DC6666            fsub qword [bp+0x66]
00004E8C  7C60              jl 0x4eee
00004E8E  F00000            lock add [bx+si],al
00004E91  76CC              jna 0x4e5f
00004E93  CC                int3
00004E94  7C0C              jl 0x4ea2
00004E96  1E                push ds
00004E97  0000              add [bx+si],al
00004E99  DC7666            fdiv qword [bp+0x66]
00004E9C  60                pushaw
00004E9D  F00000            lock add [bx+si],al
00004EA0  007CC0            add [si-0x40],bh
00004EA3  780C              js 0x4eb1
00004EA5  F8                clc
00004EA6  0010              add [bx+si],dl
00004EA8  307C30            xor [si+0x30],bh
00004EAB  3034              xor [si],dh
00004EAD  1800              sbb [bx+si],al
00004EAF  0000              add [bx+si],al
00004EB1  CC                int3
00004EB2  CC                int3
00004EB3  CC                int3
00004EB4  CC                int3
00004EB5  7600              jna 0x4eb7
00004EB7  0000              add [bx+si],al
00004EB9  CC                int3
00004EBA  CC                int3
00004EBB  CC                int3
00004EBC  7830              js 0x4eee
00004EBE  0000              add [bx+si],al
00004EC0  00C6              add dh,al
00004EC2  D6                salc
00004EC3  FE                db 0xfe
00004EC4  FE                db 0xfe
00004EC5  6C                insb
00004EC6  0000              add [bx+si],al
00004EC8  00C6              add dh,al
00004ECA  6C                insb
00004ECB  386CC6            cmp [si-0x3a],ch
00004ECE  0000              add [bx+si],al
00004ED0  00CC              add ah,cl
00004ED2  CC                int3
00004ED3  CC                int3
00004ED4  7C0C              jl 0x4ee2
00004ED6  F8                clc
00004ED7  0000              add [bx+si],al
00004ED9  FC                cld
00004EDA  98                cbw
00004EDB  3064FC            xor [si-0x4],ah
00004EDE  001C              add [si],bl
00004EE0  3030              xor [bx+si],dh
00004EE2  E030              loopne 0x4f14
00004EE4  301C              xor [si],bl
00004EE6  0018              add [bx+si],bl
00004EE8  1818              sbb [bx+si],bl
00004EEA  0018              add [bx+si],bl
00004EEC  1818              sbb [bx+si],bl
00004EEE  00E0              add al,ah
00004EF0  3030              xor [bx+si],dh
00004EF2  1C30              sbb al,0x30
00004EF4  30E0              xor al,ah
00004EF6  0076DC            add [bp-0x24],dh
00004EF9  0000              add [bx+si],al
00004EFB  0000              add [bx+si],al
00004EFD  0000              add [bx+si],al
00004EFF  0010              add [bx+si],dl
00004F01  386CC6            cmp [si-0x3a],ch
00004F04  C6                db 0xc6
00004F05  FE00              inc byte [bx+si]
00004F07  78CC              js 0x4ed5
00004F09  C0CC78            ror ah,0x78
00004F0C  180C              sbb [si],cl
00004F0E  7800              js 0x4f10
00004F10  CC                int3
00004F11  00CC              add ah,cl
00004F13  CC                int3
00004F14  CC                int3
00004F15  7E00              jng 0x4f17
00004F17  1C00              sbb al,0x0
00004F19  78CC              js 0x4ee7
00004F1B  FC                cld
00004F1C  C078007E          sar byte [bx+si+0x0],0x7e
00004F20  C3                ret
00004F21  3C06              cmp al,0x6
00004F23  3E663F            ds o32 aas
00004F26  00CC              add ah,cl
00004F28  00780C            add [bx+si+0xc],bh
00004F2B  7CCC              jl 0x4ef9
00004F2D  7E00              jng 0x4f2f
00004F2F  E000              loopne 0x4f31
00004F31  780C              js 0x4f3f
00004F33  7CCC              jl 0x4f01
00004F35  7E00              jng 0x4f37
00004F37  3030              xor [bx+si],dh
00004F39  780C              js 0x4f47
00004F3B  7CCC              jl 0x4f09
00004F3D  7E00              jng 0x4f3f
00004F3F  0000              add [bx+si],al
00004F41  78C0              js 0x4f03
00004F43  C0780C38          sar byte [bx+si+0xc],0x38
00004F47  7EC3              jng 0x4f0c
00004F49  3C66              cmp al,0x66
00004F4B  7E60              jng 0x4fad
00004F4D  3C00              cmp al,0x0
00004F4F  CC                int3
00004F50  0078CC            add [bx+si-0x34],bh
00004F53  FC                cld
00004F54  C07800E0          sar byte [bx+si+0x0],0xe0
00004F58  0078CC            add [bx+si-0x34],bh
00004F5B  FC                cld
00004F5C  C07800CC          sar byte [bx+si+0x0],0xcc
00004F60  007030            add [bx+si+0x30],dh
00004F63  3030              xor [bx+si],dh
00004F65  7800              js 0x4f67
00004F67  7CC6              jl 0x4f2f
00004F69  3818              cmp [bx+si],bl
00004F6B  1818              sbb [bx+si],bl
00004F6D  3C00              cmp al,0x0
00004F6F  E000              loopne 0x4f71
00004F71  7030              jo 0x4fa3
00004F73  3030              xor [bx+si],dh
00004F75  7800              js 0x4f77
00004F77  C6                db 0xc6
00004F78  386CC6            cmp [si-0x3a],ch
00004F7B  FEC6              inc dh
00004F7D  C60030            mov byte [bx+si],0x30
00004F80  3000              xor [bx+si],al
00004F82  78CC              js 0x4f50
00004F84  FC                cld
00004F85  CC                int3
00004F86  001C              add [si],bl
00004F88  00FC              add ah,bh
00004F8A  60                pushaw
00004F8B  7860              js 0x4fed
00004F8D  FC                cld
00004F8E  0000              add [bx+si],al
00004F90  007F0C            add [bx+0xc],bh
00004F93  7FCC              jg 0x4f61
00004F95  7F00              jg 0x4f97
00004F97  3E6C              ds insb
00004F99  CC                int3
00004F9A  FECC              dec ah
00004F9C  CC                int3
00004F9D  CE                into
00004F9E  0078CC            add [bx+si-0x34],bh
00004FA1  0078CC            add [bx+si-0x34],bh
00004FA4  CC                int3
00004FA5  7800              js 0x4fa7
00004FA7  00CC              add ah,cl
00004FA9  0078CC            add [bx+si-0x34],bh
00004FAC  CC                int3
00004FAD  7800              js 0x4faf
00004FAF  00E0              add al,ah
00004FB1  0078CC            add [bx+si-0x34],bh
00004FB4  CC                int3
00004FB5  7800              js 0x4fb7
00004FB7  78CC              js 0x4f85
00004FB9  00CC              add ah,cl
00004FBB  CC                int3
00004FBC  CC                int3
00004FBD  7E00              jng 0x4fbf
00004FBF  00E0              add al,ah
00004FC1  00CC              add ah,cl
00004FC3  CC                int3
00004FC4  CC                int3
00004FC5  7E00              jng 0x4fc7
00004FC7  00CC              add ah,cl
00004FC9  00CC              add ah,cl
00004FCB  CC                int3
00004FCC  7C0C              jl 0x4fda
00004FCE  F8                clc
00004FCF  C3                ret
00004FD0  183C              sbb [si],bh
00004FD2  66663C18          o32 cmp al,0x18
00004FD6  00CC              add ah,cl
00004FD8  00CC              add ah,cl
00004FDA  CC                int3
00004FDB  CC                int3
00004FDC  CC                int3
00004FDD  7800              js 0x4fdf
00004FDF  1818              sbb [bx+si],bl
00004FE1  7EC0              jng 0x4fa3
00004FE3  C07E1818          sar byte [bp+0x18],0x18
00004FE7  386C64            cmp [si+0x64],ch
00004FEA  F060              lock pushaw
00004FEC  E6FC              out 0xfc,al
00004FEE  00CC              add ah,cl
00004FF0  CC                int3
00004FF1  78FC              js 0x4fef
00004FF3  30FC              xor ah,bh
00004FF5  3030              xor [bx+si],dh
00004FF7  F8                clc
00004FF8  CC                int3
00004FF9  CC                int3
00004FFA  FA                cli
00004FFB  C6                db 0xc6
00004FFC  CF                iretw
00004FFD  C6C70E            mov bh,0xe
00005000  1B18              sbb bx,[bx+si]
00005002  3C18              cmp al,0x18
00005004  18D8              sbb al,bl
00005006  701C              jo 0x5024
00005008  00780C            add [bx+si+0xc],bh
0000500B  7CCC              jl 0x4fd9
0000500D  7E00              jng 0x500f
0000500F  3800              cmp [bx+si],al
00005011  7030              jo 0x5043
00005013  3030              xor [bx+si],dh
00005015  7800              js 0x5017
00005017  001C              add [si],bl
00005019  0078CC            add [bx+si-0x34],bh
0000501C  CC                int3
0000501D  7800              js 0x501f
0000501F  001C              add [si],bl
00005021  00CC              add ah,cl
00005023  CC                int3
00005024  CC                int3
00005025  7E00              jng 0x5027
00005027  00F8              add al,bh
00005029  00F8              add al,bh
0000502B  CC                int3
0000502C  CC                int3
0000502D  CC                int3
0000502E  00FC              add ah,bh
00005030  00CC              add ah,cl
00005032  EC                in al,dx
00005033  FC                cld
00005034  DCCC              fmul to st4
00005036  003C              add [si],bh
00005038  6C                insb
00005039  6C                insb
0000503A  3E007E00          add [ds:bp+0x0],bh
0000503E  0038              add [bx+si],bh
00005040  6C                insb
00005041  6C                insb
00005042  3800              cmp [bx+si],al
00005044  7C00              jl 0x5046
00005046  0030              add [bx+si],dh
00005048  0030              add [bx+si],dh
0000504A  60                pushaw
0000504B  C0CC78            ror ah,0x78
0000504E  0000              add [bx+si],al
00005050  0000              add [bx+si],al
00005052  FC                cld
00005053  C0C000            rol al,0x0
00005056  0000              add [bx+si],al
00005058  0000              add [bx+si],al
0000505A  FC                cld
0000505B  0C0C              or al,0xc
0000505D  0000              add [bx+si],al
0000505F  C3                ret
00005060  C6                db 0xc6
00005061  CC                int3
00005062  DE33              fidiv word [bp+di]
00005064  66CC              o32 int3
00005066  0F                db 0x0f
00005067  C3                ret
00005068  C6                db 0xc6
00005069  CC                int3
0000506A  DB                db 0xdb
0000506B  37                aaa
0000506C  6F                outsw
0000506D  CF                iretw
0000506E  0318              add bx,[bx+si]
00005070  1800              sbb [bx+si],al
00005072  1818              sbb [bx+si],bl
00005074  1818              sbb [bx+si],bl
00005076  0000              add [bx+si],al
00005078  3366CC            xor sp,[bp-0x34]
0000507B  663300            xor eax,[bx+si]
0000507E  0000              add [bx+si],al
00005080  CC                int3
00005081  663366CC          xor esp,[bp-0x34]
00005085  0000              add [bx+si],al
00005087  22882288          and cl,[bx+si-0x77de]
0000508B  22882288          and cl,[bx+si-0x77de]
0000508F  55                push bp
00005090  AA                stosb
00005091  55                push bp
00005092  AA                stosb
00005093  55                push bp
00005094  AA                stosb
00005095  55                push bp
00005096  AA                stosb
00005097  DB                db 0xdb
00005098  77DB              ja 0x5075
0000509A  EE                out dx,al
0000509B  DB                db 0xdb
0000509C  77DB              ja 0x5079
0000509E  EE                out dx,al
0000509F  1818              sbb [bx+si],bl
000050A1  1818              sbb [bx+si],bl
000050A3  1818              sbb [bx+si],bl
000050A5  1818              sbb [bx+si],bl
000050A7  1818              sbb [bx+si],bl
000050A9  1818              sbb [bx+si],bl
000050AB  F8                clc
000050AC  1818              sbb [bx+si],bl
000050AE  1818              sbb [bx+si],bl
000050B0  18F8              sbb al,bh
000050B2  18F8              sbb al,bh
000050B4  1818              sbb [bx+si],bl
000050B6  18363636          sbb [0x3636],dh
000050BA  36F6363636        div byte [ss:0x3636]
000050BF  0000              add [bx+si],al
000050C1  0000              add [bx+si],al
000050C3  FE                db 0xfe
000050C4  3636360000        add [ss:bx+si],al
000050C9  F8                clc
000050CA  18F8              sbb al,bh
000050CC  1818              sbb [bx+si],bl
000050CE  183636F6          sbb [0xf636],dh
000050D2  06                push es
000050D3  F6363636          div byte [0x3636]
000050D7  3636363636363636  add [ss:bx+si],al
         -0000
000050E1  FE06F636          inc byte [0x36f6]
000050E5  36363636F606FE00  test byte [ss:0xfe],0x0
         -00
000050EE  00363636          add [0x3636],dh
000050F2  36FE00            inc byte [ss:bx+si]
000050F5  0000              add [bx+si],al
000050F7  1818              sbb [bx+si],bl
000050F9  F8                clc
000050FA  18F8              sbb al,bh
000050FC  0000              add [bx+si],al
000050FE  0000              add [bx+si],al
00005100  0000              add [bx+si],al
00005102  00F8              add al,bh
00005104  1818              sbb [bx+si],bl
00005106  1818              sbb [bx+si],bl
00005108  1818              sbb [bx+si],bl
0000510A  181F              sbb [bx],bl
0000510C  0000              add [bx+si],al
0000510E  0018              add [bx+si],bl
00005110  1818              sbb [bx+si],bl
00005112  18FF              sbb bh,bh
00005114  0000              add [bx+si],al
00005116  0000              add [bx+si],al
00005118  0000              add [bx+si],al
0000511A  00FF              add bh,bh
0000511C  1818              sbb [bx+si],bl
0000511E  1818              sbb [bx+si],bl
00005120  1818              sbb [bx+si],bl
00005122  181F              sbb [bx],bl
00005124  1818              sbb [bx+si],bl
00005126  1800              sbb [bx+si],al
00005128  0000              add [bx+si],al
0000512A  00FF              add bh,bh
0000512C  0000              add [bx+si],al
0000512E  0018              add [bx+si],bl
00005130  1818              sbb [bx+si],bl
00005132  18FF              sbb bh,bh
00005134  1818              sbb [bx+si],bl
00005136  1818              sbb [bx+si],bl
00005138  181F              sbb [bx],bl
0000513A  181F              sbb [bx],bl
0000513C  1818              sbb [bx+si],bl
0000513E  18363636          sbb [0x3636],dh
00005142  3637              ss aaa
00005144  363636363637      ss aaa
0000514A  303F              xor [bx],bh
0000514C  0000              add [bx+si],al
0000514E  0000              add [bx+si],al
00005150  003F              add [bx],bh
00005152  3037              xor [bx],dh
00005154  3636363636F700FF  test word [ss:bx+si],0xff
         -00
0000515D  0000              add [bx+si],al
0000515F  0000              add [bx+si],al
00005161  FF00              inc word [bx+si]
00005163  F7363636          div word [0x3636]
00005167  363637            ss aaa
0000516A  3037              xor [bx],dh
0000516C  3636360000        add [ss:bx+si],al
00005171  FF00              inc word [bx+si]
00005173  FF00              inc word [bx+si]
00005175  0000              add [bx+si],al
00005177  3636F700F736      test word [ss:bx+si],0x36f7
0000517D  36361818          sbb [ss:bx+si],bl
00005181  FF00              inc word [bx+si]
00005183  FF00              inc word [bx+si]
00005185  0000              add [bx+si],al
00005187  36363636FF00      inc word [ss:bx+si]
0000518D  0000              add [bx+si],al
0000518F  0000              add [bx+si],al
00005191  FF00              inc word [bx+si]
00005193  FF18              call word far [bx+si]
00005195  1818              sbb [bx+si],bl
00005197  0000              add [bx+si],al
00005199  0000              add [bx+si],al
0000519B  FF363636          push word [0x3636]
0000519F  363636363F        ss aas
000051A4  0000              add [bx+si],al
000051A6  0018              add [bx+si],bl
000051A8  181F              sbb [bx],bl
000051AA  181F              sbb [bx],bl
000051AC  0000              add [bx+si],al
000051AE  0000              add [bx+si],al
000051B0  001F              add [bx],bl
000051B2  181F              sbb [bx],bl
000051B4  1818              sbb [bx+si],bl
000051B6  1800              sbb [bx+si],al
000051B8  0000              add [bx+si],al
000051BA  003F              add [bx],bh
000051BC  36363636363636FF  push word [ss:0x3636]
         -363636
000051C7  1818              sbb [bx+si],bl
000051C9  FF18              call word far [bx+si]
000051CB  FF18              call word far [bx+si]
000051CD  1818              sbb [bx+si],bl
000051CF  1818              sbb [bx+si],bl
000051D1  1818              sbb [bx+si],bl
000051D3  F8                clc
000051D4  0000              add [bx+si],al
000051D6  0000              add [bx+si],al
000051D8  0000              add [bx+si],al
000051DA  001F              add [bx],bl
000051DC  1818              sbb [bx+si],bl
000051DE  18FF              sbb bh,bh
000051E0  FF                db 0xff
000051E1  FF                db 0xff
000051E2  FF                db 0xff
000051E3  FF                db 0xff
000051E4  FF                db 0xff
000051E5  FF                db 0xff
000051E6  FF00              inc word [bx+si]
000051E8  0000              add [bx+si],al
000051EA  00FF              add bh,bh
000051EC  FF                db 0xff
000051ED  FF                db 0xff
000051EE  FFF0              push ax
000051F0  F0                lock
000051F1  F0                lock
000051F2  F0                lock
000051F3  F0                lock
000051F4  F0                lock
000051F5  F0                lock
000051F6  F0                lock
000051F7  0F                db 0x0f
000051F8  0F                db 0x0f
000051F9  0F                db 0x0f
000051FA  0F                db 0x0f
000051FB  0F                db 0x0f
000051FC  0F                db 0x0f
000051FD  0F                db 0x0f
000051FE  0FFF              ud0
00005200  FF                db 0xff
00005201  FF                db 0xff
00005202  FF00              inc word [bx+si]
00005204  0000              add [bx+si],al
00005206  0000              add [bx+si],al
00005208  0076DC            add [bp-0x24],dh
0000520B  C8DC7600          enter 0x76dc,0x0
0000520F  0078CC            add [bx+si-0x34],bh
00005212  F8                clc
00005213  CC                int3
00005214  F8                clc
00005215  C0C000            rol al,0x0
00005218  FC                cld
00005219  CC                int3
0000521A  C0C0C0            rol al,0xc0
0000521D  C00000            rol byte [bx+si],0x0
00005220  FE                db 0xfe
00005221  6C                insb
00005222  6C                insb
00005223  6C                insb
00005224  6C                insb
00005225  6C                insb
00005226  00FC              add ah,bh
00005228  CC                int3
00005229  60                pushaw
0000522A  3060CC            xor [bx+si-0x34],ah
0000522D  FC                cld
0000522E  0000              add [bx+si],al
00005230  007ED8            add [bp-0x28],bh
00005233  D8D8              fcomp st0
00005235  7000              jo 0x5237
00005237  006666            add [bp+0x66],ah
0000523A  66667C60          o32 jl 0x529e
0000523E  C00076            rol byte [bx+si],0x76
00005241  DC18              fcomp qword [bx+si]
00005243  1818              sbb [bx+si],bl
00005245  1800              sbb [bx+si],al
00005247  FC                cld
00005248  3078CC            xor [bx+si-0x34],bh
0000524B  CC                int3
0000524C  7830              js 0x527e
0000524E  FC                cld
0000524F  386CC6            cmp [si-0x3a],ch
00005252  FEC6              inc dh
00005254  6C                insb
00005255  3800              cmp [bx+si],al
00005257  386CC6            cmp [si-0x3a],ch
0000525A  C6                db 0xc6
0000525B  6C                insb
0000525C  6C                insb
0000525D  EE                out dx,al
0000525E  001C              add [si],bl
00005260  3018              xor [bx+si],bl
00005262  7CCC              jl 0x5230
00005264  CC                int3
00005265  7800              js 0x5267
00005267  0000              add [bx+si],al
00005269  7EDB              jng 0x5246
0000526B  DB7E00            fstp tword [bp+0x0]
0000526E  00060C7E          add [0x7e0c],al
00005272  DBDB              fcmovnu st3
00005274  7E60              jng 0x52d6
00005276  C03860            sar byte [bx+si],0x60
00005279  C0F8C0            sar al,0xc0
0000527C  60                pushaw
0000527D  3800              cmp [bx+si],al
0000527F  78CC              js 0x524d
00005281  CC                int3
00005282  CC                int3
00005283  CC                int3
00005284  CC                int3
00005285  CC                int3
00005286  0000              add [bx+si],al
00005288  FC                cld
00005289  00FC              add ah,bh
0000528B  00FC              add ah,bh
0000528D  0000              add [bx+si],al
0000528F  3030              xor [bx+si],dh
00005291  FC                cld
00005292  3030              xor [bx+si],dh
00005294  00FC              add ah,bh
00005296  006030            add [bx+si+0x30],ah
00005299  1830              sbb [bx+si],dh
0000529B  60                pushaw
0000529C  00FC              add ah,bh
0000529E  0018              add [bx+si],bl
000052A0  306030            xor [bx+si+0x30],ah
000052A3  1800              sbb [bx+si],al
000052A5  FC                cld
000052A6  000E1B1B          add [0x1b1b],cl
000052AA  1818              sbb [bx+si],bl
000052AC  1818              sbb [bx+si],bl
000052AE  1818              sbb [bx+si],bl
000052B0  1818              sbb [bx+si],bl
000052B2  1818              sbb [bx+si],bl
000052B4  D8D8              fcomp st0
000052B6  7030              jo 0x52e8
000052B8  3000              xor [bx+si],al
000052BA  FC                cld
000052BB  0030              add [bx+si],dh
000052BD  3000              xor [bx+si],al
000052BF  0076DC            add [bp-0x24],dh
000052C2  0076DC            add [bp-0x24],dh
000052C5  0000              add [bx+si],al
000052C7  386C6C            cmp [si+0x6c],ch
000052CA  3800              cmp [bx+si],al
000052CC  0000              add [bx+si],al
000052CE  0000              add [bx+si],al
000052D0  0000              add [bx+si],al
000052D2  1818              sbb [bx+si],bl
000052D4  0000              add [bx+si],al
000052D6  0000              add [bx+si],al
000052D8  0000              add [bx+si],al
000052DA  0018              add [bx+si],bl
000052DC  0000              add [bx+si],al
000052DE  000F              add [bx],cl
000052E0  0C0C              or al,0xc
000052E2  0CEC              or al,0xec
000052E4  6C                insb
000052E5  3C1C              cmp al,0x1c
000052E7  786C              js 0x5355
000052E9  6C                insb
000052EA  6C                insb
000052EB  6C                insb
000052EC  0000              add [bx+si],al
000052EE  007018            add [bx+si+0x18],dh
000052F1  306078            xor [bx+si+0x78],ah
000052F4  0000              add [bx+si],al
000052F6  0000              add [bx+si],al
000052F8  003C              add [si],bh
000052FA  3C3C              cmp al,0x3c
000052FC  3C00              cmp al,0x0
000052FE  0000              add [bx+si],al
00005300  0000              add [bx+si],al
00005302  0000              add [bx+si],al
00005304  0000              add [bx+si],al
00005306  0000              add [bx+si],al
00005308  0000              add [bx+si],al
0000530A  0000              add [bx+si],al
0000530C  0000              add [bx+si],al
0000530E  0000              add [bx+si],al
00005310  0000              add [bx+si],al
00005312  0000              add [bx+si],al
00005314  0000              add [bx+si],al
00005316  007E81            add [bp-0x7f],bh
00005319  A5                movsw
0000531A  8181BD99817E      add word [bx+di-0x6643],0x7e81
00005320  0000              add [bx+si],al
00005322  0000              add [bx+si],al
00005324  007EFF            add [bp-0x1],bh
00005327  DB                db 0xdb
00005328  FF                db 0xff
00005329  FFC3              inc bx
0000532B  E7FF              out 0xff,ax
0000532D  7E00              jng 0x532f
0000532F  0000              add [bx+si],al
00005331  0000              add [bx+si],al
00005333  006CFE            add [si-0x2],ch
00005336  FE                db 0xfe
00005337  FE                db 0xfe
00005338  FE                db 0xfe
00005339  7C38              jl 0x5373
0000533B  1000              adc [bx+si],al
0000533D  0000              add [bx+si],al
0000533F  0000              add [bx+si],al
00005341  0010              add [bx+si],dl
00005343  387CFE            cmp [si-0x2],bh
00005346  7C38              jl 0x5380
00005348  1000              adc [bx+si],al
0000534A  0000              add [bx+si],al
0000534C  0000              add [bx+si],al
0000534E  0018              add [bx+si],bl
00005350  3C3C              cmp al,0x3c
00005352  E7E7              out 0xe7,ax
00005354  E718              out 0x18,ax
00005356  183C              sbb [si],bh
00005358  0000              add [bx+si],al
0000535A  0000              add [bx+si],al
0000535C  0018              add [bx+si],bl
0000535E  3C7E              cmp al,0x7e
00005360  FF                db 0xff
00005361  FF                db 0xff
00005362  7E18              jng 0x537c
00005364  183C              sbb [si],bh
00005366  0000              add [bx+si],al
00005368  0000              add [bx+si],al
0000536A  0000              add [bx+si],al
0000536C  0000              add [bx+si],al
0000536E  183C              sbb [si],bh
00005370  3C18              cmp al,0x18
00005372  0000              add [bx+si],al
00005374  0000              add [bx+si],al
00005376  00FF              add bh,bh
00005378  FF                db 0xff
00005379  FF                db 0xff
0000537A  FF                db 0xff
0000537B  FFE7              jmp di
0000537D  C3                ret
0000537E  C3                ret
0000537F  E7FF              out 0xff,ax
00005381  FF                db 0xff
00005382  FF                db 0xff
00005383  FF                db 0xff
00005384  FF00              inc word [bx+si]
00005386  0000              add [bx+si],al
00005388  003C              add [si],bh
0000538A  6642              inc edx
0000538C  42                inc dx
0000538D  663C00            o32 cmp al,0x0
00005390  0000              add [bx+si],al
00005392  00FF              add bh,bh
00005394  FF                db 0xff
00005395  FF                db 0xff
00005396  FFC3              inc bx
00005398  99                cwd
00005399  BDBD99            mov bp,0x99bd
0000539C  C3                ret
0000539D  FF                db 0xff
0000539E  FF                db 0xff
0000539F  FF                db 0xff
000053A0  FF00              inc word [bx+si]
000053A2  001E0E1A          add [0x1a0e],bl
000053A6  3278CC            xor bh,[bx+si-0x34]
000053A9  CC                int3
000053AA  CC                int3
000053AB  7800              js 0x53ad
000053AD  0000              add [bx+si],al
000053AF  0000              add [bx+si],al
000053B1  3C66              cmp al,0x66
000053B3  66663C18          o32 cmp al,0x18
000053B7  7E18              jng 0x53d1
000053B9  1800              sbb [bx+si],al
000053BB  0000              add [bx+si],al
000053BD  0000              add [bx+si],al
000053BF  3F                aas
000053C0  333F              xor di,[bx]
000053C2  3030              xor [bx+si],dh
000053C4  3070F0            xor [bx+si-0x10],dh
000053C7  E000              loopne 0x53c9
000053C9  0000              add [bx+si],al
000053CB  0000              add [bx+si],al
000053CD  7F63              jg 0x5432
000053CF  7F63              jg 0x5434
000053D1  636367            arpl [bp+di+0x67],sp
000053D4  E7E6              out 0xe6,ax
000053D6  C00000            rol byte [bx+si],0x0
000053D9  0000              add [bx+si],al
000053DB  1818              sbb [bx+si],bl
000053DD  DB3C              fstp tword [si]
000053DF  E73C              out 0x3c,ax
000053E1  DB18              fistp dword [bx+si]
000053E3  1800              sbb [bx+si],al
000053E5  0000              add [bx+si],al
000053E7  0000              add [bx+si],al
000053E9  80C0E0            add al,0xe0
000053EC  F8                clc
000053ED  FE                db 0xfe
000053EE  F8                clc
000053EF  E0C0              loopne 0x53b1
000053F1  800000            add byte [bx+si],0x0
000053F4  0000              add [bx+si],al
000053F6  0002              add [bp+si],al
000053F8  06                push es
000053F9  0E                push cs
000053FA  3E                ss
000053FB  FE                db 0xfe
000053FC  3E0E              ds push cs
000053FE  06                push es
000053FF  0200              add al,[bx+si]
00005401  0000              add [bx+si],al
00005403  0000              add [bx+si],al
00005405  183C              sbb [si],bh
00005407  7E18              jng 0x5421
00005409  1818              sbb [bx+si],bl
0000540B  7E3C              jng 0x5449
0000540D  1800              sbb [bx+si],al
0000540F  0000              add [bx+si],al
00005411  0000              add [bx+si],al
00005413  6666666666660066  o32 add [bp+0x66],ah
         -66
0000541C  0000              add [bx+si],al
0000541E  0000              add [bx+si],al
00005420  007FDB            add [bx-0x25],bh
00005423  DBDB              fcmovnu st3
00005425  7B1B              jpo 0x5442
00005427  1B1B              sbb bx,[bp+di]
00005429  1B00              sbb ax,[bx+si]
0000542B  0000              add [bx+si],al
0000542D  007CC6            add [si-0x3a],bh
00005430  60                pushaw
00005431  386CC6            cmp [si-0x3a],ch
00005434  C6                db 0xc6
00005435  6C                insb
00005436  380C              cmp [si],cl
00005438  C6                db 0xc6
00005439  7C00              jl 0x543b
0000543B  0000              add [bx+si],al
0000543D  0000              add [bx+si],al
0000543F  0000              add [bx+si],al
00005441  0000              add [bx+si],al
00005443  FE                db 0xfe
00005444  FE                db 0xfe
00005445  FE00              inc byte [bx+si]
00005447  0000              add [bx+si],al
00005449  0000              add [bx+si],al
0000544B  183C              sbb [si],bh
0000544D  7E18              jng 0x5467
0000544F  1818              sbb [bx+si],bl
00005451  7E3C              jng 0x548f
00005453  187E00            sbb [bp+0x0],bh
00005456  0000              add [bx+si],al
00005458  0018              add [bx+si],bl
0000545A  3C7E              cmp al,0x7e
0000545C  1818              sbb [bx+si],bl
0000545E  1818              sbb [bx+si],bl
00005460  1818              sbb [bx+si],bl
00005462  0000              add [bx+si],al
00005464  0000              add [bx+si],al
00005466  0018              add [bx+si],bl
00005468  1818              sbb [bx+si],bl
0000546A  1818              sbb [bx+si],bl
0000546C  187E3C            sbb [bp+0x3c],bh
0000546F  1800              sbb [bx+si],al
00005471  0000              add [bx+si],al
00005473  0000              add [bx+si],al
00005475  0000              add [bx+si],al
00005477  180C              sbb [si],cl
00005479  FE0C              dec byte [si]
0000547B  1800              sbb [bx+si],al
0000547D  0000              add [bx+si],al
0000547F  0000              add [bx+si],al
00005481  0000              add [bx+si],al
00005483  0000              add [bx+si],al
00005485  3060FE            xor [bx+si-0x2],ah
00005488  60                pushaw
00005489  3000              xor [bx+si],al
0000548B  0000              add [bx+si],al
0000548D  0000              add [bx+si],al
0000548F  0000              add [bx+si],al
00005491  0000              add [bx+si],al
00005493  00C0              add al,al
00005495  C0C0FE            rol al,0xfe
00005498  0000              add [bx+si],al
0000549A  0000              add [bx+si],al
0000549C  0000              add [bx+si],al
0000549E  0000              add [bx+si],al
000054A0  0028              add [bx+si],ch
000054A2  6C                insb
000054A3  FE                db 0xfe
000054A4  6C                insb
000054A5  2800              sub [bx+si],al
000054A7  0000              add [bx+si],al
000054A9  0000              add [bx+si],al
000054AB  0000              add [bx+si],al
000054AD  0010              add [bx+si],dl
000054AF  3838              cmp [bx+si],bh
000054B1  7C7C              jl 0x552f
000054B3  FE                db 0xfe
000054B4  FE00              inc byte [bx+si]
000054B6  0000              add [bx+si],al
000054B8  0000              add [bx+si],al
000054BA  0000              add [bx+si],al
000054BC  FE                db 0xfe
000054BD  FE                db 0xfe
000054BE  7C7C              jl 0x553c
000054C0  3838              cmp [bx+si],bh
000054C2  1000              adc [bx+si],al
000054C4  0000              add [bx+si],al
000054C6  0000              add [bx+si],al
000054C8  0000              add [bx+si],al
000054CA  0000              add [bx+si],al
000054CC  0000              add [bx+si],al
000054CE  0000              add [bx+si],al
000054D0  0000              add [bx+si],al
000054D2  0000              add [bx+si],al
000054D4  0000              add [bx+si],al
000054D6  0018              add [bx+si],bl
000054D8  3C3C              cmp al,0x3c
000054DA  3C18              cmp al,0x18
000054DC  1800              sbb [bx+si],al
000054DE  1818              sbb [bx+si],bl
000054E0  0000              add [bx+si],al
000054E2  0000              add [bx+si],al
000054E4  6666662400        o32 and al,0x0
000054E9  0000              add [bx+si],al
000054EB  0000              add [bx+si],al
000054ED  0000              add [bx+si],al
000054EF  0000              add [bx+si],al
000054F1  0000              add [bx+si],al
000054F3  6C                insb
000054F4  6C                insb
000054F5  FE                db 0xfe
000054F6  6C                insb
000054F7  6C                insb
000054F8  6C                insb
000054F9  FE                db 0xfe
000054FA  6C                insb
000054FB  6C                insb
000054FC  0000              add [bx+si],al
000054FE  0018              add [bx+si],bl
00005500  187CC6            sbb [si-0x3a],bh
00005503  C2C07C            ret 0x7cc0
00005506  06                push es
00005507  86C6              xchg al,dh
00005509  7C18              jl 0x5523
0000550B  1800              sbb [bx+si],al
0000550D  0000              add [bx+si],al
0000550F  0000              add [bx+si],al
00005511  C2C60C            ret 0xcc6
00005514  1830              sbb [bx+si],dh
00005516  66C60000          o32 mov byte [bx+si],0x0
0000551A  0000              add [bx+si],al
0000551C  0038              add [bx+si],bh
0000551E  6C                insb
0000551F  6C                insb
00005520  3876DC            cmp [bp-0x24],dh
00005523  CC                int3
00005524  CC                int3
00005525  7600              jna 0x5527
00005527  0000              add [bx+si],al
00005529  0030              add [bx+si],dh
0000552B  3030              xor [bx+si],dh
0000552D  60                pushaw
0000552E  0000              add [bx+si],al
00005530  0000              add [bx+si],al
00005532  0000              add [bx+si],al
00005534  0000              add [bx+si],al
00005536  0000              add [bx+si],al
00005538  000C              add [si],cl
0000553A  1830              sbb [bx+si],dh
0000553C  3030              xor [bx+si],dh
0000553E  3030              xor [bx+si],dh
00005540  180C              sbb [si],cl
00005542  0000              add [bx+si],al
00005544  0000              add [bx+si],al
00005546  0030              add [bx+si],dh
00005548  180C              sbb [si],cl
0000554A  0C0C              or al,0xc
0000554C  0C0C              or al,0xc
0000554E  1830              sbb [bx+si],dh
00005550  0000              add [bx+si],al
00005552  0000              add [bx+si],al
00005554  0000              add [bx+si],al
00005556  00663C            add [bp+0x3c],ah
00005559  FF                db 0xff
0000555A  3C66              cmp al,0x66
0000555C  0000              add [bx+si],al
0000555E  0000              add [bx+si],al
00005560  0000              add [bx+si],al
00005562  0000              add [bx+si],al
00005564  0018              add [bx+si],bl
00005566  187E18            sbb [bp+0x18],bh
00005569  1800              sbb [bx+si],al
0000556B  0000              add [bx+si],al
0000556D  0000              add [bx+si],al
0000556F  0000              add [bx+si],al
00005571  0000              add [bx+si],al
00005573  0000              add [bx+si],al
00005575  0000              add [bx+si],al
00005577  1818              sbb [bx+si],bl
00005579  1830              sbb [bx+si],dh
0000557B  0000              add [bx+si],al
0000557D  0000              add [bx+si],al
0000557F  0000              add [bx+si],al
00005581  0000              add [bx+si],al
00005583  FE00              inc byte [bx+si]
00005585  0000              add [bx+si],al
00005587  0000              add [bx+si],al
00005589  0000              add [bx+si],al
0000558B  0000              add [bx+si],al
0000558D  0000              add [bx+si],al
0000558F  0000              add [bx+si],al
00005591  0000              add [bx+si],al
00005593  0018              add [bx+si],bl
00005595  1800              sbb [bx+si],al
00005597  0000              add [bx+si],al
00005599  0000              add [bx+si],al
0000559B  02060C18          add al,[0x180c]
0000559F  3060C0            xor [bx+si-0x40],ah
000055A2  800000            add byte [bx+si],0x0
000055A5  0000              add [bx+si],al
000055A7  0000              add [bx+si],al
000055A9  7CC6              jl 0x5571
000055AB  CE                into
000055AC  DEF6              fdivrp st6
000055AE  E6C6              out 0xc6,al
000055B0  C6                db 0xc6
000055B1  7C00              jl 0x55b3
000055B3  0000              add [bx+si],al
000055B5  0000              add [bx+si],al
000055B7  1838              sbb [bx+si],bh
000055B9  7818              js 0x55d3
000055BB  1818              sbb [bx+si],bl
000055BD  1818              sbb [bx+si],bl
000055BF  7E00              jng 0x55c1
000055C1  0000              add [bx+si],al
000055C3  0000              add [bx+si],al
000055C5  7CC6              jl 0x558d
000055C7  06                push es
000055C8  0C18              or al,0x18
000055CA  3060C6            xor [bx+si-0x3a],ah
000055CD  FE00              inc byte [bx+si]
000055CF  0000              add [bx+si],al
000055D1  0000              add [bx+si],al
000055D3  7CC6              jl 0x559b
000055D5  06                push es
000055D6  06                push es
000055D7  3C06              cmp al,0x6
000055D9  06                push es
000055DA  C6                db 0xc6
000055DB  7C00              jl 0x55dd
000055DD  0000              add [bx+si],al
000055DF  0000              add [bx+si],al
000055E1  0C1C              or al,0x1c
000055E3  3C6C              cmp al,0x6c
000055E5  CC                int3
000055E6  FE0C              dec byte [si]
000055E8  0C1E              or al,0x1e
000055EA  0000              add [bx+si],al
000055EC  0000              add [bx+si],al
000055EE  00FE              add dh,bh
000055F0  C0C0C0            rol al,0xc0
000055F3  FC                cld
000055F4  06                push es
000055F5  06                push es
000055F6  C6                db 0xc6
000055F7  7C00              jl 0x55f9
000055F9  0000              add [bx+si],al
000055FB  0000              add [bx+si],al
000055FD  3860C0            cmp [bx+si-0x40],ah
00005600  C0FCC6            sar ah,0xc6
00005603  C6C67C            mov dh,0x7c
00005606  0000              add [bx+si],al
00005608  0000              add [bx+si],al
0000560A  00FE              add dh,bh
0000560C  C6060C1830        mov byte [0x180c],0x30
00005611  3030              xor [bx+si],dh
00005613  3000              xor [bx+si],al
00005615  0000              add [bx+si],al
00005617  0000              add [bx+si],al
00005619  7CC6              jl 0x55e1
0000561B  C6C67C            mov dh,0x7c
0000561E  C6C6C6            mov dh,0xc6
00005621  7C00              jl 0x5623
00005623  0000              add [bx+si],al
00005625  0000              add [bx+si],al
00005627  7CC6              jl 0x55ef
00005629  C6C67E            mov dh,0x7e
0000562C  06                push es
0000562D  06                push es
0000562E  0C78              or al,0x78
00005630  0000              add [bx+si],al
00005632  0000              add [bx+si],al
00005634  0000              add [bx+si],al
00005636  1818              sbb [bx+si],bl
00005638  0000              add [bx+si],al
0000563A  0018              add [bx+si],bl
0000563C  1800              sbb [bx+si],al
0000563E  0000              add [bx+si],al
00005640  0000              add [bx+si],al
00005642  0000              add [bx+si],al
00005644  1818              sbb [bx+si],bl
00005646  0000              add [bx+si],al
00005648  0018              add [bx+si],bl
0000564A  1830              sbb [bx+si],dh
0000564C  0000              add [bx+si],al
0000564E  0000              add [bx+si],al
00005650  00060C18          add [0x180c],al
00005654  306030            xor [bx+si+0x30],ah
00005657  180C              sbb [si],cl
00005659  06                push es
0000565A  0000              add [bx+si],al
0000565C  0000              add [bx+si],al
0000565E  0000              add [bx+si],al
00005660  0000              add [bx+si],al
00005662  7E00              jng 0x5664
00005664  007E00            add [bp+0x0],bh
00005667  0000              add [bx+si],al
00005669  0000              add [bx+si],al
0000566B  0000              add [bx+si],al
0000566D  60                pushaw
0000566E  3018              xor [bx+si],bl
00005670  0C06              or al,0x6
00005672  0C18              or al,0x18
00005674  306000            xor [bx+si+0x0],ah
00005677  0000              add [bx+si],al
00005679  0000              add [bx+si],al
0000567B  7CC6              jl 0x5643
0000567D  C6                db 0xc6
0000567E  0C18              or al,0x18
00005680  1800              sbb [bx+si],al
00005682  1818              sbb [bx+si],bl
00005684  0000              add [bx+si],al
00005686  0000              add [bx+si],al
00005688  007CC6            add [si-0x3a],bh
0000568B  C6                db 0xc6
0000568C  DE                db 0xde
0000568D  DE                db 0xde
0000568E  DE                db 0xde
0000568F  DCC0              fadd to st0
00005691  7C00              jl 0x5693
00005693  0000              add [bx+si],al
00005695  0000              add [bx+si],al
00005697  1038              adc [bx+si],bh
00005699  6C                insb
0000569A  C6C6FE            mov dh,0xfe
0000569D  C6C6C6            mov dh,0xc6
000056A0  0000              add [bx+si],al
000056A2  0000              add [bx+si],al
000056A4  00FC              add ah,bh
000056A6  6666667C66        o32 jl 0x5711
000056AB  6666FC            o32 cld
000056AE  0000              add [bx+si],al
000056B0  0000              add [bx+si],al
000056B2  003C              add [si],bh
000056B4  66C2C0C0          o32 ret 0xc0c0
000056B8  C0C266            rol dl,0x66
000056BB  3C00              cmp al,0x0
000056BD  0000              add [bx+si],al
000056BF  0000              add [bx+si],al
000056C1  F8                clc
000056C2  6C                insb
000056C3  66666666666C      o32 insb
000056C9  F8                clc
000056CA  0000              add [bx+si],al
000056CC  0000              add [bx+si],al
000056CE  00FE              add dh,bh
000056D0  66626878          bound ebp,[bx+si+0x78]
000056D4  686266            push word 0x6662
000056D7  FE00              inc byte [bx+si]
000056D9  0000              add [bx+si],al
000056DB  0000              add [bx+si],al
000056DD  FE                db 0xfe
000056DE  66626878          bound ebp,[bx+si+0x78]
000056E2  686060            push word 0x6060
000056E5  F00000            lock add [bx+si],al
000056E8  0000              add [bx+si],al
000056EA  003C              add [si],bh
000056EC  66C2C0C0          o32 ret 0xc0c0
000056F0  DEC6              faddp st6
000056F2  663A00            o32 cmp al,[bx+si]
000056F5  0000              add [bx+si],al
000056F7  0000              add [bx+si],al
000056F9  C6C6C6            mov dh,0xc6
000056FC  C6                db 0xc6
000056FD  FEC6              inc dh
000056FF  C6C6C6            mov dh,0xc6
00005702  0000              add [bx+si],al
00005704  0000              add [bx+si],al
00005706  003C              add [si],bh
00005708  1818              sbb [bx+si],bl
0000570A  1818              sbb [bx+si],bl
0000570C  1818              sbb [bx+si],bl
0000570E  183C              sbb [si],bh
00005710  0000              add [bx+si],al
00005712  0000              add [bx+si],al
00005714  001E0C0C          add [0xc0c],bl
00005718  0C0C              or al,0xc
0000571A  0CCC              or al,0xcc
0000571C  CC                int3
0000571D  7800              js 0x571f
0000571F  0000              add [bx+si],al
00005721  0000              add [bx+si],al
00005723  E666              out 0x66,al
00005725  6C                insb
00005726  6C                insb
00005727  786C              js 0x5795
00005729  6C                insb
0000572A  66E600            o32 out 0x0,al
0000572D  0000              add [bx+si],al
0000572F  0000              add [bx+si],al
00005731  F060              lock pushaw
00005733  60                pushaw
00005734  60                pushaw
00005735  60                pushaw
00005736  60                pushaw
00005737  6266FE            bound sp,[bp-0x2]
0000573A  0000              add [bx+si],al
0000573C  0000              add [bx+si],al
0000573E  00C6              add dh,al
00005740  EE                out dx,al
00005741  FE                db 0xfe
00005742  FE                db 0xfe
00005743  D6                salc
00005744  C6C6C6            mov dh,0xc6
00005747  C60000            mov byte [bx+si],0x0
0000574A  0000              add [bx+si],al
0000574C  00C6              add dh,al
0000574E  E6F6              out 0xf6,al
00005750  FE                db 0xfe
00005751  DECE              fmulp st6
00005753  C6C6C6            mov dh,0xc6
00005756  0000              add [bx+si],al
00005758  0000              add [bx+si],al
0000575A  0038              add [bx+si],bh
0000575C  6C                insb
0000575D  C6C6C6            mov dh,0xc6
00005760  C6C66C            mov dh,0x6c
00005763  3800              cmp [bx+si],al
00005765  0000              add [bx+si],al
00005767  0000              add [bx+si],al
00005769  FC                cld
0000576A  6666667C60        o32 jl 0x57cf
0000576F  60                pushaw
00005770  60                pushaw
00005771  F00000            lock add [bx+si],al
00005774  0000              add [bx+si],al
00005776  007CC6            add [si-0x3a],bh
00005779  C6C6C6            mov dh,0xc6
0000577C  D6                salc
0000577D  DE7C0C            fidivr word [si+0xc]
00005780  0E                push cs
00005781  0000              add [bx+si],al
00005783  0000              add [bx+si],al
00005785  FC                cld
00005786  6666667C6C        o32 jl 0x57f7
0000578B  6666E600          o32 out 0x0,al
0000578F  0000              add [bx+si],al
00005791  0000              add [bx+si],al
00005793  7CC6              jl 0x575b
00005795  C6                db 0xc6
00005796  60                pushaw
00005797  380C              cmp [si],cl
00005799  C6C67C            mov dh,0x7c
0000579C  0000              add [bx+si],al
0000579E  0000              add [bx+si],al
000057A0  007E7E            add [bp+0x7e],bh
000057A3  5A                pop dx
000057A4  1818              sbb [bx+si],bl
000057A6  1818              sbb [bx+si],bl
000057A8  183C              sbb [si],bh
000057AA  0000              add [bx+si],al
000057AC  0000              add [bx+si],al
000057AE  00C6              add dh,al
000057B0  C6C6C6            mov dh,0xc6
000057B3  C6C6C6            mov dh,0xc6
000057B6  C6                db 0xc6
000057B7  7C00              jl 0x57b9
000057B9  0000              add [bx+si],al
000057BB  0000              add [bx+si],al
000057BD  C6C6C6            mov dh,0xc6
000057C0  C6C6C6            mov dh,0xc6
000057C3  6C                insb
000057C4  3810              cmp [bx+si],dl
000057C6  0000              add [bx+si],al
000057C8  0000              add [bx+si],al
000057CA  00C6              add dh,al
000057CC  C6C6C6            mov dh,0xc6
000057CF  D6                salc
000057D0  D6                salc
000057D1  FE                db 0xfe
000057D2  7C6C              jl 0x5840
000057D4  0000              add [bx+si],al
000057D6  0000              add [bx+si],al
000057D8  00C6              add dh,al
000057DA  C6                db 0xc6
000057DB  6C                insb
000057DC  3838              cmp [bx+si],bh
000057DE  386CC6            cmp [si-0x3a],ch
000057E1  C60000            mov byte [bx+si],0x0
000057E4  0000              add [bx+si],al
000057E6  006666            add [bp+0x66],ah
000057E9  66663C18          o32 cmp al,0x18
000057ED  1818              sbb [bx+si],bl
000057EF  3C00              cmp al,0x0
000057F1  0000              add [bx+si],al
000057F3  0000              add [bx+si],al
000057F5  FEC6              inc dh
000057F7  8C18              mov [bx+si],ds
000057F9  3060C2            xor [bx+si-0x3e],ah
000057FC  C6                db 0xc6
000057FD  FE00              inc byte [bx+si]
000057FF  0000              add [bx+si],al
00005801  0000              add [bx+si],al
00005803  3C30              cmp al,0x30
00005805  3030              xor [bx+si],dh
00005807  3030              xor [bx+si],dh
00005809  3030              xor [bx+si],dh
0000580B  3C00              cmp al,0x0
0000580D  0000              add [bx+si],al
0000580F  0000              add [bx+si],al
00005811  80C0E0            add al,0xe0
00005814  7038              jo 0x584e
00005816  1C0E              sbb al,0xe
00005818  06                push es
00005819  0200              add al,[bx+si]
0000581B  0000              add [bx+si],al
0000581D  0000              add [bx+si],al
0000581F  3C0C              cmp al,0xc
00005821  0C0C              or al,0xc
00005823  0C0C              or al,0xc
00005825  0C0C              or al,0xc
00005827  3C00              cmp al,0x0
00005829  0000              add [bx+si],al
0000582B  1038              adc [bx+si],bh
0000582D  6C                insb
0000582E  C60000            mov byte [bx+si],0x0
00005831  0000              add [bx+si],al
00005833  0000              add [bx+si],al
00005835  0000              add [bx+si],al
00005837  0000              add [bx+si],al
00005839  0000              add [bx+si],al
0000583B  0000              add [bx+si],al
0000583D  0000              add [bx+si],al
0000583F  0000              add [bx+si],al
00005841  0000              add [bx+si],al
00005843  0000              add [bx+si],al
00005845  FF00              inc word [bx+si]
00005847  3030              xor [bx+si],dh
00005849  1800              sbb [bx+si],al
0000584B  0000              add [bx+si],al
0000584D  0000              add [bx+si],al
0000584F  0000              add [bx+si],al
00005851  0000              add [bx+si],al
00005853  0000              add [bx+si],al
00005855  0000              add [bx+si],al
00005857  0000              add [bx+si],al
00005859  00780C            add [bx+si+0xc],bh
0000585C  7CCC              jl 0x582a
0000585E  CC                int3
0000585F  7600              jna 0x5861
00005861  0000              add [bx+si],al
00005863  0000              add [bx+si],al
00005865  E060              loopne 0x58c7
00005867  60                pushaw
00005868  786C              js 0x58d6
0000586A  6666667C00        o32 jl 0x586f
0000586F  0000              add [bx+si],al
00005871  0000              add [bx+si],al
00005873  0000              add [bx+si],al
00005875  007CC6            add [si-0x3a],bh
00005878  C0C0C6            rol al,0xc6
0000587B  7C00              jl 0x587d
0000587D  0000              add [bx+si],al
0000587F  0000              add [bx+si],al
00005881  1C0C              sbb al,0xc
00005883  0C3C              or al,0x3c
00005885  6C                insb
00005886  CC                int3
00005887  CC                int3
00005888  CC                int3
00005889  7600              jna 0x588b
0000588B  0000              add [bx+si],al
0000588D  0000              add [bx+si],al
0000588F  0000              add [bx+si],al
00005891  007CC6            add [si-0x3a],bh
00005894  FEC0              inc al
00005896  C6                db 0xc6
00005897  7C00              jl 0x5899
00005899  0000              add [bx+si],al
0000589B  0000              add [bx+si],al
0000589D  386C64            cmp [si+0x64],ch
000058A0  60                pushaw
000058A1  F060              lock pushaw
000058A3  60                pushaw
000058A4  60                pushaw
000058A5  F00000            lock add [bx+si],al
000058A8  0000              add [bx+si],al
000058AA  0000              add [bx+si],al
000058AC  0000              add [bx+si],al
000058AE  76CC              jna 0x587c
000058B0  CC                int3
000058B1  CC                int3
000058B2  7C0C              jl 0x58c0
000058B4  CC                int3
000058B5  7800              js 0x58b7
000058B7  0000              add [bx+si],al
000058B9  E060              loopne 0x591b
000058BB  60                pushaw
000058BC  6C                insb
000058BD  7666              jna 0x5925
000058BF  6666E600          o32 out 0x0,al
000058C3  0000              add [bx+si],al
000058C5  0000              add [bx+si],al
000058C7  1818              sbb [bx+si],bl
000058C9  0038              add [bx+si],bh
000058CB  1818              sbb [bx+si],bl
000058CD  1818              sbb [bx+si],bl
000058CF  3C00              cmp al,0x0
000058D1  0000              add [bx+si],al
000058D3  0000              add [bx+si],al
000058D5  06                push es
000058D6  06                push es
000058D7  000E0606          add [0x606],cl
000058DB  06                push es
000058DC  06                push es
000058DD  66663C00          o32 cmp al,0x0
000058E1  0000              add [bx+si],al
000058E3  E060              loopne 0x5945
000058E5  60                pushaw
000058E6  666C              o32 insb
000058E8  786C              js 0x5956
000058EA  66E600            o32 out 0x0,al
000058ED  0000              add [bx+si],al
000058EF  0000              add [bx+si],al
000058F1  3818              cmp [bx+si],bl
000058F3  1818              sbb [bx+si],bl
000058F5  1818              sbb [bx+si],bl
000058F7  1818              sbb [bx+si],bl
000058F9  3C00              cmp al,0x0
000058FB  0000              add [bx+si],al
000058FD  0000              add [bx+si],al
000058FF  0000              add [bx+si],al
00005901  00EC              add ah,ch
00005903  FE                db 0xfe
00005904  D6                salc
00005905  D6                salc
00005906  D6                salc
00005907  C60000            mov byte [bx+si],0x0
0000590A  0000              add [bx+si],al
0000590C  0000              add [bx+si],al
0000590E  0000              add [bx+si],al
00005910  DC6666            fsub qword [bp+0x66]
00005913  6666660000        o32 add [bx+si],al
00005918  0000              add [bx+si],al
0000591A  0000              add [bx+si],al
0000591C  0000              add [bx+si],al
0000591E  7CC6              jl 0x58e6
00005920  C6C6C6            mov dh,0xc6
00005923  7C00              jl 0x5925
00005925  0000              add [bx+si],al
00005927  0000              add [bx+si],al
00005929  0000              add [bx+si],al
0000592B  00DC              add ah,bl
0000592D  6666667C60        o32 jl 0x5992
00005932  60                pushaw
00005933  F00000            lock add [bx+si],al
00005936  0000              add [bx+si],al
00005938  0000              add [bx+si],al
0000593A  76CC              jna 0x5908
0000593C  CC                int3
0000593D  CC                int3
0000593E  7C0C              jl 0x594c
00005940  0C1E              or al,0x1e
00005942  0000              add [bx+si],al
00005944  0000              add [bx+si],al
00005946  0000              add [bx+si],al
00005948  DC7666            fdiv qword [bp+0x66]
0000594B  60                pushaw
0000594C  60                pushaw
0000594D  F00000            lock add [bx+si],al
00005950  0000              add [bx+si],al
00005952  0000              add [bx+si],al
00005954  0000              add [bx+si],al
00005956  7CC6              jl 0x591e
00005958  701C              jo 0x5976
0000595A  C6                db 0xc6
0000595B  7C00              jl 0x595d
0000595D  0000              add [bx+si],al
0000595F  0000              add [bx+si],al
00005961  1030              adc [bx+si],dh
00005963  30FC              xor ah,bh
00005965  3030              xor [bx+si],dh
00005967  30361C00          xor [0x1c],dh
0000596B  0000              add [bx+si],al
0000596D  0000              add [bx+si],al
0000596F  0000              add [bx+si],al
00005971  00CC              add ah,cl
00005973  CC                int3
00005974  CC                int3
00005975  CC                int3
00005976  CC                int3
00005977  7600              jna 0x5979
00005979  0000              add [bx+si],al
0000597B  0000              add [bx+si],al
0000597D  0000              add [bx+si],al
0000597F  006666            add [bp+0x66],ah
00005982  66663C18          o32 cmp al,0x18
00005986  0000              add [bx+si],al
00005988  0000              add [bx+si],al
0000598A  0000              add [bx+si],al
0000598C  0000              add [bx+si],al
0000598E  C6C6D6            mov dh,0xd6
00005991  D6                salc
00005992  FE                db 0xfe
00005993  6C                insb
00005994  0000              add [bx+si],al
00005996  0000              add [bx+si],al
00005998  0000              add [bx+si],al
0000599A  0000              add [bx+si],al
0000599C  C6                db 0xc6
0000599D  6C                insb
0000599E  3838              cmp [bx+si],bh
000059A0  6C                insb
000059A1  C60000            mov byte [bx+si],0x0
000059A4  0000              add [bx+si],al
000059A6  0000              add [bx+si],al
000059A8  0000              add [bx+si],al
000059AA  C6C6C6            mov dh,0xc6
000059AD  C6                db 0xc6
000059AE  7E06              jng 0x59b6
000059B0  0CF8              or al,0xf8
000059B2  0000              add [bx+si],al
000059B4  0000              add [bx+si],al
000059B6  0000              add [bx+si],al
000059B8  FECC              dec ah
000059BA  1830              sbb [bx+si],dh
000059BC  66FE00            o32 inc byte [bx+si]
000059BF  0000              add [bx+si],al
000059C1  0000              add [bx+si],al
000059C3  0E                push cs
000059C4  1818              sbb [bx+si],bl
000059C6  187018            sbb [bx+si+0x18],dh
000059C9  1818              sbb [bx+si],bl
000059CB  0E                push cs
000059CC  0000              add [bx+si],al
000059CE  0000              add [bx+si],al
000059D0  0018              add [bx+si],bl
000059D2  1818              sbb [bx+si],bl
000059D4  1800              sbb [bx+si],al
000059D6  1818              sbb [bx+si],bl
000059D8  1818              sbb [bx+si],bl
000059DA  0000              add [bx+si],al
000059DC  0000              add [bx+si],al
000059DE  007018            add [bx+si+0x18],dh
000059E1  1818              sbb [bx+si],bl
000059E3  0E                push cs
000059E4  1818              sbb [bx+si],bl
000059E6  187000            sbb [bx+si+0x0],dh
000059E9  0000              add [bx+si],al
000059EB  0000              add [bx+si],al
000059ED  76DC              jna 0x59cb
000059EF  0000              add [bx+si],al
000059F1  0000              add [bx+si],al
000059F3  0000              add [bx+si],al
000059F5  0000              add [bx+si],al
000059F7  0000              add [bx+si],al
000059F9  0000              add [bx+si],al
000059FB  0000              add [bx+si],al
000059FD  1038              adc [bx+si],bh
000059FF  6C                insb
00005A00  C6C6FE            mov dh,0xfe
00005A03  0000              add [bx+si],al
00005A05  0000              add [bx+si],al
00005A07  0000              add [bx+si],al
00005A09  3C66              cmp al,0x66
00005A0B  C2C0C0            ret 0xc0c0
00005A0E  C2663C            ret 0x3c66
00005A11  0C06              or al,0x6
00005A13  7C00              jl 0x5a15
00005A15  0000              add [bx+si],al
00005A17  CC                int3
00005A18  CC                int3
00005A19  00CC              add ah,cl
00005A1B  CC                int3
00005A1C  CC                int3
00005A1D  CC                int3
00005A1E  CC                int3
00005A1F  7600              jna 0x5a21
00005A21  0000              add [bx+si],al
00005A23  000C              add [si],cl
00005A25  1830              sbb [bx+si],dh
00005A27  007CC6            add [si-0x3a],bh
00005A2A  FEC0              inc al
00005A2C  C6                db 0xc6
00005A2D  7C00              jl 0x5a2f
00005A2F  0000              add [bx+si],al
00005A31  0010              add [bx+si],dl
00005A33  386C00            cmp [si+0x0],ch
00005A36  780C              js 0x5a44
00005A38  7CCC              jl 0x5a06
00005A3A  CC                int3
00005A3B  7600              jna 0x5a3d
00005A3D  0000              add [bx+si],al
00005A3F  0000              add [bx+si],al
00005A41  CC                int3
00005A42  CC                int3
00005A43  00780C            add [bx+si+0xc],bh
00005A46  7CCC              jl 0x5a14
00005A48  CC                int3
00005A49  7600              jna 0x5a4b
00005A4B  0000              add [bx+si],al
00005A4D  006030            add [bx+si+0x30],ah
00005A50  1800              sbb [bx+si],al
00005A52  780C              js 0x5a60
00005A54  7CCC              jl 0x5a22
00005A56  CC                int3
00005A57  7600              jna 0x5a59
00005A59  0000              add [bx+si],al
00005A5B  0038              add [bx+si],bh
00005A5D  6C                insb
00005A5E  3800              cmp [bx+si],al
00005A60  780C              js 0x5a6e
00005A62  7CCC              jl 0x5a30
00005A64  CC                int3
00005A65  7600              jna 0x5a67
00005A67  0000              add [bx+si],al
00005A69  0000              add [bx+si],al
00005A6B  0000              add [bx+si],al
00005A6D  3C66              cmp al,0x66
00005A6F  60                pushaw
00005A70  663C0C            o32 cmp al,0xc
00005A73  06                push es
00005A74  3C00              cmp al,0x0
00005A76  0000              add [bx+si],al
00005A78  1038              adc [bx+si],bh
00005A7A  6C                insb
00005A7B  007CC6            add [si-0x3a],bh
00005A7E  FEC0              inc al
00005A80  C6                db 0xc6
00005A81  7C00              jl 0x5a83
00005A83  0000              add [bx+si],al
00005A85  0000              add [bx+si],al
00005A87  CC                int3
00005A88  CC                int3
00005A89  007CC6            add [si-0x3a],bh
00005A8C  FEC0              inc al
00005A8E  C6                db 0xc6
00005A8F  7C00              jl 0x5a91
00005A91  0000              add [bx+si],al
00005A93  006030            add [bx+si+0x30],ah
00005A96  1800              sbb [bx+si],al
00005A98  7CC6              jl 0x5a60
00005A9A  FEC0              inc al
00005A9C  C6                db 0xc6
00005A9D  7C00              jl 0x5a9f
00005A9F  0000              add [bx+si],al
00005AA1  0000              add [bx+si],al
00005AA3  66660038          o32 add [bx+si],bh
00005AA7  1818              sbb [bx+si],bl
00005AA9  1818              sbb [bx+si],bl
00005AAB  3C00              cmp al,0x0
00005AAD  0000              add [bx+si],al
00005AAF  0018              add [bx+si],bl
00005AB1  3C66              cmp al,0x66
00005AB3  0038              add [bx+si],bh
00005AB5  1818              sbb [bx+si],bl
00005AB7  1818              sbb [bx+si],bl
00005AB9  3C00              cmp al,0x0
00005ABB  0000              add [bx+si],al
00005ABD  006030            add [bx+si+0x30],ah
00005AC0  1800              sbb [bx+si],al
00005AC2  3818              cmp [bx+si],bl
00005AC4  1818              sbb [bx+si],bl
00005AC6  183C              sbb [si],bh
00005AC8  0000              add [bx+si],al
00005ACA  0000              add [bx+si],al
00005ACC  C6C610            mov dh,0x10
00005ACF  386CC6            cmp [si-0x3a],ch
00005AD2  C6                db 0xc6
00005AD3  FEC6              inc dh
00005AD5  C60000            mov byte [bx+si],0x0
00005AD8  0038              add [bx+si],bh
00005ADA  6C                insb
00005ADB  3800              cmp [bx+si],al
00005ADD  386CC6            cmp [si-0x3a],ch
00005AE0  C6                db 0xc6
00005AE1  FEC6              inc dh
00005AE3  C60000            mov byte [bx+si],0x0
00005AE6  0018              add [bx+si],bl
00005AE8  306000            xor [bx+si+0x0],ah
00005AEB  FE                db 0xfe
00005AEC  6660              pushad
00005AEE  7C60              jl 0x5b50
00005AF0  66FE00            o32 inc byte [bx+si]
00005AF3  0000              add [bx+si],al
00005AF5  0000              add [bx+si],al
00005AF7  0000              add [bx+si],al
00005AF9  CC                int3
00005AFA  7636              jna 0x5b32
00005AFC  7ED8              jng 0x5ad6
00005AFE  D86E00            fsubr dword [bp+0x0]
00005B01  0000              add [bx+si],al
00005B03  0000              add [bx+si],al
00005B05  3E6C              ds insb
00005B07  CC                int3
00005B08  CC                int3
00005B09  FECC              dec ah
00005B0B  CC                int3
00005B0C  CC                int3
00005B0D  CE                into
00005B0E  0000              add [bx+si],al
00005B10  0000              add [bx+si],al
00005B12  1038              adc [bx+si],bh
00005B14  6C                insb
00005B15  007CC6            add [si-0x3a],bh
00005B18  C6C6C6            mov dh,0xc6
00005B1B  7C00              jl 0x5b1d
00005B1D  0000              add [bx+si],al
00005B1F  0000              add [bx+si],al
00005B21  C6C600            mov dh,0x0
00005B24  7CC6              jl 0x5aec
00005B26  C6C6C6            mov dh,0xc6
00005B29  7C00              jl 0x5b2b
00005B2B  0000              add [bx+si],al
00005B2D  006030            add [bx+si+0x30],ah
00005B30  1800              sbb [bx+si],al
00005B32  7CC6              jl 0x5afa
00005B34  C6C6C6            mov dh,0xc6
00005B37  7C00              jl 0x5b39
00005B39  0000              add [bx+si],al
00005B3B  0030              add [bx+si],dh
00005B3D  78CC              js 0x5b0b
00005B3F  00CC              add ah,cl
00005B41  CC                int3
00005B42  CC                int3
00005B43  CC                int3
00005B44  CC                int3
00005B45  7600              jna 0x5b47
00005B47  0000              add [bx+si],al
00005B49  006030            add [bx+si+0x30],ah
00005B4C  1800              sbb [bx+si],al
00005B4E  CC                int3
00005B4F  CC                int3
00005B50  CC                int3
00005B51  CC                int3
00005B52  CC                int3
00005B53  7600              jna 0x5b55
00005B55  0000              add [bx+si],al
00005B57  0000              add [bx+si],al
00005B59  C6C600            mov dh,0x0
00005B5C  C6C6C6            mov dh,0xc6
00005B5F  C6                db 0xc6
00005B60  7E06              jng 0x5b68
00005B62  0C78              or al,0x78
00005B64  0000              add [bx+si],al
00005B66  C6C638            mov dh,0x38
00005B69  6C                insb
00005B6A  C6C6C6            mov dh,0xc6
00005B6D  C6                db 0xc6
00005B6E  6C                insb
00005B6F  3800              cmp [bx+si],al
00005B71  0000              add [bx+si],al
00005B73  00C6              add dh,al
00005B75  C600C6            mov byte [bx+si],0xc6
00005B78  C6C6C6            mov dh,0xc6
00005B7B  C6C67C            mov dh,0x7c
00005B7E  0000              add [bx+si],al
00005B80  0000              add [bx+si],al
00005B82  1818              sbb [bx+si],bl
00005B84  3C66              cmp al,0x66
00005B86  60                pushaw
00005B87  60                pushaw
00005B88  663C18            o32 cmp al,0x18
00005B8B  1800              sbb [bx+si],al
00005B8D  0000              add [bx+si],al
00005B8F  0038              add [bx+si],bh
00005B91  6C                insb
00005B92  6460              fs pushaw
00005B94  F060              lock pushaw
00005B96  60                pushaw
00005B97  60                pushaw
00005B98  E6FC              out 0xfc,al
00005B9A  0000              add [bx+si],al
00005B9C  0000              add [bx+si],al
00005B9E  006666            add [bp+0x66],ah
00005BA1  3C18              cmp al,0x18
00005BA3  7E18              jng 0x5bbd
00005BA5  7E18              jng 0x5bbf
00005BA7  1800              sbb [bx+si],al
00005BA9  0000              add [bx+si],al
00005BAB  00F8              add al,bh
00005BAD  CC                int3
00005BAE  CC                int3
00005BAF  F8                clc
00005BB0  C4                db 0xc4
00005BB1  CC                int3
00005BB2  DECC              fmulp st4
00005BB4  CC                int3
00005BB5  C60000            mov byte [bx+si],0x0
00005BB8  0000              add [bx+si],al
00005BBA  0E                push cs
00005BBB  1B18              sbb bx,[bx+si]
00005BBD  1818              sbb [bx+si],bl
00005BBF  7E18              jng 0x5bd9
00005BC1  1818              sbb [bx+si],bl
00005BC3  18D8              sbb al,bl
00005BC5  7000              jo 0x5bc7
00005BC7  0018              add [bx+si],bl
00005BC9  306000            xor [bx+si+0x0],ah
00005BCC  780C              js 0x5bda
00005BCE  7CCC              jl 0x5b9c
00005BD0  CC                int3
00005BD1  7600              jna 0x5bd3
00005BD3  0000              add [bx+si],al
00005BD5  000C              add [si],cl
00005BD7  1830              sbb [bx+si],dh
00005BD9  0038              add [bx+si],bh
00005BDB  1818              sbb [bx+si],bl
00005BDD  1818              sbb [bx+si],bl
00005BDF  3C00              cmp al,0x0
00005BE1  0000              add [bx+si],al
00005BE3  0018              add [bx+si],bl
00005BE5  306000            xor [bx+si+0x0],ah
00005BE8  7CC6              jl 0x5bb0
00005BEA  C6C6C6            mov dh,0xc6
00005BED  7C00              jl 0x5bef
00005BEF  0000              add [bx+si],al
00005BF1  0018              add [bx+si],bl
00005BF3  306000            xor [bx+si+0x0],ah
00005BF6  CC                int3
00005BF7  CC                int3
00005BF8  CC                int3
00005BF9  CC                int3
00005BFA  CC                int3
00005BFB  7600              jna 0x5bfd
00005BFD  0000              add [bx+si],al
00005BFF  0000              add [bx+si],al
00005C01  76DC              jna 0x5bdf
00005C03  00DC              add ah,bl
00005C05  66666666660000    o32 add [bx+si],al
00005C0C  0076DC            add [bp-0x24],dh
00005C0F  00C6              add dh,al
00005C11  E6F6              out 0xf6,al
00005C13  FE                db 0xfe
00005C14  DECE              fmulp st6
00005C16  C6C600            mov dh,0x0
00005C19  0000              add [bx+si],al
00005C1B  003C              add [si],bh
00005C1D  6C                insb
00005C1E  6C                insb
00005C1F  3E007E00          add [ds:bp+0x0],bh
00005C23  0000              add [bx+si],al
00005C25  0000              add [bx+si],al
00005C27  0000              add [bx+si],al
00005C29  0038              add [bx+si],bh
00005C2B  6C                insb
00005C2C  6C                insb
00005C2D  3800              cmp [bx+si],al
00005C2F  7C00              jl 0x5c31
00005C31  0000              add [bx+si],al
00005C33  0000              add [bx+si],al
00005C35  0000              add [bx+si],al
00005C37  0000              add [bx+si],al
00005C39  3030              xor [bx+si],dh
00005C3B  0030              add [bx+si],dh
00005C3D  3060C6            xor [bx+si-0x3a],ah
00005C40  C6                db 0xc6
00005C41  7C00              jl 0x5c43
00005C43  0000              add [bx+si],al
00005C45  0000              add [bx+si],al
00005C47  0000              add [bx+si],al
00005C49  0000              add [bx+si],al
00005C4B  FEC0              inc al
00005C4D  C0C000            rol al,0x0
00005C50  0000              add [bx+si],al
00005C52  0000              add [bx+si],al
00005C54  0000              add [bx+si],al
00005C56  0000              add [bx+si],al
00005C58  00FE              add dh,bh
00005C5A  06                push es
00005C5B  06                push es
00005C5C  06                push es
00005C5D  0000              add [bx+si],al
00005C5F  0000              add [bx+si],al
00005C61  00C0              add al,al
00005C63  C0C6CC            rol dh,0xcc
00005C66  D830              fdiv dword [bx+si]
00005C68  60                pushaw
00005C69  DC860C18          fadd qword [bp+0x180c]
00005C6D  3E0000            add [ds:bx+si],al
00005C70  C0C0C6            rol al,0xc6
00005C73  CC                int3
00005C74  D830              fdiv dword [bx+si]
00005C76  66CE              o32 into
00005C78  9E                sahf
00005C79  3E06              ds push es
00005C7B  06                push es
00005C7C  0000              add [bx+si],al
00005C7E  0018              add [bx+si],bl
00005C80  1800              sbb [bx+si],al
00005C82  1818              sbb [bx+si],bl
00005C84  3C3C              cmp al,0x3c
00005C86  3C18              cmp al,0x18
00005C88  0000              add [bx+si],al
00005C8A  0000              add [bx+si],al
00005C8C  0000              add [bx+si],al
00005C8E  00366CD8          add [0xd86c],dh
00005C92  6C                insb
00005C93  360000            add [ss:bx+si],al
00005C96  0000              add [bx+si],al
00005C98  0000              add [bx+si],al
00005C9A  0000              add [bx+si],al
00005C9C  00D8              add al,bl
00005C9E  6C                insb
00005C9F  366C              ss insb
00005CA1  D800              fadd dword [bx+si]
00005CA3  0000              add [bx+si],al
00005CA5  0000              add [bx+si],al
00005CA7  114411            adc [si+0x11],ax
00005CAA  44                inc sp
00005CAB  114411            adc [si+0x11],ax
00005CAE  44                inc sp
00005CAF  114411            adc [si+0x11],ax
00005CB2  44                inc sp
00005CB3  114455            adc [si+0x55],ax
00005CB6  AA                stosb
00005CB7  55                push bp
00005CB8  AA                stosb
00005CB9  55                push bp
00005CBA  AA                stosb
00005CBB  55                push bp
00005CBC  AA                stosb
00005CBD  55                push bp
00005CBE  AA                stosb
00005CBF  55                push bp
00005CC0  AA                stosb
00005CC1  55                push bp
00005CC2  AA                stosb
00005CC3  DD77DD            fnsave [bx-0x23]
00005CC6  77DD              ja 0x5ca5
00005CC8  77DD              ja 0x5ca7
00005CCA  77DD              ja 0x5ca9
00005CCC  77DD              ja 0x5cab
00005CCE  77DD              ja 0x5cad
00005CD0  7718              ja 0x5cea
00005CD2  1818              sbb [bx+si],bl
00005CD4  1818              sbb [bx+si],bl
00005CD6  1818              sbb [bx+si],bl
00005CD8  1818              sbb [bx+si],bl
00005CDA  1818              sbb [bx+si],bl
00005CDC  1818              sbb [bx+si],bl
00005CDE  1818              sbb [bx+si],bl
00005CE0  1818              sbb [bx+si],bl
00005CE2  1818              sbb [bx+si],bl
00005CE4  1818              sbb [bx+si],bl
00005CE6  F8                clc
00005CE7  1818              sbb [bx+si],bl
00005CE9  1818              sbb [bx+si],bl
00005CEB  1818              sbb [bx+si],bl
00005CED  1818              sbb [bx+si],bl
00005CEF  1818              sbb [bx+si],bl
00005CF1  18F8              sbb al,bh
00005CF3  18F8              sbb al,bh
00005CF5  1818              sbb [bx+si],bl
00005CF7  1818              sbb [bx+si],bl
00005CF9  1818              sbb [bx+si],bl
00005CFB  36363636363636F6  div byte [ss:0x3636]
         -363636
00005D06  3636360000        add [ss:bx+si],al
00005D0B  0000              add [bx+si],al
00005D0D  0000              add [bx+si],al
00005D0F  00FE              add dh,bh
00005D11  3636363636360000  add [ss:bx+si],al
00005D19  0000              add [bx+si],al
00005D1B  00F8              add al,bh
00005D1D  18F8              sbb al,bh
00005D1F  1818              sbb [bx+si],bl
00005D21  1818              sbb [bx+si],bl
00005D23  1818              sbb [bx+si],bl
00005D25  3636363636F606F6  test byte [ss:0x36f6],0x36
         -3636
00005D2F  3636363636363636  add [ss:bx+si],al
         -3636363636363636
         -36360000
00005D43  0000              add [bx+si],al
00005D45  00FE              add dh,bh
00005D47  06                push es
00005D48  F6363636          div byte [0x3636]
00005D4C  3636363636363636  test byte [ss:0xfe],0x0
         -F606FE0000
00005D59  0000              add [bx+si],al
00005D5B  0000              add [bx+si],al
00005D5D  36363636363636FE  inc byte [ss:bx+si]
         -00
00005D66  0000              add [bx+si],al
00005D68  0000              add [bx+si],al
00005D6A  0018              add [bx+si],bl
00005D6C  1818              sbb [bx+si],bl
00005D6E  1818              sbb [bx+si],bl
00005D70  F8                clc
00005D71  18F8              sbb al,bh
00005D73  0000              add [bx+si],al
00005D75  0000              add [bx+si],al
00005D77  0000              add [bx+si],al
00005D79  0000              add [bx+si],al
00005D7B  0000              add [bx+si],al
00005D7D  0000              add [bx+si],al
00005D7F  00F8              add al,bh
00005D81  1818              sbb [bx+si],bl
00005D83  1818              sbb [bx+si],bl
00005D85  1818              sbb [bx+si],bl
00005D87  1818              sbb [bx+si],bl
00005D89  1818              sbb [bx+si],bl
00005D8B  1818              sbb [bx+si],bl
00005D8D  181F              sbb [bx],bl
00005D8F  0000              add [bx+si],al
00005D91  0000              add [bx+si],al
00005D93  0000              add [bx+si],al
00005D95  1818              sbb [bx+si],bl
00005D97  1818              sbb [bx+si],bl
00005D99  1818              sbb [bx+si],bl
00005D9B  18FF              sbb bh,bh
00005D9D  0000              add [bx+si],al
00005D9F  0000              add [bx+si],al
00005DA1  0000              add [bx+si],al
00005DA3  0000              add [bx+si],al
00005DA5  0000              add [bx+si],al
00005DA7  0000              add [bx+si],al
00005DA9  00FF              add bh,bh
00005DAB  1818              sbb [bx+si],bl
00005DAD  1818              sbb [bx+si],bl
00005DAF  1818              sbb [bx+si],bl
00005DB1  1818              sbb [bx+si],bl
00005DB3  1818              sbb [bx+si],bl
00005DB5  1818              sbb [bx+si],bl
00005DB7  181F              sbb [bx],bl
00005DB9  1818              sbb [bx+si],bl
00005DBB  1818              sbb [bx+si],bl
00005DBD  1818              sbb [bx+si],bl
00005DBF  0000              add [bx+si],al
00005DC1  0000              add [bx+si],al
00005DC3  0000              add [bx+si],al
00005DC5  00FF              add bh,bh
00005DC7  0000              add [bx+si],al
00005DC9  0000              add [bx+si],al
00005DCB  0000              add [bx+si],al
00005DCD  1818              sbb [bx+si],bl
00005DCF  1818              sbb [bx+si],bl
00005DD1  1818              sbb [bx+si],bl
00005DD3  18FF              sbb bh,bh
00005DD5  1818              sbb [bx+si],bl
00005DD7  1818              sbb [bx+si],bl
00005DD9  1818              sbb [bx+si],bl
00005DDB  1818              sbb [bx+si],bl
00005DDD  1818              sbb [bx+si],bl
00005DDF  181F              sbb [bx],bl
00005DE1  181F              sbb [bx],bl
00005DE3  1818              sbb [bx+si],bl
00005DE5  1818              sbb [bx+si],bl
00005DE7  1818              sbb [bx+si],bl
00005DE9  3636363636363637  ss aaa
00005DF1  3636363636363636  ss aaa
         -36363637
00005DFD  303F              xor [bx],bh
00005DFF  0000              add [bx+si],al
00005E01  0000              add [bx+si],al
00005E03  0000              add [bx+si],al
00005E05  0000              add [bx+si],al
00005E07  0000              add [bx+si],al
00005E09  003F              add [bx],bh
00005E0B  3037              xor [bx],dh
00005E0D  3636363636363636  test word [ss:bx+si],0xff
         -363636F700FF00
00005E1C  0000              add [bx+si],al
00005E1E  0000              add [bx+si],al
00005E20  0000              add [bx+si],al
00005E22  0000              add [bx+si],al
00005E24  0000              add [bx+si],al
00005E26  FF00              inc word [bx+si]
00005E28  F7363636          div word [0x3636]
00005E2C  3636363636363636  ss aaa
         -37
00005E35  3037              xor [bx],dh
00005E37  3636363636360000  add [ss:bx+si],al
00005E3F  0000              add [bx+si],al
00005E41  00FF              add bh,bh
00005E43  00FF              add bh,bh
00005E45  0000              add [bx+si],al
00005E47  0000              add [bx+si],al
00005E49  0000              add [bx+si],al
00005E4B  3636363636F700F7  test word [ss:bx+si],0x36f7
         -36
00005E54  36363636361818    sbb [ss:bx+si],bl
00005E5B  1818              sbb [bx+si],bl
00005E5D  18FF              sbb bh,bh
00005E5F  00FF              add bh,bh
00005E61  0000              add [bx+si],al
00005E63  0000              add [bx+si],al
00005E65  0000              add [bx+si],al
00005E67  36363636363636FF  inc word [ss:bx+si]
         -00
00005E70  0000              add [bx+si],al
00005E72  0000              add [bx+si],al
00005E74  0000              add [bx+si],al
00005E76  0000              add [bx+si],al
00005E78  0000              add [bx+si],al
00005E7A  FF00              inc word [bx+si]
00005E7C  FF18              call word far [bx+si]
00005E7E  1818              sbb [bx+si],bl
00005E80  1818              sbb [bx+si],bl
00005E82  1800              sbb [bx+si],al
00005E84  0000              add [bx+si],al
00005E86  0000              add [bx+si],al
00005E88  0000              add [bx+si],al
00005E8A  FF363636          push word [0x3636]
00005E8E  3636363636363636  ss aas
         -36363F
00005E99  0000              add [bx+si],al
00005E9B  0000              add [bx+si],al
00005E9D  0000              add [bx+si],al
00005E9F  1818              sbb [bx+si],bl
00005EA1  1818              sbb [bx+si],bl
00005EA3  181F              sbb [bx],bl
00005EA5  181F              sbb [bx],bl
00005EA7  0000              add [bx+si],al
00005EA9  0000              add [bx+si],al
00005EAB  0000              add [bx+si],al
00005EAD  0000              add [bx+si],al
00005EAF  0000              add [bx+si],al
00005EB1  001F              add [bx],bl
00005EB3  181F              sbb [bx],bl
00005EB5  1818              sbb [bx+si],bl
00005EB7  1818              sbb [bx+si],bl
00005EB9  1818              sbb [bx+si],bl
00005EBB  0000              add [bx+si],al
00005EBD  0000              add [bx+si],al
00005EBF  0000              add [bx+si],al
00005EC1  003F              add [bx],bh
00005EC3  3636363636363636  push word [ss:0x3636]
         -3636363636FF3636
         -36
00005ED4  3636361818        sbb [ss:bx+si],bl
00005ED9  1818              sbb [bx+si],bl
00005EDB  18FF              sbb bh,bh
00005EDD  18FF              sbb bh,bh
00005EDF  1818              sbb [bx+si],bl
00005EE1  1818              sbb [bx+si],bl
00005EE3  1818              sbb [bx+si],bl
00005EE5  1818              sbb [bx+si],bl
00005EE7  1818              sbb [bx+si],bl
00005EE9  1818              sbb [bx+si],bl
00005EEB  18F8              sbb al,bh
00005EED  0000              add [bx+si],al
00005EEF  0000              add [bx+si],al
00005EF1  0000              add [bx+si],al
00005EF3  0000              add [bx+si],al
00005EF5  0000              add [bx+si],al
00005EF7  0000              add [bx+si],al
00005EF9  001F              add [bx],bl
00005EFB  1818              sbb [bx+si],bl
00005EFD  1818              sbb [bx+si],bl
00005EFF  1818              sbb [bx+si],bl
00005F01  FF                db 0xff
00005F02  FF                db 0xff
00005F03  FF                db 0xff
00005F04  FF                db 0xff
00005F05  FF                db 0xff
00005F06  FF                db 0xff
00005F07  FF                db 0xff
00005F08  FF                db 0xff
00005F09  FF                db 0xff
00005F0A  FF                db 0xff
00005F0B  FF                db 0xff
00005F0C  FF                db 0xff
00005F0D  FF                db 0xff
00005F0E  FF00              inc word [bx+si]
00005F10  0000              add [bx+si],al
00005F12  0000              add [bx+si],al
00005F14  0000              add [bx+si],al
00005F16  FF                db 0xff
00005F17  FF                db 0xff
00005F18  FF                db 0xff
00005F19  FF                db 0xff
00005F1A  FF                db 0xff
00005F1B  FF                db 0xff
00005F1C  FFF0              push ax
00005F1E  F0                lock
00005F1F  F0                lock
00005F20  F0                lock
00005F21  F0                lock
00005F22  F0                lock
00005F23  F0                lock
00005F24  F0                lock
00005F25  F0                lock
00005F26  F0                lock
00005F27  F0                lock
00005F28  F0                lock
00005F29  F0                lock
00005F2A  F0                lock
00005F2B  0F                db 0x0f
00005F2C  0F                db 0x0f
00005F2D  0F                db 0x0f
00005F2E  0F                db 0x0f
00005F2F  0F                db 0x0f
00005F30  0F                db 0x0f
00005F31  0F                db 0x0f
00005F32  0F                db 0x0f
00005F33  0F                db 0x0f
00005F34  0F                db 0x0f
00005F35  0F                db 0x0f
00005F36  0F                db 0x0f
00005F37  0F                db 0x0f
00005F38  0FFF              ud0
00005F3A  FF                db 0xff
00005F3B  FF                db 0xff
00005F3C  FF                db 0xff
00005F3D  FF                db 0xff
00005F3E  FF                db 0xff
00005F3F  FF00              inc word [bx+si]
00005F41  0000              add [bx+si],al
00005F43  0000              add [bx+si],al
00005F45  0000              add [bx+si],al
00005F47  0000              add [bx+si],al
00005F49  0000              add [bx+si],al
00005F4B  0076DC            add [bp-0x24],dh
00005F4E  D8D8              fcomp st0
00005F50  DC7600            fdiv qword [bp+0x0]
00005F53  0000              add [bx+si],al
00005F55  0000              add [bx+si],al
00005F57  0000              add [bx+si],al
00005F59  7CC6              jl 0x5f21
00005F5B  FC                cld
00005F5C  C6C6FC            mov dh,0xfc
00005F5F  C0C040            rol al,0x40
00005F62  0000              add [bx+si],al
00005F64  00FE              add dh,bh
00005F66  C6C6C0            mov dh,0xc0
00005F69  C0C0C0            rol al,0xc0
00005F6C  C0C000            rol al,0x0
00005F6F  0000              add [bx+si],al
00005F71  0000              add [bx+si],al
00005F73  0000              add [bx+si],al
00005F75  FE                db 0xfe
00005F76  6C                insb
00005F77  6C                insb
00005F78  6C                insb
00005F79  6C                insb
00005F7A  6C                insb
00005F7B  6C                insb
00005F7C  0000              add [bx+si],al
00005F7E  0000              add [bx+si],al
00005F80  00FE              add dh,bh
00005F82  C6                db 0xc6
00005F83  60                pushaw
00005F84  3018              xor [bx+si],bl
00005F86  3060C6            xor [bx+si-0x3a],ah
00005F89  FE00              inc byte [bx+si]
00005F8B  0000              add [bx+si],al
00005F8D  0000              add [bx+si],al
00005F8F  0000              add [bx+si],al
00005F91  007ED8            add [bp-0x28],bh
00005F94  D8D8              fcomp st0
00005F96  D87000            fdiv dword [bx+si+0x0]
00005F99  0000              add [bx+si],al
00005F9B  0000              add [bx+si],al
00005F9D  0000              add [bx+si],al
00005F9F  666666667C60      o32 jl 0x6005
00005FA5  60                pushaw
00005FA6  C00000            rol byte [bx+si],0x0
00005FA9  0000              add [bx+si],al
00005FAB  0000              add [bx+si],al
00005FAD  76DC              jna 0x5f8b
00005FAF  1818              sbb [bx+si],bl
00005FB1  1818              sbb [bx+si],bl
00005FB3  1800              sbb [bx+si],al
00005FB5  0000              add [bx+si],al
00005FB7  0000              add [bx+si],al
00005FB9  7E18              jng 0x5fd3
00005FBB  3C66              cmp al,0x66
00005FBD  66663C18          o32 cmp al,0x18
00005FC1  7E00              jng 0x5fc3
00005FC3  0000              add [bx+si],al
00005FC5  0000              add [bx+si],al
00005FC7  386CC6            cmp [si-0x3a],ch
00005FCA  C6                db 0xc6
00005FCB  FEC6              inc dh
00005FCD  C6                db 0xc6
00005FCE  6C                insb
00005FCF  3800              cmp [bx+si],al
00005FD1  0000              add [bx+si],al
00005FD3  0000              add [bx+si],al
00005FD5  386CC6            cmp [si-0x3a],ch
00005FD8  C6C66C            mov dh,0x6c
00005FDB  6C                insb
00005FDC  6C                insb
00005FDD  EE                out dx,al
00005FDE  0000              add [bx+si],al
00005FE0  0000              add [bx+si],al
00005FE2  001E3018          add [0x1830],bl
00005FE6  0C3E              or al,0x3e
00005FE8  6666663C00        o32 cmp al,0x0
00005FED  0000              add [bx+si],al
00005FEF  0000              add [bx+si],al
00005FF1  0000              add [bx+si],al
00005FF3  007EDB            add [bp-0x25],bh
00005FF6  DB7E00            fstp tword [bp+0x0]
00005FF9  0000              add [bx+si],al
00005FFB  0000              add [bx+si],al
00005FFD  0000              add [bx+si],al
00005FFF  03067EDB          add ax,[0xdb7e]
00006003  DBF3              fcomi st3
00006005  7E60              jng 0x6067
00006007  C00000            rol byte [bx+si],0x0
0000600A  0000              add [bx+si],al
0000600C  001C              add [si],bl
0000600E  306060            xor [bx+si+0x60],ah
00006011  7C60              jl 0x6073
00006013  60                pushaw
00006014  301C              xor [si],bl
00006016  0000              add [bx+si],al
00006018  0000              add [bx+si],al
0000601A  0000              add [bx+si],al
0000601C  7CC6              jl 0x5fe4
0000601E  C6C6C6            mov dh,0xc6
00006021  C6C6C6            mov dh,0xc6
00006024  0000              add [bx+si],al
00006026  0000              add [bx+si],al
00006028  0000              add [bx+si],al
0000602A  FE00              inc byte [bx+si]
0000602C  00FE              add dh,bh
0000602E  0000              add [bx+si],al
00006030  FE00              inc byte [bx+si]
00006032  0000              add [bx+si],al
00006034  0000              add [bx+si],al
00006036  0000              add [bx+si],al
00006038  1818              sbb [bx+si],bl
0000603A  7E18              jng 0x6054
0000603C  1800              sbb [bx+si],al
0000603E  00FF              add bh,bh
00006040  0000              add [bx+si],al
00006042  0000              add [bx+si],al
00006044  0030              add [bx+si],dh
00006046  180C              sbb [si],cl
00006048  06                push es
00006049  0C18              or al,0x18
0000604B  3000              xor [bx+si],al
0000604D  7E00              jng 0x604f
0000604F  0000              add [bx+si],al
00006051  0000              add [bx+si],al
00006053  0C18              or al,0x18
00006055  306030            xor [bx+si+0x30],ah
00006058  180C              sbb [si],cl
0000605A  007E00            add [bp+0x0],bh
0000605D  0000              add [bx+si],al
0000605F  0000              add [bx+si],al
00006061  0E                push cs
00006062  1B1B              sbb bx,[bp+di]
00006064  1818              sbb [bx+si],bl
00006066  1818              sbb [bx+si],bl
00006068  1818              sbb [bx+si],bl
0000606A  1818              sbb [bx+si],bl
0000606C  1818              sbb [bx+si],bl
0000606E  1818              sbb [bx+si],bl
00006070  1818              sbb [bx+si],bl
00006072  1818              sbb [bx+si],bl
00006074  18D8              sbb al,bl
00006076  D87000            fdiv dword [bx+si+0x0]
00006079  0000              add [bx+si],al
0000607B  0000              add [bx+si],al
0000607D  0018              add [bx+si],bl
0000607F  1800              sbb [bx+si],al
00006081  7E00              jng 0x6083
00006083  1818              sbb [bx+si],bl
00006085  0000              add [bx+si],al
00006087  0000              add [bx+si],al
00006089  0000              add [bx+si],al
0000608B  0000              add [bx+si],al
0000608D  76DC              jna 0x606b
0000608F  0076DC            add [bp-0x24],dh
00006092  0000              add [bx+si],al
00006094  0000              add [bx+si],al
00006096  0000              add [bx+si],al
00006098  386C6C            cmp [si+0x6c],ch
0000609B  3800              cmp [bx+si],al
0000609D  0000              add [bx+si],al
0000609F  0000              add [bx+si],al
000060A1  0000              add [bx+si],al
000060A3  0000              add [bx+si],al
000060A5  0000              add [bx+si],al
000060A7  0000              add [bx+si],al
000060A9  0000              add [bx+si],al
000060AB  1818              sbb [bx+si],bl
000060AD  0000              add [bx+si],al
000060AF  0000              add [bx+si],al
000060B1  0000              add [bx+si],al
000060B3  0000              add [bx+si],al
000060B5  0000              add [bx+si],al
000060B7  0000              add [bx+si],al
000060B9  0018              add [bx+si],bl
000060BB  0000              add [bx+si],al
000060BD  0000              add [bx+si],al
000060BF  0000              add [bx+si],al
000060C1  000F              add [bx],cl
000060C3  0C0C              or al,0xc
000060C5  0C0C              or al,0xc
000060C7  0CEC              or al,0xec
000060C9  6C                insb
000060CA  3C1C              cmp al,0x1c
000060CC  0000              add [bx+si],al
000060CE  0000              add [bx+si],al
000060D0  D86C6C            fsubr dword [si+0x6c]
000060D3  6C                insb
000060D4  6C                insb
000060D5  6C                insb
000060D6  0000              add [bx+si],al
000060D8  0000              add [bx+si],al
000060DA  0000              add [bx+si],al
000060DC  0000              add [bx+si],al
000060DE  70D8              jo 0x60b8
000060E0  3060C8            xor [bx+si-0x38],ah
000060E3  F8                clc
000060E4  0000              add [bx+si],al
000060E6  0000              add [bx+si],al
000060E8  0000              add [bx+si],al
000060EA  0000              add [bx+si],al
000060EC  0000              add [bx+si],al
000060EE  007C7C            add [si+0x7c],bh
000060F1  7C7C              jl 0x616f
000060F3  7C7C              jl 0x6171
000060F5  0000              add [bx+si],al
000060F7  0000              add [bx+si],al
000060F9  0000              add [bx+si],al
000060FB  0000              add [bx+si],al
000060FD  0000              add [bx+si],al
000060FF  0000              add [bx+si],al
00006101  0000              add [bx+si],al
00006103  0000              add [bx+si],al
00006105  0000              add [bx+si],al
00006107  0000              add [bx+si],al
00006109  0000              add [bx+si],al
0000610B  0000              add [bx+si],al
0000610D  0000              add [bx+si],al
0000610F  0000              add [bx+si],al
00006111  0000              add [bx+si],al
00006113  0000              add [bx+si],al
00006115  0000              add [bx+si],al
00006117  0000              add [bx+si],al
00006119  7E81              jng 0x609c
0000611B  A5                movsw
0000611C  8181BD998181      add word [bx+di-0x6643],0x8181
00006122  7E00              jng 0x6124
00006124  0000              add [bx+si],al
00006126  0000              add [bx+si],al
00006128  007EFF            add [bp-0x1],bh
0000612B  DB                db 0xdb
0000612C  FF                db 0xff
0000612D  FFC3              inc bx
0000612F  E7FF              out 0xff,ax
00006131  FF                db 0xff
00006132  7E00              jng 0x6134
00006134  0000              add [bx+si],al
00006136  0000              add [bx+si],al
00006138  0000              add [bx+si],al
0000613A  006CFE            add [si-0x2],ch
0000613D  FE                db 0xfe
0000613E  FE                db 0xfe
0000613F  FE                db 0xfe
00006140  7C38              jl 0x617a
00006142  1000              adc [bx+si],al
00006144  0000              add [bx+si],al
00006146  0000              add [bx+si],al
00006148  0000              add [bx+si],al
0000614A  0010              add [bx+si],dl
0000614C  387CFE            cmp [si-0x2],bh
0000614F  7C38              jl 0x6189
00006151  1000              adc [bx+si],al
00006153  0000              add [bx+si],al
00006155  0000              add [bx+si],al
00006157  0000              add [bx+si],al
00006159  0018              add [bx+si],bl
0000615B  3C3C              cmp al,0x3c
0000615D  E7E7              out 0xe7,ax
0000615F  E718              out 0x18,ax
00006161  183C              sbb [si],bh
00006163  0000              add [bx+si],al
00006165  0000              add [bx+si],al
00006167  0000              add [bx+si],al
00006169  0018              add [bx+si],bl
0000616B  3C7E              cmp al,0x7e
0000616D  FF                db 0xff
0000616E  FF                db 0xff
0000616F  7E18              jng 0x6189
00006171  183C              sbb [si],bh
00006173  0000              add [bx+si],al
00006175  0000              add [bx+si],al
00006177  0000              add [bx+si],al
00006179  0000              add [bx+si],al
0000617B  0000              add [bx+si],al
0000617D  183C              sbb [si],bh
0000617F  3C18              cmp al,0x18
00006181  0000              add [bx+si],al
00006183  0000              add [bx+si],al
00006185  0000              add [bx+si],al
00006187  FF                db 0xff
00006188  FF                db 0xff
00006189  FF                db 0xff
0000618A  FF                db 0xff
0000618B  FF                db 0xff
0000618C  FFE7              jmp di
0000618E  C3                ret
0000618F  C3                ret
00006190  E7FF              out 0xff,ax
00006192  FF                db 0xff
00006193  FF                db 0xff
00006194  FF                db 0xff
00006195  FF                db 0xff
00006196  FF00              inc word [bx+si]
00006198  0000              add [bx+si],al
0000619A  0000              add [bx+si],al
0000619C  3C66              cmp al,0x66
0000619E  42                inc dx
0000619F  42                inc dx
000061A0  663C00            o32 cmp al,0x0
000061A3  0000              add [bx+si],al
000061A5  0000              add [bx+si],al
000061A7  FF                db 0xff
000061A8  FF                db 0xff
000061A9  FF                db 0xff
000061AA  FF                db 0xff
000061AB  FFC3              inc bx
000061AD  99                cwd
000061AE  BDBD99            mov bp,0x99bd
000061B1  C3                ret
000061B2  FF                db 0xff
000061B3  FF                db 0xff
000061B4  FF                db 0xff
000061B5  FF                db 0xff
000061B6  FF00              inc word [bx+si]
000061B8  001E0E1A          add [0x1a0e],bl
000061BC  3278CC            xor bh,[bx+si-0x34]
000061BF  CC                int3
000061C0  CC                int3
000061C1  CC                int3
000061C2  7800              js 0x61c4
000061C4  0000              add [bx+si],al
000061C6  0000              add [bx+si],al
000061C8  003C              add [si],bh
000061CA  666666663C18      o32 cmp al,0x18
000061D0  7E18              jng 0x61ea
000061D2  1800              sbb [bx+si],al
000061D4  0000              add [bx+si],al
000061D6  0000              add [bx+si],al
000061D8  003F              add [bx],bh
000061DA  333F              xor di,[bx]
000061DC  3030              xor [bx+si],dh
000061DE  3030              xor [bx+si],dh
000061E0  70F0              jo 0x61d2
000061E2  E000              loopne 0x61e4
000061E4  0000              add [bx+si],al
000061E6  0000              add [bx+si],al
000061E8  007F63            add [bx+0x63],bh
000061EB  7F63              jg 0x6250
000061ED  636363            arpl [bp+di+0x63],sp
000061F0  67E7E6            out 0xe6,ax
000061F3  C00000            rol byte [bx+si],0x0
000061F6  0000              add [bx+si],al
000061F8  0000              add [bx+si],al
000061FA  1818              sbb [bx+si],bl
000061FC  DB3C              fstp tword [si]
000061FE  E73C              out 0x3c,ax
00006200  DB18              fistp dword [bx+si]
00006202  1800              sbb [bx+si],al
00006204  0000              add [bx+si],al
00006206  0000              add [bx+si],al
00006208  80C0E0            add al,0xe0
0000620B  F0F8              lock clc
0000620D  FE                db 0xfe
0000620E  F8                clc
0000620F  F0E0C0            lock loopne 0x61d2
00006212  800000            add byte [bx+si],0x0
00006215  0000              add [bx+si],al
00006217  0002              add [bp+si],al
00006219  06                push es
0000621A  0E                push cs
0000621B  1E                push ds
0000621C  3E                ss
0000621D  FE                db 0xfe
0000621E  3E1E              ds push ds
00006220  0E                push cs
00006221  06                push es
00006222  0200              add al,[bx+si]
00006224  0000              add [bx+si],al
00006226  0000              add [bx+si],al
00006228  0018              add [bx+si],bl
0000622A  3C7E              cmp al,0x7e
0000622C  1818              sbb [bx+si],bl
0000622E  187E3C            sbb [bp+0x3c],bh
00006231  1800              sbb [bx+si],al
00006233  0000              add [bx+si],al
00006235  0000              add [bx+si],al
00006237  0000              add [bx+si],al
00006239  6666666666666600  o32 add [bp+0x66],ah
         -6666
00006243  0000              add [bx+si],al
00006245  0000              add [bx+si],al
00006247  0000              add [bx+si],al
00006249  7FDB              jg 0x6226
0000624B  DBDB              fcmovnu st3
0000624D  7B1B              jpo 0x626a
0000624F  1B1B              sbb bx,[bp+di]
00006251  1B1B              sbb bx,[bp+di]
00006253  0000              add [bx+si],al
00006255  0000              add [bx+si],al
00006257  007CC6            add [si-0x3a],bh
0000625A  60                pushaw
0000625B  386CC6            cmp [si-0x3a],ch
0000625E  C6                db 0xc6
0000625F  6C                insb
00006260  380C              cmp [si],cl
00006262  C6                db 0xc6
00006263  7C00              jl 0x6265
00006265  0000              add [bx+si],al
00006267  0000              add [bx+si],al
00006269  0000              add [bx+si],al
0000626B  0000              add [bx+si],al
0000626D  0000              add [bx+si],al
0000626F  FE                db 0xfe
00006270  FE                db 0xfe
00006271  FE                db 0xfe
00006272  FE00              inc byte [bx+si]
00006274  0000              add [bx+si],al
00006276  0000              add [bx+si],al
00006278  0018              add [bx+si],bl
0000627A  3C7E              cmp al,0x7e
0000627C  1818              sbb [bx+si],bl
0000627E  187E3C            sbb [bp+0x3c],bh
00006281  187E00            sbb [bp+0x0],bh
00006284  0000              add [bx+si],al
00006286  0000              add [bx+si],al
00006288  0018              add [bx+si],bl
0000628A  3C7E              cmp al,0x7e
0000628C  1818              sbb [bx+si],bl
0000628E  1818              sbb [bx+si],bl
00006290  1818              sbb [bx+si],bl
00006292  1800              sbb [bx+si],al
00006294  0000              add [bx+si],al
00006296  0000              add [bx+si],al
00006298  0018              add [bx+si],bl
0000629A  1818              sbb [bx+si],bl
0000629C  1818              sbb [bx+si],bl
0000629E  1818              sbb [bx+si],bl
000062A0  7E3C              jng 0x62de
000062A2  1800              sbb [bx+si],al
000062A4  0000              add [bx+si],al
000062A6  0000              add [bx+si],al
000062A8  0000              add [bx+si],al
000062AA  0000              add [bx+si],al
000062AC  180C              sbb [si],cl
000062AE  FE0C              dec byte [si]
000062B0  1800              sbb [bx+si],al
000062B2  0000              add [bx+si],al
000062B4  0000              add [bx+si],al
000062B6  0000              add [bx+si],al
000062B8  0000              add [bx+si],al
000062BA  0000              add [bx+si],al
000062BC  3060FE            xor [bx+si-0x2],ah
000062BF  60                pushaw
000062C0  3000              xor [bx+si],al
000062C2  0000              add [bx+si],al
000062C4  0000              add [bx+si],al
000062C6  0000              add [bx+si],al
000062C8  0000              add [bx+si],al
000062CA  0000              add [bx+si],al
000062CC  00C0              add al,al
000062CE  C0C0FE            rol al,0xfe
000062D1  0000              add [bx+si],al
000062D3  0000              add [bx+si],al
000062D5  0000              add [bx+si],al
000062D7  0000              add [bx+si],al
000062D9  0000              add [bx+si],al
000062DB  0024              add [si],ah
000062DD  66FF6624          jmp dword near [bp+0x24]
000062E1  0000              add [bx+si],al
000062E3  0000              add [bx+si],al
000062E5  0000              add [bx+si],al
000062E7  0000              add [bx+si],al
000062E9  0000              add [bx+si],al
000062EB  1038              adc [bx+si],bh
000062ED  387C7C            cmp [si+0x7c],bh
000062F0  FE                db 0xfe
000062F1  FE00              inc byte [bx+si]
000062F3  0000              add [bx+si],al
000062F5  0000              add [bx+si],al
000062F7  0000              add [bx+si],al
000062F9  0000              add [bx+si],al
000062FB  FE                db 0xfe
000062FC  FE                db 0xfe
000062FD  7C7C              jl 0x637b
000062FF  3838              cmp [bx+si],bh
00006301  1000              adc [bx+si],al
00006303  0000              add [bx+si],al
00006305  0000              add [bx+si],al
00006307  0000              add [bx+si],al
00006309  0000              add [bx+si],al
0000630B  0000              add [bx+si],al
0000630D  0000              add [bx+si],al
0000630F  0000              add [bx+si],al
00006311  0000              add [bx+si],al
00006313  0000              add [bx+si],al
00006315  0000              add [bx+si],al
00006317  0000              add [bx+si],al
00006319  183C              sbb [si],bh
0000631B  3C3C              cmp al,0x3c
0000631D  1818              sbb [bx+si],bl
0000631F  1800              sbb [bx+si],al
00006321  1818              sbb [bx+si],bl
00006323  0000              add [bx+si],al
00006325  0000              add [bx+si],al
00006327  006666            add [bp+0x66],ah
0000632A  662400            o32 and al,0x0
0000632D  0000              add [bx+si],al
0000632F  0000              add [bx+si],al
00006331  0000              add [bx+si],al
00006333  0000              add [bx+si],al
00006335  0000              add [bx+si],al
00006337  0000              add [bx+si],al
00006339  006C6C            add [si+0x6c],ch
0000633C  FE                db 0xfe
0000633D  6C                insb
0000633E  6C                insb
0000633F  6C                insb
00006340  FE                db 0xfe
00006341  6C                insb
00006342  6C                insb
00006343  0000              add [bx+si],al
00006345  0000              add [bx+si],al
00006347  1818              sbb [bx+si],bl
00006349  7CC6              jl 0x6311
0000634B  C2C07C            ret 0x7cc0
0000634E  06                push es
0000634F  06                push es
00006350  86C6              xchg al,dh
00006352  7C18              jl 0x636c
00006354  1800              sbb [bx+si],al
00006356  0000              add [bx+si],al
00006358  0000              add [bx+si],al
0000635A  00C2              add dl,al
0000635C  C6                db 0xc6
0000635D  0C18              or al,0x18
0000635F  3060C6            xor [bx+si-0x3a],ah
00006362  8600              xchg al,[bx+si]
00006364  0000              add [bx+si],al
00006366  0000              add [bx+si],al
00006368  0038              add [bx+si],bh
0000636A  6C                insb
0000636B  6C                insb
0000636C  3876DC            cmp [bp-0x24],dh
0000636F  CC                int3
00006370  CC                int3
00006371  CC                int3
00006372  7600              jna 0x6374
00006374  0000              add [bx+si],al
00006376  0000              add [bx+si],al
00006378  3030              xor [bx+si],dh
0000637A  306000            xor [bx+si+0x0],ah
0000637D  0000              add [bx+si],al
0000637F  0000              add [bx+si],al
00006381  0000              add [bx+si],al
00006383  0000              add [bx+si],al
00006385  0000              add [bx+si],al
00006387  0000              add [bx+si],al
00006389  0C18              or al,0x18
0000638B  3030              xor [bx+si],dh
0000638D  3030              xor [bx+si],dh
0000638F  3030              xor [bx+si],dh
00006391  180C              sbb [si],cl
00006393  0000              add [bx+si],al
00006395  0000              add [bx+si],al
00006397  0000              add [bx+si],al
00006399  3018              xor [bx+si],bl
0000639B  0C0C              or al,0xc
0000639D  0C0C              or al,0xc
0000639F  0C0C              or al,0xc
000063A1  1830              sbb [bx+si],dh
000063A3  0000              add [bx+si],al
000063A5  0000              add [bx+si],al
000063A7  0000              add [bx+si],al
000063A9  0000              add [bx+si],al
000063AB  00663C            add [bp+0x3c],ah
000063AE  FF                db 0xff
000063AF  3C66              cmp al,0x66
000063B1  0000              add [bx+si],al
000063B3  0000              add [bx+si],al
000063B5  0000              add [bx+si],al
000063B7  0000              add [bx+si],al
000063B9  0000              add [bx+si],al
000063BB  0018              add [bx+si],bl
000063BD  187E18            sbb [bp+0x18],bh
000063C0  1800              sbb [bx+si],al
000063C2  0000              add [bx+si],al
000063C4  0000              add [bx+si],al
000063C6  0000              add [bx+si],al
000063C8  0000              add [bx+si],al
000063CA  0000              add [bx+si],al
000063CC  0000              add [bx+si],al
000063CE  0000              add [bx+si],al
000063D0  1818              sbb [bx+si],bl
000063D2  1830              sbb [bx+si],dh
000063D4  0000              add [bx+si],al
000063D6  0000              add [bx+si],al
000063D8  0000              add [bx+si],al
000063DA  0000              add [bx+si],al
000063DC  0000              add [bx+si],al
000063DE  FE00              inc byte [bx+si]
000063E0  0000              add [bx+si],al
000063E2  0000              add [bx+si],al
000063E4  0000              add [bx+si],al
000063E6  0000              add [bx+si],al
000063E8  0000              add [bx+si],al
000063EA  0000              add [bx+si],al
000063EC  0000              add [bx+si],al
000063EE  0000              add [bx+si],al
000063F0  0018              add [bx+si],bl
000063F2  1800              sbb [bx+si],al
000063F4  0000              add [bx+si],al
000063F6  0000              add [bx+si],al
000063F8  0000              add [bx+si],al
000063FA  0002              add [bp+si],al
000063FC  06                push es
000063FD  0C18              or al,0x18
000063FF  3060C0            xor [bx+si-0x40],ah
00006402  800000            add byte [bx+si],0x0
00006405  0000              add [bx+si],al
00006407  0000              add [bx+si],al
00006409  3C66              cmp al,0x66
0000640B  C3                ret
0000640C  C3                ret
0000640D  DBDB              fcmovnu st3
0000640F  C3                ret
00006410  C3                ret
00006411  663C00            o32 cmp al,0x0
00006414  0000              add [bx+si],al
00006416  0000              add [bx+si],al
00006418  0018              add [bx+si],bl
0000641A  387818            cmp [bx+si+0x18],bh
0000641D  1818              sbb [bx+si],bl
0000641F  1818              sbb [bx+si],bl
00006421  187E00            sbb [bp+0x0],bh
00006424  0000              add [bx+si],al
00006426  0000              add [bx+si],al
00006428  007CC6            add [si-0x3a],bh
0000642B  06                push es
0000642C  0C18              or al,0x18
0000642E  3060C0            xor [bx+si-0x40],ah
00006431  C6                db 0xc6
00006432  FE00              inc byte [bx+si]
00006434  0000              add [bx+si],al
00006436  0000              add [bx+si],al
00006438  007CC6            add [si-0x3a],bh
0000643B  06                push es
0000643C  06                push es
0000643D  3C06              cmp al,0x6
0000643F  06                push es
00006440  06                push es
00006441  C6                db 0xc6
00006442  7C00              jl 0x6444
00006444  0000              add [bx+si],al
00006446  0000              add [bx+si],al
00006448  000C              add [si],cl
0000644A  1C3C              sbb al,0x3c
0000644C  6C                insb
0000644D  CC                int3
0000644E  FE0C              dec byte [si]
00006450  0C0C              or al,0xc
00006452  1E                push ds
00006453  0000              add [bx+si],al
00006455  0000              add [bx+si],al
00006457  0000              add [bx+si],al
00006459  FEC0              inc al
0000645B  C0C0FC            rol al,0xfc
0000645E  06                push es
0000645F  06                push es
00006460  06                push es
00006461  C6                db 0xc6
00006462  7C00              jl 0x6464
00006464  0000              add [bx+si],al
00006466  0000              add [bx+si],al
00006468  0038              add [bx+si],bh
0000646A  60                pushaw
0000646B  C0C0FC            rol al,0xfc
0000646E  C6C6C6            mov dh,0xc6
00006471  C6                db 0xc6
00006472  7C00              jl 0x6474
00006474  0000              add [bx+si],al
00006476  0000              add [bx+si],al
00006478  00FE              add dh,bh
0000647A  C606060C18        mov byte [0xc06],0x18
0000647F  3030              xor [bx+si],dh
00006481  3030              xor [bx+si],dh
00006483  0000              add [bx+si],al
00006485  0000              add [bx+si],al
00006487  0000              add [bx+si],al
00006489  7CC6              jl 0x6451
0000648B  C6C67C            mov dh,0x7c
0000648E  C6C6C6            mov dh,0xc6
00006491  C6                db 0xc6
00006492  7C00              jl 0x6494
00006494  0000              add [bx+si],al
00006496  0000              add [bx+si],al
00006498  007CC6            add [si-0x3a],bh
0000649B  C6C67E            mov dh,0x7e
0000649E  06                push es
0000649F  06                push es
000064A0  06                push es
000064A1  0C78              or al,0x78
000064A3  0000              add [bx+si],al
000064A5  0000              add [bx+si],al
000064A7  0000              add [bx+si],al
000064A9  0000              add [bx+si],al
000064AB  1818              sbb [bx+si],bl
000064AD  0000              add [bx+si],al
000064AF  0018              add [bx+si],bl
000064B1  1800              sbb [bx+si],al
000064B3  0000              add [bx+si],al
000064B5  0000              add [bx+si],al
000064B7  0000              add [bx+si],al
000064B9  0000              add [bx+si],al
000064BB  1818              sbb [bx+si],bl
000064BD  0000              add [bx+si],al
000064BF  0018              add [bx+si],bl
000064C1  1830              sbb [bx+si],dh
000064C3  0000              add [bx+si],al
000064C5  0000              add [bx+si],al
000064C7  0000              add [bx+si],al
000064C9  00060C18          add [0x180c],al
000064CD  306030            xor [bx+si+0x30],ah
000064D0  180C              sbb [si],cl
000064D2  06                push es
000064D3  0000              add [bx+si],al
000064D5  0000              add [bx+si],al
000064D7  0000              add [bx+si],al
000064D9  0000              add [bx+si],al
000064DB  007E00            add [bp+0x0],bh
000064DE  007E00            add [bp+0x0],bh
000064E1  0000              add [bx+si],al
000064E3  0000              add [bx+si],al
000064E5  0000              add [bx+si],al
000064E7  0000              add [bx+si],al
000064E9  006030            add [bx+si+0x30],ah
000064EC  180C              sbb [si],cl
000064EE  06                push es
000064EF  0C18              or al,0x18
000064F1  306000            xor [bx+si+0x0],ah
000064F4  0000              add [bx+si],al
000064F6  0000              add [bx+si],al
000064F8  007CC6            add [si-0x3a],bh
000064FB  C6                db 0xc6
000064FC  0C18              or al,0x18
000064FE  1818              sbb [bx+si],bl
00006500  0018              add [bx+si],bl
00006502  1800              sbb [bx+si],al
00006504  0000              add [bx+si],al
00006506  0000              add [bx+si],al
00006508  0000              add [bx+si],al
0000650A  7CC6              jl 0x64d2
0000650C  C6                db 0xc6
0000650D  DE                db 0xde
0000650E  DE                db 0xde
0000650F  DE                db 0xde
00006510  DCC0              fadd to st0
00006512  7C00              jl 0x6514
00006514  0000              add [bx+si],al
00006516  0000              add [bx+si],al
00006518  0010              add [bx+si],dl
0000651A  386CC6            cmp [si-0x3a],ch
0000651D  C6                db 0xc6
0000651E  FEC6              inc dh
00006520  C6C6C6            mov dh,0xc6
00006523  0000              add [bx+si],al
00006525  0000              add [bx+si],al
00006527  0000              add [bx+si],al
00006529  FC                cld
0000652A  6666667C66        o32 jl 0x6595
0000652F  666666FC          o32 cld
00006533  0000              add [bx+si],al
00006535  0000              add [bx+si],al
00006537  0000              add [bx+si],al
00006539  3C66              cmp al,0x66
0000653B  C2C0C0            ret 0xc0c0
0000653E  C0C0C2            rol al,0xc2
00006541  663C00            o32 cmp al,0x0
00006544  0000              add [bx+si],al
00006546  0000              add [bx+si],al
00006548  00F8              add al,bh
0000654A  6C                insb
0000654B  6666666666666C    o32 insb
00006552  F8                clc
00006553  0000              add [bx+si],al
00006555  0000              add [bx+si],al
00006557  0000              add [bx+si],al
00006559  FE                db 0xfe
0000655A  66626878          bound ebp,[bx+si+0x78]
0000655E  686062            push word 0x6260
00006561  66FE00            o32 inc byte [bx+si]
00006564  0000              add [bx+si],al
00006566  0000              add [bx+si],al
00006568  00FE              add dh,bh
0000656A  66626878          bound ebp,[bx+si+0x78]
0000656E  686060            push word 0x6060
00006571  60                pushaw
00006572  F00000            lock add [bx+si],al
00006575  0000              add [bx+si],al
00006577  0000              add [bx+si],al
00006579  3C66              cmp al,0x66
0000657B  C2C0C0            ret 0xc0c0
0000657E  DEC6              faddp st6
00006580  C6                db 0xc6
00006581  663A00            o32 cmp al,[bx+si]
00006584  0000              add [bx+si],al
00006586  0000              add [bx+si],al
00006588  00C6              add dh,al
0000658A  C6C6C6            mov dh,0xc6
0000658D  FEC6              inc dh
0000658F  C6C6C6            mov dh,0xc6
00006592  C60000            mov byte [bx+si],0x0
00006595  0000              add [bx+si],al
00006597  0000              add [bx+si],al
00006599  3C18              cmp al,0x18
0000659B  1818              sbb [bx+si],bl
0000659D  1818              sbb [bx+si],bl
0000659F  1818              sbb [bx+si],bl
000065A1  183C              sbb [si],bh
000065A3  0000              add [bx+si],al
000065A5  0000              add [bx+si],al
000065A7  0000              add [bx+si],al
000065A9  1E                push ds
000065AA  0C0C              or al,0xc
000065AC  0C0C              or al,0xc
000065AE  0CCC              or al,0xcc
000065B0  CC                int3
000065B1  CC                int3
000065B2  7800              js 0x65b4
000065B4  0000              add [bx+si],al
000065B6  0000              add [bx+si],al
000065B8  00E6              add dh,ah
000065BA  66666C            o32 insb
000065BD  7878              js 0x6637
000065BF  6C                insb
000065C0  6666E600          o32 out 0x0,al
000065C4  0000              add [bx+si],al
000065C6  0000              add [bx+si],al
000065C8  00F0              add al,dh
000065CA  60                pushaw
000065CB  60                pushaw
000065CC  60                pushaw
000065CD  60                pushaw
000065CE  60                pushaw
000065CF  60                pushaw
000065D0  6266FE            bound sp,[bp-0x2]
000065D3  0000              add [bx+si],al
000065D5  0000              add [bx+si],al
000065D7  0000              add [bx+si],al
000065D9  C3                ret
000065DA  E7FF              out 0xff,ax
000065DC  FF                db 0xff
000065DD  DBC3              fcmovnb st3
000065DF  C3                ret
000065E0  C3                ret
000065E1  C3                ret
000065E2  C3                ret
000065E3  0000              add [bx+si],al
000065E5  0000              add [bx+si],al
000065E7  0000              add [bx+si],al
000065E9  C6                db 0xc6
000065EA  E6F6              out 0xf6,al
000065EC  FE                db 0xfe
000065ED  DECE              fmulp st6
000065EF  C6C6C6            mov dh,0xc6
000065F2  C60000            mov byte [bx+si],0x0
000065F5  0000              add [bx+si],al
000065F7  0000              add [bx+si],al
000065F9  7CC6              jl 0x65c1
000065FB  C6C6C6            mov dh,0xc6
000065FE  C6C6C6            mov dh,0xc6
00006601  C6                db 0xc6
00006602  7C00              jl 0x6604
00006604  0000              add [bx+si],al
00006606  0000              add [bx+si],al
00006608  00FC              add ah,bh
0000660A  6666667C60        o32 jl 0x666f
0000660F  60                pushaw
00006610  60                pushaw
00006611  60                pushaw
00006612  F00000            lock add [bx+si],al
00006615  0000              add [bx+si],al
00006617  0000              add [bx+si],al
00006619  7CC6              jl 0x65e1
0000661B  C6C6C6            mov dh,0xc6
0000661E  C6C6D6            mov dh,0xd6
00006621  DE7C0C            fidivr word [si+0xc]
00006624  0E                push cs
00006625  0000              add [bx+si],al
00006627  0000              add [bx+si],al
00006629  FC                cld
0000662A  6666667C6C        o32 jl 0x669b
0000662F  666666E600        o32 out 0x0,al
00006634  0000              add [bx+si],al
00006636  0000              add [bx+si],al
00006638  007CC6            add [si-0x3a],bh
0000663B  C6                db 0xc6
0000663C  60                pushaw
0000663D  380C              cmp [si],cl
0000663F  06                push es
00006640  C6C67C            mov dh,0x7c
00006643  0000              add [bx+si],al
00006645  0000              add [bx+si],al
00006647  0000              add [bx+si],al
00006649  FF                db 0xff
0000664A  DB991818          fistp dword [bx+di+0x1818]
0000664E  1818              sbb [bx+si],bl
00006650  1818              sbb [bx+si],bl
00006652  3C00              cmp al,0x0
00006654  0000              add [bx+si],al
00006656  0000              add [bx+si],al
00006658  00C6              add dh,al
0000665A  C6C6C6            mov dh,0xc6
0000665D  C6C6C6            mov dh,0xc6
00006660  C6C67C            mov dh,0x7c
00006663  0000              add [bx+si],al
00006665  0000              add [bx+si],al
00006667  0000              add [bx+si],al
00006669  C3                ret
0000666A  C3                ret
0000666B  C3                ret
0000666C  C3                ret
0000666D  C3                ret
0000666E  C3                ret
0000666F  C3                ret
00006670  663C18            o32 cmp al,0x18
00006673  0000              add [bx+si],al
00006675  0000              add [bx+si],al
00006677  0000              add [bx+si],al
00006679  C3                ret
0000667A  C3                ret
0000667B  C3                ret
0000667C  C3                ret
0000667D  C3                ret
0000667E  DBDB              fcmovnu st3
00006680  FF6666            jmp word near [bp+0x66]
00006683  0000              add [bx+si],al
00006685  0000              add [bx+si],al
00006687  0000              add [bx+si],al
00006689  C3                ret
0000668A  C3                ret
0000668B  663C18            o32 cmp al,0x18
0000668E  183C              sbb [si],bh
00006690  66C3              o32 ret
00006692  C3                ret
00006693  0000              add [bx+si],al
00006695  0000              add [bx+si],al
00006697  0000              add [bx+si],al
00006699  C3                ret
0000669A  C3                ret
0000669B  C3                ret
0000669C  663C18            o32 cmp al,0x18
0000669F  1818              sbb [bx+si],bl
000066A1  183C              sbb [si],bh
000066A3  0000              add [bx+si],al
000066A5  0000              add [bx+si],al
000066A7  0000              add [bx+si],al
000066A9  FFC3              inc bx
000066AB  860C              xchg cl,[si]
000066AD  1830              sbb [bx+si],dh
000066AF  60                pushaw
000066B0  C1C3FF            rol bx,0xff
000066B3  0000              add [bx+si],al
000066B5  0000              add [bx+si],al
000066B7  0000              add [bx+si],al
000066B9  3C30              cmp al,0x30
000066BB  3030              xor [bx+si],dh
000066BD  3030              xor [bx+si],dh
000066BF  3030              xor [bx+si],dh
000066C1  303C              xor [si],bh
000066C3  0000              add [bx+si],al
000066C5  0000              add [bx+si],al
000066C7  0000              add [bx+si],al
000066C9  0080C0E0          add [bx+si-0x1f40],al
000066CD  7038              jo 0x6707
000066CF  1C0E              sbb al,0xe
000066D1  06                push es
000066D2  0200              add al,[bx+si]
000066D4  0000              add [bx+si],al
000066D6  0000              add [bx+si],al
000066D8  003C              add [si],bh
000066DA  0C0C              or al,0xc
000066DC  0C0C              or al,0xc
000066DE  0C0C              or al,0xc
000066E0  0C0C              or al,0xc
000066E2  3C00              cmp al,0x0
000066E4  0000              add [bx+si],al
000066E6  0010              add [bx+si],dl
000066E8  386CC6            cmp [si-0x3a],ch
000066EB  0000              add [bx+si],al
000066ED  0000              add [bx+si],al
000066EF  0000              add [bx+si],al
000066F1  0000              add [bx+si],al
000066F3  0000              add [bx+si],al
000066F5  0000              add [bx+si],al
000066F7  0000              add [bx+si],al
000066F9  0000              add [bx+si],al
000066FB  0000              add [bx+si],al
000066FD  0000              add [bx+si],al
000066FF  0000              add [bx+si],al
00006701  0000              add [bx+si],al
00006703  00FF              add bh,bh
00006705  0000              add [bx+si],al
00006707  3030              xor [bx+si],dh
00006709  1800              sbb [bx+si],al
0000670B  0000              add [bx+si],al
0000670D  0000              add [bx+si],al
0000670F  0000              add [bx+si],al
00006711  0000              add [bx+si],al
00006713  0000              add [bx+si],al
00006715  0000              add [bx+si],al
00006717  0000              add [bx+si],al
00006719  0000              add [bx+si],al
0000671B  00780C            add [bx+si+0xc],bh
0000671E  7CCC              jl 0x66ec
00006720  CC                int3
00006721  CC                int3
00006722  7600              jna 0x6724
00006724  0000              add [bx+si],al
00006726  0000              add [bx+si],al
00006728  00E0              add al,ah
0000672A  60                pushaw
0000672B  60                pushaw
0000672C  786C              js 0x679a
0000672E  666666667C00      o32 jl 0x6734
00006734  0000              add [bx+si],al
00006736  0000              add [bx+si],al
00006738  0000              add [bx+si],al
0000673A  0000              add [bx+si],al
0000673C  7CC6              jl 0x6704
0000673E  C0C0C0            rol al,0xc0
00006741  C6                db 0xc6
00006742  7C00              jl 0x6744
00006744  0000              add [bx+si],al
00006746  0000              add [bx+si],al
00006748  001C              add [si],bl
0000674A  0C0C              or al,0xc
0000674C  3C6C              cmp al,0x6c
0000674E  CC                int3
0000674F  CC                int3
00006750  CC                int3
00006751  CC                int3
00006752  7600              jna 0x6754
00006754  0000              add [bx+si],al
00006756  0000              add [bx+si],al
00006758  0000              add [bx+si],al
0000675A  0000              add [bx+si],al
0000675C  7CC6              jl 0x6724
0000675E  FEC0              inc al
00006760  C0C67C            rol dh,0x7c
00006763  0000              add [bx+si],al
00006765  0000              add [bx+si],al
00006767  0000              add [bx+si],al
00006769  386C64            cmp [si+0x64],ch
0000676C  60                pushaw
0000676D  F060              lock pushaw
0000676F  60                pushaw
00006770  60                pushaw
00006771  60                pushaw
00006772  F00000            lock add [bx+si],al
00006775  0000              add [bx+si],al
00006777  0000              add [bx+si],al
00006779  0000              add [bx+si],al
0000677B  0076CC            add [bp-0x34],dh
0000677E  CC                int3
0000677F  CC                int3
00006780  CC                int3
00006781  CC                int3
00006782  7C0C              jl 0x6790
00006784  CC                int3
00006785  7800              js 0x6787
00006787  0000              add [bx+si],al
00006789  E060              loopne 0x67eb
0000678B  60                pushaw
0000678C  6C                insb
0000678D  7666              jna 0x67f5
0000678F  666666E600        o32 out 0x0,al
00006794  0000              add [bx+si],al
00006796  0000              add [bx+si],al
00006798  0018              add [bx+si],bl
0000679A  1800              sbb [bx+si],al
0000679C  3818              cmp [bx+si],bl
0000679E  1818              sbb [bx+si],bl
000067A0  1818              sbb [bx+si],bl
000067A2  3C00              cmp al,0x0
000067A4  0000              add [bx+si],al
000067A6  0000              add [bx+si],al
000067A8  00060600          add [0x6],al
000067AC  0E                push cs
000067AD  06                push es
000067AE  06                push es
000067AF  06                push es
000067B0  06                push es
000067B1  06                push es
000067B2  06                push es
000067B3  66663C00          o32 cmp al,0x0
000067B7  0000              add [bx+si],al
000067B9  E060              loopne 0x681b
000067BB  60                pushaw
000067BC  666C              o32 insb
000067BE  7878              js 0x6838
000067C0  6C                insb
000067C1  66E600            o32 out 0x0,al
000067C4  0000              add [bx+si],al
000067C6  0000              add [bx+si],al
000067C8  0038              add [bx+si],bh
000067CA  1818              sbb [bx+si],bl
000067CC  1818              sbb [bx+si],bl
000067CE  1818              sbb [bx+si],bl
000067D0  1818              sbb [bx+si],bl
000067D2  3C00              cmp al,0x0
000067D4  0000              add [bx+si],al
000067D6  0000              add [bx+si],al
000067D8  0000              add [bx+si],al
000067DA  0000              add [bx+si],al
000067DC  E6FF              out 0xff,al
000067DE  DBDB              fcmovnu st3
000067E0  DBDB              fcmovnu st3
000067E2  DB00              fild dword [bx+si]
000067E4  0000              add [bx+si],al
000067E6  0000              add [bx+si],al
000067E8  0000              add [bx+si],al
000067EA  0000              add [bx+si],al
000067EC  DC6666            fsub qword [bp+0x66]
000067EF  666666660000      o32 add [bx+si],al
000067F5  0000              add [bx+si],al
000067F7  0000              add [bx+si],al
000067F9  0000              add [bx+si],al
000067FB  007CC6            add [si-0x3a],bh
000067FE  C6C6C6            mov dh,0xc6
00006801  C6                db 0xc6
00006802  7C00              jl 0x6804
00006804  0000              add [bx+si],al
00006806  0000              add [bx+si],al
00006808  0000              add [bx+si],al
0000680A  0000              add [bx+si],al
0000680C  DC6666            fsub qword [bp+0x66]
0000680F  6666667C60        o32 jl 0x6874
00006814  60                pushaw
00006815  F00000            lock add [bx+si],al
00006818  0000              add [bx+si],al
0000681A  0000              add [bx+si],al
0000681C  76CC              jna 0x67ea
0000681E  CC                int3
0000681F  CC                int3
00006820  CC                int3
00006821  CC                int3
00006822  7C0C              jl 0x6830
00006824  0C1E              or al,0x1e
00006826  0000              add [bx+si],al
00006828  0000              add [bx+si],al
0000682A  0000              add [bx+si],al
0000682C  DC7666            fdiv qword [bp+0x66]
0000682F  60                pushaw
00006830  60                pushaw
00006831  60                pushaw
00006832  F00000            lock add [bx+si],al
00006835  0000              add [bx+si],al
00006837  0000              add [bx+si],al
00006839  0000              add [bx+si],al
0000683B  007CC6            add [si-0x3a],bh
0000683E  60                pushaw
0000683F  380C              cmp [si],cl
00006841  C6                db 0xc6
00006842  7C00              jl 0x6844
00006844  0000              add [bx+si],al
00006846  0000              add [bx+si],al
00006848  0010              add [bx+si],dl
0000684A  3030              xor [bx+si],dh
0000684C  FC                cld
0000684D  3030              xor [bx+si],dh
0000684F  3030              xor [bx+si],dh
00006851  361C00            ss sbb al,0x0
00006854  0000              add [bx+si],al
00006856  0000              add [bx+si],al
00006858  0000              add [bx+si],al
0000685A  0000              add [bx+si],al
0000685C  CC                int3
0000685D  CC                int3
0000685E  CC                int3
0000685F  CC                int3
00006860  CC                int3
00006861  CC                int3
00006862  7600              jna 0x6864
00006864  0000              add [bx+si],al
00006866  0000              add [bx+si],al
00006868  0000              add [bx+si],al
0000686A  0000              add [bx+si],al
0000686C  C3                ret
0000686D  C3                ret
0000686E  C3                ret
0000686F  C3                ret
00006870  663C18            o32 cmp al,0x18
00006873  0000              add [bx+si],al
00006875  0000              add [bx+si],al
00006877  0000              add [bx+si],al
00006879  0000              add [bx+si],al
0000687B  00C3              add bl,al
0000687D  C3                ret
0000687E  C3                ret
0000687F  DBDB              fcmovnu st3
00006881  FF6600            jmp word near [bp+0x0]
00006884  0000              add [bx+si],al
00006886  0000              add [bx+si],al
00006888  0000              add [bx+si],al
0000688A  0000              add [bx+si],al
0000688C  C3                ret
0000688D  663C18            o32 cmp al,0x18
00006890  3C66              cmp al,0x66
00006892  C3                ret
00006893  0000              add [bx+si],al
00006895  0000              add [bx+si],al
00006897  0000              add [bx+si],al
00006899  0000              add [bx+si],al
0000689B  00C6              add dh,al
0000689D  C6C6C6            mov dh,0xc6
000068A0  C6C67E            mov dh,0x7e
000068A3  06                push es
000068A4  0CF8              or al,0xf8
000068A6  0000              add [bx+si],al
000068A8  0000              add [bx+si],al
000068AA  0000              add [bx+si],al
000068AC  FECC              dec ah
000068AE  1830              sbb [bx+si],dh
000068B0  60                pushaw
000068B1  C6                db 0xc6
000068B2  FE00              inc byte [bx+si]
000068B4  0000              add [bx+si],al
000068B6  0000              add [bx+si],al
000068B8  000E1818          add [0x1818],cl
000068BC  187018            sbb [bx+si+0x18],dh
000068BF  1818              sbb [bx+si],bl
000068C1  180E0000          sbb [0x0],cl
000068C5  0000              add [bx+si],al
000068C7  0000              add [bx+si],al
000068C9  1818              sbb [bx+si],bl
000068CB  1818              sbb [bx+si],bl
000068CD  0018              add [bx+si],bl
000068CF  1818              sbb [bx+si],bl
000068D1  1818              sbb [bx+si],bl
000068D3  0000              add [bx+si],al
000068D5  0000              add [bx+si],al
000068D7  0000              add [bx+si],al
000068D9  7018              jo 0x68f3
000068DB  1818              sbb [bx+si],bl
000068DD  0E                push cs
000068DE  1818              sbb [bx+si],bl
000068E0  1818              sbb [bx+si],bl
000068E2  7000              jo 0x68e4
000068E4  0000              add [bx+si],al
000068E6  0000              add [bx+si],al
000068E8  0076DC            add [bp-0x24],dh
000068EB  0000              add [bx+si],al
000068ED  0000              add [bx+si],al
000068EF  0000              add [bx+si],al
000068F1  0000              add [bx+si],al
000068F3  0000              add [bx+si],al
000068F5  0000              add [bx+si],al
000068F7  0000              add [bx+si],al
000068F9  0000              add [bx+si],al
000068FB  1038              adc [bx+si],bh
000068FD  6C                insb
000068FE  C6C6C6            mov dh,0xc6
00006901  FE00              inc byte [bx+si]
00006903  0000              add [bx+si],al
00006905  0000              add [bx+si],al
00006907  0000              add [bx+si],al
00006909  3C66              cmp al,0x66
0000690B  C2C0C0            ret 0xc0c0
0000690E  C0C266            rol dl,0x66
00006911  3C0C              cmp al,0xc
00006913  06                push es
00006914  7C00              jl 0x6916
00006916  0000              add [bx+si],al
00006918  00CC              add ah,cl
0000691A  0000              add [bx+si],al
0000691C  CC                int3
0000691D  CC                int3
0000691E  CC                int3
0000691F  CC                int3
00006920  CC                int3
00006921  CC                int3
00006922  7600              jna 0x6924
00006924  0000              add [bx+si],al
00006926  0000              add [bx+si],al
00006928  0C18              or al,0x18
0000692A  3000              xor [bx+si],al
0000692C  7CC6              jl 0x68f4
0000692E  FEC0              inc al
00006930  C0C67C            rol dh,0x7c
00006933  0000              add [bx+si],al
00006935  0000              add [bx+si],al
00006937  0010              add [bx+si],dl
00006939  386C00            cmp [si+0x0],ch
0000693C  780C              js 0x694a
0000693E  7CCC              jl 0x690c
00006940  CC                int3
00006941  CC                int3
00006942  7600              jna 0x6944
00006944  0000              add [bx+si],al
00006946  0000              add [bx+si],al
00006948  00CC              add ah,cl
0000694A  0000              add [bx+si],al
0000694C  780C              js 0x695a
0000694E  7CCC              jl 0x691c
00006950  CC                int3
00006951  CC                int3
00006952  7600              jna 0x6954
00006954  0000              add [bx+si],al
00006956  0000              add [bx+si],al
00006958  60                pushaw
00006959  3018              xor [bx+si],bl
0000695B  00780C            add [bx+si+0xc],bh
0000695E  7CCC              jl 0x692c
00006960  CC                int3
00006961  CC                int3
00006962  7600              jna 0x6964
00006964  0000              add [bx+si],al
00006966  0000              add [bx+si],al
00006968  386C38            cmp [si+0x38],ch
0000696B  00780C            add [bx+si+0xc],bh
0000696E  7CCC              jl 0x693c
00006970  CC                int3
00006971  CC                int3
00006972  7600              jna 0x6974
00006974  0000              add [bx+si],al
00006976  0000              add [bx+si],al
00006978  0000              add [bx+si],al
0000697A  003C              add [si],bh
0000697C  6660              pushad
0000697E  60                pushaw
0000697F  663C0C            o32 cmp al,0xc
00006982  06                push es
00006983  3C00              cmp al,0x0
00006985  0000              add [bx+si],al
00006987  0010              add [bx+si],dl
00006989  386C00            cmp [si+0x0],ch
0000698C  7CC6              jl 0x6954
0000698E  FEC0              inc al
00006990  C0C67C            rol dh,0x7c
00006993  0000              add [bx+si],al
00006995  0000              add [bx+si],al
00006997  0000              add [bx+si],al
00006999  C60000            mov byte [bx+si],0x0
0000699C  7CC6              jl 0x6964
0000699E  FEC0              inc al
000069A0  C0C67C            rol dh,0x7c
000069A3  0000              add [bx+si],al
000069A5  0000              add [bx+si],al
000069A7  006030            add [bx+si+0x30],ah
000069AA  1800              sbb [bx+si],al
000069AC  7CC6              jl 0x6974
000069AE  FEC0              inc al
000069B0  C0C67C            rol dh,0x7c
000069B3  0000              add [bx+si],al
000069B5  0000              add [bx+si],al
000069B7  0000              add [bx+si],al
000069B9  660000            o32 add [bx+si],al
000069BC  3818              cmp [bx+si],bl
000069BE  1818              sbb [bx+si],bl
000069C0  1818              sbb [bx+si],bl
000069C2  3C00              cmp al,0x0
000069C4  0000              add [bx+si],al
000069C6  0000              add [bx+si],al
000069C8  183C              sbb [si],bh
000069CA  660038            o32 add [bx+si],bh
000069CD  1818              sbb [bx+si],bl
000069CF  1818              sbb [bx+si],bl
000069D1  183C              sbb [si],bh
000069D3  0000              add [bx+si],al
000069D5  0000              add [bx+si],al
000069D7  006030            add [bx+si+0x30],ah
000069DA  1800              sbb [bx+si],al
000069DC  3818              cmp [bx+si],bl
000069DE  1818              sbb [bx+si],bl
000069E0  1818              sbb [bx+si],bl
000069E2  3C00              cmp al,0x0
000069E4  0000              add [bx+si],al
000069E6  0000              add [bx+si],al
000069E8  C60010            mov byte [bx+si],0x10
000069EB  386CC6            cmp [si-0x3a],ch
000069EE  C6                db 0xc6
000069EF  FEC6              inc dh
000069F1  C6C600            mov dh,0x0
000069F4  0000              add [bx+si],al
000069F6  0038              add [bx+si],bh
000069F8  6C                insb
000069F9  3800              cmp [bx+si],al
000069FB  386CC6            cmp [si-0x3a],ch
000069FE  C6                db 0xc6
000069FF  FEC6              inc dh
00006A01  C6C600            mov dh,0x0
00006A04  0000              add [bx+si],al
00006A06  0018              add [bx+si],bl
00006A08  306000            xor [bx+si+0x0],ah
00006A0B  FE                db 0xfe
00006A0C  6660              pushad
00006A0E  7C60              jl 0x6a70
00006A10  60                pushaw
00006A11  66FE00            o32 inc byte [bx+si]
00006A14  0000              add [bx+si],al
00006A16  0000              add [bx+si],al
00006A18  0000              add [bx+si],al
00006A1A  0000              add [bx+si],al
00006A1C  6E                outsb
00006A1D  3B1B              cmp bx,[bp+di]
00006A1F  7ED8              jng 0x69f9
00006A21  DC7700            fdiv qword [bx+0x0]
00006A24  0000              add [bx+si],al
00006A26  0000              add [bx+si],al
00006A28  003E6CCC          add [0xcc6c],bh
00006A2C  CC                int3
00006A2D  FECC              dec ah
00006A2F  CC                int3
00006A30  CC                int3
00006A31  CC                int3
00006A32  CE                into
00006A33  0000              add [bx+si],al
00006A35  0000              add [bx+si],al
00006A37  0010              add [bx+si],dl
00006A39  386C00            cmp [si+0x0],ch
00006A3C  7CC6              jl 0x6a04
00006A3E  C6C6C6            mov dh,0xc6
00006A41  C6                db 0xc6
00006A42  7C00              jl 0x6a44
00006A44  0000              add [bx+si],al
00006A46  0000              add [bx+si],al
00006A48  00C6              add dh,al
00006A4A  0000              add [bx+si],al
00006A4C  7CC6              jl 0x6a14
00006A4E  C6C6C6            mov dh,0xc6
00006A51  C6                db 0xc6
00006A52  7C00              jl 0x6a54
00006A54  0000              add [bx+si],al
00006A56  0000              add [bx+si],al
00006A58  60                pushaw
00006A59  3018              xor [bx+si],bl
00006A5B  007CC6            add [si-0x3a],bh
00006A5E  C6C6C6            mov dh,0xc6
00006A61  C6                db 0xc6
00006A62  7C00              jl 0x6a64
00006A64  0000              add [bx+si],al
00006A66  0000              add [bx+si],al
00006A68  3078CC            xor [bx+si-0x34],bh
00006A6B  00CC              add ah,cl
00006A6D  CC                int3
00006A6E  CC                int3
00006A6F  CC                int3
00006A70  CC                int3
00006A71  CC                int3
00006A72  7600              jna 0x6a74
00006A74  0000              add [bx+si],al
00006A76  0000              add [bx+si],al
00006A78  60                pushaw
00006A79  3018              xor [bx+si],bl
00006A7B  00CC              add ah,cl
00006A7D  CC                int3
00006A7E  CC                int3
00006A7F  CC                int3
00006A80  CC                int3
00006A81  CC                int3
00006A82  7600              jna 0x6a84
00006A84  0000              add [bx+si],al
00006A86  0000              add [bx+si],al
00006A88  00C6              add dh,al
00006A8A  0000              add [bx+si],al
00006A8C  C6C6C6            mov dh,0xc6
00006A8F  C6C6C6            mov dh,0xc6
00006A92  7E06              jng 0x6a9a
00006A94  0C78              or al,0x78
00006A96  0000              add [bx+si],al
00006A98  C6007C            mov byte [bx+si],0x7c
00006A9B  C6C6C6            mov dh,0xc6
00006A9E  C6C6C6            mov dh,0xc6
00006AA1  C6                db 0xc6
00006AA2  7C00              jl 0x6aa4
00006AA4  0000              add [bx+si],al
00006AA6  0000              add [bx+si],al
00006AA8  C600C6            mov byte [bx+si],0xc6
00006AAB  C6C6C6            mov dh,0xc6
00006AAE  C6C6C6            mov dh,0xc6
00006AB1  C6                db 0xc6
00006AB2  7C00              jl 0x6ab4
00006AB4  0000              add [bx+si],al
00006AB6  0000              add [bx+si],al
00006AB8  1818              sbb [bx+si],bl
00006ABA  7EC3              jng 0x6a7f
00006ABC  C0C0C0            rol al,0xc0
00006ABF  C3                ret
00006AC0  7E18              jng 0x6ada
00006AC2  1800              sbb [bx+si],al
00006AC4  0000              add [bx+si],al
00006AC6  0000              add [bx+si],al
00006AC8  386C64            cmp [si+0x64],ch
00006ACB  60                pushaw
00006ACC  F060              lock pushaw
00006ACE  60                pushaw
00006ACF  60                pushaw
00006AD0  60                pushaw
00006AD1  E6FC              out 0xfc,al
00006AD3  0000              add [bx+si],al
00006AD5  0000              add [bx+si],al
00006AD7  0000              add [bx+si],al
00006AD9  C3                ret
00006ADA  663C18            o32 cmp al,0x18
00006ADD  FF18              call word far [bx+si]
00006ADF  FF18              call word far [bx+si]
00006AE1  1818              sbb [bx+si],bl
00006AE3  0000              add [bx+si],al
00006AE5  0000              add [bx+si],al
00006AE7  00FC              add ah,bh
00006AE9  66667C62          o32 jl 0x6b4f
00006AED  666F              outsd
00006AEF  666666F30000      rep o32 add [bx+si],al
00006AF5  0000              add [bx+si],al
00006AF7  000E1B18          add [0x181b],cl
00006AFB  1818              sbb [bx+si],bl
00006AFD  7E18              jng 0x6b17
00006AFF  1818              sbb [bx+si],bl
00006B01  1818              sbb [bx+si],bl
00006B03  D87000            fdiv dword [bx+si+0x0]
00006B06  0000              add [bx+si],al
00006B08  1830              sbb [bx+si],dh
00006B0A  60                pushaw
00006B0B  00780C            add [bx+si+0xc],bh
00006B0E  7CCC              jl 0x6adc
00006B10  CC                int3
00006B11  CC                int3
00006B12  7600              jna 0x6b14
00006B14  0000              add [bx+si],al
00006B16  0000              add [bx+si],al
00006B18  0C18              or al,0x18
00006B1A  3000              xor [bx+si],al
00006B1C  3818              cmp [bx+si],bl
00006B1E  1818              sbb [bx+si],bl
00006B20  1818              sbb [bx+si],bl
00006B22  3C00              cmp al,0x0
00006B24  0000              add [bx+si],al
00006B26  0000              add [bx+si],al
00006B28  1830              sbb [bx+si],dh
00006B2A  60                pushaw
00006B2B  007CC6            add [si-0x3a],bh
00006B2E  C6C6C6            mov dh,0xc6
00006B31  C6                db 0xc6
00006B32  7C00              jl 0x6b34
00006B34  0000              add [bx+si],al
00006B36  0000              add [bx+si],al
00006B38  1830              sbb [bx+si],dh
00006B3A  60                pushaw
00006B3B  00CC              add ah,cl
00006B3D  CC                int3
00006B3E  CC                int3
00006B3F  CC                int3
00006B40  CC                int3
00006B41  CC                int3
00006B42  7600              jna 0x6b44
00006B44  0000              add [bx+si],al
00006B46  0000              add [bx+si],al
00006B48  0076DC            add [bp-0x24],dh
00006B4B  00DC              add ah,bl
00006B4D  6666666666660000  o32 add [bx+si],al
00006B55  0000              add [bx+si],al
00006B57  76DC              jna 0x6b35
00006B59  00C6              add dh,al
00006B5B  E6F6              out 0xf6,al
00006B5D  FE                db 0xfe
00006B5E  DECE              fmulp st6
00006B60  C6C6C6            mov dh,0xc6
00006B63  0000              add [bx+si],al
00006B65  0000              add [bx+si],al
00006B67  003C              add [si],bh
00006B69  6C                insb
00006B6A  6C                insb
00006B6B  3E007E00          add [ds:bp+0x0],bh
00006B6F  0000              add [bx+si],al
00006B71  0000              add [bx+si],al
00006B73  0000              add [bx+si],al
00006B75  0000              add [bx+si],al
00006B77  0038              add [bx+si],bh
00006B79  6C                insb
00006B7A  6C                insb
00006B7B  3800              cmp [bx+si],al
00006B7D  7C00              jl 0x6b7f
00006B7F  0000              add [bx+si],al
00006B81  0000              add [bx+si],al
00006B83  0000              add [bx+si],al
00006B85  0000              add [bx+si],al
00006B87  0000              add [bx+si],al
00006B89  3030              xor [bx+si],dh
00006B8B  0030              add [bx+si],dh
00006B8D  3060C0            xor [bx+si-0x40],ah
00006B90  C6C67C            mov dh,0x7c
00006B93  0000              add [bx+si],al
00006B95  0000              add [bx+si],al
00006B97  0000              add [bx+si],al
00006B99  0000              add [bx+si],al
00006B9B  0000              add [bx+si],al
00006B9D  FEC0              inc al
00006B9F  C0C0C0            rol al,0xc0
00006BA2  0000              add [bx+si],al
00006BA4  0000              add [bx+si],al
00006BA6  0000              add [bx+si],al
00006BA8  0000              add [bx+si],al
00006BAA  0000              add [bx+si],al
00006BAC  00FE              add dh,bh
00006BAE  06                push es
00006BAF  06                push es
00006BB0  06                push es
00006BB1  06                push es
00006BB2  0000              add [bx+si],al
00006BB4  0000              add [bx+si],al
00006BB6  0000              add [bx+si],al
00006BB8  C0C0C2            rol al,0xc2
00006BBB  C6                db 0xc6
00006BBC  CC                int3
00006BBD  1830              sbb [bx+si],dh
00006BBF  60                pushaw
00006BC0  CE                into
00006BC1  9B06              wait push es
00006BC3  0C1F              or al,0x1f
00006BC5  0000              add [bx+si],al
00006BC7  00C0              add al,al
00006BC9  C0C2C6            rol dl,0xc6
00006BCC  CC                int3
00006BCD  1830              sbb [bx+si],dh
00006BCF  66CE              o32 into
00006BD1  96                xchg ax,si
00006BD2  3E06              ds push es
00006BD4  06                push es
00006BD5  0000              add [bx+si],al
00006BD7  0000              add [bx+si],al
00006BD9  1818              sbb [bx+si],bl
00006BDB  0018              add [bx+si],bl
00006BDD  1818              sbb [bx+si],bl
00006BDF  3C3C              cmp al,0x3c
00006BE1  3C18              cmp al,0x18
00006BE3  0000              add [bx+si],al
00006BE5  0000              add [bx+si],al
00006BE7  0000              add [bx+si],al
00006BE9  0000              add [bx+si],al
00006BEB  00366CD8          add [0xd86c],dh
00006BEF  6C                insb
00006BF0  360000            add [ss:bx+si],al
00006BF3  0000              add [bx+si],al
00006BF5  0000              add [bx+si],al
00006BF7  0000              add [bx+si],al
00006BF9  0000              add [bx+si],al
00006BFB  00D8              add al,bl
00006BFD  6C                insb
00006BFE  366C              ss insb
00006C00  D800              fadd dword [bx+si]
00006C02  0000              add [bx+si],al
00006C04  0000              add [bx+si],al
00006C06  0011              add [bx+di],dl
00006C08  44                inc sp
00006C09  114411            adc [si+0x11],ax
00006C0C  44                inc sp
00006C0D  114411            adc [si+0x11],ax
00006C10  44                inc sp
00006C11  114411            adc [si+0x11],ax
00006C14  44                inc sp
00006C15  114455            adc [si+0x55],ax
00006C18  AA                stosb
00006C19  55                push bp
00006C1A  AA                stosb
00006C1B  55                push bp
00006C1C  AA                stosb
00006C1D  55                push bp
00006C1E  AA                stosb
00006C1F  55                push bp
00006C20  AA                stosb
00006C21  55                push bp
00006C22  AA                stosb
00006C23  55                push bp
00006C24  AA                stosb
00006C25  55                push bp
00006C26  AA                stosb
00006C27  DD77DD            fnsave [bx-0x23]
00006C2A  77DD              ja 0x6c09
00006C2C  77DD              ja 0x6c0b
00006C2E  77DD              ja 0x6c0d
00006C30  77DD              ja 0x6c0f
00006C32  77DD              ja 0x6c11
00006C34  77DD              ja 0x6c13
00006C36  7718              ja 0x6c50
00006C38  1818              sbb [bx+si],bl
00006C3A  1818              sbb [bx+si],bl
00006C3C  1818              sbb [bx+si],bl
00006C3E  1818              sbb [bx+si],bl
00006C40  1818              sbb [bx+si],bl
00006C42  1818              sbb [bx+si],bl
00006C44  1818              sbb [bx+si],bl
00006C46  1818              sbb [bx+si],bl
00006C48  1818              sbb [bx+si],bl
00006C4A  1818              sbb [bx+si],bl
00006C4C  1818              sbb [bx+si],bl
00006C4E  F8                clc
00006C4F  1818              sbb [bx+si],bl
00006C51  1818              sbb [bx+si],bl
00006C53  1818              sbb [bx+si],bl
00006C55  1818              sbb [bx+si],bl
00006C57  1818              sbb [bx+si],bl
00006C59  1818              sbb [bx+si],bl
00006C5B  18F8              sbb al,bh
00006C5D  18F8              sbb al,bh
00006C5F  1818              sbb [bx+si],bl
00006C61  1818              sbb [bx+si],bl
00006C63  1818              sbb [bx+si],bl
00006C65  1818              sbb [bx+si],bl
00006C67  36363636363636F6  div byte [ss:0x3636]
         -363636
00006C72  36363636360000    add [ss:bx+si],al
00006C79  0000              add [bx+si],al
00006C7B  0000              add [bx+si],al
00006C7D  00FE              add dh,bh
00006C7F  3636363636363636  add [ss:bx+si],al
         -0000
00006C89  0000              add [bx+si],al
00006C8B  00F8              add al,bh
00006C8D  18F8              sbb al,bh
00006C8F  1818              sbb [bx+si],bl
00006C91  1818              sbb [bx+si],bl
00006C93  1818              sbb [bx+si],bl
00006C95  1818              sbb [bx+si],bl
00006C97  3636363636F606F6  test byte [ss:0x36f6],0x36
         -3636
00006CA1  3636363636363636  add [ss:bx+si],al
         -3636363636363636
         -3636363636360000
00006CB9  0000              add [bx+si],al
00006CBB  00FE              add dh,bh
00006CBD  06                push es
00006CBE  F6363636          div byte [0x3636]
00006CC2  3636363636363636  test byte [ss:0xfe],0x0
         -3636F606FE0000
00006CD1  0000              add [bx+si],al
00006CD3  0000              add [bx+si],al
00006CD5  0000              add [bx+si],al
00006CD7  36363636363636FE  inc byte [ss:bx+si]
         -00
00006CE0  0000              add [bx+si],al
00006CE2  0000              add [bx+si],al
00006CE4  0000              add [bx+si],al
00006CE6  0018              add [bx+si],bl
00006CE8  1818              sbb [bx+si],bl
00006CEA  1818              sbb [bx+si],bl
00006CEC  F8                clc
00006CED  18F8              sbb al,bh
00006CEF  0000              add [bx+si],al
00006CF1  0000              add [bx+si],al
00006CF3  0000              add [bx+si],al
00006CF5  0000              add [bx+si],al
00006CF7  0000              add [bx+si],al
00006CF9  0000              add [bx+si],al
00006CFB  0000              add [bx+si],al
00006CFD  00F8              add al,bh
00006CFF  1818              sbb [bx+si],bl
00006D01  1818              sbb [bx+si],bl
00006D03  1818              sbb [bx+si],bl
00006D05  1818              sbb [bx+si],bl
00006D07  1818              sbb [bx+si],bl
00006D09  1818              sbb [bx+si],bl
00006D0B  1818              sbb [bx+si],bl
00006D0D  181F              sbb [bx],bl
00006D0F  0000              add [bx+si],al
00006D11  0000              add [bx+si],al
00006D13  0000              add [bx+si],al
00006D15  0000              add [bx+si],al
00006D17  1818              sbb [bx+si],bl
00006D19  1818              sbb [bx+si],bl
00006D1B  1818              sbb [bx+si],bl
00006D1D  18FF              sbb bh,bh
00006D1F  0000              add [bx+si],al
00006D21  0000              add [bx+si],al
00006D23  0000              add [bx+si],al
00006D25  0000              add [bx+si],al
00006D27  0000              add [bx+si],al
00006D29  0000              add [bx+si],al
00006D2B  0000              add [bx+si],al
00006D2D  00FF              add bh,bh
00006D2F  1818              sbb [bx+si],bl
00006D31  1818              sbb [bx+si],bl
00006D33  1818              sbb [bx+si],bl
00006D35  1818              sbb [bx+si],bl
00006D37  1818              sbb [bx+si],bl
00006D39  1818              sbb [bx+si],bl
00006D3B  1818              sbb [bx+si],bl
00006D3D  181F              sbb [bx],bl
00006D3F  1818              sbb [bx+si],bl
00006D41  1818              sbb [bx+si],bl
00006D43  1818              sbb [bx+si],bl
00006D45  1818              sbb [bx+si],bl
00006D47  0000              add [bx+si],al
00006D49  0000              add [bx+si],al
00006D4B  0000              add [bx+si],al
00006D4D  00FF              add bh,bh
00006D4F  0000              add [bx+si],al
00006D51  0000              add [bx+si],al
00006D53  0000              add [bx+si],al
00006D55  0000              add [bx+si],al
00006D57  1818              sbb [bx+si],bl
00006D59  1818              sbb [bx+si],bl
00006D5B  1818              sbb [bx+si],bl
00006D5D  18FF              sbb bh,bh
00006D5F  1818              sbb [bx+si],bl
00006D61  1818              sbb [bx+si],bl
00006D63  1818              sbb [bx+si],bl
00006D65  1818              sbb [bx+si],bl
00006D67  1818              sbb [bx+si],bl
00006D69  1818              sbb [bx+si],bl
00006D6B  181F              sbb [bx],bl
00006D6D  181F              sbb [bx],bl
00006D6F  1818              sbb [bx+si],bl
00006D71  1818              sbb [bx+si],bl
00006D73  1818              sbb [bx+si],bl
00006D75  1818              sbb [bx+si],bl
00006D77  3636363636363637  ss aaa
00006D7F  3636363636363636  ss aaa
         -363636363637
00006D8D  303F              xor [bx],bh
00006D8F  0000              add [bx+si],al
00006D91  0000              add [bx+si],al
00006D93  0000              add [bx+si],al
00006D95  0000              add [bx+si],al
00006D97  0000              add [bx+si],al
00006D99  0000              add [bx+si],al
00006D9B  003F              add [bx],bh
00006D9D  3037              xor [bx],dh
00006D9F  3636363636363636  test word [ss:bx+si],0xff
         -3636363636F700FF
         -00
00006DB0  0000              add [bx+si],al
00006DB2  0000              add [bx+si],al
00006DB4  0000              add [bx+si],al
00006DB6  0000              add [bx+si],al
00006DB8  0000              add [bx+si],al
00006DBA  0000              add [bx+si],al
00006DBC  FF00              inc word [bx+si]
00006DBE  F7363636          div word [0x3636]
00006DC2  3636363636363636  ss aaa
         -363637
00006DCD  3037              xor [bx],dh
00006DCF  3636363636363636  add [ss:bx+si],al
         -0000
00006DD9  0000              add [bx+si],al
00006DDB  00FF              add bh,bh
00006DDD  00FF              add bh,bh
00006DDF  0000              add [bx+si],al
00006DE1  0000              add [bx+si],al
00006DE3  0000              add [bx+si],al
00006DE5  0000              add [bx+si],al
00006DE7  3636363636F700F7  test word [ss:bx+si],0x36f7
         -36
00006DF0  3636363636363618  sbb [ss:bx+si],bl
         -18
00006DF9  1818              sbb [bx+si],bl
00006DFB  18FF              sbb bh,bh
00006DFD  00FF              add bh,bh
00006DFF  0000              add [bx+si],al
00006E01  0000              add [bx+si],al
00006E03  0000              add [bx+si],al
00006E05  0000              add [bx+si],al
00006E07  36363636363636FF  inc word [ss:bx+si]
         -00
00006E10  0000              add [bx+si],al
00006E12  0000              add [bx+si],al
00006E14  0000              add [bx+si],al
00006E16  0000              add [bx+si],al
00006E18  0000              add [bx+si],al
00006E1A  0000              add [bx+si],al
00006E1C  FF00              inc word [bx+si]
00006E1E  FF18              call word far [bx+si]
00006E20  1818              sbb [bx+si],bl
00006E22  1818              sbb [bx+si],bl
00006E24  1818              sbb [bx+si],bl
00006E26  1800              sbb [bx+si],al
00006E28  0000              add [bx+si],al
00006E2A  0000              add [bx+si],al
00006E2C  0000              add [bx+si],al
00006E2E  FF363636          push word [0x3636]
00006E32  3636363636363636  ss aas
         -363636363F
00006E3F  0000              add [bx+si],al
00006E41  0000              add [bx+si],al
00006E43  0000              add [bx+si],al
00006E45  0000              add [bx+si],al
00006E47  1818              sbb [bx+si],bl
00006E49  1818              sbb [bx+si],bl
00006E4B  181F              sbb [bx],bl
00006E4D  181F              sbb [bx],bl
00006E4F  0000              add [bx+si],al
00006E51  0000              add [bx+si],al
00006E53  0000              add [bx+si],al
00006E55  0000              add [bx+si],al
00006E57  0000              add [bx+si],al
00006E59  0000              add [bx+si],al
00006E5B  001F              add [bx],bl
00006E5D  181F              sbb [bx],bl
00006E5F  1818              sbb [bx+si],bl
00006E61  1818              sbb [bx+si],bl
00006E63  1818              sbb [bx+si],bl
00006E65  1818              sbb [bx+si],bl
00006E67  0000              add [bx+si],al
00006E69  0000              add [bx+si],al
00006E6B  0000              add [bx+si],al
00006E6D  003F              add [bx],bh
00006E6F  3636363636363636  push word [ss:0x3636]
         -36363636363636FF
         -363636
00006E82  36363636361818    sbb [ss:bx+si],bl
00006E89  1818              sbb [bx+si],bl
00006E8B  18FF              sbb bh,bh
00006E8D  18FF              sbb bh,bh
00006E8F  1818              sbb [bx+si],bl
00006E91  1818              sbb [bx+si],bl
00006E93  1818              sbb [bx+si],bl
00006E95  1818              sbb [bx+si],bl
00006E97  1818              sbb [bx+si],bl
00006E99  1818              sbb [bx+si],bl
00006E9B  1818              sbb [bx+si],bl
00006E9D  18F8              sbb al,bh
00006E9F  0000              add [bx+si],al
00006EA1  0000              add [bx+si],al
00006EA3  0000              add [bx+si],al
00006EA5  0000              add [bx+si],al
00006EA7  0000              add [bx+si],al
00006EA9  0000              add [bx+si],al
00006EAB  0000              add [bx+si],al
00006EAD  001F              add [bx],bl
00006EAF  1818              sbb [bx+si],bl
00006EB1  1818              sbb [bx+si],bl
00006EB3  1818              sbb [bx+si],bl
00006EB5  1818              sbb [bx+si],bl
00006EB7  FF                db 0xff
00006EB8  FF                db 0xff
00006EB9  FF                db 0xff
00006EBA  FF                db 0xff
00006EBB  FF                db 0xff
00006EBC  FF                db 0xff
00006EBD  FF                db 0xff
00006EBE  FF                db 0xff
00006EBF  FF                db 0xff
00006EC0  FF                db 0xff
00006EC1  FF                db 0xff
00006EC2  FF                db 0xff
00006EC3  FF                db 0xff
00006EC4  FF                db 0xff
00006EC5  FF                db 0xff
00006EC6  FF00              inc word [bx+si]
00006EC8  0000              add [bx+si],al
00006ECA  0000              add [bx+si],al
00006ECC  0000              add [bx+si],al
00006ECE  FF                db 0xff
00006ECF  FF                db 0xff
00006ED0  FF                db 0xff
00006ED1  FF                db 0xff
00006ED2  FF                db 0xff
00006ED3  FF                db 0xff
00006ED4  FF                db 0xff
00006ED5  FF                db 0xff
00006ED6  FFF0              push ax
00006ED8  F0                lock
00006ED9  F0                lock
00006EDA  F0                lock
00006EDB  F0                lock
00006EDC  F0                lock
00006EDD  F0                lock
00006EDE  F0                lock
00006EDF  F0                lock
00006EE0  F0                lock
00006EE1  F0                lock
00006EE2  F0                lock
00006EE3  F0                lock
00006EE4  F0                lock
00006EE5  F0                lock
00006EE6  F0                lock
00006EE7  0F                db 0x0f
00006EE8  0F                db 0x0f
00006EE9  0F                db 0x0f
00006EEA  0F                db 0x0f
00006EEB  0F                db 0x0f
00006EEC  0F                db 0x0f
00006EED  0F                db 0x0f
00006EEE  0F                db 0x0f
00006EEF  0F                db 0x0f
00006EF0  0F                db 0x0f
00006EF1  0F                db 0x0f
00006EF2  0F                db 0x0f
00006EF3  0F                db 0x0f
00006EF4  0F                db 0x0f
00006EF5  0F                db 0x0f
00006EF6  0FFF              ud0
00006EF8  FF                db 0xff
00006EF9  FF                db 0xff
00006EFA  FF                db 0xff
00006EFB  FF                db 0xff
00006EFC  FF                db 0xff
00006EFD  FF00              inc word [bx+si]
00006EFF  0000              add [bx+si],al
00006F01  0000              add [bx+si],al
00006F03  0000              add [bx+si],al
00006F05  0000              add [bx+si],al
00006F07  0000              add [bx+si],al
00006F09  0000              add [bx+si],al
00006F0B  0076DC            add [bp-0x24],dh
00006F0E  D8D8              fcomp st0
00006F10  D8DC              fcomp st4
00006F12  7600              jna 0x6f14
00006F14  0000              add [bx+si],al
00006F16  0000              add [bx+si],al
00006F18  0078CC            add [bx+si-0x34],bh
00006F1B  CC                int3
00006F1C  CC                int3
00006F1D  D8CC              fmul st4
00006F1F  C6C6C6            mov dh,0xc6
00006F22  CC                int3
00006F23  0000              add [bx+si],al
00006F25  0000              add [bx+si],al
00006F27  0000              add [bx+si],al
00006F29  FEC6              inc dh
00006F2B  C6C0C0            mov al,0xc0
00006F2E  C0C0C0            rol al,0xc0
00006F31  C0C000            rol al,0x0
00006F34  0000              add [bx+si],al
00006F36  0000              add [bx+si],al
00006F38  0000              add [bx+si],al
00006F3A  00FE              add dh,bh
00006F3C  6C                insb
00006F3D  6C                insb
00006F3E  6C                insb
00006F3F  6C                insb
00006F40  6C                insb
00006F41  6C                insb
00006F42  6C                insb
00006F43  0000              add [bx+si],al
00006F45  0000              add [bx+si],al
00006F47  0000              add [bx+si],al
00006F49  00FE              add dh,bh
00006F4B  C6                db 0xc6
00006F4C  60                pushaw
00006F4D  3018              xor [bx+si],bl
00006F4F  3060C6            xor [bx+si-0x3a],ah
00006F52  FE00              inc byte [bx+si]
00006F54  0000              add [bx+si],al
00006F56  0000              add [bx+si],al
00006F58  0000              add [bx+si],al
00006F5A  0000              add [bx+si],al
00006F5C  7ED8              jng 0x6f36
00006F5E  D8D8              fcomp st0
00006F60  D8D8              fcomp st0
00006F62  7000              jo 0x6f64
00006F64  0000              add [bx+si],al
00006F66  0000              add [bx+si],al
00006F68  0000              add [bx+si],al
00006F6A  006666            add [bp+0x66],ah
00006F6D  6666667C60        o32 jl 0x6fd2
00006F72  60                pushaw
00006F73  C00000            rol byte [bx+si],0x0
00006F76  0000              add [bx+si],al
00006F78  0000              add [bx+si],al
00006F7A  0076DC            add [bp-0x24],dh
00006F7D  1818              sbb [bx+si],bl
00006F7F  1818              sbb [bx+si],bl
00006F81  1818              sbb [bx+si],bl
00006F83  0000              add [bx+si],al
00006F85  0000              add [bx+si],al
00006F87  0000              add [bx+si],al
00006F89  007E18            add [bp+0x18],bh
00006F8C  3C66              cmp al,0x66
00006F8E  66663C18          o32 cmp al,0x18
00006F92  7E00              jng 0x6f94
00006F94  0000              add [bx+si],al
00006F96  0000              add [bx+si],al
00006F98  0000              add [bx+si],al
00006F9A  386CC6            cmp [si-0x3a],ch
00006F9D  C6                db 0xc6
00006F9E  FEC6              inc dh
00006FA0  C6                db 0xc6
00006FA1  6C                insb
00006FA2  3800              cmp [bx+si],al
00006FA4  0000              add [bx+si],al
00006FA6  0000              add [bx+si],al
00006FA8  0038              add [bx+si],bh
00006FAA  6C                insb
00006FAB  C6C6C6            mov dh,0xc6
00006FAE  6C                insb
00006FAF  6C                insb
00006FB0  6C                insb
00006FB1  6C                insb
00006FB2  EE                out dx,al
00006FB3  0000              add [bx+si],al
00006FB5  0000              add [bx+si],al
00006FB7  0000              add [bx+si],al
00006FB9  1E                push ds
00006FBA  3018              xor [bx+si],bl
00006FBC  0C3E              or al,0x3e
00006FBE  666666663C00      o32 cmp al,0x0
00006FC4  0000              add [bx+si],al
00006FC6  0000              add [bx+si],al
00006FC8  0000              add [bx+si],al
00006FCA  0000              add [bx+si],al
00006FCC  7EDB              jng 0x6fa9
00006FCE  DBDB              fcmovnu st3
00006FD0  7E00              jng 0x6fd2
00006FD2  0000              add [bx+si],al
00006FD4  0000              add [bx+si],al
00006FD6  0000              add [bx+si],al
00006FD8  0000              add [bx+si],al
00006FDA  03067EDB          add ax,[0xdb7e]
00006FDE  DBF3              fcomi st3
00006FE0  7E60              jng 0x7042
00006FE2  C00000            rol byte [bx+si],0x0
00006FE5  0000              add [bx+si],al
00006FE7  0000              add [bx+si],al
00006FE9  1C30              sbb al,0x30
00006FEB  60                pushaw
00006FEC  60                pushaw
00006FED  7C60              jl 0x704f
00006FEF  60                pushaw
00006FF0  60                pushaw
00006FF1  301C              xor [si],bl
00006FF3  0000              add [bx+si],al
00006FF5  0000              add [bx+si],al
00006FF7  0000              add [bx+si],al
00006FF9  007CC6            add [si-0x3a],bh
00006FFC  C6C6C6            mov dh,0xc6
00006FFF  C6C6C6            mov dh,0xc6
00007002  C60000            mov byte [bx+si],0x0
00007005  0000              add [bx+si],al
00007007  0000              add [bx+si],al
00007009  0000              add [bx+si],al
0000700B  FE00              inc byte [bx+si]
0000700D  00FE              add dh,bh
0000700F  0000              add [bx+si],al
00007011  FE00              inc byte [bx+si]
00007013  0000              add [bx+si],al
00007015  0000              add [bx+si],al
00007017  0000              add [bx+si],al
00007019  0000              add [bx+si],al
0000701B  1818              sbb [bx+si],bl
0000701D  7E18              jng 0x7037
0000701F  1800              sbb [bx+si],al
00007021  00FF              add bh,bh
00007023  0000              add [bx+si],al
00007025  0000              add [bx+si],al
00007027  0000              add [bx+si],al
00007029  0030              add [bx+si],dh
0000702B  180C              sbb [si],cl
0000702D  06                push es
0000702E  0C18              or al,0x18
00007030  3000              xor [bx+si],al
00007032  7E00              jng 0x7034
00007034  0000              add [bx+si],al
00007036  0000              add [bx+si],al
00007038  0000              add [bx+si],al
0000703A  0C18              or al,0x18
0000703C  306030            xor [bx+si+0x30],ah
0000703F  180C              sbb [si],cl
00007041  007E00            add [bp+0x0],bh
00007044  0000              add [bx+si],al
00007046  0000              add [bx+si],al
00007048  000E1B1B          add [0x1b1b],cl
0000704C  1818              sbb [bx+si],bl
0000704E  1818              sbb [bx+si],bl
00007050  1818              sbb [bx+si],bl
00007052  1818              sbb [bx+si],bl
00007054  1818              sbb [bx+si],bl
00007056  1818              sbb [bx+si],bl
00007058  1818              sbb [bx+si],bl
0000705A  1818              sbb [bx+si],bl
0000705C  1818              sbb [bx+si],bl
0000705E  18D8              sbb al,bl
00007060  D8D8              fcomp st0
00007062  7000              jo 0x7064
00007064  0000              add [bx+si],al
00007066  0000              add [bx+si],al
00007068  0000              add [bx+si],al
0000706A  0018              add [bx+si],bl
0000706C  1800              sbb [bx+si],al
0000706E  7E00              jng 0x7070
00007070  1818              sbb [bx+si],bl
00007072  0000              add [bx+si],al
00007074  0000              add [bx+si],al
00007076  0000              add [bx+si],al
00007078  0000              add [bx+si],al
0000707A  0000              add [bx+si],al
0000707C  76DC              jna 0x705a
0000707E  0076DC            add [bp-0x24],dh
00007081  0000              add [bx+si],al
00007083  0000              add [bx+si],al
00007085  0000              add [bx+si],al
00007087  0038              add [bx+si],bh
00007089  6C                insb
0000708A  6C                insb
0000708B  3800              cmp [bx+si],al
0000708D  0000              add [bx+si],al
0000708F  0000              add [bx+si],al
00007091  0000              add [bx+si],al
00007093  0000              add [bx+si],al
00007095  0000              add [bx+si],al
00007097  0000              add [bx+si],al
00007099  0000              add [bx+si],al
0000709B  0000              add [bx+si],al
0000709D  0018              add [bx+si],bl
0000709F  1800              sbb [bx+si],al
000070A1  0000              add [bx+si],al
000070A3  0000              add [bx+si],al
000070A5  0000              add [bx+si],al
000070A7  0000              add [bx+si],al
000070A9  0000              add [bx+si],al
000070AB  0000              add [bx+si],al
000070AD  0000              add [bx+si],al
000070AF  1800              sbb [bx+si],al
000070B1  0000              add [bx+si],al
000070B3  0000              add [bx+si],al
000070B5  0000              add [bx+si],al
000070B7  000F              add [bx],cl
000070B9  0C0C              or al,0xc
000070BB  0C0C              or al,0xc
000070BD  0CEC              or al,0xec
000070BF  6C                insb
000070C0  6C                insb
000070C1  3C1C              cmp al,0x1c
000070C3  0000              add [bx+si],al
000070C5  0000              add [bx+si],al
000070C7  00D8              add al,bl
000070C9  6C                insb
000070CA  6C                insb
000070CB  6C                insb
000070CC  6C                insb
000070CD  6C                insb
000070CE  0000              add [bx+si],al
000070D0  0000              add [bx+si],al
000070D2  0000              add [bx+si],al
000070D4  0000              add [bx+si],al
000070D6  0000              add [bx+si],al
000070D8  70D8              jo 0x70b2
000070DA  3060C8            xor [bx+si-0x38],ah
000070DD  F8                clc
000070DE  0000              add [bx+si],al
000070E0  0000              add [bx+si],al
000070E2  0000              add [bx+si],al
000070E4  0000              add [bx+si],al
000070E6  0000              add [bx+si],al
000070E8  0000              add [bx+si],al
000070EA  007C7C            add [si+0x7c],bh
000070ED  7C7C              jl 0x716b
000070EF  7C7C              jl 0x716d
000070F1  7C00              jl 0x70f3
000070F3  0000              add [bx+si],al
000070F5  0000              add [bx+si],al
000070F7  0000              add [bx+si],al
000070F9  0000              add [bx+si],al
000070FB  0000              add [bx+si],al
000070FD  0000              add [bx+si],al
000070FF  0000              add [bx+si],al
00007101  0000              add [bx+si],al
00007103  0000              add [bx+si],al
00007105  0000              add [bx+si],al
00007107  1D0000            sbb ax,0x0
0000710A  0000              add [bx+si],al
0000710C  2466              and al,0x66
0000710E  FF6624            jmp word near [bp+0x24]
00007111  0000              add [bx+si],al
00007113  0000              add [bx+si],al
00007115  0022              add [bp+si],ah
00007117  006363            add [bp+di+0x63],ah
0000711A  6322              arpl [bp+si],sp
0000711C  0000              add [bx+si],al
0000711E  0000              add [bx+si],al
00007120  0000              add [bx+si],al
00007122  0000              add [bx+si],al
00007124  002B              add [bp+di],ch
00007126  0000              add [bx+si],al
00007128  0018              add [bx+si],bl
0000712A  1818              sbb [bx+si],bl
0000712C  FF18              call word far [bx+si]
0000712E  1818              sbb [bx+si],bl
00007130  0000              add [bx+si],al
00007132  0000              add [bx+si],al
00007134  2D0000            sub ax,0x0
00007137  0000              add [bx+si],al
00007139  0000              add [bx+si],al
0000713B  FF00              inc word [bx+si]
0000713D  0000              add [bx+si],al
0000713F  0000              add [bx+si],al
00007141  0000              add [bx+si],al
00007143  4D                dec bp
00007144  0000              add [bx+si],al
00007146  C3                ret
00007147  E7FF              out 0xff,ax
00007149  DBC3              fcmovnb st3
0000714B  C3                ret
0000714C  C3                ret
0000714D  C3                ret
0000714E  C3                ret
0000714F  0000              add [bx+si],al
00007151  005400            add [si+0x0],dl
00007154  00FF              add bh,bh
00007156  DB991818          fistp dword [bx+di+0x1818]
0000715A  1818              sbb [bx+si],bl
0000715C  183C              sbb [si],bh
0000715E  0000              add [bx+si],al
00007160  005600            add [bp+0x0],dl
00007163  00C3              add bl,al
00007165  C3                ret
00007166  C3                ret
00007167  C3                ret
00007168  C3                ret
00007169  C3                ret
0000716A  663C18            o32 cmp al,0x18
0000716D  0000              add [bx+si],al
0000716F  005700            add [bx+0x0],dl
00007172  00C3              add bl,al
00007174  C3                ret
00007175  C3                ret
00007176  C3                ret
00007177  DBDB              fcmovnu st3
00007179  FF6666            jmp word near [bp+0x66]
0000717C  0000              add [bx+si],al
0000717E  005800            add [bx+si+0x0],bl
00007181  00C3              add bl,al
00007183  C3                ret
00007184  663C18            o32 cmp al,0x18
00007187  3C66              cmp al,0x66
00007189  C3                ret
0000718A  C3                ret
0000718B  0000              add [bx+si],al
0000718D  005900            add [bx+di+0x0],bl
00007190  00C3              add bl,al
00007192  C3                ret
00007193  C3                ret
00007194  663C18            o32 cmp al,0x18
00007197  1818              sbb [bx+si],bl
00007199  3C00              cmp al,0x0
0000719B  0000              add [bx+si],al
0000719D  5A                pop dx
0000719E  0000              add [bx+si],al
000071A0  FFC3              inc bx
000071A2  860C              xchg cl,[si]
000071A4  1830              sbb [bx+si],dh
000071A6  61                popaw
000071A7  C3                ret
000071A8  FF00              inc word [bx+si]
000071AA  0000              add [bx+si],al
000071AC  6D                insw
000071AD  0000              add [bx+si],al
000071AF  0000              add [bx+si],al
000071B1  00E6              add dh,ah
000071B3  FF                db 0xff
000071B4  DBDB              fcmovnu st3
000071B6  DBDB              fcmovnu st3
000071B8  0000              add [bx+si],al
000071BA  007600            add [bp+0x0],dh
000071BD  0000              add [bx+si],al
000071BF  0000              add [bx+si],al
000071C1  C3                ret
000071C2  C3                ret
000071C3  C3                ret
000071C4  663C18            o32 cmp al,0x18
000071C7  0000              add [bx+si],al
000071C9  007700            add [bx+0x0],dh
000071CC  0000              add [bx+si],al
000071CE  0000              add [bx+si],al
000071D0  C3                ret
000071D1  C3                ret
000071D2  DBDB              fcmovnu st3
000071D4  FF6600            jmp word near [bp+0x0]
000071D7  0000              add [bx+si],al
000071D9  91                xchg ax,cx
000071DA  0000              add [bx+si],al
000071DC  0000              add [bx+si],al
000071DE  6E                outsb
000071DF  3B1B              cmp bx,[bp+di]
000071E1  7ED8              jng 0x71bb
000071E3  DC7700            fdiv qword [bx+0x0]
000071E6  0000              add [bx+si],al
000071E8  9B0018            wait add [bx+si],bl
000071EB  187EC3            sbb [bp-0x3d],bh
000071EE  C0C0C3            rol al,0xc3
000071F1  7E18              jng 0x720b
000071F3  1800              sbb [bx+si],al
000071F5  0000              add [bx+si],al
000071F7  9D                popfw
000071F8  0000              add [bx+si],al
000071FA  C3                ret
000071FB  663C18            o32 cmp al,0x18
000071FE  FF18              call word far [bx+si]
00007200  FF18              call word far [bx+si]
00007202  1800              sbb [bx+si],al
00007204  0000              add [bx+si],al
00007206  9E                sahf
00007207  00FC              add ah,bh
00007209  66667C62          o32 jl 0x726f
0000720D  666F              outsd
0000720F  6666F30000        rep o32 add [bx+si],al
00007214  00F1              add cl,dh
00007216  0000              add [bx+si],al
00007218  1818              sbb [bx+si],bl
0000721A  18FF              sbb bh,bh
0000721C  1818              sbb [bx+si],bl
0000721E  1800              sbb [bx+si],al
00007220  FF00              inc word [bx+si]
00007222  0000              add [bx+si],al
00007224  F60000            test byte [bx+si],0x0
00007227  1818              sbb [bx+si],bl
00007229  0000              add [bx+si],al
0000722B  FF00              inc word [bx+si]
0000722D  0018              add [bx+si],bl
0000722F  1800              sbb [bx+si],al
00007231  0000              add [bx+si],al
00007233  001D              add [di],bl
00007235  0000              add [bx+si],al
00007237  0000              add [bx+si],al
00007239  0024              add [si],ah
0000723B  66FF6624          jmp dword near [bp+0x24]
0000723F  0000              add [bx+si],al
00007241  0000              add [bx+si],al
00007243  0000              add [bx+si],al
00007245  3000              xor [bx+si],al
00007247  003C              add [si],bh
00007249  66C3              o32 ret
0000724B  C3                ret
0000724C  DBDB              fcmovnu st3
0000724E  C3                ret
0000724F  C3                ret
00007250  663C00            o32 cmp al,0x0
00007253  0000              add [bx+si],al
00007255  004D00            add [di+0x0],cl
00007258  00C3              add bl,al
0000725A  E7FF              out 0xff,ax
0000725C  FF                db 0xff
0000725D  DBC3              fcmovnb st3
0000725F  C3                ret
00007260  C3                ret
00007261  C3                ret
00007262  C3                ret
00007263  0000              add [bx+si],al
00007265  0000              add [bx+si],al
00007267  54                push sp
00007268  0000              add [bx+si],al
0000726A  FF                db 0xff
0000726B  DB991818          fistp dword [bx+di+0x1818]
0000726F  1818              sbb [bx+si],bl
00007271  1818              sbb [bx+si],bl
00007273  3C00              cmp al,0x0
00007275  0000              add [bx+si],al
00007277  005600            add [bp+0x0],dl
0000727A  00C3              add bl,al
0000727C  C3                ret
0000727D  C3                ret
0000727E  C3                ret
0000727F  C3                ret
00007280  C3                ret
00007281  C3                ret
00007282  663C18            o32 cmp al,0x18
00007285  0000              add [bx+si],al
00007287  0000              add [bx+si],al
00007289  57                push di
0000728A  0000              add [bx+si],al
0000728C  C3                ret
0000728D  C3                ret
0000728E  C3                ret
0000728F  C3                ret
00007290  C3                ret
00007291  DBDB              fcmovnu st3
00007293  FF6666            jmp word near [bp+0x66]
00007296  0000              add [bx+si],al
00007298  0000              add [bx+si],al
0000729A  58                pop ax
0000729B  0000              add [bx+si],al
0000729D  C3                ret
0000729E  C3                ret
0000729F  663C18            o32 cmp al,0x18
000072A2  183C              sbb [si],bh
000072A4  66C3              o32 ret
000072A6  C3                ret
000072A7  0000              add [bx+si],al
000072A9  0000              add [bx+si],al
000072AB  59                pop cx
000072AC  0000              add [bx+si],al
000072AE  C3                ret
000072AF  C3                ret
000072B0  C3                ret
000072B1  663C18            o32 cmp al,0x18
000072B4  1818              sbb [bx+si],bl
000072B6  183C              sbb [si],bh
000072B8  0000              add [bx+si],al
000072BA  0000              add [bx+si],al
000072BC  5A                pop dx
000072BD  0000              add [bx+si],al
000072BF  FFC3              inc bx
000072C1  860C              xchg cl,[si]
000072C3  1830              sbb [bx+si],dh
000072C5  60                pushaw
000072C6  C1C3FF            rol bx,0xff
000072C9  0000              add [bx+si],al
000072CB  0000              add [bx+si],al
000072CD  6D                insw
000072CE  0000              add [bx+si],al
000072D0  0000              add [bx+si],al
000072D2  00E6              add dh,ah
000072D4  FF                db 0xff
000072D5  DBDB              fcmovnu st3
000072D7  DBDB              fcmovnu st3
000072D9  DB00              fild dword [bx+si]
000072DB  0000              add [bx+si],al
000072DD  007600            add [bp+0x0],dh
000072E0  0000              add [bx+si],al
000072E2  0000              add [bx+si],al
000072E4  C3                ret
000072E5  C3                ret
000072E6  C3                ret
000072E7  C3                ret
000072E8  663C18            o32 cmp al,0x18
000072EB  0000              add [bx+si],al
000072ED  0000              add [bx+si],al
000072EF  7700              ja 0x72f1
000072F1  0000              add [bx+si],al
000072F3  0000              add [bx+si],al
000072F5  C3                ret
000072F6  C3                ret
000072F7  C3                ret
000072F8  DBDB              fcmovnu st3
000072FA  FF6600            jmp word near [bp+0x0]
000072FD  0000              add [bx+si],al
000072FF  007800            add [bx+si+0x0],bh
00007302  0000              add [bx+si],al
00007304  0000              add [bx+si],al
00007306  C3                ret
00007307  663C18            o32 cmp al,0x18
0000730A  3C66              cmp al,0x66
0000730C  C3                ret
0000730D  0000              add [bx+si],al
0000730F  0000              add [bx+si],al
00007311  91                xchg ax,cx
00007312  0000              add [bx+si],al
00007314  0000              add [bx+si],al
00007316  006E3B            add [bp+0x3b],ch
00007319  1B7ED8            sbb di,[bp-0x28]
0000731C  DC7700            fdiv qword [bx+0x0]
0000731F  0000              add [bx+si],al
00007321  009B0018          add [bp+di+0x1800],bl
00007325  187EC3            sbb [bp-0x3d],bh
00007328  C0C0C0            rol al,0xc0
0000732B  C3                ret
0000732C  7E18              jng 0x7346
0000732E  1800              sbb [bx+si],al
00007330  0000              add [bx+si],al
00007332  009D0000          add [di+0x0],bl
00007336  C3                ret
00007337  663C18            o32 cmp al,0x18
0000733A  FF18              call word far [bx+si]
0000733C  FF18              call word far [bx+si]
0000733E  1818              sbb [bx+si],bl
00007340  0000              add [bx+si],al
00007342  0000              add [bx+si],al
00007344  9E                sahf
00007345  00FC              add ah,bh
00007347  66667C62          o32 jl 0x73ad
0000734B  666F              outsd
0000734D  666666F30000      rep o32 add [bx+si],al
00007353  0000              add [bx+si],al
00007355  AB                stosw
00007356  00C0              add al,al
00007358  C0C2C6            rol dl,0xc6
0000735B  CC                int3
0000735C  1830              sbb [bx+si],dh
0000735E  60                pushaw
0000735F  CE                into
00007360  9B06              wait push es
00007362  0C1F              or al,0x1f
00007364  0000              add [bx+si],al
00007366  AC                lodsb
00007367  00C0              add al,al
00007369  C0C2C6            rol dl,0xc6
0000736C  CC                int3
0000736D  1830              sbb [bx+si],dh
0000736F  66CE              o32 into
00007371  96                xchg ax,si
00007372  3E06              ds push es
00007374  06                push es
00007375  0000              add [bx+si],al
00007377  00BAC203          add [bp+si+0x3c2],bh
0000737B  B0C3              mov al,0xc3
0000737D  EE                out dx,al
0000737E  BAC403            mov dx,0x3c4
00007381  B004              mov al,0x4
00007383  EE                out dx,al
00007384  BAC503            mov dx,0x3c5
00007387  B002              mov al,0x2
00007389  EE                out dx,al
0000738A  BB0237            mov bx,0x3702
0000738D  53                push bx
0000738E  E8C646            call word 0xba57
00007391  44                inc sp
00007392  44                inc sp
00007393  C3                ret
00007394  53                push bx
00007395  756E              jnz 0x7405
00007397  205669            and [bp+0x69],dl
0000739A  7274              jc 0x7410
0000739C  7561              jnz 0x73ff
0000739E  6C                insb
0000739F  42                inc dx
000073A0  6F                outsw
000073A1  7820              js 0x73c3
000073A3  56                push si
000073A4  657273            gs jc 0x741a
000073A7  696F6E2033        imul bp,[bx+0x6e],word 0x3320
000073AC  2E322E3420        xor ch,[cs:0x2034]
000073B1  56                push si
000073B2  47                inc di
000073B3  41                inc cx
000073B4  204249            and [bp+si+0x49],al
000073B7  4F                dec di
000073B8  53                push bx
000073B9  0D0A00            or ax,0xa
000073BC  1E                push ds
000073BD  B84000            mov ax,0x40
000073C0  8ED8              mov ds,ax
000073C2  BB1000            mov bx,0x10
000073C5  8B07              mov ax,[bx]
000073C7  25CFFF            and ax,0xffcf
000073CA  0D2000            or ax,0x20
000073CD  8907              mov [bx],ax
000073CF  BB8500            mov bx,0x85
000073D2  B010              mov al,0x10
000073D4  8807              mov [bx],al
000073D6  BB8700            mov bx,0x87
000073D9  B060              mov al,0x60
000073DB  8807              mov [bx],al
000073DD  BB8800            mov bx,0x88
000073E0  B0F9              mov al,0xf9
000073E2  8807              mov [bx],al
000073E4  BB8900            mov bx,0x89
000073E7  B051              mov al,0x51
000073E9  8807              mov [bx],al
000073EB  BB6500            mov bx,0x65
000073EE  B009              mov al,0x9
000073F0  8807              mov [bx],al
000073F2  1F                pop ds
000073F3  C3                ret
000073F4  A5                movsw
000073F5  0100              add [bx+si],ax
000073F7  C00000            rol byte [bx+si],0x0
000073FA  0000              add [bx+si],al
000073FC  0000              add [bx+si],al
000073FE  0000              add [bx+si],al
00007400  0000              add [bx+si],al
00007402  0000              add [bx+si],al
00007404  0000              add [bx+si],al
00007406  0000              add [bx+si],al
00007408  0000              add [bx+si],al
0000740A  0000              add [bx+si],al
0000740C  0000              add [bx+si],al
0000740E  0000              add [bx+si],al
00007410  C3                ret
00007411  55                push bp
00007412  89E5              mov bp,sp
00007414  8B4612            mov ax,[bp+0x12]
00007417  88E0              mov al,ah
00007419  30E4              xor ah,ah
0000741B  E9D704            jmp word 0x78f5
0000741E  8A4612            mov al,[bp+0x12]
00007421  30E4              xor ah,ah
00007423  50                push ax
00007424  E82405            call word 0x794b
00007427  44                inc sp
00007428  44                inc sp
00007429  8A4612            mov al,[bp+0x12]
0000742C  247F              and al,0x7f
0000742E  EB24              jmp short 0x7454
00007430  8B4612            mov ax,[bp+0x12]
00007433  30C0              xor al,al
00007435  0C3F              or al,0x3f
00007437  894612            mov [bp+0x12],ax
0000743A  EB3D              jmp short 0x7479
0000743C  8B4612            mov ax,[bp+0x12]
0000743F  30C0              xor al,al
00007441  0C30              or al,0x30
00007443  894612            mov [bp+0x12],ax
00007446  EB31              jmp short 0x7479
00007448  8B4612            mov ax,[bp+0x12]
0000744B  30C0              xor al,al
0000744D  0C20              or al,0x20
0000744F  894612            mov [bp+0x12],ax
00007452  EB25              jmp short 0x7479
00007454  2C00              sub al,0x0
00007456  72F0              jc 0x7448
00007458  3C07              cmp al,0x7
0000745A  771B              ja 0x7477
0000745C  30E4              xor ah,ah
0000745E  D1E0              shl ax,1
00007460  89C3              mov bx,ax
00007462  2EFFA7D537        jmp word near [cs:bx+0x37d5]
00007467  AA                stosb
00007468  37                aaa
00007469  AA                stosb
0000746A  37                aaa
0000746B  AA                stosb
0000746C  37                aaa
0000746D  AA                stosb
0000746E  37                aaa
0000746F  AA                stosb
00007470  37                aaa
00007471  AA                stosb
00007472  37                aaa
00007473  9E                sahf
00007474  37                aaa
00007475  AA                stosb
00007476  37                aaa
00007477  EBCF              jmp short 0x7448
00007479  E9CD04            jmp word 0x7949
0000747C  8A4610            mov al,[bp+0x10]
0000747F  30E4              xor ah,ah
00007481  50                push ax
00007482  8B4610            mov ax,[bp+0x10]
00007485  88E0              mov al,ah
00007487  30E4              xor ah,ah
00007489  50                push ax
0000748A  E8550B            call word 0x7fe2
0000748D  83C404            add sp,byte +0x4
00007490  E9B604            jmp word 0x7949
00007493  FF760E            push word [bp+0xe]
00007496  8B460C            mov ax,[bp+0xc]
00007499  88E0              mov al,ah
0000749B  30E4              xor ah,ah
0000749D  50                push ax
0000749E  E85C0C            call word 0x80fd
000074A1  83C404            add sp,byte +0x4
000074A4  E9A204            jmp word 0x7949
000074A7  8D5E0E            lea bx,[bp+0xe]
000074AA  53                push bx
000074AB  8D5E10            lea bx,[bp+0x10]
000074AE  53                push bx
000074AF  8B460C            mov ax,[bp+0xc]
000074B2  88E0              mov al,ah
000074B4  30E4              xor ah,ah
000074B6  50                push ax
000074B7  E8430D            call word 0x81fd
000074BA  83C406            add sp,byte +0x6
000074BD  E98904            jmp word 0x7949
000074C0  31C0              xor ax,ax
000074C2  894612            mov [bp+0x12],ax
000074C5  31C0              xor ax,ax
000074C7  89460C            mov [bp+0xc],ax
000074CA  31C0              xor ax,ax
000074CC  894610            mov [bp+0x10],ax
000074CF  31C0              xor ax,ax
000074D1  89460E            mov [bp+0xe],ax
000074D4  E97204            jmp word 0x7949
000074D7  8A4612            mov al,[bp+0x12]
000074DA  30E4              xor ah,ah
000074DC  50                push ax
000074DD  E8920D            call word 0x8272
000074E0  44                inc sp
000074E1  44                inc sp
000074E2  E96404            jmp word 0x7949
000074E5  B80100            mov ax,0x1
000074E8  50                push ax
000074E9  B8FF00            mov ax,0xff
000074EC  50                push ax
000074ED  8A460E            mov al,[bp+0xe]
000074F0  30E4              xor ah,ah
000074F2  50                push ax
000074F3  8B460E            mov ax,[bp+0xe]
000074F6  88E0              mov al,ah
000074F8  30E4              xor ah,ah
000074FA  50                push ax
000074FB  8A4610            mov al,[bp+0x10]
000074FE  30E4              xor ah,ah
00007500  50                push ax
00007501  8B4610            mov ax,[bp+0x10]
00007504  88E0              mov al,ah
00007506  30E4              xor ah,ah
00007508  50                push ax
00007509  8B460C            mov ax,[bp+0xc]
0000750C  88E0              mov al,ah
0000750E  30E4              xor ah,ah
00007510  50                push ax
00007511  8A4612            mov al,[bp+0x12]
00007514  30E4              xor ah,ah
00007516  50                push ax
00007517  E8DB11            call word 0x86f5
0000751A  83C410            add sp,byte +0x10
0000751D  E92904            jmp word 0x7949
00007520  31C0              xor ax,ax
00007522  50                push ax
00007523  B8FF00            mov ax,0xff
00007526  50                push ax
00007527  8A460E            mov al,[bp+0xe]
0000752A  30E4              xor ah,ah
0000752C  50                push ax
0000752D  8B460E            mov ax,[bp+0xe]
00007530  88E0              mov al,ah
00007532  30E4              xor ah,ah
00007534  50                push ax
00007535  8A4610            mov al,[bp+0x10]
00007538  30E4              xor ah,ah
0000753A  50                push ax
0000753B  8B4610            mov ax,[bp+0x10]
0000753E  88E0              mov al,ah
00007540  30E4              xor ah,ah
00007542  50                push ax
00007543  8B460C            mov ax,[bp+0xc]
00007546  88E0              mov al,ah
00007548  30E4              xor ah,ah
0000754A  50                push ax
0000754B  8A4612            mov al,[bp+0x12]
0000754E  30E4              xor ah,ah
00007550  50                push ax
00007551  E8A111            call word 0x86f5
00007554  83C410            add sp,byte +0x10
00007557  E9EF03            jmp word 0x7949
0000755A  8D5E12            lea bx,[bp+0x12]
0000755D  53                push bx
0000755E  8B460C            mov ax,[bp+0xc]
00007561  88E0              mov al,ah
00007563  30E4              xor ah,ah
00007565  50                push ax
00007566  E89218            call word 0x8dfb
00007569  83C404            add sp,byte +0x4
0000756C  E9DA03            jmp word 0x7949
0000756F  FF7610            push word [bp+0x10]
00007572  8A460C            mov al,[bp+0xc]
00007575  30E4              xor ah,ah
00007577  50                push ax
00007578  8B460C            mov ax,[bp+0xc]
0000757B  88E0              mov al,ah
0000757D  30E4              xor ah,ah
0000757F  50                push ax
00007580  8A4612            mov al,[bp+0x12]
00007583  30E4              xor ah,ah
00007585  50                push ax
00007586  E8B81D            call word 0x9341
00007589  83C408            add sp,byte +0x8
0000758C  E9BA03            jmp word 0x7949
0000758F  FF7610            push word [bp+0x10]
00007592  8A460C            mov al,[bp+0xc]
00007595  30E4              xor ah,ah
00007597  50                push ax
00007598  8B460C            mov ax,[bp+0xc]
0000759B  88E0              mov al,ah
0000759D  30E4              xor ah,ah
0000759F  50                push ax
000075A0  8A4612            mov al,[bp+0x12]
000075A3  30E4              xor ah,ah
000075A5  50                push ax
000075A6  E88A1F            call word 0x9533
000075A9  83C408            add sp,byte +0x8
000075AC  E99A03            jmp word 0x7949
000075AF  FF760E            push word [bp+0xe]
000075B2  FF7610            push word [bp+0x10]
000075B5  8A4612            mov al,[bp+0x12]
000075B8  30E4              xor ah,ah
000075BA  50                push ax
000075BB  8B460C            mov ax,[bp+0xc]
000075BE  88E0              mov al,ah
000075C0  30E4              xor ah,ah
000075C2  50                push ax
000075C3  E8E321            call word 0x97a9
000075C6  83C408            add sp,byte +0x8
000075C9  E97D03            jmp word 0x7949
000075CC  8D5E12            lea bx,[bp+0x12]
000075CF  53                push bx
000075D0  FF760E            push word [bp+0xe]
000075D3  FF7610            push word [bp+0x10]
000075D6  8B460C            mov ax,[bp+0xc]
000075D9  88E0              mov al,ah
000075DB  30E4              xor ah,ah
000075DD  50                push ax
000075DE  E86424            call word 0x9a45
000075E1  83C408            add sp,byte +0x8
000075E4  E96203            jmp word 0x7949
000075E7  B80200            mov ax,0x2
000075EA  50                push ax
000075EB  8A460C            mov al,[bp+0xc]
000075EE  30E4              xor ah,ah
000075F0  50                push ax
000075F1  B8FF00            mov ax,0xff
000075F4  50                push ax
000075F5  8A4612            mov al,[bp+0x12]
000075F8  30E4              xor ah,ah
000075FA  50                push ax
000075FB  E84D26            call word 0x9c4b
000075FE  83C408            add sp,byte +0x8
00007601  E94503            jmp word 0x7949
00007604  FF7610            push word [bp+0x10]
00007607  FF760C            push word [bp+0xc]
0000760A  E8AB2C            call word 0xa2b8
0000760D  83C404            add sp,byte +0x4
00007610  E93603            jmp word 0x7949
00007613  8A4612            mov al,[bp+0x12]
00007616  E9E100            jmp word 0x76fa
00007619  8B460C            mov ax,[bp+0xc]
0000761C  88E0              mov al,ah
0000761E  30E4              xor ah,ah
00007620  50                push ax
00007621  8A460C            mov al,[bp+0xc]
00007624  30E4              xor ah,ah
00007626  50                push ax
00007627  FF760E            push word [bp+0xe]
0000762A  FF7610            push word [bp+0x10]
0000762D  FF7608            push word [bp+0x8]
00007630  FF7616            push word [bp+0x16]
00007633  8A4612            mov al,[bp+0x12]
00007636  30E4              xor ah,ah
00007638  50                push ax
00007639  E82C2F            call word 0xa568
0000763C  83C40E            add sp,byte +0xe
0000763F  E90C01            jmp word 0x774e
00007642  8A460C            mov al,[bp+0xc]
00007645  30E4              xor ah,ah
00007647  50                push ax
00007648  8A4612            mov al,[bp+0x12]
0000764B  30E4              xor ah,ah
0000764D  50                push ax
0000764E  E8B32F            call word 0xa604
00007651  83C404            add sp,byte +0x4
00007654  E9F700            jmp word 0x774e
00007657  8A460C            mov al,[bp+0xc]
0000765A  30E4              xor ah,ah
0000765C  50                push ax
0000765D  8A4612            mov al,[bp+0x12]
00007660  30E4              xor ah,ah
00007662  50                push ax
00007663  E83530            call word 0xa69b
00007666  83C404            add sp,byte +0x4
00007669  E9E200            jmp word 0x774e
0000766C  8A460C            mov al,[bp+0xc]
0000766F  30E4              xor ah,ah
00007671  50                push ax
00007672  8A4612            mov al,[bp+0x12]
00007675  30E4              xor ah,ah
00007677  50                push ax
00007678  E8BE30            call word 0xa739
0000767B  83C404            add sp,byte +0x4
0000767E  E9CD00            jmp word 0x774e
00007681  FF7608            push word [bp+0x8]
00007684  FF7616            push word [bp+0x16]
00007687  E84031            call word 0xa7ca
0000768A  83C404            add sp,byte +0x4
0000768D  E9BE00            jmp word 0x774e
00007690  8A460E            mov al,[bp+0xe]
00007693  30E4              xor ah,ah
00007695  50                push ax
00007696  8A460C            mov al,[bp+0xc]
00007699  30E4              xor ah,ah
0000769B  50                push ax
0000769C  FF7610            push word [bp+0x10]
0000769F  FF7608            push word [bp+0x8]
000076A2  FF7616            push word [bp+0x16]
000076A5  E82331            call word 0xa7cb
000076A8  83C40A            add sp,byte +0xa
000076AB  E9A000            jmp word 0x774e
000076AE  8A460C            mov al,[bp+0xc]
000076B1  30E4              xor ah,ah
000076B3  50                push ax
000076B4  E81531            call word 0xa7cc
000076B7  44                inc sp
000076B8  44                inc sp
000076B9  E99200            jmp word 0x774e
000076BC  8A460C            mov al,[bp+0xc]
000076BF  30E4              xor ah,ah
000076C1  50                push ax
000076C2  E80831            call word 0xa7cd
000076C5  44                inc sp
000076C6  44                inc sp
000076C7  E98400            jmp word 0x774e
000076CA  8A460C            mov al,[bp+0xc]
000076CD  30E4              xor ah,ah
000076CF  50                push ax
000076D0  E8FB30            call word 0xa7ce
000076D3  44                inc sp
000076D4  44                inc sp
000076D5  E97600            jmp word 0x774e
000076D8  8D5E0E            lea bx,[bp+0xe]
000076DB  53                push bx
000076DC  8D5E10            lea bx,[bp+0x10]
000076DF  53                push bx
000076E0  8D5E08            lea bx,[bp+0x8]
000076E3  53                push bx
000076E4  8D5E16            lea bx,[bp+0x16]
000076E7  53                push bx
000076E8  8B460C            mov ax,[bp+0xc]
000076EB  88E0              mov al,ah
000076ED  30E4              xor ah,ah
000076EF  50                push ax
000076F0  E8DC30            call word 0xa7cf
000076F3  83C40A            add sp,byte +0xa
000076F6  EB56              jmp short 0x774e
000076F8  EB54              jmp short 0x774e
000076FA  2C00              sub al,0x0
000076FC  0F8419FF          jz word 0x7619
00007700  2C01              sub al,0x1
00007702  0F843CFF          jz word 0x7642
00007706  2C01              sub al,0x1
00007708  0F844BFF          jz word 0x7657
0000770C  2C02              sub al,0x2
0000770E  0F845AFF          jz word 0x766c
00007712  2C0C              sub al,0xc
00007714  0F8401FF          jz word 0x7619
00007718  2C01              sub al,0x1
0000771A  0F8424FF          jz word 0x7642
0000771E  2C01              sub al,0x1
00007720  0F8433FF          jz word 0x7657
00007724  2C02              sub al,0x2
00007726  0F8442FF          jz word 0x766c
0000772A  2C0C              sub al,0xc
0000772C  0F8451FF          jz word 0x7681
00007730  2C01              sub al,0x1
00007732  0F845AFF          jz word 0x7690
00007736  2C01              sub al,0x1
00007738  0F8472FF          jz word 0x76ae
0000773C  2C01              sub al,0x1
0000773E  0F847AFF          jz word 0x76bc
00007742  2C01              sub al,0x1
00007744  0F8482FF          jz word 0x76ca
00007748  2C0C              sub al,0xc
0000774A  0F848AFF          jz word 0x76d8
0000774E  E9F801            jmp word 0x7949
00007751  8A460C            mov al,[bp+0xc]
00007754  EB3C              jmp short 0x7792
00007756  E85032            call word 0xa9a9
00007759  EB43              jmp short 0x779e
0000775B  FF760E            push word [bp+0xe]
0000775E  FF7616            push word [bp+0x16]
00007761  8A4612            mov al,[bp+0x12]
00007764  30E4              xor ah,ah
00007766  50                push ax
00007767  E81933            call word 0xaa83
0000776A  83C406            add sp,byte +0x6
0000776D  8B4612            mov ax,[bp+0x12]
00007770  30C0              xor al,al
00007772  0C12              or al,0x12
00007774  894612            mov [bp+0x12],ax
00007777  EB25              jmp short 0x779e
00007779  8A4612            mov al,[bp+0x12]
0000777C  30E4              xor ah,ah
0000777E  50                push ax
0000777F  E80233            call word 0xaa84
00007782  44                inc sp
00007783  44                inc sp
00007784  8B4612            mov ax,[bp+0x12]
00007787  30C0              xor al,al
00007789  0C12              or al,0x12
0000778B  894612            mov [bp+0x12],ax
0000778E  EB0E              jmp short 0x779e
00007790  EB0C              jmp short 0x779e
00007792  2C20              sub al,0x20
00007794  74C0              jz 0x7756
00007796  2C15              sub al,0x15
00007798  74C1              jz 0x775b
0000779A  2C01              sub al,0x1
0000779C  74DB              jz 0x7779
0000779E  E9A801            jmp word 0x7949
000077A1  FF7608            push word [bp+0x8]
000077A4  FF7616            push word [bp+0x16]
000077A7  8A460E            mov al,[bp+0xe]
000077AA  30E4              xor ah,ah
000077AC  50                push ax
000077AD  8B460E            mov ax,[bp+0xe]
000077B0  88E0              mov al,ah
000077B2  30E4              xor ah,ah
000077B4  50                push ax
000077B5  FF7610            push word [bp+0x10]
000077B8  8A460C            mov al,[bp+0xc]
000077BB  30E4              xor ah,ah
000077BD  50                push ax
000077BE  8B460C            mov ax,[bp+0xc]
000077C1  88E0              mov al,ah
000077C3  30E4              xor ah,ah
000077C5  50                push ax
000077C6  8A4612            mov al,[bp+0x12]
000077C9  30E4              xor ah,ah
000077CB  50                push ax
000077CC  E8B632            call word 0xaa85
000077CF  83C410            add sp,byte +0x10
000077D2  E97401            jmp word 0x7949
000077D5  FF7604            push word [bp+0x4]
000077D8  FF7616            push word [bp+0x16]
000077DB  FF760C            push word [bp+0xc]
000077DE  E8B033            call word 0xab91
000077E1  83C406            add sp,byte +0x6
000077E4  8B4612            mov ax,[bp+0x12]
000077E7  30C0              xor al,al
000077E9  0C1B              or al,0x1b
000077EB  894612            mov [bp+0x12],ax
000077EE  E95801            jmp word 0x7949
000077F1  8A4612            mov al,[bp+0x12]
000077F4  EB33              jmp short 0x7829
000077F6  8D5E0C            lea bx,[bp+0xc]
000077F9  53                push bx
000077FA  FF7610            push word [bp+0x10]
000077FD  E81035            call word 0xad10
00007800  83C404            add sp,byte +0x4
00007803  EB30              jmp short 0x7835
00007805  FF760C            push word [bp+0xc]
00007808  FF7616            push word [bp+0x16]
0000780B  FF7610            push word [bp+0x10]
0000780E  E82335            call word 0xad34
00007811  83C406            add sp,byte +0x6
00007814  EB1F              jmp short 0x7835
00007816  FF760C            push word [bp+0xc]
00007819  FF7616            push word [bp+0x16]
0000781C  FF7610            push word [bp+0x10]
0000781F  E8DC3A            call word 0xb2fe
00007822  83C406            add sp,byte +0x6
00007825  EB0E              jmp short 0x7835
00007827  EB0C              jmp short 0x7835
00007829  2C00              sub al,0x0
0000782B  74C9              jz 0x77f6
0000782D  2C01              sub al,0x1
0000782F  74D4              jz 0x7805
00007831  2C01              sub al,0x1
00007833  74E1              jz 0x7816
00007835  8B4612            mov ax,[bp+0x12]
00007838  30C0              xor al,al
0000783A  0C1C              or al,0x1c
0000783C  894612            mov [bp+0x12],ax
0000783F  E90701            jmp word 0x7949
00007842  E83349            call word 0xc178
00007845  85C0              test ax,ax
00007847  0F84A000          jz word 0x78eb
0000784B  8A4612            mov al,[bp+0x12]
0000784E  EB6E              jmp short 0x78be
00007850  FF7604            push word [bp+0x4]
00007853  FF7616            push word [bp+0x16]
00007856  8D5E12            lea bx,[bp+0x12]
00007859  53                push bx
0000785A  E85349            call word 0xc1b0
0000785D  83C406            add sp,byte +0x6
00007860  E98600            jmp word 0x78e9
00007863  FF7604            push word [bp+0x4]
00007866  FF7616            push word [bp+0x16]
00007869  FF7610            push word [bp+0x10]
0000786C  8D5E12            lea bx,[bp+0x12]
0000786F  53                push bx
00007870  E8A54C            call word 0xc518
00007873  83C408            add sp,byte +0x8
00007876  EB71              jmp short 0x78e9
00007878  FF7604            push word [bp+0x4]
0000787B  FF7616            push word [bp+0x16]
0000787E  FF760C            push word [bp+0xc]
00007881  8D5E12            lea bx,[bp+0x12]
00007884  53                push bx
00007885  E8B54D            call word 0xc63d
00007888  83C408            add sp,byte +0x8
0000788B  EB5C              jmp short 0x78e9
0000788D  8D5E0C            lea bx,[bp+0xc]
00007890  53                push bx
00007891  FF7616            push word [bp+0x16]
00007894  FF760E            push word [bp+0xe]
00007897  FF7610            push word [bp+0x10]
0000789A  8D5E12            lea bx,[bp+0x12]
0000789D  53                push bx
0000789E  E84C51            call word 0xc9ed
000078A1  83C40A            add sp,byte +0xa
000078A4  EB43              jmp short 0x78e9
000078A6  B80001            mov ax,0x100
000078A9  894612            mov [bp+0x12],ax
000078AC  EB3B              jmp short 0x78e9
000078AE  B80001            mov ax,0x100
000078B1  894612            mov [bp+0x12],ax
000078B4  EB33              jmp short 0x78e9
000078B6  B80001            mov ax,0x100
000078B9  894612            mov [bp+0x12],ax
000078BC  EB2B              jmp short 0x78e9
000078BE  2C00              sub al,0x0
000078C0  72F4              jc 0x78b6
000078C2  3C0A              cmp al,0xa
000078C4  7721              ja 0x78e7
000078C6  30E4              xor ah,ah
000078C8  D1E0              shl ax,1
000078CA  89C3              mov bx,ax
000078CC  2EFFA73F3C        jmp word near [cs:bx+0x3c3f]
000078D1  BE3BD1            mov si,0xd13b
000078D4  3BE6              cmp sp,si
000078D6  3B24              cmp sp,[si]
000078D8  3CFB              cmp al,0xfb
000078DA  3B24              cmp sp,[si]
000078DC  3C24              cmp al,0x24
000078DE  3C24              cmp al,0x24
000078E0  3C24              cmp al,0x24
000078E2  3C14              cmp al,0x14
000078E4  3C1C              cmp al,0x1c
000078E6  3CEB              cmp al,0xeb
000078E8  CDEB              int 0xeb
000078EA  06                push es
000078EB  B80001            mov ax,0x100
000078EE  894612            mov [bp+0x12],ax
000078F1  EB56              jmp short 0x7949
000078F3  EB54              jmp short 0x7949
000078F5  2D0000            sub ax,0x0
000078F8  7C4F              jl 0x7949
000078FA  3D1C00            cmp ax,0x1c
000078FD  7743              ja 0x7942
000078FF  D1E0              shl ax,1
00007901  89C3              mov bx,ax
00007903  2EFFA7763C        jmp word near [cs:bx+0x3c76]
00007908  8C37              mov [bx],segr6
0000790A  EA37013815        jmp word 0x1538:0x137
0000790F  382E3845          cmp [0x4538],ch
00007913  385338            cmp [bp+di+0x38],dl
00007916  8E38              mov segr7,[bx+si]
00007918  C838DD38          enter 0xdd38,0x38
0000791C  FD                std
0000791D  38B73C1D          cmp [bx+0x1d3c],dh
00007921  393A              cmp [bp+si],di
00007923  395539            cmp [di+0x39],dx
00007926  B73C              mov bh,0x3c
00007928  7239              jc 0x7963
0000792A  8139BF3A          cmp word [bx+di],0x3abf
0000792E  0F                db 0x0f
0000792F  3BB73CB7          cmp si,[bx-0x48c4]
00007933  3CB7              cmp al,0xb7
00007935  3CB7              cmp al,0xb7
00007937  3CB7              cmp al,0xb7
00007939  3CB7              cmp al,0xb7
0000793B  3CB7              cmp al,0xb7
0000793D  3C43              cmp al,0x43
0000793F  3B5F3B            cmp bx,[bx+0x3b]
00007942  2D4F00            sub ax,0x4f
00007945  0F84F9FE          jz word 0x7842
00007949  5D                pop bp
0000794A  C3                ret
0000794B  55                push bp
0000794C  89E5              mov bp,sp
0000794E  4C                dec sp
0000794F  8A4604            mov al,[bp+0x4]
00007952  2480              and al,0x80
00007954  8846FF            mov [bp-0x1],al
00007957  83C4EB            add sp,byte -0x15
0000795A  E81B48            call word 0xc178
0000795D  85C0              test ax,ax
0000795F  7408              jz 0x7969
00007961  31C0              xor ax,ax
00007963  50                push ax
00007964  E8F444            call word 0xbe5b
00007967  44                inc sp
00007968  44                inc sp
00007969  8A4604            mov al,[bp+0x4]
0000796C  247F              and al,0x7f
0000796E  884604            mov [bp+0x4],al
00007971  8A4604            mov al,[bp+0x4]
00007974  30E4              xor ah,ah
00007976  50                push ax
00007977  E8623F            call word 0xb8dc
0000797A  44                inc sp
0000797B  44                inc sp
0000797C  8846FE            mov [bp-0x2],al
0000797F  8A46FE            mov al,[bp-0x2]
00007982  3CFF              cmp al,0xff
00007984  7504              jnz 0x798a
00007986  89EC              mov sp,bp
00007988  5D                pop bp
00007989  C3                ret
0000798A  8A46FE            mov al,[bp-0x2]
0000798D  30E4              xor ah,ah
0000798F  89C3              mov bx,ax
00007991  8A879101          mov al,[bx+0x191]
00007995  8846F9            mov [bp-0x7],al
00007998  8A46F9            mov al,[bp-0x7]
0000799B  30E4              xor ah,ah
0000799D  B106              mov cl,0x6
0000799F  D3E0              shl ax,cl
000079A1  89C3              mov bx,ax
000079A3  8A87A501          mov al,[bx+0x1a5]
000079A7  30E4              xor ah,ah
000079A9  8946F4            mov [bp-0xc],ax
000079AC  8A46F9            mov al,[bp-0x7]
000079AF  30E4              xor ah,ah
000079B1  B106              mov cl,0x6
000079B3  D3E0              shl ax,cl
000079B5  89C3              mov bx,ax
000079B7  81C3A501          add bx,0x1a5
000079BB  8A4701            mov al,[bx+0x1]
000079BE  30E4              xor ah,ah
000079C0  8946F2            mov [bp-0xe],ax
000079C3  8A46F9            mov al,[bp-0x7]
000079C6  30E4              xor ah,ah
000079C8  B106              mov cl,0x6
000079CA  D3E0              shl ax,cl
000079CC  89C3              mov bx,ax
000079CE  81C3A501          add bx,0x1a5
000079D2  8A4702            mov al,[bx+0x2]
000079D5  30E4              xor ah,ah
000079D7  8946F0            mov [bp-0x10],ax
000079DA  B88700            mov ax,0x87
000079DD  50                push ax
000079DE  B84000            mov ax,0x40
000079E1  50                push ax
000079E2  E8E33F            call word 0xb9c8
000079E5  83C404            add sp,byte +0x4
000079E8  8846EE            mov [bp-0x12],al
000079EB  B88800            mov ax,0x88
000079EE  50                push ax
000079EF  B84000            mov ax,0x40
000079F2  50                push ax
000079F3  E8D23F            call word 0xb9c8
000079F6  83C404            add sp,byte +0x4
000079F9  8846ED            mov [bp-0x13],al
000079FC  B88900            mov ax,0x89
000079FF  50                push ax
00007A00  B84000            mov ax,0x40
00007A03  50                push ax
00007A04  E8C13F            call word 0xb9c8
00007A07  83C404            add sp,byte +0x4
00007A0A  8846EF            mov [bp-0x11],al
00007A0D  8A46EF            mov al,[bp-0x11]
00007A10  2408              and al,0x8
00007A12  84C0              test al,al
00007A14  0F854501          jnz word 0x7b5d
00007A18  8A46FE            mov al,[bp-0x2]
00007A1B  30E4              xor ah,ah
00007A1D  B103              mov cl,0x3
00007A1F  D3E0              shl ax,cl
00007A21  89C3              mov bx,ax
00007A23  81C31101          add bx,0x111
00007A27  8A4706            mov al,[bx+0x6]
00007A2A  30E4              xor ah,ah
00007A2C  50                push ax
00007A2D  B8C603            mov ax,0x3c6
00007A30  50                push ax
00007A31  E80040            call word 0xba34
00007A34  83C404            add sp,byte +0x4
00007A37  31C0              xor ax,ax
00007A39  50                push ax
00007A3A  B8C803            mov ax,0x3c8
00007A3D  50                push ax
00007A3E  E8F33F            call word 0xba34
00007A41  83C404            add sp,byte +0x4
00007A44  8A46FE            mov al,[bp-0x2]
00007A47  30E4              xor ah,ah
00007A49  B103              mov cl,0x3
00007A4B  D3E0              shl ax,cl
00007A4D  89C3              mov bx,ax
00007A4F  81C31101          add bx,0x111
00007A53  8A4707            mov al,[bx+0x7]
00007A56  EB22              jmp short 0x7a7a
00007A58  BB2509            mov bx,0x925
00007A5B  895EFA            mov [bp-0x6],bx
00007A5E  EB2A              jmp short 0x7a8a
00007A60  BBE509            mov bx,0x9e5
00007A63  895EFA            mov [bp-0x6],bx
00007A66  EB22              jmp short 0x7a8a
00007A68  BBA50A            mov bx,0xaa5
00007A6B  895EFA            mov [bp-0x6],bx
00007A6E  EB1A              jmp short 0x7a8a
00007A70  BB650B            mov bx,0xb65
00007A73  895EFA            mov [bp-0x6],bx
00007A76  EB12              jmp short 0x7a8a
00007A78  EB10              jmp short 0x7a8a
00007A7A  2C00              sub al,0x0
00007A7C  74DA              jz 0x7a58
00007A7E  2C01              sub al,0x1
00007A80  74DE              jz 0x7a60
00007A82  2C01              sub al,0x1
00007A84  74E2              jz 0x7a68
00007A86  2C01              sub al,0x1
00007A88  74E6              jz 0x7a70
00007A8A  31C0              xor ax,ax
00007A8C  8946F6            mov [bp-0xa],ax
00007A8F  E9AB00            jmp word 0x7b3d
00007A92  8A46FE            mov al,[bp-0x2]
00007A95  30E4              xor ah,ah
00007A97  B103              mov cl,0x3
00007A99  D3E0              shl ax,cl
00007A9B  89C3              mov bx,ax
00007A9D  81C31101          add bx,0x111
00007AA1  8A4707            mov al,[bx+0x7]
00007AA4  30E4              xor ah,ah
00007AA6  89C3              mov bx,ax
00007AA8  8A87A101          mov al,[bx+0x1a1]
00007AAC  30E4              xor ah,ah
00007AAE  3B46F6            cmp ax,[bp-0xa]
00007AB1  725C              jc 0x7b0f
00007AB3  8B46F6            mov ax,[bp-0xa]
00007AB6  89C2              mov dx,ax
00007AB8  D1E0              shl ax,1
00007ABA  01D0              add ax,dx
00007ABC  0346FA            add ax,[bp-0x6]
00007ABF  89C3              mov bx,ax
00007AC1  8A07              mov al,[bx]
00007AC3  30E4              xor ah,ah
00007AC5  50                push ax
00007AC6  B8C903            mov ax,0x3c9
00007AC9  50                push ax
00007ACA  E8673F            call word 0xba34
00007ACD  83C404            add sp,byte +0x4
00007AD0  8B46F6            mov ax,[bp-0xa]
00007AD3  89C2              mov dx,ax
00007AD5  D1E0              shl ax,1
00007AD7  01D0              add ax,dx
00007AD9  40                inc ax
00007ADA  0346FA            add ax,[bp-0x6]
00007ADD  89C3              mov bx,ax
00007ADF  8A07              mov al,[bx]
00007AE1  30E4              xor ah,ah
00007AE3  50                push ax
00007AE4  B8C903            mov ax,0x3c9
00007AE7  50                push ax
00007AE8  E8493F            call word 0xba34
00007AEB  83C404            add sp,byte +0x4
00007AEE  8B46F6            mov ax,[bp-0xa]
00007AF1  89C2              mov dx,ax
00007AF3  D1E0              shl ax,1
00007AF5  01D0              add ax,dx
00007AF7  40                inc ax
00007AF8  40                inc ax
00007AF9  0346FA            add ax,[bp-0x6]
00007AFC  89C3              mov bx,ax
00007AFE  8A07              mov al,[bx]
00007B00  30E4              xor ah,ah
00007B02  50                push ax
00007B03  B8C903            mov ax,0x3c9
00007B06  50                push ax
00007B07  E82A3F            call word 0xba34
00007B0A  83C404            add sp,byte +0x4
00007B0D  EB27              jmp short 0x7b36
00007B0F  31C0              xor ax,ax
00007B11  50                push ax
00007B12  B8C903            mov ax,0x3c9
00007B15  50                push ax
00007B16  E81B3F            call word 0xba34
00007B19  83C404            add sp,byte +0x4
00007B1C  31C0              xor ax,ax
00007B1E  50                push ax
00007B1F  B8C903            mov ax,0x3c9
00007B22  50                push ax
00007B23  E80E3F            call word 0xba34
00007B26  83C404            add sp,byte +0x4
00007B29  31C0              xor ax,ax
00007B2B  50                push ax
00007B2C  B8C903            mov ax,0x3c9
00007B2F  50                push ax
00007B30  E8013F            call word 0xba34
00007B33  83C404            add sp,byte +0x4
00007B36  8B46F6            mov ax,[bp-0xa]
00007B39  40                inc ax
00007B3A  8946F6            mov [bp-0xa],ax
00007B3D  8B46F6            mov ax,[bp-0xa]
00007B40  3D0001            cmp ax,0x100
00007B43  0F824BFF          jc word 0x7a92
00007B47  8A46EF            mov al,[bp-0x11]
00007B4A  2402              and al,0x2
00007B4C  3C02              cmp al,0x2
00007B4E  750D              jnz 0x7b5d
00007B50  B80001            mov ax,0x100
00007B53  50                push ax
00007B54  31C0              xor ax,ax
00007B56  50                push ax
00007B57  E85E27            call word 0xa2b8
00007B5A  83C404            add sp,byte +0x4
00007B5D  B8DA03            mov ax,0x3da
00007B60  50                push ax
00007B61  E8BA3E            call word 0xba1e
00007B64  44                inc sp
00007B65  44                inc sp
00007B66  31C0              xor ax,ax
00007B68  8946F6            mov [bp-0xa],ax
00007B6B  EB38              jmp short 0x7ba5
00007B6D  FF76F6            push word [bp-0xa]
00007B70  B8C003            mov ax,0x3c0
00007B73  50                push ax
00007B74  E8BD3E            call word 0xba34
00007B77  83C404            add sp,byte +0x4
00007B7A  8A46F9            mov al,[bp-0x7]
00007B7D  30E4              xor ah,ah
00007B7F  B106              mov cl,0x6
00007B81  D3E0              shl ax,cl
00007B83  89C3              mov bx,ax
00007B85  81C3A501          add bx,0x1a5
00007B89  8B46F6            mov ax,[bp-0xa]
00007B8C  01C3              add bx,ax
00007B8E  8A4723            mov al,[bx+0x23]
00007B91  30E4              xor ah,ah
00007B93  50                push ax
00007B94  B8C003            mov ax,0x3c0
00007B97  50                push ax
00007B98  E8993E            call word 0xba34
00007B9B  83C404            add sp,byte +0x4
00007B9E  8B46F6            mov ax,[bp-0xa]
00007BA1  40                inc ax
00007BA2  8946F6            mov [bp-0xa],ax
00007BA5  8B46F6            mov ax,[bp-0xa]
00007BA8  3D1300            cmp ax,0x13
00007BAB  76C0              jna 0x7b6d
00007BAD  B81400            mov ax,0x14
00007BB0  50                push ax
00007BB1  B8C003            mov ax,0x3c0
00007BB4  50                push ax
00007BB5  E87C3E            call word 0xba34
00007BB8  83C404            add sp,byte +0x4
00007BBB  31C0              xor ax,ax
00007BBD  50                push ax
00007BBE  B8C003            mov ax,0x3c0
00007BC1  50                push ax
00007BC2  E86F3E            call word 0xba34
00007BC5  83C404            add sp,byte +0x4
00007BC8  31C0              xor ax,ax
00007BCA  50                push ax
00007BCB  B8C403            mov ax,0x3c4
00007BCE  50                push ax
00007BCF  E8623E            call word 0xba34
00007BD2  83C404            add sp,byte +0x4
00007BD5  B80300            mov ax,0x3
00007BD8  50                push ax
00007BD9  B8C503            mov ax,0x3c5
00007BDC  50                push ax
00007BDD  E8543E            call word 0xba34
00007BE0  83C404            add sp,byte +0x4
00007BE3  B80100            mov ax,0x1
00007BE6  8946F6            mov [bp-0xa],ax
00007BE9  EB3F              jmp short 0x7c2a
00007BEB  FF76F6            push word [bp-0xa]
00007BEE  B8C403            mov ax,0x3c4
00007BF1  50                push ax
00007BF2  E83F3E            call word 0xba34
00007BF5  83C404            add sp,byte +0x4
00007BF8  8B46F6            mov ax,[bp-0xa]
00007BFB  48                dec ax
00007BFC  50                push ax
00007BFD  8A46F9            mov al,[bp-0x7]
00007C00  30E4              xor ah,ah
00007C02  B106              mov cl,0x6
00007C04  D3E0              shl ax,cl
00007C06  89C3              mov bx,ax
00007C08  81C3A501          add bx,0x1a5
00007C0C  8B46E8            mov ax,[bp-0x18]
00007C0F  01C3              add bx,ax
00007C11  44                inc sp
00007C12  44                inc sp
00007C13  8A4705            mov al,[bx+0x5]
00007C16  30E4              xor ah,ah
00007C18  50                push ax
00007C19  B8C503            mov ax,0x3c5
00007C1C  50                push ax
00007C1D  E8143E            call word 0xba34
00007C20  83C404            add sp,byte +0x4
00007C23  8B46F6            mov ax,[bp-0xa]
00007C26  40                inc ax
00007C27  8946F6            mov [bp-0xa],ax
00007C2A  8B46F6            mov ax,[bp-0xa]
00007C2D  3D0400            cmp ax,0x4
00007C30  76B9              jna 0x7beb
00007C32  31C0              xor ax,ax
00007C34  8946F6            mov [bp-0xa],ax
00007C37  EB38              jmp short 0x7c71
00007C39  FF76F6            push word [bp-0xa]
00007C3C  B8CE03            mov ax,0x3ce
00007C3F  50                push ax
00007C40  E8F13D            call word 0xba34
00007C43  83C404            add sp,byte +0x4
00007C46  8A46F9            mov al,[bp-0x7]
00007C49  30E4              xor ah,ah
00007C4B  B106              mov cl,0x6
00007C4D  D3E0              shl ax,cl
00007C4F  89C3              mov bx,ax
00007C51  81C3A501          add bx,0x1a5
00007C55  8B46F6            mov ax,[bp-0xa]
00007C58  01C3              add bx,ax
00007C5A  8A4737            mov al,[bx+0x37]
00007C5D  30E4              xor ah,ah
00007C5F  50                push ax
00007C60  B8CF03            mov ax,0x3cf
00007C63  50                push ax
00007C64  E8CD3D            call word 0xba34
00007C67  83C404            add sp,byte +0x4
00007C6A  8B46F6            mov ax,[bp-0xa]
00007C6D  40                inc ax
00007C6E  8946F6            mov [bp-0xa],ax
00007C71  8B46F6            mov ax,[bp-0xa]
00007C74  3D0800            cmp ax,0x8
00007C77  76C0              jna 0x7c39
00007C79  8A46FE            mov al,[bp-0x2]
00007C7C  30E4              xor ah,ah
00007C7E  B103              mov cl,0x3
00007C80  D3E0              shl ax,cl
00007C82  89C3              mov bx,ax
00007C84  81C31101          add bx,0x111
00007C88  8A4702            mov al,[bx+0x2]
00007C8B  3C01              cmp al,0x1
00007C8D  7505              jnz 0x7c94
00007C8F  B8B403            mov ax,0x3b4
00007C92  EB03              jmp short 0x7c97
00007C94  B8D403            mov ax,0x3d4
00007C97  8946EA            mov [bp-0x16],ax
00007C9A  B81100            mov ax,0x11
00007C9D  50                push ax
00007C9E  FF76EA            push word [bp-0x16]
00007CA1  E8A03D            call word 0xba44
00007CA4  83C404            add sp,byte +0x4
00007CA7  31C0              xor ax,ax
00007CA9  8946F6            mov [bp-0xa],ax
00007CAC  EB38              jmp short 0x7ce6
00007CAE  FF76F6            push word [bp-0xa]
00007CB1  FF76EA            push word [bp-0x16]
00007CB4  E87D3D            call word 0xba34
00007CB7  83C404            add sp,byte +0x4
00007CBA  8A46F9            mov al,[bp-0x7]
00007CBD  30E4              xor ah,ah
00007CBF  B106              mov cl,0x6
00007CC1  D3E0              shl ax,cl
00007CC3  89C3              mov bx,ax
00007CC5  81C3A501          add bx,0x1a5
00007CC9  8B46F6            mov ax,[bp-0xa]
00007CCC  01C3              add bx,ax
00007CCE  8A470A            mov al,[bx+0xa]
00007CD1  30E4              xor ah,ah
00007CD3  50                push ax
00007CD4  8B46EA            mov ax,[bp-0x16]
00007CD7  40                inc ax
00007CD8  50                push ax
00007CD9  E8583D            call word 0xba34
00007CDC  83C404            add sp,byte +0x4
00007CDF  8B46F6            mov ax,[bp-0xa]
00007CE2  40                inc ax
00007CE3  8946F6            mov [bp-0xa],ax
00007CE6  8B46F6            mov ax,[bp-0xa]
00007CE9  3D1800            cmp ax,0x18
00007CEC  76C0              jna 0x7cae
00007CEE  8A46F9            mov al,[bp-0x7]
00007CF1  30E4              xor ah,ah
00007CF3  B106              mov cl,0x6
00007CF5  D3E0              shl ax,cl
00007CF7  89C3              mov bx,ax
00007CF9  81C3A501          add bx,0x1a5
00007CFD  8A4709            mov al,[bx+0x9]
00007D00  30E4              xor ah,ah
00007D02  50                push ax
00007D03  B8C203            mov ax,0x3c2
00007D06  50                push ax
00007D07  E82A3D            call word 0xba34
00007D0A  83C404            add sp,byte +0x4
00007D0D  B82000            mov ax,0x20
00007D10  50                push ax
00007D11  B8C003            mov ax,0x3c0
00007D14  50                push ax
00007D15  E81C3D            call word 0xba34
00007D18  83C404            add sp,byte +0x4
00007D1B  B8DA03            mov ax,0x3da
00007D1E  50                push ax
00007D1F  E8FC3C            call word 0xba1e
00007D22  44                inc sp
00007D23  44                inc sp
00007D24  8A46FF            mov al,[bp-0x1]
00007D27  84C0              test al,al
00007D29  0F85C100          jnz word 0x7dee
00007D2D  8A46FE            mov al,[bp-0x2]
00007D30  30E4              xor ah,ah
00007D32  B103              mov cl,0x3
00007D34  D3E0              shl ax,cl
00007D36  89C3              mov bx,ax
00007D38  81C31101          add bx,0x111
00007D3C  8A4701            mov al,[bx+0x1]
00007D3F  84C0              test al,al
00007D41  7526              jnz 0x7d69
00007D43  B80040            mov ax,0x4000
00007D46  50                push ax
00007D47  B82007            mov ax,0x720
00007D4A  50                push ax
00007D4B  31C0              xor ax,ax
00007D4D  50                push ax
00007D4E  8A46FE            mov al,[bp-0x2]
00007D51  30E4              xor ah,ah
00007D53  B103              mov cl,0x3
00007D55  D3E0              shl ax,cl
00007D57  89C3              mov bx,ax
00007D59  81C31101          add bx,0x111
00007D5D  FF7704            push word [bx+0x4]
00007D60  E8E03B            call word 0xb943
00007D63  83C408            add sp,byte +0x8
00007D66  E98500            jmp word 0x7dee
00007D69  8A4604            mov al,[bp+0x4]
00007D6C  3C0D              cmp al,0xd
00007D6E  7324              jnc 0x7d94
00007D70  B80040            mov ax,0x4000
00007D73  50                push ax
00007D74  31C0              xor ax,ax
00007D76  50                push ax
00007D77  31C0              xor ax,ax
00007D79  50                push ax
00007D7A  8A46FE            mov al,[bp-0x2]
00007D7D  30E4              xor ah,ah
00007D7F  B103              mov cl,0x3
00007D81  D3E0              shl ax,cl
00007D83  89C3              mov bx,ax
00007D85  81C31101          add bx,0x111
00007D89  FF7704            push word [bx+0x4]
00007D8C  E8B43B            call word 0xb943
00007D8F  83C408            add sp,byte +0x8
00007D92  EB5A              jmp short 0x7dee
00007D94  B80200            mov ax,0x2
00007D97  50                push ax
00007D98  B8C403            mov ax,0x3c4
00007D9B  50                push ax
00007D9C  E8953C            call word 0xba34
00007D9F  83C404            add sp,byte +0x4
00007DA2  B8C503            mov ax,0x3c5
00007DA5  50                push ax
00007DA6  E8753C            call word 0xba1e
00007DA9  44                inc sp
00007DAA  44                inc sp
00007DAB  8846FD            mov [bp-0x3],al
00007DAE  B80F00            mov ax,0xf
00007DB1  50                push ax
00007DB2  B8C503            mov ax,0x3c5
00007DB5  50                push ax
00007DB6  E87B3C            call word 0xba34
00007DB9  83C404            add sp,byte +0x4
00007DBC  B80080            mov ax,0x8000
00007DBF  50                push ax
00007DC0  31C0              xor ax,ax
00007DC2  50                push ax
00007DC3  31C0              xor ax,ax
00007DC5  50                push ax
00007DC6  8A46FE            mov al,[bp-0x2]
00007DC9  30E4              xor ah,ah
00007DCB  B103              mov cl,0x3
00007DCD  D3E0              shl ax,cl
00007DCF  89C3              mov bx,ax
00007DD1  81C31101          add bx,0x111
00007DD5  FF7704            push word [bx+0x4]
00007DD8  E8683B            call word 0xb943
00007DDB  83C408            add sp,byte +0x8
00007DDE  8A46FD            mov al,[bp-0x3]
00007DE1  30E4              xor ah,ah
00007DE3  50                push ax
00007DE4  B8C503            mov ax,0x3c5
00007DE7  50                push ax
00007DE8  E8493C            call word 0xba34
00007DEB  83C404            add sp,byte +0x4
00007DEE  8A4604            mov al,[bp+0x4]
00007DF1  30E4              xor ah,ah
00007DF3  50                push ax
00007DF4  B84900            mov ax,0x49
00007DF7  50                push ax
00007DF8  B84000            mov ax,0x40
00007DFB  50                push ax
00007DFC  E8EF3B            call word 0xb9ee
00007DFF  83C406            add sp,byte +0x6
00007E02  FF76F4            push word [bp-0xc]
00007E05  B84A00            mov ax,0x4a
00007E08  50                push ax
00007E09  B84000            mov ax,0x40
00007E0C  50                push ax
00007E0D  E8F63B            call word 0xba06
00007E10  83C406            add sp,byte +0x6
00007E13  8A46F9            mov al,[bp-0x7]
00007E16  30E4              xor ah,ah
00007E18  B106              mov cl,0x6
00007E1A  D3E0              shl ax,cl
00007E1C  89C3              mov bx,ax
00007E1E  81C3A501          add bx,0x1a5
00007E22  FF7703            push word [bx+0x3]
00007E25  B84C00            mov ax,0x4c
00007E28  50                push ax
00007E29  B84000            mov ax,0x40
00007E2C  50                push ax
00007E2D  E8D63B            call word 0xba06
00007E30  83C406            add sp,byte +0x6
00007E33  FF76EA            push word [bp-0x16]
00007E36  B86300            mov ax,0x63
00007E39  50                push ax
00007E3A  B84000            mov ax,0x40
00007E3D  50                push ax
00007E3E  E8C53B            call word 0xba06
00007E41  83C406            add sp,byte +0x6
00007E44  FF76F2            push word [bp-0xe]
00007E47  B88400            mov ax,0x84
00007E4A  50                push ax
00007E4B  B84000            mov ax,0x40
00007E4E  50                push ax
00007E4F  E89C3B            call word 0xb9ee
00007E52  83C406            add sp,byte +0x6
00007E55  FF76F0            push word [bp-0x10]
00007E58  B88500            mov ax,0x85
00007E5B  50                push ax
00007E5C  B84000            mov ax,0x40
00007E5F  50                push ax
00007E60  E8A33B            call word 0xba06
00007E63  83C406            add sp,byte +0x6
00007E66  8A46FF            mov al,[bp-0x1]
00007E69  0C60              or al,0x60
00007E6B  30E4              xor ah,ah
00007E6D  50                push ax
00007E6E  B88700            mov ax,0x87
00007E71  50                push ax
00007E72  B84000            mov ax,0x40
00007E75  50                push ax
00007E76  E8753B            call word 0xb9ee
00007E79  83C406            add sp,byte +0x6
00007E7C  B8F900            mov ax,0xf9
00007E7F  50                push ax
00007E80  B88800            mov ax,0x88
00007E83  50                push ax
00007E84  B84000            mov ax,0x40
00007E87  50                push ax
00007E88  E8633B            call word 0xb9ee
00007E8B  83C406            add sp,byte +0x6
00007E8E  B88900            mov ax,0x89
00007E91  50                push ax
00007E92  B84000            mov ax,0x40
00007E95  50                push ax
00007E96  E82F3B            call word 0xb9c8
00007E99  83C404            add sp,byte +0x4
00007E9C  247F              and al,0x7f
00007E9E  30E4              xor ah,ah
00007EA0  50                push ax
00007EA1  B88900            mov ax,0x89
00007EA4  50                push ax
00007EA5  B84000            mov ax,0x40
00007EA8  50                push ax
00007EA9  E8423B            call word 0xb9ee
00007EAC  83C406            add sp,byte +0x6
00007EAF  B80800            mov ax,0x8
00007EB2  50                push ax
00007EB3  B88A00            mov ax,0x8a
00007EB6  50                push ax
00007EB7  B84000            mov ax,0x40
00007EBA  50                push ax
00007EBB  E8303B            call word 0xb9ee
00007EBE  83C406            add sp,byte +0x6
00007EC1  BB6237            mov bx,0x3762
00007EC4  53                push bx
00007EC5  B8A800            mov ax,0xa8
00007EC8  50                push ax
00007EC9  B84000            mov ax,0x40
00007ECC  50                push ax
00007ECD  E8363B            call word 0xba06
00007ED0  83C406            add sp,byte +0x6
00007ED3  B800C0            mov ax,0xc000
00007ED6  50                push ax
00007ED7  B8AA00            mov ax,0xaa
00007EDA  50                push ax
00007EDB  B84000            mov ax,0x40
00007EDE  50                push ax
00007EDF  E8243B            call word 0xba06
00007EE2  83C406            add sp,byte +0x6
00007EE5  31C0              xor ax,ax
00007EE7  50                push ax
00007EE8  B86500            mov ax,0x65
00007EEB  50                push ax
00007EEC  B84000            mov ax,0x40
00007EEF  50                push ax
00007EF0  E8FB3A            call word 0xb9ee
00007EF3  83C406            add sp,byte +0x6
00007EF6  31C0              xor ax,ax
00007EF8  50                push ax
00007EF9  B86600            mov ax,0x66
00007EFC  50                push ax
00007EFD  B84000            mov ax,0x40
00007F00  50                push ax
00007F01  E8EA3A            call word 0xb9ee
00007F04  83C406            add sp,byte +0x6
00007F07  8A46FE            mov al,[bp-0x2]
00007F0A  30E4              xor ah,ah
00007F0C  B103              mov cl,0x3
00007F0E  D3E0              shl ax,cl
00007F10  89C3              mov bx,ax
00007F12  81C31101          add bx,0x111
00007F16  8A4701            mov al,[bx+0x1]
00007F19  84C0              test al,al
00007F1B  750E              jnz 0x7f2b
00007F1D  B80700            mov ax,0x7
00007F20  50                push ax
00007F21  B80600            mov ax,0x6
00007F24  50                push ax
00007F25  E8BA00            call word 0x7fe2
00007F28  83C404            add sp,byte +0x4
00007F2B  31C0              xor ax,ax
00007F2D  8946F6            mov [bp-0xa],ax
00007F30  EB13              jmp short 0x7f45
00007F32  31C0              xor ax,ax
00007F34  50                push ax
00007F35  FF76F6            push word [bp-0xa]
00007F38  E8C201            call word 0x80fd
00007F3B  83C404            add sp,byte +0x4
00007F3E  8B46F6            mov ax,[bp-0xa]
00007F41  40                inc ax
00007F42  8946F6            mov [bp-0xa],ax
00007F45  8B46F6            mov ax,[bp-0xa]
00007F48  3D0800            cmp ax,0x8
00007F4B  72E5              jc 0x7f32
00007F4D  31C0              xor ax,ax
00007F4F  50                push ax
00007F50  E81F03            call word 0x8272
00007F53  44                inc sp
00007F54  44                inc sp
00007F55  8A46FE            mov al,[bp-0x2]
00007F58  30E4              xor ah,ah
00007F5A  B103              mov cl,0x3
00007F5C  D3E0              shl ax,cl
00007F5E  89C3              mov bx,ax
00007F60  81C31101          add bx,0x111
00007F64  8A4701            mov al,[bx+0x1]
00007F67  84C0              test al,al
00007F69  750E              jnz 0x7f79
00007F6B  B80411            mov ax,0x1104
00007F6E  B300              mov bl,0x0
00007F70  CD10              int 0x10
00007F72  B80311            mov ax,0x1103
00007F75  B300              mov bl,0x0
00007F77  CD10              int 0x10
00007F79  1E                push ds
00007F7A  31C0              xor ax,ax
00007F7C  8ED8              mov ds,ax
00007F7E  B87512            mov ax,0x1275
00007F81  A37C00            mov [0x7c],ax
00007F84  B800C0            mov ax,0xc000
00007F87  A37E00            mov [0x7e],ax
00007F8A  1F                pop ds
00007F8B  8B46F0            mov ax,[bp-0x10]
00007F8E  E93E00            jmp word 0x7fcf
00007F91  1E                push ds
00007F92  31C0              xor ax,ax
00007F94  8ED8              mov ds,ax
00007F96  B8750E            mov ax,0xe75
00007F99  A30C01            mov [0x10c],ax
00007F9C  B800C0            mov ax,0xc000
00007F9F  A30E01            mov [0x10e],ax
00007FA2  1F                pop ds
00007FA3  EB39              jmp short 0x7fde
00007FA5  1E                push ds
00007FA6  31C0              xor ax,ax
00007FA8  8ED8              mov ds,ax
00007FAA  B87516            mov ax,0x1675
00007FAD  A30C01            mov [0x10c],ax
00007FB0  B800C0            mov ax,0xc000
00007FB3  A30E01            mov [0x10e],ax
00007FB6  1F                pop ds
00007FB7  EB25              jmp short 0x7fde
00007FB9  1E                push ds
00007FBA  31C0              xor ax,ax
00007FBC  8ED8              mov ds,ax
00007FBE  B87524            mov ax,0x2475
00007FC1  A30C01            mov [0x10c],ax
00007FC4  B800C0            mov ax,0xc000
00007FC7  A30E01            mov [0x10e],ax
00007FCA  1F                pop ds
00007FCB  EB11              jmp short 0x7fde
00007FCD  EB0F              jmp short 0x7fde
00007FCF  2D0800            sub ax,0x8
00007FD2  74BD              jz 0x7f91
00007FD4  2D0600            sub ax,0x6
00007FD7  74CC              jz 0x7fa5
00007FD9  2D0200            sub ax,0x2
00007FDC  74DB              jz 0x7fb9
00007FDE  89EC              mov sp,bp
00007FE0  5D                pop bp
00007FE1  C3                ret
00007FE2  55                push bp
00007FE3  89E5              mov bp,sp
00007FE5  83C4F8            add sp,byte -0x8
00007FE8  8A4604            mov al,[bp+0x4]
00007FEB  243F              and al,0x3f
00007FED  884604            mov [bp+0x4],al
00007FF0  8A4606            mov al,[bp+0x6]
00007FF3  241F              and al,0x1f
00007FF5  884606            mov [bp+0x6],al
00007FF8  8A4604            mov al,[bp+0x4]
00007FFB  30E4              xor ah,ah
00007FFD  88C4              mov ah,al
00007FFF  30C0              xor al,al
00008001  024606            add al,[bp+0x6]
00008004  80D400            adc ah,0x0
00008007  8946FC            mov [bp-0x4],ax
0000800A  FF76FC            push word [bp-0x4]
0000800D  B86000            mov ax,0x60
00008010  50                push ax
00008011  B84000            mov ax,0x40
00008014  50                push ax
00008015  E8EE39            call word 0xba06
00008018  83C406            add sp,byte +0x6
0000801B  B88900            mov ax,0x89
0000801E  50                push ax
0000801F  B84000            mov ax,0x40
00008022  50                push ax
00008023  E8A239            call word 0xb9c8
00008026  83C404            add sp,byte +0x4
00008029  8846F9            mov [bp-0x7],al
0000802C  B88500            mov ax,0x85
0000802F  50                push ax
00008030  B84000            mov ax,0x40
00008033  50                push ax
00008034  E8A439            call word 0xb9db
00008037  83C404            add sp,byte +0x4
0000803A  8946FE            mov [bp-0x2],ax
0000803D  8A46F9            mov al,[bp-0x7]
00008040  2401              and al,0x1
00008042  84C0              test al,al
00008044  7466              jz 0x80ac
00008046  8B46FE            mov ax,[bp-0x2]
00008049  3D0800            cmp ax,0x8
0000804C  765E              jna 0x80ac
0000804E  8A4606            mov al,[bp+0x6]
00008051  3C08              cmp al,0x8
00008053  7357              jnc 0x80ac
00008055  8A4604            mov al,[bp+0x4]
00008058  3C20              cmp al,0x20
0000805A  7350              jnc 0x80ac
0000805C  8A4604            mov al,[bp+0x4]
0000805F  30E4              xor ah,ah
00008061  40                inc ax
00008062  50                push ax
00008063  8A4606            mov al,[bp+0x6]
00008066  30E4              xor ah,ah
00008068  3B46F6            cmp ax,[bp-0xa]
0000806B  8D66F8            lea sp,[bp-0x8]
0000806E  7415              jz 0x8085
00008070  8A4604            mov al,[bp+0x4]
00008073  30E4              xor ah,ah
00008075  40                inc ax
00008076  8B4EFE            mov cx,[bp-0x2]
00008079  F7E9              imul cx
0000807B  B103              mov cl,0x3
0000807D  D3E8              shr ax,cl
0000807F  48                dec ax
00008080  884604            mov [bp+0x4],al
00008083  EB14              jmp short 0x8099
00008085  8A4606            mov al,[bp+0x6]
00008088  30E4              xor ah,ah
0000808A  40                inc ax
0000808B  8B4EFE            mov cx,[bp-0x2]
0000808E  F7E9              imul cx
00008090  B103              mov cl,0x3
00008092  D3E8              shr ax,cl
00008094  48                dec ax
00008095  48                dec ax
00008096  884604            mov [bp+0x4],al
00008099  8A4606            mov al,[bp+0x6]
0000809C  30E4              xor ah,ah
0000809E  40                inc ax
0000809F  8B4EFE            mov cx,[bp-0x2]
000080A2  F7E9              imul cx
000080A4  B103              mov cl,0x3
000080A6  D3E8              shr ax,cl
000080A8  48                dec ax
000080A9  884606            mov [bp+0x6],al
000080AC  B86300            mov ax,0x63
000080AF  50                push ax
000080B0  B84000            mov ax,0x40
000080B3  50                push ax
000080B4  E82439            call word 0xb9db
000080B7  83C404            add sp,byte +0x4
000080BA  8946FA            mov [bp-0x6],ax
000080BD  B80A00            mov ax,0xa
000080C0  50                push ax
000080C1  FF76FA            push word [bp-0x6]
000080C4  E86D39            call word 0xba34
000080C7  83C404            add sp,byte +0x4
000080CA  8A4604            mov al,[bp+0x4]
000080CD  30E4              xor ah,ah
000080CF  50                push ax
000080D0  8B46FA            mov ax,[bp-0x6]
000080D3  40                inc ax
000080D4  50                push ax
000080D5  E85C39            call word 0xba34
000080D8  83C404            add sp,byte +0x4
000080DB  B80B00            mov ax,0xb
000080DE  50                push ax
000080DF  FF76FA            push word [bp-0x6]
000080E2  E84F39            call word 0xba34
000080E5  83C404            add sp,byte +0x4
000080E8  8A4606            mov al,[bp+0x6]
000080EB  30E4              xor ah,ah
000080ED  50                push ax
000080EE  8B46FA            mov ax,[bp-0x6]
000080F1  40                inc ax
000080F2  50                push ax
000080F3  E83E39            call word 0xba34
000080F6  83C404            add sp,byte +0x4
000080F9  89EC              mov sp,bp
000080FB  5D                pop bp
000080FC  C3                ret
000080FD  55                push bp
000080FE  89E5              mov bp,sp
00008100  83C4F4            add sp,byte -0xc
00008103  8A4604            mov al,[bp+0x4]
00008106  3C07              cmp al,0x7
00008108  7604              jna 0x810e
0000810A  89EC              mov sp,bp
0000810C  5D                pop bp
0000810D  C3                ret
0000810E  FF7606            push word [bp+0x6]
00008111  8A4604            mov al,[bp+0x4]
00008114  30E4              xor ah,ah
00008116  D1E0              shl ax,1
00008118  055000            add ax,0x50
0000811B  50                push ax
0000811C  B84000            mov ax,0x40
0000811F  50                push ax
00008120  E8E338            call word 0xba06
00008123  83C406            add sp,byte +0x6
00008126  B86200            mov ax,0x62
00008129  50                push ax
0000812A  B84000            mov ax,0x40
0000812D  50                push ax
0000812E  E89738            call word 0xb9c8
00008131  83C404            add sp,byte +0x4
00008134  8846FD            mov [bp-0x3],al
00008137  8A4604            mov al,[bp+0x4]
0000813A  3A46FD            cmp al,[bp-0x3]
0000813D  0F85B800          jnz word 0x81f9
00008141  B84A00            mov ax,0x4a
00008144  50                push ax
00008145  B84000            mov ax,0x40
00008148  50                push ax
00008149  E88F38            call word 0xb9db
0000814C  83C404            add sp,byte +0x4
0000814F  8946FA            mov [bp-0x6],ax
00008152  B88400            mov ax,0x84
00008155  50                push ax
00008156  B84000            mov ax,0x40
00008159  50                push ax
0000815A  E86B38            call word 0xb9c8
0000815D  83C404            add sp,byte +0x4
00008160  30E4              xor ah,ah
00008162  40                inc ax
00008163  8946F8            mov [bp-0x8],ax
00008166  8A4606            mov al,[bp+0x6]
00008169  8846FF            mov [bp-0x1],al
0000816C  8B4606            mov ax,[bp+0x6]
0000816F  30C0              xor al,al
00008171  88E0              mov al,ah
00008173  30E4              xor ah,ah
00008175  8846FE            mov [bp-0x2],al
00008178  8A46FE            mov al,[bp-0x2]
0000817B  30E4              xor ah,ah
0000817D  8B4EFA            mov cx,[bp-0x6]
00008180  F7E9              imul cx
00008182  50                push ax
00008183  8B46FA            mov ax,[bp-0x6]
00008186  8B4EF8            mov cx,[bp-0x8]
00008189  F7E9              imul cx
0000818B  0CFF              or al,0xff
0000818D  89C3              mov bx,ax
0000818F  8A4604            mov al,[bp+0x4]
00008192  30E4              xor ah,ah
00008194  93                xchg ax,bx
00008195  40                inc ax
00008196  89D9              mov cx,bx
00008198  F7E9              imul cx
0000819A  0246FF            add al,[bp-0x1]
0000819D  80D400            adc ah,0x0
000081A0  0346F2            add ax,[bp-0xe]
000081A3  44                inc sp
000081A4  44                inc sp
000081A5  8946F6            mov [bp-0xa],ax
000081A8  B86300            mov ax,0x63
000081AB  50                push ax
000081AC  B84000            mov ax,0x40
000081AF  50                push ax
000081B0  E82838            call word 0xb9db
000081B3  83C404            add sp,byte +0x4
000081B6  8946F4            mov [bp-0xc],ax
000081B9  B80E00            mov ax,0xe
000081BC  50                push ax
000081BD  FF76F4            push word [bp-0xc]
000081C0  E87138            call word 0xba34
000081C3  83C404            add sp,byte +0x4
000081C6  8B46F6            mov ax,[bp-0xa]
000081C9  30C0              xor al,al
000081CB  88E0              mov al,ah
000081CD  30E4              xor ah,ah
000081CF  50                push ax
000081D0  8B46F4            mov ax,[bp-0xc]
000081D3  40                inc ax
000081D4  50                push ax
000081D5  E85C38            call word 0xba34
000081D8  83C404            add sp,byte +0x4
000081DB  B80F00            mov ax,0xf
000081DE  50                push ax
000081DF  FF76F4            push word [bp-0xc]
000081E2  E84F38            call word 0xba34
000081E5  83C404            add sp,byte +0x4
000081E8  8A46F6            mov al,[bp-0xa]
000081EB  30E4              xor ah,ah
000081ED  50                push ax
000081EE  8B46F4            mov ax,[bp-0xc]
000081F1  40                inc ax
000081F2  50                push ax
000081F3  E83E38            call word 0xba34
000081F6  83C404            add sp,byte +0x4
000081F9  89EC              mov sp,bp
000081FB  5D                pop bp
000081FC  C3                ret
000081FD  55                push bp
000081FE  89E5              mov bp,sp
00008200  4C                dec sp
00008201  4C                dec sp
00008202  E84F38            call word 0xba54
00008205  8946FE            mov [bp-0x2],ax
00008208  31C0              xor ax,ax
0000820A  50                push ax
0000820B  FF7606            push word [bp+0x6]
0000820E  FF76FE            push word [bp-0x2]
00008211  E8F237            call word 0xba06
00008214  83C406            add sp,byte +0x6
00008217  31C0              xor ax,ax
00008219  50                push ax
0000821A  FF7608            push word [bp+0x8]
0000821D  FF76FE            push word [bp-0x2]
00008220  E8E337            call word 0xba06
00008223  83C406            add sp,byte +0x6
00008226  8A4604            mov al,[bp+0x4]
00008229  3C07              cmp al,0x7
0000822B  7604              jna 0x8231
0000822D  89EC              mov sp,bp
0000822F  5D                pop bp
00008230  C3                ret
00008231  B86000            mov ax,0x60
00008234  50                push ax
00008235  B84000            mov ax,0x40
00008238  50                push ax
00008239  E89F37            call word 0xb9db
0000823C  83C404            add sp,byte +0x4
0000823F  50                push ax
00008240  FF7606            push word [bp+0x6]
00008243  FF76FE            push word [bp-0x2]
00008246  E8BD37            call word 0xba06
00008249  83C406            add sp,byte +0x6
0000824C  8A4604            mov al,[bp+0x4]
0000824F  30E4              xor ah,ah
00008251  D1E0              shl ax,1
00008253  055000            add ax,0x50
00008256  50                push ax
00008257  B84000            mov ax,0x40
0000825A  50                push ax
0000825B  E87D37            call word 0xb9db
0000825E  83C404            add sp,byte +0x4
00008261  50                push ax
00008262  FF7608            push word [bp+0x8]
00008265  FF76FE            push word [bp-0x2]
00008268  E89B37            call word 0xba06
0000826B  83C406            add sp,byte +0x6
0000826E  89EC              mov sp,bp
00008270  5D                pop bp
00008271  C3                ret
00008272  55                push bp
00008273  89E5              mov bp,sp
00008275  83C4F2            add sp,byte -0xe
00008278  8A4604            mov al,[bp+0x4]
0000827B  3C07              cmp al,0x7
0000827D  7604              jna 0x8283
0000827F  89EC              mov sp,bp
00008281  5D                pop bp
00008282  C3                ret
00008283  B84900            mov ax,0x49
00008286  50                push ax
00008287  B84000            mov ax,0x40
0000828A  50                push ax
0000828B  E83A37            call word 0xb9c8
0000828E  83C404            add sp,byte +0x4
00008291  8800              mov [bx+si],al
00008293  0000              add [bx+si],al
00008295  0000              add [bx+si],al
00008297  0000              add [bx+si],al
00008299  0000              add [bx+si],al
0000829B  0000              add [bx+si],al
0000829D  0000              add [bx+si],al
0000829F  0000              add [bx+si],al
000082A1  0000              add [bx+si],al
000082A3  0000              add [bx+si],al
000082A5  0000              add [bx+si],al
000082A7  0000              add [bx+si],al
000082A9  0000              add [bx+si],al
000082AB  0000              add [bx+si],al
000082AD  0000              add [bx+si],al
000082AF  0000              add [bx+si],al
000082B1  0000              add [bx+si],al
000082B3  0000              add [bx+si],al
000082B5  0000              add [bx+si],al
000082B7  0000              add [bx+si],al
000082B9  0000              add [bx+si],al
000082BB  0000              add [bx+si],al
000082BD  0000              add [bx+si],al
000082BF  0000              add [bx+si],al
000082C1  0000              add [bx+si],al
000082C3  0000              add [bx+si],al
000082C5  0000              add [bx+si],al
000082C7  0000              add [bx+si],al
000082C9  0000              add [bx+si],al
000082CB  0000              add [bx+si],al
000082CD  0000              add [bx+si],al
000082CF  0000              add [bx+si],al
000082D1  0000              add [bx+si],al
000082D3  0000              add [bx+si],al
000082D5  0000              add [bx+si],al
000082D7  0000              add [bx+si],al
000082D9  0000              add [bx+si],al
000082DB  0000              add [bx+si],al
000082DD  0000              add [bx+si],al
000082DF  0000              add [bx+si],al
000082E1  0000              add [bx+si],al
000082E3  0000              add [bx+si],al
000082E5  0000              add [bx+si],al
000082E7  0000              add [bx+si],al
000082E9  0000              add [bx+si],al
000082EB  0000              add [bx+si],al
000082ED  0000              add [bx+si],al
000082EF  0000              add [bx+si],al
000082F1  0000              add [bx+si],al
000082F3  0000              add [bx+si],al
000082F5  0000              add [bx+si],al
000082F7  0000              add [bx+si],al
000082F9  0000              add [bx+si],al
000082FB  0000              add [bx+si],al
000082FD  0000              add [bx+si],al
000082FF  0000              add [bx+si],al
00008301  0000              add [bx+si],al
00008303  0000              add [bx+si],al
00008305  0000              add [bx+si],al
00008307  0000              add [bx+si],al
00008309  0000              add [bx+si],al
0000830B  0000              add [bx+si],al
0000830D  0000              add [bx+si],al
0000830F  0000              add [bx+si],al
00008311  0000              add [bx+si],al
00008313  0000              add [bx+si],al
00008315  0000              add [bx+si],al
00008317  0000              add [bx+si],al
00008319  0000              add [bx+si],al
0000831B  0000              add [bx+si],al
0000831D  0000              add [bx+si],al
0000831F  0000              add [bx+si],al
00008321  0000              add [bx+si],al
00008323  0000              add [bx+si],al
00008325  0000              add [bx+si],al
00008327  0000              add [bx+si],al
00008329  0000              add [bx+si],al
0000832B  0000              add [bx+si],al
0000832D  0000              add [bx+si],al
0000832F  0000              add [bx+si],al
00008331  0000              add [bx+si],al
00008333  0000              add [bx+si],al
00008335  0000              add [bx+si],al
00008337  0000              add [bx+si],al
00008339  0000              add [bx+si],al
0000833B  0000              add [bx+si],al
0000833D  0000              add [bx+si],al
0000833F  0000              add [bx+si],al
00008341  0000              add [bx+si],al
00008343  0000              add [bx+si],al
00008345  0000              add [bx+si],al
00008347  0000              add [bx+si],al
00008349  0000              add [bx+si],al
0000834B  0000              add [bx+si],al
0000834D  0000              add [bx+si],al
0000834F  0000              add [bx+si],al
00008351  0000              add [bx+si],al
00008353  0000              add [bx+si],al
00008355  0000              add [bx+si],al
00008357  0000              add [bx+si],al
00008359  0000              add [bx+si],al
0000835B  0000              add [bx+si],al
0000835D  0000              add [bx+si],al
0000835F  0000              add [bx+si],al
00008361  0000              add [bx+si],al
00008363  0000              add [bx+si],al
00008365  0000              add [bx+si],al
00008367  0000              add [bx+si],al
00008369  0000              add [bx+si],al
0000836B  0000              add [bx+si],al
0000836D  0000              add [bx+si],al
0000836F  0000              add [bx+si],al
00008371  0000              add [bx+si],al
00008373  0000              add [bx+si],al
00008375  0000              add [bx+si],al
00008377  0000              add [bx+si],al
00008379  0000              add [bx+si],al
0000837B  0000              add [bx+si],al
0000837D  0000              add [bx+si],al
0000837F  0000              add [bx+si],al
00008381  0000              add [bx+si],al
00008383  0000              add [bx+si],al
00008385  0000              add [bx+si],al
00008387  0000              add [bx+si],al
00008389  0000              add [bx+si],al
0000838B  0000              add [bx+si],al
0000838D  0000              add [bx+si],al
0000838F  0000              add [bx+si],al
00008391  0000              add [bx+si],al
00008393  0000              add [bx+si],al
00008395  0000              add [bx+si],al
00008397  0000              add [bx+si],al
00008399  0000              add [bx+si],al
0000839B  0000              add [bx+si],al
0000839D  0000              add [bx+si],al
0000839F  0000              add [bx+si],al
000083A1  0000              add [bx+si],al
000083A3  0000              add [bx+si],al
000083A5  0000              add [bx+si],al
000083A7  0000              add [bx+si],al
000083A9  0000              add [bx+si],al
000083AB  0000              add [bx+si],al
000083AD  0000              add [bx+si],al
000083AF  0000              add [bx+si],al
000083B1  0000              add [bx+si],al
000083B3  0000              add [bx+si],al
000083B5  0000              add [bx+si],al
000083B7  0000              add [bx+si],al
000083B9  0000              add [bx+si],al
000083BB  0000              add [bx+si],al
000083BD  0000              add [bx+si],al
000083BF  0000              add [bx+si],al
000083C1  0000              add [bx+si],al
000083C3  0000              add [bx+si],al
000083C5  0000              add [bx+si],al
000083C7  0000              add [bx+si],al
000083C9  0000              add [bx+si],al
000083CB  0000              add [bx+si],al
000083CD  0000              add [bx+si],al
000083CF  0000              add [bx+si],al
000083D1  0000              add [bx+si],al
000083D3  0000              add [bx+si],al
000083D5  0000              add [bx+si],al
000083D7  0000              add [bx+si],al
000083D9  0000              add [bx+si],al
000083DB  0000              add [bx+si],al
000083DD  0000              add [bx+si],al
000083DF  0000              add [bx+si],al
000083E1  0000              add [bx+si],al
000083E3  0000              add [bx+si],al
000083E5  0000              add [bx+si],al
000083E7  0000              add [bx+si],al
000083E9  0000              add [bx+si],al
000083EB  0000              add [bx+si],al
000083ED  0000              add [bx+si],al
000083EF  0000              add [bx+si],al
000083F1  0000              add [bx+si],al
000083F3  0000              add [bx+si],al
000083F5  0000              add [bx+si],al
000083F7  0000              add [bx+si],al
000083F9  0000              add [bx+si],al
000083FB  0000              add [bx+si],al
000083FD  0000              add [bx+si],al
000083FF  0000              add [bx+si],al
00008401  0000              add [bx+si],al
00008403  0000              add [bx+si],al
00008405  0000              add [bx+si],al
00008407  0000              add [bx+si],al
00008409  0000              add [bx+si],al
0000840B  0000              add [bx+si],al
0000840D  0000              add [bx+si],al
0000840F  0000              add [bx+si],al
00008411  0000              add [bx+si],al
00008413  0000              add [bx+si],al
00008415  0000              add [bx+si],al
00008417  0000              add [bx+si],al
00008419  0000              add [bx+si],al
0000841B  0000              add [bx+si],al
0000841D  0000              add [bx+si],al
0000841F  0000              add [bx+si],al
00008421  0000              add [bx+si],al
00008423  0000              add [bx+si],al
00008425  0000              add [bx+si],al
00008427  0000              add [bx+si],al
00008429  0000              add [bx+si],al
0000842B  0000              add [bx+si],al
0000842D  0000              add [bx+si],al
0000842F  0000              add [bx+si],al
00008431  0000              add [bx+si],al
00008433  0000              add [bx+si],al
00008435  0000              add [bx+si],al
00008437  0000              add [bx+si],al
00008439  0000              add [bx+si],al
0000843B  0000              add [bx+si],al
0000843D  0000              add [bx+si],al
0000843F  0000              add [bx+si],al
00008441  0000              add [bx+si],al
00008443  0000              add [bx+si],al
00008445  0000              add [bx+si],al
00008447  0000              add [bx+si],al
00008449  0000              add [bx+si],al
0000844B  0000              add [bx+si],al
0000844D  0000              add [bx+si],al
0000844F  0000              add [bx+si],al
00008451  0000              add [bx+si],al
00008453  0000              add [bx+si],al
00008455  0000              add [bx+si],al
00008457  0000              add [bx+si],al
00008459  0000              add [bx+si],al
0000845B  0000              add [bx+si],al
0000845D  0000              add [bx+si],al
0000845F  0000              add [bx+si],al
00008461  0000              add [bx+si],al
00008463  0000              add [bx+si],al
00008465  0000              add [bx+si],al
00008467  0000              add [bx+si],al
00008469  0000              add [bx+si],al
0000846B  0000              add [bx+si],al
0000846D  0000              add [bx+si],al
0000846F  0000              add [bx+si],al
00008471  0000              add [bx+si],al
00008473  0000              add [bx+si],al
00008475  0000              add [bx+si],al
00008477  0000              add [bx+si],al
00008479  0000              add [bx+si],al
0000847B  0000              add [bx+si],al
0000847D  0000              add [bx+si],al
0000847F  0000              add [bx+si],al
00008481  0000              add [bx+si],al
00008483  0000              add [bx+si],al
00008485  0000              add [bx+si],al
00008487  0000              add [bx+si],al
00008489  0000              add [bx+si],al
0000848B  0000              add [bx+si],al
0000848D  0000              add [bx+si],al
0000848F  0000              add [bx+si],al
00008491  0000              add [bx+si],al
00008493  0000              add [bx+si],al
00008495  0000              add [bx+si],al
00008497  0000              add [bx+si],al
00008499  0000              add [bx+si],al
0000849B  0000              add [bx+si],al
0000849D  0000              add [bx+si],al
0000849F  0000              add [bx+si],al
000084A1  0000              add [bx+si],al
000084A3  0000              add [bx+si],al
000084A5  0000              add [bx+si],al
000084A7  0000              add [bx+si],al
000084A9  0000              add [bx+si],al
000084AB  0000              add [bx+si],al
000084AD  0000              add [bx+si],al
000084AF  0000              add [bx+si],al
000084B1  0000              add [bx+si],al
000084B3  0000              add [bx+si],al
000084B5  0000              add [bx+si],al
000084B7  0000              add [bx+si],al
000084B9  0000              add [bx+si],al
000084BB  0000              add [bx+si],al
000084BD  0000              add [bx+si],al
000084BF  0000              add [bx+si],al
000084C1  0000              add [bx+si],al
000084C3  0000              add [bx+si],al
000084C5  0000              add [bx+si],al
000084C7  0000              add [bx+si],al
000084C9  0000              add [bx+si],al
000084CB  0000              add [bx+si],al
000084CD  0000              add [bx+si],al
000084CF  0000              add [bx+si],al
000084D1  0000              add [bx+si],al
000084D3  0000              add [bx+si],al
000084D5  0000              add [bx+si],al
000084D7  0000              add [bx+si],al
000084D9  0000              add [bx+si],al
000084DB  0000              add [bx+si],al
000084DD  0000              add [bx+si],al
000084DF  0000              add [bx+si],al
000084E1  0000              add [bx+si],al
000084E3  0000              add [bx+si],al
000084E5  0000              add [bx+si],al
000084E7  0000              add [bx+si],al
000084E9  0000              add [bx+si],al
000084EB  0000              add [bx+si],al
000084ED  0000              add [bx+si],al
000084EF  0000              add [bx+si],al
000084F1  0000              add [bx+si],al
000084F3  0000              add [bx+si],al
000084F5  0000              add [bx+si],al
000084F7  0000              add [bx+si],al
000084F9  0000              add [bx+si],al
000084FB  0000              add [bx+si],al
000084FD  0000              add [bx+si],al
000084FF  0000              add [bx+si],al
00008501  0000              add [bx+si],al
00008503  0000              add [bx+si],al
00008505  0000              add [bx+si],al
00008507  0000              add [bx+si],al
00008509  0000              add [bx+si],al
0000850B  0000              add [bx+si],al
0000850D  0000              add [bx+si],al
0000850F  0000              add [bx+si],al
00008511  0000              add [bx+si],al
00008513  0000              add [bx+si],al
00008515  0000              add [bx+si],al
00008517  0000              add [bx+si],al
00008519  0000              add [bx+si],al
0000851B  0000              add [bx+si],al
0000851D  0000              add [bx+si],al
0000851F  0000              add [bx+si],al
00008521  0000              add [bx+si],al
00008523  0000              add [bx+si],al
00008525  0000              add [bx+si],al
00008527  0000              add [bx+si],al
00008529  0000              add [bx+si],al
0000852B  0000              add [bx+si],al
0000852D  0000              add [bx+si],al
0000852F  0000              add [bx+si],al
00008531  0000              add [bx+si],al
00008533  0000              add [bx+si],al
00008535  0000              add [bx+si],al
00008537  0000              add [bx+si],al
00008539  0000              add [bx+si],al
0000853B  0000              add [bx+si],al
0000853D  0000              add [bx+si],al
0000853F  0000              add [bx+si],al
00008541  0000              add [bx+si],al
00008543  0000              add [bx+si],al
00008545  0000              add [bx+si],al
00008547  0000              add [bx+si],al
00008549  0000              add [bx+si],al
0000854B  0000              add [bx+si],al
0000854D  0000              add [bx+si],al
0000854F  0000              add [bx+si],al
00008551  0000              add [bx+si],al
00008553  0000              add [bx+si],al
00008555  0000              add [bx+si],al
00008557  0000              add [bx+si],al
00008559  0000              add [bx+si],al
0000855B  0000              add [bx+si],al
0000855D  0000              add [bx+si],al
0000855F  0000              add [bx+si],al
00008561  0000              add [bx+si],al
00008563  0000              add [bx+si],al
00008565  0000              add [bx+si],al
00008567  0000              add [bx+si],al
00008569  0000              add [bx+si],al
0000856B  0000              add [bx+si],al
0000856D  0000              add [bx+si],al
0000856F  0000              add [bx+si],al
00008571  0000              add [bx+si],al
00008573  0000              add [bx+si],al
00008575  0000              add [bx+si],al
00008577  0000              add [bx+si],al
00008579  0000              add [bx+si],al
0000857B  0000              add [bx+si],al
0000857D  0000              add [bx+si],al
0000857F  0000              add [bx+si],al
00008581  0000              add [bx+si],al
00008583  0000              add [bx+si],al
00008585  0000              add [bx+si],al
00008587  0000              add [bx+si],al
00008589  0000              add [bx+si],al
0000858B  0000              add [bx+si],al
0000858D  0000              add [bx+si],al
0000858F  0000              add [bx+si],al
00008591  0000              add [bx+si],al
00008593  0000              add [bx+si],al
00008595  0000              add [bx+si],al
00008597  0000              add [bx+si],al
00008599  0000              add [bx+si],al
0000859B  0000              add [bx+si],al
0000859D  0000              add [bx+si],al
0000859F  0000              add [bx+si],al
000085A1  0000              add [bx+si],al
000085A3  0000              add [bx+si],al
000085A5  0000              add [bx+si],al
000085A7  0000              add [bx+si],al
000085A9  0000              add [bx+si],al
000085AB  0000              add [bx+si],al
000085AD  0000              add [bx+si],al
000085AF  0000              add [bx+si],al
000085B1  0000              add [bx+si],al
000085B3  0000              add [bx+si],al
000085B5  0000              add [bx+si],al
000085B7  0000              add [bx+si],al
000085B9  0000              add [bx+si],al
000085BB  0000              add [bx+si],al
000085BD  0000              add [bx+si],al
000085BF  0000              add [bx+si],al
000085C1  0000              add [bx+si],al
000085C3  0000              add [bx+si],al
000085C5  0000              add [bx+si],al
000085C7  0000              add [bx+si],al
000085C9  0000              add [bx+si],al
000085CB  0000              add [bx+si],al
000085CD  0000              add [bx+si],al
000085CF  0000              add [bx+si],al
000085D1  0000              add [bx+si],al
000085D3  0000              add [bx+si],al
000085D5  0000              add [bx+si],al
000085D7  0000              add [bx+si],al
000085D9  0000              add [bx+si],al
000085DB  0000              add [bx+si],al
000085DD  0000              add [bx+si],al
000085DF  0000              add [bx+si],al
000085E1  0000              add [bx+si],al
000085E3  0000              add [bx+si],al
000085E5  0000              add [bx+si],al
000085E7  0000              add [bx+si],al
000085E9  0000              add [bx+si],al
000085EB  0000              add [bx+si],al
000085ED  0000              add [bx+si],al
000085EF  0000              add [bx+si],al
000085F1  0000              add [bx+si],al
000085F3  0000              add [bx+si],al
000085F5  0000              add [bx+si],al
000085F7  0000              add [bx+si],al
000085F9  0000              add [bx+si],al
000085FB  0000              add [bx+si],al
000085FD  0000              add [bx+si],al
000085FF  0000              add [bx+si],al
00008601  0000              add [bx+si],al
00008603  0000              add [bx+si],al
00008605  0000              add [bx+si],al
00008607  0000              add [bx+si],al
00008609  0000              add [bx+si],al
0000860B  0000              add [bx+si],al
0000860D  0000              add [bx+si],al
0000860F  0000              add [bx+si],al
00008611  0000              add [bx+si],al
00008613  0000              add [bx+si],al
00008615  0000              add [bx+si],al
00008617  0000              add [bx+si],al
00008619  0000              add [bx+si],al
0000861B  0000              add [bx+si],al
0000861D  0000              add [bx+si],al
0000861F  0000              add [bx+si],al
00008621  0000              add [bx+si],al
00008623  0000              add [bx+si],al
00008625  0000              add [bx+si],al
00008627  0000              add [bx+si],al
00008629  0000              add [bx+si],al
0000862B  0000              add [bx+si],al
0000862D  0000              add [bx+si],al
0000862F  0000              add [bx+si],al
00008631  0000              add [bx+si],al
00008633  0000              add [bx+si],al
00008635  0000              add [bx+si],al
00008637  0000              add [bx+si],al
00008639  0000              add [bx+si],al
0000863B  0000              add [bx+si],al
0000863D  0000              add [bx+si],al
0000863F  0000              add [bx+si],al
00008641  0000              add [bx+si],al
00008643  0000              add [bx+si],al
00008645  0000              add [bx+si],al
00008647  0000              add [bx+si],al
00008649  0000              add [bx+si],al
0000864B  0000              add [bx+si],al
0000864D  0000              add [bx+si],al
0000864F  0000              add [bx+si],al
00008651  0000              add [bx+si],al
00008653  0000              add [bx+si],al
00008655  0000              add [bx+si],al
00008657  0000              add [bx+si],al
00008659  0000              add [bx+si],al
0000865B  0000              add [bx+si],al
0000865D  0000              add [bx+si],al
0000865F  0000              add [bx+si],al
00008661  0000              add [bx+si],al
00008663  0000              add [bx+si],al
00008665  0000              add [bx+si],al
00008667  0000              add [bx+si],al
00008669  0000              add [bx+si],al
0000866B  0000              add [bx+si],al
0000866D  0000              add [bx+si],al
0000866F  0000              add [bx+si],al
00008671  0000              add [bx+si],al
00008673  0000              add [bx+si],al
00008675  0000              add [bx+si],al
00008677  0000              add [bx+si],al
00008679  0000              add [bx+si],al
0000867B  0000              add [bx+si],al
0000867D  0000              add [bx+si],al
0000867F  0000              add [bx+si],al
00008681  0000              add [bx+si],al
00008683  0000              add [bx+si],al
00008685  0000              add [bx+si],al
00008687  0000              add [bx+si],al
00008689  0000              add [bx+si],al
0000868B  0000              add [bx+si],al
0000868D  0000              add [bx+si],al
0000868F  0000              add [bx+si],al
00008691  0000              add [bx+si],al
00008693  0000              add [bx+si],al
00008695  0000              add [bx+si],al
00008697  0000              add [bx+si],al
00008699  0000              add [bx+si],al
0000869B  0000              add [bx+si],al
0000869D  0000              add [bx+si],al
0000869F  0000              add [bx+si],al
000086A1  0000              add [bx+si],al
000086A3  0000              add [bx+si],al
000086A5  0000              add [bx+si],al
000086A7  0000              add [bx+si],al
000086A9  0000              add [bx+si],al
000086AB  0000              add [bx+si],al
000086AD  0000              add [bx+si],al
000086AF  0000              add [bx+si],al
000086B1  0000              add [bx+si],al
000086B3  0000              add [bx+si],al
000086B5  0000              add [bx+si],al
000086B7  0000              add [bx+si],al
000086B9  0000              add [bx+si],al
000086BB  0000              add [bx+si],al
000086BD  0000              add [bx+si],al
000086BF  0000              add [bx+si],al
000086C1  0000              add [bx+si],al
000086C3  0000              add [bx+si],al
000086C5  0000              add [bx+si],al
000086C7  0000              add [bx+si],al
000086C9  0000              add [bx+si],al
000086CB  0000              add [bx+si],al
000086CD  0000              add [bx+si],al
000086CF  0000              add [bx+si],al
000086D1  0000              add [bx+si],al
000086D3  0000              add [bx+si],al
000086D5  0000              add [bx+si],al
000086D7  0000              add [bx+si],al
000086D9  0000              add [bx+si],al
000086DB  0000              add [bx+si],al
000086DD  0000              add [bx+si],al
000086DF  0000              add [bx+si],al
000086E1  0000              add [bx+si],al
000086E3  0000              add [bx+si],al
000086E5  0000              add [bx+si],al
000086E7  0000              add [bx+si],al
000086E9  0000              add [bx+si],al
000086EB  0000              add [bx+si],al
000086ED  0000              add [bx+si],al
000086EF  0000              add [bx+si],al
000086F1  0000              add [bx+si],al
000086F3  0000              add [bx+si],al
000086F5  0000              add [bx+si],al
000086F7  0000              add [bx+si],al
000086F9  0000              add [bx+si],al
000086FB  0000              add [bx+si],al
000086FD  0000              add [bx+si],al
000086FF  0000              add [bx+si],al
00008701  0000              add [bx+si],al
00008703  0000              add [bx+si],al
00008705  0000              add [bx+si],al
00008707  0000              add [bx+si],al
00008709  0000              add [bx+si],al
0000870B  0000              add [bx+si],al
0000870D  0000              add [bx+si],al
0000870F  0000              add [bx+si],al
00008711  0000              add [bx+si],al
00008713  0000              add [bx+si],al
00008715  0000              add [bx+si],al
00008717  0000              add [bx+si],al
00008719  0000              add [bx+si],al
0000871B  0000              add [bx+si],al
0000871D  0000              add [bx+si],al
0000871F  0000              add [bx+si],al
00008721  0000              add [bx+si],al
00008723  0000              add [bx+si],al
00008725  0000              add [bx+si],al
00008727  0000              add [bx+si],al
00008729  0000              add [bx+si],al
0000872B  0000              add [bx+si],al
0000872D  0000              add [bx+si],al
0000872F  0000              add [bx+si],al
00008731  0000              add [bx+si],al
00008733  0000              add [bx+si],al
00008735  0000              add [bx+si],al
00008737  0000              add [bx+si],al
00008739  0000              add [bx+si],al
0000873B  0000              add [bx+si],al
0000873D  0000              add [bx+si],al
0000873F  0000              add [bx+si],al
00008741  0000              add [bx+si],al
00008743  0000              add [bx+si],al
00008745  0000              add [bx+si],al
00008747  0000              add [bx+si],al
00008749  0000              add [bx+si],al
0000874B  0000              add [bx+si],al
0000874D  0000              add [bx+si],al
0000874F  0000              add [bx+si],al
00008751  0000              add [bx+si],al
00008753  0000              add [bx+si],al
00008755  0000              add [bx+si],al
00008757  0000              add [bx+si],al
00008759  0000              add [bx+si],al
0000875B  0000              add [bx+si],al
0000875D  0000              add [bx+si],al
0000875F  0000              add [bx+si],al
00008761  0000              add [bx+si],al
00008763  0000              add [bx+si],al
00008765  0000              add [bx+si],al
00008767  0000              add [bx+si],al
00008769  0000              add [bx+si],al
0000876B  0000              add [bx+si],al
0000876D  0000              add [bx+si],al
0000876F  0000              add [bx+si],al
00008771  0000              add [bx+si],al
00008773  0000              add [bx+si],al
00008775  0000              add [bx+si],al
00008777  0000              add [bx+si],al
00008779  0000              add [bx+si],al
0000877B  0000              add [bx+si],al
0000877D  0000              add [bx+si],al
0000877F  0000              add [bx+si],al
00008781  0000              add [bx+si],al
00008783  0000              add [bx+si],al
00008785  0000              add [bx+si],al
00008787  0000              add [bx+si],al
00008789  0000              add [bx+si],al
0000878B  0000              add [bx+si],al
0000878D  0000              add [bx+si],al
0000878F  0000              add [bx+si],al
00008791  0000              add [bx+si],al
00008793  0000              add [bx+si],al
00008795  0000              add [bx+si],al
00008797  0000              add [bx+si],al
00008799  0000              add [bx+si],al
0000879B  0000              add [bx+si],al
0000879D  0000              add [bx+si],al
0000879F  0000              add [bx+si],al
000087A1  0000              add [bx+si],al
000087A3  0000              add [bx+si],al
000087A5  0000              add [bx+si],al
000087A7  0000              add [bx+si],al
000087A9  0000              add [bx+si],al
000087AB  0000              add [bx+si],al
000087AD  0000              add [bx+si],al
000087AF  0000              add [bx+si],al
000087B1  0000              add [bx+si],al
000087B3  0000              add [bx+si],al
000087B5  0000              add [bx+si],al
000087B7  0000              add [bx+si],al
000087B9  0000              add [bx+si],al
000087BB  0000              add [bx+si],al
000087BD  0000              add [bx+si],al
000087BF  0000              add [bx+si],al
000087C1  0000              add [bx+si],al
000087C3  0000              add [bx+si],al
000087C5  0000              add [bx+si],al
000087C7  0000              add [bx+si],al
000087C9  0000              add [bx+si],al
000087CB  0000              add [bx+si],al
000087CD  0000              add [bx+si],al
000087CF  0000              add [bx+si],al
000087D1  0000              add [bx+si],al
000087D3  0000              add [bx+si],al
000087D5  0000              add [bx+si],al
000087D7  0000              add [bx+si],al
000087D9  0000              add [bx+si],al
000087DB  0000              add [bx+si],al
000087DD  0000              add [bx+si],al
000087DF  0000              add [bx+si],al
000087E1  0000              add [bx+si],al
000087E3  0000              add [bx+si],al
000087E5  0000              add [bx+si],al
000087E7  0000              add [bx+si],al
000087E9  0000              add [bx+si],al
000087EB  0000              add [bx+si],al
000087ED  0000              add [bx+si],al
000087EF  0000              add [bx+si],al
000087F1  0000              add [bx+si],al
000087F3  0000              add [bx+si],al
000087F5  0000              add [bx+si],al
000087F7  0000              add [bx+si],al
000087F9  0000              add [bx+si],al
000087FB  0000              add [bx+si],al
000087FD  0000              add [bx+si],al
000087FF  0000              add [bx+si],al
00008801  0000              add [bx+si],al
00008803  0000              add [bx+si],al
00008805  0000              add [bx+si],al
00008807  0000              add [bx+si],al
00008809  0000              add [bx+si],al
0000880B  0000              add [bx+si],al
0000880D  0000              add [bx+si],al
0000880F  0000              add [bx+si],al
00008811  0000              add [bx+si],al
00008813  0000              add [bx+si],al
00008815  0000              add [bx+si],al
00008817  0000              add [bx+si],al
00008819  0000              add [bx+si],al
0000881B  0000              add [bx+si],al
0000881D  0000              add [bx+si],al
0000881F  0000              add [bx+si],al
00008821  0000              add [bx+si],al
00008823  0000              add [bx+si],al
00008825  0000              add [bx+si],al
00008827  0000              add [bx+si],al
00008829  0000              add [bx+si],al
0000882B  0000              add [bx+si],al
0000882D  0000              add [bx+si],al
0000882F  0000              add [bx+si],al
00008831  0000              add [bx+si],al
00008833  0000              add [bx+si],al
00008835  0000              add [bx+si],al
00008837  0000              add [bx+si],al
00008839  0000              add [bx+si],al
0000883B  0000              add [bx+si],al
0000883D  0000              add [bx+si],al
0000883F  0000              add [bx+si],al
00008841  0000              add [bx+si],al
00008843  0000              add [bx+si],al
00008845  0000              add [bx+si],al
00008847  0000              add [bx+si],al
00008849  0000              add [bx+si],al
0000884B  0000              add [bx+si],al
0000884D  0000              add [bx+si],al
0000884F  0000              add [bx+si],al
00008851  0000              add [bx+si],al
00008853  0000              add [bx+si],al
00008855  0000              add [bx+si],al
00008857  0000              add [bx+si],al
00008859  0000              add [bx+si],al
0000885B  0000              add [bx+si],al
0000885D  0000              add [bx+si],al
0000885F  0000              add [bx+si],al
00008861  0000              add [bx+si],al
00008863  0000              add [bx+si],al
00008865  0000              add [bx+si],al
00008867  0000              add [bx+si],al
00008869  0000              add [bx+si],al
0000886B  0000              add [bx+si],al
0000886D  0000              add [bx+si],al
0000886F  0000              add [bx+si],al
00008871  0000              add [bx+si],al
00008873  0000              add [bx+si],al
00008875  0000              add [bx+si],al
00008877  0000              add [bx+si],al
00008879  0000              add [bx+si],al
0000887B  0000              add [bx+si],al
0000887D  0000              add [bx+si],al
0000887F  0000              add [bx+si],al
00008881  0000              add [bx+si],al
00008883  0000              add [bx+si],al
00008885  0000              add [bx+si],al
00008887  0000              add [bx+si],al
00008889  0000              add [bx+si],al
0000888B  0000              add [bx+si],al
0000888D  0000              add [bx+si],al
0000888F  0000              add [bx+si],al
00008891  0000              add [bx+si],al
00008893  0000              add [bx+si],al
00008895  0000              add [bx+si],al
00008897  0000              add [bx+si],al
00008899  0000              add [bx+si],al
0000889B  0000              add [bx+si],al
0000889D  0000              add [bx+si],al
0000889F  0000              add [bx+si],al
000088A1  0000              add [bx+si],al
000088A3  0000              add [bx+si],al
000088A5  0000              add [bx+si],al
000088A7  0000              add [bx+si],al
000088A9  0000              add [bx+si],al
000088AB  0000              add [bx+si],al
000088AD  0000              add [bx+si],al
000088AF  0000              add [bx+si],al
000088B1  0000              add [bx+si],al
000088B3  0000              add [bx+si],al
000088B5  0000              add [bx+si],al
000088B7  0000              add [bx+si],al
000088B9  0000              add [bx+si],al
000088BB  0000              add [bx+si],al
000088BD  0000              add [bx+si],al
000088BF  0000              add [bx+si],al
000088C1  0000              add [bx+si],al
000088C3  0000              add [bx+si],al
000088C5  0000              add [bx+si],al
000088C7  0000              add [bx+si],al
000088C9  0000              add [bx+si],al
000088CB  0000              add [bx+si],al
000088CD  0000              add [bx+si],al
000088CF  0000              add [bx+si],al
000088D1  0000              add [bx+si],al
000088D3  0000              add [bx+si],al
000088D5  0000              add [bx+si],al
000088D7  0000              add [bx+si],al
000088D9  0000              add [bx+si],al
000088DB  0000              add [bx+si],al
000088DD  0000              add [bx+si],al
000088DF  0000              add [bx+si],al
000088E1  0000              add [bx+si],al
000088E3  0000              add [bx+si],al
000088E5  0000              add [bx+si],al
000088E7  0000              add [bx+si],al
000088E9  0000              add [bx+si],al
000088EB  0000              add [bx+si],al
000088ED  0000              add [bx+si],al
000088EF  0000              add [bx+si],al
000088F1  0000              add [bx+si],al
000088F3  0000              add [bx+si],al
000088F5  0000              add [bx+si],al
000088F7  0000              add [bx+si],al
000088F9  0000              add [bx+si],al
000088FB  0000              add [bx+si],al
000088FD  0000              add [bx+si],al
000088FF  0000              add [bx+si],al
00008901  0000              add [bx+si],al
00008903  0000              add [bx+si],al
00008905  0000              add [bx+si],al
00008907  0000              add [bx+si],al
00008909  0000              add [bx+si],al
0000890B  0000              add [bx+si],al
0000890D  0000              add [bx+si],al
0000890F  0000              add [bx+si],al
00008911  0000              add [bx+si],al
00008913  0000              add [bx+si],al
00008915  0000              add [bx+si],al
00008917  0000              add [bx+si],al
00008919  0000              add [bx+si],al
0000891B  0000              add [bx+si],al
0000891D  0000              add [bx+si],al
0000891F  0000              add [bx+si],al
00008921  0000              add [bx+si],al
00008923  0000              add [bx+si],al
00008925  0000              add [bx+si],al
00008927  0000              add [bx+si],al
00008929  0000              add [bx+si],al
0000892B  0000              add [bx+si],al
0000892D  0000              add [bx+si],al
0000892F  0000              add [bx+si],al
00008931  0000              add [bx+si],al
00008933  0000              add [bx+si],al
00008935  0000              add [bx+si],al
00008937  0000              add [bx+si],al
00008939  0000              add [bx+si],al
0000893B  0000              add [bx+si],al
0000893D  0000              add [bx+si],al
0000893F  0000              add [bx+si],al
00008941  0000              add [bx+si],al
00008943  0000              add [bx+si],al
00008945  0000              add [bx+si],al
00008947  0000              add [bx+si],al
00008949  0000              add [bx+si],al
0000894B  0000              add [bx+si],al
0000894D  0000              add [bx+si],al
0000894F  0000              add [bx+si],al
00008951  0000              add [bx+si],al
00008953  0000              add [bx+si],al
00008955  0000              add [bx+si],al
00008957  0000              add [bx+si],al
00008959  0000              add [bx+si],al
0000895B  0000              add [bx+si],al
0000895D  0000              add [bx+si],al
0000895F  0000              add [bx+si],al
00008961  0000              add [bx+si],al
00008963  0000              add [bx+si],al
00008965  0000              add [bx+si],al
00008967  0000              add [bx+si],al
00008969  0000              add [bx+si],al
0000896B  0000              add [bx+si],al
0000896D  0000              add [bx+si],al
0000896F  0000              add [bx+si],al
00008971  0000              add [bx+si],al
00008973  0000              add [bx+si],al
00008975  0000              add [bx+si],al
00008977  0000              add [bx+si],al
00008979  0000              add [bx+si],al
0000897B  0000              add [bx+si],al
0000897D  0000              add [bx+si],al
0000897F  0000              add [bx+si],al
00008981  0000              add [bx+si],al
00008983  0000              add [bx+si],al
00008985  0000              add [bx+si],al
00008987  0000              add [bx+si],al
00008989  0000              add [bx+si],al
0000898B  0000              add [bx+si],al
0000898D  0000              add [bx+si],al
0000898F  0000              add [bx+si],al
00008991  0000              add [bx+si],al
00008993  0000              add [bx+si],al
00008995  0000              add [bx+si],al
00008997  0000              add [bx+si],al
00008999  0000              add [bx+si],al
0000899B  0000              add [bx+si],al
0000899D  0000              add [bx+si],al
0000899F  0000              add [bx+si],al
000089A1  0000              add [bx+si],al
000089A3  0000              add [bx+si],al
000089A5  0000              add [bx+si],al
000089A7  0000              add [bx+si],al
000089A9  0000              add [bx+si],al
000089AB  0000              add [bx+si],al
000089AD  0000              add [bx+si],al
000089AF  0000              add [bx+si],al
000089B1  0000              add [bx+si],al
000089B3  0000              add [bx+si],al
000089B5  0000              add [bx+si],al
000089B7  0000              add [bx+si],al
000089B9  0000              add [bx+si],al
000089BB  0000              add [bx+si],al
000089BD  0000              add [bx+si],al
000089BF  0000              add [bx+si],al
000089C1  0000              add [bx+si],al
000089C3  0000              add [bx+si],al
000089C5  0000              add [bx+si],al
000089C7  0000              add [bx+si],al
000089C9  0000              add [bx+si],al
000089CB  0000              add [bx+si],al
000089CD  0000              add [bx+si],al
000089CF  0000              add [bx+si],al
000089D1  0000              add [bx+si],al
000089D3  0000              add [bx+si],al
000089D5  0000              add [bx+si],al
000089D7  0000              add [bx+si],al
000089D9  0000              add [bx+si],al
000089DB  0000              add [bx+si],al
000089DD  0000              add [bx+si],al
000089DF  0000              add [bx+si],al
000089E1  0000              add [bx+si],al
000089E3  0000              add [bx+si],al
000089E5  0000              add [bx+si],al
000089E7  0000              add [bx+si],al
000089E9  0000              add [bx+si],al
000089EB  0000              add [bx+si],al
000089ED  0000              add [bx+si],al
000089EF  0000              add [bx+si],al
000089F1  0000              add [bx+si],al
000089F3  0000              add [bx+si],al
000089F5  0000              add [bx+si],al
000089F7  0000              add [bx+si],al
000089F9  0000              add [bx+si],al
000089FB  0000              add [bx+si],al
000089FD  0000              add [bx+si],al
000089FF  0000              add [bx+si],al
00008A01  0000              add [bx+si],al
00008A03  0000              add [bx+si],al
00008A05  0000              add [bx+si],al
00008A07  0000              add [bx+si],al
00008A09  0000              add [bx+si],al
00008A0B  0000              add [bx+si],al
00008A0D  0000              add [bx+si],al
00008A0F  0000              add [bx+si],al
00008A11  0000              add [bx+si],al
00008A13  0000              add [bx+si],al
00008A15  0000              add [bx+si],al
00008A17  0000              add [bx+si],al
00008A19  0000              add [bx+si],al
00008A1B  0000              add [bx+si],al
00008A1D  0000              add [bx+si],al
00008A1F  0000              add [bx+si],al
00008A21  0000              add [bx+si],al
00008A23  0000              add [bx+si],al
00008A25  0000              add [bx+si],al
00008A27  0000              add [bx+si],al
00008A29  0000              add [bx+si],al
00008A2B  0000              add [bx+si],al
00008A2D  0000              add [bx+si],al
00008A2F  0000              add [bx+si],al
00008A31  0000              add [bx+si],al
00008A33  0000              add [bx+si],al
00008A35  0000              add [bx+si],al
00008A37  0000              add [bx+si],al
00008A39  0000              add [bx+si],al
00008A3B  0000              add [bx+si],al
00008A3D  0000              add [bx+si],al
00008A3F  0000              add [bx+si],al
00008A41  0000              add [bx+si],al
00008A43  0000              add [bx+si],al
00008A45  0000              add [bx+si],al
00008A47  0000              add [bx+si],al
00008A49  0000              add [bx+si],al
00008A4B  0000              add [bx+si],al
00008A4D  0000              add [bx+si],al
00008A4F  0000              add [bx+si],al
00008A51  0000              add [bx+si],al
00008A53  0000              add [bx+si],al
00008A55  0000              add [bx+si],al
00008A57  0000              add [bx+si],al
00008A59  0000              add [bx+si],al
00008A5B  0000              add [bx+si],al
00008A5D  0000              add [bx+si],al
00008A5F  0000              add [bx+si],al
00008A61  0000              add [bx+si],al
00008A63  0000              add [bx+si],al
00008A65  0000              add [bx+si],al
00008A67  0000              add [bx+si],al
00008A69  0000              add [bx+si],al
00008A6B  0000              add [bx+si],al
00008A6D  0000              add [bx+si],al
00008A6F  0000              add [bx+si],al
00008A71  0000              add [bx+si],al
00008A73  0000              add [bx+si],al
00008A75  0000              add [bx+si],al
00008A77  0000              add [bx+si],al
00008A79  0000              add [bx+si],al
00008A7B  0000              add [bx+si],al
00008A7D  0000              add [bx+si],al
00008A7F  0000              add [bx+si],al
00008A81  0000              add [bx+si],al
00008A83  0000              add [bx+si],al
00008A85  0000              add [bx+si],al
00008A87  0000              add [bx+si],al
00008A89  0000              add [bx+si],al
00008A8B  0000              add [bx+si],al
00008A8D  0000              add [bx+si],al
00008A8F  0000              add [bx+si],al
00008A91  0000              add [bx+si],al
00008A93  0000              add [bx+si],al
00008A95  0000              add [bx+si],al
00008A97  0000              add [bx+si],al
00008A99  0000              add [bx+si],al
00008A9B  0000              add [bx+si],al
00008A9D  0000              add [bx+si],al
00008A9F  0000              add [bx+si],al
00008AA1  0000              add [bx+si],al
00008AA3  0000              add [bx+si],al
00008AA5  0000              add [bx+si],al
00008AA7  0000              add [bx+si],al
00008AA9  0000              add [bx+si],al
00008AAB  0000              add [bx+si],al
00008AAD  0000              add [bx+si],al
00008AAF  0000              add [bx+si],al
00008AB1  0000              add [bx+si],al
00008AB3  0000              add [bx+si],al
00008AB5  0000              add [bx+si],al
00008AB7  0000              add [bx+si],al
00008AB9  0000              add [bx+si],al
00008ABB  0000              add [bx+si],al
00008ABD  0000              add [bx+si],al
00008ABF  0000              add [bx+si],al
00008AC1  0000              add [bx+si],al
00008AC3  0000              add [bx+si],al
00008AC5  0000              add [bx+si],al
00008AC7  0000              add [bx+si],al
00008AC9  0000              add [bx+si],al
00008ACB  0000              add [bx+si],al
00008ACD  0000              add [bx+si],al
00008ACF  0000              add [bx+si],al
00008AD1  0000              add [bx+si],al
00008AD3  0000              add [bx+si],al
00008AD5  0000              add [bx+si],al
00008AD7  0000              add [bx+si],al
00008AD9  0000              add [bx+si],al
00008ADB  0000              add [bx+si],al
00008ADD  0000              add [bx+si],al
00008ADF  0000              add [bx+si],al
00008AE1  0000              add [bx+si],al
00008AE3  0000              add [bx+si],al
00008AE5  0000              add [bx+si],al
00008AE7  0000              add [bx+si],al
00008AE9  0000              add [bx+si],al
00008AEB  0000              add [bx+si],al
00008AED  0000              add [bx+si],al
00008AEF  0000              add [bx+si],al
00008AF1  0000              add [bx+si],al
00008AF3  0000              add [bx+si],al
00008AF5  0000              add [bx+si],al
00008AF7  0000              add [bx+si],al
00008AF9  0000              add [bx+si],al
00008AFB  0000              add [bx+si],al
00008AFD  0000              add [bx+si],al
00008AFF  0000              add [bx+si],al
00008B01  0000              add [bx+si],al
00008B03  0000              add [bx+si],al
00008B05  0000              add [bx+si],al
00008B07  0000              add [bx+si],al
00008B09  0000              add [bx+si],al
00008B0B  0000              add [bx+si],al
00008B0D  0000              add [bx+si],al
00008B0F  0000              add [bx+si],al
00008B11  0000              add [bx+si],al
00008B13  0000              add [bx+si],al
00008B15  0000              add [bx+si],al
00008B17  0000              add [bx+si],al
00008B19  0000              add [bx+si],al
00008B1B  0000              add [bx+si],al
00008B1D  0000              add [bx+si],al
00008B1F  0000              add [bx+si],al
00008B21  0000              add [bx+si],al
00008B23  0000              add [bx+si],al
00008B25  0000              add [bx+si],al
00008B27  0000              add [bx+si],al
00008B29  0000              add [bx+si],al
00008B2B  0000              add [bx+si],al
00008B2D  0000              add [bx+si],al
00008B2F  0000              add [bx+si],al
00008B31  0000              add [bx+si],al
00008B33  0000              add [bx+si],al
00008B35  0000              add [bx+si],al
00008B37  0000              add [bx+si],al
00008B39  0000              add [bx+si],al
00008B3B  0000              add [bx+si],al
00008B3D  0000              add [bx+si],al
00008B3F  0000              add [bx+si],al
00008B41  0000              add [bx+si],al
00008B43  0000              add [bx+si],al
00008B45  0000              add [bx+si],al
00008B47  0000              add [bx+si],al
00008B49  0000              add [bx+si],al
00008B4B  0000              add [bx+si],al
00008B4D  0000              add [bx+si],al
00008B4F  0000              add [bx+si],al
00008B51  0000              add [bx+si],al
00008B53  0000              add [bx+si],al
00008B55  0000              add [bx+si],al
00008B57  0000              add [bx+si],al
00008B59  0000              add [bx+si],al
00008B5B  0000              add [bx+si],al
00008B5D  0000              add [bx+si],al
00008B5F  0000              add [bx+si],al
00008B61  0000              add [bx+si],al
00008B63  0000              add [bx+si],al
00008B65  0000              add [bx+si],al
00008B67  0000              add [bx+si],al
00008B69  0000              add [bx+si],al
00008B6B  0000              add [bx+si],al
00008B6D  0000              add [bx+si],al
00008B6F  0000              add [bx+si],al
00008B71  0000              add [bx+si],al
00008B73  0000              add [bx+si],al
00008B75  0000              add [bx+si],al
00008B77  0000              add [bx+si],al
00008B79  0000              add [bx+si],al
00008B7B  0000              add [bx+si],al
00008B7D  0000              add [bx+si],al
00008B7F  0000              add [bx+si],al
00008B81  0000              add [bx+si],al
00008B83  0000              add [bx+si],al
00008B85  0000              add [bx+si],al
00008B87  0000              add [bx+si],al
00008B89  0000              add [bx+si],al
00008B8B  0000              add [bx+si],al
00008B8D  0000              add [bx+si],al
00008B8F  0000              add [bx+si],al
00008B91  0000              add [bx+si],al
00008B93  0000              add [bx+si],al
00008B95  0000              add [bx+si],al
00008B97  0000              add [bx+si],al
00008B99  0000              add [bx+si],al
00008B9B  0000              add [bx+si],al
00008B9D  0000              add [bx+si],al
00008B9F  0000              add [bx+si],al
00008BA1  0000              add [bx+si],al
00008BA3  0000              add [bx+si],al
00008BA5  0000              add [bx+si],al
00008BA7  0000              add [bx+si],al
00008BA9  0000              add [bx+si],al
00008BAB  0000              add [bx+si],al
00008BAD  0000              add [bx+si],al
00008BAF  0000              add [bx+si],al
00008BB1  0000              add [bx+si],al
00008BB3  0000              add [bx+si],al
00008BB5  0000              add [bx+si],al
00008BB7  0000              add [bx+si],al
00008BB9  0000              add [bx+si],al
00008BBB  0000              add [bx+si],al
00008BBD  0000              add [bx+si],al
00008BBF  0000              add [bx+si],al
00008BC1  0000              add [bx+si],al
00008BC3  0000              add [bx+si],al
00008BC5  0000              add [bx+si],al
00008BC7  0000              add [bx+si],al
00008BC9  0000              add [bx+si],al
00008BCB  0000              add [bx+si],al
00008BCD  0000              add [bx+si],al
00008BCF  0000              add [bx+si],al
00008BD1  0000              add [bx+si],al
00008BD3  0000              add [bx+si],al
00008BD5  0000              add [bx+si],al
00008BD7  0000              add [bx+si],al
00008BD9  0000              add [bx+si],al
00008BDB  0000              add [bx+si],al
00008BDD  0000              add [bx+si],al
00008BDF  0000              add [bx+si],al
00008BE1  0000              add [bx+si],al
00008BE3  0000              add [bx+si],al
00008BE5  0000              add [bx+si],al
00008BE7  0000              add [bx+si],al
00008BE9  0000              add [bx+si],al
00008BEB  0000              add [bx+si],al
00008BED  0000              add [bx+si],al
00008BEF  0000              add [bx+si],al
00008BF1  0000              add [bx+si],al
00008BF3  0000              add [bx+si],al
00008BF5  0000              add [bx+si],al
00008BF7  0000              add [bx+si],al
00008BF9  0000              add [bx+si],al
00008BFB  0000              add [bx+si],al
00008BFD  0000              add [bx+si],al
00008BFF  0000              add [bx+si],al
00008C01  0000              add [bx+si],al
00008C03  0000              add [bx+si],al
00008C05  0000              add [bx+si],al
00008C07  0000              add [bx+si],al
00008C09  0000              add [bx+si],al
00008C0B  0000              add [bx+si],al
00008C0D  0000              add [bx+si],al
00008C0F  0000              add [bx+si],al
00008C11  0000              add [bx+si],al
00008C13  0000              add [bx+si],al
00008C15  0000              add [bx+si],al
00008C17  0000              add [bx+si],al
00008C19  0000              add [bx+si],al
00008C1B  0000              add [bx+si],al
00008C1D  0000              add [bx+si],al
00008C1F  0000              add [bx+si],al
00008C21  0000              add [bx+si],al
00008C23  0000              add [bx+si],al
00008C25  0000              add [bx+si],al
00008C27  0000              add [bx+si],al
00008C29  0000              add [bx+si],al
00008C2B  0000              add [bx+si],al
00008C2D  0000              add [bx+si],al
00008C2F  0000              add [bx+si],al
00008C31  0000              add [bx+si],al
00008C33  0000              add [bx+si],al
00008C35  0000              add [bx+si],al
00008C37  0000              add [bx+si],al
00008C39  0000              add [bx+si],al
00008C3B  0000              add [bx+si],al
00008C3D  0000              add [bx+si],al
00008C3F  0000              add [bx+si],al
00008C41  0000              add [bx+si],al
00008C43  0000              add [bx+si],al
00008C45  0000              add [bx+si],al
00008C47  0000              add [bx+si],al
00008C49  0000              add [bx+si],al
00008C4B  0000              add [bx+si],al
00008C4D  0000              add [bx+si],al
00008C4F  0000              add [bx+si],al
00008C51  0000              add [bx+si],al
00008C53  0000              add [bx+si],al
00008C55  0000              add [bx+si],al
00008C57  0000              add [bx+si],al
00008C59  0000              add [bx+si],al
00008C5B  0000              add [bx+si],al
00008C5D  0000              add [bx+si],al
00008C5F  0000              add [bx+si],al
00008C61  0000              add [bx+si],al
00008C63  0000              add [bx+si],al
00008C65  0000              add [bx+si],al
00008C67  0000              add [bx+si],al
00008C69  0000              add [bx+si],al
00008C6B  0000              add [bx+si],al
00008C6D  0000              add [bx+si],al
00008C6F  0000              add [bx+si],al
00008C71  0000              add [bx+si],al
00008C73  0000              add [bx+si],al
00008C75  0000              add [bx+si],al
00008C77  0000              add [bx+si],al
00008C79  0000              add [bx+si],al
00008C7B  0000              add [bx+si],al
00008C7D  0000              add [bx+si],al
00008C7F  0000              add [bx+si],al
00008C81  0000              add [bx+si],al
00008C83  0000              add [bx+si],al
00008C85  0000              add [bx+si],al
00008C87  0000              add [bx+si],al
00008C89  0000              add [bx+si],al
00008C8B  0000              add [bx+si],al
00008C8D  0000              add [bx+si],al
00008C8F  0000              add [bx+si],al
00008C91  0000              add [bx+si],al
00008C93  0000              add [bx+si],al
00008C95  0000              add [bx+si],al
00008C97  0000              add [bx+si],al
00008C99  0000              add [bx+si],al
00008C9B  0000              add [bx+si],al
00008C9D  0000              add [bx+si],al
00008C9F  0000              add [bx+si],al
00008CA1  0000              add [bx+si],al
00008CA3  0000              add [bx+si],al
00008CA5  0000              add [bx+si],al
00008CA7  0000              add [bx+si],al
00008CA9  0000              add [bx+si],al
00008CAB  0000              add [bx+si],al
00008CAD  0000              add [bx+si],al
00008CAF  0000              add [bx+si],al
00008CB1  0000              add [bx+si],al
00008CB3  0000              add [bx+si],al
00008CB5  0000              add [bx+si],al
00008CB7  0000              add [bx+si],al
00008CB9  0000              add [bx+si],al
00008CBB  0000              add [bx+si],al
00008CBD  0000              add [bx+si],al
00008CBF  0000              add [bx+si],al
00008CC1  0000              add [bx+si],al
00008CC3  0000              add [bx+si],al
00008CC5  0000              add [bx+si],al
00008CC7  0000              add [bx+si],al
00008CC9  0000              add [bx+si],al
00008CCB  0000              add [bx+si],al
00008CCD  0000              add [bx+si],al
00008CCF  0000              add [bx+si],al
00008CD1  0000              add [bx+si],al
00008CD3  0000              add [bx+si],al
00008CD5  0000              add [bx+si],al
00008CD7  0000              add [bx+si],al
00008CD9  0000              add [bx+si],al
00008CDB  0000              add [bx+si],al
00008CDD  0000              add [bx+si],al
00008CDF  0000              add [bx+si],al
00008CE1  0000              add [bx+si],al
00008CE3  0000              add [bx+si],al
00008CE5  0000              add [bx+si],al
00008CE7  0000              add [bx+si],al
00008CE9  0000              add [bx+si],al
00008CEB  0000              add [bx+si],al
00008CED  0000              add [bx+si],al
00008CEF  0000              add [bx+si],al
00008CF1  0000              add [bx+si],al
00008CF3  0000              add [bx+si],al
00008CF5  0000              add [bx+si],al
00008CF7  0000              add [bx+si],al
00008CF9  0000              add [bx+si],al
00008CFB  0000              add [bx+si],al
00008CFD  0000              add [bx+si],al
00008CFF  0000              add [bx+si],al
00008D01  0000              add [bx+si],al
00008D03  0000              add [bx+si],al
00008D05  0000              add [bx+si],al
00008D07  0000              add [bx+si],al
00008D09  0000              add [bx+si],al
00008D0B  0000              add [bx+si],al
00008D0D  0000              add [bx+si],al
00008D0F  0000              add [bx+si],al
00008D11  0000              add [bx+si],al
00008D13  0000              add [bx+si],al
00008D15  0000              add [bx+si],al
00008D17  0000              add [bx+si],al
00008D19  0000              add [bx+si],al
00008D1B  0000              add [bx+si],al
00008D1D  0000              add [bx+si],al
00008D1F  0000              add [bx+si],al
00008D21  0000              add [bx+si],al
00008D23  0000              add [bx+si],al
00008D25  0000              add [bx+si],al
00008D27  0000              add [bx+si],al
00008D29  0000              add [bx+si],al
00008D2B  0000              add [bx+si],al
00008D2D  0000              add [bx+si],al
00008D2F  0000              add [bx+si],al
00008D31  0000              add [bx+si],al
00008D33  0000              add [bx+si],al
00008D35  0000              add [bx+si],al
00008D37  0000              add [bx+si],al
00008D39  0000              add [bx+si],al
00008D3B  0000              add [bx+si],al
00008D3D  0000              add [bx+si],al
00008D3F  0000              add [bx+si],al
00008D41  0000              add [bx+si],al
00008D43  0000              add [bx+si],al
00008D45  0000              add [bx+si],al
00008D47  0000              add [bx+si],al
00008D49  0000              add [bx+si],al
00008D4B  0000              add [bx+si],al
00008D4D  0000              add [bx+si],al
00008D4F  0000              add [bx+si],al
00008D51  0000              add [bx+si],al
00008D53  0000              add [bx+si],al
00008D55  0000              add [bx+si],al
00008D57  0000              add [bx+si],al
00008D59  0000              add [bx+si],al
00008D5B  0000              add [bx+si],al
00008D5D  0000              add [bx+si],al
00008D5F  0000              add [bx+si],al
00008D61  0000              add [bx+si],al
00008D63  0000              add [bx+si],al
00008D65  0000              add [bx+si],al
00008D67  0000              add [bx+si],al
00008D69  0000              add [bx+si],al
00008D6B  0000              add [bx+si],al
00008D6D  0000              add [bx+si],al
00008D6F  0000              add [bx+si],al
00008D71  0000              add [bx+si],al
00008D73  0000              add [bx+si],al
00008D75  0000              add [bx+si],al
00008D77  0000              add [bx+si],al
00008D79  0000              add [bx+si],al
00008D7B  0000              add [bx+si],al
00008D7D  0000              add [bx+si],al
00008D7F  0000              add [bx+si],al
00008D81  0000              add [bx+si],al
00008D83  0000              add [bx+si],al
00008D85  0000              add [bx+si],al
00008D87  0000              add [bx+si],al
00008D89  0000              add [bx+si],al
00008D8B  0000              add [bx+si],al
00008D8D  0000              add [bx+si],al
00008D8F  0000              add [bx+si],al
00008D91  0000              add [bx+si],al
00008D93  0000              add [bx+si],al
00008D95  0000              add [bx+si],al
00008D97  0000              add [bx+si],al
00008D99  0000              add [bx+si],al
00008D9B  0000              add [bx+si],al
00008D9D  0000              add [bx+si],al
00008D9F  0000              add [bx+si],al
00008DA1  0000              add [bx+si],al
00008DA3  0000              add [bx+si],al
00008DA5  0000              add [bx+si],al
00008DA7  0000              add [bx+si],al
00008DA9  0000              add [bx+si],al
00008DAB  0000              add [bx+si],al
00008DAD  0000              add [bx+si],al
00008DAF  0000              add [bx+si],al
00008DB1  0000              add [bx+si],al
00008DB3  0000              add [bx+si],al
00008DB5  0000              add [bx+si],al
00008DB7  0000              add [bx+si],al
00008DB9  0000              add [bx+si],al
00008DBB  0000              add [bx+si],al
00008DBD  0000              add [bx+si],al
00008DBF  0000              add [bx+si],al
00008DC1  0000              add [bx+si],al
00008DC3  0000              add [bx+si],al
00008DC5  0000              add [bx+si],al
00008DC7  0000              add [bx+si],al
00008DC9  0000              add [bx+si],al
00008DCB  0000              add [bx+si],al
00008DCD  0000              add [bx+si],al
00008DCF  0000              add [bx+si],al
00008DD1  0000              add [bx+si],al
00008DD3  0000              add [bx+si],al
00008DD5  0000              add [bx+si],al
00008DD7  0000              add [bx+si],al
00008DD9  0000              add [bx+si],al
00008DDB  0000              add [bx+si],al
00008DDD  0000              add [bx+si],al
00008DDF  0000              add [bx+si],al
00008DE1  0000              add [bx+si],al
00008DE3  0000              add [bx+si],al
00008DE5  0000              add [bx+si],al
00008DE7  0000              add [bx+si],al
00008DE9  0000              add [bx+si],al
00008DEB  0000              add [bx+si],al
00008DED  0000              add [bx+si],al
00008DEF  0000              add [bx+si],al
00008DF1  0000              add [bx+si],al
00008DF3  0000              add [bx+si],al
00008DF5  0000              add [bx+si],al
00008DF7  0000              add [bx+si],al
00008DF9  0000              add [bx+si],al
00008DFB  0000              add [bx+si],al
00008DFD  0000              add [bx+si],al
00008DFF  0000              add [bx+si],al
00008E01  0000              add [bx+si],al
00008E03  0000              add [bx+si],al
00008E05  0000              add [bx+si],al
00008E07  0000              add [bx+si],al
00008E09  0000              add [bx+si],al
00008E0B  0000              add [bx+si],al
00008E0D  0000              add [bx+si],al
00008E0F  0000              add [bx+si],al
00008E11  0000              add [bx+si],al
00008E13  0000              add [bx+si],al
00008E15  0000              add [bx+si],al
00008E17  0000              add [bx+si],al
00008E19  0000              add [bx+si],al
00008E1B  0000              add [bx+si],al
00008E1D  0000              add [bx+si],al
00008E1F  0000              add [bx+si],al
00008E21  0000              add [bx+si],al
00008E23  0000              add [bx+si],al
00008E25  0000              add [bx+si],al
00008E27  0000              add [bx+si],al
00008E29  0000              add [bx+si],al
00008E2B  0000              add [bx+si],al
00008E2D  0000              add [bx+si],al
00008E2F  0000              add [bx+si],al
00008E31  0000              add [bx+si],al
00008E33  0000              add [bx+si],al
00008E35  0000              add [bx+si],al
00008E37  0000              add [bx+si],al
00008E39  0000              add [bx+si],al
00008E3B  0000              add [bx+si],al
00008E3D  0000              add [bx+si],al
00008E3F  0000              add [bx+si],al
00008E41  0000              add [bx+si],al
00008E43  0000              add [bx+si],al
00008E45  0000              add [bx+si],al
00008E47  0000              add [bx+si],al
00008E49  0000              add [bx+si],al
00008E4B  0000              add [bx+si],al
00008E4D  0000              add [bx+si],al
00008E4F  0000              add [bx+si],al
00008E51  0000              add [bx+si],al
00008E53  0000              add [bx+si],al
00008E55  0000              add [bx+si],al
00008E57  0000              add [bx+si],al
00008E59  0000              add [bx+si],al
00008E5B  0000              add [bx+si],al
00008E5D  0000              add [bx+si],al
00008E5F  0000              add [bx+si],al
00008E61  0000              add [bx+si],al
00008E63  0000              add [bx+si],al
00008E65  0000              add [bx+si],al
00008E67  0000              add [bx+si],al
00008E69  0000              add [bx+si],al
00008E6B  0000              add [bx+si],al
00008E6D  0000              add [bx+si],al
00008E6F  0000              add [bx+si],al
00008E71  0000              add [bx+si],al
00008E73  0000              add [bx+si],al
00008E75  0000              add [bx+si],al
00008E77  0000              add [bx+si],al
00008E79  0000              add [bx+si],al
00008E7B  0000              add [bx+si],al
00008E7D  0000              add [bx+si],al
00008E7F  0000              add [bx+si],al
00008E81  0000              add [bx+si],al
00008E83  0000              add [bx+si],al
00008E85  0000              add [bx+si],al
00008E87  0000              add [bx+si],al
00008E89  0000              add [bx+si],al
00008E8B  0000              add [bx+si],al
00008E8D  0000              add [bx+si],al
00008E8F  0000              add [bx+si],al
00008E91  0000              add [bx+si],al
00008E93  0000              add [bx+si],al
00008E95  0000              add [bx+si],al
00008E97  0000              add [bx+si],al
00008E99  0000              add [bx+si],al
00008E9B  0000              add [bx+si],al
00008E9D  0000              add [bx+si],al
00008E9F  0000              add [bx+si],al
00008EA1  0000              add [bx+si],al
00008EA3  0000              add [bx+si],al
00008EA5  0000              add [bx+si],al
00008EA7  0000              add [bx+si],al
00008EA9  0000              add [bx+si],al
00008EAB  0000              add [bx+si],al
00008EAD  0000              add [bx+si],al
00008EAF  0000              add [bx+si],al
00008EB1  0000              add [bx+si],al
00008EB3  0000              add [bx+si],al
00008EB5  0000              add [bx+si],al
00008EB7  0000              add [bx+si],al
00008EB9  0000              add [bx+si],al
00008EBB  0000              add [bx+si],al
00008EBD  0000              add [bx+si],al
00008EBF  0000              add [bx+si],al
00008EC1  0000              add [bx+si],al
00008EC3  0000              add [bx+si],al
00008EC5  0000              add [bx+si],al
00008EC7  0000              add [bx+si],al
00008EC9  0000              add [bx+si],al
00008ECB  0000              add [bx+si],al
00008ECD  0000              add [bx+si],al
00008ECF  0000              add [bx+si],al
00008ED1  0000              add [bx+si],al
00008ED3  0000              add [bx+si],al
00008ED5  0000              add [bx+si],al
00008ED7  0000              add [bx+si],al
00008ED9  0000              add [bx+si],al
00008EDB  0000              add [bx+si],al
00008EDD  0000              add [bx+si],al
00008EDF  0000              add [bx+si],al
00008EE1  0000              add [bx+si],al
00008EE3  0000              add [bx+si],al
00008EE5  0000              add [bx+si],al
00008EE7  0000              add [bx+si],al
00008EE9  0000              add [bx+si],al
00008EEB  0000              add [bx+si],al
00008EED  0000              add [bx+si],al
00008EEF  0000              add [bx+si],al
00008EF1  0000              add [bx+si],al
00008EF3  0000              add [bx+si],al
00008EF5  0000              add [bx+si],al
00008EF7  0000              add [bx+si],al
00008EF9  0000              add [bx+si],al
00008EFB  0000              add [bx+si],al
00008EFD  0000              add [bx+si],al
00008EFF  0000              add [bx+si],al
00008F01  0000              add [bx+si],al
00008F03  0000              add [bx+si],al
00008F05  0000              add [bx+si],al
00008F07  0000              add [bx+si],al
00008F09  0000              add [bx+si],al
00008F0B  0000              add [bx+si],al
00008F0D  0000              add [bx+si],al
00008F0F  0000              add [bx+si],al
00008F11  0000              add [bx+si],al
00008F13  0000              add [bx+si],al
00008F15  0000              add [bx+si],al
00008F17  0000              add [bx+si],al
00008F19  0000              add [bx+si],al
00008F1B  0000              add [bx+si],al
00008F1D  0000              add [bx+si],al
00008F1F  0000              add [bx+si],al
00008F21  0000              add [bx+si],al
00008F23  0000              add [bx+si],al
00008F25  0000              add [bx+si],al
00008F27  0000              add [bx+si],al
00008F29  0000              add [bx+si],al
00008F2B  0000              add [bx+si],al
00008F2D  0000              add [bx+si],al
00008F2F  0000              add [bx+si],al
00008F31  0000              add [bx+si],al
00008F33  0000              add [bx+si],al
00008F35  0000              add [bx+si],al
00008F37  0000              add [bx+si],al
00008F39  0000              add [bx+si],al
00008F3B  0000              add [bx+si],al
00008F3D  0000              add [bx+si],al
00008F3F  0000              add [bx+si],al
00008F41  0000              add [bx+si],al
00008F43  0000              add [bx+si],al
00008F45  0000              add [bx+si],al
00008F47  0000              add [bx+si],al
00008F49  0000              add [bx+si],al
00008F4B  0000              add [bx+si],al
00008F4D  0000              add [bx+si],al
00008F4F  0000              add [bx+si],al
00008F51  0000              add [bx+si],al
00008F53  0000              add [bx+si],al
00008F55  0000              add [bx+si],al
00008F57  0000              add [bx+si],al
00008F59  0000              add [bx+si],al
00008F5B  0000              add [bx+si],al
00008F5D  0000              add [bx+si],al
00008F5F  0000              add [bx+si],al
00008F61  0000              add [bx+si],al
00008F63  0000              add [bx+si],al
00008F65  0000              add [bx+si],al
00008F67  0000              add [bx+si],al
00008F69  0000              add [bx+si],al
00008F6B  0000              add [bx+si],al
00008F6D  0000              add [bx+si],al
00008F6F  0000              add [bx+si],al
00008F71  0000              add [bx+si],al
00008F73  0000              add [bx+si],al
00008F75  0000              add [bx+si],al
00008F77  0000              add [bx+si],al
00008F79  0000              add [bx+si],al
00008F7B  0000              add [bx+si],al
00008F7D  0000              add [bx+si],al
00008F7F  0000              add [bx+si],al
00008F81  0000              add [bx+si],al
00008F83  0000              add [bx+si],al
00008F85  0000              add [bx+si],al
00008F87  0000              add [bx+si],al
00008F89  0000              add [bx+si],al
00008F8B  0000              add [bx+si],al
00008F8D  0000              add [bx+si],al
00008F8F  0000              add [bx+si],al
00008F91  0000              add [bx+si],al
00008F93  0000              add [bx+si],al
00008F95  0000              add [bx+si],al
00008F97  0000              add [bx+si],al
00008F99  0000              add [bx+si],al
00008F9B  0000              add [bx+si],al
00008F9D  0000              add [bx+si],al
00008F9F  0000              add [bx+si],al
00008FA1  0000              add [bx+si],al
00008FA3  0000              add [bx+si],al
00008FA5  0000              add [bx+si],al
00008FA7  0000              add [bx+si],al
00008FA9  0000              add [bx+si],al
00008FAB  0000              add [bx+si],al
00008FAD  0000              add [bx+si],al
00008FAF  0000              add [bx+si],al
00008FB1  0000              add [bx+si],al
00008FB3  0000              add [bx+si],al
00008FB5  0000              add [bx+si],al
00008FB7  0000              add [bx+si],al
00008FB9  0000              add [bx+si],al
00008FBB  0000              add [bx+si],al
00008FBD  0000              add [bx+si],al
00008FBF  0000              add [bx+si],al
00008FC1  0000              add [bx+si],al
00008FC3  0000              add [bx+si],al
00008FC5  0000              add [bx+si],al
00008FC7  0000              add [bx+si],al
00008FC9  0000              add [bx+si],al
00008FCB  0000              add [bx+si],al
00008FCD  0000              add [bx+si],al
00008FCF  0000              add [bx+si],al
00008FD1  0000              add [bx+si],al
00008FD3  0000              add [bx+si],al
00008FD5  0000              add [bx+si],al
00008FD7  0000              add [bx+si],al
00008FD9  0000              add [bx+si],al
00008FDB  0000              add [bx+si],al
00008FDD  0000              add [bx+si],al
00008FDF  0000              add [bx+si],al
00008FE1  0000              add [bx+si],al
00008FE3  0000              add [bx+si],al
00008FE5  0000              add [bx+si],al
00008FE7  0000              add [bx+si],al
00008FE9  0000              add [bx+si],al
00008FEB  0000              add [bx+si],al
00008FED  0000              add [bx+si],al
00008FEF  0000              add [bx+si],al
00008FF1  0000              add [bx+si],al
00008FF3  0000              add [bx+si],al
00008FF5  0000              add [bx+si],al
00008FF7  0000              add [bx+si],al
00008FF9  0000              add [bx+si],al
00008FFB  0000              add [bx+si],al
00008FFD  0000              add [bx+si],al
00008FFF  0000              add [bx+si],al
00009001  0000              add [bx+si],al
00009003  0000              add [bx+si],al
00009005  0000              add [bx+si],al
00009007  0000              add [bx+si],al
00009009  0000              add [bx+si],al
0000900B  0000              add [bx+si],al
0000900D  0000              add [bx+si],al
0000900F  0000              add [bx+si],al
00009011  0000              add [bx+si],al
00009013  0000              add [bx+si],al
00009015  0000              add [bx+si],al
00009017  0000              add [bx+si],al
00009019  0000              add [bx+si],al
0000901B  0000              add [bx+si],al
0000901D  0000              add [bx+si],al
0000901F  0000              add [bx+si],al
00009021  0000              add [bx+si],al
00009023  0000              add [bx+si],al
00009025  0000              add [bx+si],al
00009027  0000              add [bx+si],al
00009029  0000              add [bx+si],al
0000902B  0000              add [bx+si],al
0000902D  0000              add [bx+si],al
0000902F  0000              add [bx+si],al
00009031  0000              add [bx+si],al
00009033  0000              add [bx+si],al
00009035  0000              add [bx+si],al
00009037  0000              add [bx+si],al
00009039  0000              add [bx+si],al
0000903B  0000              add [bx+si],al
0000903D  0000              add [bx+si],al
0000903F  0000              add [bx+si],al
00009041  0000              add [bx+si],al
00009043  0000              add [bx+si],al
00009045  0000              add [bx+si],al
00009047  0000              add [bx+si],al
00009049  0000              add [bx+si],al
0000904B  0000              add [bx+si],al
0000904D  0000              add [bx+si],al
0000904F  0000              add [bx+si],al
00009051  0000              add [bx+si],al
00009053  0000              add [bx+si],al
00009055  0000              add [bx+si],al
00009057  0000              add [bx+si],al
00009059  0000              add [bx+si],al
0000905B  0000              add [bx+si],al
0000905D  0000              add [bx+si],al
0000905F  0000              add [bx+si],al
00009061  0000              add [bx+si],al
00009063  0000              add [bx+si],al
00009065  0000              add [bx+si],al
00009067  0000              add [bx+si],al
00009069  0000              add [bx+si],al
0000906B  0000              add [bx+si],al
0000906D  0000              add [bx+si],al
0000906F  0000              add [bx+si],al
00009071  0000              add [bx+si],al
00009073  0000              add [bx+si],al
00009075  0000              add [bx+si],al
00009077  0000              add [bx+si],al
00009079  0000              add [bx+si],al
0000907B  0000              add [bx+si],al
0000907D  0000              add [bx+si],al
0000907F  0000              add [bx+si],al
00009081  0000              add [bx+si],al
00009083  0000              add [bx+si],al
00009085  0000              add [bx+si],al
00009087  0000              add [bx+si],al
00009089  0000              add [bx+si],al
0000908B  0000              add [bx+si],al
0000908D  0000              add [bx+si],al
0000908F  0000              add [bx+si],al
00009091  0000              add [bx+si],al
00009093  0000              add [bx+si],al
00009095  0000              add [bx+si],al
00009097  0000              add [bx+si],al
00009099  0000              add [bx+si],al
0000909B  0000              add [bx+si],al
0000909D  0000              add [bx+si],al
0000909F  0000              add [bx+si],al
000090A1  0000              add [bx+si],al
000090A3  0000              add [bx+si],al
000090A5  0000              add [bx+si],al
000090A7  0000              add [bx+si],al
000090A9  0000              add [bx+si],al
000090AB  0000              add [bx+si],al
000090AD  0000              add [bx+si],al
000090AF  0000              add [bx+si],al
000090B1  0000              add [bx+si],al
000090B3  0000              add [bx+si],al
000090B5  0000              add [bx+si],al
000090B7  0000              add [bx+si],al
000090B9  0000              add [bx+si],al
000090BB  0000              add [bx+si],al
000090BD  0000              add [bx+si],al
000090BF  0000              add [bx+si],al
000090C1  0000              add [bx+si],al
000090C3  0000              add [bx+si],al
000090C5  0000              add [bx+si],al
000090C7  0000              add [bx+si],al
000090C9  0000              add [bx+si],al
000090CB  0000              add [bx+si],al
000090CD  0000              add [bx+si],al
000090CF  0000              add [bx+si],al
000090D1  0000              add [bx+si],al
000090D3  0000              add [bx+si],al
000090D5  0000              add [bx+si],al
000090D7  0000              add [bx+si],al
000090D9  0000              add [bx+si],al
000090DB  0000              add [bx+si],al
000090DD  0000              add [bx+si],al
000090DF  0000              add [bx+si],al
000090E1  0000              add [bx+si],al
000090E3  0000              add [bx+si],al
000090E5  0000              add [bx+si],al
000090E7  0000              add [bx+si],al
000090E9  0000              add [bx+si],al
000090EB  0000              add [bx+si],al
000090ED  0000              add [bx+si],al
000090EF  0000              add [bx+si],al
000090F1  0000              add [bx+si],al
000090F3  0000              add [bx+si],al
000090F5  0000              add [bx+si],al
000090F7  0000              add [bx+si],al
000090F9  0000              add [bx+si],al
000090FB  0000              add [bx+si],al
000090FD  0000              add [bx+si],al
000090FF  0000              add [bx+si],al
00009101  0000              add [bx+si],al
00009103  0000              add [bx+si],al
00009105  0000              add [bx+si],al
00009107  0000              add [bx+si],al
00009109  0000              add [bx+si],al
0000910B  0000              add [bx+si],al
0000910D  0000              add [bx+si],al
0000910F  0000              add [bx+si],al
00009111  0000              add [bx+si],al
00009113  0000              add [bx+si],al
00009115  0000              add [bx+si],al
00009117  0000              add [bx+si],al
00009119  0000              add [bx+si],al
0000911B  0000              add [bx+si],al
0000911D  0000              add [bx+si],al
0000911F  0000              add [bx+si],al
00009121  0000              add [bx+si],al
00009123  0000              add [bx+si],al
00009125  0000              add [bx+si],al
00009127  0000              add [bx+si],al
00009129  0000              add [bx+si],al
0000912B  0000              add [bx+si],al
0000912D  0000              add [bx+si],al
0000912F  0000              add [bx+si],al
00009131  0000              add [bx+si],al
00009133  0000              add [bx+si],al
00009135  0000              add [bx+si],al
00009137  0000              add [bx+si],al
00009139  0000              add [bx+si],al
0000913B  0000              add [bx+si],al
0000913D  0000              add [bx+si],al
0000913F  0000              add [bx+si],al
00009141  0000              add [bx+si],al
00009143  0000              add [bx+si],al
00009145  0000              add [bx+si],al
00009147  0000              add [bx+si],al
00009149  0000              add [bx+si],al
0000914B  0000              add [bx+si],al
0000914D  0000              add [bx+si],al
0000914F  0000              add [bx+si],al
00009151  0000              add [bx+si],al
00009153  0000              add [bx+si],al
00009155  0000              add [bx+si],al
00009157  0000              add [bx+si],al
00009159  0000              add [bx+si],al
0000915B  0000              add [bx+si],al
0000915D  0000              add [bx+si],al
0000915F  0000              add [bx+si],al
00009161  0000              add [bx+si],al
00009163  0000              add [bx+si],al
00009165  0000              add [bx+si],al
00009167  0000              add [bx+si],al
00009169  0000              add [bx+si],al
0000916B  0000              add [bx+si],al
0000916D  0000              add [bx+si],al
0000916F  0000              add [bx+si],al
00009171  0000              add [bx+si],al
00009173  0000              add [bx+si],al
00009175  0000              add [bx+si],al
00009177  0000              add [bx+si],al
00009179  0000              add [bx+si],al
0000917B  0000              add [bx+si],al
0000917D  0000              add [bx+si],al
0000917F  0000              add [bx+si],al
00009181  0000              add [bx+si],al
00009183  0000              add [bx+si],al
00009185  0000              add [bx+si],al
00009187  0000              add [bx+si],al
00009189  0000              add [bx+si],al
0000918B  0000              add [bx+si],al
0000918D  0000              add [bx+si],al
0000918F  0000              add [bx+si],al
00009191  0000              add [bx+si],al
00009193  0000              add [bx+si],al
00009195  0000              add [bx+si],al
00009197  0000              add [bx+si],al
00009199  0000              add [bx+si],al
0000919B  0000              add [bx+si],al
0000919D  0000              add [bx+si],al
0000919F  0000              add [bx+si],al
000091A1  0000              add [bx+si],al
000091A3  0000              add [bx+si],al
000091A5  0000              add [bx+si],al
000091A7  0000              add [bx+si],al
000091A9  0000              add [bx+si],al
000091AB  0000              add [bx+si],al
000091AD  0000              add [bx+si],al
000091AF  0000              add [bx+si],al
000091B1  0000              add [bx+si],al
000091B3  0000              add [bx+si],al
000091B5  0000              add [bx+si],al
000091B7  0000              add [bx+si],al
000091B9  0000              add [bx+si],al
000091BB  0000              add [bx+si],al
000091BD  0000              add [bx+si],al
000091BF  0000              add [bx+si],al
000091C1  0000              add [bx+si],al
000091C3  0000              add [bx+si],al
000091C5  0000              add [bx+si],al
000091C7  0000              add [bx+si],al
000091C9  0000              add [bx+si],al
000091CB  0000              add [bx+si],al
000091CD  0000              add [bx+si],al
000091CF  0000              add [bx+si],al
000091D1  0000              add [bx+si],al
000091D3  0000              add [bx+si],al
000091D5  0000              add [bx+si],al
000091D7  0000              add [bx+si],al
000091D9  0000              add [bx+si],al
000091DB  0000              add [bx+si],al
000091DD  0000              add [bx+si],al
000091DF  0000              add [bx+si],al
000091E1  0000              add [bx+si],al
000091E3  0000              add [bx+si],al
000091E5  0000              add [bx+si],al
000091E7  0000              add [bx+si],al
000091E9  0000              add [bx+si],al
000091EB  0000              add [bx+si],al
000091ED  0000              add [bx+si],al
000091EF  0000              add [bx+si],al
000091F1  0000              add [bx+si],al
000091F3  0000              add [bx+si],al
000091F5  0000              add [bx+si],al
000091F7  0000              add [bx+si],al
000091F9  0000              add [bx+si],al
000091FB  0000              add [bx+si],al
000091FD  0000              add [bx+si],al
000091FF  0000              add [bx+si],al
00009201  0000              add [bx+si],al
00009203  0000              add [bx+si],al
00009205  0000              add [bx+si],al
00009207  0000              add [bx+si],al
00009209  0000              add [bx+si],al
0000920B  0000              add [bx+si],al
0000920D  0000              add [bx+si],al
0000920F  0000              add [bx+si],al
00009211  0000              add [bx+si],al
00009213  0000              add [bx+si],al
00009215  0000              add [bx+si],al
00009217  0000              add [bx+si],al
00009219  0000              add [bx+si],al
0000921B  0000              add [bx+si],al
0000921D  0000              add [bx+si],al
0000921F  0000              add [bx+si],al
00009221  0000              add [bx+si],al
00009223  0000              add [bx+si],al
00009225  0000              add [bx+si],al
00009227  0000              add [bx+si],al
00009229  0000              add [bx+si],al
0000922B  0000              add [bx+si],al
0000922D  0000              add [bx+si],al
0000922F  0000              add [bx+si],al
00009231  0000              add [bx+si],al
00009233  0000              add [bx+si],al
00009235  0000              add [bx+si],al
00009237  0000              add [bx+si],al
00009239  0000              add [bx+si],al
0000923B  0000              add [bx+si],al
0000923D  0000              add [bx+si],al
0000923F  0000              add [bx+si],al
00009241  0000              add [bx+si],al
00009243  0000              add [bx+si],al
00009245  0000              add [bx+si],al
00009247  0000              add [bx+si],al
00009249  0000              add [bx+si],al
0000924B  0000              add [bx+si],al
0000924D  0000              add [bx+si],al
0000924F  0000              add [bx+si],al
00009251  0000              add [bx+si],al
00009253  0000              add [bx+si],al
00009255  0000              add [bx+si],al
00009257  0000              add [bx+si],al
00009259  0000              add [bx+si],al
0000925B  0000              add [bx+si],al
0000925D  0000              add [bx+si],al
0000925F  0000              add [bx+si],al
00009261  0000              add [bx+si],al
00009263  0000              add [bx+si],al
00009265  0000              add [bx+si],al
00009267  0000              add [bx+si],al
00009269  0000              add [bx+si],al
0000926B  0000              add [bx+si],al
0000926D  0000              add [bx+si],al
0000926F  0000              add [bx+si],al
00009271  0000              add [bx+si],al
00009273  0000              add [bx+si],al
00009275  0000              add [bx+si],al
00009277  0000              add [bx+si],al
00009279  0000              add [bx+si],al
0000927B  0000              add [bx+si],al
0000927D  0000              add [bx+si],al
0000927F  0000              add [bx+si],al
00009281  0000              add [bx+si],al
00009283  0000              add [bx+si],al
00009285  0000              add [bx+si],al
00009287  0000              add [bx+si],al
00009289  0000              add [bx+si],al
0000928B  0000              add [bx+si],al
0000928D  0000              add [bx+si],al
0000928F  0000              add [bx+si],al
00009291  0000              add [bx+si],al
00009293  0000              add [bx+si],al
00009295  0000              add [bx+si],al
00009297  0000              add [bx+si],al
00009299  0000              add [bx+si],al
0000929B  0000              add [bx+si],al
0000929D  0000              add [bx+si],al
0000929F  0000              add [bx+si],al
000092A1  0000              add [bx+si],al
000092A3  0000              add [bx+si],al
000092A5  0000              add [bx+si],al
000092A7  0000              add [bx+si],al
000092A9  0000              add [bx+si],al
000092AB  0000              add [bx+si],al
000092AD  0000              add [bx+si],al
000092AF  0000              add [bx+si],al
000092B1  0000              add [bx+si],al
000092B3  0000              add [bx+si],al
000092B5  0000              add [bx+si],al
000092B7  0000              add [bx+si],al
000092B9  0000              add [bx+si],al
000092BB  0000              add [bx+si],al
000092BD  0000              add [bx+si],al
000092BF  0000              add [bx+si],al
000092C1  0000              add [bx+si],al
000092C3  0000              add [bx+si],al
000092C5  0000              add [bx+si],al
000092C7  0000              add [bx+si],al
000092C9  0000              add [bx+si],al
000092CB  0000              add [bx+si],al
000092CD  0000              add [bx+si],al
000092CF  0000              add [bx+si],al
000092D1  0000              add [bx+si],al
000092D3  0000              add [bx+si],al
000092D5  0000              add [bx+si],al
000092D7  0000              add [bx+si],al
000092D9  0000              add [bx+si],al
000092DB  0000              add [bx+si],al
000092DD  0000              add [bx+si],al
000092DF  0000              add [bx+si],al
000092E1  0000              add [bx+si],al
000092E3  0000              add [bx+si],al
000092E5  0000              add [bx+si],al
000092E7  0000              add [bx+si],al
000092E9  0000              add [bx+si],al
000092EB  0000              add [bx+si],al
000092ED  0000              add [bx+si],al
000092EF  0000              add [bx+si],al
000092F1  0000              add [bx+si],al
000092F3  0000              add [bx+si],al
000092F5  0000              add [bx+si],al
000092F7  0000              add [bx+si],al
000092F9  0000              add [bx+si],al
000092FB  0000              add [bx+si],al
000092FD  0000              add [bx+si],al
000092FF  0000              add [bx+si],al
00009301  0000              add [bx+si],al
00009303  0000              add [bx+si],al
00009305  0000              add [bx+si],al
00009307  0000              add [bx+si],al
00009309  0000              add [bx+si],al
0000930B  0000              add [bx+si],al
0000930D  0000              add [bx+si],al
0000930F  0000              add [bx+si],al
00009311  0000              add [bx+si],al
00009313  0000              add [bx+si],al
00009315  0000              add [bx+si],al
00009317  0000              add [bx+si],al
00009319  0000              add [bx+si],al
0000931B  0000              add [bx+si],al
0000931D  0000              add [bx+si],al
0000931F  0000              add [bx+si],al
00009321  0000              add [bx+si],al
00009323  0000              add [bx+si],al
00009325  0000              add [bx+si],al
00009327  0000              add [bx+si],al
00009329  0000              add [bx+si],al
0000932B  0000              add [bx+si],al
0000932D  0000              add [bx+si],al
0000932F  0000              add [bx+si],al
00009331  0000              add [bx+si],al
00009333  0000              add [bx+si],al
00009335  0000              add [bx+si],al
00009337  0000              add [bx+si],al
00009339  0000              add [bx+si],al
0000933B  0000              add [bx+si],al
0000933D  0000              add [bx+si],al
0000933F  0000              add [bx+si],al
00009341  0000              add [bx+si],al
00009343  0000              add [bx+si],al
00009345  0000              add [bx+si],al
00009347  0000              add [bx+si],al
00009349  0000              add [bx+si],al
0000934B  0000              add [bx+si],al
0000934D  0000              add [bx+si],al
0000934F  0000              add [bx+si],al
00009351  0000              add [bx+si],al
00009353  0000              add [bx+si],al
00009355  0000              add [bx+si],al
00009357  0000              add [bx+si],al
00009359  0000              add [bx+si],al
0000935B  0000              add [bx+si],al
0000935D  0000              add [bx+si],al
0000935F  0000              add [bx+si],al
00009361  0000              add [bx+si],al
00009363  0000              add [bx+si],al
00009365  0000              add [bx+si],al
00009367  0000              add [bx+si],al
00009369  0000              add [bx+si],al
0000936B  0000              add [bx+si],al
0000936D  0000              add [bx+si],al
0000936F  0000              add [bx+si],al
00009371  0000              add [bx+si],al
00009373  0000              add [bx+si],al
00009375  0000              add [bx+si],al
00009377  0000              add [bx+si],al
00009379  0000              add [bx+si],al
0000937B  0000              add [bx+si],al
0000937D  0000              add [bx+si],al
0000937F  0000              add [bx+si],al
00009381  0000              add [bx+si],al
00009383  0000              add [bx+si],al
00009385  0000              add [bx+si],al
00009387  0000              add [bx+si],al
00009389  0000              add [bx+si],al
0000938B  0000              add [bx+si],al
0000938D  0000              add [bx+si],al
0000938F  0000              add [bx+si],al
00009391  0000              add [bx+si],al
00009393  0000              add [bx+si],al
00009395  0000              add [bx+si],al
00009397  0000              add [bx+si],al
00009399  0000              add [bx+si],al
0000939B  0000              add [bx+si],al
0000939D  0000              add [bx+si],al
0000939F  0000              add [bx+si],al
000093A1  0000              add [bx+si],al
000093A3  0000              add [bx+si],al
000093A5  0000              add [bx+si],al
000093A7  0000              add [bx+si],al
000093A9  0000              add [bx+si],al
000093AB  0000              add [bx+si],al
000093AD  0000              add [bx+si],al
000093AF  0000              add [bx+si],al
000093B1  0000              add [bx+si],al
000093B3  0000              add [bx+si],al
000093B5  0000              add [bx+si],al
000093B7  0000              add [bx+si],al
000093B9  0000              add [bx+si],al
000093BB  0000              add [bx+si],al
000093BD  0000              add [bx+si],al
000093BF  0000              add [bx+si],al
000093C1  0000              add [bx+si],al
000093C3  0000              add [bx+si],al
000093C5  0000              add [bx+si],al
000093C7  0000              add [bx+si],al
000093C9  0000              add [bx+si],al
000093CB  0000              add [bx+si],al
000093CD  0000              add [bx+si],al
000093CF  0000              add [bx+si],al
000093D1  0000              add [bx+si],al
000093D3  0000              add [bx+si],al
000093D5  0000              add [bx+si],al
000093D7  0000              add [bx+si],al
000093D9  0000              add [bx+si],al
000093DB  0000              add [bx+si],al
000093DD  0000              add [bx+si],al
000093DF  0000              add [bx+si],al
000093E1  0000              add [bx+si],al
000093E3  0000              add [bx+si],al
000093E5  0000              add [bx+si],al
000093E7  0000              add [bx+si],al
000093E9  0000              add [bx+si],al
000093EB  0000              add [bx+si],al
000093ED  0000              add [bx+si],al
000093EF  0000              add [bx+si],al
000093F1  0000              add [bx+si],al
000093F3  0000              add [bx+si],al
000093F5  0000              add [bx+si],al
000093F7  0000              add [bx+si],al
000093F9  0000              add [bx+si],al
000093FB  0000              add [bx+si],al
000093FD  0000              add [bx+si],al
000093FF  0000              add [bx+si],al
00009401  0000              add [bx+si],al
00009403  0000              add [bx+si],al
00009405  0000              add [bx+si],al
00009407  0000              add [bx+si],al
00009409  0000              add [bx+si],al
0000940B  0000              add [bx+si],al
0000940D  0000              add [bx+si],al
0000940F  0000              add [bx+si],al
00009411  0000              add [bx+si],al
00009413  0000              add [bx+si],al
00009415  0000              add [bx+si],al
00009417  0000              add [bx+si],al
00009419  0000              add [bx+si],al
0000941B  0000              add [bx+si],al
0000941D  0000              add [bx+si],al
0000941F  0000              add [bx+si],al
00009421  0000              add [bx+si],al
00009423  0000              add [bx+si],al
00009425  0000              add [bx+si],al
00009427  0000              add [bx+si],al
00009429  0000              add [bx+si],al
0000942B  0000              add [bx+si],al
0000942D  0000              add [bx+si],al
0000942F  0000              add [bx+si],al
00009431  0000              add [bx+si],al
00009433  0000              add [bx+si],al
00009435  0000              add [bx+si],al
00009437  0000              add [bx+si],al
00009439  0000              add [bx+si],al
0000943B  0000              add [bx+si],al
0000943D  0000              add [bx+si],al
0000943F  0000              add [bx+si],al
00009441  0000              add [bx+si],al
00009443  0000              add [bx+si],al
00009445  0000              add [bx+si],al
00009447  0000              add [bx+si],al
00009449  0000              add [bx+si],al
0000944B  0000              add [bx+si],al
0000944D  0000              add [bx+si],al
0000944F  0000              add [bx+si],al
00009451  0000              add [bx+si],al
00009453  0000              add [bx+si],al
00009455  0000              add [bx+si],al
00009457  0000              add [bx+si],al
00009459  0000              add [bx+si],al
0000945B  0000              add [bx+si],al
0000945D  0000              add [bx+si],al
0000945F  0000              add [bx+si],al
00009461  0000              add [bx+si],al
00009463  0000              add [bx+si],al
00009465  0000              add [bx+si],al
00009467  0000              add [bx+si],al
00009469  0000              add [bx+si],al
0000946B  0000              add [bx+si],al
0000946D  0000              add [bx+si],al
0000946F  0000              add [bx+si],al
00009471  0000              add [bx+si],al
00009473  0000              add [bx+si],al
00009475  0000              add [bx+si],al
00009477  0000              add [bx+si],al
00009479  0000              add [bx+si],al
0000947B  0000              add [bx+si],al
0000947D  0000              add [bx+si],al
0000947F  0000              add [bx+si],al
00009481  0000              add [bx+si],al
00009483  0000              add [bx+si],al
00009485  0000              add [bx+si],al
00009487  0000              add [bx+si],al
00009489  0000              add [bx+si],al
0000948B  0000              add [bx+si],al
0000948D  0000              add [bx+si],al
0000948F  0000              add [bx+si],al
00009491  0000              add [bx+si],al
00009493  0000              add [bx+si],al
00009495  0000              add [bx+si],al
00009497  0000              add [bx+si],al
00009499  0000              add [bx+si],al
0000949B  0000              add [bx+si],al
0000949D  0000              add [bx+si],al
0000949F  0000              add [bx+si],al
000094A1  0000              add [bx+si],al
000094A3  0000              add [bx+si],al
000094A5  0000              add [bx+si],al
000094A7  0000              add [bx+si],al
000094A9  0000              add [bx+si],al
000094AB  0000              add [bx+si],al
000094AD  0000              add [bx+si],al
000094AF  0000              add [bx+si],al
000094B1  0000              add [bx+si],al
000094B3  0000              add [bx+si],al
000094B5  0000              add [bx+si],al
000094B7  0000              add [bx+si],al
000094B9  0000              add [bx+si],al
000094BB  0000              add [bx+si],al
000094BD  0000              add [bx+si],al
000094BF  0000              add [bx+si],al
000094C1  0000              add [bx+si],al
000094C3  0000              add [bx+si],al
000094C5  0000              add [bx+si],al
000094C7  0000              add [bx+si],al
000094C9  0000              add [bx+si],al
000094CB  0000              add [bx+si],al
000094CD  0000              add [bx+si],al
000094CF  0000              add [bx+si],al
000094D1  0000              add [bx+si],al
000094D3  0000              add [bx+si],al
000094D5  0000              add [bx+si],al
000094D7  0000              add [bx+si],al
000094D9  0000              add [bx+si],al
000094DB  0000              add [bx+si],al
000094DD  0000              add [bx+si],al
000094DF  0000              add [bx+si],al
000094E1  0000              add [bx+si],al
000094E3  0000              add [bx+si],al
000094E5  0000              add [bx+si],al
000094E7  0000              add [bx+si],al
000094E9  0000              add [bx+si],al
000094EB  0000              add [bx+si],al
000094ED  0000              add [bx+si],al
000094EF  0000              add [bx+si],al
000094F1  0000              add [bx+si],al
000094F3  0000              add [bx+si],al
000094F5  0000              add [bx+si],al
000094F7  0000              add [bx+si],al
000094F9  0000              add [bx+si],al
000094FB  0000              add [bx+si],al
000094FD  0000              add [bx+si],al
000094FF  0000              add [bx+si],al
00009501  0000              add [bx+si],al
00009503  0000              add [bx+si],al
00009505  0000              add [bx+si],al
00009507  0000              add [bx+si],al
00009509  0000              add [bx+si],al
0000950B  0000              add [bx+si],al
0000950D  0000              add [bx+si],al
0000950F  0000              add [bx+si],al
00009511  0000              add [bx+si],al
00009513  0000              add [bx+si],al
00009515  0000              add [bx+si],al
00009517  0000              add [bx+si],al
00009519  0000              add [bx+si],al
0000951B  0000              add [bx+si],al
0000951D  0000              add [bx+si],al
0000951F  0000              add [bx+si],al
00009521  0000              add [bx+si],al
00009523  0000              add [bx+si],al
00009525  0000              add [bx+si],al
00009527  0000              add [bx+si],al
00009529  0000              add [bx+si],al
0000952B  0000              add [bx+si],al
0000952D  0000              add [bx+si],al
0000952F  0000              add [bx+si],al
00009531  0000              add [bx+si],al
00009533  0000              add [bx+si],al
00009535  0000              add [bx+si],al
00009537  0000              add [bx+si],al
00009539  0000              add [bx+si],al
0000953B  0000              add [bx+si],al
0000953D  0000              add [bx+si],al
0000953F  0000              add [bx+si],al
00009541  0000              add [bx+si],al
00009543  0000              add [bx+si],al
00009545  0000              add [bx+si],al
00009547  0000              add [bx+si],al
00009549  0000              add [bx+si],al
0000954B  0000              add [bx+si],al
0000954D  0000              add [bx+si],al
0000954F  0000              add [bx+si],al
00009551  0000              add [bx+si],al
00009553  0000              add [bx+si],al
00009555  0000              add [bx+si],al
00009557  0000              add [bx+si],al
00009559  0000              add [bx+si],al
0000955B  0000              add [bx+si],al
0000955D  0000              add [bx+si],al
0000955F  0000              add [bx+si],al
00009561  0000              add [bx+si],al
00009563  0000              add [bx+si],al
00009565  0000              add [bx+si],al
00009567  0000              add [bx+si],al
00009569  0000              add [bx+si],al
0000956B  0000              add [bx+si],al
0000956D  0000              add [bx+si],al
0000956F  0000              add [bx+si],al
00009571  0000              add [bx+si],al
00009573  0000              add [bx+si],al
00009575  0000              add [bx+si],al
00009577  0000              add [bx+si],al
00009579  0000              add [bx+si],al
0000957B  0000              add [bx+si],al
0000957D  0000              add [bx+si],al
0000957F  0000              add [bx+si],al
00009581  0000              add [bx+si],al
00009583  0000              add [bx+si],al
00009585  0000              add [bx+si],al
00009587  0000              add [bx+si],al
00009589  0000              add [bx+si],al
0000958B  0000              add [bx+si],al
0000958D  0000              add [bx+si],al
0000958F  0000              add [bx+si],al
00009591  0000              add [bx+si],al
00009593  0000              add [bx+si],al
00009595  0000              add [bx+si],al
00009597  0000              add [bx+si],al
00009599  0000              add [bx+si],al
0000959B  0000              add [bx+si],al
0000959D  0000              add [bx+si],al
0000959F  0000              add [bx+si],al
000095A1  0000              add [bx+si],al
000095A3  0000              add [bx+si],al
000095A5  0000              add [bx+si],al
000095A7  0000              add [bx+si],al
000095A9  0000              add [bx+si],al
000095AB  0000              add [bx+si],al
000095AD  0000              add [bx+si],al
000095AF  0000              add [bx+si],al
000095B1  0000              add [bx+si],al
000095B3  0000              add [bx+si],al
000095B5  0000              add [bx+si],al
000095B7  0000              add [bx+si],al
000095B9  0000              add [bx+si],al
000095BB  0000              add [bx+si],al
000095BD  0000              add [bx+si],al
000095BF  0000              add [bx+si],al
000095C1  0000              add [bx+si],al
000095C3  0000              add [bx+si],al
000095C5  0000              add [bx+si],al
000095C7  0000              add [bx+si],al
000095C9  0000              add [bx+si],al
000095CB  0000              add [bx+si],al
000095CD  0000              add [bx+si],al
000095CF  0000              add [bx+si],al
000095D1  0000              add [bx+si],al
000095D3  0000              add [bx+si],al
000095D5  0000              add [bx+si],al
000095D7  0000              add [bx+si],al
000095D9  0000              add [bx+si],al
000095DB  0000              add [bx+si],al
000095DD  0000              add [bx+si],al
000095DF  0000              add [bx+si],al
000095E1  0000              add [bx+si],al
000095E3  0000              add [bx+si],al
000095E5  0000              add [bx+si],al
000095E7  0000              add [bx+si],al
000095E9  0000              add [bx+si],al
000095EB  0000              add [bx+si],al
000095ED  0000              add [bx+si],al
000095EF  0000              add [bx+si],al
000095F1  0000              add [bx+si],al
000095F3  0000              add [bx+si],al
000095F5  0000              add [bx+si],al
000095F7  0000              add [bx+si],al
000095F9  0000              add [bx+si],al
000095FB  0000              add [bx+si],al
000095FD  0000              add [bx+si],al
000095FF  0000              add [bx+si],al
00009601  0000              add [bx+si],al
00009603  0000              add [bx+si],al
00009605  0000              add [bx+si],al
00009607  0000              add [bx+si],al
00009609  0000              add [bx+si],al
0000960B  0000              add [bx+si],al
0000960D  0000              add [bx+si],al
0000960F  0000              add [bx+si],al
00009611  0000              add [bx+si],al
00009613  0000              add [bx+si],al
00009615  0000              add [bx+si],al
00009617  0000              add [bx+si],al
00009619  0000              add [bx+si],al
0000961B  0000              add [bx+si],al
0000961D  0000              add [bx+si],al
0000961F  0000              add [bx+si],al
00009621  0000              add [bx+si],al
00009623  0000              add [bx+si],al
00009625  0000              add [bx+si],al
00009627  0000              add [bx+si],al
00009629  0000              add [bx+si],al
0000962B  0000              add [bx+si],al
0000962D  0000              add [bx+si],al
0000962F  0000              add [bx+si],al
00009631  0000              add [bx+si],al
00009633  0000              add [bx+si],al
00009635  0000              add [bx+si],al
00009637  0000              add [bx+si],al
00009639  0000              add [bx+si],al
0000963B  0000              add [bx+si],al
0000963D  0000              add [bx+si],al
0000963F  0000              add [bx+si],al
00009641  0000              add [bx+si],al
00009643  0000              add [bx+si],al
00009645  0000              add [bx+si],al
00009647  0000              add [bx+si],al
00009649  0000              add [bx+si],al
0000964B  0000              add [bx+si],al
0000964D  0000              add [bx+si],al
0000964F  0000              add [bx+si],al
00009651  0000              add [bx+si],al
00009653  0000              add [bx+si],al
00009655  0000              add [bx+si],al
00009657  0000              add [bx+si],al
00009659  0000              add [bx+si],al
0000965B  0000              add [bx+si],al
0000965D  0000              add [bx+si],al
0000965F  0000              add [bx+si],al
00009661  0000              add [bx+si],al
00009663  0000              add [bx+si],al
00009665  0000              add [bx+si],al
00009667  0000              add [bx+si],al
00009669  0000              add [bx+si],al
0000966B  0000              add [bx+si],al
0000966D  0000              add [bx+si],al
0000966F  0000              add [bx+si],al
00009671  0000              add [bx+si],al
00009673  0000              add [bx+si],al
00009675  0000              add [bx+si],al
00009677  0000              add [bx+si],al
00009679  0000              add [bx+si],al
0000967B  0000              add [bx+si],al
0000967D  0000              add [bx+si],al
0000967F  0000              add [bx+si],al
00009681  0000              add [bx+si],al
00009683  0000              add [bx+si],al
00009685  0000              add [bx+si],al
00009687  0000              add [bx+si],al
00009689  0000              add [bx+si],al
0000968B  0000              add [bx+si],al
0000968D  0000              add [bx+si],al
0000968F  0000              add [bx+si],al
00009691  0000              add [bx+si],al
00009693  0000              add [bx+si],al
00009695  0000              add [bx+si],al
00009697  0000              add [bx+si],al
00009699  0000              add [bx+si],al
0000969B  0000              add [bx+si],al
0000969D  0000              add [bx+si],al
0000969F  0000              add [bx+si],al
000096A1  0000              add [bx+si],al
000096A3  0000              add [bx+si],al
000096A5  0000              add [bx+si],al
000096A7  0000              add [bx+si],al
000096A9  0000              add [bx+si],al
000096AB  0000              add [bx+si],al
000096AD  0000              add [bx+si],al
000096AF  0000              add [bx+si],al
000096B1  0000              add [bx+si],al
000096B3  0000              add [bx+si],al
000096B5  0000              add [bx+si],al
000096B7  0000              add [bx+si],al
000096B9  0000              add [bx+si],al
000096BB  0000              add [bx+si],al
000096BD  0000              add [bx+si],al
000096BF  0000              add [bx+si],al
000096C1  0000              add [bx+si],al
000096C3  0000              add [bx+si],al
000096C5  0000              add [bx+si],al
000096C7  0000              add [bx+si],al
000096C9  0000              add [bx+si],al
000096CB  0000              add [bx+si],al
000096CD  0000              add [bx+si],al
000096CF  0000              add [bx+si],al
000096D1  0000              add [bx+si],al
000096D3  0000              add [bx+si],al
000096D5  0000              add [bx+si],al
000096D7  0000              add [bx+si],al
000096D9  0000              add [bx+si],al
000096DB  0000              add [bx+si],al
000096DD  0000              add [bx+si],al
000096DF  0000              add [bx+si],al
000096E1  0000              add [bx+si],al
000096E3  0000              add [bx+si],al
000096E5  0000              add [bx+si],al
000096E7  0000              add [bx+si],al
000096E9  0000              add [bx+si],al
000096EB  0000              add [bx+si],al
000096ED  0000              add [bx+si],al
000096EF  0000              add [bx+si],al
000096F1  0000              add [bx+si],al
000096F3  0000              add [bx+si],al
000096F5  0000              add [bx+si],al
000096F7  0000              add [bx+si],al
000096F9  0000              add [bx+si],al
000096FB  0000              add [bx+si],al
000096FD  0000              add [bx+si],al
000096FF  0000              add [bx+si],al
00009701  0000              add [bx+si],al
00009703  0000              add [bx+si],al
00009705  0000              add [bx+si],al
00009707  0000              add [bx+si],al
00009709  0000              add [bx+si],al
0000970B  0000              add [bx+si],al
0000970D  0000              add [bx+si],al
0000970F  0000              add [bx+si],al
00009711  0000              add [bx+si],al
00009713  0000              add [bx+si],al
00009715  0000              add [bx+si],al
00009717  0000              add [bx+si],al
00009719  0000              add [bx+si],al
0000971B  0000              add [bx+si],al
0000971D  0000              add [bx+si],al
0000971F  0000              add [bx+si],al
00009721  0000              add [bx+si],al
00009723  0000              add [bx+si],al
00009725  0000              add [bx+si],al
00009727  0000              add [bx+si],al
00009729  0000              add [bx+si],al
0000972B  0000              add [bx+si],al
0000972D  0000              add [bx+si],al
0000972F  0000              add [bx+si],al
00009731  0000              add [bx+si],al
00009733  0000              add [bx+si],al
00009735  0000              add [bx+si],al
00009737  0000              add [bx+si],al
00009739  0000              add [bx+si],al
0000973B  0000              add [bx+si],al
0000973D  0000              add [bx+si],al
0000973F  0000              add [bx+si],al
00009741  0000              add [bx+si],al
00009743  0000              add [bx+si],al
00009745  0000              add [bx+si],al
00009747  0000              add [bx+si],al
00009749  0000              add [bx+si],al
0000974B  0000              add [bx+si],al
0000974D  0000              add [bx+si],al
0000974F  0000              add [bx+si],al
00009751  0000              add [bx+si],al
00009753  0000              add [bx+si],al
00009755  0000              add [bx+si],al
00009757  0000              add [bx+si],al
00009759  0000              add [bx+si],al
0000975B  0000              add [bx+si],al
0000975D  0000              add [bx+si],al
0000975F  0000              add [bx+si],al
00009761  0000              add [bx+si],al
00009763  0000              add [bx+si],al
00009765  0000              add [bx+si],al
00009767  0000              add [bx+si],al
00009769  0000              add [bx+si],al
0000976B  0000              add [bx+si],al
0000976D  0000              add [bx+si],al
0000976F  0000              add [bx+si],al
00009771  0000              add [bx+si],al
00009773  0000              add [bx+si],al
00009775  0000              add [bx+si],al
00009777  0000              add [bx+si],al
00009779  0000              add [bx+si],al
0000977B  0000              add [bx+si],al
0000977D  0000              add [bx+si],al
0000977F  0000              add [bx+si],al
00009781  0000              add [bx+si],al
00009783  0000              add [bx+si],al
00009785  0000              add [bx+si],al
00009787  0000              add [bx+si],al
00009789  0000              add [bx+si],al
0000978B  0000              add [bx+si],al
0000978D  0000              add [bx+si],al
0000978F  0000              add [bx+si],al
00009791  0000              add [bx+si],al
00009793  0000              add [bx+si],al
00009795  0000              add [bx+si],al
00009797  0000              add [bx+si],al
00009799  0000              add [bx+si],al
0000979B  0000              add [bx+si],al
0000979D  0000              add [bx+si],al
0000979F  0000              add [bx+si],al
000097A1  0000              add [bx+si],al
000097A3  0000              add [bx+si],al
000097A5  0000              add [bx+si],al
000097A7  0000              add [bx+si],al
000097A9  0000              add [bx+si],al
000097AB  0000              add [bx+si],al
000097AD  0000              add [bx+si],al
000097AF  0000              add [bx+si],al
000097B1  0000              add [bx+si],al
000097B3  0000              add [bx+si],al
000097B5  0000              add [bx+si],al
000097B7  0000              add [bx+si],al
000097B9  0000              add [bx+si],al
000097BB  0000              add [bx+si],al
000097BD  0000              add [bx+si],al
000097BF  0000              add [bx+si],al
000097C1  0000              add [bx+si],al
000097C3  0000              add [bx+si],al
000097C5  0000              add [bx+si],al
000097C7  0000              add [bx+si],al
000097C9  0000              add [bx+si],al
000097CB  0000              add [bx+si],al
000097CD  0000              add [bx+si],al
000097CF  0000              add [bx+si],al
000097D1  0000              add [bx+si],al
000097D3  0000              add [bx+si],al
000097D5  0000              add [bx+si],al
000097D7  0000              add [bx+si],al
000097D9  0000              add [bx+si],al
000097DB  0000              add [bx+si],al
000097DD  0000              add [bx+si],al
000097DF  0000              add [bx+si],al
000097E1  0000              add [bx+si],al
000097E3  0000              add [bx+si],al
000097E5  0000              add [bx+si],al
000097E7  0000              add [bx+si],al
000097E9  0000              add [bx+si],al
000097EB  0000              add [bx+si],al
000097ED  0000              add [bx+si],al
000097EF  0000              add [bx+si],al
000097F1  0000              add [bx+si],al
000097F3  0000              add [bx+si],al
000097F5  0000              add [bx+si],al
000097F7  0000              add [bx+si],al
000097F9  0000              add [bx+si],al
000097FB  0000              add [bx+si],al
000097FD  0000              add [bx+si],al
000097FF  0000              add [bx+si],al
00009801  0000              add [bx+si],al
00009803  0000              add [bx+si],al
00009805  0000              add [bx+si],al
00009807  0000              add [bx+si],al
00009809  0000              add [bx+si],al
0000980B  0000              add [bx+si],al
0000980D  0000              add [bx+si],al
0000980F  0000              add [bx+si],al
00009811  0000              add [bx+si],al
00009813  0000              add [bx+si],al
00009815  0000              add [bx+si],al
00009817  0000              add [bx+si],al
00009819  0000              add [bx+si],al
0000981B  0000              add [bx+si],al
0000981D  0000              add [bx+si],al
0000981F  0000              add [bx+si],al
00009821  0000              add [bx+si],al
00009823  0000              add [bx+si],al
00009825  0000              add [bx+si],al
00009827  0000              add [bx+si],al
00009829  0000              add [bx+si],al
0000982B  0000              add [bx+si],al
0000982D  0000              add [bx+si],al
0000982F  0000              add [bx+si],al
00009831  0000              add [bx+si],al
00009833  0000              add [bx+si],al
00009835  0000              add [bx+si],al
00009837  0000              add [bx+si],al
00009839  0000              add [bx+si],al
0000983B  0000              add [bx+si],al
0000983D  0000              add [bx+si],al
0000983F  0000              add [bx+si],al
00009841  0000              add [bx+si],al
00009843  0000              add [bx+si],al
00009845  0000              add [bx+si],al
00009847  0000              add [bx+si],al
00009849  0000              add [bx+si],al
0000984B  0000              add [bx+si],al
0000984D  0000              add [bx+si],al
0000984F  0000              add [bx+si],al
00009851  0000              add [bx+si],al
00009853  0000              add [bx+si],al
00009855  0000              add [bx+si],al
00009857  0000              add [bx+si],al
00009859  0000              add [bx+si],al
0000985B  0000              add [bx+si],al
0000985D  0000              add [bx+si],al
0000985F  0000              add [bx+si],al
00009861  0000              add [bx+si],al
00009863  0000              add [bx+si],al
00009865  0000              add [bx+si],al
00009867  0000              add [bx+si],al
00009869  0000              add [bx+si],al
0000986B  0000              add [bx+si],al
0000986D  0000              add [bx+si],al
0000986F  0000              add [bx+si],al
00009871  0000              add [bx+si],al
00009873  0000              add [bx+si],al
00009875  0000              add [bx+si],al
00009877  0000              add [bx+si],al
00009879  0000              add [bx+si],al
0000987B  0000              add [bx+si],al
0000987D  0000              add [bx+si],al
0000987F  0000              add [bx+si],al
00009881  0000              add [bx+si],al
00009883  0000              add [bx+si],al
00009885  0000              add [bx+si],al
00009887  0000              add [bx+si],al
00009889  0000              add [bx+si],al
0000988B  0000              add [bx+si],al
0000988D  0000              add [bx+si],al
0000988F  0000              add [bx+si],al
00009891  0000              add [bx+si],al
00009893  0000              add [bx+si],al
00009895  0000              add [bx+si],al
00009897  0000              add [bx+si],al
00009899  0000              add [bx+si],al
0000989B  0000              add [bx+si],al
0000989D  0000              add [bx+si],al
0000989F  0000              add [bx+si],al
000098A1  0000              add [bx+si],al
000098A3  0000              add [bx+si],al
000098A5  0000              add [bx+si],al
000098A7  0000              add [bx+si],al
000098A9  0000              add [bx+si],al
000098AB  0000              add [bx+si],al
000098AD  0000              add [bx+si],al
000098AF  0000              add [bx+si],al
000098B1  0000              add [bx+si],al
000098B3  0000              add [bx+si],al
000098B5  0000              add [bx+si],al
000098B7  0000              add [bx+si],al
000098B9  0000              add [bx+si],al
000098BB  0000              add [bx+si],al
000098BD  0000              add [bx+si],al
000098BF  0000              add [bx+si],al
000098C1  0000              add [bx+si],al
000098C3  0000              add [bx+si],al
000098C5  0000              add [bx+si],al
000098C7  0000              add [bx+si],al
000098C9  0000              add [bx+si],al
000098CB  0000              add [bx+si],al
000098CD  0000              add [bx+si],al
000098CF  0000              add [bx+si],al
000098D1  0000              add [bx+si],al
000098D3  0000              add [bx+si],al
000098D5  0000              add [bx+si],al
000098D7  0000              add [bx+si],al
000098D9  0000              add [bx+si],al
000098DB  0000              add [bx+si],al
000098DD  0000              add [bx+si],al
000098DF  0000              add [bx+si],al
000098E1  0000              add [bx+si],al
000098E3  0000              add [bx+si],al
000098E5  0000              add [bx+si],al
000098E7  0000              add [bx+si],al
000098E9  0000              add [bx+si],al
000098EB  0000              add [bx+si],al
000098ED  0000              add [bx+si],al
000098EF  0000              add [bx+si],al
000098F1  0000              add [bx+si],al
000098F3  0000              add [bx+si],al
000098F5  0000              add [bx+si],al
000098F7  0000              add [bx+si],al
000098F9  0000              add [bx+si],al
000098FB  0000              add [bx+si],al
000098FD  0000              add [bx+si],al
000098FF  0000              add [bx+si],al
00009901  0000              add [bx+si],al
00009903  0000              add [bx+si],al
00009905  0000              add [bx+si],al
00009907  0000              add [bx+si],al
00009909  0000              add [bx+si],al
0000990B  0000              add [bx+si],al
0000990D  0000              add [bx+si],al
0000990F  0000              add [bx+si],al
00009911  0000              add [bx+si],al
00009913  0000              add [bx+si],al
00009915  0000              add [bx+si],al
00009917  0000              add [bx+si],al
00009919  0000              add [bx+si],al
0000991B  0000              add [bx+si],al
0000991D  0000              add [bx+si],al
0000991F  0000              add [bx+si],al
00009921  0000              add [bx+si],al
00009923  0000              add [bx+si],al
00009925  0000              add [bx+si],al
00009927  0000              add [bx+si],al
00009929  0000              add [bx+si],al
0000992B  0000              add [bx+si],al
0000992D  0000              add [bx+si],al
0000992F  0000              add [bx+si],al
00009931  0000              add [bx+si],al
00009933  0000              add [bx+si],al
00009935  0000              add [bx+si],al
00009937  0000              add [bx+si],al
00009939  0000              add [bx+si],al
0000993B  0000              add [bx+si],al
0000993D  0000              add [bx+si],al
0000993F  0000              add [bx+si],al
00009941  0000              add [bx+si],al
00009943  0000              add [bx+si],al
00009945  0000              add [bx+si],al
00009947  0000              add [bx+si],al
00009949  0000              add [bx+si],al
0000994B  0000              add [bx+si],al
0000994D  0000              add [bx+si],al
0000994F  0000              add [bx+si],al
00009951  0000              add [bx+si],al
00009953  0000              add [bx+si],al
00009955  0000              add [bx+si],al
00009957  0000              add [bx+si],al
00009959  0000              add [bx+si],al
0000995B  0000              add [bx+si],al
0000995D  0000              add [bx+si],al
0000995F  0000              add [bx+si],al
00009961  0000              add [bx+si],al
00009963  0000              add [bx+si],al
00009965  0000              add [bx+si],al
00009967  0000              add [bx+si],al
00009969  0000              add [bx+si],al
0000996B  0000              add [bx+si],al
0000996D  0000              add [bx+si],al
0000996F  0000              add [bx+si],al
00009971  0000              add [bx+si],al
00009973  0000              add [bx+si],al
00009975  0000              add [bx+si],al
00009977  0000              add [bx+si],al
00009979  0000              add [bx+si],al
0000997B  0000              add [bx+si],al
0000997D  0000              add [bx+si],al
0000997F  0000              add [bx+si],al
00009981  0000              add [bx+si],al
00009983  0000              add [bx+si],al
00009985  0000              add [bx+si],al
00009987  0000              add [bx+si],al
00009989  0000              add [bx+si],al
0000998B  0000              add [bx+si],al
0000998D  0000              add [bx+si],al
0000998F  0000              add [bx+si],al
00009991  0000              add [bx+si],al
00009993  0000              add [bx+si],al
00009995  0000              add [bx+si],al
00009997  0000              add [bx+si],al
00009999  0000              add [bx+si],al
0000999B  0000              add [bx+si],al
0000999D  0000              add [bx+si],al
0000999F  0000              add [bx+si],al
000099A1  0000              add [bx+si],al
000099A3  0000              add [bx+si],al
000099A5  0000              add [bx+si],al
000099A7  0000              add [bx+si],al
000099A9  0000              add [bx+si],al
000099AB  0000              add [bx+si],al
000099AD  0000              add [bx+si],al
000099AF  0000              add [bx+si],al
000099B1  0000              add [bx+si],al
000099B3  0000              add [bx+si],al
000099B5  0000              add [bx+si],al
000099B7  0000              add [bx+si],al
000099B9  0000              add [bx+si],al
000099BB  0000              add [bx+si],al
000099BD  0000              add [bx+si],al
000099BF  0000              add [bx+si],al
000099C1  0000              add [bx+si],al
000099C3  0000              add [bx+si],al
000099C5  0000              add [bx+si],al
000099C7  0000              add [bx+si],al
000099C9  0000              add [bx+si],al
000099CB  0000              add [bx+si],al
000099CD  0000              add [bx+si],al
000099CF  0000              add [bx+si],al
000099D1  0000              add [bx+si],al
000099D3  0000              add [bx+si],al
000099D5  0000              add [bx+si],al
000099D7  0000              add [bx+si],al
000099D9  0000              add [bx+si],al
000099DB  0000              add [bx+si],al
000099DD  0000              add [bx+si],al
000099DF  0000              add [bx+si],al
000099E1  0000              add [bx+si],al
000099E3  0000              add [bx+si],al
000099E5  0000              add [bx+si],al
000099E7  0000              add [bx+si],al
000099E9  0000              add [bx+si],al
000099EB  0000              add [bx+si],al
000099ED  0000              add [bx+si],al
000099EF  0000              add [bx+si],al
000099F1  0000              add [bx+si],al
000099F3  0000              add [bx+si],al
000099F5  0000              add [bx+si],al
000099F7  0000              add [bx+si],al
000099F9  0000              add [bx+si],al
000099FB  0000              add [bx+si],al
000099FD  0000              add [bx+si],al
000099FF  0000              add [bx+si],al
00009A01  0000              add [bx+si],al
00009A03  0000              add [bx+si],al
00009A05  0000              add [bx+si],al
00009A07  0000              add [bx+si],al
00009A09  0000              add [bx+si],al
00009A0B  0000              add [bx+si],al
00009A0D  0000              add [bx+si],al
00009A0F  0000              add [bx+si],al
00009A11  0000              add [bx+si],al
00009A13  0000              add [bx+si],al
00009A15  0000              add [bx+si],al
00009A17  0000              add [bx+si],al
00009A19  0000              add [bx+si],al
00009A1B  0000              add [bx+si],al
00009A1D  0000              add [bx+si],al
00009A1F  0000              add [bx+si],al
00009A21  0000              add [bx+si],al
00009A23  0000              add [bx+si],al
00009A25  0000              add [bx+si],al
00009A27  0000              add [bx+si],al
00009A29  0000              add [bx+si],al
00009A2B  0000              add [bx+si],al
00009A2D  0000              add [bx+si],al
00009A2F  0000              add [bx+si],al
00009A31  0000              add [bx+si],al
00009A33  0000              add [bx+si],al
00009A35  0000              add [bx+si],al
00009A37  0000              add [bx+si],al
00009A39  0000              add [bx+si],al
00009A3B  0000              add [bx+si],al
00009A3D  0000              add [bx+si],al
00009A3F  0000              add [bx+si],al
00009A41  0000              add [bx+si],al
00009A43  0000              add [bx+si],al
00009A45  0000              add [bx+si],al
00009A47  0000              add [bx+si],al
00009A49  0000              add [bx+si],al
00009A4B  0000              add [bx+si],al
00009A4D  0000              add [bx+si],al
00009A4F  0000              add [bx+si],al
00009A51  0000              add [bx+si],al
00009A53  0000              add [bx+si],al
00009A55  0000              add [bx+si],al
00009A57  0000              add [bx+si],al
00009A59  0000              add [bx+si],al
00009A5B  0000              add [bx+si],al
00009A5D  0000              add [bx+si],al
00009A5F  0000              add [bx+si],al
00009A61  0000              add [bx+si],al
00009A63  0000              add [bx+si],al
00009A65  0000              add [bx+si],al
00009A67  0000              add [bx+si],al
00009A69  0000              add [bx+si],al
00009A6B  0000              add [bx+si],al
00009A6D  0000              add [bx+si],al
00009A6F  0000              add [bx+si],al
00009A71  0000              add [bx+si],al
00009A73  0000              add [bx+si],al
00009A75  0000              add [bx+si],al
00009A77  0000              add [bx+si],al
00009A79  0000              add [bx+si],al
00009A7B  0000              add [bx+si],al
00009A7D  0000              add [bx+si],al
00009A7F  0000              add [bx+si],al
00009A81  0000              add [bx+si],al
00009A83  0000              add [bx+si],al
00009A85  0000              add [bx+si],al
00009A87  0000              add [bx+si],al
00009A89  0000              add [bx+si],al
00009A8B  0000              add [bx+si],al
00009A8D  0000              add [bx+si],al
00009A8F  0000              add [bx+si],al
00009A91  0000              add [bx+si],al
00009A93  0000              add [bx+si],al
00009A95  0000              add [bx+si],al
00009A97  0000              add [bx+si],al
00009A99  0000              add [bx+si],al
00009A9B  0000              add [bx+si],al
00009A9D  0000              add [bx+si],al
00009A9F  0000              add [bx+si],al
00009AA1  0000              add [bx+si],al
00009AA3  0000              add [bx+si],al
00009AA5  0000              add [bx+si],al
00009AA7  0000              add [bx+si],al
00009AA9  0000              add [bx+si],al
00009AAB  0000              add [bx+si],al
00009AAD  0000              add [bx+si],al
00009AAF  0000              add [bx+si],al
00009AB1  0000              add [bx+si],al
00009AB3  0000              add [bx+si],al
00009AB5  0000              add [bx+si],al
00009AB7  0000              add [bx+si],al
00009AB9  0000              add [bx+si],al
00009ABB  0000              add [bx+si],al
00009ABD  0000              add [bx+si],al
00009ABF  0000              add [bx+si],al
00009AC1  0000              add [bx+si],al
00009AC3  0000              add [bx+si],al
00009AC5  0000              add [bx+si],al
00009AC7  0000              add [bx+si],al
00009AC9  0000              add [bx+si],al
00009ACB  0000              add [bx+si],al
00009ACD  0000              add [bx+si],al
00009ACF  0000              add [bx+si],al
00009AD1  0000              add [bx+si],al
00009AD3  0000              add [bx+si],al
00009AD5  0000              add [bx+si],al
00009AD7  0000              add [bx+si],al
00009AD9  0000              add [bx+si],al
00009ADB  0000              add [bx+si],al
00009ADD  0000              add [bx+si],al
00009ADF  0000              add [bx+si],al
00009AE1  0000              add [bx+si],al
00009AE3  0000              add [bx+si],al
00009AE5  0000              add [bx+si],al
00009AE7  0000              add [bx+si],al
00009AE9  0000              add [bx+si],al
00009AEB  0000              add [bx+si],al
00009AED  0000              add [bx+si],al
00009AEF  0000              add [bx+si],al
00009AF1  0000              add [bx+si],al
00009AF3  0000              add [bx+si],al
00009AF5  0000              add [bx+si],al
00009AF7  0000              add [bx+si],al
00009AF9  0000              add [bx+si],al
00009AFB  0000              add [bx+si],al
00009AFD  0000              add [bx+si],al
00009AFF  0000              add [bx+si],al
00009B01  0000              add [bx+si],al
00009B03  0000              add [bx+si],al
00009B05  0000              add [bx+si],al
00009B07  0000              add [bx+si],al
00009B09  0000              add [bx+si],al
00009B0B  0000              add [bx+si],al
00009B0D  0000              add [bx+si],al
00009B0F  0000              add [bx+si],al
00009B11  0000              add [bx+si],al
00009B13  0000              add [bx+si],al
00009B15  0000              add [bx+si],al
00009B17  0000              add [bx+si],al
00009B19  0000              add [bx+si],al
00009B1B  0000              add [bx+si],al
00009B1D  0000              add [bx+si],al
00009B1F  0000              add [bx+si],al
00009B21  0000              add [bx+si],al
00009B23  0000              add [bx+si],al
00009B25  0000              add [bx+si],al
00009B27  0000              add [bx+si],al
00009B29  0000              add [bx+si],al
00009B2B  0000              add [bx+si],al
00009B2D  0000              add [bx+si],al
00009B2F  0000              add [bx+si],al
00009B31  0000              add [bx+si],al
00009B33  0000              add [bx+si],al
00009B35  0000              add [bx+si],al
00009B37  0000              add [bx+si],al
00009B39  0000              add [bx+si],al
00009B3B  0000              add [bx+si],al
00009B3D  0000              add [bx+si],al
00009B3F  0000              add [bx+si],al
00009B41  0000              add [bx+si],al
00009B43  0000              add [bx+si],al
00009B45  0000              add [bx+si],al
00009B47  0000              add [bx+si],al
00009B49  0000              add [bx+si],al
00009B4B  0000              add [bx+si],al
00009B4D  0000              add [bx+si],al
00009B4F  0000              add [bx+si],al
00009B51  0000              add [bx+si],al
00009B53  0000              add [bx+si],al
00009B55  0000              add [bx+si],al
00009B57  0000              add [bx+si],al
00009B59  0000              add [bx+si],al
00009B5B  0000              add [bx+si],al
00009B5D  0000              add [bx+si],al
00009B5F  0000              add [bx+si],al
00009B61  0000              add [bx+si],al
00009B63  0000              add [bx+si],al
00009B65  0000              add [bx+si],al
00009B67  0000              add [bx+si],al
00009B69  0000              add [bx+si],al
00009B6B  0000              add [bx+si],al
00009B6D  0000              add [bx+si],al
00009B6F  0000              add [bx+si],al
00009B71  0000              add [bx+si],al
00009B73  0000              add [bx+si],al
00009B75  0000              add [bx+si],al
00009B77  0000              add [bx+si],al
00009B79  0000              add [bx+si],al
00009B7B  0000              add [bx+si],al
00009B7D  0000              add [bx+si],al
00009B7F  0000              add [bx+si],al
00009B81  0000              add [bx+si],al
00009B83  0000              add [bx+si],al
00009B85  0000              add [bx+si],al
00009B87  0000              add [bx+si],al
00009B89  0000              add [bx+si],al
00009B8B  0000              add [bx+si],al
00009B8D  0000              add [bx+si],al
00009B8F  0000              add [bx+si],al
00009B91  0000              add [bx+si],al
00009B93  0000              add [bx+si],al
00009B95  0000              add [bx+si],al
00009B97  0000              add [bx+si],al
00009B99  0000              add [bx+si],al
00009B9B  0000              add [bx+si],al
00009B9D  0000              add [bx+si],al
00009B9F  0000              add [bx+si],al
00009BA1  0000              add [bx+si],al
00009BA3  0000              add [bx+si],al
00009BA5  0000              add [bx+si],al
00009BA7  0000              add [bx+si],al
00009BA9  0000              add [bx+si],al
00009BAB  0000              add [bx+si],al
00009BAD  0000              add [bx+si],al
00009BAF  0000              add [bx+si],al
00009BB1  0000              add [bx+si],al
00009BB3  0000              add [bx+si],al
00009BB5  0000              add [bx+si],al
00009BB7  0000              add [bx+si],al
00009BB9  0000              add [bx+si],al
00009BBB  0000              add [bx+si],al
00009BBD  0000              add [bx+si],al
00009BBF  0000              add [bx+si],al
00009BC1  0000              add [bx+si],al
00009BC3  0000              add [bx+si],al
00009BC5  0000              add [bx+si],al
00009BC7  0000              add [bx+si],al
00009BC9  0000              add [bx+si],al
00009BCB  0000              add [bx+si],al
00009BCD  0000              add [bx+si],al
00009BCF  0000              add [bx+si],al
00009BD1  0000              add [bx+si],al
00009BD3  0000              add [bx+si],al
00009BD5  0000              add [bx+si],al
00009BD7  0000              add [bx+si],al
00009BD9  0000              add [bx+si],al
00009BDB  0000              add [bx+si],al
00009BDD  0000              add [bx+si],al
00009BDF  0000              add [bx+si],al
00009BE1  0000              add [bx+si],al
00009BE3  0000              add [bx+si],al
00009BE5  0000              add [bx+si],al
00009BE7  0000              add [bx+si],al
00009BE9  0000              add [bx+si],al
00009BEB  0000              add [bx+si],al
00009BED  0000              add [bx+si],al
00009BEF  0000              add [bx+si],al
00009BF1  0000              add [bx+si],al
00009BF3  0000              add [bx+si],al
00009BF5  0000              add [bx+si],al
00009BF7  0000              add [bx+si],al
00009BF9  0000              add [bx+si],al
00009BFB  0000              add [bx+si],al
00009BFD  0000              add [bx+si],al
00009BFF  0000              add [bx+si],al
00009C01  0000              add [bx+si],al
00009C03  0000              add [bx+si],al
00009C05  0000              add [bx+si],al
00009C07  0000              add [bx+si],al
00009C09  0000              add [bx+si],al
00009C0B  0000              add [bx+si],al
00009C0D  0000              add [bx+si],al
00009C0F  0000              add [bx+si],al
00009C11  0000              add [bx+si],al
00009C13  0000              add [bx+si],al
00009C15  0000              add [bx+si],al
00009C17  0000              add [bx+si],al
00009C19  0000              add [bx+si],al
00009C1B  0000              add [bx+si],al
00009C1D  0000              add [bx+si],al
00009C1F  0000              add [bx+si],al
00009C21  0000              add [bx+si],al
00009C23  0000              add [bx+si],al
00009C25  0000              add [bx+si],al
00009C27  0000              add [bx+si],al
00009C29  0000              add [bx+si],al
00009C2B  0000              add [bx+si],al
00009C2D  0000              add [bx+si],al
00009C2F  0000              add [bx+si],al
00009C31  0000              add [bx+si],al
00009C33  0000              add [bx+si],al
00009C35  0000              add [bx+si],al
00009C37  0000              add [bx+si],al
00009C39  0000              add [bx+si],al
00009C3B  0000              add [bx+si],al
00009C3D  0000              add [bx+si],al
00009C3F  0000              add [bx+si],al
00009C41  0000              add [bx+si],al
00009C43  0000              add [bx+si],al
00009C45  0000              add [bx+si],al
00009C47  0000              add [bx+si],al
00009C49  0000              add [bx+si],al
00009C4B  0000              add [bx+si],al
00009C4D  0000              add [bx+si],al
00009C4F  0000              add [bx+si],al
00009C51  0000              add [bx+si],al
00009C53  0000              add [bx+si],al
00009C55  0000              add [bx+si],al
00009C57  0000              add [bx+si],al
00009C59  0000              add [bx+si],al
00009C5B  0000              add [bx+si],al
00009C5D  0000              add [bx+si],al
00009C5F  0000              add [bx+si],al
00009C61  0000              add [bx+si],al
00009C63  0000              add [bx+si],al
00009C65  0000              add [bx+si],al
00009C67  0000              add [bx+si],al
00009C69  0000              add [bx+si],al
00009C6B  0000              add [bx+si],al
00009C6D  0000              add [bx+si],al
00009C6F  0000              add [bx+si],al
00009C71  0000              add [bx+si],al
00009C73  0000              add [bx+si],al
00009C75  0000              add [bx+si],al
00009C77  0000              add [bx+si],al
00009C79  0000              add [bx+si],al
00009C7B  0000              add [bx+si],al
00009C7D  0000              add [bx+si],al
00009C7F  0000              add [bx+si],al
00009C81  0000              add [bx+si],al
00009C83  0000              add [bx+si],al
00009C85  0000              add [bx+si],al
00009C87  0000              add [bx+si],al
00009C89  0000              add [bx+si],al
00009C8B  0000              add [bx+si],al
00009C8D  0000              add [bx+si],al
00009C8F  0000              add [bx+si],al
00009C91  0000              add [bx+si],al
00009C93  0000              add [bx+si],al
00009C95  0000              add [bx+si],al
00009C97  0000              add [bx+si],al
00009C99  0000              add [bx+si],al
00009C9B  0000              add [bx+si],al
00009C9D  0000              add [bx+si],al
00009C9F  0000              add [bx+si],al
00009CA1  0000              add [bx+si],al
00009CA3  0000              add [bx+si],al
00009CA5  0000              add [bx+si],al
00009CA7  0000              add [bx+si],al
00009CA9  0000              add [bx+si],al
00009CAB  0000              add [bx+si],al
00009CAD  0000              add [bx+si],al
00009CAF  0000              add [bx+si],al
00009CB1  0000              add [bx+si],al
00009CB3  0000              add [bx+si],al
00009CB5  0000              add [bx+si],al
00009CB7  0000              add [bx+si],al
00009CB9  0000              add [bx+si],al
00009CBB  0000              add [bx+si],al
00009CBD  0000              add [bx+si],al
00009CBF  0000              add [bx+si],al
00009CC1  0000              add [bx+si],al
00009CC3  0000              add [bx+si],al
00009CC5  0000              add [bx+si],al
00009CC7  0000              add [bx+si],al
00009CC9  0000              add [bx+si],al
00009CCB  0000              add [bx+si],al
00009CCD  0000              add [bx+si],al
00009CCF  0000              add [bx+si],al
00009CD1  0000              add [bx+si],al
00009CD3  0000              add [bx+si],al
00009CD5  0000              add [bx+si],al
00009CD7  0000              add [bx+si],al
00009CD9  0000              add [bx+si],al
00009CDB  0000              add [bx+si],al
00009CDD  0000              add [bx+si],al
00009CDF  0000              add [bx+si],al
00009CE1  0000              add [bx+si],al
00009CE3  0000              add [bx+si],al
00009CE5  0000              add [bx+si],al
00009CE7  0000              add [bx+si],al
00009CE9  0000              add [bx+si],al
00009CEB  0000              add [bx+si],al
00009CED  0000              add [bx+si],al
00009CEF  0000              add [bx+si],al
00009CF1  0000              add [bx+si],al
00009CF3  0000              add [bx+si],al
00009CF5  0000              add [bx+si],al
00009CF7  0000              add [bx+si],al
00009CF9  0000              add [bx+si],al
00009CFB  0000              add [bx+si],al
00009CFD  0000              add [bx+si],al
00009CFF  0000              add [bx+si],al
00009D01  0000              add [bx+si],al
00009D03  0000              add [bx+si],al
00009D05  0000              add [bx+si],al
00009D07  0000              add [bx+si],al
00009D09  0000              add [bx+si],al
00009D0B  0000              add [bx+si],al
00009D0D  0000              add [bx+si],al
00009D0F  0000              add [bx+si],al
00009D11  0000              add [bx+si],al
00009D13  0000              add [bx+si],al
00009D15  0000              add [bx+si],al
00009D17  0000              add [bx+si],al
00009D19  0000              add [bx+si],al
00009D1B  0000              add [bx+si],al
00009D1D  0000              add [bx+si],al
00009D1F  0000              add [bx+si],al
00009D21  0000              add [bx+si],al
00009D23  0000              add [bx+si],al
00009D25  0000              add [bx+si],al
00009D27  0000              add [bx+si],al
00009D29  0000              add [bx+si],al
00009D2B  0000              add [bx+si],al
00009D2D  0000              add [bx+si],al
00009D2F  0000              add [bx+si],al
00009D31  0000              add [bx+si],al
00009D33  0000              add [bx+si],al
00009D35  0000              add [bx+si],al
00009D37  0000              add [bx+si],al
00009D39  0000              add [bx+si],al
00009D3B  0000              add [bx+si],al
00009D3D  0000              add [bx+si],al
00009D3F  0000              add [bx+si],al
00009D41  0000              add [bx+si],al
00009D43  0000              add [bx+si],al
00009D45  0000              add [bx+si],al
00009D47  0000              add [bx+si],al
00009D49  0000              add [bx+si],al
00009D4B  0000              add [bx+si],al
00009D4D  0000              add [bx+si],al
00009D4F  0000              add [bx+si],al
00009D51  0000              add [bx+si],al
00009D53  0000              add [bx+si],al
00009D55  0000              add [bx+si],al
00009D57  0000              add [bx+si],al
00009D59  0000              add [bx+si],al
00009D5B  0000              add [bx+si],al
00009D5D  0000              add [bx+si],al
00009D5F  0000              add [bx+si],al
00009D61  0000              add [bx+si],al
00009D63  0000              add [bx+si],al
00009D65  0000              add [bx+si],al
00009D67  0000              add [bx+si],al
00009D69  0000              add [bx+si],al
00009D6B  0000              add [bx+si],al
00009D6D  0000              add [bx+si],al
00009D6F  0000              add [bx+si],al
00009D71  0000              add [bx+si],al
00009D73  0000              add [bx+si],al
00009D75  0000              add [bx+si],al
00009D77  0000              add [bx+si],al
00009D79  0000              add [bx+si],al
00009D7B  0000              add [bx+si],al
00009D7D  0000              add [bx+si],al
00009D7F  0000              add [bx+si],al
00009D81  0000              add [bx+si],al
00009D83  0000              add [bx+si],al
00009D85  0000              add [bx+si],al
00009D87  0000              add [bx+si],al
00009D89  0000              add [bx+si],al
00009D8B  0000              add [bx+si],al
00009D8D  0000              add [bx+si],al
00009D8F  0000              add [bx+si],al
00009D91  0000              add [bx+si],al
00009D93  0000              add [bx+si],al
00009D95  0000              add [bx+si],al
00009D97  0000              add [bx+si],al
00009D99  0000              add [bx+si],al
00009D9B  0000              add [bx+si],al
00009D9D  0000              add [bx+si],al
00009D9F  0000              add [bx+si],al
00009DA1  0000              add [bx+si],al
00009DA3  0000              add [bx+si],al
00009DA5  0000              add [bx+si],al
00009DA7  0000              add [bx+si],al
00009DA9  0000              add [bx+si],al
00009DAB  0000              add [bx+si],al
00009DAD  0000              add [bx+si],al
00009DAF  0000              add [bx+si],al
00009DB1  0000              add [bx+si],al
00009DB3  0000              add [bx+si],al
00009DB5  0000              add [bx+si],al
00009DB7  0000              add [bx+si],al
00009DB9  0000              add [bx+si],al
00009DBB  0000              add [bx+si],al
00009DBD  0000              add [bx+si],al
00009DBF  0000              add [bx+si],al
00009DC1  0000              add [bx+si],al
00009DC3  0000              add [bx+si],al
00009DC5  0000              add [bx+si],al
00009DC7  0000              add [bx+si],al
00009DC9  0000              add [bx+si],al
00009DCB  0000              add [bx+si],al
00009DCD  0000              add [bx+si],al
00009DCF  0000              add [bx+si],al
00009DD1  0000              add [bx+si],al
00009DD3  0000              add [bx+si],al
00009DD5  0000              add [bx+si],al
00009DD7  0000              add [bx+si],al
00009DD9  0000              add [bx+si],al
00009DDB  0000              add [bx+si],al
00009DDD  0000              add [bx+si],al
00009DDF  0000              add [bx+si],al
00009DE1  0000              add [bx+si],al
00009DE3  0000              add [bx+si],al
00009DE5  0000              add [bx+si],al
00009DE7  0000              add [bx+si],al
00009DE9  0000              add [bx+si],al
00009DEB  0000              add [bx+si],al
00009DED  0000              add [bx+si],al
00009DEF  0000              add [bx+si],al
00009DF1  0000              add [bx+si],al
00009DF3  0000              add [bx+si],al
00009DF5  0000              add [bx+si],al
00009DF7  0000              add [bx+si],al
00009DF9  0000              add [bx+si],al
00009DFB  0000              add [bx+si],al
00009DFD  0000              add [bx+si],al
00009DFF  0000              add [bx+si],al
00009E01  0000              add [bx+si],al
00009E03  0000              add [bx+si],al
00009E05  0000              add [bx+si],al
00009E07  0000              add [bx+si],al
00009E09  0000              add [bx+si],al
00009E0B  0000              add [bx+si],al
00009E0D  0000              add [bx+si],al
00009E0F  0000              add [bx+si],al
00009E11  0000              add [bx+si],al
00009E13  0000              add [bx+si],al
00009E15  0000              add [bx+si],al
00009E17  0000              add [bx+si],al
00009E19  0000              add [bx+si],al
00009E1B  0000              add [bx+si],al
00009E1D  0000              add [bx+si],al
00009E1F  0000              add [bx+si],al
00009E21  0000              add [bx+si],al
00009E23  0000              add [bx+si],al
00009E25  0000              add [bx+si],al
00009E27  0000              add [bx+si],al
00009E29  0000              add [bx+si],al
00009E2B  0000              add [bx+si],al
00009E2D  0000              add [bx+si],al
00009E2F  0000              add [bx+si],al
00009E31  0000              add [bx+si],al
00009E33  0000              add [bx+si],al
00009E35  0000              add [bx+si],al
00009E37  0000              add [bx+si],al
00009E39  0000              add [bx+si],al
00009E3B  0000              add [bx+si],al
00009E3D  0000              add [bx+si],al
00009E3F  0000              add [bx+si],al
00009E41  0000              add [bx+si],al
00009E43  0000              add [bx+si],al
00009E45  0000              add [bx+si],al
00009E47  0000              add [bx+si],al
00009E49  0000              add [bx+si],al
00009E4B  0000              add [bx+si],al
00009E4D  0000              add [bx+si],al
00009E4F  0000              add [bx+si],al
00009E51  0000              add [bx+si],al
00009E53  0000              add [bx+si],al
00009E55  0000              add [bx+si],al
00009E57  0000              add [bx+si],al
00009E59  0000              add [bx+si],al
00009E5B  0000              add [bx+si],al
00009E5D  0000              add [bx+si],al
00009E5F  0000              add [bx+si],al
00009E61  0000              add [bx+si],al
00009E63  0000              add [bx+si],al
00009E65  0000              add [bx+si],al
00009E67  0000              add [bx+si],al
00009E69  0000              add [bx+si],al
00009E6B  0000              add [bx+si],al
00009E6D  0000              add [bx+si],al
00009E6F  0000              add [bx+si],al
00009E71  0000              add [bx+si],al
00009E73  0000              add [bx+si],al
00009E75  0000              add [bx+si],al
00009E77  0000              add [bx+si],al
00009E79  0000              add [bx+si],al
00009E7B  0000              add [bx+si],al
00009E7D  0000              add [bx+si],al
00009E7F  0000              add [bx+si],al
00009E81  0000              add [bx+si],al
00009E83  0000              add [bx+si],al
00009E85  0000              add [bx+si],al
00009E87  0000              add [bx+si],al
00009E89  0000              add [bx+si],al
00009E8B  0000              add [bx+si],al
00009E8D  0000              add [bx+si],al
00009E8F  0000              add [bx+si],al
00009E91  0000              add [bx+si],al
00009E93  0000              add [bx+si],al
00009E95  0000              add [bx+si],al
00009E97  0000              add [bx+si],al
00009E99  0000              add [bx+si],al
00009E9B  0000              add [bx+si],al
00009E9D  0000              add [bx+si],al
00009E9F  0000              add [bx+si],al
00009EA1  0000              add [bx+si],al
00009EA3  0000              add [bx+si],al
00009EA5  0000              add [bx+si],al
00009EA7  0000              add [bx+si],al
00009EA9  0000              add [bx+si],al
00009EAB  0000              add [bx+si],al
00009EAD  0000              add [bx+si],al
00009EAF  0000              add [bx+si],al
00009EB1  0000              add [bx+si],al
00009EB3  0000              add [bx+si],al
00009EB5  0000              add [bx+si],al
00009EB7  0000              add [bx+si],al
00009EB9  0000              add [bx+si],al
00009EBB  0000              add [bx+si],al
00009EBD  0000              add [bx+si],al
00009EBF  0000              add [bx+si],al
00009EC1  0000              add [bx+si],al
00009EC3  0000              add [bx+si],al
00009EC5  0000              add [bx+si],al
00009EC7  0000              add [bx+si],al
00009EC9  0000              add [bx+si],al
00009ECB  0000              add [bx+si],al
00009ECD  0000              add [bx+si],al
00009ECF  0000              add [bx+si],al
00009ED1  0000              add [bx+si],al
00009ED3  0000              add [bx+si],al
00009ED5  0000              add [bx+si],al
00009ED7  0000              add [bx+si],al
00009ED9  0000              add [bx+si],al
00009EDB  0000              add [bx+si],al
00009EDD  0000              add [bx+si],al
00009EDF  0000              add [bx+si],al
00009EE1  0000              add [bx+si],al
00009EE3  0000              add [bx+si],al
00009EE5  0000              add [bx+si],al
00009EE7  0000              add [bx+si],al
00009EE9  0000              add [bx+si],al
00009EEB  0000              add [bx+si],al
00009EED  0000              add [bx+si],al
00009EEF  0000              add [bx+si],al
00009EF1  0000              add [bx+si],al
00009EF3  0000              add [bx+si],al
00009EF5  0000              add [bx+si],al
00009EF7  0000              add [bx+si],al
00009EF9  0000              add [bx+si],al
00009EFB  0000              add [bx+si],al
00009EFD  0000              add [bx+si],al
00009EFF  0000              add [bx+si],al
00009F01  0000              add [bx+si],al
00009F03  0000              add [bx+si],al
00009F05  0000              add [bx+si],al
00009F07  0000              add [bx+si],al
00009F09  0000              add [bx+si],al
00009F0B  0000              add [bx+si],al
00009F0D  0000              add [bx+si],al
00009F0F  0000              add [bx+si],al
00009F11  0000              add [bx+si],al
00009F13  0000              add [bx+si],al
00009F15  0000              add [bx+si],al
00009F17  0000              add [bx+si],al
00009F19  0000              add [bx+si],al
00009F1B  0000              add [bx+si],al
00009F1D  0000              add [bx+si],al
00009F1F  0000              add [bx+si],al
00009F21  0000              add [bx+si],al
00009F23  0000              add [bx+si],al
00009F25  0000              add [bx+si],al
00009F27  0000              add [bx+si],al
00009F29  0000              add [bx+si],al
00009F2B  0000              add [bx+si],al
00009F2D  0000              add [bx+si],al
00009F2F  0000              add [bx+si],al
00009F31  0000              add [bx+si],al
00009F33  0000              add [bx+si],al
00009F35  0000              add [bx+si],al
00009F37  0000              add [bx+si],al
00009F39  0000              add [bx+si],al
00009F3B  0000              add [bx+si],al
00009F3D  0000              add [bx+si],al
00009F3F  0000              add [bx+si],al
00009F41  0000              add [bx+si],al
00009F43  0000              add [bx+si],al
00009F45  0000              add [bx+si],al
00009F47  0000              add [bx+si],al
00009F49  0000              add [bx+si],al
00009F4B  0000              add [bx+si],al
00009F4D  0000              add [bx+si],al
00009F4F  0000              add [bx+si],al
00009F51  0000              add [bx+si],al
00009F53  0000              add [bx+si],al
00009F55  0000              add [bx+si],al
00009F57  0000              add [bx+si],al
00009F59  0000              add [bx+si],al
00009F5B  0000              add [bx+si],al
00009F5D  0000              add [bx+si],al
00009F5F  0000              add [bx+si],al
00009F61  0000              add [bx+si],al
00009F63  0000              add [bx+si],al
00009F65  0000              add [bx+si],al
00009F67  0000              add [bx+si],al
00009F69  0000              add [bx+si],al
00009F6B  0000              add [bx+si],al
00009F6D  0000              add [bx+si],al
00009F6F  0000              add [bx+si],al
00009F71  0000              add [bx+si],al
00009F73  0000              add [bx+si],al
00009F75  0000              add [bx+si],al
00009F77  0000              add [bx+si],al
00009F79  0000              add [bx+si],al
00009F7B  0000              add [bx+si],al
00009F7D  0000              add [bx+si],al
00009F7F  0000              add [bx+si],al
00009F81  0000              add [bx+si],al
00009F83  0000              add [bx+si],al
00009F85  0000              add [bx+si],al
00009F87  0000              add [bx+si],al
00009F89  0000              add [bx+si],al
00009F8B  0000              add [bx+si],al
00009F8D  0000              add [bx+si],al
00009F8F  0000              add [bx+si],al
00009F91  0000              add [bx+si],al
00009F93  0000              add [bx+si],al
00009F95  0000              add [bx+si],al
00009F97  0000              add [bx+si],al
00009F99  0000              add [bx+si],al
00009F9B  0000              add [bx+si],al
00009F9D  0000              add [bx+si],al
00009F9F  0000              add [bx+si],al
00009FA1  0000              add [bx+si],al
00009FA3  0000              add [bx+si],al
00009FA5  0000              add [bx+si],al
00009FA7  0000              add [bx+si],al
00009FA9  0000              add [bx+si],al
00009FAB  0000              add [bx+si],al
00009FAD  0000              add [bx+si],al
00009FAF  0000              add [bx+si],al
00009FB1  0000              add [bx+si],al
00009FB3  0000              add [bx+si],al
00009FB5  0000              add [bx+si],al
00009FB7  0000              add [bx+si],al
00009FB9  0000              add [bx+si],al
00009FBB  0000              add [bx+si],al
00009FBD  0000              add [bx+si],al
00009FBF  0000              add [bx+si],al
00009FC1  0000              add [bx+si],al
00009FC3  0000              add [bx+si],al
00009FC5  0000              add [bx+si],al
00009FC7  0000              add [bx+si],al
00009FC9  0000              add [bx+si],al
00009FCB  0000              add [bx+si],al
00009FCD  0000              add [bx+si],al
00009FCF  0000              add [bx+si],al
00009FD1  0000              add [bx+si],al
00009FD3  0000              add [bx+si],al
00009FD5  0000              add [bx+si],al
00009FD7  0000              add [bx+si],al
00009FD9  0000              add [bx+si],al
00009FDB  0000              add [bx+si],al
00009FDD  0000              add [bx+si],al
00009FDF  0000              add [bx+si],al
00009FE1  0000              add [bx+si],al
00009FE3  0000              add [bx+si],al
00009FE5  0000              add [bx+si],al
00009FE7  0000              add [bx+si],al
00009FE9  0000              add [bx+si],al
00009FEB  0000              add [bx+si],al
00009FED  0000              add [bx+si],al
00009FEF  0000              add [bx+si],al
00009FF1  0000              add [bx+si],al
00009FF3  0000              add [bx+si],al
00009FF5  0000              add [bx+si],al
00009FF7  0000              add [bx+si],al
00009FF9  0000              add [bx+si],al
00009FFB  0000              add [bx+si],al
00009FFD  0000              add [bx+si],al
00009FFF  0000              add [bx+si],al
0000A001  0000              add [bx+si],al
0000A003  0000              add [bx+si],al
0000A005  0000              add [bx+si],al
0000A007  0000              add [bx+si],al
0000A009  0000              add [bx+si],al
0000A00B  0000              add [bx+si],al
0000A00D  0000              add [bx+si],al
0000A00F  0000              add [bx+si],al
0000A011  0000              add [bx+si],al
0000A013  0000              add [bx+si],al
0000A015  0000              add [bx+si],al
0000A017  0000              add [bx+si],al
0000A019  0000              add [bx+si],al
0000A01B  0000              add [bx+si],al
0000A01D  0000              add [bx+si],al
0000A01F  0000              add [bx+si],al
0000A021  0000              add [bx+si],al
0000A023  0000              add [bx+si],al
0000A025  0000              add [bx+si],al
0000A027  0000              add [bx+si],al
0000A029  0000              add [bx+si],al
0000A02B  0000              add [bx+si],al
0000A02D  0000              add [bx+si],al
0000A02F  0000              add [bx+si],al
0000A031  0000              add [bx+si],al
0000A033  0000              add [bx+si],al
0000A035  0000              add [bx+si],al
0000A037  0000              add [bx+si],al
0000A039  0000              add [bx+si],al
0000A03B  0000              add [bx+si],al
0000A03D  0000              add [bx+si],al
0000A03F  0000              add [bx+si],al
0000A041  0000              add [bx+si],al
0000A043  0000              add [bx+si],al
0000A045  0000              add [bx+si],al
0000A047  0000              add [bx+si],al
0000A049  0000              add [bx+si],al
0000A04B  0000              add [bx+si],al
0000A04D  0000              add [bx+si],al
0000A04F  0000              add [bx+si],al
0000A051  0000              add [bx+si],al
0000A053  0000              add [bx+si],al
0000A055  0000              add [bx+si],al
0000A057  0000              add [bx+si],al
0000A059  0000              add [bx+si],al
0000A05B  0000              add [bx+si],al
0000A05D  0000              add [bx+si],al
0000A05F  0000              add [bx+si],al
0000A061  0000              add [bx+si],al
0000A063  0000              add [bx+si],al
0000A065  0000              add [bx+si],al
0000A067  0000              add [bx+si],al
0000A069  0000              add [bx+si],al
0000A06B  0000              add [bx+si],al
0000A06D  0000              add [bx+si],al
0000A06F  0000              add [bx+si],al
0000A071  0000              add [bx+si],al
0000A073  0000              add [bx+si],al
0000A075  0000              add [bx+si],al
0000A077  0000              add [bx+si],al
0000A079  0000              add [bx+si],al
0000A07B  0000              add [bx+si],al
0000A07D  0000              add [bx+si],al
0000A07F  0000              add [bx+si],al
0000A081  0000              add [bx+si],al
0000A083  0000              add [bx+si],al
0000A085  0000              add [bx+si],al
0000A087  0000              add [bx+si],al
0000A089  0000              add [bx+si],al
0000A08B  0000              add [bx+si],al
0000A08D  0000              add [bx+si],al
0000A08F  0000              add [bx+si],al
0000A091  0000              add [bx+si],al
0000A093  0000              add [bx+si],al
0000A095  0000              add [bx+si],al
0000A097  0000              add [bx+si],al
0000A099  0000              add [bx+si],al
0000A09B  0000              add [bx+si],al
0000A09D  0000              add [bx+si],al
0000A09F  0000              add [bx+si],al
0000A0A1  0000              add [bx+si],al
0000A0A3  0000              add [bx+si],al
0000A0A5  0000              add [bx+si],al
0000A0A7  0000              add [bx+si],al
0000A0A9  0000              add [bx+si],al
0000A0AB  0000              add [bx+si],al
0000A0AD  0000              add [bx+si],al
0000A0AF  0000              add [bx+si],al
0000A0B1  0000              add [bx+si],al
0000A0B3  0000              add [bx+si],al
0000A0B5  0000              add [bx+si],al
0000A0B7  0000              add [bx+si],al
0000A0B9  0000              add [bx+si],al
0000A0BB  0000              add [bx+si],al
0000A0BD  0000              add [bx+si],al
0000A0BF  0000              add [bx+si],al
0000A0C1  0000              add [bx+si],al
0000A0C3  0000              add [bx+si],al
0000A0C5  0000              add [bx+si],al
0000A0C7  0000              add [bx+si],al
0000A0C9  0000              add [bx+si],al
0000A0CB  0000              add [bx+si],al
0000A0CD  0000              add [bx+si],al
0000A0CF  0000              add [bx+si],al
0000A0D1  0000              add [bx+si],al
0000A0D3  0000              add [bx+si],al
0000A0D5  0000              add [bx+si],al
0000A0D7  0000              add [bx+si],al
0000A0D9  0000              add [bx+si],al
0000A0DB  0000              add [bx+si],al
0000A0DD  0000              add [bx+si],al
0000A0DF  0000              add [bx+si],al
0000A0E1  0000              add [bx+si],al
0000A0E3  0000              add [bx+si],al
0000A0E5  0000              add [bx+si],al
0000A0E7  0000              add [bx+si],al
0000A0E9  0000              add [bx+si],al
0000A0EB  0000              add [bx+si],al
0000A0ED  0000              add [bx+si],al
0000A0EF  0000              add [bx+si],al
0000A0F1  0000              add [bx+si],al
0000A0F3  0000              add [bx+si],al
0000A0F5  0000              add [bx+si],al
0000A0F7  0000              add [bx+si],al
0000A0F9  0000              add [bx+si],al
0000A0FB  0000              add [bx+si],al
0000A0FD  0000              add [bx+si],al
0000A0FF  0000              add [bx+si],al
0000A101  0000              add [bx+si],al
0000A103  0000              add [bx+si],al
0000A105  0000              add [bx+si],al
0000A107  0000              add [bx+si],al
0000A109  0000              add [bx+si],al
0000A10B  0000              add [bx+si],al
0000A10D  0000              add [bx+si],al
0000A10F  0000              add [bx+si],al
0000A111  0000              add [bx+si],al
0000A113  0000              add [bx+si],al
0000A115  0000              add [bx+si],al
0000A117  0000              add [bx+si],al
0000A119  0000              add [bx+si],al
0000A11B  0000              add [bx+si],al
0000A11D  0000              add [bx+si],al
0000A11F  0000              add [bx+si],al
0000A121  0000              add [bx+si],al
0000A123  0000              add [bx+si],al
0000A125  0000              add [bx+si],al
0000A127  0000              add [bx+si],al
0000A129  0000              add [bx+si],al
0000A12B  0000              add [bx+si],al
0000A12D  0000              add [bx+si],al
0000A12F  0000              add [bx+si],al
0000A131  0000              add [bx+si],al
0000A133  0000              add [bx+si],al
0000A135  0000              add [bx+si],al
0000A137  0000              add [bx+si],al
0000A139  0000              add [bx+si],al
0000A13B  0000              add [bx+si],al
0000A13D  0000              add [bx+si],al
0000A13F  0000              add [bx+si],al
0000A141  0000              add [bx+si],al
0000A143  0000              add [bx+si],al
0000A145  0000              add [bx+si],al
0000A147  0000              add [bx+si],al
0000A149  0000              add [bx+si],al
0000A14B  0000              add [bx+si],al
0000A14D  0000              add [bx+si],al
0000A14F  0000              add [bx+si],al
0000A151  0000              add [bx+si],al
0000A153  0000              add [bx+si],al
0000A155  0000              add [bx+si],al
0000A157  0000              add [bx+si],al
0000A159  0000              add [bx+si],al
0000A15B  0000              add [bx+si],al
0000A15D  0000              add [bx+si],al
0000A15F  0000              add [bx+si],al
0000A161  0000              add [bx+si],al
0000A163  0000              add [bx+si],al
0000A165  0000              add [bx+si],al
0000A167  0000              add [bx+si],al
0000A169  0000              add [bx+si],al
0000A16B  0000              add [bx+si],al
0000A16D  0000              add [bx+si],al
0000A16F  0000              add [bx+si],al
0000A171  0000              add [bx+si],al
0000A173  0000              add [bx+si],al
0000A175  0000              add [bx+si],al
0000A177  0000              add [bx+si],al
0000A179  0000              add [bx+si],al
0000A17B  0000              add [bx+si],al
0000A17D  0000              add [bx+si],al
0000A17F  0000              add [bx+si],al
0000A181  0000              add [bx+si],al
0000A183  0000              add [bx+si],al
0000A185  0000              add [bx+si],al
0000A187  0000              add [bx+si],al
0000A189  0000              add [bx+si],al
0000A18B  0000              add [bx+si],al
0000A18D  0000              add [bx+si],al
0000A18F  0000              add [bx+si],al
0000A191  0000              add [bx+si],al
0000A193  0000              add [bx+si],al
0000A195  0000              add [bx+si],al
0000A197  0000              add [bx+si],al
0000A199  0000              add [bx+si],al
0000A19B  0000              add [bx+si],al
0000A19D  0000              add [bx+si],al
0000A19F  0000              add [bx+si],al
0000A1A1  0000              add [bx+si],al
0000A1A3  0000              add [bx+si],al
0000A1A5  0000              add [bx+si],al
0000A1A7  0000              add [bx+si],al
0000A1A9  0000              add [bx+si],al
0000A1AB  0000              add [bx+si],al
0000A1AD  0000              add [bx+si],al
0000A1AF  0000              add [bx+si],al
0000A1B1  0000              add [bx+si],al
0000A1B3  0000              add [bx+si],al
0000A1B5  0000              add [bx+si],al
0000A1B7  0000              add [bx+si],al
0000A1B9  0000              add [bx+si],al
0000A1BB  0000              add [bx+si],al
0000A1BD  0000              add [bx+si],al
0000A1BF  0000              add [bx+si],al
0000A1C1  0000              add [bx+si],al
0000A1C3  0000              add [bx+si],al
0000A1C5  0000              add [bx+si],al
0000A1C7  0000              add [bx+si],al
0000A1C9  0000              add [bx+si],al
0000A1CB  0000              add [bx+si],al
0000A1CD  0000              add [bx+si],al
0000A1CF  0000              add [bx+si],al
0000A1D1  0000              add [bx+si],al
0000A1D3  0000              add [bx+si],al
0000A1D5  0000              add [bx+si],al
0000A1D7  0000              add [bx+si],al
0000A1D9  0000              add [bx+si],al
0000A1DB  0000              add [bx+si],al
0000A1DD  0000              add [bx+si],al
0000A1DF  0000              add [bx+si],al
0000A1E1  0000              add [bx+si],al
0000A1E3  0000              add [bx+si],al
0000A1E5  0000              add [bx+si],al
0000A1E7  0000              add [bx+si],al
0000A1E9  0000              add [bx+si],al
0000A1EB  0000              add [bx+si],al
0000A1ED  0000              add [bx+si],al
0000A1EF  0000              add [bx+si],al
0000A1F1  0000              add [bx+si],al
0000A1F3  0000              add [bx+si],al
0000A1F5  0000              add [bx+si],al
0000A1F7  0000              add [bx+si],al
0000A1F9  0000              add [bx+si],al
0000A1FB  0000              add [bx+si],al
0000A1FD  0000              add [bx+si],al
0000A1FF  0000              add [bx+si],al
0000A201  0000              add [bx+si],al
0000A203  0000              add [bx+si],al
0000A205  0000              add [bx+si],al
0000A207  0000              add [bx+si],al
0000A209  0000              add [bx+si],al
0000A20B  0000              add [bx+si],al
0000A20D  0000              add [bx+si],al
0000A20F  0000              add [bx+si],al
0000A211  0000              add [bx+si],al
0000A213  0000              add [bx+si],al
0000A215  0000              add [bx+si],al
0000A217  0000              add [bx+si],al
0000A219  0000              add [bx+si],al
0000A21B  0000              add [bx+si],al
0000A21D  0000              add [bx+si],al
0000A21F  0000              add [bx+si],al
0000A221  0000              add [bx+si],al
0000A223  0000              add [bx+si],al
0000A225  0000              add [bx+si],al
0000A227  0000              add [bx+si],al
0000A229  0000              add [bx+si],al
0000A22B  0000              add [bx+si],al
0000A22D  0000              add [bx+si],al
0000A22F  0000              add [bx+si],al
0000A231  0000              add [bx+si],al
0000A233  0000              add [bx+si],al
0000A235  0000              add [bx+si],al
0000A237  0000              add [bx+si],al
0000A239  0000              add [bx+si],al
0000A23B  0000              add [bx+si],al
0000A23D  0000              add [bx+si],al
0000A23F  0000              add [bx+si],al
0000A241  0000              add [bx+si],al
0000A243  0000              add [bx+si],al
0000A245  0000              add [bx+si],al
0000A247  0000              add [bx+si],al
0000A249  0000              add [bx+si],al
0000A24B  0000              add [bx+si],al
0000A24D  0000              add [bx+si],al
0000A24F  0000              add [bx+si],al
0000A251  0000              add [bx+si],al
0000A253  0000              add [bx+si],al
0000A255  0000              add [bx+si],al
0000A257  0000              add [bx+si],al
0000A259  0000              add [bx+si],al
0000A25B  0000              add [bx+si],al
0000A25D  0000              add [bx+si],al
0000A25F  0000              add [bx+si],al
0000A261  0000              add [bx+si],al
0000A263  0000              add [bx+si],al
0000A265  0000              add [bx+si],al
0000A267  0000              add [bx+si],al
0000A269  0000              add [bx+si],al
0000A26B  0000              add [bx+si],al
0000A26D  0000              add [bx+si],al
0000A26F  0000              add [bx+si],al
0000A271  0000              add [bx+si],al
0000A273  0000              add [bx+si],al
0000A275  0000              add [bx+si],al
0000A277  0000              add [bx+si],al
0000A279  0000              add [bx+si],al
0000A27B  0000              add [bx+si],al
0000A27D  0000              add [bx+si],al
0000A27F  0000              add [bx+si],al
0000A281  0000              add [bx+si],al
0000A283  0000              add [bx+si],al
0000A285  0000              add [bx+si],al
0000A287  0000              add [bx+si],al
0000A289  0000              add [bx+si],al
0000A28B  0000              add [bx+si],al
0000A28D  0000              add [bx+si],al
0000A28F  0000              add [bx+si],al
0000A291  0000              add [bx+si],al
0000A293  0000              add [bx+si],al
0000A295  0000              add [bx+si],al
0000A297  0000              add [bx+si],al
0000A299  0000              add [bx+si],al
0000A29B  0000              add [bx+si],al
0000A29D  0000              add [bx+si],al
0000A29F  0000              add [bx+si],al
0000A2A1  0000              add [bx+si],al
0000A2A3  0000              add [bx+si],al
0000A2A5  0000              add [bx+si],al
0000A2A7  0000              add [bx+si],al
0000A2A9  0000              add [bx+si],al
0000A2AB  0000              add [bx+si],al
0000A2AD  0000              add [bx+si],al
0000A2AF  0000              add [bx+si],al
0000A2B1  0000              add [bx+si],al
0000A2B3  0000              add [bx+si],al
0000A2B5  0000              add [bx+si],al
0000A2B7  0000              add [bx+si],al
0000A2B9  0000              add [bx+si],al
0000A2BB  0000              add [bx+si],al
0000A2BD  0000              add [bx+si],al
0000A2BF  0000              add [bx+si],al
0000A2C1  0000              add [bx+si],al
0000A2C3  0000              add [bx+si],al
0000A2C5  0000              add [bx+si],al
0000A2C7  0000              add [bx+si],al
0000A2C9  0000              add [bx+si],al
0000A2CB  0000              add [bx+si],al
0000A2CD  0000              add [bx+si],al
0000A2CF  0000              add [bx+si],al
0000A2D1  0000              add [bx+si],al
0000A2D3  0000              add [bx+si],al
0000A2D5  0000              add [bx+si],al
0000A2D7  0000              add [bx+si],al
0000A2D9  0000              add [bx+si],al
0000A2DB  0000              add [bx+si],al
0000A2DD  0000              add [bx+si],al
0000A2DF  0000              add [bx+si],al
0000A2E1  0000              add [bx+si],al
0000A2E3  0000              add [bx+si],al
0000A2E5  0000              add [bx+si],al
0000A2E7  0000              add [bx+si],al
0000A2E9  0000              add [bx+si],al
0000A2EB  0000              add [bx+si],al
0000A2ED  0000              add [bx+si],al
0000A2EF  0000              add [bx+si],al
0000A2F1  0000              add [bx+si],al
0000A2F3  0000              add [bx+si],al
0000A2F5  0000              add [bx+si],al
0000A2F7  0000              add [bx+si],al
0000A2F9  0000              add [bx+si],al
0000A2FB  0000              add [bx+si],al
0000A2FD  0000              add [bx+si],al
0000A2FF  0000              add [bx+si],al
0000A301  0000              add [bx+si],al
0000A303  0000              add [bx+si],al
0000A305  0000              add [bx+si],al
0000A307  0000              add [bx+si],al
0000A309  0000              add [bx+si],al
0000A30B  0000              add [bx+si],al
0000A30D  0000              add [bx+si],al
0000A30F  0000              add [bx+si],al
0000A311  0000              add [bx+si],al
0000A313  0000              add [bx+si],al
0000A315  0000              add [bx+si],al
0000A317  0000              add [bx+si],al
0000A319  0000              add [bx+si],al
0000A31B  0000              add [bx+si],al
0000A31D  0000              add [bx+si],al
0000A31F  0000              add [bx+si],al
0000A321  0000              add [bx+si],al
0000A323  0000              add [bx+si],al
0000A325  0000              add [bx+si],al
0000A327  0000              add [bx+si],al
0000A329  0000              add [bx+si],al
0000A32B  0000              add [bx+si],al
0000A32D  0000              add [bx+si],al
0000A32F  0000              add [bx+si],al
0000A331  0000              add [bx+si],al
0000A333  0000              add [bx+si],al
0000A335  0000              add [bx+si],al
0000A337  0000              add [bx+si],al
0000A339  0000              add [bx+si],al
0000A33B  0000              add [bx+si],al
0000A33D  0000              add [bx+si],al
0000A33F  0000              add [bx+si],al
0000A341  0000              add [bx+si],al
0000A343  0000              add [bx+si],al
0000A345  0000              add [bx+si],al
0000A347  0000              add [bx+si],al
0000A349  0000              add [bx+si],al
0000A34B  0000              add [bx+si],al
0000A34D  0000              add [bx+si],al
0000A34F  0000              add [bx+si],al
0000A351  0000              add [bx+si],al
0000A353  0000              add [bx+si],al
0000A355  0000              add [bx+si],al
0000A357  0000              add [bx+si],al
0000A359  0000              add [bx+si],al
0000A35B  0000              add [bx+si],al
0000A35D  0000              add [bx+si],al
0000A35F  0000              add [bx+si],al
0000A361  0000              add [bx+si],al
0000A363  0000              add [bx+si],al
0000A365  0000              add [bx+si],al
0000A367  0000              add [bx+si],al
0000A369  0000              add [bx+si],al
0000A36B  0000              add [bx+si],al
0000A36D  0000              add [bx+si],al
0000A36F  0000              add [bx+si],al
0000A371  0000              add [bx+si],al
0000A373  0000              add [bx+si],al
0000A375  0000              add [bx+si],al
0000A377  0000              add [bx+si],al
0000A379  0000              add [bx+si],al
0000A37B  0000              add [bx+si],al
0000A37D  0000              add [bx+si],al
0000A37F  0000              add [bx+si],al
0000A381  0000              add [bx+si],al
0000A383  0000              add [bx+si],al
0000A385  0000              add [bx+si],al
0000A387  0000              add [bx+si],al
0000A389  0000              add [bx+si],al
0000A38B  0000              add [bx+si],al
0000A38D  0000              add [bx+si],al
0000A38F  0000              add [bx+si],al
0000A391  0000              add [bx+si],al
0000A393  0000              add [bx+si],al
0000A395  0000              add [bx+si],al
0000A397  0000              add [bx+si],al
0000A399  0000              add [bx+si],al
0000A39B  0000              add [bx+si],al
0000A39D  0000              add [bx+si],al
0000A39F  0000              add [bx+si],al
0000A3A1  0000              add [bx+si],al
0000A3A3  0000              add [bx+si],al
0000A3A5  0000              add [bx+si],al
0000A3A7  0000              add [bx+si],al
0000A3A9  0000              add [bx+si],al
0000A3AB  0000              add [bx+si],al
0000A3AD  0000              add [bx+si],al
0000A3AF  0000              add [bx+si],al
0000A3B1  0000              add [bx+si],al
0000A3B3  0000              add [bx+si],al
0000A3B5  0000              add [bx+si],al
0000A3B7  0000              add [bx+si],al
0000A3B9  0000              add [bx+si],al
0000A3BB  0000              add [bx+si],al
0000A3BD  0000              add [bx+si],al
0000A3BF  0000              add [bx+si],al
0000A3C1  0000              add [bx+si],al
0000A3C3  0000              add [bx+si],al
0000A3C5  0000              add [bx+si],al
0000A3C7  0000              add [bx+si],al
0000A3C9  0000              add [bx+si],al
0000A3CB  0000              add [bx+si],al
0000A3CD  0000              add [bx+si],al
0000A3CF  0000              add [bx+si],al
0000A3D1  0000              add [bx+si],al
0000A3D3  0000              add [bx+si],al
0000A3D5  0000              add [bx+si],al
0000A3D7  0000              add [bx+si],al
0000A3D9  0000              add [bx+si],al
0000A3DB  0000              add [bx+si],al
0000A3DD  0000              add [bx+si],al
0000A3DF  0000              add [bx+si],al
0000A3E1  0000              add [bx+si],al
0000A3E3  0000              add [bx+si],al
0000A3E5  0000              add [bx+si],al
0000A3E7  0000              add [bx+si],al
0000A3E9  0000              add [bx+si],al
0000A3EB  0000              add [bx+si],al
0000A3ED  0000              add [bx+si],al
0000A3EF  0000              add [bx+si],al
0000A3F1  0000              add [bx+si],al
0000A3F3  0000              add [bx+si],al
0000A3F5  0000              add [bx+si],al
0000A3F7  0000              add [bx+si],al
0000A3F9  0000              add [bx+si],al
0000A3FB  0000              add [bx+si],al
0000A3FD  0000              add [bx+si],al
0000A3FF  0000              add [bx+si],al
0000A401  0000              add [bx+si],al
0000A403  0000              add [bx+si],al
0000A405  0000              add [bx+si],al
0000A407  0000              add [bx+si],al
0000A409  0000              add [bx+si],al
0000A40B  0000              add [bx+si],al
0000A40D  0000              add [bx+si],al
0000A40F  0000              add [bx+si],al
0000A411  0000              add [bx+si],al
0000A413  0000              add [bx+si],al
0000A415  0000              add [bx+si],al
0000A417  0000              add [bx+si],al
0000A419  0000              add [bx+si],al
0000A41B  0000              add [bx+si],al
0000A41D  0000              add [bx+si],al
0000A41F  0000              add [bx+si],al
0000A421  0000              add [bx+si],al
0000A423  0000              add [bx+si],al
0000A425  0000              add [bx+si],al
0000A427  0000              add [bx+si],al
0000A429  0000              add [bx+si],al
0000A42B  0000              add [bx+si],al
0000A42D  0000              add [bx+si],al
0000A42F  0000              add [bx+si],al
0000A431  0000              add [bx+si],al
0000A433  0000              add [bx+si],al
0000A435  0000              add [bx+si],al
0000A437  0000              add [bx+si],al
0000A439  0000              add [bx+si],al
0000A43B  0000              add [bx+si],al
0000A43D  0000              add [bx+si],al
0000A43F  0000              add [bx+si],al
0000A441  0000              add [bx+si],al
0000A443  0000              add [bx+si],al
0000A445  0000              add [bx+si],al
0000A447  0000              add [bx+si],al
0000A449  0000              add [bx+si],al
0000A44B  0000              add [bx+si],al
0000A44D  0000              add [bx+si],al
0000A44F  0000              add [bx+si],al
0000A451  0000              add [bx+si],al
0000A453  0000              add [bx+si],al
0000A455  0000              add [bx+si],al
0000A457  0000              add [bx+si],al
0000A459  0000              add [bx+si],al
0000A45B  0000              add [bx+si],al
0000A45D  0000              add [bx+si],al
0000A45F  0000              add [bx+si],al
0000A461  0000              add [bx+si],al
0000A463  0000              add [bx+si],al
0000A465  0000              add [bx+si],al
0000A467  0000              add [bx+si],al
0000A469  0000              add [bx+si],al
0000A46B  0000              add [bx+si],al
0000A46D  0000              add [bx+si],al
0000A46F  0000              add [bx+si],al
0000A471  0000              add [bx+si],al
0000A473  0000              add [bx+si],al
0000A475  0000              add [bx+si],al
0000A477  0000              add [bx+si],al
0000A479  0000              add [bx+si],al
0000A47B  0000              add [bx+si],al
0000A47D  0000              add [bx+si],al
0000A47F  0000              add [bx+si],al
0000A481  0000              add [bx+si],al
0000A483  0000              add [bx+si],al
0000A485  0000              add [bx+si],al
0000A487  0000              add [bx+si],al
0000A489  0000              add [bx+si],al
0000A48B  0000              add [bx+si],al
0000A48D  0000              add [bx+si],al
0000A48F  0000              add [bx+si],al
0000A491  0000              add [bx+si],al
0000A493  0000              add [bx+si],al
0000A495  0000              add [bx+si],al
0000A497  0000              add [bx+si],al
0000A499  0000              add [bx+si],al
0000A49B  0000              add [bx+si],al
0000A49D  0000              add [bx+si],al
0000A49F  0000              add [bx+si],al
0000A4A1  0000              add [bx+si],al
0000A4A3  0000              add [bx+si],al
0000A4A5  0000              add [bx+si],al
0000A4A7  0000              add [bx+si],al
0000A4A9  0000              add [bx+si],al
0000A4AB  0000              add [bx+si],al
0000A4AD  0000              add [bx+si],al
0000A4AF  0000              add [bx+si],al
0000A4B1  0000              add [bx+si],al
0000A4B3  0000              add [bx+si],al
0000A4B5  0000              add [bx+si],al
0000A4B7  0000              add [bx+si],al
0000A4B9  0000              add [bx+si],al
0000A4BB  0000              add [bx+si],al
0000A4BD  0000              add [bx+si],al
0000A4BF  0000              add [bx+si],al
0000A4C1  0000              add [bx+si],al
0000A4C3  0000              add [bx+si],al
0000A4C5  0000              add [bx+si],al
0000A4C7  0000              add [bx+si],al
0000A4C9  0000              add [bx+si],al
0000A4CB  0000              add [bx+si],al
0000A4CD  0000              add [bx+si],al
0000A4CF  0000              add [bx+si],al
0000A4D1  0000              add [bx+si],al
0000A4D3  0000              add [bx+si],al
0000A4D5  0000              add [bx+si],al
0000A4D7  0000              add [bx+si],al
0000A4D9  0000              add [bx+si],al
0000A4DB  0000              add [bx+si],al
0000A4DD  0000              add [bx+si],al
0000A4DF  0000              add [bx+si],al
0000A4E1  0000              add [bx+si],al
0000A4E3  0000              add [bx+si],al
0000A4E5  0000              add [bx+si],al
0000A4E7  0000              add [bx+si],al
0000A4E9  0000              add [bx+si],al
0000A4EB  0000              add [bx+si],al
0000A4ED  0000              add [bx+si],al
0000A4EF  0000              add [bx+si],al
0000A4F1  0000              add [bx+si],al
0000A4F3  0000              add [bx+si],al
0000A4F5  0000              add [bx+si],al
0000A4F7  0000              add [bx+si],al
0000A4F9  0000              add [bx+si],al
0000A4FB  0000              add [bx+si],al
0000A4FD  0000              add [bx+si],al
0000A4FF  0000              add [bx+si],al
0000A501  0000              add [bx+si],al
0000A503  0000              add [bx+si],al
0000A505  0000              add [bx+si],al
0000A507  0000              add [bx+si],al
0000A509  0000              add [bx+si],al
0000A50B  0000              add [bx+si],al
0000A50D  0000              add [bx+si],al
0000A50F  0000              add [bx+si],al
0000A511  0000              add [bx+si],al
0000A513  0000              add [bx+si],al
0000A515  0000              add [bx+si],al
0000A517  0000              add [bx+si],al
0000A519  0000              add [bx+si],al
0000A51B  0000              add [bx+si],al
0000A51D  0000              add [bx+si],al
0000A51F  0000              add [bx+si],al
0000A521  0000              add [bx+si],al
0000A523  0000              add [bx+si],al
0000A525  0000              add [bx+si],al
0000A527  0000              add [bx+si],al
0000A529  0000              add [bx+si],al
0000A52B  0000              add [bx+si],al
0000A52D  0000              add [bx+si],al
0000A52F  0000              add [bx+si],al
0000A531  0000              add [bx+si],al
0000A533  0000              add [bx+si],al
0000A535  0000              add [bx+si],al
0000A537  0000              add [bx+si],al
0000A539  0000              add [bx+si],al
0000A53B  0000              add [bx+si],al
0000A53D  0000              add [bx+si],al
0000A53F  0000              add [bx+si],al
0000A541  0000              add [bx+si],al
0000A543  0000              add [bx+si],al
0000A545  0000              add [bx+si],al
0000A547  0000              add [bx+si],al
0000A549  0000              add [bx+si],al
0000A54B  0000              add [bx+si],al
0000A54D  0000              add [bx+si],al
0000A54F  0000              add [bx+si],al
0000A551  0000              add [bx+si],al
0000A553  0000              add [bx+si],al
0000A555  0000              add [bx+si],al
0000A557  0000              add [bx+si],al
0000A559  0000              add [bx+si],al
0000A55B  0000              add [bx+si],al
0000A55D  0000              add [bx+si],al
0000A55F  0000              add [bx+si],al
0000A561  0000              add [bx+si],al
0000A563  0000              add [bx+si],al
0000A565  0000              add [bx+si],al
0000A567  0000              add [bx+si],al
0000A569  0000              add [bx+si],al
0000A56B  0000              add [bx+si],al
0000A56D  0000              add [bx+si],al
0000A56F  0000              add [bx+si],al
0000A571  0000              add [bx+si],al
0000A573  0000              add [bx+si],al
0000A575  0000              add [bx+si],al
0000A577  0000              add [bx+si],al
0000A579  0000              add [bx+si],al
0000A57B  0000              add [bx+si],al
0000A57D  0000              add [bx+si],al
0000A57F  0000              add [bx+si],al
0000A581  0000              add [bx+si],al
0000A583  0000              add [bx+si],al
0000A585  0000              add [bx+si],al
0000A587  0000              add [bx+si],al
0000A589  0000              add [bx+si],al
0000A58B  0000              add [bx+si],al
0000A58D  0000              add [bx+si],al
0000A58F  0000              add [bx+si],al
0000A591  0000              add [bx+si],al
0000A593  0000              add [bx+si],al
0000A595  0000              add [bx+si],al
0000A597  0000              add [bx+si],al
0000A599  0000              add [bx+si],al
0000A59B  0000              add [bx+si],al
0000A59D  0000              add [bx+si],al
0000A59F  0000              add [bx+si],al
0000A5A1  0000              add [bx+si],al
0000A5A3  0000              add [bx+si],al
0000A5A5  0000              add [bx+si],al
0000A5A7  0000              add [bx+si],al
0000A5A9  0000              add [bx+si],al
0000A5AB  0000              add [bx+si],al
0000A5AD  0000              add [bx+si],al
0000A5AF  0000              add [bx+si],al
0000A5B1  0000              add [bx+si],al
0000A5B3  0000              add [bx+si],al
0000A5B5  0000              add [bx+si],al
0000A5B7  0000              add [bx+si],al
0000A5B9  0000              add [bx+si],al
0000A5BB  0000              add [bx+si],al
0000A5BD  0000              add [bx+si],al
0000A5BF  0000              add [bx+si],al
0000A5C1  0000              add [bx+si],al
0000A5C3  0000              add [bx+si],al
0000A5C5  0000              add [bx+si],al
0000A5C7  0000              add [bx+si],al
0000A5C9  0000              add [bx+si],al
0000A5CB  0000              add [bx+si],al
0000A5CD  0000              add [bx+si],al
0000A5CF  0000              add [bx+si],al
0000A5D1  0000              add [bx+si],al
0000A5D3  0000              add [bx+si],al
0000A5D5  0000              add [bx+si],al
0000A5D7  0000              add [bx+si],al
0000A5D9  0000              add [bx+si],al
0000A5DB  0000              add [bx+si],al
0000A5DD  0000              add [bx+si],al
0000A5DF  0000              add [bx+si],al
0000A5E1  0000              add [bx+si],al
0000A5E3  0000              add [bx+si],al
0000A5E5  0000              add [bx+si],al
0000A5E7  0000              add [bx+si],al
0000A5E9  0000              add [bx+si],al
0000A5EB  0000              add [bx+si],al
0000A5ED  0000              add [bx+si],al
0000A5EF  0000              add [bx+si],al
0000A5F1  0000              add [bx+si],al
0000A5F3  0000              add [bx+si],al
0000A5F5  0000              add [bx+si],al
0000A5F7  0000              add [bx+si],al
0000A5F9  0000              add [bx+si],al
0000A5FB  0000              add [bx+si],al
0000A5FD  0000              add [bx+si],al
0000A5FF  0000              add [bx+si],al
0000A601  0000              add [bx+si],al
0000A603  0000              add [bx+si],al
0000A605  0000              add [bx+si],al
0000A607  0000              add [bx+si],al
0000A609  0000              add [bx+si],al
0000A60B  0000              add [bx+si],al
0000A60D  0000              add [bx+si],al
0000A60F  0000              add [bx+si],al
0000A611  0000              add [bx+si],al
0000A613  0000              add [bx+si],al
0000A615  0000              add [bx+si],al
0000A617  0000              add [bx+si],al
0000A619  0000              add [bx+si],al
0000A61B  0000              add [bx+si],al
0000A61D  0000              add [bx+si],al
0000A61F  0000              add [bx+si],al
0000A621  0000              add [bx+si],al
0000A623  0000              add [bx+si],al
0000A625  0000              add [bx+si],al
0000A627  0000              add [bx+si],al
0000A629  0000              add [bx+si],al
0000A62B  0000              add [bx+si],al
0000A62D  0000              add [bx+si],al
0000A62F  0000              add [bx+si],al
0000A631  0000              add [bx+si],al
0000A633  0000              add [bx+si],al
0000A635  0000              add [bx+si],al
0000A637  0000              add [bx+si],al
0000A639  0000              add [bx+si],al
0000A63B  0000              add [bx+si],al
0000A63D  0000              add [bx+si],al
0000A63F  0000              add [bx+si],al
0000A641  0000              add [bx+si],al
0000A643  0000              add [bx+si],al
0000A645  0000              add [bx+si],al
0000A647  0000              add [bx+si],al
0000A649  0000              add [bx+si],al
0000A64B  0000              add [bx+si],al
0000A64D  0000              add [bx+si],al
0000A64F  0000              add [bx+si],al
0000A651  0000              add [bx+si],al
0000A653  0000              add [bx+si],al
0000A655  0000              add [bx+si],al
0000A657  0000              add [bx+si],al
0000A659  0000              add [bx+si],al
0000A65B  0000              add [bx+si],al
0000A65D  0000              add [bx+si],al
0000A65F  0000              add [bx+si],al
0000A661  0000              add [bx+si],al
0000A663  0000              add [bx+si],al
0000A665  0000              add [bx+si],al
0000A667  0000              add [bx+si],al
0000A669  0000              add [bx+si],al
0000A66B  0000              add [bx+si],al
0000A66D  0000              add [bx+si],al
0000A66F  0000              add [bx+si],al
0000A671  0000              add [bx+si],al
0000A673  0000              add [bx+si],al
0000A675  0000              add [bx+si],al
0000A677  0000              add [bx+si],al
0000A679  0000              add [bx+si],al
0000A67B  0000              add [bx+si],al
0000A67D  0000              add [bx+si],al
0000A67F  0000              add [bx+si],al
0000A681  0000              add [bx+si],al
0000A683  0000              add [bx+si],al
0000A685  0000              add [bx+si],al
0000A687  0000              add [bx+si],al
0000A689  0000              add [bx+si],al
0000A68B  0000              add [bx+si],al
0000A68D  0000              add [bx+si],al
0000A68F  0000              add [bx+si],al
0000A691  0000              add [bx+si],al
0000A693  0000              add [bx+si],al
0000A695  0000              add [bx+si],al
0000A697  0000              add [bx+si],al
0000A699  0000              add [bx+si],al
0000A69B  0000              add [bx+si],al
0000A69D  0000              add [bx+si],al
0000A69F  0000              add [bx+si],al
0000A6A1  0000              add [bx+si],al
0000A6A3  0000              add [bx+si],al
0000A6A5  0000              add [bx+si],al
0000A6A7  0000              add [bx+si],al
0000A6A9  0000              add [bx+si],al
0000A6AB  0000              add [bx+si],al
0000A6AD  0000              add [bx+si],al
0000A6AF  0000              add [bx+si],al
0000A6B1  0000              add [bx+si],al
0000A6B3  0000              add [bx+si],al
0000A6B5  0000              add [bx+si],al
0000A6B7  0000              add [bx+si],al
0000A6B9  0000              add [bx+si],al
0000A6BB  0000              add [bx+si],al
0000A6BD  0000              add [bx+si],al
0000A6BF  0000              add [bx+si],al
0000A6C1  0000              add [bx+si],al
0000A6C3  0000              add [bx+si],al
0000A6C5  0000              add [bx+si],al
0000A6C7  0000              add [bx+si],al
0000A6C9  0000              add [bx+si],al
0000A6CB  0000              add [bx+si],al
0000A6CD  0000              add [bx+si],al
0000A6CF  0000              add [bx+si],al
0000A6D1  0000              add [bx+si],al
0000A6D3  0000              add [bx+si],al
0000A6D5  0000              add [bx+si],al
0000A6D7  0000              add [bx+si],al
0000A6D9  0000              add [bx+si],al
0000A6DB  0000              add [bx+si],al
0000A6DD  0000              add [bx+si],al
0000A6DF  0000              add [bx+si],al
0000A6E1  0000              add [bx+si],al
0000A6E3  0000              add [bx+si],al
0000A6E5  0000              add [bx+si],al
0000A6E7  0000              add [bx+si],al
0000A6E9  0000              add [bx+si],al
0000A6EB  0000              add [bx+si],al
0000A6ED  0000              add [bx+si],al
0000A6EF  0000              add [bx+si],al
0000A6F1  0000              add [bx+si],al
0000A6F3  0000              add [bx+si],al
0000A6F5  0000              add [bx+si],al
0000A6F7  0000              add [bx+si],al
0000A6F9  0000              add [bx+si],al
0000A6FB  0000              add [bx+si],al
0000A6FD  0000              add [bx+si],al
0000A6FF  0000              add [bx+si],al
0000A701  0000              add [bx+si],al
0000A703  0000              add [bx+si],al
0000A705  0000              add [bx+si],al
0000A707  0000              add [bx+si],al
0000A709  0000              add [bx+si],al
0000A70B  0000              add [bx+si],al
0000A70D  0000              add [bx+si],al
0000A70F  0000              add [bx+si],al
0000A711  0000              add [bx+si],al
0000A713  0000              add [bx+si],al
0000A715  0000              add [bx+si],al
0000A717  0000              add [bx+si],al
0000A719  0000              add [bx+si],al
0000A71B  0000              add [bx+si],al
0000A71D  0000              add [bx+si],al
0000A71F  0000              add [bx+si],al
0000A721  0000              add [bx+si],al
0000A723  0000              add [bx+si],al
0000A725  0000              add [bx+si],al
0000A727  0000              add [bx+si],al
0000A729  0000              add [bx+si],al
0000A72B  0000              add [bx+si],al
0000A72D  0000              add [bx+si],al
0000A72F  0000              add [bx+si],al
0000A731  0000              add [bx+si],al
0000A733  0000              add [bx+si],al
0000A735  0000              add [bx+si],al
0000A737  0000              add [bx+si],al
0000A739  0000              add [bx+si],al
0000A73B  0000              add [bx+si],al
0000A73D  0000              add [bx+si],al
0000A73F  0000              add [bx+si],al
0000A741  0000              add [bx+si],al
0000A743  0000              add [bx+si],al
0000A745  0000              add [bx+si],al
0000A747  0000              add [bx+si],al
0000A749  0000              add [bx+si],al
0000A74B  0000              add [bx+si],al
0000A74D  0000              add [bx+si],al
0000A74F  0000              add [bx+si],al
0000A751  0000              add [bx+si],al
0000A753  0000              add [bx+si],al
0000A755  0000              add [bx+si],al
0000A757  0000              add [bx+si],al
0000A759  0000              add [bx+si],al
0000A75B  0000              add [bx+si],al
0000A75D  0000              add [bx+si],al
0000A75F  0000              add [bx+si],al
0000A761  0000              add [bx+si],al
0000A763  0000              add [bx+si],al
0000A765  0000              add [bx+si],al
0000A767  0000              add [bx+si],al
0000A769  0000              add [bx+si],al
0000A76B  0000              add [bx+si],al
0000A76D  0000              add [bx+si],al
0000A76F  0000              add [bx+si],al
0000A771  0000              add [bx+si],al
0000A773  0000              add [bx+si],al
0000A775  0000              add [bx+si],al
0000A777  0000              add [bx+si],al
0000A779  0000              add [bx+si],al
0000A77B  0000              add [bx+si],al
0000A77D  0000              add [bx+si],al
0000A77F  0000              add [bx+si],al
0000A781  0000              add [bx+si],al
0000A783  0000              add [bx+si],al
0000A785  0000              add [bx+si],al
0000A787  0000              add [bx+si],al
0000A789  0000              add [bx+si],al
0000A78B  0000              add [bx+si],al
0000A78D  0000              add [bx+si],al
0000A78F  0000              add [bx+si],al
0000A791  0000              add [bx+si],al
0000A793  0000              add [bx+si],al
0000A795  0000              add [bx+si],al
0000A797  0000              add [bx+si],al
0000A799  0000              add [bx+si],al
0000A79B  0000              add [bx+si],al
0000A79D  0000              add [bx+si],al
0000A79F  0000              add [bx+si],al
0000A7A1  0000              add [bx+si],al
0000A7A3  0000              add [bx+si],al
0000A7A5  0000              add [bx+si],al
0000A7A7  0000              add [bx+si],al
0000A7A9  0000              add [bx+si],al
0000A7AB  0000              add [bx+si],al
0000A7AD  0000              add [bx+si],al
0000A7AF  0000              add [bx+si],al
0000A7B1  0000              add [bx+si],al
0000A7B3  0000              add [bx+si],al
0000A7B5  0000              add [bx+si],al
0000A7B7  0000              add [bx+si],al
0000A7B9  0000              add [bx+si],al
0000A7BB  0000              add [bx+si],al
0000A7BD  0000              add [bx+si],al
0000A7BF  0000              add [bx+si],al
0000A7C1  0000              add [bx+si],al
0000A7C3  0000              add [bx+si],al
0000A7C5  0000              add [bx+si],al
0000A7C7  0000              add [bx+si],al
0000A7C9  0000              add [bx+si],al
0000A7CB  0000              add [bx+si],al
0000A7CD  0000              add [bx+si],al
0000A7CF  0000              add [bx+si],al
0000A7D1  0000              add [bx+si],al
0000A7D3  0000              add [bx+si],al
0000A7D5  0000              add [bx+si],al
0000A7D7  0000              add [bx+si],al
0000A7D9  0000              add [bx+si],al
0000A7DB  0000              add [bx+si],al
0000A7DD  0000              add [bx+si],al
0000A7DF  0000              add [bx+si],al
0000A7E1  0000              add [bx+si],al
0000A7E3  0000              add [bx+si],al
0000A7E5  0000              add [bx+si],al
0000A7E7  0000              add [bx+si],al
0000A7E9  0000              add [bx+si],al
0000A7EB  0000              add [bx+si],al
0000A7ED  0000              add [bx+si],al
0000A7EF  0000              add [bx+si],al
0000A7F1  0000              add [bx+si],al
0000A7F3  0000              add [bx+si],al
0000A7F5  0000              add [bx+si],al
0000A7F7  0000              add [bx+si],al
0000A7F9  0000              add [bx+si],al
0000A7FB  0000              add [bx+si],al
0000A7FD  0000              add [bx+si],al
0000A7FF  0000              add [bx+si],al
0000A801  0000              add [bx+si],al
0000A803  0000              add [bx+si],al
0000A805  0000              add [bx+si],al
0000A807  0000              add [bx+si],al
0000A809  0000              add [bx+si],al
0000A80B  0000              add [bx+si],al
0000A80D  0000              add [bx+si],al
0000A80F  0000              add [bx+si],al
0000A811  0000              add [bx+si],al
0000A813  0000              add [bx+si],al
0000A815  0000              add [bx+si],al
0000A817  0000              add [bx+si],al
0000A819  0000              add [bx+si],al
0000A81B  0000              add [bx+si],al
0000A81D  0000              add [bx+si],al
0000A81F  0000              add [bx+si],al
0000A821  0000              add [bx+si],al
0000A823  0000              add [bx+si],al
0000A825  0000              add [bx+si],al
0000A827  0000              add [bx+si],al
0000A829  0000              add [bx+si],al
0000A82B  0000              add [bx+si],al
0000A82D  0000              add [bx+si],al
0000A82F  0000              add [bx+si],al
0000A831  0000              add [bx+si],al
0000A833  0000              add [bx+si],al
0000A835  0000              add [bx+si],al
0000A837  0000              add [bx+si],al
0000A839  0000              add [bx+si],al
0000A83B  0000              add [bx+si],al
0000A83D  0000              add [bx+si],al
0000A83F  0000              add [bx+si],al
0000A841  0000              add [bx+si],al
0000A843  0000              add [bx+si],al
0000A845  0000              add [bx+si],al
0000A847  0000              add [bx+si],al
0000A849  0000              add [bx+si],al
0000A84B  0000              add [bx+si],al
0000A84D  0000              add [bx+si],al
0000A84F  0000              add [bx+si],al
0000A851  0000              add [bx+si],al
0000A853  0000              add [bx+si],al
0000A855  0000              add [bx+si],al
0000A857  0000              add [bx+si],al
0000A859  0000              add [bx+si],al
0000A85B  0000              add [bx+si],al
0000A85D  0000              add [bx+si],al
0000A85F  0000              add [bx+si],al
0000A861  0000              add [bx+si],al
0000A863  0000              add [bx+si],al
0000A865  0000              add [bx+si],al
0000A867  0000              add [bx+si],al
0000A869  0000              add [bx+si],al
0000A86B  0000              add [bx+si],al
0000A86D  0000              add [bx+si],al
0000A86F  0000              add [bx+si],al
0000A871  0000              add [bx+si],al
0000A873  0000              add [bx+si],al
0000A875  0000              add [bx+si],al
0000A877  0000              add [bx+si],al
0000A879  0000              add [bx+si],al
0000A87B  0000              add [bx+si],al
0000A87D  0000              add [bx+si],al
0000A87F  0000              add [bx+si],al
0000A881  0000              add [bx+si],al
0000A883  0000              add [bx+si],al
0000A885  0000              add [bx+si],al
0000A887  0000              add [bx+si],al
0000A889  0000              add [bx+si],al
0000A88B  0000              add [bx+si],al
0000A88D  0000              add [bx+si],al
0000A88F  0000              add [bx+si],al
0000A891  0000              add [bx+si],al
0000A893  0000              add [bx+si],al
0000A895  0000              add [bx+si],al
0000A897  0000              add [bx+si],al
0000A899  0000              add [bx+si],al
0000A89B  0000              add [bx+si],al
0000A89D  0000              add [bx+si],al
0000A89F  0000              add [bx+si],al
0000A8A1  0000              add [bx+si],al
0000A8A3  0000              add [bx+si],al
0000A8A5  0000              add [bx+si],al
0000A8A7  0000              add [bx+si],al
0000A8A9  0000              add [bx+si],al
0000A8AB  0000              add [bx+si],al
0000A8AD  0000              add [bx+si],al
0000A8AF  0000              add [bx+si],al
0000A8B1  0000              add [bx+si],al
0000A8B3  0000              add [bx+si],al
0000A8B5  0000              add [bx+si],al
0000A8B7  0000              add [bx+si],al
0000A8B9  0000              add [bx+si],al
0000A8BB  0000              add [bx+si],al
0000A8BD  0000              add [bx+si],al
0000A8BF  0000              add [bx+si],al
0000A8C1  0000              add [bx+si],al
0000A8C3  0000              add [bx+si],al
0000A8C5  0000              add [bx+si],al
0000A8C7  0000              add [bx+si],al
0000A8C9  0000              add [bx+si],al
0000A8CB  0000              add [bx+si],al
0000A8CD  0000              add [bx+si],al
0000A8CF  0000              add [bx+si],al
0000A8D1  0000              add [bx+si],al
0000A8D3  0000              add [bx+si],al
0000A8D5  0000              add [bx+si],al
0000A8D7  0000              add [bx+si],al
0000A8D9  0000              add [bx+si],al
0000A8DB  0000              add [bx+si],al
0000A8DD  0000              add [bx+si],al
0000A8DF  0000              add [bx+si],al
0000A8E1  0000              add [bx+si],al
0000A8E3  0000              add [bx+si],al
0000A8E5  0000              add [bx+si],al
0000A8E7  0000              add [bx+si],al
0000A8E9  0000              add [bx+si],al
0000A8EB  0000              add [bx+si],al
0000A8ED  0000              add [bx+si],al
0000A8EF  0000              add [bx+si],al
0000A8F1  0000              add [bx+si],al
0000A8F3  0000              add [bx+si],al
0000A8F5  0000              add [bx+si],al
0000A8F7  0000              add [bx+si],al
0000A8F9  0000              add [bx+si],al
0000A8FB  0000              add [bx+si],al
0000A8FD  0000              add [bx+si],al
0000A8FF  0000              add [bx+si],al
0000A901  0000              add [bx+si],al
0000A903  0000              add [bx+si],al
0000A905  0000              add [bx+si],al
0000A907  0000              add [bx+si],al
0000A909  0000              add [bx+si],al
0000A90B  0000              add [bx+si],al
0000A90D  0000              add [bx+si],al
0000A90F  0000              add [bx+si],al
0000A911  0000              add [bx+si],al
0000A913  0000              add [bx+si],al
0000A915  0000              add [bx+si],al
0000A917  0000              add [bx+si],al
0000A919  0000              add [bx+si],al
0000A91B  0000              add [bx+si],al
0000A91D  0000              add [bx+si],al
0000A91F  0000              add [bx+si],al
0000A921  0000              add [bx+si],al
0000A923  0000              add [bx+si],al
0000A925  0000              add [bx+si],al
0000A927  0000              add [bx+si],al
0000A929  0000              add [bx+si],al
0000A92B  0000              add [bx+si],al
0000A92D  0000              add [bx+si],al
0000A92F  0000              add [bx+si],al
0000A931  0000              add [bx+si],al
0000A933  0000              add [bx+si],al
0000A935  0000              add [bx+si],al
0000A937  0000              add [bx+si],al
0000A939  0000              add [bx+si],al
0000A93B  0000              add [bx+si],al
0000A93D  0000              add [bx+si],al
0000A93F  0000              add [bx+si],al
0000A941  0000              add [bx+si],al
0000A943  0000              add [bx+si],al
0000A945  0000              add [bx+si],al
0000A947  0000              add [bx+si],al
0000A949  0000              add [bx+si],al
0000A94B  0000              add [bx+si],al
0000A94D  0000              add [bx+si],al
0000A94F  0000              add [bx+si],al
0000A951  0000              add [bx+si],al
0000A953  0000              add [bx+si],al
0000A955  0000              add [bx+si],al
0000A957  0000              add [bx+si],al
0000A959  0000              add [bx+si],al
0000A95B  0000              add [bx+si],al
0000A95D  0000              add [bx+si],al
0000A95F  0000              add [bx+si],al
0000A961  0000              add [bx+si],al
0000A963  0000              add [bx+si],al
0000A965  0000              add [bx+si],al
0000A967  0000              add [bx+si],al
0000A969  0000              add [bx+si],al
0000A96B  0000              add [bx+si],al
0000A96D  0000              add [bx+si],al
0000A96F  0000              add [bx+si],al
0000A971  0000              add [bx+si],al
0000A973  0000              add [bx+si],al
0000A975  0000              add [bx+si],al
0000A977  0000              add [bx+si],al
0000A979  0000              add [bx+si],al
0000A97B  0000              add [bx+si],al
0000A97D  0000              add [bx+si],al
0000A97F  0000              add [bx+si],al
0000A981  0000              add [bx+si],al
0000A983  0000              add [bx+si],al
0000A985  0000              add [bx+si],al
0000A987  0000              add [bx+si],al
0000A989  0000              add [bx+si],al
0000A98B  0000              add [bx+si],al
0000A98D  0000              add [bx+si],al
0000A98F  0000              add [bx+si],al
0000A991  0000              add [bx+si],al
0000A993  0000              add [bx+si],al
0000A995  0000              add [bx+si],al
0000A997  0000              add [bx+si],al
0000A999  0000              add [bx+si],al
0000A99B  0000              add [bx+si],al
0000A99D  0000              add [bx+si],al
0000A99F  0000              add [bx+si],al
0000A9A1  0000              add [bx+si],al
0000A9A3  0000              add [bx+si],al
0000A9A5  0000              add [bx+si],al
0000A9A7  0000              add [bx+si],al
0000A9A9  0000              add [bx+si],al
0000A9AB  0000              add [bx+si],al
0000A9AD  0000              add [bx+si],al
0000A9AF  0000              add [bx+si],al
0000A9B1  0000              add [bx+si],al
0000A9B3  0000              add [bx+si],al
0000A9B5  0000              add [bx+si],al
0000A9B7  0000              add [bx+si],al
0000A9B9  0000              add [bx+si],al
0000A9BB  0000              add [bx+si],al
0000A9BD  0000              add [bx+si],al
0000A9BF  0000              add [bx+si],al
0000A9C1  0000              add [bx+si],al
0000A9C3  0000              add [bx+si],al
0000A9C5  0000              add [bx+si],al
0000A9C7  0000              add [bx+si],al
0000A9C9  0000              add [bx+si],al
0000A9CB  0000              add [bx+si],al
0000A9CD  0000              add [bx+si],al
0000A9CF  0000              add [bx+si],al
0000A9D1  0000              add [bx+si],al
0000A9D3  0000              add [bx+si],al
0000A9D5  0000              add [bx+si],al
0000A9D7  0000              add [bx+si],al
0000A9D9  0000              add [bx+si],al
0000A9DB  0000              add [bx+si],al
0000A9DD  0000              add [bx+si],al
0000A9DF  0000              add [bx+si],al
0000A9E1  0000              add [bx+si],al
0000A9E3  0000              add [bx+si],al
0000A9E5  0000              add [bx+si],al
0000A9E7  0000              add [bx+si],al
0000A9E9  0000              add [bx+si],al
0000A9EB  0000              add [bx+si],al
0000A9ED  0000              add [bx+si],al
0000A9EF  0000              add [bx+si],al
0000A9F1  0000              add [bx+si],al
0000A9F3  0000              add [bx+si],al
0000A9F5  0000              add [bx+si],al
0000A9F7  0000              add [bx+si],al
0000A9F9  0000              add [bx+si],al
0000A9FB  0000              add [bx+si],al
0000A9FD  0000              add [bx+si],al
0000A9FF  0000              add [bx+si],al
0000AA01  0000              add [bx+si],al
0000AA03  0000              add [bx+si],al
0000AA05  0000              add [bx+si],al
0000AA07  0000              add [bx+si],al
0000AA09  0000              add [bx+si],al
0000AA0B  0000              add [bx+si],al
0000AA0D  0000              add [bx+si],al
0000AA0F  0000              add [bx+si],al
0000AA11  0000              add [bx+si],al
0000AA13  0000              add [bx+si],al
0000AA15  0000              add [bx+si],al
0000AA17  0000              add [bx+si],al
0000AA19  0000              add [bx+si],al
0000AA1B  0000              add [bx+si],al
0000AA1D  0000              add [bx+si],al
0000AA1F  0000              add [bx+si],al
0000AA21  0000              add [bx+si],al
0000AA23  0000              add [bx+si],al
0000AA25  0000              add [bx+si],al
0000AA27  0000              add [bx+si],al
0000AA29  0000              add [bx+si],al
0000AA2B  0000              add [bx+si],al
0000AA2D  0000              add [bx+si],al
0000AA2F  0000              add [bx+si],al
0000AA31  0000              add [bx+si],al
0000AA33  0000              add [bx+si],al
0000AA35  0000              add [bx+si],al
0000AA37  0000              add [bx+si],al
0000AA39  0000              add [bx+si],al
0000AA3B  0000              add [bx+si],al
0000AA3D  0000              add [bx+si],al
0000AA3F  0000              add [bx+si],al
0000AA41  0000              add [bx+si],al
0000AA43  0000              add [bx+si],al
0000AA45  0000              add [bx+si],al
0000AA47  0000              add [bx+si],al
0000AA49  0000              add [bx+si],al
0000AA4B  0000              add [bx+si],al
0000AA4D  0000              add [bx+si],al
0000AA4F  0000              add [bx+si],al
0000AA51  0000              add [bx+si],al
0000AA53  0000              add [bx+si],al
0000AA55  0000              add [bx+si],al
0000AA57  0000              add [bx+si],al
0000AA59  0000              add [bx+si],al
0000AA5B  0000              add [bx+si],al
0000AA5D  0000              add [bx+si],al
0000AA5F  0000              add [bx+si],al
0000AA61  0000              add [bx+si],al
0000AA63  0000              add [bx+si],al
0000AA65  0000              add [bx+si],al
0000AA67  0000              add [bx+si],al
0000AA69  0000              add [bx+si],al
0000AA6B  0000              add [bx+si],al
0000AA6D  0000              add [bx+si],al
0000AA6F  0000              add [bx+si],al
0000AA71  0000              add [bx+si],al
0000AA73  0000              add [bx+si],al
0000AA75  0000              add [bx+si],al
0000AA77  0000              add [bx+si],al
0000AA79  0000              add [bx+si],al
0000AA7B  0000              add [bx+si],al
0000AA7D  0000              add [bx+si],al
0000AA7F  0000              add [bx+si],al
0000AA81  0000              add [bx+si],al
0000AA83  0000              add [bx+si],al
0000AA85  0000              add [bx+si],al
0000AA87  0000              add [bx+si],al
0000AA89  0000              add [bx+si],al
0000AA8B  0000              add [bx+si],al
0000AA8D  0000              add [bx+si],al
0000AA8F  0000              add [bx+si],al
0000AA91  0000              add [bx+si],al
0000AA93  0000              add [bx+si],al
0000AA95  0000              add [bx+si],al
0000AA97  0000              add [bx+si],al
0000AA99  0000              add [bx+si],al
0000AA9B  0000              add [bx+si],al
0000AA9D  0000              add [bx+si],al
0000AA9F  0000              add [bx+si],al
0000AAA1  0000              add [bx+si],al
0000AAA3  0000              add [bx+si],al
0000AAA5  0000              add [bx+si],al
0000AAA7  0000              add [bx+si],al
0000AAA9  0000              add [bx+si],al
0000AAAB  0000              add [bx+si],al
0000AAAD  0000              add [bx+si],al
0000AAAF  0000              add [bx+si],al
0000AAB1  0000              add [bx+si],al
0000AAB3  0000              add [bx+si],al
0000AAB5  0000              add [bx+si],al
0000AAB7  0000              add [bx+si],al
0000AAB9  0000              add [bx+si],al
0000AABB  0000              add [bx+si],al
0000AABD  0000              add [bx+si],al
0000AABF  0000              add [bx+si],al
0000AAC1  0000              add [bx+si],al
0000AAC3  0000              add [bx+si],al
0000AAC5  0000              add [bx+si],al
0000AAC7  0000              add [bx+si],al
0000AAC9  0000              add [bx+si],al
0000AACB  0000              add [bx+si],al
0000AACD  0000              add [bx+si],al
0000AACF  0000              add [bx+si],al
0000AAD1  0000              add [bx+si],al
0000AAD3  0000              add [bx+si],al
0000AAD5  0000              add [bx+si],al
0000AAD7  0000              add [bx+si],al
0000AAD9  0000              add [bx+si],al
0000AADB  0000              add [bx+si],al
0000AADD  0000              add [bx+si],al
0000AADF  0000              add [bx+si],al
0000AAE1  0000              add [bx+si],al
0000AAE3  0000              add [bx+si],al
0000AAE5  0000              add [bx+si],al
0000AAE7  0000              add [bx+si],al
0000AAE9  0000              add [bx+si],al
0000AAEB  0000              add [bx+si],al
0000AAED  0000              add [bx+si],al
0000AAEF  0000              add [bx+si],al
0000AAF1  0000              add [bx+si],al
0000AAF3  0000              add [bx+si],al
0000AAF5  0000              add [bx+si],al
0000AAF7  0000              add [bx+si],al
0000AAF9  0000              add [bx+si],al
0000AAFB  0000              add [bx+si],al
0000AAFD  0000              add [bx+si],al
0000AAFF  0000              add [bx+si],al
0000AB01  0000              add [bx+si],al
0000AB03  0000              add [bx+si],al
0000AB05  0000              add [bx+si],al
0000AB07  0000              add [bx+si],al
0000AB09  0000              add [bx+si],al
0000AB0B  0000              add [bx+si],al
0000AB0D  0000              add [bx+si],al
0000AB0F  0000              add [bx+si],al
0000AB11  0000              add [bx+si],al
0000AB13  0000              add [bx+si],al
0000AB15  0000              add [bx+si],al
0000AB17  0000              add [bx+si],al
0000AB19  0000              add [bx+si],al
0000AB1B  0000              add [bx+si],al
0000AB1D  0000              add [bx+si],al
0000AB1F  0000              add [bx+si],al
0000AB21  0000              add [bx+si],al
0000AB23  0000              add [bx+si],al
0000AB25  0000              add [bx+si],al
0000AB27  0000              add [bx+si],al
0000AB29  0000              add [bx+si],al
0000AB2B  0000              add [bx+si],al
0000AB2D  0000              add [bx+si],al
0000AB2F  0000              add [bx+si],al
0000AB31  0000              add [bx+si],al
0000AB33  0000              add [bx+si],al
0000AB35  0000              add [bx+si],al
0000AB37  0000              add [bx+si],al
0000AB39  0000              add [bx+si],al
0000AB3B  0000              add [bx+si],al
0000AB3D  0000              add [bx+si],al
0000AB3F  0000              add [bx+si],al
0000AB41  0000              add [bx+si],al
0000AB43  0000              add [bx+si],al
0000AB45  0000              add [bx+si],al
0000AB47  0000              add [bx+si],al
0000AB49  0000              add [bx+si],al
0000AB4B  0000              add [bx+si],al
0000AB4D  0000              add [bx+si],al
0000AB4F  0000              add [bx+si],al
0000AB51  0000              add [bx+si],al
0000AB53  0000              add [bx+si],al
0000AB55  0000              add [bx+si],al
0000AB57  0000              add [bx+si],al
0000AB59  0000              add [bx+si],al
0000AB5B  0000              add [bx+si],al
0000AB5D  0000              add [bx+si],al
0000AB5F  0000              add [bx+si],al
0000AB61  0000              add [bx+si],al
0000AB63  0000              add [bx+si],al
0000AB65  0000              add [bx+si],al
0000AB67  0000              add [bx+si],al
0000AB69  0000              add [bx+si],al
0000AB6B  0000              add [bx+si],al
0000AB6D  0000              add [bx+si],al
0000AB6F  0000              add [bx+si],al
0000AB71  0000              add [bx+si],al
0000AB73  0000              add [bx+si],al
0000AB75  0000              add [bx+si],al
0000AB77  0000              add [bx+si],al
0000AB79  0000              add [bx+si],al
0000AB7B  0000              add [bx+si],al
0000AB7D  0000              add [bx+si],al
0000AB7F  0000              add [bx+si],al
0000AB81  0000              add [bx+si],al
0000AB83  0000              add [bx+si],al
0000AB85  0000              add [bx+si],al
0000AB87  0000              add [bx+si],al
0000AB89  0000              add [bx+si],al
0000AB8B  0000              add [bx+si],al
0000AB8D  0000              add [bx+si],al
0000AB8F  0000              add [bx+si],al
0000AB91  0000              add [bx+si],al
0000AB93  0000              add [bx+si],al
0000AB95  0000              add [bx+si],al
0000AB97  0000              add [bx+si],al
0000AB99  0000              add [bx+si],al
0000AB9B  0000              add [bx+si],al
0000AB9D  0000              add [bx+si],al
0000AB9F  0000              add [bx+si],al
0000ABA1  0000              add [bx+si],al
0000ABA3  0000              add [bx+si],al
0000ABA5  0000              add [bx+si],al
0000ABA7  0000              add [bx+si],al
0000ABA9  0000              add [bx+si],al
0000ABAB  0000              add [bx+si],al
0000ABAD  0000              add [bx+si],al
0000ABAF  0000              add [bx+si],al
0000ABB1  0000              add [bx+si],al
0000ABB3  0000              add [bx+si],al
0000ABB5  0000              add [bx+si],al
0000ABB7  0000              add [bx+si],al
0000ABB9  0000              add [bx+si],al
0000ABBB  0000              add [bx+si],al
0000ABBD  0000              add [bx+si],al
0000ABBF  0000              add [bx+si],al
0000ABC1  0000              add [bx+si],al
0000ABC3  0000              add [bx+si],al
0000ABC5  0000              add [bx+si],al
0000ABC7  0000              add [bx+si],al
0000ABC9  0000              add [bx+si],al
0000ABCB  0000              add [bx+si],al
0000ABCD  0000              add [bx+si],al
0000ABCF  0000              add [bx+si],al
0000ABD1  0000              add [bx+si],al
0000ABD3  0000              add [bx+si],al
0000ABD5  0000              add [bx+si],al
0000ABD7  0000              add [bx+si],al
0000ABD9  0000              add [bx+si],al
0000ABDB  0000              add [bx+si],al
0000ABDD  0000              add [bx+si],al
0000ABDF  0000              add [bx+si],al
0000ABE1  0000              add [bx+si],al
0000ABE3  0000              add [bx+si],al
0000ABE5  0000              add [bx+si],al
0000ABE7  0000              add [bx+si],al
0000ABE9  0000              add [bx+si],al
0000ABEB  0000              add [bx+si],al
0000ABED  0000              add [bx+si],al
0000ABEF  0000              add [bx+si],al
0000ABF1  0000              add [bx+si],al
0000ABF3  0000              add [bx+si],al
0000ABF5  0000              add [bx+si],al
0000ABF7  0000              add [bx+si],al
0000ABF9  0000              add [bx+si],al
0000ABFB  0000              add [bx+si],al
0000ABFD  0000              add [bx+si],al
0000ABFF  0000              add [bx+si],al
0000AC01  0000              add [bx+si],al
0000AC03  0000              add [bx+si],al
0000AC05  0000              add [bx+si],al
0000AC07  0000              add [bx+si],al
0000AC09  0000              add [bx+si],al
0000AC0B  0000              add [bx+si],al
0000AC0D  0000              add [bx+si],al
0000AC0F  0000              add [bx+si],al
0000AC11  0000              add [bx+si],al
0000AC13  0000              add [bx+si],al
0000AC15  0000              add [bx+si],al
0000AC17  0000              add [bx+si],al
0000AC19  0000              add [bx+si],al
0000AC1B  0000              add [bx+si],al
0000AC1D  0000              add [bx+si],al
0000AC1F  0000              add [bx+si],al
0000AC21  0000              add [bx+si],al
0000AC23  0000              add [bx+si],al
0000AC25  0000              add [bx+si],al
0000AC27  0000              add [bx+si],al
0000AC29  0000              add [bx+si],al
0000AC2B  0000              add [bx+si],al
0000AC2D  0000              add [bx+si],al
0000AC2F  0000              add [bx+si],al
0000AC31  0000              add [bx+si],al
0000AC33  0000              add [bx+si],al
0000AC35  0000              add [bx+si],al
0000AC37  0000              add [bx+si],al
0000AC39  0000              add [bx+si],al
0000AC3B  0000              add [bx+si],al
0000AC3D  0000              add [bx+si],al
0000AC3F  0000              add [bx+si],al
0000AC41  0000              add [bx+si],al
0000AC43  0000              add [bx+si],al
0000AC45  0000              add [bx+si],al
0000AC47  0000              add [bx+si],al
0000AC49  0000              add [bx+si],al
0000AC4B  0000              add [bx+si],al
0000AC4D  0000              add [bx+si],al
0000AC4F  0000              add [bx+si],al
0000AC51  0000              add [bx+si],al
0000AC53  0000              add [bx+si],al
0000AC55  0000              add [bx+si],al
0000AC57  0000              add [bx+si],al
0000AC59  0000              add [bx+si],al
0000AC5B  0000              add [bx+si],al
0000AC5D  0000              add [bx+si],al
0000AC5F  0000              add [bx+si],al
0000AC61  0000              add [bx+si],al
0000AC63  0000              add [bx+si],al
0000AC65  0000              add [bx+si],al
0000AC67  0000              add [bx+si],al
0000AC69  0000              add [bx+si],al
0000AC6B  0000              add [bx+si],al
0000AC6D  0000              add [bx+si],al
0000AC6F  0000              add [bx+si],al
0000AC71  0000              add [bx+si],al
0000AC73  0000              add [bx+si],al
0000AC75  0000              add [bx+si],al
0000AC77  0000              add [bx+si],al
0000AC79  0000              add [bx+si],al
0000AC7B  0000              add [bx+si],al
0000AC7D  0000              add [bx+si],al
0000AC7F  0000              add [bx+si],al
0000AC81  0000              add [bx+si],al
0000AC83  0000              add [bx+si],al
0000AC85  0000              add [bx+si],al
0000AC87  0000              add [bx+si],al
0000AC89  0000              add [bx+si],al
0000AC8B  0000              add [bx+si],al
0000AC8D  0000              add [bx+si],al
0000AC8F  0000              add [bx+si],al
0000AC91  0000              add [bx+si],al
0000AC93  0000              add [bx+si],al
0000AC95  0000              add [bx+si],al
0000AC97  0000              add [bx+si],al
0000AC99  0000              add [bx+si],al
0000AC9B  0000              add [bx+si],al
0000AC9D  0000              add [bx+si],al
0000AC9F  0000              add [bx+si],al
0000ACA1  0000              add [bx+si],al
0000ACA3  0000              add [bx+si],al
0000ACA5  0000              add [bx+si],al
0000ACA7  0000              add [bx+si],al
0000ACA9  0000              add [bx+si],al
0000ACAB  0000              add [bx+si],al
0000ACAD  0000              add [bx+si],al
0000ACAF  0000              add [bx+si],al
0000ACB1  0000              add [bx+si],al
0000ACB3  0000              add [bx+si],al
0000ACB5  0000              add [bx+si],al
0000ACB7  0000              add [bx+si],al
0000ACB9  0000              add [bx+si],al
0000ACBB  0000              add [bx+si],al
0000ACBD  0000              add [bx+si],al
0000ACBF  0000              add [bx+si],al
0000ACC1  0000              add [bx+si],al
0000ACC3  0000              add [bx+si],al
0000ACC5  0000              add [bx+si],al
0000ACC7  0000              add [bx+si],al
0000ACC9  0000              add [bx+si],al
0000ACCB  0000              add [bx+si],al
0000ACCD  0000              add [bx+si],al
0000ACCF  0000              add [bx+si],al
0000ACD1  0000              add [bx+si],al
0000ACD3  0000              add [bx+si],al
0000ACD5  0000              add [bx+si],al
0000ACD7  0000              add [bx+si],al
0000ACD9  0000              add [bx+si],al
0000ACDB  0000              add [bx+si],al
0000ACDD  0000              add [bx+si],al
0000ACDF  0000              add [bx+si],al
0000ACE1  0000              add [bx+si],al
0000ACE3  0000              add [bx+si],al
0000ACE5  0000              add [bx+si],al
0000ACE7  0000              add [bx+si],al
0000ACE9  0000              add [bx+si],al
0000ACEB  0000              add [bx+si],al
0000ACED  0000              add [bx+si],al
0000ACEF  0000              add [bx+si],al
0000ACF1  0000              add [bx+si],al
0000ACF3  0000              add [bx+si],al
0000ACF5  0000              add [bx+si],al
0000ACF7  0000              add [bx+si],al
0000ACF9  0000              add [bx+si],al
0000ACFB  0000              add [bx+si],al
0000ACFD  0000              add [bx+si],al
0000ACFF  0000              add [bx+si],al
0000AD01  0000              add [bx+si],al
0000AD03  0000              add [bx+si],al
0000AD05  0000              add [bx+si],al
0000AD07  0000              add [bx+si],al
0000AD09  0000              add [bx+si],al
0000AD0B  0000              add [bx+si],al
0000AD0D  0000              add [bx+si],al
0000AD0F  0000              add [bx+si],al
0000AD11  0000              add [bx+si],al
0000AD13  0000              add [bx+si],al
0000AD15  0000              add [bx+si],al
0000AD17  0000              add [bx+si],al
0000AD19  0000              add [bx+si],al
0000AD1B  0000              add [bx+si],al
0000AD1D  0000              add [bx+si],al
0000AD1F  0000              add [bx+si],al
0000AD21  0000              add [bx+si],al
0000AD23  0000              add [bx+si],al
0000AD25  0000              add [bx+si],al
0000AD27  0000              add [bx+si],al
0000AD29  0000              add [bx+si],al
0000AD2B  0000              add [bx+si],al
0000AD2D  0000              add [bx+si],al
0000AD2F  0000              add [bx+si],al
0000AD31  0000              add [bx+si],al
0000AD33  0000              add [bx+si],al
0000AD35  0000              add [bx+si],al
0000AD37  0000              add [bx+si],al
0000AD39  0000              add [bx+si],al
0000AD3B  0000              add [bx+si],al
0000AD3D  0000              add [bx+si],al
0000AD3F  0000              add [bx+si],al
0000AD41  0000              add [bx+si],al
0000AD43  0000              add [bx+si],al
0000AD45  0000              add [bx+si],al
0000AD47  0000              add [bx+si],al
0000AD49  0000              add [bx+si],al
0000AD4B  0000              add [bx+si],al
0000AD4D  0000              add [bx+si],al
0000AD4F  0000              add [bx+si],al
0000AD51  0000              add [bx+si],al
0000AD53  0000              add [bx+si],al
0000AD55  0000              add [bx+si],al
0000AD57  0000              add [bx+si],al
0000AD59  0000              add [bx+si],al
0000AD5B  0000              add [bx+si],al
0000AD5D  0000              add [bx+si],al
0000AD5F  0000              add [bx+si],al
0000AD61  0000              add [bx+si],al
0000AD63  0000              add [bx+si],al
0000AD65  0000              add [bx+si],al
0000AD67  0000              add [bx+si],al
0000AD69  0000              add [bx+si],al
0000AD6B  0000              add [bx+si],al
0000AD6D  0000              add [bx+si],al
0000AD6F  0000              add [bx+si],al
0000AD71  0000              add [bx+si],al
0000AD73  0000              add [bx+si],al
0000AD75  0000              add [bx+si],al
0000AD77  0000              add [bx+si],al
0000AD79  0000              add [bx+si],al
0000AD7B  0000              add [bx+si],al
0000AD7D  0000              add [bx+si],al
0000AD7F  0000              add [bx+si],al
0000AD81  0000              add [bx+si],al
0000AD83  0000              add [bx+si],al
0000AD85  0000              add [bx+si],al
0000AD87  0000              add [bx+si],al
0000AD89  0000              add [bx+si],al
0000AD8B  0000              add [bx+si],al
0000AD8D  0000              add [bx+si],al
0000AD8F  0000              add [bx+si],al
0000AD91  0000              add [bx+si],al
0000AD93  0000              add [bx+si],al
0000AD95  0000              add [bx+si],al
0000AD97  0000              add [bx+si],al
0000AD99  0000              add [bx+si],al
0000AD9B  0000              add [bx+si],al
0000AD9D  0000              add [bx+si],al
0000AD9F  0000              add [bx+si],al
0000ADA1  0000              add [bx+si],al
0000ADA3  0000              add [bx+si],al
0000ADA5  0000              add [bx+si],al
0000ADA7  0000              add [bx+si],al
0000ADA9  0000              add [bx+si],al
0000ADAB  0000              add [bx+si],al
0000ADAD  0000              add [bx+si],al
0000ADAF  0000              add [bx+si],al
0000ADB1  0000              add [bx+si],al
0000ADB3  0000              add [bx+si],al
0000ADB5  0000              add [bx+si],al
0000ADB7  0000              add [bx+si],al
0000ADB9  0000              add [bx+si],al
0000ADBB  0000              add [bx+si],al
0000ADBD  0000              add [bx+si],al
0000ADBF  0000              add [bx+si],al
0000ADC1  0000              add [bx+si],al
0000ADC3  0000              add [bx+si],al
0000ADC5  0000              add [bx+si],al
0000ADC7  0000              add [bx+si],al
0000ADC9  0000              add [bx+si],al
0000ADCB  0000              add [bx+si],al
0000ADCD  0000              add [bx+si],al
0000ADCF  0000              add [bx+si],al
0000ADD1  0000              add [bx+si],al
0000ADD3  0000              add [bx+si],al
0000ADD5  0000              add [bx+si],al
0000ADD7  0000              add [bx+si],al
0000ADD9  0000              add [bx+si],al
0000ADDB  0000              add [bx+si],al
0000ADDD  0000              add [bx+si],al
0000ADDF  0000              add [bx+si],al
0000ADE1  0000              add [bx+si],al
0000ADE3  0000              add [bx+si],al
0000ADE5  0000              add [bx+si],al
0000ADE7  0000              add [bx+si],al
0000ADE9  0000              add [bx+si],al
0000ADEB  0000              add [bx+si],al
0000ADED  0000              add [bx+si],al
0000ADEF  0000              add [bx+si],al
0000ADF1  0000              add [bx+si],al
0000ADF3  0000              add [bx+si],al
0000ADF5  0000              add [bx+si],al
0000ADF7  0000              add [bx+si],al
0000ADF9  0000              add [bx+si],al
0000ADFB  0000              add [bx+si],al
0000ADFD  0000              add [bx+si],al
0000ADFF  0000              add [bx+si],al
0000AE01  0000              add [bx+si],al
0000AE03  0000              add [bx+si],al
0000AE05  0000              add [bx+si],al
0000AE07  0000              add [bx+si],al
0000AE09  0000              add [bx+si],al
0000AE0B  0000              add [bx+si],al
0000AE0D  0000              add [bx+si],al
0000AE0F  0000              add [bx+si],al
0000AE11  0000              add [bx+si],al
0000AE13  0000              add [bx+si],al
0000AE15  0000              add [bx+si],al
0000AE17  0000              add [bx+si],al
0000AE19  0000              add [bx+si],al
0000AE1B  0000              add [bx+si],al
0000AE1D  0000              add [bx+si],al
0000AE1F  0000              add [bx+si],al
0000AE21  0000              add [bx+si],al
0000AE23  0000              add [bx+si],al
0000AE25  0000              add [bx+si],al
0000AE27  0000              add [bx+si],al
0000AE29  0000              add [bx+si],al
0000AE2B  0000              add [bx+si],al
0000AE2D  0000              add [bx+si],al
0000AE2F  0000              add [bx+si],al
0000AE31  0000              add [bx+si],al
0000AE33  0000              add [bx+si],al
0000AE35  0000              add [bx+si],al
0000AE37  0000              add [bx+si],al
0000AE39  0000              add [bx+si],al
0000AE3B  0000              add [bx+si],al
0000AE3D  0000              add [bx+si],al
0000AE3F  0000              add [bx+si],al
0000AE41  0000              add [bx+si],al
0000AE43  0000              add [bx+si],al
0000AE45  0000              add [bx+si],al
0000AE47  0000              add [bx+si],al
0000AE49  0000              add [bx+si],al
0000AE4B  0000              add [bx+si],al
0000AE4D  0000              add [bx+si],al
0000AE4F  0000              add [bx+si],al
0000AE51  0000              add [bx+si],al
0000AE53  0000              add [bx+si],al
0000AE55  0000              add [bx+si],al
0000AE57  0000              add [bx+si],al
0000AE59  0000              add [bx+si],al
0000AE5B  0000              add [bx+si],al
0000AE5D  0000              add [bx+si],al
0000AE5F  0000              add [bx+si],al
0000AE61  0000              add [bx+si],al
0000AE63  0000              add [bx+si],al
0000AE65  0000              add [bx+si],al
0000AE67  0000              add [bx+si],al
0000AE69  0000              add [bx+si],al
0000AE6B  0000              add [bx+si],al
0000AE6D  0000              add [bx+si],al
0000AE6F  0000              add [bx+si],al
0000AE71  0000              add [bx+si],al
0000AE73  0000              add [bx+si],al
0000AE75  0000              add [bx+si],al
0000AE77  0000              add [bx+si],al
0000AE79  0000              add [bx+si],al
0000AE7B  0000              add [bx+si],al
0000AE7D  0000              add [bx+si],al
0000AE7F  0000              add [bx+si],al
0000AE81  0000              add [bx+si],al
0000AE83  0000              add [bx+si],al
0000AE85  0000              add [bx+si],al
0000AE87  0000              add [bx+si],al
0000AE89  0000              add [bx+si],al
0000AE8B  0000              add [bx+si],al
0000AE8D  0000              add [bx+si],al
0000AE8F  0000              add [bx+si],al
0000AE91  0000              add [bx+si],al
0000AE93  0000              add [bx+si],al
0000AE95  0000              add [bx+si],al
0000AE97  0000              add [bx+si],al
0000AE99  0000              add [bx+si],al
0000AE9B  0000              add [bx+si],al
0000AE9D  0000              add [bx+si],al
0000AE9F  0000              add [bx+si],al
0000AEA1  0000              add [bx+si],al
0000AEA3  0000              add [bx+si],al
0000AEA5  0000              add [bx+si],al
0000AEA7  0000              add [bx+si],al
0000AEA9  0000              add [bx+si],al
0000AEAB  0000              add [bx+si],al
0000AEAD  0000              add [bx+si],al
0000AEAF  0000              add [bx+si],al
0000AEB1  0000              add [bx+si],al
0000AEB3  0000              add [bx+si],al
0000AEB5  0000              add [bx+si],al
0000AEB7  0000              add [bx+si],al
0000AEB9  0000              add [bx+si],al
0000AEBB  0000              add [bx+si],al
0000AEBD  0000              add [bx+si],al
0000AEBF  0000              add [bx+si],al
0000AEC1  0000              add [bx+si],al
0000AEC3  0000              add [bx+si],al
0000AEC5  0000              add [bx+si],al
0000AEC7  0000              add [bx+si],al
0000AEC9  0000              add [bx+si],al
0000AECB  0000              add [bx+si],al
0000AECD  0000              add [bx+si],al
0000AECF  0000              add [bx+si],al
0000AED1  0000              add [bx+si],al
0000AED3  0000              add [bx+si],al
0000AED5  0000              add [bx+si],al
0000AED7  0000              add [bx+si],al
0000AED9  0000              add [bx+si],al
0000AEDB  0000              add [bx+si],al
0000AEDD  0000              add [bx+si],al
0000AEDF  0000              add [bx+si],al
0000AEE1  0000              add [bx+si],al
0000AEE3  0000              add [bx+si],al
0000AEE5  0000              add [bx+si],al
0000AEE7  0000              add [bx+si],al
0000AEE9  0000              add [bx+si],al
0000AEEB  0000              add [bx+si],al
0000AEED  0000              add [bx+si],al
0000AEEF  0000              add [bx+si],al
0000AEF1  0000              add [bx+si],al
0000AEF3  0000              add [bx+si],al
0000AEF5  0000              add [bx+si],al
0000AEF7  0000              add [bx+si],al
0000AEF9  0000              add [bx+si],al
0000AEFB  0000              add [bx+si],al
0000AEFD  0000              add [bx+si],al
0000AEFF  0000              add [bx+si],al
0000AF01  0000              add [bx+si],al
0000AF03  0000              add [bx+si],al
0000AF05  0000              add [bx+si],al
0000AF07  0000              add [bx+si],al
0000AF09  0000              add [bx+si],al
0000AF0B  0000              add [bx+si],al
0000AF0D  0000              add [bx+si],al
0000AF0F  0000              add [bx+si],al
0000AF11  0000              add [bx+si],al
0000AF13  0000              add [bx+si],al
0000AF15  0000              add [bx+si],al
0000AF17  0000              add [bx+si],al
0000AF19  0000              add [bx+si],al
0000AF1B  0000              add [bx+si],al
0000AF1D  0000              add [bx+si],al
0000AF1F  0000              add [bx+si],al
0000AF21  0000              add [bx+si],al
0000AF23  0000              add [bx+si],al
0000AF25  0000              add [bx+si],al
0000AF27  0000              add [bx+si],al
0000AF29  0000              add [bx+si],al
0000AF2B  0000              add [bx+si],al
0000AF2D  0000              add [bx+si],al
0000AF2F  0000              add [bx+si],al
0000AF31  0000              add [bx+si],al
0000AF33  0000              add [bx+si],al
0000AF35  0000              add [bx+si],al
0000AF37  0000              add [bx+si],al
0000AF39  0000              add [bx+si],al
0000AF3B  0000              add [bx+si],al
0000AF3D  0000              add [bx+si],al
0000AF3F  0000              add [bx+si],al
0000AF41  0000              add [bx+si],al
0000AF43  0000              add [bx+si],al
0000AF45  0000              add [bx+si],al
0000AF47  0000              add [bx+si],al
0000AF49  0000              add [bx+si],al
0000AF4B  0000              add [bx+si],al
0000AF4D  0000              add [bx+si],al
0000AF4F  0000              add [bx+si],al
0000AF51  0000              add [bx+si],al
0000AF53  0000              add [bx+si],al
0000AF55  0000              add [bx+si],al
0000AF57  0000              add [bx+si],al
0000AF59  0000              add [bx+si],al
0000AF5B  0000              add [bx+si],al
0000AF5D  0000              add [bx+si],al
0000AF5F  0000              add [bx+si],al
0000AF61  0000              add [bx+si],al
0000AF63  0000              add [bx+si],al
0000AF65  0000              add [bx+si],al
0000AF67  0000              add [bx+si],al
0000AF69  0000              add [bx+si],al
0000AF6B  0000              add [bx+si],al
0000AF6D  0000              add [bx+si],al
0000AF6F  0000              add [bx+si],al
0000AF71  0000              add [bx+si],al
0000AF73  0000              add [bx+si],al
0000AF75  0000              add [bx+si],al
0000AF77  0000              add [bx+si],al
0000AF79  0000              add [bx+si],al
0000AF7B  0000              add [bx+si],al
0000AF7D  0000              add [bx+si],al
0000AF7F  0000              add [bx+si],al
0000AF81  0000              add [bx+si],al
0000AF83  0000              add [bx+si],al
0000AF85  0000              add [bx+si],al
0000AF87  0000              add [bx+si],al
0000AF89  0000              add [bx+si],al
0000AF8B  0000              add [bx+si],al
0000AF8D  0000              add [bx+si],al
0000AF8F  0000              add [bx+si],al
0000AF91  0000              add [bx+si],al
0000AF93  0000              add [bx+si],al
0000AF95  0000              add [bx+si],al
0000AF97  0000              add [bx+si],al
0000AF99  0000              add [bx+si],al
0000AF9B  0000              add [bx+si],al
0000AF9D  0000              add [bx+si],al
0000AF9F  0000              add [bx+si],al
0000AFA1  0000              add [bx+si],al
0000AFA3  0000              add [bx+si],al
0000AFA5  0000              add [bx+si],al
0000AFA7  0000              add [bx+si],al
0000AFA9  0000              add [bx+si],al
0000AFAB  0000              add [bx+si],al
0000AFAD  0000              add [bx+si],al
0000AFAF  0000              add [bx+si],al
0000AFB1  0000              add [bx+si],al
0000AFB3  0000              add [bx+si],al
0000AFB5  0000              add [bx+si],al
0000AFB7  0000              add [bx+si],al
0000AFB9  0000              add [bx+si],al
0000AFBB  0000              add [bx+si],al
0000AFBD  0000              add [bx+si],al
0000AFBF  0000              add [bx+si],al
0000AFC1  0000              add [bx+si],al
0000AFC3  0000              add [bx+si],al
0000AFC5  0000              add [bx+si],al
0000AFC7  0000              add [bx+si],al
0000AFC9  0000              add [bx+si],al
0000AFCB  0000              add [bx+si],al
0000AFCD  0000              add [bx+si],al
0000AFCF  0000              add [bx+si],al
0000AFD1  0000              add [bx+si],al
0000AFD3  0000              add [bx+si],al
0000AFD5  0000              add [bx+si],al
0000AFD7  0000              add [bx+si],al
0000AFD9  0000              add [bx+si],al
0000AFDB  0000              add [bx+si],al
0000AFDD  0000              add [bx+si],al
0000AFDF  0000              add [bx+si],al
0000AFE1  0000              add [bx+si],al
0000AFE3  0000              add [bx+si],al
0000AFE5  0000              add [bx+si],al
0000AFE7  0000              add [bx+si],al
0000AFE9  0000              add [bx+si],al
0000AFEB  0000              add [bx+si],al
0000AFED  0000              add [bx+si],al
0000AFEF  0000              add [bx+si],al
0000AFF1  0000              add [bx+si],al
0000AFF3  0000              add [bx+si],al
0000AFF5  0000              add [bx+si],al
0000AFF7  0000              add [bx+si],al
0000AFF9  0000              add [bx+si],al
0000AFFB  0000              add [bx+si],al
0000AFFD  0000              add [bx+si],al
0000AFFF  0000              add [bx+si],al
0000B001  0000              add [bx+si],al
0000B003  0000              add [bx+si],al
0000B005  0000              add [bx+si],al
0000B007  0000              add [bx+si],al
0000B009  0000              add [bx+si],al
0000B00B  0000              add [bx+si],al
0000B00D  0000              add [bx+si],al
0000B00F  0000              add [bx+si],al
0000B011  0000              add [bx+si],al
0000B013  0000              add [bx+si],al
0000B015  0000              add [bx+si],al
0000B017  0000              add [bx+si],al
0000B019  0000              add [bx+si],al
0000B01B  0000              add [bx+si],al
0000B01D  0000              add [bx+si],al
0000B01F  0000              add [bx+si],al
0000B021  0000              add [bx+si],al
0000B023  0000              add [bx+si],al
0000B025  0000              add [bx+si],al
0000B027  0000              add [bx+si],al
0000B029  0000              add [bx+si],al
0000B02B  0000              add [bx+si],al
0000B02D  0000              add [bx+si],al
0000B02F  0000              add [bx+si],al
0000B031  0000              add [bx+si],al
0000B033  0000              add [bx+si],al
0000B035  0000              add [bx+si],al
0000B037  0000              add [bx+si],al
0000B039  0000              add [bx+si],al
0000B03B  0000              add [bx+si],al
0000B03D  0000              add [bx+si],al
0000B03F  0000              add [bx+si],al
0000B041  0000              add [bx+si],al
0000B043  0000              add [bx+si],al
0000B045  0000              add [bx+si],al
0000B047  0000              add [bx+si],al
0000B049  0000              add [bx+si],al
0000B04B  0000              add [bx+si],al
0000B04D  0000              add [bx+si],al
0000B04F  0000              add [bx+si],al
0000B051  0000              add [bx+si],al
0000B053  0000              add [bx+si],al
0000B055  0000              add [bx+si],al
0000B057  0000              add [bx+si],al
0000B059  0000              add [bx+si],al
0000B05B  0000              add [bx+si],al
0000B05D  0000              add [bx+si],al
0000B05F  0000              add [bx+si],al
0000B061  0000              add [bx+si],al
0000B063  0000              add [bx+si],al
0000B065  0000              add [bx+si],al
0000B067  0000              add [bx+si],al
0000B069  0000              add [bx+si],al
0000B06B  0000              add [bx+si],al
0000B06D  0000              add [bx+si],al
0000B06F  0000              add [bx+si],al
0000B071  0000              add [bx+si],al
0000B073  0000              add [bx+si],al
0000B075  0000              add [bx+si],al
0000B077  0000              add [bx+si],al
0000B079  0000              add [bx+si],al
0000B07B  0000              add [bx+si],al
0000B07D  0000              add [bx+si],al
0000B07F  0000              add [bx+si],al
0000B081  0000              add [bx+si],al
0000B083  0000              add [bx+si],al
0000B085  0000              add [bx+si],al
0000B087  0000              add [bx+si],al
0000B089  0000              add [bx+si],al
0000B08B  0000              add [bx+si],al
0000B08D  0000              add [bx+si],al
0000B08F  0000              add [bx+si],al
0000B091  0000              add [bx+si],al
0000B093  0000              add [bx+si],al
0000B095  0000              add [bx+si],al
0000B097  0000              add [bx+si],al
0000B099  0000              add [bx+si],al
0000B09B  0000              add [bx+si],al
0000B09D  0000              add [bx+si],al
0000B09F  0000              add [bx+si],al
0000B0A1  0000              add [bx+si],al
0000B0A3  0000              add [bx+si],al
0000B0A5  0000              add [bx+si],al
0000B0A7  0000              add [bx+si],al
0000B0A9  0000              add [bx+si],al
0000B0AB  0000              add [bx+si],al
0000B0AD  0000              add [bx+si],al
0000B0AF  0000              add [bx+si],al
0000B0B1  0000              add [bx+si],al
0000B0B3  0000              add [bx+si],al
0000B0B5  0000              add [bx+si],al
0000B0B7  0000              add [bx+si],al
0000B0B9  0000              add [bx+si],al
0000B0BB  0000              add [bx+si],al
0000B0BD  0000              add [bx+si],al
0000B0BF  0000              add [bx+si],al
0000B0C1  0000              add [bx+si],al
0000B0C3  0000              add [bx+si],al
0000B0C5  0000              add [bx+si],al
0000B0C7  0000              add [bx+si],al
0000B0C9  0000              add [bx+si],al
0000B0CB  0000              add [bx+si],al
0000B0CD  0000              add [bx+si],al
0000B0CF  0000              add [bx+si],al
0000B0D1  0000              add [bx+si],al
0000B0D3  0000              add [bx+si],al
0000B0D5  0000              add [bx+si],al
0000B0D7  0000              add [bx+si],al
0000B0D9  0000              add [bx+si],al
0000B0DB  0000              add [bx+si],al
0000B0DD  0000              add [bx+si],al
0000B0DF  0000              add [bx+si],al
0000B0E1  0000              add [bx+si],al
0000B0E3  0000              add [bx+si],al
0000B0E5  0000              add [bx+si],al
0000B0E7  0000              add [bx+si],al
0000B0E9  0000              add [bx+si],al
0000B0EB  0000              add [bx+si],al
0000B0ED  0000              add [bx+si],al
0000B0EF  0000              add [bx+si],al
0000B0F1  0000              add [bx+si],al
0000B0F3  0000              add [bx+si],al
0000B0F5  0000              add [bx+si],al
0000B0F7  0000              add [bx+si],al
0000B0F9  0000              add [bx+si],al
0000B0FB  0000              add [bx+si],al
0000B0FD  0000              add [bx+si],al
0000B0FF  0000              add [bx+si],al
0000B101  0000              add [bx+si],al
0000B103  0000              add [bx+si],al
0000B105  0000              add [bx+si],al
0000B107  0000              add [bx+si],al
0000B109  0000              add [bx+si],al
0000B10B  0000              add [bx+si],al
0000B10D  0000              add [bx+si],al
0000B10F  0000              add [bx+si],al
0000B111  0000              add [bx+si],al
0000B113  0000              add [bx+si],al
0000B115  0000              add [bx+si],al
0000B117  0000              add [bx+si],al
0000B119  0000              add [bx+si],al
0000B11B  0000              add [bx+si],al
0000B11D  0000              add [bx+si],al
0000B11F  0000              add [bx+si],al
0000B121  0000              add [bx+si],al
0000B123  0000              add [bx+si],al
0000B125  0000              add [bx+si],al
0000B127  0000              add [bx+si],al
0000B129  0000              add [bx+si],al
0000B12B  0000              add [bx+si],al
0000B12D  0000              add [bx+si],al
0000B12F  0000              add [bx+si],al
0000B131  0000              add [bx+si],al
0000B133  0000              add [bx+si],al
0000B135  0000              add [bx+si],al
0000B137  0000              add [bx+si],al
0000B139  0000              add [bx+si],al
0000B13B  0000              add [bx+si],al
0000B13D  0000              add [bx+si],al
0000B13F  0000              add [bx+si],al
0000B141  0000              add [bx+si],al
0000B143  0000              add [bx+si],al
0000B145  0000              add [bx+si],al
0000B147  0000              add [bx+si],al
0000B149  0000              add [bx+si],al
0000B14B  0000              add [bx+si],al
0000B14D  0000              add [bx+si],al
0000B14F  0000              add [bx+si],al
0000B151  0000              add [bx+si],al
0000B153  0000              add [bx+si],al
0000B155  0000              add [bx+si],al
0000B157  0000              add [bx+si],al
0000B159  0000              add [bx+si],al
0000B15B  0000              add [bx+si],al
0000B15D  0000              add [bx+si],al
0000B15F  0000              add [bx+si],al
0000B161  0000              add [bx+si],al
0000B163  0000              add [bx+si],al
0000B165  0000              add [bx+si],al
0000B167  0000              add [bx+si],al
0000B169  0000              add [bx+si],al
0000B16B  0000              add [bx+si],al
0000B16D  0000              add [bx+si],al
0000B16F  0000              add [bx+si],al
0000B171  0000              add [bx+si],al
0000B173  0000              add [bx+si],al
0000B175  0000              add [bx+si],al
0000B177  0000              add [bx+si],al
0000B179  0000              add [bx+si],al
0000B17B  0000              add [bx+si],al
0000B17D  0000              add [bx+si],al
0000B17F  0000              add [bx+si],al
0000B181  0000              add [bx+si],al
0000B183  0000              add [bx+si],al
0000B185  0000              add [bx+si],al
0000B187  0000              add [bx+si],al
0000B189  0000              add [bx+si],al
0000B18B  0000              add [bx+si],al
0000B18D  0000              add [bx+si],al
0000B18F  0000              add [bx+si],al
0000B191  0000              add [bx+si],al
0000B193  0000              add [bx+si],al
0000B195  0000              add [bx+si],al
0000B197  0000              add [bx+si],al
0000B199  0000              add [bx+si],al
0000B19B  0000              add [bx+si],al
0000B19D  0000              add [bx+si],al
0000B19F  0000              add [bx+si],al
0000B1A1  0000              add [bx+si],al
0000B1A3  0000              add [bx+si],al
0000B1A5  0000              add [bx+si],al
0000B1A7  0000              add [bx+si],al
0000B1A9  0000              add [bx+si],al
0000B1AB  0000              add [bx+si],al
0000B1AD  0000              add [bx+si],al
0000B1AF  0000              add [bx+si],al
0000B1B1  0000              add [bx+si],al
0000B1B3  0000              add [bx+si],al
0000B1B5  0000              add [bx+si],al
0000B1B7  0000              add [bx+si],al
0000B1B9  0000              add [bx+si],al
0000B1BB  0000              add [bx+si],al
0000B1BD  0000              add [bx+si],al
0000B1BF  0000              add [bx+si],al
0000B1C1  0000              add [bx+si],al
0000B1C3  0000              add [bx+si],al
0000B1C5  0000              add [bx+si],al
0000B1C7  0000              add [bx+si],al
0000B1C9  0000              add [bx+si],al
0000B1CB  0000              add [bx+si],al
0000B1CD  0000              add [bx+si],al
0000B1CF  0000              add [bx+si],al
0000B1D1  0000              add [bx+si],al
0000B1D3  0000              add [bx+si],al
0000B1D5  0000              add [bx+si],al
0000B1D7  0000              add [bx+si],al
0000B1D9  0000              add [bx+si],al
0000B1DB  0000              add [bx+si],al
0000B1DD  0000              add [bx+si],al
0000B1DF  0000              add [bx+si],al
0000B1E1  0000              add [bx+si],al
0000B1E3  0000              add [bx+si],al
0000B1E5  0000              add [bx+si],al
0000B1E7  0000              add [bx+si],al
0000B1E9  0000              add [bx+si],al
0000B1EB  0000              add [bx+si],al
0000B1ED  0000              add [bx+si],al
0000B1EF  0000              add [bx+si],al
0000B1F1  0000              add [bx+si],al
0000B1F3  0000              add [bx+si],al
0000B1F5  0000              add [bx+si],al
0000B1F7  0000              add [bx+si],al
0000B1F9  0000              add [bx+si],al
0000B1FB  0000              add [bx+si],al
0000B1FD  0000              add [bx+si],al
0000B1FF  0000              add [bx+si],al
0000B201  0000              add [bx+si],al
0000B203  0000              add [bx+si],al
0000B205  0000              add [bx+si],al
0000B207  0000              add [bx+si],al
0000B209  0000              add [bx+si],al
0000B20B  0000              add [bx+si],al
0000B20D  0000              add [bx+si],al
0000B20F  0000              add [bx+si],al
0000B211  0000              add [bx+si],al
0000B213  0000              add [bx+si],al
0000B215  0000              add [bx+si],al
0000B217  0000              add [bx+si],al
0000B219  0000              add [bx+si],al
0000B21B  0000              add [bx+si],al
0000B21D  0000              add [bx+si],al
0000B21F  0000              add [bx+si],al
0000B221  0000              add [bx+si],al
0000B223  0000              add [bx+si],al
0000B225  0000              add [bx+si],al
0000B227  0000              add [bx+si],al
0000B229  0000              add [bx+si],al
0000B22B  0000              add [bx+si],al
0000B22D  0000              add [bx+si],al
0000B22F  0000              add [bx+si],al
0000B231  0000              add [bx+si],al
0000B233  0000              add [bx+si],al
0000B235  0000              add [bx+si],al
0000B237  0000              add [bx+si],al
0000B239  0000              add [bx+si],al
0000B23B  0000              add [bx+si],al
0000B23D  0000              add [bx+si],al
0000B23F  0000              add [bx+si],al
0000B241  0000              add [bx+si],al
0000B243  0000              add [bx+si],al
0000B245  0000              add [bx+si],al
0000B247  0000              add [bx+si],al
0000B249  0000              add [bx+si],al
0000B24B  0000              add [bx+si],al
0000B24D  0000              add [bx+si],al
0000B24F  0000              add [bx+si],al
0000B251  0000              add [bx+si],al
0000B253  0000              add [bx+si],al
0000B255  0000              add [bx+si],al
0000B257  0000              add [bx+si],al
0000B259  0000              add [bx+si],al
0000B25B  0000              add [bx+si],al
0000B25D  0000              add [bx+si],al
0000B25F  0000              add [bx+si],al
0000B261  0000              add [bx+si],al
0000B263  0000              add [bx+si],al
0000B265  0000              add [bx+si],al
0000B267  0000              add [bx+si],al
0000B269  0000              add [bx+si],al
0000B26B  0000              add [bx+si],al
0000B26D  0000              add [bx+si],al
0000B26F  0000              add [bx+si],al
0000B271  0000              add [bx+si],al
0000B273  0000              add [bx+si],al
0000B275  0000              add [bx+si],al
0000B277  0000              add [bx+si],al
0000B279  0000              add [bx+si],al
0000B27B  0000              add [bx+si],al
0000B27D  0000              add [bx+si],al
0000B27F  0000              add [bx+si],al
0000B281  0000              add [bx+si],al
0000B283  0000              add [bx+si],al
0000B285  0000              add [bx+si],al
0000B287  0000              add [bx+si],al
0000B289  0000              add [bx+si],al
0000B28B  0000              add [bx+si],al
0000B28D  0000              add [bx+si],al
0000B28F  0000              add [bx+si],al
0000B291  0000              add [bx+si],al
0000B293  0000              add [bx+si],al
0000B295  0000              add [bx+si],al
0000B297  0000              add [bx+si],al
0000B299  0000              add [bx+si],al
0000B29B  0000              add [bx+si],al
0000B29D  0000              add [bx+si],al
0000B29F  0000              add [bx+si],al
0000B2A1  0000              add [bx+si],al
0000B2A3  0000              add [bx+si],al
0000B2A5  0000              add [bx+si],al
0000B2A7  0000              add [bx+si],al
0000B2A9  0000              add [bx+si],al
0000B2AB  0000              add [bx+si],al
0000B2AD  0000              add [bx+si],al
0000B2AF  0000              add [bx+si],al
0000B2B1  0000              add [bx+si],al
0000B2B3  0000              add [bx+si],al
0000B2B5  0000              add [bx+si],al
0000B2B7  0000              add [bx+si],al
0000B2B9  0000              add [bx+si],al
0000B2BB  0000              add [bx+si],al
0000B2BD  0000              add [bx+si],al
0000B2BF  0000              add [bx+si],al
0000B2C1  0000              add [bx+si],al
0000B2C3  0000              add [bx+si],al
0000B2C5  0000              add [bx+si],al
0000B2C7  0000              add [bx+si],al
0000B2C9  0000              add [bx+si],al
0000B2CB  0000              add [bx+si],al
0000B2CD  0000              add [bx+si],al
0000B2CF  0000              add [bx+si],al
0000B2D1  0000              add [bx+si],al
0000B2D3  0000              add [bx+si],al
0000B2D5  0000              add [bx+si],al
0000B2D7  0000              add [bx+si],al
0000B2D9  0000              add [bx+si],al
0000B2DB  0000              add [bx+si],al
0000B2DD  0000              add [bx+si],al
0000B2DF  0000              add [bx+si],al
0000B2E1  0000              add [bx+si],al
0000B2E3  0000              add [bx+si],al
0000B2E5  0000              add [bx+si],al
0000B2E7  0000              add [bx+si],al
0000B2E9  0000              add [bx+si],al
0000B2EB  0000              add [bx+si],al
0000B2ED  0000              add [bx+si],al
0000B2EF  0000              add [bx+si],al
0000B2F1  0000              add [bx+si],al
0000B2F3  0000              add [bx+si],al
0000B2F5  0000              add [bx+si],al
0000B2F7  0000              add [bx+si],al
0000B2F9  0000              add [bx+si],al
0000B2FB  0000              add [bx+si],al
0000B2FD  0000              add [bx+si],al
0000B2FF  0000              add [bx+si],al
0000B301  0000              add [bx+si],al
0000B303  0000              add [bx+si],al
0000B305  0000              add [bx+si],al
0000B307  0000              add [bx+si],al
0000B309  0000              add [bx+si],al
0000B30B  0000              add [bx+si],al
0000B30D  0000              add [bx+si],al
0000B30F  0000              add [bx+si],al
0000B311  0000              add [bx+si],al
0000B313  0000              add [bx+si],al
0000B315  0000              add [bx+si],al
0000B317  0000              add [bx+si],al
0000B319  0000              add [bx+si],al
0000B31B  0000              add [bx+si],al
0000B31D  0000              add [bx+si],al
0000B31F  0000              add [bx+si],al
0000B321  0000              add [bx+si],al
0000B323  0000              add [bx+si],al
0000B325  0000              add [bx+si],al
0000B327  0000              add [bx+si],al
0000B329  0000              add [bx+si],al
0000B32B  0000              add [bx+si],al
0000B32D  0000              add [bx+si],al
0000B32F  0000              add [bx+si],al
0000B331  0000              add [bx+si],al
0000B333  0000              add [bx+si],al
0000B335  0000              add [bx+si],al
0000B337  0000              add [bx+si],al
0000B339  0000              add [bx+si],al
0000B33B  0000              add [bx+si],al
0000B33D  0000              add [bx+si],al
0000B33F  0000              add [bx+si],al
0000B341  0000              add [bx+si],al
0000B343  0000              add [bx+si],al
0000B345  0000              add [bx+si],al
0000B347  0000              add [bx+si],al
0000B349  0000              add [bx+si],al
0000B34B  0000              add [bx+si],al
0000B34D  0000              add [bx+si],al
0000B34F  0000              add [bx+si],al
0000B351  0000              add [bx+si],al
0000B353  0000              add [bx+si],al
0000B355  0000              add [bx+si],al
0000B357  0000              add [bx+si],al
0000B359  0000              add [bx+si],al
0000B35B  0000              add [bx+si],al
0000B35D  0000              add [bx+si],al
0000B35F  0000              add [bx+si],al
0000B361  0000              add [bx+si],al
0000B363  0000              add [bx+si],al
0000B365  0000              add [bx+si],al
0000B367  0000              add [bx+si],al
0000B369  0000              add [bx+si],al
0000B36B  0000              add [bx+si],al
0000B36D  0000              add [bx+si],al
0000B36F  0000              add [bx+si],al
0000B371  0000              add [bx+si],al
0000B373  0000              add [bx+si],al
0000B375  0000              add [bx+si],al
0000B377  0000              add [bx+si],al
0000B379  0000              add [bx+si],al
0000B37B  0000              add [bx+si],al
0000B37D  0000              add [bx+si],al
0000B37F  0000              add [bx+si],al
0000B381  0000              add [bx+si],al
0000B383  0000              add [bx+si],al
0000B385  0000              add [bx+si],al
0000B387  0000              add [bx+si],al
0000B389  0000              add [bx+si],al
0000B38B  0000              add [bx+si],al
0000B38D  0000              add [bx+si],al
0000B38F  0000              add [bx+si],al
0000B391  0000              add [bx+si],al
0000B393  0000              add [bx+si],al
0000B395  0000              add [bx+si],al
0000B397  0000              add [bx+si],al
0000B399  0000              add [bx+si],al
0000B39B  0000              add [bx+si],al
0000B39D  0000              add [bx+si],al
0000B39F  0000              add [bx+si],al
0000B3A1  0000              add [bx+si],al
0000B3A3  0000              add [bx+si],al
0000B3A5  0000              add [bx+si],al
0000B3A7  0000              add [bx+si],al
0000B3A9  0000              add [bx+si],al
0000B3AB  0000              add [bx+si],al
0000B3AD  0000              add [bx+si],al
0000B3AF  0000              add [bx+si],al
0000B3B1  0000              add [bx+si],al
0000B3B3  0000              add [bx+si],al
0000B3B5  0000              add [bx+si],al
0000B3B7  0000              add [bx+si],al
0000B3B9  0000              add [bx+si],al
0000B3BB  0000              add [bx+si],al
0000B3BD  0000              add [bx+si],al
0000B3BF  0000              add [bx+si],al
0000B3C1  0000              add [bx+si],al
0000B3C3  0000              add [bx+si],al
0000B3C5  0000              add [bx+si],al
0000B3C7  0000              add [bx+si],al
0000B3C9  0000              add [bx+si],al
0000B3CB  0000              add [bx+si],al
0000B3CD  0000              add [bx+si],al
0000B3CF  0000              add [bx+si],al
0000B3D1  0000              add [bx+si],al
0000B3D3  0000              add [bx+si],al
0000B3D5  0000              add [bx+si],al
0000B3D7  0000              add [bx+si],al
0000B3D9  0000              add [bx+si],al
0000B3DB  0000              add [bx+si],al
0000B3DD  0000              add [bx+si],al
0000B3DF  0000              add [bx+si],al
0000B3E1  0000              add [bx+si],al
0000B3E3  0000              add [bx+si],al
0000B3E5  0000              add [bx+si],al
0000B3E7  0000              add [bx+si],al
0000B3E9  0000              add [bx+si],al
0000B3EB  0000              add [bx+si],al
0000B3ED  0000              add [bx+si],al
0000B3EF  0000              add [bx+si],al
0000B3F1  0000              add [bx+si],al
0000B3F3  0000              add [bx+si],al
0000B3F5  0000              add [bx+si],al
0000B3F7  0000              add [bx+si],al
0000B3F9  0000              add [bx+si],al
0000B3FB  0000              add [bx+si],al
0000B3FD  0000              add [bx+si],al
0000B3FF  0000              add [bx+si],al
0000B401  0000              add [bx+si],al
0000B403  0000              add [bx+si],al
0000B405  0000              add [bx+si],al
0000B407  0000              add [bx+si],al
0000B409  0000              add [bx+si],al
0000B40B  0000              add [bx+si],al
0000B40D  0000              add [bx+si],al
0000B40F  0000              add [bx+si],al
0000B411  0000              add [bx+si],al
0000B413  0000              add [bx+si],al
0000B415  0000              add [bx+si],al
0000B417  0000              add [bx+si],al
0000B419  0000              add [bx+si],al
0000B41B  0000              add [bx+si],al
0000B41D  0000              add [bx+si],al
0000B41F  0000              add [bx+si],al
0000B421  0000              add [bx+si],al
0000B423  0000              add [bx+si],al
0000B425  0000              add [bx+si],al
0000B427  0000              add [bx+si],al
0000B429  0000              add [bx+si],al
0000B42B  0000              add [bx+si],al
0000B42D  0000              add [bx+si],al
0000B42F  0000              add [bx+si],al
0000B431  0000              add [bx+si],al
0000B433  0000              add [bx+si],al
0000B435  0000              add [bx+si],al
0000B437  0000              add [bx+si],al
0000B439  0000              add [bx+si],al
0000B43B  0000              add [bx+si],al
0000B43D  0000              add [bx+si],al
0000B43F  0000              add [bx+si],al
0000B441  0000              add [bx+si],al
0000B443  0000              add [bx+si],al
0000B445  0000              add [bx+si],al
0000B447  0000              add [bx+si],al
0000B449  0000              add [bx+si],al
0000B44B  0000              add [bx+si],al
0000B44D  0000              add [bx+si],al
0000B44F  0000              add [bx+si],al
0000B451  0000              add [bx+si],al
0000B453  0000              add [bx+si],al
0000B455  0000              add [bx+si],al
0000B457  0000              add [bx+si],al
0000B459  0000              add [bx+si],al
0000B45B  0000              add [bx+si],al
0000B45D  0000              add [bx+si],al
0000B45F  0000              add [bx+si],al
0000B461  0000              add [bx+si],al
0000B463  0000              add [bx+si],al
0000B465  0000              add [bx+si],al
0000B467  0000              add [bx+si],al
0000B469  0000              add [bx+si],al
0000B46B  0000              add [bx+si],al
0000B46D  0000              add [bx+si],al
0000B46F  0000              add [bx+si],al
0000B471  0000              add [bx+si],al
0000B473  0000              add [bx+si],al
0000B475  0000              add [bx+si],al
0000B477  0000              add [bx+si],al
0000B479  0000              add [bx+si],al
0000B47B  0000              add [bx+si],al
0000B47D  0000              add [bx+si],al
0000B47F  0000              add [bx+si],al
0000B481  0000              add [bx+si],al
0000B483  0000              add [bx+si],al
0000B485  0000              add [bx+si],al
0000B487  0000              add [bx+si],al
0000B489  0000              add [bx+si],al
0000B48B  0000              add [bx+si],al
0000B48D  0000              add [bx+si],al
0000B48F  0000              add [bx+si],al
0000B491  0000              add [bx+si],al
0000B493  0000              add [bx+si],al
0000B495  0000              add [bx+si],al
0000B497  0000              add [bx+si],al
0000B499  0000              add [bx+si],al
0000B49B  0000              add [bx+si],al
0000B49D  0000              add [bx+si],al
0000B49F  0000              add [bx+si],al
0000B4A1  0000              add [bx+si],al
0000B4A3  0000              add [bx+si],al
0000B4A5  0000              add [bx+si],al
0000B4A7  0000              add [bx+si],al
0000B4A9  0000              add [bx+si],al
0000B4AB  0000              add [bx+si],al
0000B4AD  0000              add [bx+si],al
0000B4AF  0000              add [bx+si],al
0000B4B1  0000              add [bx+si],al
0000B4B3  0000              add [bx+si],al
0000B4B5  0000              add [bx+si],al
0000B4B7  0000              add [bx+si],al
0000B4B9  0000              add [bx+si],al
0000B4BB  0000              add [bx+si],al
0000B4BD  0000              add [bx+si],al
0000B4BF  0000              add [bx+si],al
0000B4C1  0000              add [bx+si],al
0000B4C3  0000              add [bx+si],al
0000B4C5  0000              add [bx+si],al
0000B4C7  0000              add [bx+si],al
0000B4C9  0000              add [bx+si],al
0000B4CB  0000              add [bx+si],al
0000B4CD  0000              add [bx+si],al
0000B4CF  0000              add [bx+si],al
0000B4D1  0000              add [bx+si],al
0000B4D3  0000              add [bx+si],al
0000B4D5  0000              add [bx+si],al
0000B4D7  0000              add [bx+si],al
0000B4D9  0000              add [bx+si],al
0000B4DB  0000              add [bx+si],al
0000B4DD  0000              add [bx+si],al
0000B4DF  0000              add [bx+si],al
0000B4E1  0000              add [bx+si],al
0000B4E3  0000              add [bx+si],al
0000B4E5  0000              add [bx+si],al
0000B4E7  0000              add [bx+si],al
0000B4E9  0000              add [bx+si],al
0000B4EB  0000              add [bx+si],al
0000B4ED  0000              add [bx+si],al
0000B4EF  0000              add [bx+si],al
0000B4F1  0000              add [bx+si],al
0000B4F3  0000              add [bx+si],al
0000B4F5  0000              add [bx+si],al
0000B4F7  0000              add [bx+si],al
0000B4F9  0000              add [bx+si],al
0000B4FB  0000              add [bx+si],al
0000B4FD  0000              add [bx+si],al
0000B4FF  0000              add [bx+si],al
0000B501  0000              add [bx+si],al
0000B503  0000              add [bx+si],al
0000B505  0000              add [bx+si],al
0000B507  0000              add [bx+si],al
0000B509  0000              add [bx+si],al
0000B50B  0000              add [bx+si],al
0000B50D  0000              add [bx+si],al
0000B50F  0000              add [bx+si],al
0000B511  0000              add [bx+si],al
0000B513  0000              add [bx+si],al
0000B515  0000              add [bx+si],al
0000B517  0000              add [bx+si],al
0000B519  0000              add [bx+si],al
0000B51B  0000              add [bx+si],al
0000B51D  0000              add [bx+si],al
0000B51F  0000              add [bx+si],al
0000B521  0000              add [bx+si],al
0000B523  0000              add [bx+si],al
0000B525  0000              add [bx+si],al
0000B527  0000              add [bx+si],al
0000B529  0000              add [bx+si],al
0000B52B  0000              add [bx+si],al
0000B52D  0000              add [bx+si],al
0000B52F  0000              add [bx+si],al
0000B531  0000              add [bx+si],al
0000B533  0000              add [bx+si],al
0000B535  0000              add [bx+si],al
0000B537  0000              add [bx+si],al
0000B539  0000              add [bx+si],al
0000B53B  0000              add [bx+si],al
0000B53D  0000              add [bx+si],al
0000B53F  0000              add [bx+si],al
0000B541  0000              add [bx+si],al
0000B543  0000              add [bx+si],al
0000B545  0000              add [bx+si],al
0000B547  0000              add [bx+si],al
0000B549  0000              add [bx+si],al
0000B54B  0000              add [bx+si],al
0000B54D  0000              add [bx+si],al
0000B54F  0000              add [bx+si],al
0000B551  0000              add [bx+si],al
0000B553  0000              add [bx+si],al
0000B555  0000              add [bx+si],al
0000B557  0000              add [bx+si],al
0000B559  0000              add [bx+si],al
0000B55B  0000              add [bx+si],al
0000B55D  0000              add [bx+si],al
0000B55F  0000              add [bx+si],al
0000B561  0000              add [bx+si],al
0000B563  0000              add [bx+si],al
0000B565  0000              add [bx+si],al
0000B567  0000              add [bx+si],al
0000B569  0000              add [bx+si],al
0000B56B  0000              add [bx+si],al
0000B56D  0000              add [bx+si],al
0000B56F  0000              add [bx+si],al
0000B571  0000              add [bx+si],al
0000B573  0000              add [bx+si],al
0000B575  0000              add [bx+si],al
0000B577  0000              add [bx+si],al
0000B579  0000              add [bx+si],al
0000B57B  0000              add [bx+si],al
0000B57D  0000              add [bx+si],al
0000B57F  0000              add [bx+si],al
0000B581  0000              add [bx+si],al
0000B583  0000              add [bx+si],al
0000B585  0000              add [bx+si],al
0000B587  0000              add [bx+si],al
0000B589  0000              add [bx+si],al
0000B58B  0000              add [bx+si],al
0000B58D  0000              add [bx+si],al
0000B58F  0000              add [bx+si],al
0000B591  0000              add [bx+si],al
0000B593  0000              add [bx+si],al
0000B595  0000              add [bx+si],al
0000B597  0000              add [bx+si],al
0000B599  0000              add [bx+si],al
0000B59B  0000              add [bx+si],al
0000B59D  0000              add [bx+si],al
0000B59F  0000              add [bx+si],al
0000B5A1  0000              add [bx+si],al
0000B5A3  0000              add [bx+si],al
0000B5A5  0000              add [bx+si],al
0000B5A7  0000              add [bx+si],al
0000B5A9  0000              add [bx+si],al
0000B5AB  0000              add [bx+si],al
0000B5AD  0000              add [bx+si],al
0000B5AF  0000              add [bx+si],al
0000B5B1  0000              add [bx+si],al
0000B5B3  0000              add [bx+si],al
0000B5B5  0000              add [bx+si],al
0000B5B7  0000              add [bx+si],al
0000B5B9  0000              add [bx+si],al
0000B5BB  0000              add [bx+si],al
0000B5BD  0000              add [bx+si],al
0000B5BF  0000              add [bx+si],al
0000B5C1  0000              add [bx+si],al
0000B5C3  0000              add [bx+si],al
0000B5C5  0000              add [bx+si],al
0000B5C7  0000              add [bx+si],al
0000B5C9  0000              add [bx+si],al
0000B5CB  0000              add [bx+si],al
0000B5CD  0000              add [bx+si],al
0000B5CF  0000              add [bx+si],al
0000B5D1  0000              add [bx+si],al
0000B5D3  0000              add [bx+si],al
0000B5D5  0000              add [bx+si],al
0000B5D7  0000              add [bx+si],al
0000B5D9  0000              add [bx+si],al
0000B5DB  0000              add [bx+si],al
0000B5DD  0000              add [bx+si],al
0000B5DF  0000              add [bx+si],al
0000B5E1  0000              add [bx+si],al
0000B5E3  0000              add [bx+si],al
0000B5E5  0000              add [bx+si],al
0000B5E7  0000              add [bx+si],al
0000B5E9  0000              add [bx+si],al
0000B5EB  0000              add [bx+si],al
0000B5ED  0000              add [bx+si],al
0000B5EF  0000              add [bx+si],al
0000B5F1  0000              add [bx+si],al
0000B5F3  0000              add [bx+si],al
0000B5F5  0000              add [bx+si],al
0000B5F7  0000              add [bx+si],al
0000B5F9  0000              add [bx+si],al
0000B5FB  0000              add [bx+si],al
0000B5FD  0000              add [bx+si],al
0000B5FF  0000              add [bx+si],al
0000B601  0000              add [bx+si],al
0000B603  0000              add [bx+si],al
0000B605  0000              add [bx+si],al
0000B607  0000              add [bx+si],al
0000B609  0000              add [bx+si],al
0000B60B  0000              add [bx+si],al
0000B60D  0000              add [bx+si],al
0000B60F  0000              add [bx+si],al
0000B611  0000              add [bx+si],al
0000B613  0000              add [bx+si],al
0000B615  0000              add [bx+si],al
0000B617  0000              add [bx+si],al
0000B619  0000              add [bx+si],al
0000B61B  0000              add [bx+si],al
0000B61D  0000              add [bx+si],al
0000B61F  0000              add [bx+si],al
0000B621  0000              add [bx+si],al
0000B623  0000              add [bx+si],al
0000B625  0000              add [bx+si],al
0000B627  0000              add [bx+si],al
0000B629  0000              add [bx+si],al
0000B62B  0000              add [bx+si],al
0000B62D  0000              add [bx+si],al
0000B62F  0000              add [bx+si],al
0000B631  0000              add [bx+si],al
0000B633  0000              add [bx+si],al
0000B635  0000              add [bx+si],al
0000B637  0000              add [bx+si],al
0000B639  0000              add [bx+si],al
0000B63B  0000              add [bx+si],al
0000B63D  0000              add [bx+si],al
0000B63F  0000              add [bx+si],al
0000B641  0000              add [bx+si],al
0000B643  0000              add [bx+si],al
0000B645  0000              add [bx+si],al
0000B647  0000              add [bx+si],al
0000B649  0000              add [bx+si],al
0000B64B  0000              add [bx+si],al
0000B64D  0000              add [bx+si],al
0000B64F  0000              add [bx+si],al
0000B651  0000              add [bx+si],al
0000B653  0000              add [bx+si],al
0000B655  0000              add [bx+si],al
0000B657  0000              add [bx+si],al
0000B659  0000              add [bx+si],al
0000B65B  0000              add [bx+si],al
0000B65D  0000              add [bx+si],al
0000B65F  0000              add [bx+si],al
0000B661  0000              add [bx+si],al
0000B663  0000              add [bx+si],al
0000B665  0000              add [bx+si],al
0000B667  0000              add [bx+si],al
0000B669  0000              add [bx+si],al
0000B66B  0000              add [bx+si],al
0000B66D  0000              add [bx+si],al
0000B66F  0000              add [bx+si],al
0000B671  0000              add [bx+si],al
0000B673  0000              add [bx+si],al
0000B675  0000              add [bx+si],al
0000B677  0000              add [bx+si],al
0000B679  0000              add [bx+si],al
0000B67B  0000              add [bx+si],al
0000B67D  0000              add [bx+si],al
0000B67F  0000              add [bx+si],al
0000B681  0000              add [bx+si],al
0000B683  0000              add [bx+si],al
0000B685  0000              add [bx+si],al
0000B687  0000              add [bx+si],al
0000B689  0000              add [bx+si],al
0000B68B  0000              add [bx+si],al
0000B68D  0000              add [bx+si],al
0000B68F  0000              add [bx+si],al
0000B691  0000              add [bx+si],al
0000B693  0000              add [bx+si],al
0000B695  0000              add [bx+si],al
0000B697  0000              add [bx+si],al
0000B699  0000              add [bx+si],al
0000B69B  0000              add [bx+si],al
0000B69D  0000              add [bx+si],al
0000B69F  0000              add [bx+si],al
0000B6A1  0000              add [bx+si],al
0000B6A3  0000              add [bx+si],al
0000B6A5  0000              add [bx+si],al
0000B6A7  0000              add [bx+si],al
0000B6A9  0000              add [bx+si],al
0000B6AB  0000              add [bx+si],al
0000B6AD  0000              add [bx+si],al
0000B6AF  0000              add [bx+si],al
0000B6B1  0000              add [bx+si],al
0000B6B3  0000              add [bx+si],al
0000B6B5  0000              add [bx+si],al
0000B6B7  0000              add [bx+si],al
0000B6B9  0000              add [bx+si],al
0000B6BB  0000              add [bx+si],al
0000B6BD  0000              add [bx+si],al
0000B6BF  0000              add [bx+si],al
0000B6C1  0000              add [bx+si],al
0000B6C3  0000              add [bx+si],al
0000B6C5  0000              add [bx+si],al
0000B6C7  0000              add [bx+si],al
0000B6C9  0000              add [bx+si],al
0000B6CB  0000              add [bx+si],al
0000B6CD  0000              add [bx+si],al
0000B6CF  0000              add [bx+si],al
0000B6D1  0000              add [bx+si],al
0000B6D3  0000              add [bx+si],al
0000B6D5  0000              add [bx+si],al
0000B6D7  0000              add [bx+si],al
0000B6D9  0000              add [bx+si],al
0000B6DB  0000              add [bx+si],al
0000B6DD  0000              add [bx+si],al
0000B6DF  0000              add [bx+si],al
0000B6E1  0000              add [bx+si],al
0000B6E3  0000              add [bx+si],al
0000B6E5  0000              add [bx+si],al
0000B6E7  0000              add [bx+si],al
0000B6E9  0000              add [bx+si],al
0000B6EB  0000              add [bx+si],al
0000B6ED  0000              add [bx+si],al
0000B6EF  0000              add [bx+si],al
0000B6F1  0000              add [bx+si],al
0000B6F3  0000              add [bx+si],al
0000B6F5  0000              add [bx+si],al
0000B6F7  0000              add [bx+si],al
0000B6F9  0000              add [bx+si],al
0000B6FB  0000              add [bx+si],al
0000B6FD  0000              add [bx+si],al
0000B6FF  0000              add [bx+si],al
0000B701  0000              add [bx+si],al
0000B703  0000              add [bx+si],al
0000B705  0000              add [bx+si],al
0000B707  0000              add [bx+si],al
0000B709  0000              add [bx+si],al
0000B70B  0000              add [bx+si],al
0000B70D  0000              add [bx+si],al
0000B70F  0000              add [bx+si],al
0000B711  0000              add [bx+si],al
0000B713  0000              add [bx+si],al
0000B715  0000              add [bx+si],al
0000B717  0000              add [bx+si],al
0000B719  0000              add [bx+si],al
0000B71B  0000              add [bx+si],al
0000B71D  0000              add [bx+si],al
0000B71F  0000              add [bx+si],al
0000B721  0000              add [bx+si],al
0000B723  0000              add [bx+si],al
0000B725  0000              add [bx+si],al
0000B727  0000              add [bx+si],al
0000B729  0000              add [bx+si],al
0000B72B  0000              add [bx+si],al
0000B72D  0000              add [bx+si],al
0000B72F  0000              add [bx+si],al
0000B731  0000              add [bx+si],al
0000B733  0000              add [bx+si],al
0000B735  0000              add [bx+si],al
0000B737  0000              add [bx+si],al
0000B739  0000              add [bx+si],al
0000B73B  0000              add [bx+si],al
0000B73D  0000              add [bx+si],al
0000B73F  0000              add [bx+si],al
0000B741  0000              add [bx+si],al
0000B743  0000              add [bx+si],al
0000B745  0000              add [bx+si],al
0000B747  0000              add [bx+si],al
0000B749  0000              add [bx+si],al
0000B74B  0000              add [bx+si],al
0000B74D  0000              add [bx+si],al
0000B74F  0000              add [bx+si],al
0000B751  0000              add [bx+si],al
0000B753  0000              add [bx+si],al
0000B755  0000              add [bx+si],al
0000B757  0000              add [bx+si],al
0000B759  0000              add [bx+si],al
0000B75B  0000              add [bx+si],al
0000B75D  0000              add [bx+si],al
0000B75F  0000              add [bx+si],al
0000B761  0000              add [bx+si],al
0000B763  0000              add [bx+si],al
0000B765  0000              add [bx+si],al
0000B767  0000              add [bx+si],al
0000B769  0000              add [bx+si],al
0000B76B  0000              add [bx+si],al
0000B76D  0000              add [bx+si],al
0000B76F  0000              add [bx+si],al
0000B771  0000              add [bx+si],al
0000B773  0000              add [bx+si],al
0000B775  0000              add [bx+si],al
0000B777  0000              add [bx+si],al
0000B779  0000              add [bx+si],al
0000B77B  0000              add [bx+si],al
0000B77D  0000              add [bx+si],al
0000B77F  0000              add [bx+si],al
0000B781  0000              add [bx+si],al
0000B783  0000              add [bx+si],al
0000B785  0000              add [bx+si],al
0000B787  0000              add [bx+si],al
0000B789  0000              add [bx+si],al
0000B78B  0000              add [bx+si],al
0000B78D  0000              add [bx+si],al
0000B78F  0000              add [bx+si],al
0000B791  0000              add [bx+si],al
0000B793  0000              add [bx+si],al
0000B795  0000              add [bx+si],al
0000B797  0000              add [bx+si],al
0000B799  0000              add [bx+si],al
0000B79B  0000              add [bx+si],al
0000B79D  0000              add [bx+si],al
0000B79F  0000              add [bx+si],al
0000B7A1  0000              add [bx+si],al
0000B7A3  0000              add [bx+si],al
0000B7A5  0000              add [bx+si],al
0000B7A7  0000              add [bx+si],al
0000B7A9  0000              add [bx+si],al
0000B7AB  0000              add [bx+si],al
0000B7AD  0000              add [bx+si],al
0000B7AF  0000              add [bx+si],al
0000B7B1  0000              add [bx+si],al
0000B7B3  0000              add [bx+si],al
0000B7B5  0000              add [bx+si],al
0000B7B7  0000              add [bx+si],al
0000B7B9  0000              add [bx+si],al
0000B7BB  0000              add [bx+si],al
0000B7BD  0000              add [bx+si],al
0000B7BF  0000              add [bx+si],al
0000B7C1  0000              add [bx+si],al
0000B7C3  0000              add [bx+si],al
0000B7C5  0000              add [bx+si],al
0000B7C7  0000              add [bx+si],al
0000B7C9  0000              add [bx+si],al
0000B7CB  0000              add [bx+si],al
0000B7CD  0000              add [bx+si],al
0000B7CF  0000              add [bx+si],al
0000B7D1  0000              add [bx+si],al
0000B7D3  0000              add [bx+si],al
0000B7D5  0000              add [bx+si],al
0000B7D7  0000              add [bx+si],al
0000B7D9  0000              add [bx+si],al
0000B7DB  0000              add [bx+si],al
0000B7DD  0000              add [bx+si],al
0000B7DF  0000              add [bx+si],al
0000B7E1  0000              add [bx+si],al
0000B7E3  0000              add [bx+si],al
0000B7E5  0000              add [bx+si],al
0000B7E7  0000              add [bx+si],al
0000B7E9  0000              add [bx+si],al
0000B7EB  0000              add [bx+si],al
0000B7ED  0000              add [bx+si],al
0000B7EF  0000              add [bx+si],al
0000B7F1  0000              add [bx+si],al
0000B7F3  0000              add [bx+si],al
0000B7F5  0000              add [bx+si],al
0000B7F7  0000              add [bx+si],al
0000B7F9  0000              add [bx+si],al
0000B7FB  0000              add [bx+si],al
0000B7FD  0000              add [bx+si],al
0000B7FF  0000              add [bx+si],al
0000B801  0000              add [bx+si],al
0000B803  0000              add [bx+si],al
0000B805  0000              add [bx+si],al
0000B807  0000              add [bx+si],al
0000B809  0000              add [bx+si],al
0000B80B  0000              add [bx+si],al
0000B80D  0000              add [bx+si],al
0000B80F  0000              add [bx+si],al
0000B811  0000              add [bx+si],al
0000B813  0000              add [bx+si],al
0000B815  0000              add [bx+si],al
0000B817  0000              add [bx+si],al
0000B819  0000              add [bx+si],al
0000B81B  0000              add [bx+si],al
0000B81D  0000              add [bx+si],al
0000B81F  0000              add [bx+si],al
0000B821  0000              add [bx+si],al
0000B823  0000              add [bx+si],al
0000B825  0000              add [bx+si],al
0000B827  0000              add [bx+si],al
0000B829  0000              add [bx+si],al
0000B82B  0000              add [bx+si],al
0000B82D  0000              add [bx+si],al
0000B82F  0000              add [bx+si],al
0000B831  0000              add [bx+si],al
0000B833  0000              add [bx+si],al
0000B835  0000              add [bx+si],al
0000B837  0000              add [bx+si],al
0000B839  0000              add [bx+si],al
0000B83B  0000              add [bx+si],al
0000B83D  0000              add [bx+si],al
0000B83F  0000              add [bx+si],al
0000B841  0000              add [bx+si],al
0000B843  0000              add [bx+si],al
0000B845  0000              add [bx+si],al
0000B847  0000              add [bx+si],al
0000B849  0000              add [bx+si],al
0000B84B  0000              add [bx+si],al
0000B84D  0000              add [bx+si],al
0000B84F  0000              add [bx+si],al
0000B851  0000              add [bx+si],al
0000B853  0000              add [bx+si],al
0000B855  0000              add [bx+si],al
0000B857  0000              add [bx+si],al
0000B859  0000              add [bx+si],al
0000B85B  0000              add [bx+si],al
0000B85D  0000              add [bx+si],al
0000B85F  0000              add [bx+si],al
0000B861  0000              add [bx+si],al
0000B863  0000              add [bx+si],al
0000B865  0000              add [bx+si],al
0000B867  0000              add [bx+si],al
0000B869  0000              add [bx+si],al
0000B86B  0000              add [bx+si],al
0000B86D  0000              add [bx+si],al
0000B86F  0000              add [bx+si],al
0000B871  0000              add [bx+si],al
0000B873  0000              add [bx+si],al
0000B875  0000              add [bx+si],al
0000B877  0000              add [bx+si],al
0000B879  0000              add [bx+si],al
0000B87B  0000              add [bx+si],al
0000B87D  0000              add [bx+si],al
0000B87F  0000              add [bx+si],al
0000B881  0000              add [bx+si],al
0000B883  0000              add [bx+si],al
0000B885  0000              add [bx+si],al
0000B887  0000              add [bx+si],al
0000B889  0000              add [bx+si],al
0000B88B  0000              add [bx+si],al
0000B88D  0000              add [bx+si],al
0000B88F  0000              add [bx+si],al
0000B891  0000              add [bx+si],al
0000B893  0000              add [bx+si],al
0000B895  0000              add [bx+si],al
0000B897  0000              add [bx+si],al
0000B899  0000              add [bx+si],al
0000B89B  0000              add [bx+si],al
0000B89D  0000              add [bx+si],al
0000B89F  0000              add [bx+si],al
0000B8A1  0000              add [bx+si],al
0000B8A3  0000              add [bx+si],al
0000B8A5  0000              add [bx+si],al
0000B8A7  0000              add [bx+si],al
0000B8A9  0000              add [bx+si],al
0000B8AB  0000              add [bx+si],al
0000B8AD  0000              add [bx+si],al
0000B8AF  0000              add [bx+si],al
0000B8B1  0000              add [bx+si],al
0000B8B3  0000              add [bx+si],al
0000B8B5  0000              add [bx+si],al
0000B8B7  0000              add [bx+si],al
0000B8B9  0000              add [bx+si],al
0000B8BB  0000              add [bx+si],al
0000B8BD  0000              add [bx+si],al
0000B8BF  0000              add [bx+si],al
0000B8C1  0000              add [bx+si],al
0000B8C3  0000              add [bx+si],al
0000B8C5  0000              add [bx+si],al
0000B8C7  0000              add [bx+si],al
0000B8C9  0000              add [bx+si],al
0000B8CB  0000              add [bx+si],al
0000B8CD  0000              add [bx+si],al
0000B8CF  0000              add [bx+si],al
0000B8D1  0000              add [bx+si],al
0000B8D3  0000              add [bx+si],al
0000B8D5  0000              add [bx+si],al
0000B8D7  0000              add [bx+si],al
0000B8D9  0000              add [bx+si],al
0000B8DB  0000              add [bx+si],al
0000B8DD  0000              add [bx+si],al
0000B8DF  0000              add [bx+si],al
0000B8E1  0000              add [bx+si],al
0000B8E3  0000              add [bx+si],al
0000B8E5  0000              add [bx+si],al
0000B8E7  0000              add [bx+si],al
0000B8E9  0000              add [bx+si],al
0000B8EB  0000              add [bx+si],al
0000B8ED  0000              add [bx+si],al
0000B8EF  0000              add [bx+si],al
0000B8F1  0000              add [bx+si],al
0000B8F3  0000              add [bx+si],al
0000B8F5  0000              add [bx+si],al
0000B8F7  0000              add [bx+si],al
0000B8F9  0000              add [bx+si],al
0000B8FB  0000              add [bx+si],al
0000B8FD  0000              add [bx+si],al
0000B8FF  0000              add [bx+si],al
0000B901  0000              add [bx+si],al
0000B903  0000              add [bx+si],al
0000B905  0000              add [bx+si],al
0000B907  0000              add [bx+si],al
0000B909  0000              add [bx+si],al
0000B90B  0000              add [bx+si],al
0000B90D  0000              add [bx+si],al
0000B90F  0000              add [bx+si],al
0000B911  0000              add [bx+si],al
0000B913  0000              add [bx+si],al
0000B915  0000              add [bx+si],al
0000B917  0000              add [bx+si],al
0000B919  0000              add [bx+si],al
0000B91B  0000              add [bx+si],al
0000B91D  0000              add [bx+si],al
0000B91F  0000              add [bx+si],al
0000B921  0000              add [bx+si],al
0000B923  0000              add [bx+si],al
0000B925  0000              add [bx+si],al
0000B927  0000              add [bx+si],al
0000B929  0000              add [bx+si],al
0000B92B  0000              add [bx+si],al
0000B92D  0000              add [bx+si],al
0000B92F  0000              add [bx+si],al
0000B931  0000              add [bx+si],al
0000B933  0000              add [bx+si],al
0000B935  0000              add [bx+si],al
0000B937  0000              add [bx+si],al
0000B939  0000              add [bx+si],al
0000B93B  0000              add [bx+si],al
0000B93D  0000              add [bx+si],al
0000B93F  0000              add [bx+si],al
0000B941  0000              add [bx+si],al
0000B943  0000              add [bx+si],al
0000B945  0000              add [bx+si],al
0000B947  0000              add [bx+si],al
0000B949  0000              add [bx+si],al
0000B94B  0000              add [bx+si],al
0000B94D  0000              add [bx+si],al
0000B94F  0000              add [bx+si],al
0000B951  0000              add [bx+si],al
0000B953  0000              add [bx+si],al
0000B955  0000              add [bx+si],al
0000B957  0000              add [bx+si],al
0000B959  0000              add [bx+si],al
0000B95B  0000              add [bx+si],al
0000B95D  0000              add [bx+si],al
0000B95F  0000              add [bx+si],al
0000B961  0000              add [bx+si],al
0000B963  0000              add [bx+si],al
0000B965  0000              add [bx+si],al
0000B967  0000              add [bx+si],al
0000B969  0000              add [bx+si],al
0000B96B  0000              add [bx+si],al
0000B96D  0000              add [bx+si],al
0000B96F  0000              add [bx+si],al
0000B971  0000              add [bx+si],al
0000B973  0000              add [bx+si],al
0000B975  0000              add [bx+si],al
0000B977  0000              add [bx+si],al
0000B979  0000              add [bx+si],al
0000B97B  0000              add [bx+si],al
0000B97D  0000              add [bx+si],al
0000B97F  0000              add [bx+si],al
0000B981  0000              add [bx+si],al
0000B983  0000              add [bx+si],al
0000B985  0000              add [bx+si],al
0000B987  0000              add [bx+si],al
0000B989  0000              add [bx+si],al
0000B98B  0000              add [bx+si],al
0000B98D  0000              add [bx+si],al
0000B98F  0000              add [bx+si],al
0000B991  0000              add [bx+si],al
0000B993  0000              add [bx+si],al
0000B995  0000              add [bx+si],al
0000B997  0000              add [bx+si],al
0000B999  0000              add [bx+si],al
0000B99B  0000              add [bx+si],al
0000B99D  0000              add [bx+si],al
0000B99F  0000              add [bx+si],al
0000B9A1  0000              add [bx+si],al
0000B9A3  0000              add [bx+si],al
0000B9A5  0000              add [bx+si],al
0000B9A7  0000              add [bx+si],al
0000B9A9  0000              add [bx+si],al
0000B9AB  0000              add [bx+si],al
0000B9AD  0000              add [bx+si],al
0000B9AF  0000              add [bx+si],al
0000B9B1  0000              add [bx+si],al
0000B9B3  0000              add [bx+si],al
0000B9B5  0000              add [bx+si],al
0000B9B7  0000              add [bx+si],al
0000B9B9  0000              add [bx+si],al
0000B9BB  0000              add [bx+si],al
0000B9BD  0000              add [bx+si],al
0000B9BF  0000              add [bx+si],al
0000B9C1  0000              add [bx+si],al
0000B9C3  0000              add [bx+si],al
0000B9C5  0000              add [bx+si],al
0000B9C7  0000              add [bx+si],al
0000B9C9  0000              add [bx+si],al
0000B9CB  0000              add [bx+si],al
0000B9CD  0000              add [bx+si],al
0000B9CF  0000              add [bx+si],al
0000B9D1  0000              add [bx+si],al
0000B9D3  0000              add [bx+si],al
0000B9D5  0000              add [bx+si],al
0000B9D7  0000              add [bx+si],al
0000B9D9  0000              add [bx+si],al
0000B9DB  0000              add [bx+si],al
0000B9DD  0000              add [bx+si],al
0000B9DF  0000              add [bx+si],al
0000B9E1  0000              add [bx+si],al
0000B9E3  0000              add [bx+si],al
0000B9E5  0000              add [bx+si],al
0000B9E7  0000              add [bx+si],al
0000B9E9  0000              add [bx+si],al
0000B9EB  0000              add [bx+si],al
0000B9ED  0000              add [bx+si],al
0000B9EF  0000              add [bx+si],al
0000B9F1  0000              add [bx+si],al
0000B9F3  0000              add [bx+si],al
0000B9F5  0000              add [bx+si],al
0000B9F7  0000              add [bx+si],al
0000B9F9  0000              add [bx+si],al
0000B9FB  0000              add [bx+si],al
0000B9FD  0000              add [bx+si],al
0000B9FF  0000              add [bx+si],al
0000BA01  0000              add [bx+si],al
0000BA03  0000              add [bx+si],al
0000BA05  0000              add [bx+si],al
0000BA07  0000              add [bx+si],al
0000BA09  0000              add [bx+si],al
0000BA0B  0000              add [bx+si],al
0000BA0D  0000              add [bx+si],al
0000BA0F  0000              add [bx+si],al
0000BA11  0000              add [bx+si],al
0000BA13  0000              add [bx+si],al
0000BA15  0000              add [bx+si],al
0000BA17  0000              add [bx+si],al
0000BA19  0000              add [bx+si],al
0000BA1B  0000              add [bx+si],al
0000BA1D  0000              add [bx+si],al
0000BA1F  0000              add [bx+si],al
0000BA21  0000              add [bx+si],al
0000BA23  0000              add [bx+si],al
0000BA25  0000              add [bx+si],al
0000BA27  0000              add [bx+si],al
0000BA29  0000              add [bx+si],al
0000BA2B  0000              add [bx+si],al
0000BA2D  0000              add [bx+si],al
0000BA2F  0000              add [bx+si],al
0000BA31  0000              add [bx+si],al
0000BA33  0000              add [bx+si],al
0000BA35  0000              add [bx+si],al
0000BA37  0000              add [bx+si],al
0000BA39  0000              add [bx+si],al
0000BA3B  0000              add [bx+si],al
0000BA3D  0000              add [bx+si],al
0000BA3F  0000              add [bx+si],al
0000BA41  0000              add [bx+si],al
0000BA43  0000              add [bx+si],al
0000BA45  0000              add [bx+si],al
0000BA47  0000              add [bx+si],al
0000BA49  0000              add [bx+si],al
0000BA4B  0000              add [bx+si],al
0000BA4D  0000              add [bx+si],al
0000BA4F  0000              add [bx+si],al
0000BA51  0000              add [bx+si],al
0000BA53  0000              add [bx+si],al
0000BA55  0000              add [bx+si],al
0000BA57  0000              add [bx+si],al
0000BA59  0000              add [bx+si],al
0000BA5B  0000              add [bx+si],al
0000BA5D  0000              add [bx+si],al
0000BA5F  0000              add [bx+si],al
0000BA61  0000              add [bx+si],al
0000BA63  0000              add [bx+si],al
0000BA65  0000              add [bx+si],al
0000BA67  0000              add [bx+si],al
0000BA69  0000              add [bx+si],al
0000BA6B  0000              add [bx+si],al
0000BA6D  0000              add [bx+si],al
0000BA6F  0000              add [bx+si],al
0000BA71  0000              add [bx+si],al
0000BA73  0000              add [bx+si],al
0000BA75  0000              add [bx+si],al
0000BA77  0000              add [bx+si],al
0000BA79  0000              add [bx+si],al
0000BA7B  0000              add [bx+si],al
0000BA7D  0000              add [bx+si],al
0000BA7F  0000              add [bx+si],al
0000BA81  0000              add [bx+si],al
0000BA83  0000              add [bx+si],al
0000BA85  0000              add [bx+si],al
0000BA87  0000              add [bx+si],al
0000BA89  0000              add [bx+si],al
0000BA8B  0000              add [bx+si],al
0000BA8D  0000              add [bx+si],al
0000BA8F  0000              add [bx+si],al
0000BA91  0000              add [bx+si],al
0000BA93  0000              add [bx+si],al
0000BA95  0000              add [bx+si],al
0000BA97  0000              add [bx+si],al
0000BA99  0000              add [bx+si],al
0000BA9B  0000              add [bx+si],al
0000BA9D  0000              add [bx+si],al
0000BA9F  0000              add [bx+si],al
0000BAA1  0000              add [bx+si],al
0000BAA3  0000              add [bx+si],al
0000BAA5  0000              add [bx+si],al
0000BAA7  0000              add [bx+si],al
0000BAA9  0000              add [bx+si],al
0000BAAB  0000              add [bx+si],al
0000BAAD  0000              add [bx+si],al
0000BAAF  0000              add [bx+si],al
0000BAB1  0000              add [bx+si],al
0000BAB3  0000              add [bx+si],al
0000BAB5  0000              add [bx+si],al
0000BAB7  0000              add [bx+si],al
0000BAB9  0000              add [bx+si],al
0000BABB  0000              add [bx+si],al
0000BABD  0000              add [bx+si],al
0000BABF  0000              add [bx+si],al
0000BAC1  0000              add [bx+si],al
0000BAC3  0000              add [bx+si],al
0000BAC5  0000              add [bx+si],al
0000BAC7  0000              add [bx+si],al
0000BAC9  0000              add [bx+si],al
0000BACB  0000              add [bx+si],al
0000BACD  0000              add [bx+si],al
0000BACF  0000              add [bx+si],al
0000BAD1  0000              add [bx+si],al
0000BAD3  0000              add [bx+si],al
0000BAD5  0000              add [bx+si],al
0000BAD7  0000              add [bx+si],al
0000BAD9  0000              add [bx+si],al
0000BADB  0000              add [bx+si],al
0000BADD  0000              add [bx+si],al
0000BADF  0000              add [bx+si],al
0000BAE1  0000              add [bx+si],al
0000BAE3  0000              add [bx+si],al
0000BAE5  0000              add [bx+si],al
0000BAE7  0000              add [bx+si],al
0000BAE9  0000              add [bx+si],al
0000BAEB  0000              add [bx+si],al
0000BAED  0000              add [bx+si],al
0000BAEF  0000              add [bx+si],al
0000BAF1  0000              add [bx+si],al
0000BAF3  0000              add [bx+si],al
0000BAF5  0000              add [bx+si],al
0000BAF7  0000              add [bx+si],al
0000BAF9  0000              add [bx+si],al
0000BAFB  0000              add [bx+si],al
0000BAFD  0000              add [bx+si],al
0000BAFF  0000              add [bx+si],al
0000BB01  0000              add [bx+si],al
0000BB03  0000              add [bx+si],al
0000BB05  0000              add [bx+si],al
0000BB07  0000              add [bx+si],al
0000BB09  0000              add [bx+si],al
0000BB0B  0000              add [bx+si],al
0000BB0D  0000              add [bx+si],al
0000BB0F  0000              add [bx+si],al
0000BB11  0000              add [bx+si],al
0000BB13  0000              add [bx+si],al
0000BB15  0000              add [bx+si],al
0000BB17  0000              add [bx+si],al
0000BB19  0000              add [bx+si],al
0000BB1B  0000              add [bx+si],al
0000BB1D  0000              add [bx+si],al
0000BB1F  0000              add [bx+si],al
0000BB21  0000              add [bx+si],al
0000BB23  0000              add [bx+si],al
0000BB25  0000              add [bx+si],al
0000BB27  0000              add [bx+si],al
0000BB29  0000              add [bx+si],al
0000BB2B  0000              add [bx+si],al
0000BB2D  0000              add [bx+si],al
0000BB2F  0000              add [bx+si],al
0000BB31  0000              add [bx+si],al
0000BB33  0000              add [bx+si],al
0000BB35  0000              add [bx+si],al
0000BB37  0000              add [bx+si],al
0000BB39  0000              add [bx+si],al
0000BB3B  0000              add [bx+si],al
0000BB3D  0000              add [bx+si],al
0000BB3F  0000              add [bx+si],al
0000BB41  0000              add [bx+si],al
0000BB43  0000              add [bx+si],al
0000BB45  0000              add [bx+si],al
0000BB47  0000              add [bx+si],al
0000BB49  0000              add [bx+si],al
0000BB4B  0000              add [bx+si],al
0000BB4D  0000              add [bx+si],al
0000BB4F  0000              add [bx+si],al
0000BB51  0000              add [bx+si],al
0000BB53  0000              add [bx+si],al
0000BB55  0000              add [bx+si],al
0000BB57  0000              add [bx+si],al
0000BB59  0000              add [bx+si],al
0000BB5B  0000              add [bx+si],al
0000BB5D  0000              add [bx+si],al
0000BB5F  0000              add [bx+si],al
0000BB61  0000              add [bx+si],al
0000BB63  0000              add [bx+si],al
0000BB65  0000              add [bx+si],al
0000BB67  0000              add [bx+si],al
0000BB69  0000              add [bx+si],al
0000BB6B  0000              add [bx+si],al
0000BB6D  0000              add [bx+si],al
0000BB6F  0000              add [bx+si],al
0000BB71  0000              add [bx+si],al
0000BB73  0000              add [bx+si],al
0000BB75  0000              add [bx+si],al
0000BB77  0000              add [bx+si],al
0000BB79  0000              add [bx+si],al
0000BB7B  0000              add [bx+si],al
0000BB7D  0000              add [bx+si],al
0000BB7F  0000              add [bx+si],al
0000BB81  0000              add [bx+si],al
0000BB83  0000              add [bx+si],al
0000BB85  0000              add [bx+si],al
0000BB87  0000              add [bx+si],al
0000BB89  0000              add [bx+si],al
0000BB8B  0000              add [bx+si],al
0000BB8D  0000              add [bx+si],al
0000BB8F  0000              add [bx+si],al
0000BB91  0000              add [bx+si],al
0000BB93  0000              add [bx+si],al
0000BB95  0000              add [bx+si],al
0000BB97  0000              add [bx+si],al
0000BB99  0000              add [bx+si],al
0000BB9B  0000              add [bx+si],al
0000BB9D  0000              add [bx+si],al
0000BB9F  0000              add [bx+si],al
0000BBA1  0000              add [bx+si],al
0000BBA3  0000              add [bx+si],al
0000BBA5  0000              add [bx+si],al
0000BBA7  0000              add [bx+si],al
0000BBA9  0000              add [bx+si],al
0000BBAB  0000              add [bx+si],al
0000BBAD  0000              add [bx+si],al
0000BBAF  0000              add [bx+si],al
0000BBB1  0000              add [bx+si],al
0000BBB3  0000              add [bx+si],al
0000BBB5  0000              add [bx+si],al
0000BBB7  0000              add [bx+si],al
0000BBB9  0000              add [bx+si],al
0000BBBB  0000              add [bx+si],al
0000BBBD  0000              add [bx+si],al
0000BBBF  0000              add [bx+si],al
0000BBC1  0000              add [bx+si],al
0000BBC3  0000              add [bx+si],al
0000BBC5  0000              add [bx+si],al
0000BBC7  0000              add [bx+si],al
0000BBC9  0000              add [bx+si],al
0000BBCB  0000              add [bx+si],al
0000BBCD  0000              add [bx+si],al
0000BBCF  0000              add [bx+si],al
0000BBD1  0000              add [bx+si],al
0000BBD3  0000              add [bx+si],al
0000BBD5  0000              add [bx+si],al
0000BBD7  0000              add [bx+si],al
0000BBD9  0000              add [bx+si],al
0000BBDB  0000              add [bx+si],al
0000BBDD  0000              add [bx+si],al
0000BBDF  0000              add [bx+si],al
0000BBE1  0000              add [bx+si],al
0000BBE3  0000              add [bx+si],al
0000BBE5  0000              add [bx+si],al
0000BBE7  0000              add [bx+si],al
0000BBE9  0000              add [bx+si],al
0000BBEB  0000              add [bx+si],al
0000BBED  0000              add [bx+si],al
0000BBEF  0000              add [bx+si],al
0000BBF1  0000              add [bx+si],al
0000BBF3  0000              add [bx+si],al
0000BBF5  0000              add [bx+si],al
0000BBF7  0000              add [bx+si],al
0000BBF9  0000              add [bx+si],al
0000BBFB  0000              add [bx+si],al
0000BBFD  0000              add [bx+si],al
0000BBFF  0000              add [bx+si],al
0000BC01  0000              add [bx+si],al
0000BC03  0000              add [bx+si],al
0000BC05  0000              add [bx+si],al
0000BC07  0000              add [bx+si],al
0000BC09  0000              add [bx+si],al
0000BC0B  0000              add [bx+si],al
0000BC0D  0000              add [bx+si],al
0000BC0F  0000              add [bx+si],al
0000BC11  0000              add [bx+si],al
0000BC13  0000              add [bx+si],al
0000BC15  0000              add [bx+si],al
0000BC17  0000              add [bx+si],al
0000BC19  0000              add [bx+si],al
0000BC1B  0000              add [bx+si],al
0000BC1D  0000              add [bx+si],al
0000BC1F  0000              add [bx+si],al
0000BC21  0000              add [bx+si],al
0000BC23  0000              add [bx+si],al
0000BC25  0000              add [bx+si],al
0000BC27  0000              add [bx+si],al
0000BC29  0000              add [bx+si],al
0000BC2B  0000              add [bx+si],al
0000BC2D  0000              add [bx+si],al
0000BC2F  0000              add [bx+si],al
0000BC31  0000              add [bx+si],al
0000BC33  0000              add [bx+si],al
0000BC35  0000              add [bx+si],al
0000BC37  0000              add [bx+si],al
0000BC39  0000              add [bx+si],al
0000BC3B  0000              add [bx+si],al
0000BC3D  0000              add [bx+si],al
0000BC3F  0000              add [bx+si],al
0000BC41  0000              add [bx+si],al
0000BC43  0000              add [bx+si],al
0000BC45  0000              add [bx+si],al
0000BC47  0000              add [bx+si],al
0000BC49  0000              add [bx+si],al
0000BC4B  0000              add [bx+si],al
0000BC4D  0000              add [bx+si],al
0000BC4F  0000              add [bx+si],al
0000BC51  0000              add [bx+si],al
0000BC53  0000              add [bx+si],al
0000BC55  0000              add [bx+si],al
0000BC57  0000              add [bx+si],al
0000BC59  0000              add [bx+si],al
0000BC5B  0000              add [bx+si],al
0000BC5D  0000              add [bx+si],al
0000BC5F  0000              add [bx+si],al
0000BC61  0000              add [bx+si],al
0000BC63  0000              add [bx+si],al
0000BC65  0000              add [bx+si],al
0000BC67  0000              add [bx+si],al
0000BC69  0000              add [bx+si],al
0000BC6B  0000              add [bx+si],al
0000BC6D  0000              add [bx+si],al
0000BC6F  0000              add [bx+si],al
0000BC71  0000              add [bx+si],al
0000BC73  0000              add [bx+si],al
0000BC75  0000              add [bx+si],al
0000BC77  0000              add [bx+si],al
0000BC79  0000              add [bx+si],al
0000BC7B  0000              add [bx+si],al
0000BC7D  0000              add [bx+si],al
0000BC7F  0000              add [bx+si],al
0000BC81  0000              add [bx+si],al
0000BC83  0000              add [bx+si],al
0000BC85  0000              add [bx+si],al
0000BC87  0000              add [bx+si],al
0000BC89  0000              add [bx+si],al
0000BC8B  0000              add [bx+si],al
0000BC8D  0000              add [bx+si],al
0000BC8F  0000              add [bx+si],al
0000BC91  0000              add [bx+si],al
0000BC93  0000              add [bx+si],al
0000BC95  0000              add [bx+si],al
0000BC97  0000              add [bx+si],al
0000BC99  0000              add [bx+si],al
0000BC9B  0000              add [bx+si],al
0000BC9D  0000              add [bx+si],al
0000BC9F  0000              add [bx+si],al
0000BCA1  0000              add [bx+si],al
0000BCA3  0000              add [bx+si],al
0000BCA5  0000              add [bx+si],al
0000BCA7  0000              add [bx+si],al
0000BCA9  0000              add [bx+si],al
0000BCAB  0000              add [bx+si],al
0000BCAD  0000              add [bx+si],al
0000BCAF  0000              add [bx+si],al
0000BCB1  0000              add [bx+si],al
0000BCB3  0000              add [bx+si],al
0000BCB5  0000              add [bx+si],al
0000BCB7  0000              add [bx+si],al
0000BCB9  0000              add [bx+si],al
0000BCBB  0000              add [bx+si],al
0000BCBD  0000              add [bx+si],al
0000BCBF  0000              add [bx+si],al
0000BCC1  0000              add [bx+si],al
0000BCC3  0000              add [bx+si],al
0000BCC5  0000              add [bx+si],al
0000BCC7  0000              add [bx+si],al
0000BCC9  0000              add [bx+si],al
0000BCCB  0000              add [bx+si],al
0000BCCD  0000              add [bx+si],al
0000BCCF  0000              add [bx+si],al
0000BCD1  0000              add [bx+si],al
0000BCD3  0000              add [bx+si],al
0000BCD5  0000              add [bx+si],al
0000BCD7  0000              add [bx+si],al
0000BCD9  0000              add [bx+si],al
0000BCDB  0000              add [bx+si],al
0000BCDD  0000              add [bx+si],al
0000BCDF  0000              add [bx+si],al
0000BCE1  0000              add [bx+si],al
0000BCE3  0000              add [bx+si],al
0000BCE5  0000              add [bx+si],al
0000BCE7  0000              add [bx+si],al
0000BCE9  0000              add [bx+si],al
0000BCEB  0000              add [bx+si],al
0000BCED  0000              add [bx+si],al
0000BCEF  0000              add [bx+si],al
0000BCF1  0000              add [bx+si],al
0000BCF3  0000              add [bx+si],al
0000BCF5  0000              add [bx+si],al
0000BCF7  0000              add [bx+si],al
0000BCF9  0000              add [bx+si],al
0000BCFB  0000              add [bx+si],al
0000BCFD  0000              add [bx+si],al
0000BCFF  0000              add [bx+si],al
0000BD01  0000              add [bx+si],al
0000BD03  0000              add [bx+si],al
0000BD05  0000              add [bx+si],al
0000BD07  0000              add [bx+si],al
0000BD09  0000              add [bx+si],al
0000BD0B  0000              add [bx+si],al
0000BD0D  0000              add [bx+si],al
0000BD0F  0000              add [bx+si],al
0000BD11  0000              add [bx+si],al
0000BD13  0000              add [bx+si],al
0000BD15  0000              add [bx+si],al
0000BD17  0000              add [bx+si],al
0000BD19  0000              add [bx+si],al
0000BD1B  0000              add [bx+si],al
0000BD1D  0000              add [bx+si],al
0000BD1F  0000              add [bx+si],al
0000BD21  0000              add [bx+si],al
0000BD23  0000              add [bx+si],al
0000BD25  0000              add [bx+si],al
0000BD27  0000              add [bx+si],al
0000BD29  0000              add [bx+si],al
0000BD2B  0000              add [bx+si],al
0000BD2D  0000              add [bx+si],al
0000BD2F  0000              add [bx+si],al
0000BD31  0000              add [bx+si],al
0000BD33  0000              add [bx+si],al
0000BD35  0000              add [bx+si],al
0000BD37  0000              add [bx+si],al
0000BD39  0000              add [bx+si],al
0000BD3B  0000              add [bx+si],al
0000BD3D  0000              add [bx+si],al
0000BD3F  0000              add [bx+si],al
0000BD41  0000              add [bx+si],al
0000BD43  0000              add [bx+si],al
0000BD45  0000              add [bx+si],al
0000BD47  0000              add [bx+si],al
0000BD49  0000              add [bx+si],al
0000BD4B  0000              add [bx+si],al
0000BD4D  0000              add [bx+si],al
0000BD4F  0000              add [bx+si],al
0000BD51  0000              add [bx+si],al
0000BD53  0000              add [bx+si],al
0000BD55  0000              add [bx+si],al
0000BD57  0000              add [bx+si],al
0000BD59  0000              add [bx+si],al
0000BD5B  0000              add [bx+si],al
0000BD5D  0000              add [bx+si],al
0000BD5F  0000              add [bx+si],al
0000BD61  0000              add [bx+si],al
0000BD63  0000              add [bx+si],al
0000BD65  0000              add [bx+si],al
0000BD67  0000              add [bx+si],al
0000BD69  0000              add [bx+si],al
0000BD6B  0000              add [bx+si],al
0000BD6D  0000              add [bx+si],al
0000BD6F  0000              add [bx+si],al
0000BD71  0000              add [bx+si],al
0000BD73  0000              add [bx+si],al
0000BD75  0000              add [bx+si],al
0000BD77  0000              add [bx+si],al
0000BD79  0000              add [bx+si],al
0000BD7B  0000              add [bx+si],al
0000BD7D  0000              add [bx+si],al
0000BD7F  0000              add [bx+si],al
0000BD81  0000              add [bx+si],al
0000BD83  0000              add [bx+si],al
0000BD85  0000              add [bx+si],al
0000BD87  0000              add [bx+si],al
0000BD89  0000              add [bx+si],al
0000BD8B  0000              add [bx+si],al
0000BD8D  0000              add [bx+si],al
0000BD8F  0000              add [bx+si],al
0000BD91  0000              add [bx+si],al
0000BD93  0000              add [bx+si],al
0000BD95  0000              add [bx+si],al
0000BD97  0000              add [bx+si],al
0000BD99  0000              add [bx+si],al
0000BD9B  0000              add [bx+si],al
0000BD9D  0000              add [bx+si],al
0000BD9F  0000              add [bx+si],al
0000BDA1  0000              add [bx+si],al
0000BDA3  0000              add [bx+si],al
0000BDA5  0000              add [bx+si],al
0000BDA7  0000              add [bx+si],al
0000BDA9  0000              add [bx+si],al
0000BDAB  0000              add [bx+si],al
0000BDAD  0000              add [bx+si],al
0000BDAF  0000              add [bx+si],al
0000BDB1  0000              add [bx+si],al
0000BDB3  0000              add [bx+si],al
0000BDB5  0000              add [bx+si],al
0000BDB7  0000              add [bx+si],al
0000BDB9  0000              add [bx+si],al
0000BDBB  0000              add [bx+si],al
0000BDBD  0000              add [bx+si],al
0000BDBF  0000              add [bx+si],al
0000BDC1  0000              add [bx+si],al
0000BDC3  0000              add [bx+si],al
0000BDC5  0000              add [bx+si],al
0000BDC7  0000              add [bx+si],al
0000BDC9  0000              add [bx+si],al
0000BDCB  0000              add [bx+si],al
0000BDCD  0000              add [bx+si],al
0000BDCF  0000              add [bx+si],al
0000BDD1  0000              add [bx+si],al
0000BDD3  0000              add [bx+si],al
0000BDD5  0000              add [bx+si],al
0000BDD7  0000              add [bx+si],al
0000BDD9  0000              add [bx+si],al
0000BDDB  0000              add [bx+si],al
0000BDDD  0000              add [bx+si],al
0000BDDF  0000              add [bx+si],al
0000BDE1  0000              add [bx+si],al
0000BDE3  0000              add [bx+si],al
0000BDE5  0000              add [bx+si],al
0000BDE7  0000              add [bx+si],al
0000BDE9  0000              add [bx+si],al
0000BDEB  0000              add [bx+si],al
0000BDED  0000              add [bx+si],al
0000BDEF  0000              add [bx+si],al
0000BDF1  0000              add [bx+si],al
0000BDF3  0000              add [bx+si],al
0000BDF5  0000              add [bx+si],al
0000BDF7  0000              add [bx+si],al
0000BDF9  0000              add [bx+si],al
0000BDFB  0000              add [bx+si],al
0000BDFD  0000              add [bx+si],al
0000BDFF  0000              add [bx+si],al
0000BE01  0000              add [bx+si],al
0000BE03  0000              add [bx+si],al
0000BE05  0000              add [bx+si],al
0000BE07  0000              add [bx+si],al
0000BE09  0000              add [bx+si],al
0000BE0B  0000              add [bx+si],al
0000BE0D  0000              add [bx+si],al
0000BE0F  0000              add [bx+si],al
0000BE11  0000              add [bx+si],al
0000BE13  0000              add [bx+si],al
0000BE15  0000              add [bx+si],al
0000BE17  0000              add [bx+si],al
0000BE19  0000              add [bx+si],al
0000BE1B  0000              add [bx+si],al
0000BE1D  0000              add [bx+si],al
0000BE1F  0000              add [bx+si],al
0000BE21  0000              add [bx+si],al
0000BE23  0000              add [bx+si],al
0000BE25  0000              add [bx+si],al
0000BE27  0000              add [bx+si],al
0000BE29  0000              add [bx+si],al
0000BE2B  0000              add [bx+si],al
0000BE2D  0000              add [bx+si],al
0000BE2F  0000              add [bx+si],al
0000BE31  0000              add [bx+si],al
0000BE33  0000              add [bx+si],al
0000BE35  0000              add [bx+si],al
0000BE37  0000              add [bx+si],al
0000BE39  0000              add [bx+si],al
0000BE3B  0000              add [bx+si],al
0000BE3D  0000              add [bx+si],al
0000BE3F  0000              add [bx+si],al
0000BE41  0000              add [bx+si],al
0000BE43  0000              add [bx+si],al
0000BE45  0000              add [bx+si],al
0000BE47  0000              add [bx+si],al
0000BE49  0000              add [bx+si],al
0000BE4B  0000              add [bx+si],al
0000BE4D  0000              add [bx+si],al
0000BE4F  0000              add [bx+si],al
0000BE51  0000              add [bx+si],al
0000BE53  0000              add [bx+si],al
0000BE55  0000              add [bx+si],al
0000BE57  0000              add [bx+si],al
0000BE59  0000              add [bx+si],al
0000BE5B  0000              add [bx+si],al
0000BE5D  0000              add [bx+si],al
0000BE5F  0000              add [bx+si],al
0000BE61  0000              add [bx+si],al
0000BE63  0000              add [bx+si],al
0000BE65  0000              add [bx+si],al
0000BE67  0000              add [bx+si],al
0000BE69  0000              add [bx+si],al
0000BE6B  0000              add [bx+si],al
0000BE6D  0000              add [bx+si],al
0000BE6F  0000              add [bx+si],al
0000BE71  0000              add [bx+si],al
0000BE73  0000              add [bx+si],al
0000BE75  0000              add [bx+si],al
0000BE77  0000              add [bx+si],al
0000BE79  0000              add [bx+si],al
0000BE7B  0000              add [bx+si],al
0000BE7D  0000              add [bx+si],al
0000BE7F  0000              add [bx+si],al
0000BE81  0000              add [bx+si],al
0000BE83  0000              add [bx+si],al
0000BE85  0000              add [bx+si],al
0000BE87  0000              add [bx+si],al
0000BE89  0000              add [bx+si],al
0000BE8B  0000              add [bx+si],al
0000BE8D  0000              add [bx+si],al
0000BE8F  0000              add [bx+si],al
0000BE91  0000              add [bx+si],al
0000BE93  0000              add [bx+si],al
0000BE95  0000              add [bx+si],al
0000BE97  0000              add [bx+si],al
0000BE99  0000              add [bx+si],al
0000BE9B  0000              add [bx+si],al
0000BE9D  0000              add [bx+si],al
0000BE9F  0000              add [bx+si],al
0000BEA1  0000              add [bx+si],al
0000BEA3  0000              add [bx+si],al
0000BEA5  0000              add [bx+si],al
0000BEA7  0000              add [bx+si],al
0000BEA9  0000              add [bx+si],al
0000BEAB  0000              add [bx+si],al
0000BEAD  0000              add [bx+si],al
0000BEAF  0000              add [bx+si],al
0000BEB1  0000              add [bx+si],al
0000BEB3  0000              add [bx+si],al
0000BEB5  0000              add [bx+si],al
0000BEB7  0000              add [bx+si],al
0000BEB9  0000              add [bx+si],al
0000BEBB  0000              add [bx+si],al
0000BEBD  0000              add [bx+si],al
0000BEBF  0000              add [bx+si],al
0000BEC1  0000              add [bx+si],al
0000BEC3  0000              add [bx+si],al
0000BEC5  0000              add [bx+si],al
0000BEC7  0000              add [bx+si],al
0000BEC9  0000              add [bx+si],al
0000BECB  0000              add [bx+si],al
0000BECD  0000              add [bx+si],al
0000BECF  0000              add [bx+si],al
0000BED1  0000              add [bx+si],al
0000BED3  0000              add [bx+si],al
0000BED5  0000              add [bx+si],al
0000BED7  0000              add [bx+si],al
0000BED9  0000              add [bx+si],al
0000BEDB  0000              add [bx+si],al
0000BEDD  0000              add [bx+si],al
0000BEDF  0000              add [bx+si],al
0000BEE1  0000              add [bx+si],al
0000BEE3  0000              add [bx+si],al
0000BEE5  0000              add [bx+si],al
0000BEE7  0000              add [bx+si],al
0000BEE9  0000              add [bx+si],al
0000BEEB  0000              add [bx+si],al
0000BEED  0000              add [bx+si],al
0000BEEF  0000              add [bx+si],al
0000BEF1  0000              add [bx+si],al
0000BEF3  0000              add [bx+si],al
0000BEF5  0000              add [bx+si],al
0000BEF7  0000              add [bx+si],al
0000BEF9  0000              add [bx+si],al
0000BEFB  0000              add [bx+si],al
0000BEFD  0000              add [bx+si],al
0000BEFF  0000              add [bx+si],al
0000BF01  0000              add [bx+si],al
0000BF03  0000              add [bx+si],al
0000BF05  0000              add [bx+si],al
0000BF07  0000              add [bx+si],al
0000BF09  0000              add [bx+si],al
0000BF0B  0000              add [bx+si],al
0000BF0D  0000              add [bx+si],al
0000BF0F  0000              add [bx+si],al
0000BF11  0000              add [bx+si],al
0000BF13  0000              add [bx+si],al
0000BF15  0000              add [bx+si],al
0000BF17  0000              add [bx+si],al
0000BF19  0000              add [bx+si],al
0000BF1B  0000              add [bx+si],al
0000BF1D  0000              add [bx+si],al
0000BF1F  0000              add [bx+si],al
0000BF21  0000              add [bx+si],al
0000BF23  0000              add [bx+si],al
0000BF25  0000              add [bx+si],al
0000BF27  0000              add [bx+si],al
0000BF29  0000              add [bx+si],al
0000BF2B  0000              add [bx+si],al
0000BF2D  0000              add [bx+si],al
0000BF2F  0000              add [bx+si],al
0000BF31  0000              add [bx+si],al
0000BF33  0000              add [bx+si],al
0000BF35  0000              add [bx+si],al
0000BF37  0000              add [bx+si],al
0000BF39  0000              add [bx+si],al
0000BF3B  0000              add [bx+si],al
0000BF3D  0000              add [bx+si],al
0000BF3F  0000              add [bx+si],al
0000BF41  0000              add [bx+si],al
0000BF43  0000              add [bx+si],al
0000BF45  0000              add [bx+si],al
0000BF47  0000              add [bx+si],al
0000BF49  0000              add [bx+si],al
0000BF4B  0000              add [bx+si],al
0000BF4D  0000              add [bx+si],al
0000BF4F  0000              add [bx+si],al
0000BF51  0000              add [bx+si],al
0000BF53  0000              add [bx+si],al
0000BF55  0000              add [bx+si],al
0000BF57  0000              add [bx+si],al
0000BF59  0000              add [bx+si],al
0000BF5B  0000              add [bx+si],al
0000BF5D  0000              add [bx+si],al
0000BF5F  0000              add [bx+si],al
0000BF61  0000              add [bx+si],al
0000BF63  0000              add [bx+si],al
0000BF65  0000              add [bx+si],al
0000BF67  0000              add [bx+si],al
0000BF69  0000              add [bx+si],al
0000BF6B  0000              add [bx+si],al
0000BF6D  0000              add [bx+si],al
0000BF6F  0000              add [bx+si],al
0000BF71  0000              add [bx+si],al
0000BF73  0000              add [bx+si],al
0000BF75  0000              add [bx+si],al
0000BF77  0000              add [bx+si],al
0000BF79  0000              add [bx+si],al
0000BF7B  0000              add [bx+si],al
0000BF7D  0000              add [bx+si],al
0000BF7F  0000              add [bx+si],al
0000BF81  0000              add [bx+si],al
0000BF83  0000              add [bx+si],al
0000BF85  0000              add [bx+si],al
0000BF87  0000              add [bx+si],al
0000BF89  0000              add [bx+si],al
0000BF8B  0000              add [bx+si],al
0000BF8D  0000              add [bx+si],al
0000BF8F  0000              add [bx+si],al
0000BF91  0000              add [bx+si],al
0000BF93  0000              add [bx+si],al
0000BF95  0000              add [bx+si],al
0000BF97  0000              add [bx+si],al
0000BF99  0000              add [bx+si],al
0000BF9B  0000              add [bx+si],al
0000BF9D  0000              add [bx+si],al
0000BF9F  0000              add [bx+si],al
0000BFA1  0000              add [bx+si],al
0000BFA3  0000              add [bx+si],al
0000BFA5  0000              add [bx+si],al
0000BFA7  0000              add [bx+si],al
0000BFA9  0000              add [bx+si],al
0000BFAB  0000              add [bx+si],al
0000BFAD  0000              add [bx+si],al
0000BFAF  0000              add [bx+si],al
0000BFB1  0000              add [bx+si],al
0000BFB3  0000              add [bx+si],al
0000BFB5  0000              add [bx+si],al
0000BFB7  0000              add [bx+si],al
0000BFB9  0000              add [bx+si],al
0000BFBB  0000              add [bx+si],al
0000BFBD  0000              add [bx+si],al
0000BFBF  0000              add [bx+si],al
0000BFC1  0000              add [bx+si],al
0000BFC3  0000              add [bx+si],al
0000BFC5  0000              add [bx+si],al
0000BFC7  0000              add [bx+si],al
0000BFC9  0000              add [bx+si],al
0000BFCB  0000              add [bx+si],al
0000BFCD  0000              add [bx+si],al
0000BFCF  0000              add [bx+si],al
0000BFD1  0000              add [bx+si],al
0000BFD3  0000              add [bx+si],al
0000BFD5  0000              add [bx+si],al
0000BFD7  0000              add [bx+si],al
0000BFD9  0000              add [bx+si],al
0000BFDB  0000              add [bx+si],al
0000BFDD  0000              add [bx+si],al
0000BFDF  0000              add [bx+si],al
0000BFE1  0000              add [bx+si],al
0000BFE3  0000              add [bx+si],al
0000BFE5  0000              add [bx+si],al
0000BFE7  0000              add [bx+si],al
0000BFE9  0000              add [bx+si],al
0000BFEB  0000              add [bx+si],al
0000BFED  0000              add [bx+si],al
0000BFEF  0000              add [bx+si],al
0000BFF1  0000              add [bx+si],al
0000BFF3  0000              add [bx+si],al
0000BFF5  0000              add [bx+si],al
0000BFF7  0000              add [bx+si],al
0000BFF9  0000              add [bx+si],al
0000BFFB  0000              add [bx+si],al
0000BFFD  0000              add [bx+si],al
0000BFFF  0000              add [bx+si],al
0000C001  0000              add [bx+si],al
0000C003  0000              add [bx+si],al
0000C005  0000              add [bx+si],al
0000C007  0000              add [bx+si],al
0000C009  0000              add [bx+si],al
0000C00B  0000              add [bx+si],al
0000C00D  0000              add [bx+si],al
0000C00F  0000              add [bx+si],al
0000C011  0000              add [bx+si],al
0000C013  0000              add [bx+si],al
0000C015  0000              add [bx+si],al
0000C017  0000              add [bx+si],al
0000C019  0000              add [bx+si],al
0000C01B  0000              add [bx+si],al
0000C01D  0000              add [bx+si],al
0000C01F  0000              add [bx+si],al
0000C021  0000              add [bx+si],al
0000C023  0000              add [bx+si],al
0000C025  0000              add [bx+si],al
0000C027  0000              add [bx+si],al
0000C029  0000              add [bx+si],al
0000C02B  0000              add [bx+si],al
0000C02D  0000              add [bx+si],al
0000C02F  0000              add [bx+si],al
0000C031  0000              add [bx+si],al
0000C033  0000              add [bx+si],al
0000C035  0000              add [bx+si],al
0000C037  0000              add [bx+si],al
0000C039  0000              add [bx+si],al
0000C03B  0000              add [bx+si],al
0000C03D  0000              add [bx+si],al
0000C03F  0000              add [bx+si],al
0000C041  0000              add [bx+si],al
0000C043  0000              add [bx+si],al
0000C045  0000              add [bx+si],al
0000C047  0000              add [bx+si],al
0000C049  0000              add [bx+si],al
0000C04B  0000              add [bx+si],al
0000C04D  0000              add [bx+si],al
0000C04F  0000              add [bx+si],al
0000C051  0000              add [bx+si],al
0000C053  0000              add [bx+si],al
0000C055  0000              add [bx+si],al
0000C057  0000              add [bx+si],al
0000C059  0000              add [bx+si],al
0000C05B  0000              add [bx+si],al
0000C05D  0000              add [bx+si],al
0000C05F  0000              add [bx+si],al
0000C061  0000              add [bx+si],al
0000C063  0000              add [bx+si],al
0000C065  0000              add [bx+si],al
0000C067  0000              add [bx+si],al
0000C069  0000              add [bx+si],al
0000C06B  0000              add [bx+si],al
0000C06D  0000              add [bx+si],al
0000C06F  0000              add [bx+si],al
0000C071  0000              add [bx+si],al
0000C073  0000              add [bx+si],al
0000C075  0000              add [bx+si],al
0000C077  0000              add [bx+si],al
0000C079  0000              add [bx+si],al
0000C07B  0000              add [bx+si],al
0000C07D  0000              add [bx+si],al
0000C07F  0000              add [bx+si],al
0000C081  0000              add [bx+si],al
0000C083  0000              add [bx+si],al
0000C085  0000              add [bx+si],al
0000C087  0000              add [bx+si],al
0000C089  0000              add [bx+si],al
0000C08B  0000              add [bx+si],al
0000C08D  0000              add [bx+si],al
0000C08F  0000              add [bx+si],al
0000C091  0000              add [bx+si],al
0000C093  0000              add [bx+si],al
0000C095  0000              add [bx+si],al
0000C097  0000              add [bx+si],al
0000C099  0000              add [bx+si],al
0000C09B  0000              add [bx+si],al
0000C09D  0000              add [bx+si],al
0000C09F  0000              add [bx+si],al
0000C0A1  0000              add [bx+si],al
0000C0A3  0000              add [bx+si],al
0000C0A5  0000              add [bx+si],al
0000C0A7  0000              add [bx+si],al
0000C0A9  0000              add [bx+si],al
0000C0AB  0000              add [bx+si],al
0000C0AD  0000              add [bx+si],al
0000C0AF  0000              add [bx+si],al
0000C0B1  0000              add [bx+si],al
0000C0B3  0000              add [bx+si],al
0000C0B5  0000              add [bx+si],al
0000C0B7  0000              add [bx+si],al
0000C0B9  0000              add [bx+si],al
0000C0BB  0000              add [bx+si],al
0000C0BD  0000              add [bx+si],al
0000C0BF  0000              add [bx+si],al
0000C0C1  0000              add [bx+si],al
0000C0C3  0000              add [bx+si],al
0000C0C5  0000              add [bx+si],al
0000C0C7  0000              add [bx+si],al
0000C0C9  0000              add [bx+si],al
0000C0CB  0000              add [bx+si],al
0000C0CD  0000              add [bx+si],al
0000C0CF  0000              add [bx+si],al
0000C0D1  0000              add [bx+si],al
0000C0D3  0000              add [bx+si],al
0000C0D5  0000              add [bx+si],al
0000C0D7  0000              add [bx+si],al
0000C0D9  0000              add [bx+si],al
0000C0DB  0000              add [bx+si],al
0000C0DD  0000              add [bx+si],al
0000C0DF  0000              add [bx+si],al
0000C0E1  0000              add [bx+si],al
0000C0E3  0000              add [bx+si],al
0000C0E5  0000              add [bx+si],al
0000C0E7  0000              add [bx+si],al
0000C0E9  0000              add [bx+si],al
0000C0EB  0000              add [bx+si],al
0000C0ED  0000              add [bx+si],al
0000C0EF  0000              add [bx+si],al
0000C0F1  0000              add [bx+si],al
0000C0F3  0000              add [bx+si],al
0000C0F5  0000              add [bx+si],al
0000C0F7  0000              add [bx+si],al
0000C0F9  0000              add [bx+si],al
0000C0FB  0000              add [bx+si],al
0000C0FD  0000              add [bx+si],al
0000C0FF  0000              add [bx+si],al
0000C101  0000              add [bx+si],al
0000C103  0000              add [bx+si],al
0000C105  0000              add [bx+si],al
0000C107  0000              add [bx+si],al
0000C109  0000              add [bx+si],al
0000C10B  0000              add [bx+si],al
0000C10D  0000              add [bx+si],al
0000C10F  0000              add [bx+si],al
0000C111  0000              add [bx+si],al
0000C113  0000              add [bx+si],al
0000C115  0000              add [bx+si],al
0000C117  0000              add [bx+si],al
0000C119  0000              add [bx+si],al
0000C11B  0000              add [bx+si],al
0000C11D  0000              add [bx+si],al
0000C11F  0000              add [bx+si],al
0000C121  0000              add [bx+si],al
0000C123  0000              add [bx+si],al
0000C125  0000              add [bx+si],al
0000C127  0000              add [bx+si],al
0000C129  0000              add [bx+si],al
0000C12B  0000              add [bx+si],al
0000C12D  0000              add [bx+si],al
0000C12F  0000              add [bx+si],al
0000C131  0000              add [bx+si],al
0000C133  0000              add [bx+si],al
0000C135  0000              add [bx+si],al
0000C137  0000              add [bx+si],al
0000C139  0000              add [bx+si],al
0000C13B  0000              add [bx+si],al
0000C13D  0000              add [bx+si],al
0000C13F  0000              add [bx+si],al
0000C141  0000              add [bx+si],al
0000C143  0000              add [bx+si],al
0000C145  0000              add [bx+si],al
0000C147  0000              add [bx+si],al
0000C149  0000              add [bx+si],al
0000C14B  0000              add [bx+si],al
0000C14D  0000              add [bx+si],al
0000C14F  0000              add [bx+si],al
0000C151  0000              add [bx+si],al
0000C153  0000              add [bx+si],al
0000C155  0000              add [bx+si],al
0000C157  0000              add [bx+si],al
0000C159  0000              add [bx+si],al
0000C15B  0000              add [bx+si],al
0000C15D  0000              add [bx+si],al
0000C15F  0000              add [bx+si],al
0000C161  0000              add [bx+si],al
0000C163  0000              add [bx+si],al
0000C165  0000              add [bx+si],al
0000C167  0000              add [bx+si],al
0000C169  0000              add [bx+si],al
0000C16B  0000              add [bx+si],al
0000C16D  0000              add [bx+si],al
0000C16F  0000              add [bx+si],al
0000C171  0000              add [bx+si],al
0000C173  0000              add [bx+si],al
0000C175  0000              add [bx+si],al
0000C177  0000              add [bx+si],al
0000C179  0000              add [bx+si],al
0000C17B  0000              add [bx+si],al
0000C17D  0000              add [bx+si],al
0000C17F  0000              add [bx+si],al
0000C181  0000              add [bx+si],al
0000C183  0000              add [bx+si],al
0000C185  0000              add [bx+si],al
0000C187  0000              add [bx+si],al
0000C189  0000              add [bx+si],al
0000C18B  0000              add [bx+si],al
0000C18D  0000              add [bx+si],al
0000C18F  0000              add [bx+si],al
0000C191  0000              add [bx+si],al
0000C193  0000              add [bx+si],al
0000C195  0000              add [bx+si],al
0000C197  0000              add [bx+si],al
0000C199  0000              add [bx+si],al
0000C19B  0000              add [bx+si],al
0000C19D  0000              add [bx+si],al
0000C19F  0000              add [bx+si],al
0000C1A1  0000              add [bx+si],al
0000C1A3  0000              add [bx+si],al
0000C1A5  0000              add [bx+si],al
0000C1A7  0000              add [bx+si],al
0000C1A9  0000              add [bx+si],al
0000C1AB  0000              add [bx+si],al
0000C1AD  0000              add [bx+si],al
0000C1AF  0000              add [bx+si],al
0000C1B1  0000              add [bx+si],al
0000C1B3  0000              add [bx+si],al
0000C1B5  0000              add [bx+si],al
0000C1B7  0000              add [bx+si],al
0000C1B9  0000              add [bx+si],al
0000C1BB  0000              add [bx+si],al
0000C1BD  0000              add [bx+si],al
0000C1BF  0000              add [bx+si],al
0000C1C1  0000              add [bx+si],al
0000C1C3  0000              add [bx+si],al
0000C1C5  0000              add [bx+si],al
0000C1C7  0000              add [bx+si],al
0000C1C9  0000              add [bx+si],al
0000C1CB  0000              add [bx+si],al
0000C1CD  0000              add [bx+si],al
0000C1CF  0000              add [bx+si],al
0000C1D1  0000              add [bx+si],al
0000C1D3  0000              add [bx+si],al
0000C1D5  0000              add [bx+si],al
0000C1D7  0000              add [bx+si],al
0000C1D9  0000              add [bx+si],al
0000C1DB  0000              add [bx+si],al
0000C1DD  0000              add [bx+si],al
0000C1DF  0000              add [bx+si],al
0000C1E1  0000              add [bx+si],al
0000C1E3  0000              add [bx+si],al
0000C1E5  0000              add [bx+si],al
0000C1E7  0000              add [bx+si],al
0000C1E9  0000              add [bx+si],al
0000C1EB  0000              add [bx+si],al
0000C1ED  0000              add [bx+si],al
0000C1EF  0000              add [bx+si],al
0000C1F1  0000              add [bx+si],al
0000C1F3  0000              add [bx+si],al
0000C1F5  0000              add [bx+si],al
0000C1F7  0000              add [bx+si],al
0000C1F9  0000              add [bx+si],al
0000C1FB  0000              add [bx+si],al
0000C1FD  0000              add [bx+si],al
0000C1FF  0000              add [bx+si],al
0000C201  0000              add [bx+si],al
0000C203  0000              add [bx+si],al
0000C205  0000              add [bx+si],al
0000C207  0000              add [bx+si],al
0000C209  0000              add [bx+si],al
0000C20B  0000              add [bx+si],al
0000C20D  0000              add [bx+si],al
0000C20F  0000              add [bx+si],al
0000C211  0000              add [bx+si],al
0000C213  0000              add [bx+si],al
0000C215  0000              add [bx+si],al
0000C217  0000              add [bx+si],al
0000C219  0000              add [bx+si],al
0000C21B  0000              add [bx+si],al
0000C21D  0000              add [bx+si],al
0000C21F  0000              add [bx+si],al
0000C221  0000              add [bx+si],al
0000C223  0000              add [bx+si],al
0000C225  0000              add [bx+si],al
0000C227  0000              add [bx+si],al
0000C229  0000              add [bx+si],al
0000C22B  0000              add [bx+si],al
0000C22D  0000              add [bx+si],al
0000C22F  0000              add [bx+si],al
0000C231  0000              add [bx+si],al
0000C233  0000              add [bx+si],al
0000C235  0000              add [bx+si],al
0000C237  0000              add [bx+si],al
0000C239  0000              add [bx+si],al
0000C23B  0000              add [bx+si],al
0000C23D  0000              add [bx+si],al
0000C23F  0000              add [bx+si],al
0000C241  0000              add [bx+si],al
0000C243  0000              add [bx+si],al
0000C245  0000              add [bx+si],al
0000C247  0000              add [bx+si],al
0000C249  0000              add [bx+si],al
0000C24B  0000              add [bx+si],al
0000C24D  0000              add [bx+si],al
0000C24F  0000              add [bx+si],al
0000C251  0000              add [bx+si],al
0000C253  0000              add [bx+si],al
0000C255  0000              add [bx+si],al
0000C257  0000              add [bx+si],al
0000C259  0000              add [bx+si],al
0000C25B  0000              add [bx+si],al
0000C25D  0000              add [bx+si],al
0000C25F  0000              add [bx+si],al
0000C261  0000              add [bx+si],al
0000C263  0000              add [bx+si],al
0000C265  0000              add [bx+si],al
0000C267  0000              add [bx+si],al
0000C269  0000              add [bx+si],al
0000C26B  0000              add [bx+si],al
0000C26D  0000              add [bx+si],al
0000C26F  0000              add [bx+si],al
0000C271  0000              add [bx+si],al
0000C273  0000              add [bx+si],al
0000C275  0000              add [bx+si],al
0000C277  0000              add [bx+si],al
0000C279  0000              add [bx+si],al
0000C27B  0000              add [bx+si],al
0000C27D  0000              add [bx+si],al
0000C27F  0000              add [bx+si],al
0000C281  0000              add [bx+si],al
0000C283  0000              add [bx+si],al
0000C285  0000              add [bx+si],al
0000C287  0000              add [bx+si],al
0000C289  0000              add [bx+si],al
0000C28B  0000              add [bx+si],al
0000C28D  0000              add [bx+si],al
0000C28F  0000              add [bx+si],al
0000C291  0000              add [bx+si],al
0000C293  0000              add [bx+si],al
0000C295  0000              add [bx+si],al
0000C297  0000              add [bx+si],al
0000C299  0000              add [bx+si],al
0000C29B  0000              add [bx+si],al
0000C29D  0000              add [bx+si],al
0000C29F  0000              add [bx+si],al
0000C2A1  0000              add [bx+si],al
0000C2A3  0000              add [bx+si],al
0000C2A5  0000              add [bx+si],al
0000C2A7  0000              add [bx+si],al
0000C2A9  0000              add [bx+si],al
0000C2AB  0000              add [bx+si],al
0000C2AD  0000              add [bx+si],al
0000C2AF  0000              add [bx+si],al
0000C2B1  0000              add [bx+si],al
0000C2B3  0000              add [bx+si],al
0000C2B5  0000              add [bx+si],al
0000C2B7  0000              add [bx+si],al
0000C2B9  0000              add [bx+si],al
0000C2BB  0000              add [bx+si],al
0000C2BD  0000              add [bx+si],al
0000C2BF  0000              add [bx+si],al
0000C2C1  0000              add [bx+si],al
0000C2C3  0000              add [bx+si],al
0000C2C5  0000              add [bx+si],al
0000C2C7  0000              add [bx+si],al
0000C2C9  0000              add [bx+si],al
0000C2CB  0000              add [bx+si],al
0000C2CD  0000              add [bx+si],al
0000C2CF  0000              add [bx+si],al
0000C2D1  0000              add [bx+si],al
0000C2D3  0000              add [bx+si],al
0000C2D5  0000              add [bx+si],al
0000C2D7  0000              add [bx+si],al
0000C2D9  0000              add [bx+si],al
0000C2DB  0000              add [bx+si],al
0000C2DD  0000              add [bx+si],al
0000C2DF  0000              add [bx+si],al
0000C2E1  0000              add [bx+si],al
0000C2E3  0000              add [bx+si],al
0000C2E5  0000              add [bx+si],al
0000C2E7  0000              add [bx+si],al
0000C2E9  0000              add [bx+si],al
0000C2EB  0000              add [bx+si],al
0000C2ED  0000              add [bx+si],al
0000C2EF  0000              add [bx+si],al
0000C2F1  0000              add [bx+si],al
0000C2F3  0000              add [bx+si],al
0000C2F5  0000              add [bx+si],al
0000C2F7  0000              add [bx+si],al
0000C2F9  0000              add [bx+si],al
0000C2FB  0000              add [bx+si],al
0000C2FD  0000              add [bx+si],al
0000C2FF  0000              add [bx+si],al
0000C301  0000              add [bx+si],al
0000C303  0000              add [bx+si],al
0000C305  0000              add [bx+si],al
0000C307  0000              add [bx+si],al
0000C309  0000              add [bx+si],al
0000C30B  0000              add [bx+si],al
0000C30D  0000              add [bx+si],al
0000C30F  0000              add [bx+si],al
0000C311  0000              add [bx+si],al
0000C313  0000              add [bx+si],al
0000C315  0000              add [bx+si],al
0000C317  0000              add [bx+si],al
0000C319  0000              add [bx+si],al
0000C31B  0000              add [bx+si],al
0000C31D  0000              add [bx+si],al
0000C31F  0000              add [bx+si],al
0000C321  0000              add [bx+si],al
0000C323  0000              add [bx+si],al
0000C325  0000              add [bx+si],al
0000C327  0000              add [bx+si],al
0000C329  0000              add [bx+si],al
0000C32B  0000              add [bx+si],al
0000C32D  0000              add [bx+si],al
0000C32F  0000              add [bx+si],al
0000C331  0000              add [bx+si],al
0000C333  0000              add [bx+si],al
0000C335  0000              add [bx+si],al
0000C337  0000              add [bx+si],al
0000C339  0000              add [bx+si],al
0000C33B  0000              add [bx+si],al
0000C33D  0000              add [bx+si],al
0000C33F  0000              add [bx+si],al
0000C341  0000              add [bx+si],al
0000C343  0000              add [bx+si],al
0000C345  0000              add [bx+si],al
0000C347  0000              add [bx+si],al
0000C349  0000              add [bx+si],al
0000C34B  0000              add [bx+si],al
0000C34D  0000              add [bx+si],al
0000C34F  0000              add [bx+si],al
0000C351  0000              add [bx+si],al
0000C353  0000              add [bx+si],al
0000C355  0000              add [bx+si],al
0000C357  0000              add [bx+si],al
0000C359  0000              add [bx+si],al
0000C35B  0000              add [bx+si],al
0000C35D  0000              add [bx+si],al
0000C35F  0000              add [bx+si],al
0000C361  0000              add [bx+si],al
0000C363  0000              add [bx+si],al
0000C365  0000              add [bx+si],al
0000C367  0000              add [bx+si],al
0000C369  0000              add [bx+si],al
0000C36B  0000              add [bx+si],al
0000C36D  0000              add [bx+si],al
0000C36F  0000              add [bx+si],al
0000C371  0000              add [bx+si],al
0000C373  0000              add [bx+si],al
0000C375  0000              add [bx+si],al
0000C377  0000              add [bx+si],al
0000C379  0000              add [bx+si],al
0000C37B  0000              add [bx+si],al
0000C37D  0000              add [bx+si],al
0000C37F  0000              add [bx+si],al
0000C381  0000              add [bx+si],al
0000C383  0000              add [bx+si],al
0000C385  0000              add [bx+si],al
0000C387  0000              add [bx+si],al
0000C389  0000              add [bx+si],al
0000C38B  0000              add [bx+si],al
0000C38D  0000              add [bx+si],al
0000C38F  0000              add [bx+si],al
0000C391  0000              add [bx+si],al
0000C393  0000              add [bx+si],al
0000C395  0000              add [bx+si],al
0000C397  0000              add [bx+si],al
0000C399  0000              add [bx+si],al
0000C39B  0000              add [bx+si],al
0000C39D  0000              add [bx+si],al
0000C39F  0000              add [bx+si],al
0000C3A1  0000              add [bx+si],al
0000C3A3  0000              add [bx+si],al
0000C3A5  0000              add [bx+si],al
0000C3A7  0000              add [bx+si],al
0000C3A9  0000              add [bx+si],al
0000C3AB  0000              add [bx+si],al
0000C3AD  0000              add [bx+si],al
0000C3AF  0000              add [bx+si],al
0000C3B1  0000              add [bx+si],al
0000C3B3  0000              add [bx+si],al
0000C3B5  0000              add [bx+si],al
0000C3B7  0000              add [bx+si],al
0000C3B9  0000              add [bx+si],al
0000C3BB  0000              add [bx+si],al
0000C3BD  0000              add [bx+si],al
0000C3BF  0000              add [bx+si],al
0000C3C1  0000              add [bx+si],al
0000C3C3  0000              add [bx+si],al
0000C3C5  0000              add [bx+si],al
0000C3C7  0000              add [bx+si],al
0000C3C9  0000              add [bx+si],al
0000C3CB  0000              add [bx+si],al
0000C3CD  0000              add [bx+si],al
0000C3CF  0000              add [bx+si],al
0000C3D1  0000              add [bx+si],al
0000C3D3  0000              add [bx+si],al
0000C3D5  0000              add [bx+si],al
0000C3D7  0000              add [bx+si],al
0000C3D9  0000              add [bx+si],al
0000C3DB  0000              add [bx+si],al
0000C3DD  0000              add [bx+si],al
0000C3DF  0000              add [bx+si],al
0000C3E1  0000              add [bx+si],al
0000C3E3  0000              add [bx+si],al
0000C3E5  0000              add [bx+si],al
0000C3E7  0000              add [bx+si],al
0000C3E9  0000              add [bx+si],al
0000C3EB  0000              add [bx+si],al
0000C3ED  0000              add [bx+si],al
0000C3EF  0000              add [bx+si],al
0000C3F1  0000              add [bx+si],al
0000C3F3  0000              add [bx+si],al
0000C3F5  0000              add [bx+si],al
0000C3F7  0000              add [bx+si],al
0000C3F9  0000              add [bx+si],al
0000C3FB  0000              add [bx+si],al
0000C3FD  0000              add [bx+si],al
0000C3FF  0000              add [bx+si],al
0000C401  0000              add [bx+si],al
0000C403  0000              add [bx+si],al
0000C405  0000              add [bx+si],al
0000C407  0000              add [bx+si],al
0000C409  0000              add [bx+si],al
0000C40B  0000              add [bx+si],al
0000C40D  0000              add [bx+si],al
0000C40F  0000              add [bx+si],al
0000C411  0000              add [bx+si],al
0000C413  0000              add [bx+si],al
0000C415  0000              add [bx+si],al
0000C417  0000              add [bx+si],al
0000C419  0000              add [bx+si],al
0000C41B  0000              add [bx+si],al
0000C41D  0000              add [bx+si],al
0000C41F  0000              add [bx+si],al
0000C421  0000              add [bx+si],al
0000C423  0000              add [bx+si],al
0000C425  0000              add [bx+si],al
0000C427  0000              add [bx+si],al
0000C429  0000              add [bx+si],al
0000C42B  0000              add [bx+si],al
0000C42D  0000              add [bx+si],al
0000C42F  0000              add [bx+si],al
0000C431  0000              add [bx+si],al
0000C433  0000              add [bx+si],al
0000C435  0000              add [bx+si],al
0000C437  0000              add [bx+si],al
0000C439  0000              add [bx+si],al
0000C43B  0000              add [bx+si],al
0000C43D  0000              add [bx+si],al
0000C43F  0000              add [bx+si],al
0000C441  0000              add [bx+si],al
0000C443  0000              add [bx+si],al
0000C445  0000              add [bx+si],al
0000C447  0000              add [bx+si],al
0000C449  0000              add [bx+si],al
0000C44B  0000              add [bx+si],al
0000C44D  0000              add [bx+si],al
0000C44F  0000              add [bx+si],al
0000C451  0000              add [bx+si],al
0000C453  0000              add [bx+si],al
0000C455  0000              add [bx+si],al
0000C457  0000              add [bx+si],al
0000C459  0000              add [bx+si],al
0000C45B  0000              add [bx+si],al
0000C45D  0000              add [bx+si],al
0000C45F  0000              add [bx+si],al
0000C461  0000              add [bx+si],al
0000C463  0000              add [bx+si],al
0000C465  0000              add [bx+si],al
0000C467  0000              add [bx+si],al
0000C469  0000              add [bx+si],al
0000C46B  0000              add [bx+si],al
0000C46D  0000              add [bx+si],al
0000C46F  0000              add [bx+si],al
0000C471  0000              add [bx+si],al
0000C473  0000              add [bx+si],al
0000C475  0000              add [bx+si],al
0000C477  0000              add [bx+si],al
0000C479  0000              add [bx+si],al
0000C47B  0000              add [bx+si],al
0000C47D  0000              add [bx+si],al
0000C47F  0000              add [bx+si],al
0000C481  0000              add [bx+si],al
0000C483  0000              add [bx+si],al
0000C485  0000              add [bx+si],al
0000C487  0000              add [bx+si],al
0000C489  0000              add [bx+si],al
0000C48B  0000              add [bx+si],al
0000C48D  0000              add [bx+si],al
0000C48F  0000              add [bx+si],al
0000C491  0000              add [bx+si],al
0000C493  0000              add [bx+si],al
0000C495  0000              add [bx+si],al
0000C497  0000              add [bx+si],al
0000C499  0000              add [bx+si],al
0000C49B  0000              add [bx+si],al
0000C49D  0000              add [bx+si],al
0000C49F  0000              add [bx+si],al
0000C4A1  0000              add [bx+si],al
0000C4A3  0000              add [bx+si],al
0000C4A5  0000              add [bx+si],al
0000C4A7  0000              add [bx+si],al
0000C4A9  0000              add [bx+si],al
0000C4AB  0000              add [bx+si],al
0000C4AD  0000              add [bx+si],al
0000C4AF  0000              add [bx+si],al
0000C4B1  0000              add [bx+si],al
0000C4B3  0000              add [bx+si],al
0000C4B5  0000              add [bx+si],al
0000C4B7  0000              add [bx+si],al
0000C4B9  0000              add [bx+si],al
0000C4BB  0000              add [bx+si],al
0000C4BD  0000              add [bx+si],al
0000C4BF  0000              add [bx+si],al
0000C4C1  0000              add [bx+si],al
0000C4C3  0000              add [bx+si],al
0000C4C5  0000              add [bx+si],al
0000C4C7  0000              add [bx+si],al
0000C4C9  0000              add [bx+si],al
0000C4CB  0000              add [bx+si],al
0000C4CD  0000              add [bx+si],al
0000C4CF  0000              add [bx+si],al
0000C4D1  0000              add [bx+si],al
0000C4D3  0000              add [bx+si],al
0000C4D5  0000              add [bx+si],al
0000C4D7  0000              add [bx+si],al
0000C4D9  0000              add [bx+si],al
0000C4DB  0000              add [bx+si],al
0000C4DD  0000              add [bx+si],al
0000C4DF  0000              add [bx+si],al
0000C4E1  0000              add [bx+si],al
0000C4E3  0000              add [bx+si],al
0000C4E5  0000              add [bx+si],al
0000C4E7  0000              add [bx+si],al
0000C4E9  0000              add [bx+si],al
0000C4EB  0000              add [bx+si],al
0000C4ED  0000              add [bx+si],al
0000C4EF  0000              add [bx+si],al
0000C4F1  0000              add [bx+si],al
0000C4F3  0000              add [bx+si],al
0000C4F5  0000              add [bx+si],al
0000C4F7  0000              add [bx+si],al
0000C4F9  0000              add [bx+si],al
0000C4FB  0000              add [bx+si],al
0000C4FD  0000              add [bx+si],al
0000C4FF  0000              add [bx+si],al
0000C501  0000              add [bx+si],al
0000C503  0000              add [bx+si],al
0000C505  0000              add [bx+si],al
0000C507  0000              add [bx+si],al
0000C509  0000              add [bx+si],al
0000C50B  0000              add [bx+si],al
0000C50D  0000              add [bx+si],al
0000C50F  0000              add [bx+si],al
0000C511  0000              add [bx+si],al
0000C513  0000              add [bx+si],al
0000C515  0000              add [bx+si],al
0000C517  0000              add [bx+si],al
0000C519  0000              add [bx+si],al
0000C51B  0000              add [bx+si],al
0000C51D  0000              add [bx+si],al
0000C51F  0000              add [bx+si],al
0000C521  0000              add [bx+si],al
0000C523  0000              add [bx+si],al
0000C525  0000              add [bx+si],al
0000C527  0000              add [bx+si],al
0000C529  0000              add [bx+si],al
0000C52B  0000              add [bx+si],al
0000C52D  0000              add [bx+si],al
0000C52F  0000              add [bx+si],al
0000C531  0000              add [bx+si],al
0000C533  0000              add [bx+si],al
0000C535  0000              add [bx+si],al
0000C537  0000              add [bx+si],al
0000C539  0000              add [bx+si],al
0000C53B  0000              add [bx+si],al
0000C53D  0000              add [bx+si],al
0000C53F  0000              add [bx+si],al
0000C541  0000              add [bx+si],al
0000C543  0000              add [bx+si],al
0000C545  0000              add [bx+si],al
0000C547  0000              add [bx+si],al
0000C549  0000              add [bx+si],al
0000C54B  0000              add [bx+si],al
0000C54D  0000              add [bx+si],al
0000C54F  0000              add [bx+si],al
0000C551  0000              add [bx+si],al
0000C553  0000              add [bx+si],al
0000C555  0000              add [bx+si],al
0000C557  0000              add [bx+si],al
0000C559  0000              add [bx+si],al
0000C55B  0000              add [bx+si],al
0000C55D  0000              add [bx+si],al
0000C55F  0000              add [bx+si],al
0000C561  0000              add [bx+si],al
0000C563  0000              add [bx+si],al
0000C565  0000              add [bx+si],al
0000C567  0000              add [bx+si],al
0000C569  0000              add [bx+si],al
0000C56B  0000              add [bx+si],al
0000C56D  0000              add [bx+si],al
0000C56F  0000              add [bx+si],al
0000C571  0000              add [bx+si],al
0000C573  0000              add [bx+si],al
0000C575  0000              add [bx+si],al
0000C577  0000              add [bx+si],al
0000C579  0000              add [bx+si],al
0000C57B  0000              add [bx+si],al
0000C57D  0000              add [bx+si],al
0000C57F  0000              add [bx+si],al
0000C581  0000              add [bx+si],al
0000C583  0000              add [bx+si],al
0000C585  0000              add [bx+si],al
0000C587  0000              add [bx+si],al
0000C589  0000              add [bx+si],al
0000C58B  0000              add [bx+si],al
0000C58D  0000              add [bx+si],al
0000C58F  0000              add [bx+si],al
0000C591  0000              add [bx+si],al
0000C593  0000              add [bx+si],al
0000C595  0000              add [bx+si],al
0000C597  0000              add [bx+si],al
0000C599  0000              add [bx+si],al
0000C59B  0000              add [bx+si],al
0000C59D  0000              add [bx+si],al
0000C59F  0000              add [bx+si],al
0000C5A1  0000              add [bx+si],al
0000C5A3  0000              add [bx+si],al
0000C5A5  0000              add [bx+si],al
0000C5A7  0000              add [bx+si],al
0000C5A9  0000              add [bx+si],al
0000C5AB  0000              add [bx+si],al
0000C5AD  0000              add [bx+si],al
0000C5AF  0000              add [bx+si],al
0000C5B1  0000              add [bx+si],al
0000C5B3  0000              add [bx+si],al
0000C5B5  0000              add [bx+si],al
0000C5B7  0000              add [bx+si],al
0000C5B9  0000              add [bx+si],al
0000C5BB  0000              add [bx+si],al
0000C5BD  0000              add [bx+si],al
0000C5BF  0000              add [bx+si],al
0000C5C1  0000              add [bx+si],al
0000C5C3  0000              add [bx+si],al
0000C5C5  0000              add [bx+si],al
0000C5C7  0000              add [bx+si],al
0000C5C9  0000              add [bx+si],al
0000C5CB  0000              add [bx+si],al
0000C5CD  0000              add [bx+si],al
0000C5CF  0000              add [bx+si],al
0000C5D1  0000              add [bx+si],al
0000C5D3  0000              add [bx+si],al
0000C5D5  0000              add [bx+si],al
0000C5D7  0000              add [bx+si],al
0000C5D9  0000              add [bx+si],al
0000C5DB  0000              add [bx+si],al
0000C5DD  0000              add [bx+si],al
0000C5DF  0000              add [bx+si],al
0000C5E1  0000              add [bx+si],al
0000C5E3  0000              add [bx+si],al
0000C5E5  0000              add [bx+si],al
0000C5E7  0000              add [bx+si],al
0000C5E9  0000              add [bx+si],al
0000C5EB  0000              add [bx+si],al
0000C5ED  0000              add [bx+si],al
0000C5EF  0000              add [bx+si],al
0000C5F1  0000              add [bx+si],al
0000C5F3  0000              add [bx+si],al
0000C5F5  0000              add [bx+si],al
0000C5F7  0000              add [bx+si],al
0000C5F9  0000              add [bx+si],al
0000C5FB  0000              add [bx+si],al
0000C5FD  0000              add [bx+si],al
0000C5FF  0000              add [bx+si],al
0000C601  0000              add [bx+si],al
0000C603  0000              add [bx+si],al
0000C605  0000              add [bx+si],al
0000C607  0000              add [bx+si],al
0000C609  0000              add [bx+si],al
0000C60B  0000              add [bx+si],al
0000C60D  0000              add [bx+si],al
0000C60F  0000              add [bx+si],al
0000C611  0000              add [bx+si],al
0000C613  0000              add [bx+si],al
0000C615  0000              add [bx+si],al
0000C617  0000              add [bx+si],al
0000C619  0000              add [bx+si],al
0000C61B  0000              add [bx+si],al
0000C61D  0000              add [bx+si],al
0000C61F  0000              add [bx+si],al
0000C621  0000              add [bx+si],al
0000C623  0000              add [bx+si],al
0000C625  0000              add [bx+si],al
0000C627  0000              add [bx+si],al
0000C629  0000              add [bx+si],al
0000C62B  0000              add [bx+si],al
0000C62D  0000              add [bx+si],al
0000C62F  0000              add [bx+si],al
0000C631  0000              add [bx+si],al
0000C633  0000              add [bx+si],al
0000C635  0000              add [bx+si],al
0000C637  0000              add [bx+si],al
0000C639  0000              add [bx+si],al
0000C63B  0000              add [bx+si],al
0000C63D  0000              add [bx+si],al
0000C63F  0000              add [bx+si],al
0000C641  0000              add [bx+si],al
0000C643  0000              add [bx+si],al
0000C645  0000              add [bx+si],al
0000C647  0000              add [bx+si],al
0000C649  0000              add [bx+si],al
0000C64B  0000              add [bx+si],al
0000C64D  0000              add [bx+si],al
0000C64F  0000              add [bx+si],al
0000C651  0000              add [bx+si],al
0000C653  0000              add [bx+si],al
0000C655  0000              add [bx+si],al
0000C657  0000              add [bx+si],al
0000C659  0000              add [bx+si],al
0000C65B  0000              add [bx+si],al
0000C65D  0000              add [bx+si],al
0000C65F  0000              add [bx+si],al
0000C661  0000              add [bx+si],al
0000C663  0000              add [bx+si],al
0000C665  0000              add [bx+si],al
0000C667  0000              add [bx+si],al
0000C669  0000              add [bx+si],al
0000C66B  0000              add [bx+si],al
0000C66D  0000              add [bx+si],al
0000C66F  0000              add [bx+si],al
0000C671  0000              add [bx+si],al
0000C673  0000              add [bx+si],al
0000C675  0000              add [bx+si],al
0000C677  0000              add [bx+si],al
0000C679  0000              add [bx+si],al
0000C67B  0000              add [bx+si],al
0000C67D  0000              add [bx+si],al
0000C67F  0000              add [bx+si],al
0000C681  0000              add [bx+si],al
0000C683  0000              add [bx+si],al
0000C685  0000              add [bx+si],al
0000C687  0000              add [bx+si],al
0000C689  0000              add [bx+si],al
0000C68B  0000              add [bx+si],al
0000C68D  0000              add [bx+si],al
0000C68F  0000              add [bx+si],al
0000C691  0000              add [bx+si],al
0000C693  0000              add [bx+si],al
0000C695  0000              add [bx+si],al
0000C697  0000              add [bx+si],al
0000C699  0000              add [bx+si],al
0000C69B  0000              add [bx+si],al
0000C69D  0000              add [bx+si],al
0000C69F  0000              add [bx+si],al
0000C6A1  0000              add [bx+si],al
0000C6A3  0000              add [bx+si],al
0000C6A5  0000              add [bx+si],al
0000C6A7  0000              add [bx+si],al
0000C6A9  0000              add [bx+si],al
0000C6AB  0000              add [bx+si],al
0000C6AD  0000              add [bx+si],al
0000C6AF  0000              add [bx+si],al
0000C6B1  0000              add [bx+si],al
0000C6B3  0000              add [bx+si],al
0000C6B5  0000              add [bx+si],al
0000C6B7  0000              add [bx+si],al
0000C6B9  0000              add [bx+si],al
0000C6BB  0000              add [bx+si],al
0000C6BD  0000              add [bx+si],al
0000C6BF  0000              add [bx+si],al
0000C6C1  0000              add [bx+si],al
0000C6C3  0000              add [bx+si],al
0000C6C5  0000              add [bx+si],al
0000C6C7  0000              add [bx+si],al
0000C6C9  0000              add [bx+si],al
0000C6CB  0000              add [bx+si],al
0000C6CD  0000              add [bx+si],al
0000C6CF  0000              add [bx+si],al
0000C6D1  0000              add [bx+si],al
0000C6D3  0000              add [bx+si],al
0000C6D5  0000              add [bx+si],al
0000C6D7  0000              add [bx+si],al
0000C6D9  0000              add [bx+si],al
0000C6DB  0000              add [bx+si],al
0000C6DD  0000              add [bx+si],al
0000C6DF  0000              add [bx+si],al
0000C6E1  0000              add [bx+si],al
0000C6E3  0000              add [bx+si],al
0000C6E5  0000              add [bx+si],al
0000C6E7  0000              add [bx+si],al
0000C6E9  0000              add [bx+si],al
0000C6EB  0000              add [bx+si],al
0000C6ED  0000              add [bx+si],al
0000C6EF  0000              add [bx+si],al
0000C6F1  0000              add [bx+si],al
0000C6F3  0000              add [bx+si],al
0000C6F5  0000              add [bx+si],al
0000C6F7  0000              add [bx+si],al
0000C6F9  0000              add [bx+si],al
0000C6FB  0000              add [bx+si],al
0000C6FD  0000              add [bx+si],al
0000C6FF  0000              add [bx+si],al
0000C701  0000              add [bx+si],al
0000C703  0000              add [bx+si],al
0000C705  0000              add [bx+si],al
0000C707  0000              add [bx+si],al
0000C709  0000              add [bx+si],al
0000C70B  0000              add [bx+si],al
0000C70D  0000              add [bx+si],al
0000C70F  0000              add [bx+si],al
0000C711  0000              add [bx+si],al
0000C713  0000              add [bx+si],al
0000C715  0000              add [bx+si],al
0000C717  0000              add [bx+si],al
0000C719  0000              add [bx+si],al
0000C71B  0000              add [bx+si],al
0000C71D  0000              add [bx+si],al
0000C71F  0000              add [bx+si],al
0000C721  0000              add [bx+si],al
0000C723  0000              add [bx+si],al
0000C725  0000              add [bx+si],al
0000C727  0000              add [bx+si],al
0000C729  0000              add [bx+si],al
0000C72B  0000              add [bx+si],al
0000C72D  0000              add [bx+si],al
0000C72F  0000              add [bx+si],al
0000C731  0000              add [bx+si],al
0000C733  0000              add [bx+si],al
0000C735  0000              add [bx+si],al
0000C737  0000              add [bx+si],al
0000C739  0000              add [bx+si],al
0000C73B  0000              add [bx+si],al
0000C73D  0000              add [bx+si],al
0000C73F  0000              add [bx+si],al
0000C741  0000              add [bx+si],al
0000C743  0000              add [bx+si],al
0000C745  0000              add [bx+si],al
0000C747  0000              add [bx+si],al
0000C749  0000              add [bx+si],al
0000C74B  0000              add [bx+si],al
0000C74D  0000              add [bx+si],al
0000C74F  0000              add [bx+si],al
0000C751  0000              add [bx+si],al
0000C753  0000              add [bx+si],al
0000C755  0000              add [bx+si],al
0000C757  0000              add [bx+si],al
0000C759  0000              add [bx+si],al
0000C75B  0000              add [bx+si],al
0000C75D  0000              add [bx+si],al
0000C75F  0000              add [bx+si],al
0000C761  0000              add [bx+si],al
0000C763  0000              add [bx+si],al
0000C765  0000              add [bx+si],al
0000C767  0000              add [bx+si],al
0000C769  0000              add [bx+si],al
0000C76B  0000              add [bx+si],al
0000C76D  0000              add [bx+si],al
0000C76F  0000              add [bx+si],al
0000C771  0000              add [bx+si],al
0000C773  0000              add [bx+si],al
0000C775  0000              add [bx+si],al
0000C777  0000              add [bx+si],al
0000C779  0000              add [bx+si],al
0000C77B  0000              add [bx+si],al
0000C77D  0000              add [bx+si],al
0000C77F  0000              add [bx+si],al
0000C781  0000              add [bx+si],al
0000C783  0000              add [bx+si],al
0000C785  0000              add [bx+si],al
0000C787  0000              add [bx+si],al
0000C789  0000              add [bx+si],al
0000C78B  0000              add [bx+si],al
0000C78D  0000              add [bx+si],al
0000C78F  0000              add [bx+si],al
0000C791  0000              add [bx+si],al
0000C793  0000              add [bx+si],al
0000C795  0000              add [bx+si],al
0000C797  0000              add [bx+si],al
0000C799  0000              add [bx+si],al
0000C79B  0000              add [bx+si],al
0000C79D  0000              add [bx+si],al
0000C79F  0000              add [bx+si],al
0000C7A1  0000              add [bx+si],al
0000C7A3  0000              add [bx+si],al
0000C7A5  0000              add [bx+si],al
0000C7A7  0000              add [bx+si],al
0000C7A9  0000              add [bx+si],al
0000C7AB  0000              add [bx+si],al
0000C7AD  0000              add [bx+si],al
0000C7AF  0000              add [bx+si],al
0000C7B1  0000              add [bx+si],al
0000C7B3  0000              add [bx+si],al
0000C7B5  0000              add [bx+si],al
0000C7B7  0000              add [bx+si],al
0000C7B9  0000              add [bx+si],al
0000C7BB  0000              add [bx+si],al
0000C7BD  0000              add [bx+si],al
0000C7BF  0000              add [bx+si],al
0000C7C1  0000              add [bx+si],al
0000C7C3  0000              add [bx+si],al
0000C7C5  0000              add [bx+si],al
0000C7C7  0000              add [bx+si],al
0000C7C9  0000              add [bx+si],al
0000C7CB  0000              add [bx+si],al
0000C7CD  0000              add [bx+si],al
0000C7CF  0000              add [bx+si],al
0000C7D1  0000              add [bx+si],al
0000C7D3  0000              add [bx+si],al
0000C7D5  0000              add [bx+si],al
0000C7D7  0000              add [bx+si],al
0000C7D9  0000              add [bx+si],al
0000C7DB  0000              add [bx+si],al
0000C7DD  0000              add [bx+si],al
0000C7DF  0000              add [bx+si],al
0000C7E1  0000              add [bx+si],al
0000C7E3  0000              add [bx+si],al
0000C7E5  0000              add [bx+si],al
0000C7E7  0000              add [bx+si],al
0000C7E9  0000              add [bx+si],al
0000C7EB  0000              add [bx+si],al
0000C7ED  0000              add [bx+si],al
0000C7EF  0000              add [bx+si],al
0000C7F1  0000              add [bx+si],al
0000C7F3  0000              add [bx+si],al
0000C7F5  0000              add [bx+si],al
0000C7F7  0000              add [bx+si],al
0000C7F9  0000              add [bx+si],al
0000C7FB  0000              add [bx+si],al
0000C7FD  0000              add [bx+si],al
0000C7FF  0000              add [bx+si],al
0000C801  0000              add [bx+si],al
0000C803  0000              add [bx+si],al
0000C805  0000              add [bx+si],al
0000C807  0000              add [bx+si],al
0000C809  0000              add [bx+si],al
0000C80B  0000              add [bx+si],al
0000C80D  0000              add [bx+si],al
0000C80F  0000              add [bx+si],al
0000C811  0000              add [bx+si],al
0000C813  0000              add [bx+si],al
0000C815  0000              add [bx+si],al
0000C817  0000              add [bx+si],al
0000C819  0000              add [bx+si],al
0000C81B  0000              add [bx+si],al
0000C81D  0000              add [bx+si],al
0000C81F  0000              add [bx+si],al
0000C821  0000              add [bx+si],al
0000C823  0000              add [bx+si],al
0000C825  0000              add [bx+si],al
0000C827  0000              add [bx+si],al
0000C829  0000              add [bx+si],al
0000C82B  0000              add [bx+si],al
0000C82D  0000              add [bx+si],al
0000C82F  0000              add [bx+si],al
0000C831  0000              add [bx+si],al
0000C833  0000              add [bx+si],al
0000C835  0000              add [bx+si],al
0000C837  0000              add [bx+si],al
0000C839  0000              add [bx+si],al
0000C83B  0000              add [bx+si],al
0000C83D  0000              add [bx+si],al
0000C83F  0000              add [bx+si],al
0000C841  0000              add [bx+si],al
0000C843  0000              add [bx+si],al
0000C845  0000              add [bx+si],al
0000C847  0000              add [bx+si],al
0000C849  0000              add [bx+si],al
0000C84B  0000              add [bx+si],al
0000C84D  0000              add [bx+si],al
0000C84F  0000              add [bx+si],al
0000C851  0000              add [bx+si],al
0000C853  0000              add [bx+si],al
0000C855  0000              add [bx+si],al
0000C857  0000              add [bx+si],al
0000C859  0000              add [bx+si],al
0000C85B  0000              add [bx+si],al
0000C85D  0000              add [bx+si],al
0000C85F  0000              add [bx+si],al
0000C861  0000              add [bx+si],al
0000C863  0000              add [bx+si],al
0000C865  0000              add [bx+si],al
0000C867  0000              add [bx+si],al
0000C869  0000              add [bx+si],al
0000C86B  0000              add [bx+si],al
0000C86D  0000              add [bx+si],al
0000C86F  0000              add [bx+si],al
0000C871  0000              add [bx+si],al
0000C873  0000              add [bx+si],al
0000C875  0000              add [bx+si],al
0000C877  0000              add [bx+si],al
0000C879  0000              add [bx+si],al
0000C87B  0000              add [bx+si],al
0000C87D  0000              add [bx+si],al
0000C87F  0000              add [bx+si],al
0000C881  0000              add [bx+si],al
0000C883  0000              add [bx+si],al
0000C885  0000              add [bx+si],al
0000C887  0000              add [bx+si],al
0000C889  0000              add [bx+si],al
0000C88B  0000              add [bx+si],al
0000C88D  0000              add [bx+si],al
0000C88F  0000              add [bx+si],al
0000C891  0000              add [bx+si],al
0000C893  0000              add [bx+si],al
0000C895  0000              add [bx+si],al
0000C897  0000              add [bx+si],al
0000C899  0000              add [bx+si],al
0000C89B  0000              add [bx+si],al
0000C89D  0000              add [bx+si],al
0000C89F  0000              add [bx+si],al
0000C8A1  0000              add [bx+si],al
0000C8A3  0000              add [bx+si],al
0000C8A5  0000              add [bx+si],al
0000C8A7  0000              add [bx+si],al
0000C8A9  0000              add [bx+si],al
0000C8AB  0000              add [bx+si],al
0000C8AD  0000              add [bx+si],al
0000C8AF  0000              add [bx+si],al
0000C8B1  0000              add [bx+si],al
0000C8B3  0000              add [bx+si],al
0000C8B5  0000              add [bx+si],al
0000C8B7  0000              add [bx+si],al
0000C8B9  0000              add [bx+si],al
0000C8BB  0000              add [bx+si],al
0000C8BD  0000              add [bx+si],al
0000C8BF  0000              add [bx+si],al
0000C8C1  0000              add [bx+si],al
0000C8C3  0000              add [bx+si],al
0000C8C5  0000              add [bx+si],al
0000C8C7  0000              add [bx+si],al
0000C8C9  0000              add [bx+si],al
0000C8CB  0000              add [bx+si],al
0000C8CD  0000              add [bx+si],al
0000C8CF  0000              add [bx+si],al
0000C8D1  0000              add [bx+si],al
0000C8D3  0000              add [bx+si],al
0000C8D5  0000              add [bx+si],al
0000C8D7  0000              add [bx+si],al
0000C8D9  0000              add [bx+si],al
0000C8DB  0000              add [bx+si],al
0000C8DD  0000              add [bx+si],al
0000C8DF  0000              add [bx+si],al
0000C8E1  0000              add [bx+si],al
0000C8E3  0000              add [bx+si],al
0000C8E5  0000              add [bx+si],al
0000C8E7  0000              add [bx+si],al
0000C8E9  0000              add [bx+si],al
0000C8EB  0000              add [bx+si],al
0000C8ED  0000              add [bx+si],al
0000C8EF  0000              add [bx+si],al
0000C8F1  0000              add [bx+si],al
0000C8F3  0000              add [bx+si],al
0000C8F5  0000              add [bx+si],al
0000C8F7  0000              add [bx+si],al
0000C8F9  0000              add [bx+si],al
0000C8FB  0000              add [bx+si],al
0000C8FD  0000              add [bx+si],al
0000C8FF  0000              add [bx+si],al
0000C901  0000              add [bx+si],al
0000C903  0000              add [bx+si],al
0000C905  0000              add [bx+si],al
0000C907  0000              add [bx+si],al
0000C909  0000              add [bx+si],al
0000C90B  0000              add [bx+si],al
0000C90D  0000              add [bx+si],al
0000C90F  0000              add [bx+si],al
0000C911  0000              add [bx+si],al
0000C913  0000              add [bx+si],al
0000C915  0000              add [bx+si],al
0000C917  0000              add [bx+si],al
0000C919  0000              add [bx+si],al
0000C91B  0000              add [bx+si],al
0000C91D  0000              add [bx+si],al
0000C91F  0000              add [bx+si],al
0000C921  0000              add [bx+si],al
0000C923  0000              add [bx+si],al
0000C925  0000              add [bx+si],al
0000C927  0000              add [bx+si],al
0000C929  0000              add [bx+si],al
0000C92B  0000              add [bx+si],al
0000C92D  0000              add [bx+si],al
0000C92F  0000              add [bx+si],al
0000C931  0000              add [bx+si],al
0000C933  0000              add [bx+si],al
0000C935  0000              add [bx+si],al
0000C937  0000              add [bx+si],al
0000C939  0000              add [bx+si],al
0000C93B  0000              add [bx+si],al
0000C93D  0000              add [bx+si],al
0000C93F  0000              add [bx+si],al
0000C941  0000              add [bx+si],al
0000C943  0000              add [bx+si],al
0000C945  0000              add [bx+si],al
0000C947  0000              add [bx+si],al
0000C949  0000              add [bx+si],al
0000C94B  0000              add [bx+si],al
0000C94D  0000              add [bx+si],al
0000C94F  0000              add [bx+si],al
0000C951  0000              add [bx+si],al
0000C953  0000              add [bx+si],al
0000C955  0000              add [bx+si],al
0000C957  0000              add [bx+si],al
0000C959  0000              add [bx+si],al
0000C95B  0000              add [bx+si],al
0000C95D  0000              add [bx+si],al
0000C95F  0000              add [bx+si],al
0000C961  0000              add [bx+si],al
0000C963  0000              add [bx+si],al
0000C965  0000              add [bx+si],al
0000C967  0000              add [bx+si],al
0000C969  0000              add [bx+si],al
0000C96B  0000              add [bx+si],al
0000C96D  0000              add [bx+si],al
0000C96F  0000              add [bx+si],al
0000C971  0000              add [bx+si],al
0000C973  0000              add [bx+si],al
0000C975  0000              add [bx+si],al
0000C977  0000              add [bx+si],al
0000C979  0000              add [bx+si],al
0000C97B  0000              add [bx+si],al
0000C97D  0000              add [bx+si],al
0000C97F  0000              add [bx+si],al
0000C981  0000              add [bx+si],al
0000C983  0000              add [bx+si],al
0000C985  0000              add [bx+si],al
0000C987  0000              add [bx+si],al
0000C989  0000              add [bx+si],al
0000C98B  0000              add [bx+si],al
0000C98D  0000              add [bx+si],al
0000C98F  0000              add [bx+si],al
0000C991  0000              add [bx+si],al
0000C993  0000              add [bx+si],al
0000C995  0000              add [bx+si],al
0000C997  0000              add [bx+si],al
0000C999  0000              add [bx+si],al
0000C99B  0000              add [bx+si],al
0000C99D  0000              add [bx+si],al
0000C99F  0000              add [bx+si],al
0000C9A1  0000              add [bx+si],al
0000C9A3  0000              add [bx+si],al
0000C9A5  0000              add [bx+si],al
0000C9A7  0000              add [bx+si],al
0000C9A9  0000              add [bx+si],al
0000C9AB  0000              add [bx+si],al
0000C9AD  0000              add [bx+si],al
0000C9AF  0000              add [bx+si],al
0000C9B1  0000              add [bx+si],al
0000C9B3  0000              add [bx+si],al
0000C9B5  0000              add [bx+si],al
0000C9B7  0000              add [bx+si],al
0000C9B9  0000              add [bx+si],al
0000C9BB  0000              add [bx+si],al
0000C9BD  0000              add [bx+si],al
0000C9BF  0000              add [bx+si],al
0000C9C1  0000              add [bx+si],al
0000C9C3  0000              add [bx+si],al
0000C9C5  0000              add [bx+si],al
0000C9C7  0000              add [bx+si],al
0000C9C9  0000              add [bx+si],al
0000C9CB  0000              add [bx+si],al
0000C9CD  0000              add [bx+si],al
0000C9CF  0000              add [bx+si],al
0000C9D1  0000              add [bx+si],al
0000C9D3  0000              add [bx+si],al
0000C9D5  0000              add [bx+si],al
0000C9D7  0000              add [bx+si],al
0000C9D9  0000              add [bx+si],al
0000C9DB  0000              add [bx+si],al
0000C9DD  0000              add [bx+si],al
0000C9DF  0000              add [bx+si],al
0000C9E1  0000              add [bx+si],al
0000C9E3  0000              add [bx+si],al
0000C9E5  0000              add [bx+si],al
0000C9E7  0000              add [bx+si],al
0000C9E9  0000              add [bx+si],al
0000C9EB  0000              add [bx+si],al
0000C9ED  0000              add [bx+si],al
0000C9EF  0000              add [bx+si],al
0000C9F1  0000              add [bx+si],al
0000C9F3  0000              add [bx+si],al
0000C9F5  0000              add [bx+si],al
0000C9F7  0000              add [bx+si],al
0000C9F9  0000              add [bx+si],al
0000C9FB  0000              add [bx+si],al
0000C9FD  0000              add [bx+si],al
0000C9FF  0000              add [bx+si],al
0000CA01  0000              add [bx+si],al
0000CA03  0000              add [bx+si],al
0000CA05  0000              add [bx+si],al
0000CA07  0000              add [bx+si],al
0000CA09  0000              add [bx+si],al
0000CA0B  0000              add [bx+si],al
0000CA0D  0000              add [bx+si],al
0000CA0F  0000              add [bx+si],al
0000CA11  0000              add [bx+si],al
0000CA13  0000              add [bx+si],al
0000CA15  0000              add [bx+si],al
0000CA17  0000              add [bx+si],al
0000CA19  0000              add [bx+si],al
0000CA1B  0000              add [bx+si],al
0000CA1D  0000              add [bx+si],al
0000CA1F  0000              add [bx+si],al
0000CA21  0000              add [bx+si],al
0000CA23  0000              add [bx+si],al
0000CA25  0000              add [bx+si],al
0000CA27  0000              add [bx+si],al
0000CA29  0000              add [bx+si],al
0000CA2B  0000              add [bx+si],al
0000CA2D  0000              add [bx+si],al
0000CA2F  0000              add [bx+si],al
0000CA31  0000              add [bx+si],al
0000CA33  0000              add [bx+si],al
0000CA35  0000              add [bx+si],al
0000CA37  0000              add [bx+si],al
0000CA39  0000              add [bx+si],al
0000CA3B  0000              add [bx+si],al
0000CA3D  0000              add [bx+si],al
0000CA3F  0000              add [bx+si],al
0000CA41  0000              add [bx+si],al
0000CA43  0000              add [bx+si],al
0000CA45  0000              add [bx+si],al
0000CA47  0000              add [bx+si],al
0000CA49  0000              add [bx+si],al
0000CA4B  0000              add [bx+si],al
0000CA4D  0000              add [bx+si],al
0000CA4F  0000              add [bx+si],al
0000CA51  0000              add [bx+si],al
0000CA53  0000              add [bx+si],al
0000CA55  0000              add [bx+si],al
0000CA57  0000              add [bx+si],al
0000CA59  0000              add [bx+si],al
0000CA5B  0000              add [bx+si],al
0000CA5D  0000              add [bx+si],al
0000CA5F  0000              add [bx+si],al
0000CA61  0000              add [bx+si],al
0000CA63  0000              add [bx+si],al
0000CA65  0000              add [bx+si],al
0000CA67  0000              add [bx+si],al
0000CA69  0000              add [bx+si],al
0000CA6B  0000              add [bx+si],al
0000CA6D  0000              add [bx+si],al
0000CA6F  0000              add [bx+si],al
0000CA71  0000              add [bx+si],al
0000CA73  0000              add [bx+si],al
0000CA75  0000              add [bx+si],al
0000CA77  0000              add [bx+si],al
0000CA79  0000              add [bx+si],al
0000CA7B  0000              add [bx+si],al
0000CA7D  0000              add [bx+si],al
0000CA7F  0000              add [bx+si],al
0000CA81  0000              add [bx+si],al
0000CA83  0000              add [bx+si],al
0000CA85  0000              add [bx+si],al
0000CA87  0000              add [bx+si],al
0000CA89  0000              add [bx+si],al
0000CA8B  0000              add [bx+si],al
0000CA8D  0000              add [bx+si],al
0000CA8F  0000              add [bx+si],al
0000CA91  0000              add [bx+si],al
0000CA93  0000              add [bx+si],al
0000CA95  0000              add [bx+si],al
0000CA97  0000              add [bx+si],al
0000CA99  0000              add [bx+si],al
0000CA9B  0000              add [bx+si],al
0000CA9D  0000              add [bx+si],al
0000CA9F  0000              add [bx+si],al
0000CAA1  0000              add [bx+si],al
0000CAA3  0000              add [bx+si],al
0000CAA5  0000              add [bx+si],al
0000CAA7  0000              add [bx+si],al
0000CAA9  0000              add [bx+si],al
0000CAAB  0000              add [bx+si],al
0000CAAD  0000              add [bx+si],al
0000CAAF  0000              add [bx+si],al
0000CAB1  0000              add [bx+si],al
0000CAB3  0000              add [bx+si],al
0000CAB5  0000              add [bx+si],al
0000CAB7  0000              add [bx+si],al
0000CAB9  0000              add [bx+si],al
0000CABB  0000              add [bx+si],al
0000CABD  0000              add [bx+si],al
0000CABF  0000              add [bx+si],al
0000CAC1  0000              add [bx+si],al
0000CAC3  0000              add [bx+si],al
0000CAC5  0000              add [bx+si],al
0000CAC7  0000              add [bx+si],al
0000CAC9  0000              add [bx+si],al
0000CACB  0000              add [bx+si],al
0000CACD  0000              add [bx+si],al
0000CACF  0000              add [bx+si],al
0000CAD1  0000              add [bx+si],al
0000CAD3  0000              add [bx+si],al
0000CAD5  0000              add [bx+si],al
0000CAD7  0000              add [bx+si],al
0000CAD9  0000              add [bx+si],al
0000CADB  0000              add [bx+si],al
0000CADD  0000              add [bx+si],al
0000CADF  0000              add [bx+si],al
0000CAE1  0000              add [bx+si],al
0000CAE3  0000              add [bx+si],al
0000CAE5  0000              add [bx+si],al
0000CAE7  0000              add [bx+si],al
0000CAE9  0000              add [bx+si],al
0000CAEB  0000              add [bx+si],al
0000CAED  0000              add [bx+si],al
0000CAEF  0000              add [bx+si],al
0000CAF1  0000              add [bx+si],al
0000CAF3  0000              add [bx+si],al
0000CAF5  0000              add [bx+si],al
0000CAF7  0000              add [bx+si],al
0000CAF9  0000              add [bx+si],al
0000CAFB  0000              add [bx+si],al
0000CAFD  0000              add [bx+si],al
0000CAFF  0000              add [bx+si],al
0000CB01  0000              add [bx+si],al
0000CB03  0000              add [bx+si],al
0000CB05  0000              add [bx+si],al
0000CB07  0000              add [bx+si],al
0000CB09  0000              add [bx+si],al
0000CB0B  0000              add [bx+si],al
0000CB0D  0000              add [bx+si],al
0000CB0F  0000              add [bx+si],al
0000CB11  0000              add [bx+si],al
0000CB13  0000              add [bx+si],al
0000CB15  0000              add [bx+si],al
0000CB17  0000              add [bx+si],al
0000CB19  0000              add [bx+si],al
0000CB1B  0000              add [bx+si],al
0000CB1D  0000              add [bx+si],al
0000CB1F  0000              add [bx+si],al
0000CB21  0000              add [bx+si],al
0000CB23  0000              add [bx+si],al
0000CB25  0000              add [bx+si],al
0000CB27  0000              add [bx+si],al
0000CB29  0000              add [bx+si],al
0000CB2B  0000              add [bx+si],al
0000CB2D  0000              add [bx+si],al
0000CB2F  0000              add [bx+si],al
0000CB31  0000              add [bx+si],al
0000CB33  0000              add [bx+si],al
0000CB35  0000              add [bx+si],al
0000CB37  0000              add [bx+si],al
0000CB39  0000              add [bx+si],al
0000CB3B  0000              add [bx+si],al
0000CB3D  0000              add [bx+si],al
0000CB3F  0000              add [bx+si],al
0000CB41  0000              add [bx+si],al
0000CB43  0000              add [bx+si],al
0000CB45  0000              add [bx+si],al
0000CB47  0000              add [bx+si],al
0000CB49  0000              add [bx+si],al
0000CB4B  0000              add [bx+si],al
0000CB4D  0000              add [bx+si],al
0000CB4F  0000              add [bx+si],al
0000CB51  0000              add [bx+si],al
0000CB53  0000              add [bx+si],al
0000CB55  0000              add [bx+si],al
0000CB57  0000              add [bx+si],al
0000CB59  0000              add [bx+si],al
0000CB5B  0000              add [bx+si],al
0000CB5D  0000              add [bx+si],al
0000CB5F  0000              add [bx+si],al
0000CB61  0000              add [bx+si],al
0000CB63  0000              add [bx+si],al
0000CB65  0000              add [bx+si],al
0000CB67  0000              add [bx+si],al
0000CB69  0000              add [bx+si],al
0000CB6B  0000              add [bx+si],al
0000CB6D  0000              add [bx+si],al
0000CB6F  0000              add [bx+si],al
0000CB71  0000              add [bx+si],al
0000CB73  0000              add [bx+si],al
0000CB75  0000              add [bx+si],al
0000CB77  0000              add [bx+si],al
0000CB79  0000              add [bx+si],al
0000CB7B  0000              add [bx+si],al
0000CB7D  0000              add [bx+si],al
0000CB7F  0000              add [bx+si],al
0000CB81  0000              add [bx+si],al
0000CB83  0000              add [bx+si],al
0000CB85  0000              add [bx+si],al
0000CB87  0000              add [bx+si],al
0000CB89  0000              add [bx+si],al
0000CB8B  0000              add [bx+si],al
0000CB8D  0000              add [bx+si],al
0000CB8F  0000              add [bx+si],al
0000CB91  0000              add [bx+si],al
0000CB93  0000              add [bx+si],al
0000CB95  0000              add [bx+si],al
0000CB97  0000              add [bx+si],al
0000CB99  0000              add [bx+si],al
0000CB9B  0000              add [bx+si],al
0000CB9D  0000              add [bx+si],al
0000CB9F  0000              add [bx+si],al
0000CBA1  0000              add [bx+si],al
0000CBA3  0000              add [bx+si],al
0000CBA5  0000              add [bx+si],al
0000CBA7  0000              add [bx+si],al
0000CBA9  0000              add [bx+si],al
0000CBAB  0000              add [bx+si],al
0000CBAD  0000              add [bx+si],al
0000CBAF  0000              add [bx+si],al
0000CBB1  0000              add [bx+si],al
0000CBB3  0000              add [bx+si],al
0000CBB5  0000              add [bx+si],al
0000CBB7  0000              add [bx+si],al
0000CBB9  0000              add [bx+si],al
0000CBBB  0000              add [bx+si],al
0000CBBD  0000              add [bx+si],al
0000CBBF  0000              add [bx+si],al
0000CBC1  0000              add [bx+si],al
0000CBC3  0000              add [bx+si],al
0000CBC5  0000              add [bx+si],al
0000CBC7  0000              add [bx+si],al
0000CBC9  0000              add [bx+si],al
0000CBCB  0000              add [bx+si],al
0000CBCD  0000              add [bx+si],al
0000CBCF  0000              add [bx+si],al
0000CBD1  0000              add [bx+si],al
0000CBD3  0000              add [bx+si],al
0000CBD5  0000              add [bx+si],al
0000CBD7  0000              add [bx+si],al
0000CBD9  0000              add [bx+si],al
0000CBDB  0000              add [bx+si],al
0000CBDD  0000              add [bx+si],al
0000CBDF  0000              add [bx+si],al
0000CBE1  0000              add [bx+si],al
0000CBE3  0000              add [bx+si],al
0000CBE5  0000              add [bx+si],al
0000CBE7  0000              add [bx+si],al
0000CBE9  0000              add [bx+si],al
0000CBEB  0000              add [bx+si],al
0000CBED  0000              add [bx+si],al
0000CBEF  0000              add [bx+si],al
0000CBF1  0000              add [bx+si],al
0000CBF3  0000              add [bx+si],al
0000CBF5  0000              add [bx+si],al
0000CBF7  0000              add [bx+si],al
0000CBF9  0000              add [bx+si],al
0000CBFB  0000              add [bx+si],al
0000CBFD  0000              add [bx+si],al
0000CBFF  0000              add [bx+si],al
0000CC01  0000              add [bx+si],al
0000CC03  0000              add [bx+si],al
0000CC05  0000              add [bx+si],al
0000CC07  0000              add [bx+si],al
0000CC09  0000              add [bx+si],al
0000CC0B  0000              add [bx+si],al
0000CC0D  0000              add [bx+si],al
0000CC0F  0000              add [bx+si],al
0000CC11  0000              add [bx+si],al
0000CC13  0000              add [bx+si],al
0000CC15  0000              add [bx+si],al
0000CC17  0000              add [bx+si],al
0000CC19  0000              add [bx+si],al
0000CC1B  0000              add [bx+si],al
0000CC1D  0000              add [bx+si],al
0000CC1F  0000              add [bx+si],al
0000CC21  0000              add [bx+si],al
0000CC23  0000              add [bx+si],al
0000CC25  0000              add [bx+si],al
0000CC27  0000              add [bx+si],al
0000CC29  0000              add [bx+si],al
0000CC2B  0000              add [bx+si],al
0000CC2D  0000              add [bx+si],al
0000CC2F  0000              add [bx+si],al
0000CC31  0000              add [bx+si],al
0000CC33  0000              add [bx+si],al
0000CC35  0000              add [bx+si],al
0000CC37  0000              add [bx+si],al
0000CC39  0000              add [bx+si],al
0000CC3B  0000              add [bx+si],al
0000CC3D  0000              add [bx+si],al
0000CC3F  0000              add [bx+si],al
0000CC41  0000              add [bx+si],al
0000CC43  0000              add [bx+si],al
0000CC45  0000              add [bx+si],al
0000CC47  0000              add [bx+si],al
0000CC49  0000              add [bx+si],al
0000CC4B  0000              add [bx+si],al
0000CC4D  0000              add [bx+si],al
0000CC4F  0000              add [bx+si],al
0000CC51  0000              add [bx+si],al
0000CC53  0000              add [bx+si],al
0000CC55  0000              add [bx+si],al
0000CC57  0000              add [bx+si],al
0000CC59  0000              add [bx+si],al
0000CC5B  0000              add [bx+si],al
0000CC5D  0000              add [bx+si],al
0000CC5F  0000              add [bx+si],al
0000CC61  0000              add [bx+si],al
0000CC63  0000              add [bx+si],al
0000CC65  0000              add [bx+si],al
0000CC67  0000              add [bx+si],al
0000CC69  0000              add [bx+si],al
0000CC6B  0000              add [bx+si],al
0000CC6D  0000              add [bx+si],al
0000CC6F  0000              add [bx+si],al
0000CC71  0000              add [bx+si],al
0000CC73  0000              add [bx+si],al
0000CC75  0000              add [bx+si],al
0000CC77  0000              add [bx+si],al
0000CC79  0000              add [bx+si],al
0000CC7B  0000              add [bx+si],al
0000CC7D  0000              add [bx+si],al
0000CC7F  0000              add [bx+si],al
0000CC81  0000              add [bx+si],al
0000CC83  0000              add [bx+si],al
0000CC85  0000              add [bx+si],al
0000CC87  0000              add [bx+si],al
0000CC89  0000              add [bx+si],al
0000CC8B  0000              add [bx+si],al
0000CC8D  0000              add [bx+si],al
0000CC8F  0000              add [bx+si],al
0000CC91  00                db 0x00
