; REFAÇA TUDO COM A NOVA TELA

;  $ /media/SD/www/programacao/Assembly/compiladores/NASM/nasm.elf -f bin -o tdebug.elf 1_tdebug.asm && chmod +x tdebug.elf && ./tdebug.elf ; echo -e "\n$?"

%ifndef _tdebug
%define _tdebug
tdebug:

%include "include32/0_cabecalho.asm"

%include "2_estado_inicial.asm"

%include "3_codigo_teste.asm"

PUSHA   ; Push AX, CX, DX, BX, original SP, BP, SI, and DI.  ; [esp+52]
PUSHF   ; [esp+20]
PUSH CS ; [esp+16]
PUSH DS ; [esp+12]
PUSH SS ; [esp+8]
PUSH ES ; [esp+4]
PUSH FS ; [esp]

call write_registradores_stdout

MOV EBX, 0x00000006   ; retorno
MOV EAX, 0x00000001   ; sair
INT 0x80

%include "include32/4_write_registradores_stdout.asm"

loadsize equ $ - $$
%endif

