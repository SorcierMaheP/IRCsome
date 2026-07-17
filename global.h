#pragma once

#include <sys/types.h>
#include <openssl/ssl.h>

// Custom defines
#define RED(str) "\x1b[31m" str "\x1b[0m"
#define GREEN(str) "\x1b[32m" str "\x1b[0m"
#define CYAN(str) "\x1b[36m" str "\x1b[0m"
#define BOLD_HIGH_ULINE_CYAN(str) "\x1b[1;4;96m" str "\x1b[0m"
#define YELLOW(str) "\x1b[33m" str "\x1b[0m"
#define BOLD_HIGH_YELLOW(str) "\x1b[1;93m" str "\x1b[0m"
#define BOLD_HIGH_ULINE_YELLOW(str) "\x1b[1;4;93m" str "\x1b[0m"
#define WHITE(str) "\x1b[37m" str "\x1b[0m"
#define BOLD_HIGH_WHITE(str) "\x1b[1;97m" str "\x1b[0m"
#define BOLD_HIGH_ULINE_WHITE(str) "\x1b[1;4;97m" str "\x1b[0m"

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

typedef struct IRC_Message
{
    // TODO: Tags
    char *source;
    char *command;
    char **params;
    size_t params_len;
    size_t capacity;
} IRC_Message;