

; input:  [esp+0x04] o offset do primeiro byte da string

; output: eax o resultado
;         edx o offset do 0x00


strlen:
	mov	ebp, esp
	sub     esp, 0x1C

; str =          [ebp+0x04]      offset do primeiro byte da string
; char_ptr =     [ebp-0x04]
; longword_ptr = [ebp-0x08]
; longword =     [ebp-0x0C]
; himagic =      [ebp-0x10]
; lomagic =      [ebp-0x14]
; cp =           [ebp-0x18]
; ret     =      [ebp-0x1C]

        ; char_ptr = str
	mov	eax, [ebp+0x04]   
	mov	[ebp-0x04], eax
	jmp	.L2


.L5:    ; if (*char_ptr == '\0')
	mov	eax, [ebp-0x04]
	movzx	eax, BYTE [eax]
	test	al, al
	jnz	.L3  ; (ZF=0) salta se o byte não é 0x00

	mov	eax, [ebp-0x04] ; char_ptr
	mov	edx, [ebp+0x04] ; str
	sub	eax, edx
	mov	[ebp-0x1C], eax
	jmp	.L4

.L3:
	add	[ebp-0x04], 0x01

.L2:    ; char_ptr & 3 != 0
	mov	eax, [ebp-0x04] ; char_ptr
	and	eax, 0x03
	test	eax, eax
	jnz	.L5  ; se não está alinhado

; final do for

	; longword_ptr = char_ptr
	mov	eax, [ebp-0x04]
	mov	[ebp-0x08], eax
	mov	[ebp-0x10], 0x80808080
	mov	[ebp-0x14], 0x01010101



.L10:
	; longword = *longword_ptr++
	mov	eax, [ebp-0x08]
	mov	eax, [eax]
	mov	[ebp-0x0C], eax
	add	[ebp-0x08], 0x04

	; longword - lomagic
	mov	edx, [ebp-0x14] ; lomagic
	mov	eax, [ebp-0x0C] ; longword
	mov	ecx, eax
	sub	ecx, edx
	mov	edx, ecx

	not	eax
	and	eax, edx
	and	eax, [ebp-0x10]
	test	eax, eax
	jz	.L10


	mov	eax, [ebp-0x08] ; longword_ptr
	sub	eax, 4
	mov	[ebp-0x18], eax
	mov	eax, [ebp-0x18]
	movzx	eax, BYTE [eax]
	test	al, al
	jnz	.L7
	mov	eax, [ebp-0x18]
	mov	edx, [ebp+0x04]
	sub	eax, edx
	mov	[ebp-0x1C], eax
	jmp	.L4
.L7:
	mov	eax, [ebp-0x18]
	add	eax, 1
	movzx	eax, BYTE [eax]
	test	al, al
	jnz	.L8
	mov	edx, [ebp-0x18]
	mov	eax, [ebp+0x04]
	mov	ecx, edx
	sub	ecx, eax
	add	ecx, 1
	mov	[ebp-0x1C], ecx
	jmp	.L4
.L8:
	mov	eax, [ebp-0x18]
	add	eax, 2
	movzx	eax, BYTE [eax]
	test	al, al
	jne	.L9
	mov	edx, [ebp-0x18]
	mov	eax, [ebp+0x04]
	mov	ecx, edx
	sub	ecx, eax
	add	ecx, 2
	mov	[ebp-0x1C], ecx
	jmp	.L4
.L9:
	mov	eax, [ebp-0x18]
	add	eax, 3
	movzx	eax, BYTE [eax]
	test	al, al
	jnz	.L10  ; isso precisa não ocorrer nunca?
	mov	edx, [ebp-0x18]
	mov	eax, [ebp+0x04]
	mov	ecx, edx
	sub	ecx, eax
	add	ecx, 3
	mov	[ebp-0x1C], ecx
.L4:
	mov	eax, [ebp-0x1C]
	mov	esp, ebp
	ret

