; Listing generated by Microsoft (R) Optimizing Compiler Version 14.00.50727.42 

	TITLE	c:\djgpp\Demo23\SysCore\FloppyDisk\flpydsk.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMT
INCLUDELIB OLDNAMES

_BSS	SEGMENT
__CurrentDrive DB 01H DUP (?)
__FloppyDiskIRQ DB 01H DUP (?)
_BSS	ENDS
PUBLIC	?dma_initialize_floppy@@YA_NPAEI@Z		; dma_initialize_floppy
EXTRN	?dma_unmask_all@@YAXH@Z:PROC			; dma_unmask_all
EXTRN	?dma_set_read@@YAXE@Z:PROC			; dma_set_read
EXTRN	?dma_set_count@@YAXEEE@Z:PROC			; dma_set_count
EXTRN	?dma_set_address@@YAXEEE@Z:PROC			; dma_set_address
EXTRN	?dma_reset_flipflop@@YAXH@Z:PROC		; dma_reset_flipflop
EXTRN	?dma_mask_channel@@YAXE@Z:PROC			; dma_mask_channel
EXTRN	?dma_reset@@YAXH@Z:PROC				; dma_reset
; Function compile flags: /Ogtpy
; File c:\djgpp\demo23\syscore\floppydisk\flpydsk.cpp
_TEXT	SEGMENT
_c$ = -8						; size = 4
_buffer$ = 8						; size = 4
_length$ = 12						; size = 4
?dma_initialize_floppy@@YA_NPAEI@Z PROC			; dma_initialize_floppy

; 198  : bool _cdecl dma_initialize_floppy(uint8_t* buffer, unsigned length){

	sub	esp, 8
	push	esi

; 199  :    union{
; 200  :       uint8_t byte[4];//Lo[0], Mid[1], Hi[2]
; 201  :       unsigned long l;
; 202  :    }a, c;
; 203  : 
; 204  :    a.l=(unsigned)buffer;
; 205  :    c.l=(unsigned)length-1;

	mov	esi, DWORD PTR _length$[esp+8]
	push	edi

; 206  : 
; 207  :    //Check for buffer issues
; 208  :    if ((a.l >> 24) || (c.l >> 16) || (((a.l & 0xffff)+c.l) >> 16)){

	mov	edi, DWORD PTR _buffer$[esp+12]
	add	esi, -1
	test	edi, -16777216				; ff000000H
	mov	DWORD PTR _c$[esp+16], esi
	jne	SHORT $LN1@dma_initia
	test	esi, -65536				; ffff0000H
	jne	SHORT $LN1@dma_initia
	movzx	eax, di
	add	eax, esi
	test	eax, -65536				; ffff0000H
	jne	SHORT $LN1@dma_initia

; 217  :    }
; 218  : 
; 219  :    dma_reset (1);

	push	1
	call	?dma_reset@@YAXH@Z			; dma_reset

; 220  :    dma_mask_channel( FDC_DMA_CHANNEL );//Mask channel 2

	push	2
	call	?dma_mask_channel@@YAXE@Z		; dma_mask_channel

; 221  :    dma_reset_flipflop ( 1 );//Flipflop reset on DMA 1

	push	1
	call	?dma_reset_flipflop@@YAXH@Z		; dma_reset_flipflop

; 222  : 
; 223  :    dma_set_address( FDC_DMA_CHANNEL, a.byte[0],a.byte[1]);//Buffer address

	mov	ecx, DWORD PTR _buffer$[esp+25]
	push	ecx
	push	edi
	push	2
	call	?dma_set_address@@YAXEEE@Z		; dma_set_address

; 224  :    dma_reset_flipflop( 1 );//Flipflop reset on DMA 1

	push	1
	call	?dma_reset_flipflop@@YAXH@Z		; dma_reset_flipflop

; 225  : 
; 226  :    dma_set_count( FDC_DMA_CHANNEL, c.byte[0],c.byte[1]);//Set count

	mov	edx, DWORD PTR _c$[esp+45]
	push	edx
	push	esi
	push	2
	call	?dma_set_count@@YAXEEE@Z		; dma_set_count

; 227  :    dma_set_read ( FDC_DMA_CHANNEL );

	push	2
	call	?dma_set_read@@YAXE@Z			; dma_set_read

; 228  : 
; 229  :    dma_unmask_all( 1 );//Unmask channel 2

	push	1
	call	?dma_unmask_all@@YAXH@Z			; dma_unmask_all
	add	esp, 48					; 00000030H
	pop	edi

; 230  : 
; 231  :    return true;

	mov	al, 1
	pop	esi

; 232  : }

	add	esp, 8
	ret	0
$LN1@dma_initia:
	pop	edi

; 209  : #ifdef _DEBUG
; 210  :       _asm{
; 211  :          mov      eax, 0x1337
; 212  :          cli
; 213  :          hlt
; 214  :       }
; 215  : #endif
; 216  :       return false;

	xor	al, al
	pop	esi

; 232  : }

	add	esp, 8
	ret	0
?dma_initialize_floppy@@YA_NPAEI@Z ENDP			; dma_initialize_floppy
_TEXT	ENDS
PUBLIC	?flpydsk_read_status@@YAEXZ			; flpydsk_read_status
EXTRN	?inportb@@YAEG@Z:PROC				; inportb
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
?flpydsk_read_status@@YAEXZ PROC			; flpydsk_read_status

; 240  : 
; 241  : 	//! just return main status register
; 242  : 	return inportb (FLPYDSK_MSR);

	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4

; 243  : }

	ret	0
?flpydsk_read_status@@YAEXZ ENDP			; flpydsk_read_status
_TEXT	ENDS
PUBLIC	?flpydsk_write_dor@@YAXE@Z			; flpydsk_write_dor
EXTRN	?outportb@@YAXGE@Z:PROC				; outportb
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
_val$ = 8						; size = 1
?flpydsk_write_dor@@YAXE@Z PROC				; flpydsk_write_dor

; 247  : 
; 248  : 	//! write the digital output register
; 249  : 	outportb (FLPYDSK_DOR, val);

	mov	eax, DWORD PTR _val$[esp-4]
	push	eax
	push	1010					; 000003f2H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8

; 250  : }

	ret	0
?flpydsk_write_dor@@YAXE@Z ENDP				; flpydsk_write_dor
_TEXT	ENDS
PUBLIC	?flpydsk_send_command@@YAXE@Z			; flpydsk_send_command
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
_cmd$ = 8						; size = 1
?flpydsk_send_command@@YAXE@Z PROC			; flpydsk_send_command

