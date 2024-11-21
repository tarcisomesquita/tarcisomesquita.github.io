
push ebp
mov ebp, esp
and esp, 0xFFFFFFF0

r_eflag:  push 0x00000292

r_eax:    push 0x00000000
r_ecx:    push 0x00000000
r_edx:    push 0x00000000
r_ebx:    push 0x00000000
r_esp:    push esp
r_ebp:    push ebp
r_esi:    push 0x00000000
r_edi:    push 0x00000000

POPA
POPF

;pilha

push 0x00000001
push 0x00000002
push 0x00000003
push 0x00000004
push 0x00000005
push 0x00000006
push 0x00000007
push 0x00000008

