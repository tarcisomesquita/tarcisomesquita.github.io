/*
gcc -c -fno-stack-protector -fpic -fshort-wchar -mno-red-zone -I ./gnu-efi-3.0.9/inc -I ./gnu-efi-3.0.9/inc/x86_64 -DEFI_FUNCTION_WRAPPER -o main.o 3_gnu-efi.c

ld main.o gnu-efi-3.0.9/x86_64/gnuefi/crt0-efi-x86_64.o -nostdlib -znocombreloc -T gnu-efi-3.0.9/gnuefi/elf_x86_64_efi.lds -shared -Bsymbolic -L gnu-efi-3.0.9/x86_64/gnuefi/ -l:libgnuefi.a -L gnu-efi-3.0.9/x86_64/lib/ -l:libefi.a -o main.so

objcopy -j .text -j .sdata -j .data -j .dynamic -j .dynsym -j .rel -j .rela -j .reloc --target=efi-app-x86_64 main.so main.efi

mkdir -p UEFI/EFI/BOOT
cp main.efi UEFI/EFI/BOOT/BOOTx64.EFI
mkisofs -V UEFI -o uefi.iso UEFI/
*/

#include <efi.h>
#include <efilib.h>
 
EFI_STATUS EFIAPI efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
  InitializeLib(ImageHandle, SystemTable);
  Print(L"Hello, world!\n");
  return EFI_SUCCESS;
}