; 253  : void flpydsk_send_command (uint8_t cmd) {

	push	esi

; 254  : 
; 255  : 	//! wait until data register is ready. We send commands to the data register
; 256  : 	for (int i = 0; i < 500; i++ )

	xor	esi, esi
$LL4@flpydsk_se:

; 257  : 		if ( flpydsk_read_status () & FLPYDSK_MSR_MASK_DATAREG )

	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN10@flpydsk_se
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL4@flpydsk_se
	pop	esi

; 259  : }

	ret	0
$LN10@flpydsk_se:

; 258  : 			return outportb (FLPYDSK_FIFO, cmd);

	mov	eax, DWORD PTR _cmd$[esp]
	push	eax
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8
	pop	esi

; 259  : }

	ret	0
?flpydsk_send_command@@YAXE@Z ENDP			; flpydsk_send_command
_TEXT	ENDS
PUBLIC	?flpydsk_read_data@@YAEXZ			; flpydsk_read_data
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
?flpydsk_read_data@@YAEXZ PROC				; flpydsk_read_data

; 262  : uint8_t flpydsk_read_data () {

	push	esi

; 263  : 
; 264  : 	//! same as above function but returns data register for reading
; 265  : 	for (int i = 0; i < 500; i++ )

	xor	esi, esi
$LL4@flpydsk_re:

; 266  : 		if ( flpydsk_read_status () & FLPYDSK_MSR_MASK_DATAREG )

	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN10@flpydsk_re
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL4@flpydsk_re

; 268  : 
; 269  : 	return 0;

	xor	al, al
	pop	esi

; 270  : }

	ret	0
$LN10@flpydsk_re:

; 267  : 			return inportb (FLPYDSK_FIFO);

	push	1013					; 000003f5H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	pop	esi

; 270  : }

	ret	0
?flpydsk_read_data@@YAEXZ ENDP				; flpydsk_read_data
_TEXT	ENDS
PUBLIC	?flpydsk_write_ccr@@YAXE@Z			; flpydsk_write_ccr
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
_val$ = 8						; size = 1
?flpydsk_write_ccr@@YAXE@Z PROC				; flpydsk_write_ccr

; 274  : 
; 275  : 	//! write the configuation control
; 276  : 	outportb (FLPYDSK_CTRL, val);

	mov	eax, DWORD PTR _val$[esp-4]
	push	eax
	push	1015					; 000003f7H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8

; 277  : }

	ret	0
?flpydsk_write_ccr@@YAXE@Z ENDP				; flpydsk_write_ccr
_TEXT	ENDS
PUBLIC	?flpydsk_wait_irq@@YAXXZ			; flpydsk_wait_irq
; Function compile flags: /Ogtpy
;	COMDAT ?flpydsk_wait_irq@@YAXXZ
_TEXT	SEGMENT
?flpydsk_wait_irq@@YAXXZ PROC				; flpydsk_wait_irq, COMDAT

; 284  : inline void flpydsk_wait_irq () {

$LL2@flpydsk_wa:

; 285  : 
; 286  : 	//! wait for irq to fire
; 287  : 	while ( _FloppyDiskIRQ == 0)

	mov	al, BYTE PTR __FloppyDiskIRQ
	test	al, al
	je	SHORT $LL2@flpydsk_wa

; 288  : 		;
; 289  : 	_FloppyDiskIRQ = 0;

	mov	BYTE PTR __FloppyDiskIRQ, 0

; 290  : }

	ret	0
?flpydsk_wait_irq@@YAXXZ ENDP				; flpydsk_wait_irq
_TEXT	ENDS
PUBLIC	?i86_flpy_irq@@YAXXZ				; i86_flpy_irq
EXTRN	?interruptdone@@YAXI@Z:PROC			; interruptdone
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
?i86_flpy_irq@@YAXXZ PROC				; i86_flpy_irq

; 294  : void _cdecl i86_flpy_irq () {

	push	ebx
	push	esi
	push	edi

; 295  : 
; 296  : 	_asm add esp, 12

	add	esp, 12					; 0000000cH

; 297  : 	_asm pushad

	pushad

; 298  : 	_asm cli

	cli

; 299  : 
; 300  : 	//! irq fired
; 301  : 	_FloppyDiskIRQ = 1;
; 302  : 
; 303  : 	//! tell hal we are done
; 304  : 	interruptdone( FLOPPY_IRQ );

	push	6
	mov	BYTE PTR __FloppyDiskIRQ, 1
	call	?interruptdone@@YAXI@Z			; interruptdone
	add	esp, 4

; 305  : 
; 306  : 	_asm sti

	sti

; 307  : 	_asm popad

	popad

; 308  : 	_asm iretd

	iretd

; 309  : }

	pop	edi
	pop	esi
	pop	ebx
	ret	0
?i86_flpy_irq@@YAXXZ ENDP				; i86_flpy_irq
_TEXT	ENDS
PUBLIC	?flpydsk_check_int@@YAXPAI0@Z			; flpydsk_check_int
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
_st0$ = 8						; size = 4
_cyl$ = 12						; size = 4
?flpydsk_check_int@@YAXPAI0@Z PROC			; flpydsk_check_int

; 317  : 
; 318  : 	flpydsk_send_command (FDC_CMD_CHECK_INT);

	push	8
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command
	add	esp, 4

; 319  : 
; 320  : 	*st0 = flpydsk_read_data ();

	call	?flpydsk_read_data@@YAEXZ		; flpydsk_read_data
	mov	ecx, DWORD PTR _st0$[esp-4]
	movzx	eax, al
	mov	DWORD PTR [ecx], eax

; 321  : 	*cyl = flpydsk_read_data ();

	call	?flpydsk_read_data@@YAEXZ		; flpydsk_read_data
	movzx	edx, al
	mov	eax, DWORD PTR _cyl$[esp-4]
	mov	DWORD PTR [eax], edx

; 322  : }

	ret	0
?flpydsk_check_int@@YAXPAI0@Z ENDP			; flpydsk_check_int
_TEXT	ENDS
PUBLIC	?flpydsk_control_motor@@YAX_N@Z			; flpydsk_control_motor
EXTRN	?sleep@@YAXH@Z:PROC				; sleep
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
_b$ = 8							; size = 1
?flpydsk_control_motor@@YAX_N@Z PROC			; flpydsk_control_motor

; 326  : 
; 327  : 	//! sanity check: invalid drive
; 328  : 	if (_CurrentDrive > 3)

	mov	al, BYTE PTR __CurrentDrive
	cmp	al, 3
	ja	SHORT $LN10@flpydsk_co

