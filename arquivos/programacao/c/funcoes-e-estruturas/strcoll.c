
// gcc -Wall strcoll.c -o strcoll.elf && ./strcoll.elf

// Compare the collated forms of S1 and S2.
// retorna -1 s1[n] <= s2[n]
// retorna  0 s1[n] == s2[n]
// retorna  1 s1[n] >= s2[n]


//#include<string.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = 
extern int strcoll (const char *s1, const char *s2);

//#include<stdio.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = 
extern int printf(const char *, ...);

int main() {
   char s1[] = "123";
   char s2[] = "123";
   
   printf("\nretornou: %d\n\n", strcoll(s1,s2));
   
   return 0;
}

