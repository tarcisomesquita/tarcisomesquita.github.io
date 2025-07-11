
// #include<netdb.h>

struct servent // Description of data base entry for a single service.
{
   char *s_name;       // Official service name.
   char **s_aliases;   // Alias list.
   int s_port;         // Port number.
   char *s_proto;      // Protocol to use.
};

// Return entry from network data base for network with NAME and protocol PROTO.
extern struct servent *getservbyname(const char *name, const char *proto);


// Function to convert between host and network byte order.
// #include <netinet/in.h>
extern unsigned short int ntohs(unsigned short int netshort);
// "www" = 80 = 0x0050
// htons(80) = 0x5000
// ntohs(0x5000) = 80;


extern int printf(char *, ...);

int main()
{
   char name[] = "www"; // "kerberos"
   char proto[] = "tcp";
   struct servent *description;
   
   description = getservbyname(name, proto);
   if(!description) {
      printf("\nERRO: a função getservbyname não retornou um ponteiro\n\n");
      return 1;
   }
   
   printf("\ndescription->s_name        = \"%s\"\n", description->s_name);
   printf("description->s_aliases     =");
   for(;;)
   {
      char *p;
      if(! description->s_aliases) break;
      if(*description->s_aliases)
      {
         p = *description->s_aliases;
         printf(" \"%s\"", p);
         description->s_aliases++;
         continue;
      }
      printf("\n");
      break;
   }
   printf("ntohs(description->s_port) = %u\n", ntohs(description->s_port));
   printf("description->s_proto       = \"%s\"\n\n", description->s_proto);
   
   
   
   return 0;
}

