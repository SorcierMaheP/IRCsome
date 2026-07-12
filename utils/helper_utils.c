#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "utils.h"

void HELPER_password_input(char **pass)
{
    static struct termios old_terminal;
    static struct termios new_terminal;

    // get settings of the actual terminal
    tcgetattr(STDIN_FILENO, &old_terminal);

    // do not echo the characters
    new_terminal = old_terminal;
    new_terminal.c_lflag &= ~(ECHO);

    // set this as the new terminal options
    tcsetattr(STDIN_FILENO, TCSANOW, &new_terminal);

    // get the password
    // the user can add chars and delete if he puts it wrong
    // the input process is done when he hits the enter
    // the \n is stored, we replace it with \0
    *pass = malloc(BUFFER_SIZE);

    if (*pass == NULL)
    {
        CUST_ERROR(strerror(errno));
        exit(EXIT_FAILURE);
    }

    if (fgets(*pass, BUFFER_SIZE, stdin) == NULL)
    {
        free(*pass);
        CUST_ERROR(strerror(errno));
        exit(EXIT_FAILURE);
    }

    (*pass)[strcspn(*pass, "\n")] = '\0';

    // go back to the old settings
    tcsetattr(STDIN_FILENO, TCSANOW, &old_terminal);
}

SSL_CTX *HELPER_tls_ctx_init()
{
    SSL_CTX *ctx = CORE_create_client_ctx();
    if (!ctx)
    {
        CUST_ERROR("Failed to create client SSL_CTX");
        exit(EXIT_FAILURE);
    }
    return ctx;
}

void HELPER_tls_connection_destroy(SSL **ssl)
{
    if (*ssl)
    {
        SSL_shutdown(*ssl);
        SSL_free(*ssl);
        *ssl = NULL;
    }
}

void HELPER_tls_ctx_destroy(SSL_CTX *ctx)
{
    SSL_CTX_free(ctx);
}

void HELPER_irc_msg_printer(IRC_Message irc_msg)
{
    printf("%s ", irc_msg.source ? irc_msg.source : "(none)");
    printf("%s ", irc_msg.command);

    for (size_t i = 0; i < irc_msg.params_len; i++)
    {
        printf("\"%s\" ", irc_msg.params[i]);
    }
    printf("\n");
}