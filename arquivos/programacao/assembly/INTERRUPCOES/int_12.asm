; return in AX the size of low memory in kilobytes.
; This function automatically decrements the returned size by the 1KB Extended BIOS Data Area, located in the top 1KB of low memory.

; Input: none.
; Output: AX - Kilobytes of low memory.

INT    12H

; para a máquina virtual retorna AX=0

