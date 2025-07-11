# To call C library functions assemble your assembly code with the gcc command. The gcc command will assemble your assembly code and automatically link it with the C startup code. Startup code initializes the global variables used by C library functions, and then calls the main function expected to be in every C program. In our case, this main function will be written in assembly language.

# gcc 3_hello-libc.s -o hello-libc.elf && ./hello-libc.elf
               .intel_syntax noprefix
               .text
Message:       .asciz "Hello World LIBC!"
               .global main
main:
               push OFFSET FLAT:Message
               call puts
               add  esp, 4
               
               push DWORD PTR n       # push second argument, n
               push OFFSET FLAT:fmt   # push first argument, address of fmt
               call printf            # call printf("%d\n", eax)
               add  esp, 8            # pop 2 arguments
               
               ret

      .data
n:    .long   5        # number
fmt:  .asciz  "%d\n"   # format for printf

