#pragma once

#include "global.h"

// command/commands/command_dispatch.c
void COMMAND_irc_dispatch(Client *, IRC_Message *);

// command/numerics/numeric_dispatch.c
void NUMERIC_irc_dispatch(Client *, IRC_Message *);

// utils/core_utils.c
int CORE_ssl_write(SSL *, const char *, ...);

// utils/helper_utils.c
void HELPER_irc_msg_printer(const IRC_Message *);
int HELPER_msg_printer(const char *, ...);
char *HELPER_concat_params(const IRC_Message *, size_t);