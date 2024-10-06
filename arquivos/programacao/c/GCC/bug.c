extern int printf(char *, ...);
#include<string.h>

void risky_programming (char *input) {
   char str[10+1];     // one more for the null character
   
   strcpy(str, input);   // copy input
   printf("\n%s\n", str);
   return;
}

void secure_programming (char *input) {
   char str[10];
   
   strncpy (str, input, sizeof(str)); // copy input without exceeding the length of the destination
   str[sizeof(str) - 1] = '\0';  // if strlen(input) == sizeof(str) then strncpy won't NUL terminate
   printf("\n%s\n", str);
   return;
}

int main () {
   char teste[] = "só isso me";
   
   secure_programming(teste);
   risky_programming(teste);
   return 0;
}

/*
Code injection

shell injection
allow software to programmatically execute a command line.
Typical shell injection-related functions include system(), StartProcess(), java.lang.Runtime.exec(), and System.Diagnostics.Process.Start().

Data Execution Prevention (DEP) is a security feature included in modern operating systems. It is known to be available in Linux, Mac OS X, iOS, Microsoft Windows and Android operating systems and is intended to prevent an application or service from executing code from a non-executable memory region. This helps prevent certain exploits that store code via a buffer overflow, for example.

Some CPUs support a feature called NX ("No eXecute") or XD ("eXecute Disabled") bit, which in conjunction with software, can be used to mark pages of data (such as those containing the stack and the heap) as readable and writeable but not executable.
*/

