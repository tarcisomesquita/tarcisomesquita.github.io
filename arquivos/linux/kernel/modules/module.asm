
section .text

	global init_module
	global cleanup_module
	global kernel_version

	extern printk

init_module:
	push	dword str1
	call	printk
	pop	eax
	xor	eax,eax
	ret

cleanup_module:
	push	dword str2
	call	printk
	pop	eax
	ret
	
str1		db	"init_module done",0xa,0
str2		db	"cleanup_module done",0xa,0

kernel_version	db	"2.2.18",0

The only thing this example does is reporting its actions. Modify kernel_version to match yours, and build module with:

$ nasm -f elf -o module.m module.asm

$ ld -r -o module.o module.m

Now you can play with it using insmod/rmmod/lsmod (root privilidged are required); a lot of fun, huh?

