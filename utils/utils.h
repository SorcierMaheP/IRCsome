#pragma once

#include <errno.h>
#include <string.h>
#include <openssl/ssl.h>
#include <poll.h>

// Custom defines
#define RED(str) "\x1b[31m" str "\x1b[0m"
#define GREEN(str) "\x1b[32m" str "\x1b[0m"

#define CUST_ERROR(msg) \
    fprintf(stderr, RED("ERROR: %s!\n"), (msg))
#define CUST_MESSAGE(msg) \
    fprintf(stdout, GREEN("MESSAGE: %s!\n"), (msg))

#define BUFFER_SIZE 4096

// Custom structs
struct network
{
    char *host;
    char *port;
    SSL *ssl;
};

struct id
{
    char *pass;
    char *nick;
    char *user;
    char *real;
};

typedef struct Client
{
    struct network network;
    struct id id;
} Client;

typedef struct Buffer
{
    char data[BUFFER_SIZE];
    size_t len;
} Buffer;

typedef struct IRC_Message
{
    // TODO: Tags
    char *source;
    char *command;
    char **params;
    size_t params_len;
    size_t capacity;
} IRC_Message;

// core_utils.c
void CORE_client_setup(int, char *[], Client *);
SSL_CTX *CORE_create_client_ctx(void);
int CORE_tcp_dial(const char *, const char *);
void CORE_tls_dial(SSL_CTX *, struct network *);
void CORE_polling_setup(struct network, struct pollfd *);
int CORE_ssl_write(SSL *, const char *, ...);
void CORE_conn_reg(Client);
int CORE_ssl_read(struct network, Buffer *);
void CORE_process_buffer(Buffer *);
IRC_Message CORE_msg_parser(char *, char);
void CORE_read_input(struct network);

// helper_utils.c
void HELPER_password_input(char **);
SSL_CTX *HELPER_tls_ctx_init();
void HELPER_tls_connection_destroy(SSL **);
void HELPER_tls_ctx_destroy(SSL_CTX *);
void HELPER_irc_msg_printer(IRC_Message);
