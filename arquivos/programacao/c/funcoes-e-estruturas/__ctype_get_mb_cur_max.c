
/* Maximum length of a multibyte character in the current locale.  */


typedef unsigned int size_t;


//#include<stdlib.h> // = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
#define	MB_CUR_MAX	(__ctype_get_mb_cur_max ())
extern size_t __ctype_get_mb_cur_max(void);

//#include<stdio.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(const char *, ...);


int main()
{
   printf("%u\n",__ctype_get_mb_cur_max());
   return 0;
}

