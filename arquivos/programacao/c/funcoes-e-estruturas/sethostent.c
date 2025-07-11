
You can scan the entire hosts database one entry at a time using sethostent, gethostent and endhostent. Be careful when using these functions because they are not reentrant.
— Function: void sethostent (int stayopen)

    This function opens the hosts database to begin scanning it. You can then call gethostent to read the entries.

    If the stayopen argument is nonzero, this sets a flag so that subsequent calls to gethostbyname or gethostbyaddr will not close the database (as they usually would). This makes for more efficiency if you call those functions several times, by avoiding reopening the database for each call. 

— Function: struct hostent * gethostent (void)

    This function returns the next entry in the hosts database. It returns a null pointer if there are no more entries. 

— Function: void endhostent (void)

    This function closes the hosts database. 
