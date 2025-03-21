
Next: General Time String Parsing, Up: Parsing Date and Time
21.4.6.1 Interpret string according to given format

The first function is rather low-level. It is nevertheless frequently used in software since it is better known. Its interface and implementation are heavily influenced by the getdate function, which is defined and implemented in terms of calls to strptime.
— Function: char * strptime (const char *s, const char *fmt, struct tm *tp)

    The strptime function parses the input string s according to the format string fmt and stores its results in the structure tp.

    The input string could be generated by a strftime call or obtained any other way. It does not need to be in a human-recognizable format; e.g. a date passed as "02:1999:9" is acceptable, even though it is ambiguous without context. As long as the format string fmt matches the input string the function will succeed.

    The user has to make sure, though, that the input can be parsed in a unambiguous way. The string "1999112" can be parsed using the format "%Y%m%d" as 1999-1-12, 1999-11-2, or even 19991-1-2. It is necessary to add appropriate separators to reliably get results.

    The format string consists of the same components as the format string of the strftime function. The only difference is that the flags _, -, 0, and ^ are not allowed. Several of the distinct formats of strftime do the same work in strptime since differences like case of the input do not matter. For reasons of symmetry all formats are supported, though.

    The modifiers E and O are also allowed everywhere the strftime function allows them.

    The formats are:

    %a
    %A
        The weekday name according to the current locale, in abbreviated form or the full name.
    %b
    %B
    %h
        The month name according to the current locale, in abbreviated form or the full name.
    %c
        The date and time representation for the current locale.
    %Ec
        Like %c but the locale's alternative date and time format is used.
    %C
        The century of the year.

        It makes sense to use this format only if the format string also contains the %y format.
    %EC
        The locale's representation of the period.

        Unlike %C it sometimes makes sense to use this format since some cultures represent years relative to the beginning of eras instead of using the Gregorian years.
    %d
    %e
        The day of the month as a decimal number (range 1 through 31). Leading zeroes are permitted but not required.
    %Od
    %Oe
        Same as %d but using the locale's alternative numeric symbols.

        Leading zeroes are permitted but not required.
    %D
        Equivalent to %m/%d/%y.
    %F
        Equivalent to %Y-%m-%d, which is the ISO 8601 date format.

        This is a GNU extension following an ISO C99 extension to strftime.
    %g
        The year corresponding to the ISO week number, but without the century (range 00 through 99).

        Note: Currently, this is not fully implemented. The format is recognized, input is consumed but no field in tm is set.

        This format is a GNU extension following a GNU extension of strftime.
    %G
        The year corresponding to the ISO week number.

        Note: Currently, this is not fully implemented. The format is recognized, input is consumed but no field in tm is set.

        This format is a GNU extension following a GNU extension of strftime.
    %H
    %k
        The hour as a decimal number, using a 24-hour clock (range 00 through 23).

        %k is a GNU extension following a GNU extension of strftime.
    %OH
        Same as %H but using the locale's alternative numeric symbols.
    %I
    %l
        The hour as a decimal number, using a 12-hour clock (range 01 through 12).

        %l is a GNU extension following a GNU extension of strftime.
    %OI
        Same as %I but using the locale's alternative numeric symbols.
    %j
        The day of the year as a decimal number (range 1 through 366).

        Leading zeroes are permitted but not required.
    %m
        The month as a decimal number (range 1 through 12).

        Leading zeroes are permitted but not required.
    %Om
        Same as %m but using the locale's alternative numeric symbols.
    %M
        The minute as a decimal number (range 0 through 59).

        Leading zeroes are permitted but not required.
    %OM
        Same as %M but using the locale's alternative numeric symbols.
    %n
    %t
        Matches any white space.
    %p
    %P
        The locale-dependent equivalent to ‘AM’ or ‘PM’.

        This format is not useful unless %I or %l is also used. Another complication is that the locale might not define these values at all and therefore the conversion fails.

        %P is a GNU extension following a GNU extension to strftime.
    %r
        The complete time using the AM/PM format of the current locale.

        A complication is that the locale might not define this format at all and therefore the conversion fails.
    %R
        The hour and minute in decimal numbers using the format %H:%M.

        %R is a GNU extension following a GNU extension to strftime.
    %s
        The number of seconds since the epoch, i.e., since 1970-01-01 00:00:00 UTC. Leap seconds are not counted unless leap second support is available.

        %s is a GNU extension following a GNU extension to strftime.
    %S
        The seconds as a decimal number (range 0 through 60).

        Leading zeroes are permitted but not required.

        NB: The Unix specification says the upper bound on this value is 61, a result of a decision to allow double leap seconds. You will not see the value 61 because no minute has more than one leap second, but the myth persists.
    %OS
        Same as %S but using the locale's alternative numeric symbols.
    %T
        Equivalent to the use of %H:%M:%S in this place.
    %u
        The day of the week as a decimal number (range 1 through 7), Monday being 1.

        Leading zeroes are permitted but not required.

        Note: Currently, this is not fully implemented. The format is recognized, input is consumed but no field in tm is set.
    %U
        The week number of the current year as a decimal number (range 0 through 53).

        Leading zeroes are permitted but not required.
    %OU
        Same as %U but using the locale's alternative numeric symbols.
    %V
        The ISO 8601:1988 week number as a decimal number (range 1 through 53).

        Leading zeroes are permitted but not required.

        Note: Currently, this is not fully implemented. The format is recognized, input is consumed but no field in tm is set.
    %w
        The day of the week as a decimal number (range 0 through 6), Sunday being 0.

        Leading zeroes are permitted but not required.

        Note: Currently, this is not fully implemented. The format is recognized, input is consumed but no field in tm is set.
    %Ow
        Same as %w but using the locale's alternative numeric symbols.
    %W
        The week number of the current year as a decimal number (range 0 through 53).

        Leading zeroes are permitted but not required.

        Note: Currently, this is not fully implemented. The format is recognized, input is consumed but no field in tm is set.
    %OW
        Same as %W but using the locale's alternative numeric symbols.
    %x
        The date using the locale's date format.
    %Ex
        Like %x but the locale's alternative data representation is used.
    %X
        The time using the locale's time format.
    %EX
        Like %X but the locale's alternative time representation is used.
    %y
        The year without a century as a decimal number (range 0 through 99).

        Leading zeroes are permitted but not required.

        Note that it is questionable to use this format without the %C format. The strptime function does regard input values in the range 68 to 99 as the years 1969 to 1999 and the values 0 to 68 as the years 2000 to 2068. But maybe this heuristic fails for some input data.

        Therefore it is best to avoid %y completely and use %Y instead.
    %Ey
        The offset from %EC in the locale's alternative representation.
    %Oy
        The offset of the year (from %C) using the locale's alternative numeric symbols.
    %Y
        The year as a decimal number, using the Gregorian calendar.
    %EY
        The full alternative year representation.
    %z
        The offset from GMT in ISO 8601/RFC822 format.
    %Z
        The timezone name.

        Note: Currently, this is not fully implemented. The format is recognized, input is consumed but no field in tm is set.
    %%
        A literal ‘%’ character. 

    All other characters in the format string must have a matching character in the input string. Exceptions are white spaces in the input string which can match zero or more whitespace characters in the format string.

    Portability Note: The XPG standard advises applications to use at least one whitespace character (as specified by isspace) or other non-alphanumeric characters between any two conversion specifications. The GNU C Library does not have this limitation but other libraries might have trouble parsing formats like "%d%m%Y%H%M%S".

    The strptime function processes the input string from right to left. Each of the three possible input elements (white space, literal, or format) are handled one after the other. If the input cannot be matched to the format string the function stops. The remainder of the format and input strings are not processed.

    The function returns a pointer to the first character it was unable to process. If the input string contains more characters than required by the format string the return value points right after the last consumed input character. If the whole input string is consumed the return value points to the NULL byte at the end of the string. If an error occurs, i.e., strptime fails to match all of the format string, the function returns NULL. 