; 329  : 		return;
; 330  : 
; 331  : 	uint8_t motor = 0;
; 332  : 
; 333  : 	//! select the correct mask based on current drive
; 334  : 	switch (_CurrentDrive) {

	movzx	ecx, al
	xor	dl, dl
	cmp	ecx, 3
	ja	SHORT $LN7@flpydsk_co
	jmp	DWORD PTR $LN18@flpydsk_co[ecx*4]
$LN6@flpydsk_co:

; 335  : 
; 336  : 		case 0:
; 337  : 			motor = FLPYDSK_DOR_MASK_DRIVE0_MOTOR;

	mov	dl, 16					; 00000010H

; 338  : 			break;

	jmp	SHORT $LN7@flpydsk_co
$LN5@flpydsk_co:

; 339  : 		case 1:
; 340  : 			motor = FLPYDSK_DOR_MASK_DRIVE1_MOTOR;

	mov	dl, 32					; 00000020H

; 341  : 			break;

	jmp	SHORT $LN7@flpydsk_co
$LN4@flpydsk_co:

; 342  : 		case 2:
; 343  : 			motor = FLPYDSK_DOR_MASK_DRIVE2_MOTOR;

	mov	dl, 64					; 00000040H

; 344  : 			break;

	jmp	SHORT $LN7@flpydsk_co
$LN3@flpydsk_co:

; 345  : 		case 3:
; 346  : 			motor = FLPYDSK_DOR_MASK_DRIVE3_MOTOR;

	mov	dl, 128					; 00000080H
$LN7@flpydsk_co:

; 347  : 			break;
; 348  : 	}
; 349  : 
; 350  : 	//! turn on or off the motor of that drive
; 351  : 	if (b)

	cmp	BYTE PTR _b$[esp-4], 0
	je	SHORT $LN2@flpydsk_co
	or	al, dl

; 352  : 		flpydsk_write_dor (uint8_t(_CurrentDrive | motor | FLPYDSK_DOR_MASK_RESET | FLPYDSK_DOR_MASK_DMA));

	or	eax, 12					; 0000000cH
	push	eax

; 353  : 	else

	jmp	SHORT $LN17@flpydsk_co
$LN2@flpydsk_co:

; 354  : 		flpydsk_write_dor (FLPYDSK_DOR_MASK_RESET);

	push	4
$LN17@flpydsk_co:
	push	1010					; 000003f2H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8

; 355  : 
; 356  : 	//! in all cases; wait a little bit for the motor to spin up/turn off
; 357  : 	sleep (20);

	mov	DWORD PTR _b$[esp-4], 20		; 00000014H
	jmp	?sleep@@YAXH@Z				; sleep
$LN10@flpydsk_co:

; 358  : }

	ret	0
$LN18@flpydsk_co:
	DD	$LN6@flpydsk_co
	DD	$LN5@flpydsk_co
	DD	$LN4@flpydsk_co
	DD	$LN3@flpydsk_co
?flpydsk_control_motor@@YAX_N@Z ENDP			; flpydsk_control_motor
_TEXT	ENDS
PUBLIC	?flpydsk_drive_data@@YAXEEE_N@Z			; flpydsk_drive_data
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
_stepr$ = 8						; size = 1
_loadt$ = 12						; size = 1
_unloadt$ = 16						; size = 1
_dma$ = 20						; size = 1
?flpydsk_drive_data@@YAXEEE_N@Z PROC			; flpydsk_drive_data

; 362  : 
; 363  : 	uint8_t data = 0;
; 364  : 
; 365  : 	//! send command
; 366  : 	flpydsk_send_command (FDC_CMD_SPECIFY);

	push	3
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command

; 367  : 	data = ( (stepr & 0xf) << 4) | (unloadt & 0xf);

	movzx	eax, BYTE PTR _stepr$[esp]
	mov	cl, BYTE PTR _unloadt$[esp]
	shl	al, 4
	and	cl, 15					; 0000000fH
	or	al, cl

; 368  : 		flpydsk_send_command (data);

	push	eax
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command

; 369  : 	data = (( loadt << 1 ) | ( (dma) ? 0 : 1 ) );

	cmp	BYTE PTR _dma$[esp+4], 0
	mov	al, BYTE PTR _loadt$[esp+4]
	sete	dl
	add	al, al
	or	dl, al

; 370  : 		flpydsk_send_command (data);

	push	edx
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command
	add	esp, 12					; 0000000cH

; 371  : }

	ret	0
?flpydsk_drive_data@@YAXEEE_N@Z ENDP			; flpydsk_drive_data
_TEXT	ENDS
PUBLIC	?flpydsk_calibrate@@YAHE@Z			; flpydsk_calibrate
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
_drive$ = 8						; size = 1
?flpydsk_calibrate@@YAHE@Z PROC				; flpydsk_calibrate

; 375  : 
; 376  : 	uint32_t st0, cyl;
; 377  : 
; 378  : 	if (drive >= 4)

	cmp	BYTE PTR _drive$[esp-4], 4
	jb	SHORT $LN5@flpydsk_ca

; 379  : 		return -2;

	mov	eax, -2					; fffffffeH

; 402  : }

	ret	0
$LN5@flpydsk_ca:

; 380  : 
; 381  : 	//! turn on the motor
; 382  : 	flpydsk_control_motor (true);

	mov	al, BYTE PTR __CurrentDrive
	cmp	al, 3
	ja	SHORT $LN17@flpydsk_ca
	movzx	edx, al
	xor	cl, cl
	cmp	edx, 3
	ja	SHORT $LN14@flpydsk_ca
	jmp	DWORD PTR $LN142@flpydsk_ca[edx*4]
$LN13@flpydsk_ca:
	mov	cl, 16					; 00000010H
	jmp	SHORT $LN14@flpydsk_ca
$LN12@flpydsk_ca:
	mov	cl, 32					; 00000020H
	jmp	SHORT $LN14@flpydsk_ca
$LN11@flpydsk_ca:
	mov	cl, 64					; 00000040H
	jmp	SHORT $LN14@flpydsk_ca
$LN10@flpydsk_ca:
	mov	cl, 128					; 00000080H
$LN14@flpydsk_ca:
	or	al, cl
	or	eax, 12					; 0000000cH
	push	eax
	push	1010					; 000003f2H
	call	?outportb@@YAXGE@Z			; outportb
	push	20					; 00000014H
	call	?sleep@@YAXH@Z				; sleep
	add	esp, 12					; 0000000cH
$LN17@flpydsk_ca:
	push	edi

