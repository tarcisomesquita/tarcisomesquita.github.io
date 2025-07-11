
; A idéia é deixar o estado guardado em algum lugar para poder recuperar quando quiser, mas não mudar o estado atual.

; Presupõe que foi usada a instrução MOV BP,SP no início do programa.

; input:  
; output: BX e CX possuem respctivamente o SEGMENTO e o OFFSET de onde começa o estado na memória.

%ifndef _estado_copia
   %define _estado_copia

estado_copia_numero equ 60

estado_copia:
PUSH  CS
PUSH  DS
PUSH  SS
PUSH  ES
PUSH  FS
PUSHA     ; Push AX, CX, DX, BX, original SP, BP, SI, and DI.
PUSHF

MOV   BX,BP
SUB   BX,SP

MOV   CX,estado_copia_numero ; Verifica se há espaço suficiente para armazenar a pilha.
ADD   CX,30
CMP   CX,BX
JNC   estado_copia_continue
CALL  escreve_enter_tela
MOV   SI,estado_copia_msg
CALL  escreve_string_tela
CALL  escreve_enter_tela
estado_copia_fim:
HLT
jmp short estado_copia_fim

estado_copia_continue:
MOV   AX,BP
MOV   BP,SP
MOV   BX,estado_copia_registradores

estado_copia_proximo:
MOV   CX,[BP]
MOV   [BX],CX

ADD   BP,0x02
ADD   BX,0x02

CMP   AX,BP
JNC   estado_copia_proximo

;MOV DX,estado_copia_registradores
;MOV CX, DX
;ADD CX,60
;CALL escreve_memoria_tela

POPF
POPA
ADD   SP,0x0A
RET

estado_copia_registradores:   ; bytes para os registradores.
times 30 db 0x00

estado_copia_pilha:           ; bytes para a pilha
times estado_copia_numero db 0x00

estado_copia_msg:
db "estado_copia: ERRO: BP-SP>estado_copia_numero+30", 0x0D, 0x0A, 0x00

%include "include/escreve_string_tela.asm"
%include "include/escreve_enter_tela.asm"

%endif

