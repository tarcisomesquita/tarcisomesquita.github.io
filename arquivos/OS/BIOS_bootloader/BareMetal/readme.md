cd BMFS
make NO_FUSE=1 NO_UNIX_UTILS=1
mkdir ../../bin/
mv src/bmfs ../../bin/
cd ../../bin
./bmfs bmfs.image initialize 128M
cd ..

cd Pure64
nasm src/bootsectors/bmfs_mbr.asm -o bmfs_mbr.sys
nasm src/bootsectors/multiboot.asm -o multiboot.sys
nasm src/bootsectors/pxestart.asm -o pxestart.sys
cd src
nasm pure64.asm -o ../pure64.sys
cd ..
mv *.sys ../../bin/
cd ..

cd BareMetal-OS/os
nasm kernel64.asm -o ../../../bin/kernel64.sys
cd ../../..

cd bin
echo Formatting Disk Image
./bmfs bmfs.image format /force
echo Writing Master Boot Record
dd if=bmfs_mbr.sys of=bmfs.image bs=512 conv=notrunc

echo Writing Pure64+Software
cat pure64.sys kernel64.sys > software.sys
dd if=software.sys of=bmfs.image bs=512 seek=16 conv=notrunc
cd ..

VBoxManage internalcommands createrawvmdk -filename ${HOME}/bmfs.vmdk -rawdisk $(pwd)/bin/bmfs.image
FALHOU

you should see a '>' prompt.
You can now run the application by typing:
sysinfo.app (FALHOU)


cd src/BareMetal-OS/programs/
gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o hello.o helloc.c
gcc -c -m64 -nostdlib -nostartfiles -nodefaultlibs -fomit-frame-pointer -mno-red-zone -o libBareMetal.o libBareMetal.c
ld -T app.ld -o ../../../bin/hello.app hello.o libBareMetal.o
cd ../../../bin
./bmfs bmfs.image create hello.app 2
./bmfs bmfs.image write  hello.app
cd ..

> helloc.app (FALHOU)
