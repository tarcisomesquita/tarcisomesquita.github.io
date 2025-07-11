00401050  81EC04010000      sub esp,0x0000104
00401056  8D442400          lea eax,[esp+0x0]
0040105A  6804010000        push dword 0x0000104
0040105F  50                push eax
00401060  FF1508204000      call dword [dword 0x402008]
00401066  83C408            add esp,byte +0x8
00401069  85C0              test eax,eax
0040106B  7515              jnz 0x401082
0040106D  6810304000        push dword 0x403010
00401072  FF1504204000      call dword [dword 0x402004]
00401078  83C404            add esp,byte +0x4
0040107B  81C404010000      add esp,0x104
00401081  C3                ret
00401082  8D4C2400          lea ecx,[esp+0x0]
00401086  51                push ecx
00401087  6820304000        push dword 0x403020
0040108C  FF1524204000      call dword [dword 0x402024]
00401092  83C408            add esp,byte +0x8
00401095  81C404010000      add esp,0x104
0040109B  C3                ret
0040109C  90                nop
0040109D  90                nop
0040109E  90                nop
0040109F  90                nop
004010A0  55                push ebp
004010A1  8BEC              mov ebp,esp
004010A3  6AFF              push byte -0x1
004010A5  6848204000        push dword 0x402048
004010AA  68F0114000        push dword 0x4011f0
004010AF  64A100000000      mov eax,[fs:0x0]
004010B5  50                push eax
004010B6  64892500000000    mov [dword fs:0x0],esp
004010BD  83C4E0            add esp,byte -0x20
004010C0  53                push ebx
004010C1  56                push esi
004010C2  57                push edi
004010C3  8965E8            mov [ebp-0x18],esp
004010C6  C745FC00000000    mov dword [ebp-0x4],0x0
004010CD  6A01              push byte +0x1
004010CF  FF1534204000      call dword [dword 0x402034]
004010D5  83C404            add esp,byte +0x4
004010D8  C70540304000FFFF  mov dword [dword 0x403040],0xffffffff
         -FFFF
004010E2  C70544304000FFFF  mov dword [dword 0x403044],0xffffffff
         -FFFF
