/*
clear ; \
gcc -Os -fno-stack-protector -fno-builtin -nostdinc -Wall -falign-jumps=1 -falign-loops=1 -falign-functions=1 -c -o start_exec-start.o ./start.S && \
gcc -o start.exec -nostdlib -Wl,-N -Wl,-Ttext -Wl,8000 start_exec-start.o && \
objcopy -O binary start.exec start && \
dd if=start of=vdi_HD.vdi bs=512 seek=$((0x18842)) conv=notrunc && \
sudo sync && \
rm start start_exec-start.o start.exec && \
VBoxManage startvm "lx"
*/

.file "start.S"
.text
.code16

.globl start, _start
start:
_start:

// _start is loaded at 0x8000 and is jumped to with
// CS:IP 0:0x8000 in stage2.
//we continue to use the stack for stage1 and assume that some registers are set to correct values.

// save drive reference first thing!
pushw %dx

// print a notification message on the screen
pushw %si
movw $(notification_string-_start+0x8000), %si; call message
popw %si

// this sets up for the first run through "bootloop"
movw $(firstlist - 8 -_start+0x8000), %di

// save the sector number of the second sector in %ebp
movl (%di), %ebp

// this is the loop for reading the secondary boot-loader in
bootloop:

// check the number of sectors to read
cmpw $0, 4(%di)

// if zero, go to the start function
je bootit

setup_sectors:
// check if we use LBA or CHS
cmpb $0, -1(%si)

// jump to chs_mode if zero
je chs_mode

lba_mode:
// load logical sector start
movl (%di), %ebx

// the maximum is limited to 0x7f because of Phoenix EDD
xorl %eax, %eax
movb $0x7f, %al

// how many do we really want to read?
cmpw %ax, 4(%di) // compare against total number of sectors

// which is greater?
jg 1f

// if less than, set to total
movw 4(%di), %ax

1:
// subtract from total
subw %ax, 4(%di)

// add into logical sector start
addl %eax, (%di)

// set up disk address packet

// the size and the reserved byte
movw $0x0010, (%si)

// the number of sectors
movw %ax, 2(%si)

// the absolute address (low 32 bits)
movl %ebx, 8(%si)

// the segment of buffer address
movw $(0x7000), 6(%si)

// save %ax from destruction!
pushw %ax

// zero %eax
xorl %eax, %eax

// the offset of buffer address
movw %ax, 4(%si)

// the absolute address (high 32 bits)
movl %eax, 12(%si)



//BIOS call "INT 0x13 Function 0x42" to read sectors from disk into memory
//Call with	%ah = 0x42
//		%dl = drive number
//		%ds:%si = segment:offset of disk address packet
//Return:
//		%al = 0x0 on success; err code on failure


movb $0x42, %ah
int $0x13

jc read_error

movw $(0x7000), %bx
jmp copy_buffer

chs_mode:
// load logical sector start (bottom half)
movl (%di), %eax

// zero %edx
xorl %edx, %edx

// divide by number of sectors
divl (%si)

// save sector start
movb %dl, 10(%si)

xorl %edx, %edx // zero %edx
divl 4(%si) // divide by number of heads

// save head start
movb %dl, 11(%si)

// save cylinder start
movw %ax, 12(%si)

// do we need too many cylinders?
cmpw 8(%si), %ax
jge geometry_error

// determine the maximum sector length of this read
movw (%si), %ax // get number of sectors per track/head

// subtract sector start
subb 10(%si), %al

// how many do we really want to read?
cmpw %ax, 4(%di) // compare against total number of sectors


// which is greater?
jg 2f

// if less than, set to total
movw 4(%di), %ax

2:
// subtract from total
subw %ax, 4(%di)

// add into logical sector start
addl %eax, (%di)


// This is the loop for taking care of BIOS geometry translation (ugh!)


// get high bits of cylinder
movb 13(%si), %dl

shlb $6, %dl // shift left by 6 bits
movb 10(%si), %cl // get sector

