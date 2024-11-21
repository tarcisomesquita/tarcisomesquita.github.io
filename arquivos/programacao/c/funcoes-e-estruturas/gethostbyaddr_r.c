
int gethostbyaddr_r (const char *addr, size_t length, int format, struct hostent *restrict result_buf, char *restrict buf, size_t buflen, struct hostent **restrict result, int *restrict h_errnop)

    The gethostbyaddr_r function returns information about the host with Internet address addr. The parameter addr is not really a pointer to char - it can be a pointer to an IPv4 or an IPv6 address. The length argument is the size (in bytes) of the address at addr. format specifies the address format; for an IPv4 Internet address, specify a value of AF_INET; for an IPv6 Internet address, use AF_INET6.

    Similar to the gethostbyname_r function, the caller must provide buffers for the result and memory used internally. In case of success the function returns zero. Otherwise the value is an error number where ERANGE has the special meaning that the caller-provided buffer is too small. 

