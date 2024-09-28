
int gethostbyname_r (const char *restrict name, struct hostent *restrict result_buf, char *restrict buf, size_t buflen, struct hostent **restrict result, int *restrict h_errnop)

    The gethostbyname_r function returns information about the host named name. The caller must pass a pointer to an object of type struct hostent in the result_buf parameter. In addition the function may need extra buffer space and the caller must pass an pointer and the size of the buffer in the buf and buflen parameters.

    A pointer to the buffer, in which the result is stored, is available in *result after the function call successfully returned. If an error occurs or if no entry is found, the pointer *result is a null pointer. Success is signalled by a zero return value. If the function failed the return value is an error number. In addition to the errors defined for gethostbyname it can also be ERANGE. In this case the call should be repeated with a larger buffer. Additional error information is not stored in the global variable h_errno but instead in the object pointed to by h_errnop.

    Here's a small example:

              struct hostent *
              gethostname (char *host)
              {
                struct hostent hostbuf, *hp;
                size_t hstbuflen;
                char *tmphstbuf;
                int res;
                int herr;
              
                hstbuflen = 1024;
                /* Allocate buffer, remember to free it to avoid memory leakage.  */
                tmphstbuf = malloc (hstbuflen);
              
                while ((res = gethostbyname_r (host, &hostbuf, tmphstbuf, hstbuflen,
                                               &hp, &herr)) == ERANGE)
                  {
                    /* Enlarge the buffer.  */
                    hstbuflen *= 2;
                    tmphstbuf = realloc (tmphstbuf, hstbuflen);
                  }
                /*  Check for errors.  */
                if (res || hp == NULL)
                  return NULL;
                return hp;
              }

