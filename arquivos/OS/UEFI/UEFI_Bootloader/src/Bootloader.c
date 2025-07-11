// Source Code: https://github.com/KNNSpeed/Simple-UEFI-Bootloader
// This program is an x86-64 bootloader
// It loads programs specified by Kernel64.txt and passes the following structure to them:
/*
  typedef struct {
    UINT32                    UEFI_Version;                   // The system UEFI version
    UINT32                    Bootloader_MajorVersion;        // The major version of the bootloader
    UINT32                    Bootloader_MinorVersion;        // The minor version of the bootloader

    UINT32                    Memory_Map_Descriptor_Version;  // The memory descriptor version
    UINTN                     Memory_Map_Descriptor_Size;     // The size of an individual memory descriptor
    EFI_MEMORY_DESCRIPTOR    *Memory_Map;                     // The system memory map as an array of EFI_MEMORY_DESCRIPTOR structs
    UINTN                     Memory_Map_Size;                // The total size of the system memory map

    EFI_PHYSICAL_ADDRESS      Kernel_BaseAddress;             // The base memory address of the loaded kernel file
    UINTN                     Kernel_Pages;                   // The number of pages (1 page == 4096 bytes) allocated for the kernel file

    CHAR16                   *ESP_Root_Device_Path;           // A UTF-16 string containing the drive root of the EFI System Partition as converted from UEFI device path format
    UINT64                    ESP_Root_Size;                  // The size (in bytes) of the above ESP root string
    CHAR16                   *Kernel_Path;                    // A UTF-16 string containing the kernel's file path relative to the EFI System Partition root (it's the first line of Kernel64.txt)
    UINT64                    Kernel_Path_Size;               // The size (in bytes) of the above kernel file path
    CHAR16                   *Kernel_Options;                 // A UTF-16 string containing various load options (it's the second line of Kernel64.txt)
    UINT64                    Kernel_Options_Size;            // The size (in bytes) of the above load options string

    EFI_RUNTIME_SERVICES     *RTServices;                     // UEFI Runtime Services
    GPU_CONFIG               *GPU_Configs;                    // Information about available graphics output devices; see below GPU_CONFIG struct for details
    EFI_FILE_INFO            *FileMeta;                       // Kernel file metadata
    EFI_CONFIGURATION_TABLE  *ConfigTables;                   // UEFI-installed system configuration tables (ACPI, SMBIOS, etc.)
    UINTN                     Number_of_ConfigTables;         // The number of system configuration tables
  } LOADER_PARAMS;
*/
//
// GPU_CONFIG is a custom structure that is defined as follows:
//
/*
  typedef struct {
    EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE  *GPUArray;             // An array of EFI_GRAPHICS_OUTPUT_PROTOCOL_MODE structs defining each available framebuffer
    UINT64                              NumberOfFrameBuffers; // The number of structs in the array (== the number of available framebuffers)
  } GPU_CONFIG;
*/
//
// if you want keyboard input, you need to program the PS/2 or USB subsystem to get it.
//
// \EFI\BOOT\BOOTX64.EFI
// 2. Put the bare metal program or kernel somewhere on the same FAT32 drive or EFI System Partition.
//
// 3. Make a file called Kernel64.txt--this should be stored **in the same folder as the bootloader itself.** See the next section for how to properly format this file.
//
// That's it! If your kernel file's entry point function is something like **main_function(LOADER_PARAMS * LP)**, it should load after you
// select how you want your graphics output device(s) configured. See https://github.com/KNNSpeed/Simple-Kernel for an example, including
// proper compilation options.
//
//----------------------------------------------------------------------------------------------------------------------------------
// Kernel64.txt Format and Contents:
//----------------------------------------------------------------------------------------------------------------------------------
//
// Kernel64.txt should be stored in UTF-16 format in the same directory as the boot loader on the EFI System Partition.
//
// First line should be the filename and location of the kernel, e.g. \EFI\Kernel1\MyKernel.64
// Second line is the string of load options to be passed to the kernel, e.g. "root=/dev/nvme0n1p5 initrd=\\\EFI\\\ubuntu\\\initrd.img
// Third line should be blank


