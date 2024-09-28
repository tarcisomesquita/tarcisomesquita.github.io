 
// #include<bin/locale.h>  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
enum
{
  __LC_CTYPE = 0,
  __LC_NUMERIC = 1,
  __LC_TIME = 2,
  __LC_COLLATE = 3,
  __LC_MONETARY = 4,
  __LC_MESSAGES = 5,
  __LC_ALL = 6,
  __LC_PAPER = 7,
  __LC_NAME = 8,
  __LC_ADDRESS = 9,
  __LC_TELEPHONE = 10,
  __LC_MEASUREMENT = 11,
  __LC_IDENTIFICATION = 12
}; 


// #include<locale.h>  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

/* These are the possibilities for the first argument to setlocale.
   The code assumes that the lowest LC_* symbol has the value zero.  */
#define LC_CTYPE          __LC_CTYPE
#define LC_NUMERIC        __LC_NUMERIC
#define LC_TIME           __LC_TIME
#define LC_COLLATE        __LC_COLLATE
#define LC_MONETARY       __LC_MONETARY
#define LC_MESSAGES       __LC_MESSAGES
#define	LC_ALL		  __LC_ALL
#define LC_PAPER	  __LC_PAPER
#define LC_NAME		  __LC_NAME
#define LC_ADDRESS	  __LC_ADDRESS
#define LC_TELEPHONE	  __LC_TELEPHONE
#define LC_MEASUREMENT	  __LC_MEASUREMENT
#define LC_IDENTIFICATION __LC_IDENTIFICATION

/* Set and/or return the current locale.  */
extern char *setlocale(int category, const char *locale);


//#include<stdio.h> = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
int printf(char *, ...); 


int main(int argc, char **argv)
{
   printf("%s\n", setlocale(LC_ALL, ""));
   return 0;
}

/*

If locale is not NULL, the program’s current locale is modified according  to the arguments.


category
determines which parts of the current locale should be modified.

        LC_ALL for all of the locale.
 
        LC_COLLATE
               for regular expression matching (it determines  the  meaning  of
               range expressions and equivalence classes) and string collation.
 
        LC_CTYPE
               for regular expression matching, character classification,  con‐
               version,  case-sensitive  comparison,  and  wide character func‐
               tions.
 
        LC_MESSAGES
               for localizable natural-language messages.
 
        LC_MONETARY
               for monetary formatting.
 
        LC_NUMERIC
               for number formatting (such as the decimal point and  the  thou‐
               sands separator).
 
        LC_TIME
               for time and date formatting.

 
locale
contain the required setting of category like "C" or "da_DK".

        "", each part of the locale that should be modified
 
        NULL, the current locale is only queried, not modified.
 
        On  startup of the main program, the portable "C" locale is selected as
        default.  A program may be made portable to all locales by calling:
 
            setlocale(LC_ALL, "");
 

        A successful call to setlocale() returns an string  that  corre‐
        sponds to the locale set.
        The return value is NULL if the request cannot be  hon‐
        ored.
 

O programa locale procura dados nas seguintes variáveis LC_ALL, LC_COLLATE, LC_CTYPE,  LC_MESSAGES, LC_MONETARY, LC_NUMERIC, LC_TIME, LANG. Se não encontrar em nenhuma, ela returns NULL.


A  locale  name  is  typically  of the form language[_territory][.codeset][@modifier]
language is an ISO 639 language code
territory is an ISO 3166 country code
codeset is a character set or encoding identifier like ISO-8859-1 or UTF-8.

For  a  list  of  all  supported locales, try "locale -a".

bn_BD
bn_IN
C
de_AT.utf8
de_BE.utf8
de_CH.utf8
de_DE.utf8
de_LI.utf8
de_LU.utf8
en_AU.utf8
en_BW.utf8
en_CA.utf8
en_DK.utf8
en_GB.utf8
en_HK.utf8
en_IE.utf8
en_IN
en_NG
en_NZ.utf8
en_PH.utf8
en_SG.utf8
en_US.utf8
en_ZA.utf8
en_ZW.utf8
es_AR.utf8
es_BO.utf8
es_CL.utf8
es_CO.utf8
es_CR.utf8
es_DO.utf8
es_EC.utf8
es_ES.utf8
es_GT.utf8
es_HN.utf8
es_MX.utf8
es_NI.utf8
es_PA.utf8
es_PE.utf8
es_PR.utf8
es_PY.utf8
es_SV.utf8
es_US.utf8
es_UY.utf8
es_VE.utf8
fr_BE.utf8
fr_CA.utf8
fr_CH.utf8
fr_FR.utf8
fr_LU.utf8
POSIX
pt_BR.utf8
pt_PT.utf8
xh_ZA.utf8
*/

