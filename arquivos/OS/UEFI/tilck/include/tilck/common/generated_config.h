/* SPDX-License-Identifier: BSD-2-Clause */

/*
 * This is a TEMPLATE. The actual "generated_config.h" is generated by CMake
 * and put in <BUILD_DIR>/tilck_gen_headers/config.h.
 */


#pragma once

#define VER_MAJOR              @tilck_VERSION_MAJOR@
#define VER_MINOR              @tilck_VERSION_MINOR@
#define VER_PATCH              @tilck_VERSION_PATCH@

#define VER_MAJOR_STR          "@tilck_VERSION_MAJOR@"
#define VER_MINOR_STR          "@tilck_VERSION_MINOR@"
#define VER_PATCH_STR          "@tilck_VERSION_PATCH@"

#define ARCH_GCC_TC            "@ARCH_GCC_TC@"
#define PROJ_BUILD_DIR         "@CMAKE_BINARY_DIR@"
#define BUILDTYPE_STR          "@CMAKE_BUILD_TYPE@"

#define BL_ST2_DATA_SEG        (@BL_ST2_DATA_SEG@)
#define BL_BASE_ADDR           (@BL_BASE_ADDR@)
#define KERNEL_BASE_VA         (@KERNEL_BASE_VA@)
#define KERNEL_PADDR           (@KERNEL_PADDR@)
#define LINEAR_MAPPING_MB      (@LINEAR_MAPPING_MB@)
#define USER_STACK_PAGES       (@USER_STACK_PAGES@)

#define DEVSHELL_PATH          "@TILCK_DEVSHELL_PATH@"
#define KERNEL_FILE_PATH       "/@KERNEL_FATPART_PATH@"
#define KERNEL_FILE_PATH_EFI   "\\@KERNEL_FATPART_PATH_EFI@"

#define TIMER_HZ               (@TIMER_HZ@)
#define TTY_COUNT              (@TTY_COUNT@)

/* enabled by default */
#cmakedefine01 KRN_TRACK_NESTED_INTERR
#cmakedefine01 PANIC_SHOW_STACKTRACE
#cmakedefine01 DEBUG_CHECKS_IN_RELEASE
#cmakedefine01 KERNEL_SELFTESTS
#cmakedefine01 KERNEL_STACK_ISOLATION
#cmakedefine01 KERNEL_SYMBOLS

/* disabled by default */
#cmakedefine01 KERNEL_GCOV
#cmakedefine01 FORK_NO_COW
#cmakedefine01 MMAP_NO_COW
#cmakedefine01 PANIC_SHOW_REGS
#cmakedefine01 KMALLOC_HEAVY_STATS
#cmakedefine01 KMALLOC_FREE_MEM_POISONING
#cmakedefine01 KMALLOC_SUPPORT_DEBUG_LOG
#cmakedefine01 KMALLOC_SUPPORT_LEAK_DETECTOR
#cmakedefine01 BOOTLOADER_POISON_MEMORY
#cmakedefine01 FAT_TEST_DIR
#cmakedefine01 KERNEL_DO_PS2_SELFTEST
#cmakedefine01 KERNEL_BIG_IO_BUF

#if DEBUG_CHECKS_IN_RELEASE
   #ifdef NDEBUG
      #undef NDEBUG
      #define DEBUG
   #endif
#endif