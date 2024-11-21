
extern int fputs_unlocked (const char *__restrict __s, FILE *__restrict __stream);

gettext é uma biblioteca do Projeto GNU que faz a internacionalização de softwares, ou seja, a escrita de multiplas línguas em softwares

Para a tradução da string é necessário junto ao programa um arquivo com extensão .po
Dentro do arquivo .po de um programa escrito em C é necessário conter:

#: src/name.c:36
msgid "My name is %s.\n"
msgstr "Meu nome é %s.\n."



