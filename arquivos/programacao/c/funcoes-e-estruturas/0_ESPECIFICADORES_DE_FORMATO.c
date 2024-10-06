
/*

The format tags follow this prototype:

%[flags][width][.precision][length]specifier

Where specifier is the most significant one and defines the type and the interpretation of the value of the coresponding argument:
specifier  Output                                                            Example
c          Character                                                         a
d or i     Signed decimal integer                                            392
e          Scientific notation (mantise/exponent) using e character          3.9265e+2
E          Scientific notation (mantise/exponent) using E character          3.9265E+2
f          Decimal floating point                                            392.65
g          Use the shorter of %e or %f                                       392.65
G          Use the shorter of %E or %f                                       392.65
o          Signed octal                                                      610
s          String of characters                                              sample
u          Unsigned decimal integer                                          7235
x          Unsigned hexadecimal integer                                      7fa
X          Unsigned hexadecimal integer (capital letters)                    7FA
p          Pointer address                                                   B800:0000
n          Nothing printed. The argument must be a pointer to a signed int,  
        where the number of characters written so far is stored.             
%          A % followed by another % character will write % to the stream.   %



length     description
h          The argument is interpreted as a short int or unsigned short int (only applies to integer specifiers: i, d, o, u, x and X).
l          The argument is interpreted as a long int or unsigned long int for integer specifiers (i, d, o, u, x and X), and 
            as a wide character or wide character string for specifiers c and s.
L          The argument is interpreted as a long double (only applies to floating point specifiers: e, E, f, g and G).



.precision    description
.number       For integer specifiers (d, i, o, u, x, X):
                 precision specifies the minimum number of digits to be written. If the value to be written is shorter 
                 than this number, the result is padded with leading zeros. The value is not truncated even if the result
                 is longer. A precision of 0 means that no character is written for the value 0.
              For e, E and f specifiers:
                 this is the number of digits to be printed after de decimal point.
              For g and G specifiers:
                 This is the maximum number of significant digits to be printed.
              For s:
                 this is the maximum number of characters to be printed.
                 By default all characters are printed until the ending null character is encountered.
              For c type:
                 it has no effect.
              When no precision is specified, the default is 1.
                 If the period is specified without an explicit value for precision, 0 is assumed.
.*            The precision is not specified in the format string, but as an additional integer value argument
               preceding the argument that has to be formatted.



width       description
(number)    Minimum number of characters to be printed. If the value to be printed is shorter than this number, 
             the result is padded with blank spaces. The value is not truncated even if the result is larger.
*           The width is not specified in the format string, but as an additional integer value argument 
             preceding the argument that has to be formatted.




flags     description
-         Left-justify within the given field width; Right justification is the default (see width sub-specifier).
+         Forces to preceed the result with a plus or minus sign (+ or -) even for positive numbers. 
           By default, only negative numbers are preceded with a - sign.
(space)   If no sign is going to be written, a blank space is inserted before the value.
#         Used with o, x or X specifiers the value is preceeded with 0, 0x or 0X respectively for values different than zero.
          Used with e, E and f, it forces the written output to contain a decimal point even if no digits would follow.
           By default, if no digits follow, no decimal point is written.
          Used with g or G the result is the same as with e or E but trailing zeros are not removed.
0         Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier).

*/

//#include<stdio.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern int printf(char *, ...);


int main(void)
{
   char val_c = 'A';
   int val_i = 100;
   double val_d = 50.5;
   char frase[]="COMPUTACAO";

   printf("[%c] [%c] [%d]\n",val_c, val_c+1 ,val_c);
   printf("[%d] [%5d] [%-5d] [%05d]\n",val_i, val_i, val_i, val_i);
   printf("[%5.2f]\n",val_d);
   printf("[%15s]\n", frase);
   printf("[%-15s]\n", frase);
   printf("[%3.4s]\n", frase);
   printf("[%15.3s]\n", frase);
   printf("[%-15.3s]\n", frase);
}


/*
Caracteres de Escape

Os caracteres de escape são usados para representar alguns caracteres que, ou não estão disponíveis diretamente no teclado do computador ou em determinadas situação não podem ser inseridos diretamente dentro de um programa fonte C.

Caracter   Descrição
'\a' 	   Campainha ou Bell   // não funciona na minha máquina
'\b' 	   Retrocesso ou Backspace
'\n        Alimentação de Linha : LF (Dos/Windows = CR+LF)
'\r' 	   Retorno do Carro
'\t' 	   Tabulação Horizontal (TAB)
'\'' 	   Aspa Simples
'\"' 	   Aspa Dupla
'\\' 	   Contrabarra
'\0' 	   Caracter Nulo (ASCII 0)

#define BOLD "\033[1m"
#define NORMAL "\033[0m"
printf("%s", BOLD);
printf("\nIsso é um teste\n");
printf("%s", NORMAL);
Veja sequencias de escape em linguas/bash
*/

