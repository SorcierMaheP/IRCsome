include .env
export

CC=gcc
CFLAGS=-lssl -lcrypto -I. -Wall -Wstrict-prototypes -Wshadow -Wundef -Werror -Wextra -pedantic
SRC=$(wildcard client.c utils/*.c command/commands/*.c command/numerics/*.c)

run: client.c $(SRC)
	$(CC) $(CFLAGS) -o client $(SRC)
	./client -H $(IRC_HOST) -P $(IRC_PORT) -N $(IRC_NICK) -R $(IRC_REAL)

pass: client.c $(SRC)
	$(CC) $(CFLAGS) -o client $(SRC)
	./client -H $(IRC_HOST) -P $(IRC_PORT) -N $(IRC_NICK) -R $(IRC_REAL) -p