incb %cl // normalize sector (sectors go from 1-N, not 0-(N-1) )
orb %dl, %cl // composite together
movb 12(%si), %ch // sector+hcyl in cl, cylinder in ch

// restore %dx
popw %dx
pushw %dx

// head number
movb 11(%si), %dh

pushw %ax // save %ax from destruction!


// BIOS call "INT 0x13 Function 0x2" to read sectors from disk into memory
// Call with	%ah = 0x2
// 		%al = number of sectors
// 		%ch = cylinder
// 		%cl = sector (bits 6-7 are high bits of "cylinder")
// 		%dh = head
// 		%dl = drive (0x80 for hard disk, 0x0 for floppy disk)
// 		%es:%bx = segment:offset of buffer
// Return:
// 		%al = 0x0 on success; err code on failure


movw $(0x7000), %bx
movw %bx, %es // load %es segment with disk buffer

xorw %bx, %bx // %bx = 0, put it at 0 in the segment
movb $0x2, %ah // function 2
int $0x13

jc read_error

// save source segment
movw %es, %bx

copy_buffer:

// load addresses for copy from disk buffer to destination
movw 6(%di), %es // load destination segment

// restore %ax
popw %ax

// determine the next possible destination address (presuming 512 byte sectors!)
shlw $5, %ax // shift %ax five bits to the left
addw %ax, 6(%di) // add the corrected value to the destination address for next time

// save addressing regs
pusha
pushw %ds

// get the copy length
shlw $4, %ax
movw %ax, %cx

xorw %di, %di // zero offset of destination addresses
xorw %si, %si // zero offset of source addresses
movw %bx, %ds // restore the source segment

cld // sets the copy direction to forward

// perform copy
rep // sets a repeat
movsb // this runs the actual copy

// restore addressing regs and print a dot with correct DS (MSG modifies SI, which is saved, and unused AX and BX)
popw %ds
movw $(notification_step-_start+0x8000), %si; call message
popa

// check if finished with this dataset
cmpw $0, 4(%di)
jne setup_sectors

// update position to load from
subw $8, %di

// jump to bootloop
jmp bootloop

// END OF MAIN LOOP

bootit:
// print a newline
movw $(notification_done-_start+0x8000), %si; call message
popw %dx // this makes sure %dl is our "boot" drive



ljmp $0, $0x8200




// BIOS Geometry translation error (past the end of the disk geometry!).

geometry_error:
movw $(geometry_error_string-_start+0x8000), %si; call message
jmp general_error


// Read error on the disk.

read_error:
movw $(read_error_string-_start+0x8000), %si; call message

general_error:
movw $(general_error_string-_start+0x8000), %si; call message

// go here when you need to stop the machine hard after an error condition
stop: jmp stop




notification_string: .string "Loading stage2"


notification_step: .string "."
notification_done: .string "\r\n"

geometry_error_string: .string "Geom"
read_error_string: .string "Read"
general_error_string: .string " Error"


// message: write the string pointed to by %si

// WARNING: trashes %si, %ax, and %bx



// Use BIOS "int 10H Function 0Eh" to write character in teletype mode
// %ah = 0xe	%al = character
// %bh = page	%bl = foreground color (graphics modes)

1:
movw $0x0001, %bx
movb $0xe, %ah
int $0x10 // display a byte

incw %si
message:
movb (%si), %al
cmpb $0, %al
jne 1b // if not end of string, jmp to display
ret
lastlist:


// This area is an empty space between the main body of code below which
// grows up (fixed after compilation, but between releases it may change
// in size easily), and the lists of sectors to read, which grows down
// from a fixed top location.


.word 0
.word 0

. = _start + 0x200 - 16

.long 0x0001885a
.long 0x0b00006e
// fill the first data listing with the default
blocklist_default_start: .long 0x00018841         // sector start parameter          // alterou AQUI e os oito bytes anteriores
blocklist_default_len:   .word 0x0017             // number of sectors to read       // alterou AQUI
blocklist_default_seg:   .word 0x0820 // this is the segment of the starting address to load the data into
firstlist: // this label has to be after the list data!!!
