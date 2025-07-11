/*
#sudo apt-get install gcc-mingw-w64

#edit gnu-efi/lib/data.c setting all the members of the LibStubUnicodeInterface structure to NULL.

x86_64-w64-mingw32-gcc -ffreestanding -I./gnu-efi-3.0.9/inc -I./gnu-efi-3.0.9/inc/x86_64 -I./gnu-efi-3.0.9/inc/protocol -c -o hello.o 1_hello.c
x86_64-w64-mingw32-gcc -ffreestanding -I./gnu-efi-3.0.9/inc -I./gnu-efi-3.0.9/inc/x86_64 -I./gnu-efi-3.0.9/inc/protocol -c -o data.o gnu-efi-3.0.9/lib/data.c

x86_64-w64-mingw32-gcc -nostdlib -Wl,-dll -shared -Wl,--subsystem,10 -e efi_main -o BOOTX64.EFI hello.o data.o -lgcc -L gnu-efi-3.0.9/x86_64/lib/ -lefi

mkdir -p UEFI/EFI/BOOT
cp BOOTX64.EFI UEFI/EFI/BOOT/BOOTx64.EFI
mkisofs -V UEFI -o uefi.iso UEFI/

rm -r hello.o data.o UEFI/EFI/BOOT
*/


#include <efi.h>
#include <efilib.h>
 
EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
  EFI_STATUS Status;
  EFI_INPUT_KEY Key;
 
  // Store the system table for future use in other functions
  ST = SystemTable;
 
  // Say hi
  Status = ST->ConOut->OutputString(ST->ConOut, L"Hello World\n\r");
  if (EFI_ERROR(Status)) return Status;
 
  /* Now wait for a keystroke before continuing, otherwise your
     message will flash off the screen before you see it.
 
     First, we need to empty the console input buffer to flush
     out any keystrokes entered before this point */
  Status = ST->ConIn->Reset(ST->ConIn, FALSE);
  if (EFI_ERROR(Status)) return Status;
 
  /* Now wait until a key becomes available.  This is a simple
     polling implementation.  You could try and use the WaitForKey
     event instead if you like */
  while ((Status = ST->ConIn->ReadKeyStroke(ST->ConIn, &Key)) == EFI_NOT_READY) ;
 
  return Status;
}
