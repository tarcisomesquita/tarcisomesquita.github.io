
CC           := /usr/bin/gcc
LD           := /usr/bin/ld
OBJCOPY      := /usr/bin/objcopy

OS           := $(shell uname -s)

export HAVE_EFI_OBJCOPY=y

CFLAGS += -Wno-error=pragmas -mno-red-zone -fpic

CFLAGS  += -g -O2 -Wall -Wextra -Werror \
           -fshort-wchar -fno-strict-aliasing \
	   -ffreestanding -fno-stack-protector -fno-stack-check \
           -fno-stack-check -fno-merge-all-constants

CPPFLAGS += -DCONFIG_x86_64
CPPFLAGS += -DGNU_EFI_USE_MS_ABI -maccumulate-outgoing-args --std=c11

LDFLAGS	+= -nostdlib --warn-common --no-undefined --fatal-warnings --build-id=sha1
LDFLAGS	+= -shared -Bsymbolic -L../x86_64/lib -L../x86_64/gnuefi ../x86_64/gnuefi/crt0-efi-x86_64.o

CPPFLAGS	+= -D__KERNEL__ -I/usr/src/sys/build/include


SRCDIR = .
TOPDIR := $(shell pwd)
INCDIR  += -I$(SRCDIR) -I$(TOPDIR)/inc -I$(TOPDIR)/inc/x86_64 -I$(TOPDIR)/inc/protocol

TOPDIR = $(SRCDIR)/..

export LIBGCC=$(shell $(CC) -print-libgcc-file-name)
LOADLIBES	+= -lefi -lgnuefi $(LIBGCC)
LOADLIBES	+= -T $(TOPDIR)/gnuefi/elf_x86_64_efi.lds

TARGET_APPS = t.efi t2.efi t3.efi t4.efi t5.efi t6.efi \
	      printenv.efi t7.efi t8.efi tcc.efi modelist.efi \
	      route80h.efi drv0_use.efi AllocPages.efi exit.efi \
	      FreePages.efi setjmp.efi debughook.efi debughook.efi.debug \
	      bltgrid.efi lfbgrid.efi setdbg.efi unsetdbg.efi

# TALVEZ MUDAR AQUI
TARGET_BSDRIVERS = drv0.efi

FORMAT		:= --target efi-app-x86_64
$(TARGET_BSDRIVERS): FORMAT=--target efi-bsdrv-x86_64

TARGETS = $(TARGET_APPS) $(TARGET_BSDRIVERS)

all:	$(TARGETS)

clean:
	rm -f $(TARGETS) *~ *.o *.so


%.efi: %.so
	$(OBJCOPY) -j .text -j .sdata -j .data -j .dynamic -j .dynsym -j .rel \
		    -j .rela -j .rel.* -j .rela.* -j .rel* -j .rela* \
		    -j .reloc $(FORMAT) $*.so $@

%.efi.debug: %.so
	$(OBJCOPY) -j .debug_info -j .debug_abbrev -j .debug_aranges \
		-j .debug_line -j .debug_str -j .debug_ranges \
		-j .note.gnu.build-id \
		$(FORMAT) $*.so $@

%.so: %.o
	$(LD) $(LDFLAGS) $^ -o $@ $(LOADLIBES)

%.o: %.c
	$(CC) $(INCDIR) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

%.S: %.c
	$(CC) $(INCDIR) $(CFLAGS) $(CPPFLAGS) -S $< -o $@

%.E: %.c
	$(CC) $(INCDIR) $(CFLAGS) $(CPPFLAGS) -E $< -o $@