; 383  : 
; 384  : 	for (int i = 0; i < 10; i++) {

	xor	edi, edi
	push	esi
$LL4@flpydsk_ca:

; 385  : 
; 386  : 		//! send command
; 387  : 		flpydsk_send_command ( FDC_CMD_CALIBRATE );

	xor	esi, esi
$LL26@flpydsk_ca:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN106@flpydsk_ca
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL26@flpydsk_ca

; 391  : 
; 392  : 		//! did we fine cylinder 0? if so, we are done
; 393  : 		if (!cyl) {

	jmp	SHORT $LN24@flpydsk_ca
$LN106@flpydsk_ca:

; 385  : 
; 386  : 		//! send command
; 387  : 		flpydsk_send_command ( FDC_CMD_CALIBRATE );

	push	7
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8
$LN24@flpydsk_ca:

; 388  : 		flpydsk_send_command ( drive );

	xor	esi, esi
$LL34@flpydsk_ca:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN107@flpydsk_ca
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL34@flpydsk_ca

; 391  : 
; 392  : 		//! did we fine cylinder 0? if so, we are done
; 393  : 		if (!cyl) {

	jmp	SHORT $LL40@flpydsk_ca
$LN107@flpydsk_ca:

; 388  : 		flpydsk_send_command ( drive );

	mov	eax, DWORD PTR _drive$[esp+4]
	push	eax
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8

; 389  : 		flpydsk_wait_irq ();

$LL40@flpydsk_ca:
	mov	cl, BYTE PTR __FloppyDiskIRQ
	test	cl, cl
	je	SHORT $LL40@flpydsk_ca
	mov	BYTE PTR __FloppyDiskIRQ, 0

; 390  : 		flpydsk_check_int ( &st0, &cyl);

	xor	esi, esi
	npad	9
$LL48@flpydsk_ca:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN108@flpydsk_ca
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL48@flpydsk_ca

; 391  : 
; 392  : 		//! did we fine cylinder 0? if so, we are done
; 393  : 		if (!cyl) {

	jmp	SHORT $LN46@flpydsk_ca
$LN108@flpydsk_ca:

; 390  : 		flpydsk_check_int ( &st0, &cyl);

	push	8
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8
$LN46@flpydsk_ca:
	xor	esi, esi
	npad	1
$LL56@flpydsk_ca:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN109@flpydsk_ca
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL56@flpydsk_ca

; 391  : 
; 392  : 		//! did we fine cylinder 0? if so, we are done
; 393  : 		if (!cyl) {

	jmp	SHORT $LN54@flpydsk_ca
$LN109@flpydsk_ca:

; 390  : 		flpydsk_check_int ( &st0, &cyl);

	push	1013					; 000003f5H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
$LN54@flpydsk_ca:
	xor	esi, esi
	npad	3
$LL64@flpydsk_ca:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN110@flpydsk_ca
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL64@flpydsk_ca
$LN111@flpydsk_ca:

; 394  : 
; 395  : 			flpydsk_control_motor (false);

	cmp	BYTE PTR __CurrentDrive, 3
	ja	SHORT $LN78@flpydsk_ca
	push	4
	push	1010					; 000003f2H
	call	?outportb@@YAXGE@Z			; outportb
	push	20					; 00000014H
	call	?sleep@@YAXH@Z				; sleep
	add	esp, 12					; 0000000cH
$LN78@flpydsk_ca:
	pop	esi

; 396  : 			return 0;

	xor	eax, eax
	pop	edi

; 402  : }

	ret	0
$LN110@flpydsk_ca:

; 390  : 		flpydsk_check_int ( &st0, &cyl);

	push	1013					; 000003f5H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4

; 391  : 
; 392  : 		//! did we fine cylinder 0? if so, we are done
; 393  : 		if (!cyl) {

	test	al, al
	je	SHORT $LN111@flpydsk_ca
	add	edi, 1
	cmp	edi, 10					; 0000000aH
	jl	$LL4@flpydsk_ca

; 397  : 		}
; 398  : 	}
; 399  : 
; 400  : 	flpydsk_control_motor (false);

	cmp	BYTE PTR __CurrentDrive, 3
	ja	SHORT $LN93@flpydsk_ca
	push	4
	push	1010					; 000003f2H
	call	?outportb@@YAXGE@Z			; outportb
	push	20					; 00000014H
	call	?sleep@@YAXH@Z				; sleep
	add	esp, 12					; 0000000cH
$LN93@flpydsk_ca:
	pop	esi

; 401  : 	return -1;

	or	eax, -1
	pop	edi

; 402  : }

	ret	0
	npad	2
$LN142@flpydsk_ca:
	DD	$LN13@flpydsk_ca
	DD	$LN12@flpydsk_ca
	DD	$LN11@flpydsk_ca
	DD	$LN10@flpydsk_ca
?flpydsk_calibrate@@YAHE@Z ENDP				; flpydsk_calibrate
_TEXT	ENDS
PUBLIC	?flpydsk_disable_controller@@YAXXZ		; flpydsk_disable_controller
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
?flpydsk_disable_controller@@YAXXZ PROC			; flpydsk_disable_controller

; 406  : 
; 407  : 	flpydsk_write_dor (0);

	push	0
	push	1010					; 000003f2H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8

; 408  : }

	ret	0
?flpydsk_disable_controller@@YAXXZ ENDP			; flpydsk_disable_controller
_TEXT	ENDS
PUBLIC	?flpydsk_enable_controller@@YAXXZ		; flpydsk_enable_controller
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
?flpydsk_enable_controller@@YAXXZ PROC			; flpydsk_enable_controller

; 412  : 
; 413  : 	flpydsk_write_dor ( FLPYDSK_DOR_MASK_RESET | FLPYDSK_DOR_MASK_DMA);

	push	12					; 0000000cH
	push	1010					; 000003f2H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8

; 414  : }

	ret	0
?flpydsk_enable_controller@@YAXXZ ENDP			; flpydsk_enable_controller
_TEXT	ENDS
PUBLIC	?flpydsk_reset@@YAXXZ				; flpydsk_reset
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
?flpydsk_reset@@YAXXZ PROC				; flpydsk_reset

; 418  : 
; 419  : 	uint32_t st0, cyl;
; 420  : 
; 421  : 	//! reset the controller
; 422  : 	flpydsk_disable_controller ();

	push	0
	push	1010					; 000003f2H
	call	?outportb@@YAXGE@Z			; outportb

; 423  : 	flpydsk_enable_controller ();

	push	12					; 0000000cH
	push	1010					; 000003f2H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 16					; 00000010H
	npad	5

; 424  : 	flpydsk_wait_irq ();