The specification of the function in the XPG standard is rather vague, leaving out a few important pieces of information. Most importantly, it does not specify what happens to those elements of tm which are not directly initialized by the different formats. The implementations on different Unix systems vary here.

The GNU libc implementation does not touch those fields which are not directly initialized. Exceptions are the tm_wday and tm_yday elements, which are recomputed if any of the year, month, or date elements changed. This has two implications:

    * Before calling the strptime function for a new input string, you should prepare the tm structure you pass. Normally this will mean initializing all values are to zero. Alternatively, you can set all fields to values like INT_MAX, allowing you to determine which elements were set by the function call. Zero does not work here since it is a valid value for many of the fields.

      Careful initialization is necessary if you want to find out whether a certain field in tm was initialized by the function call.
    * You can construct a struct tm value with several consecutive strptime calls. A useful application of this is e.g. the parsing of two separate strings, one containing date information and the other time information. By parsing one after the other without clearing the structure in-between, you can construct a complete broken-down time. 

The following example shows a function which parses a string which is contains the date information in either US style or ISO 8601 form:

     const char *
     parse_date (const char *input, struct tm *tm)
     {
       const char *cp;
     
       /* First clear the result structure.  */
       memset (tm, '\0', sizeof (*tm));
     
       /* Try the ISO format first.  */
       cp = strptime (input, "%F", tm);
       if (cp == NULL)
         {
           /* Does not match.  Try the US form.  */
           cp = strptime (input, "%D", tm);
         }
     
       return cp;
     }


