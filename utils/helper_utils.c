#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <openssl/ssl.h>
#include <regex.h>

#include "utils.h"

regex_t command_regex = {0};
regex_t numeric_regex = {0};

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

void HELPER_regex_init(void)
{
    int ret = 0;
    char errbuf[256];

    if ((ret = regcomp(&command_regex, "^[A-Z]+$", REG_EXTENDED)))
    {
        regerror(ret, &command_regex, errbuf, sizeof(errbuf));
        CUST_ERROR(errbuf);
        exit(EXIT_FAILURE);
    }

    if ((ret = regcomp(&numeric_regex, "^[0-9]{3}$", REG_EXTENDED)))
    {
        regerror(ret, &command_regex, errbuf, sizeof(errbuf));
        CUST_ERROR(errbuf);
        exit(EXIT_FAILURE);
    }
}

void HELPER_regex_destroy(void)
{
    regfree(&command_regex);
    regfree(&numeric_regex);
}

int HELPER_is_command_valid(char *command)
{
    int ret = 0;
    char errbuf[256];

    ret = regexec(&command_regex, command, 0, NULL, 0);

    if (ret == 0)
        return 1;
    else if (ret == REG_NOMATCH)
        return 0;
    else
    {
        regerror(ret, &command_regex, errbuf, sizeof(errbuf));
        CUST_ERROR(errbuf);
        exit(EXIT_FAILURE);
    }
}

int HELPER_is_command_numeric(char *command)
{
    int ret = 0;
    char errbuf[256];

    ret = regexec(&numeric_regex, command, 0, NULL, 0);

    if (ret == 0)
        return 1;
    else if (ret == REG_NOMATCH)
        return 0;
    else
    {
        regerror(ret, &numeric_regex, errbuf, sizeof(errbuf));
        CUST_ERROR(errbuf);
        exit(EXIT_FAILURE);
    }
}

void HELPER_irc_msg_printer(const IRC_Message *irc_msg)
{
    fprintf(stdout, CYAN("%s "), irc_msg->source ? irc_msg->source : "(none)");
    fprintf(stdout, CYAN("%s "), irc_msg->command);

    for (size_t i = 0; i < irc_msg->params_len; i++)
    {
        fprintf(stdout, CYAN("\"%s\" "), irc_msg->params[i]);
    }
    fprintf(stdout, "\n");
}

int HELPER_msg_printer(const char *fmt, ...)
{
    char buf[BUFFER_SIZE];

    va_list ap;
    va_start(ap, fmt);
    int len = vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);

    if (len < 0 || len >= (int)sizeof(buf))
    {
        CUST_ERROR("Error with creating formatted string for HELPER_msg_printer");
        exit(EXIT_FAILURE);
    }

    int ret = fprintf(stdout, "%s", buf);

    return ret;
}

char *HELPER_concat_params(const IRC_Message *irc_msg, size_t start)
{
    size_t len = 0;

    for (size_t i = start; irc_msg->params[i] != NULL && i < irc_msg->params_len; i++)
    {
        len += strlen(irc_msg->params[i]);
        if (irc_msg->params[i + 1] != NULL)
            len++;
    }

    char *result = malloc(len + 1);
    if (!result)
    {
        CUST_ERROR(strerror(errno));
        exit(EXIT_FAILURE);
    }

    result[0] = '\0';
    for (size_t i = start; irc_msg->params[i] != NULL && i < irc_msg->params_len; i++)
    {
        strcat(result, irc_msg->params[i]);
        if (irc_msg->params[i + 1] != NULL)
            strcat(result, " ");
    }

    return result;
}