// Booting Multiple Kernels:
//----------------------------------------------------------------------------------------------------------------------------------
//
// A copy of the bootloader and a kernel64.txt file is required for every kernel in a multi-use situation. Recommended
// practice for booting multiple kernels is to make a folder for each kernel, and each folder should contain its own bootloader,
// kernel64.txt, and kernel file. The method to boot multiple kernel files varies by machine: generally there is a firmware boot menu
// accessed by F10, F11, F12, etc. at power-on, and entries can be added to this menu in the UEFI firmware setup (accessed by F2, DEL,
// etc. at power-on). Some machines may need boot entries added by the Linux program efibootmgr, and some might only work with one UEFI
// application stored in the folder \EFI\BOOT\ with the filename BOOTX64.EFI. In more inconvenient cases like these, it is probably easier
// to just boot from FAT32-formatted USB drives using the same \EFI\BOOT\BOOTX64.EFI convention. If the UEFI firmware allows booting from
// them, CDs/DVDs and FAT/FAT16-formatted drives (like floppies) can be used with the same file/folder naming scheme, too.
//

#include "Bootloader.h"

STATIC CONST CHAR16 AppleFirmwareVendor[6] = L"Apple";
UINT8 IsApple = 0;

//==================================================================================================================================
//  efi_main: Main Function
//==================================================================================================================================
//
// Loader's "main" function. This bootloader's program entry point is defined as efi_main per UEFI application convention.
//

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  // ImageHandle is this program's own EFI_HANDLE
  // SystemTable is the EFI system table of the machine

  // Initialize the GNU-EFI library
  InitializeLib(ImageHandle, SystemTable);
/*
  From InitializeLib:

  ST = SystemTable;
  BS = SystemTable->BootServices;
  RT = SystemTable->RuntimeServices;

*/
  EFI_STATUS Status;

  // Do a preliminary screen clear, always
  Status = SystemTable->ConOut->ClearScreen(SystemTable->ConOut);
  if(EFI_ERROR(Status))
  {
    Print(L"NOTE: Could not clear the screen, so there may be some system text above this line.\r\n");
  }

#ifdef DISABLE_UEFI_WATCHDOG_TIMER
  // Disable watchdog timer for debugging
  Status = BS->SetWatchdogTimer (0, 0, 0, NULL);
  if(EFI_ERROR(Status))
  {
    Print(L"Error stopping watchdog, timeout still counting down...\r\n");
  }
#endif

  // Thanks to the rEFIt 0.14 project for having figured this out long ago. ConsoleControlProtocol is needed to switch Mac boot graphics to text mode.
  if(compare(ST->FirmwareVendor, AppleFirmwareVendor, 6))
  {
    IsApple = 1;
    EFI_CONSOLE_CONTROL_PROTOCOL * ConsoleMode = NULL;
    Status = LibLocateProtocol(&ConsoleControlProtocol, (VOID**)&ConsoleMode); // Find the handle that corresponds to this protocol. There's only 1.
    if(EFI_ERROR(Status))
    {
      ConsoleMode = NULL;

  #ifdef MAIN_DEBUG_ENABLED
      Print(L"Console Control Protocol not located. It may not be supported.\r\n");
  #endif
    }

    if(ConsoleMode != NULL)
    {
      EFI_CONSOLE_CONTROL_SCREEN_MODE Current_Mode;

      ConsoleMode->GetMode(ConsoleMode, &Current_Mode, NULL, NULL);

      if(Current_Mode != EfiConsoleControlScreenText)
      {
  #ifdef MAIN_DEBUG_ENABLED
        Print(L"Console control protocol located & now setting text mode...\r\n");
  #endif

        ConsoleMode->SetMode(ConsoleMode, EfiConsoleControlScreenText);

  #ifdef MAIN_DEBUG_ENABLED
        Print(L"Text mode set.\r\n");
  #endif
      }
  #ifdef MAIN_DEBUG_ENABLED
      else
      {
        Print(L"Output already in text mode.\r\n");
      }
  #endif
    }
  }
  // End text mode

  // Print out general system info
  EFI_TIME Now;
  Status = RT->GetTime(&Now, NULL);
  if(EFI_ERROR(Status))
  {
    Print(L"Error getting time...\r\n");
    return Status;
  }

  Print(L"%02hhu/%02hhu/%04hu - %02hhu:%02hhu:%02hhu.%u\r\n\n", Now.Month, Now.Day, Now.Year, Now.Hour, Now.Minute, Now.Second, Now.Nanosecond); // GNU-EFI apparently has a print function for time... Oh well.
