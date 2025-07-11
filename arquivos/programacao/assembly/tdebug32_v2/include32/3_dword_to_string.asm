
; input:  AX deve conter a dword
; output: AX tem o endereço da string.

%ifndef _dword_to_string
%define _dword_to_string

dword_to_string:
push esi
push eax

mov  esi, dword_to_string_string
mov  eax, [esp]
call byte_to_hex
mov  [esi+6], ax

mov  eax, [esp]
ror  eax, 8
call byte_to_hex
mov  [esi+4], ax

mov  eax, [esp]
ror  eax, 16
call byte_to_hex
mov  [esi+2], ax

mov  eax, [esp]
ror  eax, 24
call byte_to_hex
mov  [esi], ax

pop  eax
mov  eax, dword_to_string_string
pop  esi
RET

dword_to_string_string:
db "AABBCCDD",0x00

%include "include32/2_byte_to_hex.asm"
%endif

