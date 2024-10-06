/*
0804833f <main>:
 804833f:	8d 4c 24 04          	lea    ecx,[esp+0x4]
 8048352:	89 4d dc             	mov    DWORD PTR [ebp-0x24],ecx

 8048479:	8b 55 dc             	mov    edx,DWORD PTR [ebp-0x24]
 804847c:	03 42 04             	add    eax,DWORD PTR [edx+0x4]
 804847f:	8b 00                	mov    eax,DWORD PTR [eax]
 8048481:	89 04 24             	mov    DWORD PTR [esp],eax
 8048484:	e8 17 e8 01 00       	call   8066ca0 <chroot>

08066ca0 <chroot>:
 8066ca0:	89 da                	mov    edx,ebx
 8066ca2:	8b 5c 24 04          	mov    ebx,DWORD PTR [esp+0x4]
 8066ca6:	b8 3d 00 00 00       	mov    eax,0x3d
 8066cab:	cd 80                	int    0x80


 chroot -- run command or shell with special root directory
   Copyright (C) 95, 96, 1997, 1999-2004, 2007 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* Written by Roland McGrath.  */

#include <config.h>
#include <getopt.h>
#include <stdio.h>
#include <sys/types.h>

#include "system.h"
#include "error.h"
#include "long-options.h"
#include "quote.h"

/* The official name of this program (e.g., no `g' prefix).  */
#define PROGRAM_NAME "chroot"

#define AUTHORS "Roland McGrath"

/* The name this program was run with, for error messages. */
char *program_name;

void
usage (int status)
{
  if (status != EXIT_SUCCESS)
    fprintf (stderr, _("Try `%s --help' for more information.\n"),
	     program_name);
  else
    {
      printf (_("\
Usage: %s NEWROOT [COMMAND...]\n\
  or:  %s OPTION\n\
"), program_name, program_name);
      fputs (_("\
Run COMMAND with root directory set to NEWROOT.\n\
\n\
"), stdout);
      fputs (HELP_OPTION_DESCRIPTION, stdout);
      fputs (VERSION_OPTION_DESCRIPTION, stdout);
      fputs (_("\
\n\
If no command is given, run ``${SHELL} -i'' (default: /bin/sh).\n\
"), stdout);
      emit_bug_reporting_address ();
    }
  exit (status);
}

int
main (int argc, char **argv)
{
  initialize_main (&argc, &argv);
  program_name = argv[0];
  setlocale (LC_ALL, "");
  bindtextdomain (PACKAGE, LOCALEDIR);
  textdomain (PACKAGE);

  initialize_exit_failure (EXIT_FAILURE);
  atexit (close_stdout);

  parse_long_options (argc, argv, PROGRAM_NAME, PACKAGE_NAME, VERSION,
		      usage, AUTHORS, (char const *) NULL);
  if (getopt_long (argc, argv, "+", NULL, NULL) != -1)
    usage (EXIT_FAILURE);

  if (argc <= optind)
    {
      error (0, 0, _("missing operand"));
      usage (EXIT_FAILURE);
    }

  if (chroot (argv[optind]) != 0)
    error (EXIT_FAILURE, errno, _("cannot change root directory to %s"), argv[1]);

  if (chdir ("/"))
    error (EXIT_FAILURE, errno, _("cannot chdir to root directory"));

  if (argc == optind + 1)
    {
      /* No command.  Run an interactive shell.  */
      char *shell = getenv ("SHELL");
      if (shell == NULL)
	shell = "/bin/sh";
      argv[0] = shell;
      argv[1] = "-i";
      argv[2] = NULL;
    }
  else
    {
      /* The following arguments give the command.  */
      argv += optind + 1;
    }

  /* Execute the given command.  */
  execvp (argv[0], argv);

  {
    int exit_status = (errno == ENOENT ? EXIT_ENOENT : EXIT_CANNOT_INVOKE);
    error (0, errno, _("cannot run command %s"), quote (argv[0]));
    exit (exit_status);
  }
}
