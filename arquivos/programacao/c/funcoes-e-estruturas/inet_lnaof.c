
uint32_t inet_lnaof (struct in_addr addr)

    This function returns the local-address-within-network part of the Internet host address addr.

    The function works only with traditional IPv4 class A, B and C network types. It doesn't work with classless addresses and shouldn't be used anymore. 
