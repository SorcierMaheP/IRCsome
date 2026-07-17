#include "command/commands/command_def.h"
#include "command/command.h"
#include <errno.h>

void COMMAND_handle_NICK(const IRC_Message *irc_msg)
{
    HELPER_msg_printer(CYAN("%s changed their nickname to %s\n"), irc_msg->source, irc_msg->params[0]);
}

void COMMAND_handle_QUIT(const IRC_Message *irc_msg)
{
    HELPER_msg_printer(CYAN("%s has left (%s)\n"), irc_msg->source, irc_msg->params[0]);
}

void COMMAND_handle_JOIN(const IRC_Message *irc_msg)
{
    HELPER_msg_printer(CYAN("%s has joined %s\n"), irc_msg->source, irc_msg->params[0]);
}

void COMMAND_handle_PART(const IRC_Message *irc_msg)
{
    if (irc_msg->params[1] != NULL)
        HELPER_msg_printer(CYAN("%s has been removed from %s (%s)\n"), irc_msg->source, irc_msg->params[0], irc_msg->params[1]);
    else
        HELPER_msg_printer(CYAN("%s has been removed from %s\n"), irc_msg->source, irc_msg->params[0]);
}

void COMMAND_handle_PRIVMSG(const char *nick, const IRC_Message *irc_msg)
{
    char targets[512];

    strlcpy(targets, irc_msg->params[0], sizeof(targets));
    char *target = strtok(targets, ",");

    do
    {
        if (strcmp(nick, target) == 0)
        {
            HELPER_msg_printer(BOLD_HIGH_ULINE_WHITE("%s: ") BOLD_HIGH_ULINE_WHITE("\"%s\"") WHITE(" (to %s)\n"), irc_msg->source, irc_msg->params[1], irc_msg->params[0]);
            return;
        }
    } while ((target = strtok(NULL, ",")) != NULL);

    HELPER_msg_printer(BOLD_HIGH_WHITE("%s: ") BOLD_HIGH_WHITE("\"%s\"") WHITE(" (to %s)\n"), irc_msg->source, irc_msg->params[1], irc_msg->params[0]);
}

void COMMAND_handle_NOTICE(const IRC_Message *irc_msg)
{
    HELPER_msg_printer(BOLD_HIGH_ULINE_YELLOW("%s: ") BOLD_HIGH_ULINE_YELLOW("\"%s\"") YELLOW(" (to %s)\n"), irc_msg->source, irc_msg->params[1], irc_msg->params[0]);
}

void COMMAND_handle_MODE(const IRC_Message *irc_msg)
{
    // First two params will be target and modestring respectively
    char *modeargs = HELPER_concat_params(irc_msg, 2);

    if (*modeargs == '\0')
        HELPER_msg_printer(CYAN("%s set mode %s for %s\n"), irc_msg->source, irc_msg->params[1], irc_msg->params[0]);
    else
        HELPER_msg_printer(CYAN("%s set mode %s %s for %s\n"), irc_msg->source, irc_msg->params[1], modeargs, irc_msg->params[0]);

    free(modeargs);
}

void COMMAND_handle_TOPIC(const IRC_Message *irc_msg)
{
    // Empty TOPIC means it was cleared
    if (*irc_msg->params[1] == '\0')
    {
        HELPER_msg_printer(CYAN("The topic for channel %s was cleared\n"), irc_msg->params[0]);
        return;
    }
    HELPER_msg_printer(CYAN("The topic for channel %s was changed to \"%s\"\n"), irc_msg->params[0], irc_msg->params[1]);
}

void COMMAND_handle_INVITE(const IRC_Message *irc_msg)
{
    HELPER_msg_printer(BOLD_HIGH_ULINE_CYAN("You were invited to the channel %s (by %s)\n"), irc_msg->params[0], irc_msg->source);
}

void COMMAND_handle_KICK(const IRC_Message *irc_msg)
{
    if (irc_msg->params[2] != NULL)
        HELPER_msg_printer(CYAN("%s was kicked from channel %s by %s (%s)\n"), irc_msg->params[1], irc_msg->params[0], irc_msg->source, irc_msg->params[2]);
    else
        HELPER_msg_printer(CYAN("%s was kicked from channel %s by %s\n"), irc_msg->params[1], irc_msg->params[0], irc_msg->source);
}

void COMMAND_handle_PING(SSL *ssl, const IRC_Message *irc_msg)
{
    CORE_ssl_write(ssl, "PONG %s\r\n", irc_msg->params[0]);
}