$LL15@flpydsk_re@2:
	mov	al, BYTE PTR __FloppyDiskIRQ
	test	al, al
	je	SHORT $LL15@flpydsk_re@2
	push	esi
	push	edi
	mov	BYTE PTR __FloppyDiskIRQ, 0
	mov	edi, 4
	npad	9
$LL3@flpydsk_re@2:

; 428  : 		flpydsk_check_int (&st0,&cyl);

	xor	esi, esi
$LL23@flpydsk_re@2:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN80@flpydsk_re@2
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL23@flpydsk_re@2

; 432  : 
; 433  : 	//! pass mechanical drive info. steprate=3ms, unload time=240ms, load time=16ms
; 434  : 	flpydsk_drive_data (3,16,240,true);

	jmp	SHORT $LN21@flpydsk_re@2
$LN80@flpydsk_re@2:

; 428  : 		flpydsk_check_int (&st0,&cyl);

	push	8
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8
$LN21@flpydsk_re@2:
	xor	esi, esi
$LL31@flpydsk_re@2:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN81@flpydsk_re@2
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL31@flpydsk_re@2

; 432  : 
; 433  : 	//! pass mechanical drive info. steprate=3ms, unload time=240ms, load time=16ms
; 434  : 	flpydsk_drive_data (3,16,240,true);

	jmp	SHORT $LN29@flpydsk_re@2
$LN81@flpydsk_re@2:

; 428  : 		flpydsk_check_int (&st0,&cyl);

	push	1013					; 000003f5H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
$LN29@flpydsk_re@2:
	xor	esi, esi
	npad	2
$LL39@flpydsk_re@2:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN82@flpydsk_re@2
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL39@flpydsk_re@2

; 432  : 
; 433  : 	//! pass mechanical drive info. steprate=3ms, unload time=240ms, load time=16ms
; 434  : 	flpydsk_drive_data (3,16,240,true);

	jmp	SHORT $LN37@flpydsk_re@2
$LN82@flpydsk_re@2:

; 428  : 		flpydsk_check_int (&st0,&cyl);

	push	1013					; 000003f5H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
$LN37@flpydsk_re@2:

; 425  : 
; 426  : 	//! send CHECK_INT/SENSE INTERRUPT command to all drives
; 427  : 	for (int i=0; i<4; i++)

	sub	edi, 1
	jne	$LL3@flpydsk_re@2

; 429  : 
; 430  : 	//! transfer speed 500kb/s
; 431  : 	flpydsk_write_ccr (0);

	push	0
	push	1015					; 000003f7H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8

; 432  : 
; 433  : 	//! pass mechanical drive info. steprate=3ms, unload time=240ms, load time=16ms
; 434  : 	flpydsk_drive_data (3,16,240,true);

	xor	esi, esi
$LL51@flpydsk_re@2:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN83@flpydsk_re@2
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL51@flpydsk_re@2
	jmp	SHORT $LN49@flpydsk_re@2
$LN83@flpydsk_re@2:
	push	3
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8
$LN49@flpydsk_re@2:
	xor	esi, esi
$LL59@flpydsk_re@2:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN84@flpydsk_re@2
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL59@flpydsk_re@2
	jmp	SHORT $LN57@flpydsk_re@2
$LN84@flpydsk_re@2:
	push	48					; 00000030H
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8
$LN57@flpydsk_re@2:
	xor	esi, esi
$LL67@flpydsk_re@2:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN85@flpydsk_re@2
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL67@flpydsk_re@2

; 435  : 
; 436  : 	//! calibrate the disk
; 437  : 	flpydsk_calibrate ( _CurrentDrive );

	movzx	ecx, BYTE PTR __CurrentDrive
	push	ecx
	call	?flpydsk_calibrate@@YAHE@Z		; flpydsk_calibrate
	add	esp, 4
	pop	edi
	pop	esi

; 438  : }

	ret	0
$LN85@flpydsk_re@2:

; 432  : 
; 433  : 	//! pass mechanical drive info. steprate=3ms, unload time=240ms, load time=16ms
; 434  : 	flpydsk_drive_data (3,16,240,true);

	push	32					; 00000020H
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb

; 435  : 
; 436  : 	//! calibrate the disk
; 437  : 	flpydsk_calibrate ( _CurrentDrive );

	movzx	ecx, BYTE PTR __CurrentDrive
	add	esp, 8
	push	ecx
	call	?flpydsk_calibrate@@YAHE@Z		; flpydsk_calibrate
	add	esp, 4
	pop	edi
	pop	esi

; 438  : }

	ret	0
?flpydsk_reset@@YAXXZ ENDP				; flpydsk_reset
_TEXT	ENDS
PUBLIC	?flpydsk_read_sector_imp@@YAXEEE@Z		; flpydsk_read_sector_imp
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
_head$ = 8						; size = 1
_track$ = 12						; size = 1
_sector$ = 16						; size = 1
?flpydsk_read_sector_imp@@YAXEEE@Z PROC			; flpydsk_read_sector_imp

