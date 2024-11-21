VERSION = 3.0.9

MKFILE_PATH := $(abspath $(lastword $(MAKEFILE_LIST)))
SRCDIR = $(dir $(MKFILE_PATH))

VPATH = $(SRCDIR)


TOPDIR := $(shell if [ "$$PWD" != "" ]; then echo $$PWD; else pwd; fi)

#
# Variables below overridable from command-line:
#   make VARNAME=value ...
#

#
# Where to install the package. GNU-EFI will create and access
# lib and include under the root
#
INSTALLROOT  := /
PREFIX       := /usr/local
LIBDIR 	     := $(PREFIX)/lib
INSTALL	     := install

# Compilation tools
HOSTCC       := $(prefix)gcc
CC           := $(prefix)$(CROSS_COMPILE)gcc
AS           := $(prefix)$(CROSS_COMPILE)as
LD           := $(prefix)$(CROSS_COMPILE)ld
AR           := $(prefix)$(CROSS_COMPILE)ar
RANLIB       := $(prefix)$(CROSS_COMPILE)ranlib
OBJCOPY      := $(prefix)$(CROSS_COMPILE)objcopy


# Host/target identification
OS           := $(shell uname -s)
HOSTARCH     ?= $(shell $(HOSTCC) -dumpmachine | cut -f1 -d- | sed -e s,i[3456789]86,ia32, -e 's,armv7.*,arm,' )
ARCH         ?= $(shell $(HOSTCC) -dumpmachine | cut -f1 -d- | sed -e s,i[3456789]86,ia32, -e 's,armv7.*,arm,' )

# Get ARCH from the compiler if cross compiling 
ifneq ($(CROSS_COMPILE),)
  override ARCH := $(shell $(CC) -dumpmachine | cut -f1 -d-| sed -e s,i[3456789]86,ia32, -e 's,armv7.*,arm,' )
endif

# FreeBSD (and possibly others) reports amd64 instead of x86_64
ifeq ($(ARCH),amd64)
  override ARCH := x86_64
endif

#
# Where to build the package
#
OBJDIR       := $(TOPDIR)/$(ARCH)

#
# Variables below derived from variables above
#

# Arch-specific compilation flags
CPPFLAGS += -DCONFIG_$(ARCH)

CFLAGS += -Wno-error=pragmas

ifeq ($(ARCH),ia64)
  CFLAGS += -mfixed-range=f32-f127
endif

ifeq ($(ARCH),ia32)
  CFLAGS += -mno-mmx -mno-sse
  ifeq ($(HOSTARCH),x86_64)
    ARCH3264 = -m32
  endif
endif

ifeq ($(ARCH),x86_64)
  GCCVERSION   := $(shell $(CC) -dumpversion | cut -f1 -d.)
  GCCMINOR     := $(shell $(CC) -dumpversion | cut -f2 -d.)
  USING_CLANG  := $(shell $(CC) -v 2>&1 | grep -q 'clang version' && echo clang)

  # Rely on GCC MS ABI support?
  GCCNEWENOUGH := $(shell ( [ $(GCCVERSION) -gt "4" ]           \
                            || ( [ $(GCCVERSION) -eq "4" ]      \
                                 && [ $(GCCMINOR) -ge "7" ] ) ) \
                          && echo 1)
  ifeq ($(GCCNEWENOUGH),1)
    CPPFLAGS += -DGNU_EFI_USE_MS_ABI -maccumulate-outgoing-args --std=c11
  else ifeq ($(USING_CLANG),clang)
    CPPFLAGS += -DGNU_EFI_USE_MS_ABI --std=c11
  endif

  CFLAGS += -mno-red-zone
  ifeq ($(HOSTARCH),ia32)
    ARCH3264 = -m64
  endif
endif

ifneq (,$(filter $(ARCH),ia32 x86_64))
  # Disable AVX, if the compiler supports that.
  CC_CAN_DISABLE_AVX=$(shell $(CC) -Werror -c -o /dev/null -xc -mno-avx - </dev/null >/dev/null 2>&1 && echo 1)
  ifeq ($(CC_CAN_DISABLE_AVX), 1)
    CFLAGS += -mno-avx
  endif
endif


