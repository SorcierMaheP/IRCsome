include .env
export

CC=gcc
CFLAGS=-lssl -lcrypto -Wall -Wstrict-prototypes -Wshadow -Wundef -Werror -Wextra -pedantic

run: client.c utils/core_utils.c utils/helper_utils.c
	$(CC) $(CFLAGS) -o client client.c utils/core_utils.c utils/helper_utils.c
	./client -H $(IRC_HOST) -P $(IRC_PORT) -N $(IRC_NICK) -R $(IRC_REAL)

pass: client.c utils/core_utils.c utils/helper_utils.c
	$(CC) $(CFLAGS) -o client client.c utils/core_utils.c utils/helper_utils.c
	./client -H $(IRC_HOST) -P $(IRC_PORT) -N $(IRC_NICK) -R $(IRC_REAL) -p