
— Variable: getdate_err

    This variable of type int contains the error code of the last unsuccessful call to getdate. Defined values are:

    1
        The environment variable DATEMSK is not defined or null.
    2
        The template file denoted by the DATEMSK environment variable cannot be opened.
    3
        Information about the template file cannot retrieved.
    4
        The template file is not a regular file.
    5
        An I/O error occurred while reading the template file.
    6
        Not enough memory available to execute the function.
    7
        The template file contains no matching template.
    8
        The input date is invalid, but would match a template otherwise. This includes dates like February 31st, and dates which cannot be represented in a time_t variable. 

— Function: struct tm * getdate (const char *string)

    The interface to getdate is the simplest possible for a function to parse a string and return the value. string is the input string and the result is returned in a statically-allocated variable.

    The details about how the string is processed are hidden from the user. In fact, they can be outside the control of the program. Which formats are recognized is controlled by the file named by the environment variable DATEMSK. This file should contain lines of valid format strings which could be passed to strptime.

    The getdate function reads these format strings one after the other and tries to match the input string. The first line which completely matches the input string is used.

    Elements not initialized through the format string retain the values present at the time of the getdate function call.

    The formats recognized by getdate are the same as for strptime. See above for an explanation. There are only a few extensions to the strptime behavior:

        * If the %Z format is given the broken-down time is based on the current time of the timezone matched, not of the current timezone of the runtime environment.

          Note: This is not implemented (currently). The problem is that timezone names are not unique. If a fixed timezone is assumed for a given string (say EST meaning US East Coast time), then uses for countries other than the USA will fail. So far we have found no good solution to this.
        * If only the weekday is specified the selected day depends on the current date. If the current weekday is greater or equal to the tm_wday value the current week's day is chosen, otherwise the day next week is chosen.
        * A similar heuristic is used when only the month is given and not the year. If the month is greater than or equal to the current month, then the current year is used. Otherwise it wraps to next year. The first day of the month is assumed if one is not explicitly specified.
        * The current hour, minute, and second are used if the appropriate value is not set through the format.
        * If no date is given tomorrow's date is used if the time is smaller than the current time. Otherwise today's date is taken. 

    It should be noted that the format in the template file need not only contain format elements. The following is a list of possible format strings (taken from the Unix standard):

              %m
              %A %B %d, %Y %H:%M:%S
              %A
              %B
              %m/%d/%y %I %p
              %d,%m,%Y %H:%M
              at %A the %dst of %B in %Y
              run job at %I %p,%B %dnd
              %A den %d. %B %Y %H.%M Uhr

    As you can see, the template list can contain very specific strings like run job at %I %p,%B %dnd. Using the above list of templates and assuming the current time is Mon Sep 22 12:19:47 EDT 1986 we can obtain the following results for the given input.

    Input 	Match 	Result
    Mon 	%a 	Mon Sep 22 12:19:47 EDT 1986
    Sun 	%a 	Sun Sep 28 12:19:47 EDT 1986
    Fri 	%a 	Fri Sep 26 12:19:47 EDT 1986
    September 	%B 	Mon Sep 1 12:19:47 EDT 1986
    January 	%B 	Thu Jan 1 12:19:47 EST 1987
    December 	%B 	Mon Dec 1 12:19:47 EST 1986
    Sep Mon 	%b %a 	Mon Sep 1 12:19:47 EDT 1986
    Jan Fri 	%b %a 	Fri Jan 2 12:19:47 EST 1987
    Dec Mon 	%b %a 	Mon Dec 1 12:19:47 EST 1986
    Jan Wed 1989 	%b %a %Y 	Wed Jan 4 12:19:47 EST 1989
    Fri 9 	%a %H 	Fri Sep 26 09:00:00 EDT 1986
    Feb 10:30 	%b %H:%S 	Sun Feb 1 10:00:30 EST 1987
    10:30 	%H:%M 	Tue Sep 23 10:30:00 EDT 1986
    13:30 	%H:%M 	Mon Sep 22 13:30:00 EDT 1986

    The return value of the function is a pointer to a static variable of type struct tm, or a null pointer if an error occurred. The result is only valid until the next getdate call, making this function unusable in multi-threaded applications.

    The errno variable is not changed. Error conditions are stored in the global variable getdate_err. See the description above for a list of the possible error values.

    Warning: The getdate function should never be used in SUID-programs. The reason is obvious: using the DATEMSK environment variable you can get the function to open any arbitrary file and chances are high that with some bogus input (such as a binary file) the program will crash. 

— Function: int getdate_r (const char *string, struct tm *tp)

    The getdate_r function is the reentrant counterpart of getdate. It does not use the global variable getdate_err to signal an error, but instead returns an error code. The same error codes as described in the getdate_err documentation above are used, with 0 meaning success.

    Moreover, getdate_r stores the broken-down time in the variable of type struct tm pointed to by the second argument, rather than in a static variable.

    This function is not defined in the Unix standard. Nevertheless it is available on some other Unix systems as well.

    The warning against using getdate in SUID-programs applies to getdate_r as well. 