#
# Set HAVE_EFI_OBJCOPY if objcopy understands --target efi-[app|bsdrv|rtdrv],
# otherwise we need to compose the PE/COFF header using the assembler
#
ifneq ($(ARCH),aarch64)
ifneq ($(ARCH),arm)
ifneq ($(ARCH),mips64el)
export HAVE_EFI_OBJCOPY=y
endif
endif
endif

ifneq ($(ARCH),arm)
export LIBGCC=$(shell $(CC) $(ARCH3264) -print-libgcc-file-name)
endif

ifeq ($(ARCH),arm)
CFLAGS += -marm
endif

# Generic compilation flags
INCDIR  += -I$(SRCDIR) -I$(TOPDIR)/inc -I$(TOPDIR)/inc/$(ARCH) \
           -I$(TOPDIR)/inc/protocol

# Only enable -fpic for non MinGW compilers (unneeded on MinGW)
GCCMACHINE := $(shell $(CC) -dumpmachine)
ifneq (mingw32,$(findstring mingw32, $(GCCMACHINE)))
  CFLAGS += -fpic
endif

ifeq (FreeBSD, $(findstring FreeBSD, $(OS)))
CFLAGS  += $(ARCH3264) -g -O2 -Wall -Wextra -Werror \
           -fshort-wchar -fno-strict-aliasing \
           -ffreestanding -fno-stack-protector
else
CFLAGS  += $(ARCH3264) -g -O2 -Wall -Wextra -Werror \
           -fshort-wchar -fno-strict-aliasing \
	   -ffreestanding -fno-stack-protector -fno-stack-check \
           -fno-stack-check \
           $(if $(findstring gcc,$(CC)),-fno-merge-all-constants,)
endif

ARFLAGS := rDv
ASFLAGS += $(ARCH3264)
LDFLAGS	+= -nostdlib --warn-common --no-undefined --fatal-warnings \
	   --build-id=sha1
SUBDIRS = lib gnuefi inc apps
gnuefi: lib

all:	check_gcc $(SUBDIRS)

mkvars:
	@echo AR=$(AR)
	@echo ARCH=$(ARCH)
	@echo ARCH3264=$(ARCH3264)
	@echo AS=$(AS)
	@echo ASFLAGS=$(ASFLAGS)
	@echo CC=$(CC)
	@echo CFLAGS=$(CFLAGS)
	@echo CPPFLAGS=$(CPPFLAGS)
	@echo GCCMINOR=$(GCCMINOR)
	@echo GCCNEWENOUGH=$(GCCNEWENOUGH)
	@echo GCCVERSION=$(GCCVERSION)
	@echo HOSTARCH=$(HOSTARCH)
	@echo INCDIR=$(INCDIR)
	@echo INSTALL=$(INSTALL)
	@echo INSTALLROOT=$(INSTALLROOT)
	@echo LD=$(LD)
	@echo LDFLAGS=$(LDFLAGS)
	@echo LIBDIR=$(LIBDIR)
	@echo OBJCOPY=$(OBJCOPY)
	@echo OS=$(OS)
	@echo prefix=$(prefix)
	@echo PREFIX=$(PREFIX)
	@echo RANLIB=$(RANLIB)
	@echo SRCDIR=$(SRCDIR)
	@echo TOPDIR=$(TOPDIR)

$(SUBDIRS):
	mkdir -p $(OBJDIR)/$@
	$(MAKE) -C $(OBJDIR)/$@ -f $(SRCDIR)/$@/Makefile SRCDIR=$(SRCDIR)/$@ ARCH=$(ARCH)

clean:
	rm -f *~
	@for d in $(SUBDIRS); do \
		if [ -d $(OBJDIR)/$$d ]; then \
			$(MAKE) -C $(OBJDIR)/$$d -f $(SRCDIR)/$$d/Makefile SRCDIR=$(SRCDIR)/$$d clean; \
		fi; \
	done

install:
	@for d in $(SUBDIRS); do \
		mkdir -p $(OBJDIR)/$$d; \
		$(MAKE) -C $(OBJDIR)/$$d -f $(SRCDIR)/$$d/Makefile SRCDIR=$(SRCDIR)/$$d install; done

.PHONY:	$(SUBDIRS) clean depend

#
# on both platforms you must use gcc 3.0 or higher 
#
check_gcc:
ifeq ($(GCC_VERSION),2)
	@echo "you need to use a version of gcc >= 3.0, you are using `$(CC) --version`"
	@exit 1
endif


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

