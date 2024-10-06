extern int printf(char *, ...);

// __rawmemchr (optstring, c) : __builtin_strchr (optstring, c)));

      -fno-builtin
       -fno-builtin-function
           Donât recognize built-in functions that do not begin with
           __builtin_ as prefix.

           GCC normally generates special code to handle certain built-in
           functions more efficiently; for instance, calls to "alloca" may
           become single instructions that adjust the stack directly, and
           calls to "memcpy" may become inline copy loops.  The resulting code
           is often both smaller and faster, but since the function calls no
           longer appear as such, you cannot set a breakpoint on those calls,
           nor can you change the behavior of the functions by linking with a
           different library.  In addition, when a function is recognized as a
           built-in function, GCC may use information about that function to
           warn about problems with calls to that function, or to generate
           more efficient code, even if the resulting code still contains
           calls to that function.  For example, warnings are given with
           -Wformat for bad calls to "printf", when "printf" is built in, and
           "strlen" is known not to modify global memory.

           With the -fno-builtin-function option only the built-in function
           function is disabled.  function must not begin with __builtin_.  If
           a function is named this is not built-in in this version of GCC,
           this option is ignored.  There is no corresponding
           -fbuiltin-function option; if you wish to enable built-in functions
           selectively when using -fno-builtin or -ffreestanding, you may
           define macros such as:

                   #define abs(n)          __builtin_abs ((n))
                   #define strcpy(d, s)    __builtin_strcpy ((d), (s))

int main() {
   char var[] = "VAR";
   
   if( __builtin_constant_p (var))     printf("VAR\n" );
   if( __builtin_constant_p (fora))    printf("FORA\n" );
   if( __builtin_constant_p ("TESTE")) printf("TESTE\n" );
   
   return 0;
}

