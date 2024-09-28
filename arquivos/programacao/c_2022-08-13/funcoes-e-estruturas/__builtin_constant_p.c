
// não sei como isso funciona

extern int printf(char *, ...);

char fora[] = "FORA";

int main() {
   char var[] = "VAR";
   
   if( __builtin_constant_p (var))     printf("VAR\n" );
   if( __builtin_constant_p (fora))    printf("FORA\n" );
   if( __builtin_constant_p ("TESTE")) printf("TESTE\n" );
   
   return 0;
}