#ifdef MAIN_DEBUG_ENABLED
  #ifdef MEMORY_DEBUG_ENABLED // Very slow memory debug version
    Print(L"Simple UEFI Bootloader - V%u.%u DEBUG (Memory)\r\n", MAJOR_VER, MINOR_VER);
  #else // Standard debug version
    Print(L"Simple UEFI Bootloader - V%u.%u DEBUG\r\n", MAJOR_VER, MINOR_VER);
  #endif
#else
  #ifdef FINAL_LOADER_DEBUG_ENABLED // Lite debug version
    Print(L"Simple UEFI Bootloader - V%u.%u DEBUG (Lite)\r\n", MAJOR_VER, MINOR_VER);
  #else // Release version
    Print(L"Simple UEFI Bootloader - V%u.%u\r\n", MAJOR_VER, MINOR_VER);
  #endif
#endif
  Print(L"Copyright (c) 2017-2019 KNNSpeed\r\n\n");
  Print(L"For software licensing information and related usage terms, please refer to the LICENSE file found at https://github.com/KNNSpeed/Simple-UEFI-Bootloader.\r\n\n");

  UINT64 timeout_seconds = 10; // 10 seconds
  EFI_INPUT_KEY Key_Check = {0};

  while(timeout_seconds)
  {
    Print(L"Continuing in %llu, press 's' to stop timer or press any other key to continue. \r", timeout_seconds);
    Status = WaitForSingleEvent(ST->ConIn->WaitForKey, 10000000); // Timeout units are 100ns
    if(Status != EFI_TIMEOUT)
    {
      Status = ST->ConIn->ReadKeyStroke(ST->ConIn, &Key_Check);
      if (EFI_ERROR(Status))
      {
        Print(L"\nError reading keystroke. 0x%llx\r\n", Status);
        return Status;
      }

      if(Key_Check.UnicodeChar == L's')
      {
        Keywait(L"\nTimer stopped. ");
      }
      else
      {
        Print(L"\n");
        Status = ST->ConIn->Reset(ST->ConIn, FALSE);
        if (EFI_ERROR(Status))
        {
          Print(L"Error resetting input buffer. 0x%llx\r\n", Status);
          return Status;
        }
      }

      break;
    }
    timeout_seconds -= 1;
  }
  if(!timeout_seconds)
  {
    Print(L"\n");
  }
  Print(L"\r\n");

#ifdef MAIN_DEBUG_ENABLED
  Print(L"EFI System Table Info\r\n   Signature: 0x%lx\r\n   UEFI Revision: 0x%08x\r\n   Header Size: %u Bytes\r\n   CRC32: 0x%08x\r\n   Reserved: 0x%x\r\n", ST->Hdr.Signature, ST->Hdr.Revision, ST->Hdr.HeaderSize, ST->Hdr.CRC32, ST->Hdr.Reserved);
#else
  Print(L"EFI System Table Info\r\n   Signature: 0x%lx\r\n   UEFI Revision: %u.%u", ST->Hdr.Signature, ST->Hdr.Revision >> 16, (ST->Hdr.Revision & 0xFFFF) / 10);
  if((ST->Hdr.Revision & 0xFFFF) % 10)
  {
    Print(L".%u\r\n", (ST->Hdr.Revision & 0xFFFF) % 10); // UEFI major.minor version numbers are defined in BCD (in a 65535.65535 format) and are meant to be displayed as 2 digits if the minor ones digit is 0. Sub-minor revisions are included in the minor number. See the "EFI_TABLE_HEADER" section in any UEFI spec.
    // The spec also states that minor versions are limited to a max of 99, even though they get to have a whole 16-bit number.
  }
  else
  {
    Print(L"\r\n");
  }
#endif

  Print(L"   Firmware Vendor: %s\r\n   Firmware Revision: 0x%08x\r\n\n", ST->FirmwareVendor, ST->FirmwareRevision);

  // Configuration table info
  Print(L"%llu system configuration tables are available.\r\n", ST->NumberOfTableEntries);