; 441  : void flpydsk_read_sector_imp (uint8_t head, uint8_t track, uint8_t sector) {

	push	ebx

; 442  : 
; 443  : 	uint32_t st0, cyl;
; 444  : 
; 445  : 	//! initialize DMA
; 446  : 	dma_initialize_floppy ((uint8_t*) DMA_BUFFER, 512 );

	push	512					; 00000200H
	push	4096					; 00001000H
	call	?dma_initialize_floppy@@YA_NPAEI@Z	; dma_initialize_floppy

; 447  : 
; 448  : 	//! set the DMA for read transfer
; 449  : 	dma_set_read ( FDC_DMA_CHANNEL );

	push	2
	call	?dma_set_read@@YAXE@Z			; dma_set_read

; 450  : 
; 451  : 	//! read in a sector
; 452  : 	flpydsk_send_command (
; 453  : 				FDC_CMD_READ_SECT | FDC_CMD_EXT_MULTITRACK | FDC_CMD_EXT_SKIP | FDC_CMD_EXT_DENSITY);

	push	230					; 000000e6H
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command

; 454  : 	flpydsk_send_command ( head << 2 | _CurrentDrive );

	mov	ebx, DWORD PTR _head$[esp+16]
	movzx	eax, bl
	add	al, al
	add	al, al
	or	al, BYTE PTR __CurrentDrive
	push	eax
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command

; 455  : 	flpydsk_send_command ( track);

	mov	ecx, DWORD PTR _track$[esp+20]
	push	ecx
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command

; 456  : 	flpydsk_send_command ( head);

	push	ebx
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command

; 457  : 	flpydsk_send_command ( sector);

	mov	ebx, DWORD PTR _sector$[esp+28]
	push	ebx
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command

; 458  : 	flpydsk_send_command ( FLPYDSK_SECTOR_DTL_512 );

	push	2
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command

; 459  : 	flpydsk_send_command ( ( ( sector + 1 ) >= FLPY_SECTORS_PER_TRACK ) ? FLPY_SECTORS_PER_TRACK : sector + 1 );

	movzx	eax, bl
	add	esp, 36					; 00000024H
	add	eax, 1
	cmp	eax, 18					; 00000012H
	pop	ebx
	jl	SHORT $LN6@flpydsk_re@3
	mov	eax, 18					; 00000012H
$LN6@flpydsk_re@3:
	push	eax
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command

; 460  : 	flpydsk_send_command ( FLPYDSK_GAP3_LENGTH_3_5 );

	push	27					; 0000001bH
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command

; 461  : 	flpydsk_send_command ( 0xff );

	push	255					; 000000ffH
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command
	add	esp, 12					; 0000000cH
	npad	9

; 462  : 
; 463  : 	//! wait for irq
; 464  : 	flpydsk_wait_irq ();

$LL9@flpydsk_re@3:
	mov	dl, BYTE PTR __FloppyDiskIRQ
	test	dl, dl
	je	SHORT $LL9@flpydsk_re@3
	push	esi
	push	edi
	mov	BYTE PTR __FloppyDiskIRQ, 0
	mov	edi, 7
	npad	8
$LL3@flpydsk_re@3:

; 468  : 		flpydsk_read_data ();

	xor	esi, esi
$LL15@flpydsk_re@3:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN52@flpydsk_re@3
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL15@flpydsk_re@3

; 469  : 
; 470  : 	//! let FDC know we handled interrupt
; 471  : 	flpydsk_check_int (&st0,&cyl);

	jmp	SHORT $LN2@flpydsk_re@3
$LN52@flpydsk_re@3:

; 468  : 		flpydsk_read_data ();

	push	1013					; 000003f5H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
$LN2@flpydsk_re@3:

; 465  : 
; 466  : 	//! read status info
; 467  : 	for (int j=0; j<7; j++)

	sub	edi, 1
	jne	SHORT $LL3@flpydsk_re@3

; 469  : 
; 470  : 	//! let FDC know we handled interrupt
; 471  : 	flpydsk_check_int (&st0,&cyl);

	xor	esi, esi
$LL25@flpydsk_re@3:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN53@flpydsk_re@3
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL25@flpydsk_re@3
	jmp	SHORT $LN23@flpydsk_re@3
$LN53@flpydsk_re@3:
	push	8
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8
$LN23@flpydsk_re@3:
	xor	esi, esi
$LL33@flpydsk_re@3:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN54@flpydsk_re@3
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL33@flpydsk_re@3
	jmp	SHORT $LN31@flpydsk_re@3
$LN54@flpydsk_re@3:
	push	1013					; 000003f5H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
$LN31@flpydsk_re@3:
	xor	esi, esi
$LL41@flpydsk_re@3:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN55@flpydsk_re@3
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL41@flpydsk_re@3
	pop	edi
	pop	esi

; 472  : }

	ret	0
$LN55@flpydsk_re@3:

; 469  : 
; 470  : 	//! let FDC know we handled interrupt
; 471  : 	flpydsk_check_int (&st0,&cyl);

	push	1013					; 000003f5H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	pop	edi
	pop	esi

; 472  : }

	ret	0
?flpydsk_read_sector_imp@@YAXEEE@Z ENDP			; flpydsk_read_sector_imp
_TEXT	ENDS
PUBLIC	?flpydsk_seek@@YAHEE@Z				; flpydsk_seek
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
tv231 = -5						; size = 1
$T3453 = -4						; size = 1
_cyl$ = 8						; size = 1
_head$ = 12						; size = 1
?flpydsk_seek@@YAHEE@Z PROC				; flpydsk_seek

; 475  : int flpydsk_seek ( uint8_t cyl, uint8_t head ) {

	sub	esp, 8

; 476  : 
; 477  : 	uint32_t st0, cyl0;
; 478  : 
; 479  : 	if (_CurrentDrive >= 4)

	cmp	BYTE PTR __CurrentDrive, 4
	jb	SHORT $LN5@flpydsk_se@2

; 480  : 		return -1;

	or	eax, -1

; 499  : }

	add	esp, 8
	ret	0
$LN5@flpydsk_se@2:

