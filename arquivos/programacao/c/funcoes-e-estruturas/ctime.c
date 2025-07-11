
Function: char * asctime (const struct tm *brokentime)

    The asctime function converts the broken-down time value that brokentime points to into a string in a standard format:

              "Tue May 21 13:46:22 1991\n"

    The abbreviations for the days of week are: ‘Sun’, ‘Mon’, ‘Tue’, ‘Wed’, ‘Thu’, ‘Fri’, and ‘Sat’.

    The abbreviations for the months are: ‘Jan’, ‘Feb’, ‘Mar’, ‘Apr’, ‘May’, ‘Jun’, ‘Jul’, ‘Aug’, ‘Sep’, ‘Oct’, ‘Nov’, and ‘Dec’.

    The return value points to a statically allocated string, which might be overwritten by subsequent calls to asctime or ctime. (But no other library function overwrites the contents of this string.) 

— Function: char * asctime_r (const struct tm *brokentime, char *buffer)

    This function is similar to asctime but instead of placing the result in a static buffer it writes the string in the buffer pointed to by the parameter buffer. This buffer should have room for at least 26 bytes, including the terminating null.

    If no error occurred the function returns a pointer to the string the result was written into, i.e., it returns buffer. Otherwise return NULL. 

— Function: char * ctime (const time_t *time)

    The ctime function is similar to asctime, except that you specify the calendar time argument as a time_t simple time value rather than in broken-down local time format. It is equivalent to

              asctime (localtime (time))

    ctime sets the variable tzname, because localtime does so. See Time Zone Functions. 

— Function: char * ctime_r (const time_t *time, char *buffer)

    This function is similar to ctime, but places the result in the string pointed to by buffer. It is equivalent to (written using gcc extensions, see Statement Exprs):

              ({ struct tm tm; asctime_r (localtime_r (time, &tm), buf); })

    If no error occurred the function returns a pointer to the string the result was written into, i.e., it returns buffer. Otherwise return NULL. 

Function: size_t strftime (char *s, size_t size, const char *template, const struct tm *brokentime)

    This function is similar to the sprintf function
 template are specialized for printing components of the date and time brokentime according to the locale currently specified for time conversion (see Locales).

Ordinary characters appearing in the template are copied to the output string s; this can include multibyte character sequences. Conversion specifiers are introduced by a ‘%’ character, followed by an optional flag which can be one of the following. These flags are all GNU extensions. The first three affect only the output of numbers:

_
    The number is padded with spaces.
-
    The number is not padded at all.
0
    The number is padded with zeros even if the format specifies padding with spaces.
^
    The output uses uppercase characters, but only if this is possible (see Case Conversion). 

The default action is to pad the number with zeros to keep it a constant width. Numbers that do not have a range indicated below are never padded, since there is no natural width for them.

Following the flag an optional specification of the width is possible. This is specified in decimal notation. If the natural size of the output is of the field has less than the specified number of characters, the result is written right adjusted and space padded to the given size.

An optional modifier can follow the optional flag and width specification. The modifiers, which were first standardized by POSIX.2-1992 and by ISO C99, are:

E
    Use the locale's alternate representation for date and time. This modifier applies to the %c, %C, %x, %X, %y and %Y format specifiers. In a Japanese locale, for example, %Ex might yield a date format based on the Japanese Emperors' reigns.
O
    Use the locale's alternate numeric symbols for numbers. This modifier applies only to numeric format specifiers. 

If the format supports the modifier but no alternate representation is available, it is ignored.

The conversion specifier ends with a format specifier taken from the following list. The whole ‘%’ sequence is replaced in the output string as follows:

%a
    The abbreviated weekday name according to the current locale.
%A
    The full weekday name according to the current locale.
%b
    The abbreviated month name according to the current locale.
%B
    The full month name according to the current locale.

    Using %B together with %d produces grammatically incorrect results for some locales.
%c
    The preferred calendar time representation for the current locale.
%C
    The century of the year. This is equivalent to the greatest integer not greater than the year divided by 100.

    This format was first standardized by POSIX.2-1992 and by ISO C99.
%d
    The day of the month as a decimal number (range 01 through 31).
%D
    The date using the format %m/%d/%y.

    This format was first standardized by POSIX.2-1992 and by ISO C99.
%e
    The day of the month like with %d, but padded with blank (range 1 through 31).

    This format was first standardized by POSIX.2-1992 and by ISO C99.
%F
    The date using the format %Y-%m-%d. This is the form specified in the ISO 8601 standard and is the preferred form for all uses.

    This format was first standardized by ISO C99 and by POSIX.1-2001.
%g
    The year corresponding to the ISO week number, but without the century (range 00 through 99). This has the same format and value as %y, except that if the ISO week number (see %V) belongs to the previous or next year, that year is used instead.

    This format was first standardized by ISO C99 and by POSIX.1-2001.
%G
    The year corresponding to the ISO week number. This has the same format and value as %Y, except that if the ISO week number (see %V) belongs to the previous or next year, that year is used instead.

    This format was first standardized by ISO C99 and by POSIX.1-2001 but was previously available as a GNU extension.
%h
    The abbreviated month name according to the current locale. The action is the same as for %b.

    This format was first standardized by POSIX.2-1992 and by ISO C99.
