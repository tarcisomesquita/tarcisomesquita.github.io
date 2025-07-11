/*
requer gnu-efi package


i686-w64-mingw32-gcc -c -o uefi.o -I ./gnu-efi-3.0.9/inc -I ./gnu-efi-3.0.9/inc/x86_64/ uefi.c
i686-w64-mingw32-ld -shared -dll --subsystem 10 -nostdlib -o uefi.efi -e _efi_main uefi.o
file uefi.efi 

i686-w64-mingw32-gcc -c -o uefi.o -I ./gnu-efi-3.0.9/inc -I ./gnu-efi-3.0.9/inc/ia32 uefi.c
i686-w64-mingw32-ld -b pei-i386 -shared -dll --subsystem 10 -nostdlib -o uefi.efi -e _efi_main uefi.o

Note here that '--subsystem 10' specifies an EFI application.


mkdir -p UEFI/EFI/BOOT
cp uefi.efi	UEFI/EFI/BOOT/BOOTx64.EFI
mkisofs -V UEFI -o uefi.iso UEFI/

*/

#include <efi.h>
#include <efilib.h>
 
EFI_SYSTEM_TABLE *gST;
 
EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable) {
    EFI_STATUS Status;
    EFI_INPUT_KEY Key;
 
    /* Store the system table for future use in other functions */
    gST = SystemTable;
 
    /* Say hi */
    Status = gST->ConOut->OutputString(gST->ConOut, L"Hello World\n\r");
    if (EFI_ERROR(Status))
        return Status;
 
    /* Now wait for a keystroke before continuing, otherwise your
       message will flash off the screen before you see it.
 
       First, we need to empty the console input buffer to flush
       out any keystrokes entered before this point */
    Status = gST->ConIn->Reset(gST->ConIn, FALSE);
    if (EFI_ERROR(Status))
        return Status;
 
    /* Now wait until a key becomes available.  This is a simple
       polling implementation.  You could try and use the WaitForKey
       event instead if you like */
    while ((Status = gST->ConIn->ReadKeyStroke(gST->ConIn, &Key)) == EFI_NOT_READY) ;
 
    return Status;
}

