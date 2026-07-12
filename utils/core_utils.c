#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>      // Structs for network DB operations
#include <unistd.h>     // Unix API
#include <sys/socket.h> // Socket utils

#include "utils.h"

#define INITIAL_PARAMS_LENGTH 15

void CORE_client_setup(int argc, char **argv, Client *client)
{
    (client->id).user = getenv("USER") != NULL ? getenv("USER") : "unknown";

    int user_option;
    char *options = "H:P:pN:R:";

    while ((user_option = getopt(argc, argv, options)) != -1)
    {
        switch (user_option)
        {
        case 'H':
            (client->network).host = optarg;
            break;
        case 'P':
            (client->network).port = optarg;
            break;
        case 'p':
            fprintf(stdout, "Enter the connection password if needed, else press [ENTER].\n");
            HELPER_password_input(&(client->id).pass);
            break;
        case 'N':
            (client->id).nick = optarg;
            break;
        case 'R':
            (client->id).real = optarg;
            break;
        case '?':
            CUST_ERROR("Invalid option or missing required option argument");
            exit(EXIT_FAILURE);
            break;
        default:
            CUST_ERROR("Unknown error");
            exit(EXIT_FAILURE);
        }
    }

    if ((client->network).host == NULL || (client->network).port == NULL || (client->id).nick == NULL || (client->id).real == NULL)
    {
        CUST_ERROR("Enter all mandatory options (-H, -P, -N, -R)");
        exit(EXIT_FAILURE);
    }
}

SSL_CTX *CORE_create_client_ctx(void)
{
    const SSL_METHOD *method = TLS_client_method();
    SSL_CTX *ctx = SSL_CTX_new(method);

    if (!ctx)
    {
        return NULL;
    }

    /* Trust store: for self-signed testing, trust server.crt directly */
    if (!SSL_CTX_load_verify_locations(ctx, "/etc/ssl/certs/ca-certificates.crt", "/etc/ssl/certs/"))
    {
        SSL_CTX_free(ctx);
        return NULL;
    }

    SSL_CTX_set_verify(ctx, SSL_VERIFY_PEER, NULL);
    SSL_CTX_set_verify_depth(ctx, 4);

    SSL_CTX_set_min_proto_version(ctx, TLS1_3_VERSION);
    return ctx;
}

int CORE_tcp_dial(const char *host, const char *port)
{
    int sock_fd, s;
    struct addrinfo hints; // To restrict addresses
    struct addrinfo *result, *rp;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;

    if ((s = getaddrinfo(host, port, &hints, &result)) != 0)
    {
        CUST_ERROR(gai_strerror(s));
        exit(EXIT_FAILURE);
    }

    // result will point to a list of address structures
    for (rp = result; rp != NULL; rp = rp->ai_next)
    {
        sock_fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);

        if (sock_fd == -1)
            continue;

        if (connect(sock_fd, rp->ai_addr, rp->ai_addrlen) != -1)
            break; // We could connect successfully

        close(sock_fd);
    }

    freeaddrinfo(result);

    if (rp == NULL)
    {
        CUST_ERROR("Could not connect to any of the addresses found");
        exit(EXIT_FAILURE);
    }

    return sock_fd;
}

