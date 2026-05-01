// sudo apt-get install libssl-dev
// gcc tls_connect.c -o tls_connect -lssl -lcrypto

#include "stdio.h"  // printf(), exit()

#include "openssl/bio.h"
#include "openssl/err.h"
#include "openssl/ssl.h"

int tls_connect(char *hostname) {
  SSL_CTX *ctx; // context structure
  SSL *ssl;     // connection structure
  BIO *cbio;    // connection BIO
  
  char name[1024]; // addressee of the connection
  char req[1024];  // request
  char resp[1024]; // response
  int len;
  
  // Set up the OpenSSL library
  SSL_load_error_strings();
  SSL_library_init();
  
  // Create SSL context structure and load the trust store (accepted root ca-certificates)
  ctx = SSL_CTX_new(SSLv23_client_method());
  if(! ctx) {
    fprintf(stderr, "Error creating SSL context\n");
    ERR_print_errors_fp(stderr);
    exit(1);
  }
  
  if(! SSL_CTX_load_verify_locations(ctx, "/etc/ssl/certs/ca-certificates.crt", NULL)) {
    fprintf(stderr, "Error loading trust store into SSL context\n");
    ERR_print_errors_fp(stderr);
    exit(1);
  }
  
  cbio = BIO_new_ssl_connect(ctx); // Set up the SSL connection
  
  // Set flag SSL_MODE_AUTO_RETRY
  BIO_get_ssl(cbio, &ssl);
  SSL_set_mode(ssl, SSL_MODE_AUTO_RETRY);
  
  // Connect to server <hostname>
  sprintf(name, "%s:%s", hostname, "https"); // name = "<hostname>:<port>"
  BIO_set_conn_hostname(cbio, name);
  if (BIO_do_connect(cbio) <= 0) {
    fprintf(stderr, "Error attempting to connect\n");
    ERR_print_errors_fp(stderr);
    BIO_free_all(cbio);
    SSL_CTX_free(ctx);
    exit(1);
  }
  
  // Check the certificate
  if (SSL_get_verify_result(ssl) != X509_V_OK) fprintf(stderr, "Certificate verification error: %i\n", (int) SSL_get_verify_result(ssl));
  
  // send HTTP request to the server <hostname>
  sprintf(req, "GET / HTTP/1.1\x0D\x0AHost: %s\x0D\x0A\x43onnection: Close\x0D\x0A\x0D\x0A", hostname);
  BIO_puts(cbio, req);
  
  // read HTTP response from server and print to stdout
  for ( ; ; ) {
    len = BIO_read(cbio, resp, 1024);
    if(len <= 0) break;
    
    resp[len] = '\0';
    printf("%s", resp);
  }
  
  // close TCP/IP connection and free bio and context
  BIO_free_all(cbio);
  SSL_CTX_free(ctx);

  return 0;
}

int main(int argc, char *argv[]) {
  if (argc > 1) tls_connect(argv[1]);
  else          printf("Usage: %s <hostname>\n", argv[0]);
  
  return 0;
}
