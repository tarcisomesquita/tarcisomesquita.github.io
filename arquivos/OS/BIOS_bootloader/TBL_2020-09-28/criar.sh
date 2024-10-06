#!/bin/bash

#        mbr + bootloader + kernel    + initrd    + disco     + int13AH02
# 512 * (2   + 2*10       + 2*1024*10 + 2*1024*40 +           + 2*1024*8)
TSIZE=$((2   + 2*10       + 2*1024*10 + 2*1024*40 + 2*1024*16 + 2*1024*8))
dd if=/dev/zero of=TBL.bin bs=512 count=$TSIZE 2>/dev/null

echo "# Disk DescriptorFile
version=1
CID=d6d5fd82
parentCID=ffffffff
createType=\"fullDevice\"

# Extent description
RW $TSIZE FLAT \"$(pwd)/TBL.bin\" 0

ddb.virtualHWVersion = \"4\"
ddb.adapterType=\"ide\"
ddb.uuid.image=\"136eb13f-c900-41d4-82fd-30a1e45f36a7\"
" > image.vmdk
cat image.vmdk


gcc -Os -m32 -mtune=generic -march=i686 -fno-stack-protector -fno-builtin -nostdinc -Wall -Werror -falign-jumps=1 -falign-loops=1 -falign-functions=1 -c -o mbr.o ./TBL_mbr.asm

/usr/bin/ld -m elf_i386 -s -static -o mbr.elf -N -Ttext 7C00 mbr.o

objcopy -O binary mbr.elf mbr.bin

rm mbr.elf mbr.o


dd if=mbr.bin      of=image.bin bs=512 skip=0 seek=0                         count=1              conv=notrunc 2>/dev/null
dd if=tbl.bin      of=image.bin bs=512 skip=0 seek=2                         count=$((2*10))      conv=notrunc 2>/dev/null
dd if=vmlinuz.bin  of=image.bin bs=512 skip=0 seek=$((2 + 2*10))             count=$((2*1024*10)) conv=notrunc 2>/dev/null
dd if=initrd.bin   of=image.bin bs=512 skip=0 seek=$((2 + 2*10 + 2*1024*10)) count=$((2*1024*40)) conv=notrunc 2>/dev/null


