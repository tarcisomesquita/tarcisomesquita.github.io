
/*
.po files means Portable Object
.mo files means Machine Object
.pot are kind of base translation files found in distributions

PO files are meant to be read and edited by humans, and associate each original, translatable string of a given package with its translation in a particular target language.
A single PO file is dedicated to a single target language.

PO files are best created by the xgettext program

PO file format:

white-space
#  translator-comments
#. automatic-comments
#: reference...
#, flag...
msgid untranslated-string
msgstr translated-string

Substitua os valores padrão do cabeçalho do arquivo .pot
Content-Type
    Replace `CHARSET' with the character encoding used for your language, in your locale, or UTF-8.

 /usr/local/share/locale/pt_BR/LC_MESSAGES/gettext.mo

O arquivo .mo é colocado dentro de:
/usr/share/locale-langpack/pt_BR/LC_MESSAGES

sudo apt-get install gettext

touch po/nome_executable.pot
xgettext -d nome_executable -s -o po/nome_executable.pot src/main.c

msginit -o po/es.po -i po/nome_executable.pot

Noutro "locale" (idioma) distinto ao do noso sistema
msginit -l gl -o gl.po -i nome_executable.pot


Creando (compilando) o ficheiro binario ".mo" que lerá o executable
msgfmt -c -v -o po/nome_executable.mo po/es.po


Coloque todas as strings em português dentro das macros do gettext, crie
> o pot, crie um en.po, traduza e compile a tradução. Na carga do programa
> ele vai ver que o locale é "en" ou "en_US", e vai chamar a tradução para
> o inglês.


Exemplo:
Veio junto com o código fonte de gettxt

file po/gettxt.pot

# SOME DESCRIPTIVE TITLE.
# Copyright (C) YEAR Free Software Foundation, Inc.
# FIRST AUTHOR <EMAIL@ADDRESS>, YEAR.
#
#, fuzzy
msgid ""
msgstr ""
"Project-Id-Version: PACKAGE VERSION\n"
"POT-Creation-Date: 2001-05-23 23:03+0200\n"
"PO-Revision-Date: YEAR-MO-DA HO:MI+ZONE\n"
"Last-Translator: FULL NAME <EMAIL@ADDRESS>\n"
"Language-Team: LANGUAGE <LL@li.org>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=CHARSET\n"
"Content-Transfer-Encoding: 8-bit\n"

#: lib/error.c:115
msgid "Unknown system error"
msgstr ""

#: lib/getopt.c:691
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr ""

#: lib/getopt.c:716
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr ""

#: lib/getopt.c:721
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr ""



file po/pt_BR.po
# Brazilian Portuguese translation of the "gettext" messages
# Copyright (C) 2001 Free Software Foundation, Inc.
# Sandro Nunes Henrique <sandro@conectiva.com.br>, 1998
# Rodrigo Stulzer Lopes <rodrigo@conectiva.com.br>, 2000
# Flávio Bruno Leitner <flavio@conectiva.com.br>, 2001.
#
msgid ""
msgstr ""
"Project-Id-Version: GNU gettext 0.10.36\n"
"POT-Creation-Date: 2001-05-23 23:03+0200\n"
"PO-Revision-Date: 2001-04-03 08:25+02:00\n"
"Last-Translator: Flávio Bruno Leitner <flavio@conectiva.com.br>\n"
"Language-Team: Brazilian Portuguese <ldp-br@bazar.conectiva.com.br>\n"
"MIME-Version: 1.0\n"
"Content-Type: text/plain; charset=ISO-8859-1\n"
"Content-Transfer-Encoding: 8bit\n"

#: lib/error.c:115
msgid "Unknown system error"
msgstr "Erro de sistema desconhecido"

#: lib/getopt.c:691
#, c-format
msgid "%s: option `%s' is ambiguous\n"
msgstr "%s: opção `%s' é ambígua\n"

#: lib/getopt.c:716
#, c-format
msgid "%s: option `--%s' doesn't allow an argument\n"
msgstr "%s: opção `--%s' não aceita parâmetros\n"

#: lib/getopt.c:721
#, c-format
msgid "%s: option `%c%s' doesn't allow an argument\n"
msgstr "%s: opção `%c%s' não aceita parâmetros\n"

*/

/* Variáveis globais */

const char *program_name;



/* Funções da biblioteca padrão */

int printf(char *, ...);



/* Funções externas */

//#include<libintl.h> //  = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =
extern char *gettext(const char *);
#define N_(msgid) msgid
#define _(msgid) gettext(msgid)


int main(int argc, char **argv)
{
   // PACKAGE and LOCALEDIR should be provided either by `config.h
   setlocale (LC_ALL, "");              // Set locale via LC_ALL.
   
   bindtextdomain (PACKAGE, LOCALEDIR); // Set the text message domain.
   textdomain (PACKAGE);

   program_name = argv[0];
   printf (gettext ("Usage: %s [SHORT-OPTION]... [STRING]...\n  or:  %s LONG-OPTION\n"), program_name, program_name);
   printf (gettext ("Teste\n"));
   return 0;
}

/*

*/
