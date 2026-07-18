#pragma once

#include "global.h"

#define COMMAND_LIST(X) \
    X(NICK)             \
    X(QUIT)             \
    X(JOIN)             \
    X(PART)             \
    X(PRIVMSG)          \
    X(NOTICE)           \
    X(MODE)             \
    X(TOPIC)            \
    X(INVITE)           \
    X(KICK)             \
    X(PING)             \
    X(ERROR)            \
    X(AWAY)             \
    X(WALLOPS)

typedef enum
{
    CMD_UNKNOWN,
#define X(cmd) CMD_##cmd,
    COMMAND_LIST(X)
#undef X
} IRC_Command;

// command/commands/command_func.c
void COMMAND_handle_NICK(char **, const IRC_Message *);
void COMMAND_handle_QUIT(const char *, const IRC_Message *);
void COMMAND_handle_JOIN(const char *, const IRC_Message *);
void COMMAND_handle_PART(const char *, const IRC_Message *);
void COMMAND_handle_PRIVMSG(const char *, const IRC_Message *);
void COMMAND_handle_NOTICE(const IRC_Message *);
void COMMAND_handle_MODE(const char *, const IRC_Message *);
void COMMAND_handle_TOPIC(const IRC_Message *);
void COMMAND_handle_INVITE(const IRC_Message *);
void COMMAND_handle_KICK(const char *, const IRC_Message *);
void COMMAND_handle_PING(SSL *, const IRC_Message *);
void COMMAND_handle_ERROR(const IRC_Message *);
void COMMAND_handle_AWAY(const IRC_Message *);
void COMMAND_handle_WALLOPS(const IRC_Message *);