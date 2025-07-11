
; define o estado inicial
r_cs:     push 0x00000073
r_ds:     push 0x0000007b
r_ss:     push 0x0000007b
r_es:     push 0x0000007b
r_fs:     push 0x00000000

r_eflag:  push 0x00000292

r_eax:    push 0x00000000
r_ecx:    push 0x00000000
r_edx:    push 0x00000000
r_ebx:    push 0x00000000
r_esp:    push 0xbfed1c80
r_ebp:    push 0x00000000
r_esi:    push 0x00000000
r_edi:    push 0x00000000

POPA
POPF

;POP FS
;POP ES
;POP SS
;POP DS
;POP CS

