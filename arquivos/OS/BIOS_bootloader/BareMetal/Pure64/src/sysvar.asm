; =============================================================================
; Pure64 -- a 64-bit OS/software loader written in Assembly for x86-64 systems
; Copyright (C) 2008-2017 Return Infinity -- see LICENSE.TXT
;
; System Variables
; =============================================================================


;CONFIG
cfg_smpinit:		db 1	; By default SMP is enabled. Set to 0 to disable.
cfg_mbr:		db 0	; Did we boot off of a disk with a proper MBR
cfg_hdd:		db 0	; Was a bootable drive detected

; Memory locations
E820Map:		equ 0x0000000000004000
InfoMap:		equ 0x0000000000005000
SystemVariables:	equ 0x0000000000005A00

; DQ - Starting at offset 0, increments by 0x8
os_ACPITableAddress:	equ SystemVariables + 0x00
screen_cursor_offset:	equ SystemVariables + 0x08
os_LocalX2APICAddress:	equ SystemVariables + 0x10
os_Counter_Timer:	equ SystemVariables + 0x18
os_Counter_RTC:		equ SystemVariables + 0x20
os_LocalAPICAddress:	equ SystemVariables + 0x28
os_IOAPICAddress:	equ SystemVariables + 0x30
os_HPETAddress:		equ SystemVariables + 0x38

; DD - Starting at offset 128, increments by 4
os_BSP:			equ SystemVariables + 128
mem_amount:		equ SystemVariables + 132
os_VideoBase:		equ SystemVariables + 136

; DW - Starting at offset 256, increments by 2
cpu_speed:		equ SystemVariables + 256
cpu_activated:		equ SystemVariables + 258
cpu_detected:		equ SystemVariables + 260

; DB - Starting at offset 384, increments by 1
screen_cursor_x:	equ SystemVariables + 386
screen_cursor_y:	equ SystemVariables + 387
memtempstring:		equ SystemVariables + 390
speedtempstring:	equ SystemVariables + 400
cpu_amount_string:	equ SystemVariables + 410
os_key:			equ SystemVariables + 421
os_IOAPICCount:		equ SystemVariables + 424


align 16
GDTR32:					; Global Descriptors Table Register
	dw gdt32_end - gdt32 - 1	; limit of GDT (size minus one)
	dq gdt32			; linear address of GDT

align 16
gdt32:
	dw 0x0000, 0x0000, 0x0000, 0x0000	; Null desciptor
	dw 0xFFFF, 0x0000, 0x9A00, 0x00CF	; 32-bit code descriptor
	dw 0xFFFF, 0x0000, 0x9200, 0x00CF	; 32-bit data descriptor
gdt32_end:

; -----------------------------------------------------------------------------
align 16
GDTR64:					; Global Descriptors Table Register
	dw gdt64_end - gdt64 - 1	; limit of GDT (size minus one)
	dq 0x0000000000001000		; linear address of GDT

gdt64:					; This structure is copied to 0x0000000000001000
SYS64_NULL_SEL equ $-gdt64		; Null Segment
	dq 0x0000000000000000
SYS64_CODE_SEL equ $-gdt64		; Code segment, read/execute, nonconforming
	dq 0x0020980000000000		; 0x00209A0000000000
SYS64_DATA_SEL equ $-gdt64		; Data segment, read/write, expand down
	dq 0x0000900000000000		; 0x0020920000000000
gdt64_end:

IDTR64:					; Interrupt Descriptor Table Register
	dw 256*16-1			; limit of IDT (size minus one) (4096 bytes - 1)
	dq 0x0000000000000000		; linear address of IDT
; -----------------------------------------------------------------------------


; =============================================================================
; EOF