void CORE_tls_dial(SSL_CTX *ctx, struct network *client_network)
{
    int sock_fd = CORE_tcp_dial(client_network->host, client_network->port);

    client_network->ssl = SSL_new(ctx);
    if (!client_network->ssl)
    {
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    SSL_set_fd(client_network->ssl, sock_fd);

    /* Optional but good practice: set the SNI and hostname for verification */
    SSL_set_tlsext_host_name(client_network->ssl, client_network->host);

    if (SSL_connect(client_network->ssl) <= 0)
    {
        CUST_ERROR("TLS handshake failed");
        SSL_shutdown(client_network->ssl);
        SSL_free(client_network->ssl);
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    CUST_MESSAGE("TLS handshake successful");
}

void CORE_polling_setup(struct network client_network, struct pollfd *fds)
{

    fds[0].fd = SSL_get_fd(client_network.ssl);
    fds[0].events = POLLIN;

    fds[1].fd = STDIN_FILENO;
    fds[1].events = POLLIN;
}

int CORE_ssl_write(SSL *ssl, const char *fmt, ...)
{
    char buf[512];

    va_list ap;
    va_start(ap, fmt);
    int len = vsnprintf(buf, sizeof(buf), fmt, ap);
    va_end(ap);

    if (len < 0 || len >= (int)sizeof(buf))
    {
        CUST_ERROR("Error with creating formatted string for SSL_write");
        exit(EXIT_FAILURE);
    }

    int ret = SSL_write(ssl, buf, len);

    if (ret <= 0)
    {
        CUST_ERROR("SSL_write failed");
        exit(EXIT_FAILURE);
    }

    return ret;
}

void CORE_conn_reg(Client client)
{
    // TODO: Capability Negotiation

    // PASS <password>
    if (client.id.pass && *(client.id.pass) != '\0')
    {
        CORE_ssl_write(client.network.ssl, "PASS %s\r\n", client.id.pass);
    }

    // NICK <nickname>
    CORE_ssl_write(client.network.ssl, "NICK %s\r\n", client.id.nick);

    // USER <username> 0 * <realname>
    CORE_ssl_write(client.network.ssl, "USER %s 0 * :%s\r\n", client.id.nick, client.id.real);
}

int CORE_ssl_read(struct network network, Buffer *buf)
{

    int ret = SSL_read(network.ssl, buf->data + buf->len, BUFFER_SIZE - buf->len - 1);

    if (ret <= 0)
    {
        CUST_ERROR("SSL_read failed");
        exit(EXIT_FAILURE);
    }

    buf->len += ret;
    buf->data[buf->len] = '\0';

    return ret;
}

void CORE_process_buffer(Buffer *buf)
{
    char delim = ' ';
    char *line_end; // Pointer to \r if "\r\n" is found.
    IRC_Message server_msg = {0};

    while ((line_end = strstr(buf->data, "\r\n")) != NULL)
    {
        *line_end = '\0';

        // Process one complete IRC message. Ignore empty messages.
        if (line_end != buf->data)
        {
            server_msg = CORE_msg_parser(buf->data, delim);
            HELPER_irc_msg_printer(server_msg);
            free(server_msg.params);
        }

        size_t line_len = (line_end - buf->data) + 2;
        memmove(buf->data,
                buf->data + line_len,
                buf->len - line_len);

        buf->len -= line_len;
        buf->data[buf->len] = '\0';
    }
}

IRC_Message CORE_msg_parser(char msg[], char delim)
{
    IRC_Message irc_msg = {0};
    irc_msg.params = malloc(INITIAL_PARAMS_LENGTH * sizeof(char *));
    if (irc_msg.params == NULL)
    {
        CUST_ERROR(strerror(errno));
        exit(EXIT_FAILURE);
    }
    irc_msg.capacity = INITIAL_PARAMS_LENGTH;

    char *ptr = msg;

    while (*ptr && *ptr == delim)
        ptr++;

    if (*ptr == '\0')
    {
        CUST_ERROR("Malformed message received from server");
        exit(EXIT_FAILURE);
    }

    // SOURCE
    if (*ptr == ':')
    {
        ptr++;
        irc_msg.source = ptr;

        while (*ptr && *ptr != delim)
            ptr++;

        if (*ptr == '\0')
        {
            CUST_ERROR("Malformed message received from server");
            exit(EXIT_FAILURE);
        }

        *ptr++ = '\0';

        while (*ptr == delim)
            ptr++;
    }

    // COMMAND
    if (*ptr == '\0')
    {
        CUST_ERROR("Malformed message received from server");
        exit(EXIT_FAILURE);
    }

    irc_msg.command = ptr;

    while (*ptr && *ptr != delim)
        ptr++;

    if (*ptr != '\0')
    {
        *ptr++ = '\0';

        while (*ptr == delim)
            ptr++;
    }

    // PARAMETERS
    while (*ptr)
    {
        if (irc_msg.params_len == irc_msg.capacity)
        {
            irc_msg.capacity *= 2;
            irc_msg.params = realloc(
                irc_msg.params,
                irc_msg.capacity * sizeof(char *));
            if (irc_msg.params == NULL)
            {
                CUST_ERROR(strerror(errno));
                exit(EXIT_FAILURE);
            }
        }

        // TRAILING PARAMETER
        // Consider everything after : to be a single param
        if (*ptr == ':')
        {
            irc_msg.params[irc_msg.params_len++] = ++ptr;
            break;
        }

        irc_msg.params[irc_msg.params_len++] = ptr;

        while (*ptr && *ptr != delim)
            ptr++;

        if (*ptr == '\0')
            break;

        *ptr++ = '\0';

        while (*ptr == delim)
            ptr++;
    }

    return irc_msg;
}

void CORE_read_input(struct network client_network)
{
    char line[512];

    if (fgets(line, sizeof(line), stdin) == NULL)
    {
        CUST_ERROR(strerror(errno));
        exit(EXIT_FAILURE);
    }
    line[strcspn(line, "\n")] = '\0';

    CORE_ssl_write(client_network.ssl, "%s\r\n", line);
}