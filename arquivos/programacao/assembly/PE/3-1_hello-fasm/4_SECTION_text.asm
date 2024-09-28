O_MSG = msg - text_i + 0x401000
KERNEL32.DLL_ExitProcess = FT_KERNEL32.DLL_ExitProcess - idata_i + 0x402000
USER32.DLL_MessageBoxW   = FT_USER32.DLL_MessageBoxW   - idata_i + 0x402000


text_i:
sub rsp,0x08                  # 00401000  4883EC08
sub rsp,0x20                  # 00401004  4883EC20


mov rcx,0x0                   # 00401019  48C7C100000000
mov rdx, O_MSG
mov r9,0x0                    # 00401063  49C7C100000000

call QWORD PTR [USER32.DLL_MessageBoxW]   # 0040106A  FF1548100000         # 4020B8   FirstThunk_1_f00  MessageBoxW

mov rcx,0x00000000                  # 00401078  48C7C100000000
call QWORD PTR [KERNEL32.DLL_ExitProcess]

.align 0x10, 0x00

msg:
.byte 'H', 0x00, 'i', 0x00, 'l', 0x00, 'l', 0x00, 'o', 0x00, ' ', 0x00
.byte 'w', 0x00, 'o', 0x00, 'r', 0x00, 'l', 0x00, 'd', 0x00, '!', 0x00, 0x0a, 0x00


.align 0x200, 0x00

text_f:

