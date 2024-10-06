#include <efi.h>
#include <efilib.h>

EFI_STATUS
EFIAPI
efi_main (EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
   InitializeLib(ImageHandle, SystemTable);
   Print(L"Hello, world!\n");

   return EFI_SUCCESS;
}
/*
InitializeLib() sets up some global variables
ST is system table
BS is boot services
RT is runtime services
If you use the TianoCore EDK II, this call doesn't exist, and the variables in question are generally referred to as gST, gBS, and gRT, respectively.

Print() is similar to printf()
Strings in EFI use a 16-bit encoding, so you must precede string constants with the character L
string variables must be defined as a CHAR16* type in order to display properly with Print() or to be passed to most EFI functions.


EFI=./gnu-efi-3.0.9
gcc -I${EFI}/inc -I${EFI}/inc/x86_64 -I${EFI}/inc/protocol -fno-stack-protector -fpic -fshort-wchar -mno-red-zone -Wall -DEFI_FUNCTION_WRAPPER -c -o hello.o EFI_helloWorld.c

ld -nostdlib -znocombreloc -T ${EFI}/gnuefi/elf_x86_64_efi.lds -shared -Bsymbolic -L ${EFI}/x86_64/lib -L ${EFI}/x86_64/gnuefi ${EFI}/x86_64/gnuefi/crt0-efi-x86_64.o  hello.o -o hello.so -lefi -lgnuefi

objcopy -j .text -j .sdata -j .data -j .dynamic -j .dynsym  -j .rel -j .rela -j .reloc --target=efi-app-x86_64 hello.so hello.efi
*/