%H
    The hour as a decimal number, using a 24-hour clock (range 00 through 23).
%I
    The hour as a decimal number, using a 12-hour clock (range 01 through 12).
%j
    The day of the year as a decimal number (range 001 through 366).
%k
    The hour as a decimal number, using a 24-hour clock like %H, but padded with blank (range 0 through 23).

    This format is a GNU extension.
%l
    The hour as a decimal number, using a 12-hour clock like %I, but padded with blank (range 1 through 12).

    This format is a GNU extension.
%m
    The month as a decimal number (range 01 through 12).
%M
    The minute as a decimal number (range 00 through 59).
%n
    A single ‘\n’ (newline) character.

    This format was first standardized by POSIX.2-1992 and by ISO C99.
%p
    Either ‘AM’ or ‘PM’, according to the given time value; or the corresponding strings for the current locale. Noon is treated as ‘PM’ and midnight as ‘AM’. In most locales ‘AM’/‘PM’ format is not supported, in such cases "%p" yields an empty string.
%P
    Either ‘am’ or ‘pm’, according to the given time value; or the corresponding strings for the current locale, printed in lowercase characters. Noon is treated as ‘pm’ and midnight as ‘am’. In most locales ‘AM’/‘PM’ format is not supported, in such cases "%P" yields an empty string.

    This format is a GNU extension.
%r
    The complete calendar time using the AM/PM format of the current locale.

    This format was first standardized by POSIX.2-1992 and by ISO C99. In the POSIX locale, this format is equivalent to %I:%M:%S %p.
%R
    The hour and minute in decimal numbers using the format %H:%M.

    This format was first standardized by ISO C99 and by POSIX.1-2001 but was previously available as a GNU extension.
%s
    The number of seconds since the epoch, i.e., since 1970-01-01 00:00:00 UTC. Leap seconds are not counted unless leap second support is available.

    This format is a GNU extension.
%S
    The seconds as a decimal number (range 00 through 60).
%t
    A single ‘\t’ (tabulator) character.

    This format was first standardized by POSIX.2-1992 and by ISO C99.
%T
    The time of day using decimal numbers using the format %H:%M:%S.

    This format was first standardized by POSIX.2-1992 and by ISO C99.
%u
    The day of the week as a decimal number (range 1 through 7), Monday being 1.

    This format was first standardized by POSIX.2-1992 and by ISO C99.
%U
    The week number of the current year as a decimal number (range 00 through 53), starting with the first Sunday as the first day of the first week. Days preceding the first Sunday in the year are considered to be in week 00.
%V
    The ISO 8601:1988 week number as a decimal number (range 01 through 53). ISO weeks start with Monday and end with Sunday. Week 01 of a year is the first week which has the majority of its days in that year; this is equivalent to the week containing the year's first Thursday, and it is also equivalent to the week containing January 4. Week 01 of a year can contain days from the previous year. The week before week 01 of a year is the last week (52 or 53) of the previous year even if it contains days from the new year.

    This format was first standardized by POSIX.2-1992 and by ISO C99.
%w
    The day of the week as a decimal number (range 0 through 6), Sunday being 0.
%W
    The week number of the current year as a decimal number (range 00 through 53), starting with the first Monday as the first day of the first week. All days preceding the first Monday in the year are considered to be in week 00.
%x
    The preferred date representation for the current locale.
%X
    The preferred time of day representation for the current locale.
%y
    The year without a century as a decimal number (range 00 through 99). This is equivalent to the year modulo 100.
%Y
    The year as a decimal number, using the Gregorian calendar. Years before the year 1 are numbered 0, -1, and so on.
%z
    RFC 822/ISO 8601:1988 style numeric time zone (e.g., -0600 or +0100), or nothing if no time zone is determinable.

    This format was first standardized by ISO C99 and by POSIX.1-2001 but was previously available as a GNU extension.

    In the POSIX locale, a full RFC 822 timestamp is generated by the format ‘"%a, %d %b %Y %H:%M:%S %z"’ (or the equivalent ‘"%a, %d %b %Y %T %z"’).
%Z
    The time zone abbreviation (empty if the time zone can't be determined).
%%
    A literal ‘%’ character. 

The size parameter can be used to specify the maximum number of characters to be stored in the array s, including the terminating null character. If the formatted time requires more than size characters, strftime returns zero and the contents of the array s are undefined. Otherwise the return value indicates the number of characters placed in the array s, not including the terminating null character. 


     #include <time.h>
     #include <stdio.h>
     
     #define SIZE 256
     
     int
     main (void)
     {
       char buffer[SIZE];
       time_t curtime;
       struct tm *loctime;
     
       /* Get the current time. */
       curtime = time (NULL);
     
       /* Convert it to local time representation. */
       loctime = localtime (&curtime);
     
       /* Print out the date and time in the standard format. */
       fputs (asctime (loctime), stdout);
     
       /* Print it out in a nice format. */
       strftime (buffer, SIZE, "Today is %A, %B %d.\n", loctime);
       fputs (buffer, stdout);
       strftime (buffer, SIZE, "The time is %I:%M %p.\n", loctime);
       fputs (buffer, stdout);
     
       return 0;
     }

It produces output like this:

     Wed Jul 31 13:02:36 1991
     Today is Wednesday, July 31.
     The time is 01:02 PM.

