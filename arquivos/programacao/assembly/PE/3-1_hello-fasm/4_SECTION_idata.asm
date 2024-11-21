idata_i:
OriginalFirstThunk_0:        .long OriginalFirstThunk_0_f00 - idata_i + 0x2000  # 0x0400 
TimeDateStamp_0:             .long 0x00000000   # 0x0404 
ForwarderChain_0:            .long 0x00000000   # 0x0408 
Name_o_0:                    .long Name_l_0 - idata_i + 0x2000  # 0x040C 
FirstThunk_0:                .long FirstThunk_0_f00 - idata_i + 0x2000  # 0x0410 

OriginalFirstThunk_1:        .long 0x2000 + OriginalFirstThunk_1_f00 - idata_i   # 0x0414 
TimeDateStamp_1:             .long 0x00000000   # 0x0418 
ForwarderChain_1:            .long 0x00000000   # 0x041C 
Name_o_1:                    .long 0x2000 + Name_l_1 - idata_i    # 0x0420 
FirstThunk_1:                .long 0x2000 + FirstThunk_1_f00 - idata_i   # 0x0424 

OriginalFirstThunk_2:        .long 0x00000000   # 0x0428 
TimeDateStamp_2:             .long 0x00000000   # 0x042C 
ForwarderChain_2:            .long 0x00000000   # 0x0430 
Name_o_2:                    .long 0x00000000   # 0x0434 
FirstThunk_2:                .long 0x00000000   # 0x0438 

Name_l_0:                    .ascii "KERNEL32.DLL"; .byte 0x00, 0x00  #  0x043C
Name_l_1:                    .ascii "USER32.DLL";   .byte 0x00, 0x00  #  0x044A
                             .byte 0x00, 0x00   # 0x044A

OriginalFirstThunk_0_f00:   .quad 0x2000 + Hint_l_0_f00 - idata_i  #  0x0458
OriginalFirstThunk_0_f01:   .quad 0x0000000000000000  #  0x0468

FT_KERNEL32.DLL_ExitProcess:
FirstThunk_0_f00:           .quad 0x2000 + Hint_l_0_f00 - idata_i  #  0x0470
FirstThunk_0_f01:           .quad 0x0000000000000000  #  0x0480

Hint_l_0_f00:               .byte 0x00, 0x00          #  0x0488
Name_l_0_f00:               .ascii "ExitProcess"; .byte 0x00  #  0x048A

OriginalFirstThunk_1_f00:   .quad 0x2000 + Hint_l_1_f00 - idata_i  #  0x04A8
OriginalFirstThunk_1_f01:   .quad 0x0000000000000000  #  0x04B0

FT_USER32.DLL_MessageBoxW:
FirstThunk_1_f00:           .quad 0x2000 + Hint_l_1_f00 - idata_i  #  0x04B8
FirstThunk_1_f01:           .quad 0x0000000000000000  #  0x04C0

Hint_l_1_f00:               .byte 0x00, 0x00          #  0x04C8
Name_l_1_f00:               .ascii "MessageBoxW"; .byte 0x00  #  0x04CA


# 000004d6:
.align 0x200, 0x00
idata_f:

