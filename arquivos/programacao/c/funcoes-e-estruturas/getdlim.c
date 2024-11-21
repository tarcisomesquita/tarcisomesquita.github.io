Function: ssize_t getdelim (char **lineptr, size_t *n, int delimiter, FILE *stream)

    This function is like getline except that the character which tells it to stop reading is not necessarily newline. The argument delimiter specifies the delimiter character; getdelim keeps reading until it sees that character (or end of file).

    The text is stored in lineptr, including the delimiter character and a terminating null. Like getline, getdelim makes lineptr bigger if it isn't big enough.

    getline is in fact implemented in terms of getdelim, just like this:

              ssize_t
              getline (char **lineptr, size_t *n, FILE *stream)
              {
                return getdelim (lineptr, n, '\n', stream);
              }


