#include "command/command.h"
#include "command/numerics/numeric_def.h"

#include <stdlib.h>

void NUMERIC_irc_dispatch(Client *client, IRC_Message *irc_msg)
{
    char *numeric = irc_msg->command;
    client = client;
    switch ((IRC_Numeric)atoi(numeric))
    {
    default:
        HELPER_irc_msg_printer(irc_msg);
        break;
    }
}
