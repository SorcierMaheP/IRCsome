#pragma once

#include <openssl/ssl.h>
#include <poll.h>
#include <regex.h>

#include "global.h"

typedef struct Buffer
{
    char data[BUFFER_SIZE];
    size_t len;
} Buffer;

// core_utils.c
void CORE_client_setup(int, char *[], Client *);
SSL_CTX *CORE_create_client_ctx(void);
int CORE_tcp_dial(const char *, const char *);
void CORE_tls_dial(SSL_CTX *, struct network *);
void CORE_polling_setup(struct network, struct pollfd *);
int CORE_ssl_write(SSL *, const char *, ...);
void CORE_conn_reg(Client);
int CORE_ssl_read(SSL *, Buffer *);
void CORE_process_buffer(Client *, Buffer *);
IRC_Message CORE_msg_parser(char *, char);
void CORE_read_input(struct network);
void CORE_irc_msg_process(Client *, IRC_Message *);

// helper_utils.c
void HELPER_password_input(char **);
SSL_CTX *HELPER_tls_ctx_init(void);
void HELPER_tls_connection_destroy(SSL **);
void HELPER_tls_ctx_destroy(SSL_CTX *);
void HELPER_regex_init(void);
void HELPER_regex_destroy(void);
void HELPER_client_destroy(Client *);
int HELPER_is_command_valid(char *);
int HELPER_is_command_numeric(char *);
void HELPER_irc_msg_printer(const IRC_Message *);
char *HELPER_concat_params(const IRC_Message *, size_t);

// ../command/commands/command_dispatch.c
void COMMAND_irc_dispatch(Client *, IRC_Message *);

// ../command/numerics/numeric_dispatch.c
void NUMERIC_irc_dispatch(Client *, IRC_Message *);