004010EC  FF1530204000      call dword [dword 0x402030]
004010F2  8B0D3C304000      mov ecx,[dword 0x40303c]
004010F8  8908              mov [eax],ecx
004010FA  FF152C204000      call dword [dword 0x40202c]
00401100  8B1538304000      mov edx,[dword 0x403038]
00401106  8910              mov [eax],edx
00401108  A128204000        mov eax,[0x402028]
0040110D  8B08              mov ecx,[eax]
0040110F  890D48304000      mov [dword 0x403048],ecx
00401115  E816010000        call dword 0x401230
0040111A  A124304000        mov eax,[0x403024]
0040111F  85C0              test eax,eax
00401121  750E              jnz 0x401131
00401123  68D0114000        push dword 0x4011d0
00401128  FF1500204000      call dword [dword 0x402000]
0040112E  83C404            add esp,byte +0x4
00401131  E8CA000000        call dword 0x401200
00401136  680C304000        push dword 0x40300c
0040113B  6808304000        push dword 0x403008
00401140  E8B1000000        call dword 0x4011f6
00401145  83C408            add esp,byte +0x8
00401148  8B1534304000      mov edx,[dword 0x403034]
0040114E  8955D8            mov [ebp-0x28],edx
00401151  8D45D8            lea eax,[ebp-0x28]
00401154  50                push eax
00401155  8B0D30304000      mov ecx,[dword 0x403030]
0040115B  51                push ecx
0040115C  8D55E0            lea edx,[ebp-0x20]
0040115F  52                push edx
00401160  8D45D4            lea eax,[ebp-0x2c]
00401163  50                push eax
00401164  8D4DE4            lea ecx,[ebp-0x1c]
00401167  51                push ecx
00401168  FF151C204000      call dword [dword 0x40201c]
0040116E  83C414            add esp,byte +0x14
00401171  6804304000        push dword 0x403004
00401176  6800304000        push dword 0x403000
0040117B  E876000000        call dword 0x4011f6
00401180  83C408            add esp,byte +0x8
00401183  FF1518204000      call dword [dword 0x402018]
00401189  8B55E0            mov edx,[ebp-0x20]
0040118C  8910              mov [eax],edx
0040118E  8B45E0            mov eax,[ebp-0x20]
00401191  50                push eax
00401192  8B4DD4            mov ecx,[ebp-0x2c]
00401195  51                push ecx
00401196  8B55E4            mov edx,[ebp-0x1c]
00401199  52                push edx
0040119A  E8B1FEFFFF        call dword 0x401050
0040119F  83C40C            add esp,byte +0xc
004011A2  8945DC            mov [ebp-0x24],eax
004011A5  50                push eax
004011A6  FF1514204000      call dword [dword 0x402014]
004011AC  EB22              jmp short 0x4011d0
004011AE  8B45EC            mov eax,[ebp-0x14]
004011B1  8B08              mov ecx,[eax]
004011B3  8B09              mov ecx,[ecx]
004011B5  894DD0            mov [ebp-0x30],ecx
004011B8  50                push eax
004011B9  51                push ecx
004011BA  E831000000        call dword 0x4011f0
004011BF  83C408            add esp,byte +0x8
004011C2  C3                ret
004011C3  8B65E8            mov esp,[ebp-0x18]
004011C6  8B55D0            mov edx,[ebp-0x30]
004011C9  52                push edx
004011CA  FF150C204000      call dword [dword 0x40200c]
004011D0  83C404            add esp,byte +0x4
004011D3  C745FCFFFFFFFF    mov dword [ebp-0x4],0xffffffff
004011DA  8B4DF0            mov ecx,[ebp-0x10]
004011DD  64890D00000000    mov [dword fs:0x0],ecx
004011E4  5F                pop edi
004011E5  5E                pop esi
004011E6  5B                pop ebx
004011E7  8BE5              mov esp,ebp
004011E9  5D                pop ebp
004011EA  C3                ret
004011EB  90                nop
004011EC  90                nop
004011ED  90                nop
004011EE  90                nop
004011EF  90                nop
004011F0  FF2510204000      jmp dword [dword 0x402010]
004011F6  FF2520204000      jmp dword [dword 0x402020]
004011FC  CC                int3
004011FD  CC                int3
004011FE  CC                int3
004011FF  CC                int3
00401200  6800000300        push dword 0x30000
00401205  6800000100        push dword 0x10000
0040120A  E837000000        call dword 0x401246
0040120F  83C408            add esp,byte +0x8
00401212  C3                ret
00401213  90                nop
00401214  90                nop
00401215  90                nop
00401216  90                nop
00401217  90                nop
00401218  90                nop
00401219  90                nop
0040121A  90                nop
0040121B  90                nop
0040121C  90                nop
0040121D  90                nop
0040121E  90                nop
0040121F  90                nop
00401220  33C0              xor eax,eax
00401222  C3                ret
00401223  90                nop
00401224  90                nop
00401225  90                nop
00401226  90                nop
00401227  90                nop
00401228  90                nop
00401229  90                nop
0040122A  90                nop
0040122B  90                nop
0040122C  90                nop
0040122D  90                nop
0040122E  90                nop
0040122F  90                nop
00401230  C3                ret
00401231  90                nop
00401232  90                nop
00401233  90                nop
00401234  90                nop
00401235  90                nop
00401236  90                nop
00401237  90                nop
00401238  90                nop
00401239  90                nop
0040123A  90                nop
0040123B  90                nop
0040123C  90                nop
0040123D  90                nop
0040123E  90                nop
0040123F  90                nop
00401240  FF2538204000      jmp dword [dword 0x402038]
00401246  FF253C204000      jmp dword [dword 0x40203c]
0040124C  0000              add [eax],al
0040124E  0000              add [eax],al