#ifdef MAIN_DEBUG_ENABLED
  Keywait(L"\0");

  // Search for ACPI tables
  UINT8 RSDPfound = 0;
  UINTN RSDP_index = 0;

  // This print is for debugging
  for(UINTN i=0; i < ST->NumberOfTableEntries; i++)
  {
    Print(L"Table %llu GUID: %08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x\r\n", i,
            ST->ConfigurationTable[i].VendorGuid.Data1,
            ST->ConfigurationTable[i].VendorGuid.Data2,
            ST->ConfigurationTable[i].VendorGuid.Data3,
            ST->ConfigurationTable[i].VendorGuid.Data4[0],
            ST->ConfigurationTable[i].VendorGuid.Data4[1],
            ST->ConfigurationTable[i].VendorGuid.Data4[2],
            ST->ConfigurationTable[i].VendorGuid.Data4[3],
            ST->ConfigurationTable[i].VendorGuid.Data4[4],
            ST->ConfigurationTable[i].VendorGuid.Data4[5],
            ST->ConfigurationTable[i].VendorGuid.Data4[6],
            ST->ConfigurationTable[i].VendorGuid.Data4[7]);

    if (compare(&ST->ConfigurationTable[i].VendorGuid, &Acpi20TableGuid, 16))
    {
      Print(L"RSDP 2.0 found!\r\n");
      RSDP_index = i;
      RSDPfound = 2;
    }
  }
  // If no RSDP 2.0, check for 1.0
  if(!RSDPfound)
  {
    for(UINTN i=0; i < ST->NumberOfTableEntries; i++)
    {
      if (compare(&ST->ConfigurationTable[i].VendorGuid, &AcpiTableGuid, 16))
      {
        Print(L"RSDP 1.0 found!\r\n");
        RSDP_index = i;
        RSDPfound = 1;
      }
    }
  }

  if(!RSDPfound)
  {
    Print(L"System has no RSDP.\r\n");
  }

  Keywait(L"\0");

  // View memmap before too much happens to it
  print_memmap();
  Keywait(L"Done printing MemMap.\r\n");
#endif

  // Create graphics structure
  GPU_CONFIG *Graphics;
  Status = ST->BootServices->AllocatePool(EfiLoaderData, sizeof(GPU_CONFIG), (void**)&Graphics);
  if(EFI_ERROR(Status))
  {
    Print(L"Graphics AllocatePool error. 0x%llx\r\n", Status);
    return Status;
  }

#ifdef MAIN_DEBUG_ENABLED
  Print(L"Graphics struct allocated\r\n");
#endif

  // Set up graphics
  Status = InitUEFI_GOP(ImageHandle, Graphics);
  if(EFI_ERROR(Status))
  {
    Print(L"InitUEFI_GOP error. 0x%llx\r\n", Status);
    Keywait(L"\0");
    return Status;
  }

#ifdef MAIN_DEBUG_ENABLED
  Keywait(L"InitUEFI_GOP finished.\r\n");

  // Data verification
  Print(L"Config table address: 0x%llx\r\n", ST->ConfigurationTable);
  Print(L"Data at RSDP (first 16 bytes): 0x%016llx%016llx\r\n", *(EFI_PHYSICAL_ADDRESS*)(((UINT64)ST->ConfigurationTable[RSDP_index].VendorTable) + 8), *(EFI_PHYSICAL_ADDRESS*)ST->ConfigurationTable[RSDP_index].VendorTable);
#endif

  // Load a program and exit boot services, then pass a loader block to that program's entry point to execute the program
  Status = GoTime(ImageHandle, Graphics, ST->ConfigurationTable, ST->NumberOfTableEntries, ST->Hdr.Revision);

  // Pause to evaluate any errors
  Keywait(L"GoTime returned...\r\n");
  return Status;
}

//==================================================================================================================================
//  Keywait: Pause
//==================================================================================================================================
//
// A simple pause function that waits for user input before continuing.
// Adapted from http://wiki.osdev.org/UEFI_Bare_Bones
//
// Note: Does not take format modifier arguments like %s, %d, etc., only plain strings.
//

EFI_STATUS Keywait(CHAR16 *String)
{
  EFI_STATUS Status;
  EFI_INPUT_KEY Key;
  Print(String);

  Status = ST->ConOut->OutputString(ST->ConOut, L"Press any key to continue...");
  if (EFI_ERROR(Status))
  {
    return Status;
  }

  // Clear keystroke buffer
  Status = ST->ConIn->Reset(ST->ConIn, FALSE);
  if (EFI_ERROR(Status))
  {
    return Status;
  }

  // Poll for key
  while ((Status = ST->ConIn->ReadKeyStroke(ST->ConIn, &Key)) == EFI_NOT_READY);

  // Clear keystroke buffer (this is just a pause)
  Status = ST->ConIn->Reset(ST->ConIn, FALSE);
  if (EFI_ERROR(Status))
  {
    return Status;
  }

  Print(L"\r\n");

  return Status;
}