; 481  : 
; 482  : 	for (int i = 0; i < 10; i++ ) {

	mov	al, BYTE PTR _head$[esp+4]
	push	edi
	add	al, al
	xor	edi, edi
	add	al, al
	mov	BYTE PTR tv231[esp+12], al
	push	esi
$LL4@flpydsk_se@2:

; 483  : 
; 484  : 		//! send the command
; 485  : 		flpydsk_send_command (FDC_CMD_SEEK);

	xor	esi, esi
$LL11@flpydsk_se@2:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN70@flpydsk_se@2
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL11@flpydsk_se@2

; 492  : 
; 493  : 		//! found the cylinder?
; 494  : 		if ( cyl0 == cyl)

	jmp	SHORT $LN9@flpydsk_se@2
$LN70@flpydsk_se@2:

; 483  : 
; 484  : 		//! send the command
; 485  : 		flpydsk_send_command (FDC_CMD_SEEK);

	push	15					; 0000000fH
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8
$LN9@flpydsk_se@2:

; 486  : 		flpydsk_send_command ( (head) << 2 | _CurrentDrive);

	mov	al, BYTE PTR tv231[esp+16]
	or	al, BYTE PTR __CurrentDrive
	xor	esi, esi
	mov	BYTE PTR $T3453[esp+16], al
$LL19@flpydsk_se@2:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN71@flpydsk_se@2
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL19@flpydsk_se@2

; 492  : 
; 493  : 		//! found the cylinder?
; 494  : 		if ( cyl0 == cyl)

	jmp	SHORT $LN17@flpydsk_se@2
$LN71@flpydsk_se@2:

; 486  : 		flpydsk_send_command ( (head) << 2 | _CurrentDrive);

	mov	ecx, DWORD PTR $T3453[esp+16]
	push	ecx
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8
$LN17@flpydsk_se@2:

; 487  : 		flpydsk_send_command (cyl);

	xor	esi, esi
$LL27@flpydsk_se@2:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN72@flpydsk_se@2
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL27@flpydsk_se@2

; 492  : 
; 493  : 		//! found the cylinder?
; 494  : 		if ( cyl0 == cyl)

	jmp	SHORT $LL33@flpydsk_se@2
$LN72@flpydsk_se@2:

; 487  : 		flpydsk_send_command (cyl);

	mov	edx, DWORD PTR _cyl$[esp+12]
	push	edx
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8

; 488  : 
; 489  : 		//! wait for the results phase IRQ
; 490  : 		flpydsk_wait_irq ();

$LL33@flpydsk_se@2:
	mov	al, BYTE PTR __FloppyDiskIRQ
	test	al, al
	je	SHORT $LL33@flpydsk_se@2
	mov	BYTE PTR __FloppyDiskIRQ, 0

; 491  : 		flpydsk_check_int (&st0,&cyl0);

	xor	esi, esi
$LL41@flpydsk_se@2:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN73@flpydsk_se@2
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL41@flpydsk_se@2

; 492  : 
; 493  : 		//! found the cylinder?
; 494  : 		if ( cyl0 == cyl)

	jmp	SHORT $LN39@flpydsk_se@2
$LN73@flpydsk_se@2:

; 491  : 		flpydsk_check_int (&st0,&cyl0);

	push	8
	push	1013					; 000003f5H
	call	?outportb@@YAXGE@Z			; outportb
	add	esp, 8
$LN39@flpydsk_se@2:
	xor	esi, esi
$LL49@flpydsk_se@2:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN74@flpydsk_se@2
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL49@flpydsk_se@2

; 492  : 
; 493  : 		//! found the cylinder?
; 494  : 		if ( cyl0 == cyl)

	jmp	SHORT $LN47@flpydsk_se@2
$LN74@flpydsk_se@2:

; 491  : 		flpydsk_check_int (&st0,&cyl0);

	push	1013					; 000003f5H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
$LN47@flpydsk_se@2:
	xor	esi, esi
$LL57@flpydsk_se@2:
	push	1012					; 000003f4H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	test	al, al
	js	SHORT $LN75@flpydsk_se@2
	add	esi, 1
	cmp	esi, 500				; 000001f4H
	jl	SHORT $LL57@flpydsk_se@2
	xor	al, al
$LN58@flpydsk_se@2:

; 492  : 
; 493  : 		//! found the cylinder?
; 494  : 		if ( cyl0 == cyl)

	cmp	al, BYTE PTR _cyl$[esp+12]
	je	SHORT $LN76@flpydsk_se@2
	add	edi, 1
	cmp	edi, 10					; 0000000aH
	jl	$LL4@flpydsk_se@2
	pop	esi

; 496  : 	}
; 497  : 
; 498  : 	return -1;

	or	eax, -1
	pop	edi

; 499  : }

	add	esp, 8
	ret	0
$LN75@flpydsk_se@2:

; 491  : 		flpydsk_check_int (&st0,&cyl0);

	push	1013					; 000003f5H
	call	?inportb@@YAEG@Z			; inportb
	add	esp, 4
	jmp	SHORT $LN58@flpydsk_se@2
$LN76@flpydsk_se@2:
	pop	esi

; 495  : 			return 0;

	xor	eax, eax
	pop	edi

; 499  : }

	add	esp, 8
	ret	0
?flpydsk_seek@@YAHEE@Z ENDP				; flpydsk_seek
_TEXT	ENDS
PUBLIC	?flpydsk_lba_to_chs@@YAXHPAH00@Z		; flpydsk_lba_to_chs
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
_lba$ = 8						; size = 4
_head$ = 12						; size = 4
_track$ = 16						; size = 4
_sector$ = 20						; size = 4
?flpydsk_lba_to_chs@@YAXHPAH00@Z PROC			; flpydsk_lba_to_chs

; 507  : 
; 508  :    *head = ( lba % ( FLPY_SECTORS_PER_TRACK * 2 ) ) / ( FLPY_SECTORS_PER_TRACK );

	mov	ecx, DWORD PTR _lba$[esp-4]
	mov	eax, 954437177				; 38e38e39H
	imul	ecx
	sar	edx, 3
	push	esi
	mov	esi, edx
	shr	esi, 31					; 0000001fH
	add	esi, edx
	lea	eax, DWORD PTR [esi+esi*8]
	add	eax, eax
	add	eax, eax
	mov	edx, ecx
	sub	edx, eax
	mov	eax, 954437177				; 38e38e39H
	imul	edx
	sar	edx, 2
	mov	eax, edx
	shr	eax, 31					; 0000001fH
	add	eax, edx
	mov	edx, DWORD PTR _head$[esp]
	mov	DWORD PTR [edx], eax

; 509  :    *track = lba / ( FLPY_SECTORS_PER_TRACK * 2 );

	mov	eax, DWORD PTR _track$[esp]
	mov	DWORD PTR [eax], esi

; 510  :    *sector = lba % FLPY_SECTORS_PER_TRACK + 1;

	mov	eax, 954437177				; 38e38e39H
	imul	ecx
	sar	edx, 2
	mov	eax, edx
	shr	eax, 31					; 0000001fH
	add	eax, edx
	lea	edx, DWORD PTR [eax+eax*8]
	mov	eax, DWORD PTR _sector$[esp]
	add	edx, edx
	sub	ecx, edx
	add	ecx, 1
	mov	DWORD PTR [eax], ecx
	pop	esi

; 511  : }

	ret	0
?flpydsk_lba_to_chs@@YAXHPAH00@Z ENDP			; flpydsk_lba_to_chs
_TEXT	ENDS
PUBLIC	?flpydsk_install@@YAXH@Z			; flpydsk_install
EXTRN	?setvect@@YAXHA6AXXZH@Z:PROC			; setvect
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
_irq$ = 8						; size = 4
?flpydsk_install@@YAXH@Z PROC				; flpydsk_install

; 515  : 
; 516  : 	//! install irq handler
; 517  : 	setvect (irq, i86_flpy_irq);

	mov	eax, DWORD PTR _irq$[esp-4]
	push	0
	push	OFFSET ?i86_flpy_irq@@YAXXZ		; i86_flpy_irq
	push	eax
	call	?setvect@@YAXHA6AXXZH@Z			; setvect

; 518  : 
; 519  : 	//! reset the fdc
; 520  : 	flpydsk_reset ();

	call	?flpydsk_reset@@YAXXZ			; flpydsk_reset

; 521  : 
; 522  : 	//! set drive information
; 523  : 	flpydsk_drive_data (13, 1, 0xf, true);

	push	3
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command
	push	223					; 000000dfH
	call	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command
	add	esp, 20					; 00000014H
	mov	DWORD PTR _irq$[esp-4], 2
	jmp	?flpydsk_send_command@@YAXE@Z		; flpydsk_send_command
