// clear ; gcc -Wall -static isdigit.c -o isdigit.elf && strace ./isdigit.elf 38

// #include<ctype.h>
extern const unsigned short int **__ctype_b_loc(void);
enum {
   _ISupper  = ((0) < 8 ? ((1 << (0)) << 8) : ((1 << (0)) >> 8)),    // UPPERCASE.
   _ISlower  = ((1) < 8 ? ((1 << (1)) << 8) : ((1 << (1)) >> 8)),    // lowercase.
   _ISalpha  = ((2) < 8 ? ((1 << (2)) << 8) : ((1 << (2)) >> 8)),    // Alphabetic.
   _ISdigit  = ((3) < 8 ? ((1 << (3)) << 8) : ((1 << (3)) >> 8)),    // Numeric.
   _ISxdigit = ((4) < 8 ? ((1 << (4)) << 8) : ((1 << (4)) >> 8)),    // Hexadecimal numeric.
   _ISspace  = ((5) < 8 ? ((1 << (5)) << 8) : ((1 << (5)) >> 8)),    // Whitespace.
   _ISprint  = ((6) < 8 ? ((1 << (6)) << 8) : ((1 << (6)) >> 8)),    // Printing.
   _ISgraph  = ((7) < 8 ? ((1 << (7)) << 8) : ((1 << (7)) >> 8)),    // Graphical.
   _ISblank  = ((8) < 8 ? ((1 << (8)) << 8) : ((1 << (8)) >> 8)),    // Blank (usually SPC and TAB).
   _IScntrl  = ((9) < 8 ? ((1 << (9)) << 8) : ((1 << (9)) >> 8)),    // Control character.
   _ISpunct  = ((10) < 8 ? ((1 << (10)) << 8) : ((1 << (10)) >> 8)), // Punctuation.
   _ISalnum  = ((11) < 8 ? ((1 << (11)) << 8) : ((1 << (11)) >> 8))  // Alphanumeric.
};
# define isdigit(c)   ((*__ctype_b_loc())[(int)(c)] & (unsigned short int)_ISdigit)

extern int printf(char *, ...);
extern int atoi(const char *);

int main(int argc, char **argv) {
   if (argc != 2) return 1;
   
   if (isdigit(argv[1][0])) printf("\n%d\n\n", atoi(argv[1]));
   
   return 0;
}

