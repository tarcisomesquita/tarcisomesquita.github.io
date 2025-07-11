# SPDX-License-Identifier: BSD-2-Clause
cmake_minimum_required(VERSION 3.2)

set(EARLY_BOOT_SCRIPT ${CMAKE_BINARY_DIR}/boot/legacy/early_boot_script.ld)
set(STAGE3_SCRIPT ${CMAKE_BINARY_DIR}/boot/legacy/stage3/linker_script.ld)
set(KERNEL_SCRIPT ${CMAKE_BINARY_DIR}/kernel/arch/${ARCH}/linker_script.ld)
set(MUSL_GCC ${CMAKE_BINARY_DIR}/scripts/musl-gcc)
set(MUSL_GXX ${CMAKE_BINARY_DIR}/scripts/musl-g++)

hex2dec(${BL_ST2_DATA_SEG} BL_ST2_DATA_SEG_DEC)

math(EXPR BL_BASE_ADDR_DEC
      "${BL_ST2_DATA_SEG_DEC} * 16 + ${EARLY_BOOT_SZ} + ${STAGE3_ENTRY_OFF}")

dec2hex(${BL_BASE_ADDR_DEC} BL_BASE_ADDR)

configure_file(
   ${CMAKE_SOURCE_DIR}/include/tilck/common/generated_config.h
   ${CMAKE_BINARY_DIR}/tilck_gen_headers/config.h
)

configure_file(
   ${CMAKE_SOURCE_DIR}/include/tilck/kernel/config_modules.h
   ${CMAKE_BINARY_DIR}/tilck_gen_headers/config_modules.h
)

configure_file(
   ${CMAKE_SOURCE_DIR}/boot/legacy/early_boot_script.ld
   ${EARLY_BOOT_SCRIPT}
   @ONLY
)

configure_file(
   ${CMAKE_SOURCE_DIR}/kernel/arch/${ARCH}/linker_script.ld
   ${KERNEL_SCRIPT}
   @ONLY
)

configure_file(
   ${CMAKE_SOURCE_DIR}/other/musl-gcc
   ${MUSL_GCC}
   @ONLY
)

configure_file(
   ${CMAKE_SOURCE_DIR}/other/musl-g++
   ${MUSL_GXX}
   @ONLY
)

configure_file(
   ${CMAKE_SOURCE_DIR}/tests/system/runners/single_test_run
   ${CMAKE_BINARY_DIR}/st/single_test_run
   @ONLY
)

configure_file(
   ${CMAKE_SOURCE_DIR}/tests/system/runners/run_all_tests
   ${CMAKE_BINARY_DIR}/st/run_all_tests
   @ONLY
)

configure_file(
   ${CMAKE_SOURCE_DIR}/tests/system/runners/utils.py
   ${CMAKE_BINARY_DIR}/st/utils.py
   @ONLY
)

configure_file(
   ${CMAKE_SOURCE_DIR}/other/cmake/config_fatpart
   ${CMAKE_BINARY_DIR}/config_fatpart
)

# Run qemu scripts

list(
   APPEND run_qemu_files

   run_nokvm_qemu
   run_qemu
   run_nokvm_qemu_with_usbdisk
   run_multiboot_nokvm_qemu
   run_multiboot_qemu
   run_efi_nokvm_qemu32
   run_efi_qemu32
   run_efi_nokvm_qemu64
   run_efi_qemu64
   debug_run_qemu
)

foreach(script_file ${run_qemu_files})
   configure_file(
      ${CMAKE_SOURCE_DIR}/scripts/templates/qemu/${script_file}
      ${CMAKE_BINARY_DIR}/${script_file}
      @ONLY
   )
endforeach()

include_directories(${CMAKE_BINARY_DIR})
