#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <poll.h>
#include <openssl/ssl.h>

#include "utils/utils.h"

int main(int argc, char *argv[])
{
    Client client = {0};
    Buffer buf = {0};
    struct pollfd fds[2];

    CORE_client_setup(argc, argv, &client);

    SSL_CTX *ctx = HELPER_tls_ctx_init();
    CORE_tls_dial(ctx, &client.network);

    CORE_polling_setup(client.network, fds);

    CORE_conn_reg(client);

    while (1)
    {
        int ret = poll(fds, 2, -1);

        if (ret < 0)
        {
            CUST_ERROR(strerror(errno));
            exit(EXIT_FAILURE);
        }

        if (fds[0].revents & POLLIN)
        {
            CORE_ssl_read(client.network.ssl, &buf);
            CORE_process_buffer(&client, &buf);
        }

        if (fds[1].revents & POLLIN)
        {
            CORE_read_input(client.network);
        }
    }

    HELPER_tls_connection_destroy(&client.network.ssl);
    HELPER_tls_ctx_destroy(ctx);
    HELPER_regex_destroy();

    return 0;
}