?flpydsk_install@@YAXH@Z ENDP				; flpydsk_install
_TEXT	ENDS
PUBLIC	?flpydsk_set_working_drive@@YAXE@Z		; flpydsk_set_working_drive
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
_drive$ = 8						; size = 1
?flpydsk_set_working_drive@@YAXE@Z PROC			; flpydsk_set_working_drive

; 528  : 
; 529  : 	if (drive < 4)

	mov	al, BYTE PTR _drive$[esp-4]
	cmp	al, 4
	jae	SHORT $LN1@flpydsk_se@3

; 530  : 		_CurrentDrive = drive;

	mov	BYTE PTR __CurrentDrive, al
$LN1@flpydsk_se@3:

; 531  : }

	ret	0
?flpydsk_set_working_drive@@YAXE@Z ENDP			; flpydsk_set_working_drive
_TEXT	ENDS
PUBLIC	?flpydsk_get_working_drive@@YAEXZ		; flpydsk_get_working_drive
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
?flpydsk_get_working_drive@@YAEXZ PROC			; flpydsk_get_working_drive

; 535  : 
; 536  : 	return _CurrentDrive;

	mov	al, BYTE PTR __CurrentDrive

; 537  : }

	ret	0
?flpydsk_get_working_drive@@YAEXZ ENDP			; flpydsk_get_working_drive
_TEXT	ENDS
PUBLIC	?flpydsk_read_sector@@YAPAEH@Z			; flpydsk_read_sector
; Function compile flags: /Ogtpy
_TEXT	SEGMENT
_head$ = -12						; size = 4
_track$ = -8						; size = 4
_sector$ = -4						; size = 4
_sectorLBA$ = 8						; size = 4
?flpydsk_read_sector@@YAPAEH@Z PROC			; flpydsk_read_sector

; 540  : uint8_t* flpydsk_read_sector (int sectorLBA) {

	sub	esp, 12					; 0000000cH
	push	ebx

; 541  : 
; 542  : 	if (_CurrentDrive >= 4)

	mov	bl, BYTE PTR __CurrentDrive

; 543  : 		return 0;

	xor	eax, eax
	cmp	bl, 4
	jae	$LN3@flpydsk_re@4

; 544  : 
; 545  : 	//! convert LBA sector to CHS
; 546  : 	int head=0, track=0, sector=1;

	mov	DWORD PTR _head$[esp+16], eax
	mov	DWORD PTR _track$[esp+16], eax

; 547  : 	flpydsk_lba_to_chs (sectorLBA, &head, &track, &sector);

	lea	eax, DWORD PTR _sector$[esp+16]
	push	eax
	mov	eax, DWORD PTR _sectorLBA$[esp+16]
	lea	ecx, DWORD PTR _track$[esp+20]
	push	ecx
	lea	edx, DWORD PTR _head$[esp+24]
	push	edx
	push	eax
	mov	DWORD PTR _sector$[esp+32], 1
	call	?flpydsk_lba_to_chs@@YAXHPAH00@Z	; flpydsk_lba_to_chs
	add	esp, 16					; 00000010H

; 548  : 
; 549  : 	//! turn motor on and seek to track
; 550  : 	flpydsk_control_motor (true);

	cmp	bl, 3
	ja	SHORT $LN14@flpydsk_re@4
	movzx	ecx, bl
	xor	al, al
	cmp	ecx, 3
	ja	SHORT $LN11@flpydsk_re@4
	jmp	DWORD PTR $LN37@flpydsk_re@4[ecx*4]
$LN10@flpydsk_re@4:
	mov	al, 16					; 00000010H
	jmp	SHORT $LN11@flpydsk_re@4
$LN9@flpydsk_re@4:
	mov	al, 32					; 00000020H
	jmp	SHORT $LN11@flpydsk_re@4
$LN8@flpydsk_re@4:
	mov	al, 64					; 00000040H
	jmp	SHORT $LN11@flpydsk_re@4
$LN7@flpydsk_re@4:
	mov	al, 128					; 00000080H
$LN11@flpydsk_re@4:
	or	bl, al
	or	ebx, 12					; 0000000cH
	push	ebx
	push	1010					; 000003f2H
	call	?outportb@@YAXGE@Z			; outportb
	push	20					; 00000014H
	call	?sleep@@YAXH@Z				; sleep
	add	esp, 12					; 0000000cH
$LN14@flpydsk_re@4:
	push	esi

; 551  : 	if (flpydsk_seek ((uint8_t)track, (uint8_t)head) != 0)

	mov	esi, DWORD PTR _head$[esp+20]
	push	edi
	mov	edi, DWORD PTR _track$[esp+24]
	push	esi
	push	edi
	call	?flpydsk_seek@@YAHEE@Z			; flpydsk_seek
	add	esp, 8
	test	eax, eax
	je	SHORT $LN1@flpydsk_re@4
	pop	edi
	pop	esi

; 552  : 		return 0;

	xor	eax, eax
	pop	ebx

; 560  : }

	add	esp, 12					; 0000000cH
	ret	0
$LN1@flpydsk_re@4:

; 553  : 
; 554  : 	//! read sector and turn motor off
; 555  : 	flpydsk_read_sector_imp ((uint8_t)head, (uint8_t)track, (uint8_t)sector);

	mov	ecx, DWORD PTR _sector$[esp+24]
	push	ecx
	push	edi
	push	esi
	call	?flpydsk_read_sector_imp@@YAXEEE@Z	; flpydsk_read_sector_imp
	add	esp, 12					; 0000000cH

; 556  : 	flpydsk_control_motor (false);

	cmp	BYTE PTR __CurrentDrive, 3
	ja	SHORT $LN29@flpydsk_re@4
	push	4
	push	1010					; 000003f2H
	call	?outportb@@YAXGE@Z			; outportb
	push	20					; 00000014H
	call	?sleep@@YAXH@Z				; sleep
	add	esp, 12					; 0000000cH
$LN29@flpydsk_re@4:
	pop	edi

; 557  : 
; 558  : 	//! warning: this is a bit hackish
; 559  : 	return (uint8_t*) DMA_BUFFER;

	mov	eax, 4096				; 00001000H
	pop	esi
$LN3@flpydsk_re@4:
	pop	ebx

; 560  : }

	add	esp, 12					; 0000000cH
	ret	0
	npad	2
$LN37@flpydsk_re@4:
	DD	$LN10@flpydsk_re@4
	DD	$LN9@flpydsk_re@4
	DD	$LN8@flpydsk_re@4
	DD	$LN7@flpydsk_re@4
?flpydsk_read_sector@@YAPAEH@Z ENDP			; flpydsk_read_sector
_TEXT	ENDS
END