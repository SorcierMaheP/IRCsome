#include "command/command.h"
#include "command/commands/command_def.h"

#include <string.h>

IRC_Command COMMAND_str_to_enum(const char *str)
{
#define X(cmd)                  \
    if (strcmp(str, #cmd) == 0) \
        return CMD_##cmd;

    COMMAND_LIST(X)
#undef X

    return CMD_UNKNOWN;
}

void COMMAND_irc_dispatch(Client *client, IRC_Message *irc_msg)
{
    IRC_Command cmd = COMMAND_str_to_enum(irc_msg->command);

    SSL *ssl = client->network.ssl;
    char **nick = &client->id.nick;
    if (irc_msg->source == NULL || irc_msg->source[0] == '\0')
        irc_msg->source = "(remote)";

    switch (cmd)
    {
    case CMD_NICK:
        COMMAND_handle_NICK(nick, irc_msg);
        break;

    case CMD_QUIT:
        COMMAND_handle_QUIT(*nick, irc_msg);
        break;

    case CMD_JOIN:
        COMMAND_handle_JOIN(*nick, irc_msg);
        break;

    case CMD_PART:
        COMMAND_handle_PART(*nick, irc_msg);
        break;

    case CMD_PRIVMSG:
        COMMAND_handle_PRIVMSG(*nick, irc_msg);
        break;

    case CMD_NOTICE:
        COMMAND_handle_NOTICE(irc_msg);
        break;

    case CMD_MODE:
        COMMAND_handle_MODE(*nick, irc_msg);
        break;

    case CMD_TOPIC:
        COMMAND_handle_TOPIC(irc_msg);
        break;

    case CMD_INVITE:
        COMMAND_handle_INVITE(irc_msg);
        break;

    case CMD_KICK:
        COMMAND_handle_KICK(*nick, irc_msg);
        break;

    case CMD_PING:
        COMMAND_handle_PING(ssl, irc_msg);
        break;

    case CMD_ERROR:
        COMMAND_handle_ERROR(irc_msg);
        break;

    // TODO: Work on this
    case CMD_UNKNOWN:
        CUST_ERROR("Unknown IRC command encountered");
        HELPER_irc_msg_printer(irc_msg);
        break;

    // TODO: Work on this
    default:
        HELPER_irc_msg_printer(irc_msg);
    }
}