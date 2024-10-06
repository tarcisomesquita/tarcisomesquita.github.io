#!/bin/bash

rm -rf tbl

# = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

OPT="-Os -m32 -mtune=generic -march=i686 -fno-stack-protector -fno-builtin -nostdinc -Wall -Werror -falign-jumps=1 -falign-loops=1 -falign-functions=1"

gcc $OPT -c -o main.o                   ./main.S                   && \
gcc $OPT -c -o real_to_prot.o           ./real_to_prot.S           && \
gcc $OPT -c -o prot_to_real.o           ./prot_to_real.S           && \
gcc $OPT -c -o stop.o                   ./stop.S                   && \
gcc $OPT -c -o tbl_printf.o             ./tbl_printf.c             && \
gcc $OPT -c -o console_getkey.o         ./console_getkey.S         && \
\
gcc $OPT -c -o gateA20.o                ./gateA20.S                && \
gcc $OPT -c -o get_diskinfo.o           ./get_diskinfo.c           && \
gcc $OPT -c -o int13_ah08.o             ./int13_ah08.S             && \
\
gcc $OPT -c -o mainc.o                  ./mainc.s                  && \
gcc $OPT -c -o devread_my.o             ./devread_my.c             && \
gcc $OPT -c -o int13_ah02.o             ./int13_ah02.S             && \
gcc $OPT -c -o grub_memmove.o           ./grub_memmove.S           && \
gcc $OPT -c -o big_linux_boot.o         ./big_linux_boot.S         && \
\
/usr/lib/gcc/x86_64-linux-gnu/4.9/collect2 -m elf_i386 -s -static -o tbl.elf -N -Ttext 2000 main.o real_to_prot.o prot_to_real.o stop.o tbl_printf.o console_getkey.o gateA20.o get_diskinfo.o int13_ah02.o mainc.o devread_my.o int13_ah08.o grub_memmove.o big_linux_boot.o && \
\
objcopy -O binary tbl.elf tbl && \
\
rm -rf *.o rm *.elf *~ && exit 0

exit 1

