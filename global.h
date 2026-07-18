#pragma once

#include <sys/types.h>
#include <openssl/ssl.h>

// Custom defines
/* Colors */
#define ANSI_RED "\x1b[31m"
#define ANSI_GREEN "\x1b[32m"
#define ANSI_YELLOW "\x1b[33m"
#define ANSI_WHITE "\x1b[37m"
#define ANSI_CYAN "\x1b[36m"

/* Bright/Bold */
#define ANSI_BOLD_HIGH_YELLOW "\x1b[1;93m"
#define ANSI_BOLD_HIGH_WHITE "\x1b[1;97m"
#define ANSI_BOLD_HIGH_CYAN "\x1b[1;96m"

/* Bright/Bold/Underline */
#define ANSI_BOLD_HIGH_ULINE_YELLOW "\x1b[1;4;93m"
#define ANSI_BOLD_HIGH_ULINE_WHITE "\x1b[1;4;97m"
#define ANSI_BOLD_HIGH_ULINE_CYAN "\x1b[1;4;96m"

/* Reset */
#define ANSI_RESET "\x1b[0m"

#define CUST_ERROR(msg) \
    fprintf(stderr, ANSI_RED "ERROR: %s!\n" ANSI_RESET, (msg))
#define CUST_MESSAGE(msg) \
    fprintf(stdout, ANSI_GREEN "MESSAGE: %s!\n" ANSI_RESET, (msg))

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

typedef struct IRC_Message
{
    // TODO: Tags
    char *source;
    char *command;
    char **params;
    size_t params_len;
    size_t capacity;
} IRC_Message;