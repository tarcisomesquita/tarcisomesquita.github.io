
; input:  eax tem o offset do primeiro byte da string
; output: eax retorna o número de bytes escritos

%ifndef _write_registradores_stdout
%define _write_registradores_stdout

write_registradores_stdout_linha:
db 0x0A, "==============================================================================", 0x0A, 0x00

write_registradores_stdout_dados:

db \
"CS = ", 0x00, "   EAX = ", 0x00, "   ESP = ", 0x00, "   res= ", 0x00, "   res= ", 0x00, "   SF = ", 0x00, 0x0A, \
"DS = ", 0x00, "   ECX = ", 0x00, "   EBP = ", 0x00, "   res= ", 0x00, "   NT = ", 0x00, "   ZF = ", 0x00, 0x0A, \
"SS = ", 0x00, "   EDX = ", 0x00, "   ESI = ", 0x00, "   ID = ", 0x00, "   IO = ", 0x00, "   res= ", 0x00, 0x0A, \
"ES = ", 0x00, "   EBX = ", 0x00, "   EDI = ", 0x00, "   VIP= ", 0x00, "   IO = ", 0x00, "   AF = ", 0x00, 0x0A, \
"FS = ", 0x00, 0x0A, \
"                                                     VIF= ", 0x00, "   OF = ", 0x00, "   res= ", 0x00, 0x0A, \
"                                                     AC = ", 0x00, "   DF = ", 0x00, "   PF = ", 0x00, 0x0A, \
"                                                     VM = ", 0x00, "   IF = ", 0x00, "   res= ", 0x00, 0x0A, \
"                                                     RF = ", 0x00, "   TF = ", 0x00, "   CF = ", 0x00, 0x0A, \
0x0A, \
"           0 1  2 3   4 5  6 7    8 9  A B   C D  E F", 0x0A, 0x00

write_registradores_stdout:
; CALL write_registradores_stdout_geral
; CALL write_registradores_stdout_flags
; CALL write_registradores_stdout_segmento

PUSH write_registradores_stdout_dados

MOV  EAX, write_registradores_stdout_linha
CALL write_string_stdout

MOV  EAX, 0x0000000A
CALL write_char_stdout

; "CS ="
MOV  EAX, [esp]
CALL write_string_stdout
MOV  EAX, [esp+24]
call dword_to_string
CALL write_string_stdout

; "EAX ="
MOV  EAX, [esp]
ADD  EAX, 6
CALL write_string_stdout
MOV  EAX, [esp+60]
call dword_to_string
CALL write_string_stdout

; "ESP ="
MOV  EAX, [esp]
ADD  EAX, 16
CALL write_string_stdout
MOV  EAX, [esp+40]
call dword_to_string
CALL write_string_stdout

; "res="
MOV  EAX, [esp]
ADD  EAX, 26
CALL write_string_stdout
MOV  EAX, [esp+30]
BT   EAX,23
MOV  AL, 0x31
JC   write_registradores_stdout_FLAG_23
MOV  AL, 0x30
write_registradores_stdout_FLAG_23:
CALL write_char_stdout

; "res="
MOV  EAX, [esp]
ADD  EAX, 35
CALL write_string_stdout
MOV  EAX, [esp+30]
BT   EAX,15
MOV  AL, 0x31
JC   write_registradores_stdout_FLAG_15
MOV  AL, 0x30
write_registradores_stdout_FLAG_15:
CALL write_char_stdout

; "SF ="
MOV  EAX, [esp]
ADD  EAX, 44
CALL write_string_stdout
MOV  EAX, [esp+30]
BT   EAX,7
MOV  AL, 0x31
JC   write_registradores_stdout_FLAG_7
MOV  AL, 0x30
write_registradores_stdout_FLAG_7:
CALL write_char_stdout

; "DS ="
MOV  EAX, [esp]
ADD  EAX, 53
CALL write_string_stdout
MOV  EAX, [esp+20]
call dword_to_string
CALL write_string_stdout

; "ECX ="
MOV  EAX, [esp]
ADD  EAX, 60
CALL write_string_stdout
MOV  EAX, [esp+56]
call dword_to_string
CALL write_string_stdout

; "EBP ="
MOV  EAX, [esp]
ADD  EAX, 70
CALL write_string_stdout
MOV  EAX, [esp+40]
call dword_to_string
CALL write_string_stdout

; "res="
MOV  EAX, [esp]
ADD  EAX, 80
CALL write_string_stdout
MOV  EAX, [esp+30]
BT   EAX,22
MOV  AL, 0x31
JC   write_registradores_stdout_FLAG_22
MOV  AL, 0x30
write_registradores_stdout_FLAG_22:
CALL write_char_stdout

; "NT ="
MOV  EAX, [esp]
ADD  EAX, 89
CALL write_string_stdout
MOV  EAX, [esp+30]
BT   EAX,14
MOV  AL, 0x31
JC   write_registradores_stdout_FLAG_14
MOV  AL, 0x30
write_registradores_stdout_FLAG_14:
CALL write_char_stdout

; "ZF ="
MOV  EAX, [esp]
ADD  EAX, 98
CALL write_string_stdout
MOV  EAX, [esp+30]
BT   EAX,6
MOV  AL, 0x31
JC   write_registradores_stdout_FLAG_6
MOV  AL, 0x30
write_registradores_stdout_FLAG_6:
CALL write_char_stdout

; "SS ="
MOV  EAX, [esp]
ADD  EAX, 107
CALL write_string_stdout
MOV  EAX, [esp+16]
call dword_to_string
CALL write_string_stdout

; "EDX ="
MOV  EAX, [esp]
ADD  EAX, 114
CALL write_string_stdout
MOV  EAX, [esp+52]
call dword_to_string
CALL write_string_stdout

; "ESI ="
MOV  EAX, [esp]
ADD  EAX, 124
CALL write_string_stdout
MOV  EAX, [esp+36]
call dword_to_string
CALL write_string_stdout

POP EAX
RET


%include "include32/3_dword_to_string.asm"
%include "include32/2_byte_to_hex.asm"
%include "include32/2_write_char_stdout.asm"
%include "include32/2_write_string_stdout.asm"
%endif

