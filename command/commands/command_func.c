#include "command/commands/command_def.h"
#include "command/command.h"
#include <errno.h>

void COMMAND_handle_NICK(char **nick, const IRC_Message *irc_msg)
{
    const char *color = strcmp(irc_msg->source, *nick) == 0 ? ANSI_BOLD_HIGH_ULINE_CYAN : ANSI_CYAN;
    if (strcmp(irc_msg->source, *nick) == 0)
    {
        free(*nick);
        *nick = strdup(irc_msg->params[0]);
    }
    HELPER_msg_printer("%s%s changed their nickname to %s%s\n", color, irc_msg->source, irc_msg->params[0], ANSI_RESET);
}

void COMMAND_handle_QUIT(const char *nick, const IRC_Message *irc_msg)
{
    const char *color = strcmp(irc_msg->source, nick) == 0 ? ANSI_BOLD_HIGH_ULINE_CYAN : ANSI_CYAN;
    HELPER_msg_printer("%s%s has left (%s)%s\n", color, irc_msg->source, irc_msg->params[0], ANSI_RESET);
}

void COMMAND_handle_JOIN(const char *nick, const IRC_Message *irc_msg)
{
    const char *color = strcmp(irc_msg->source, nick) == 0 ? ANSI_BOLD_HIGH_ULINE_CYAN : ANSI_CYAN;
    HELPER_msg_printer("%s%s has joined %s%s\n", color, irc_msg->source, irc_msg->params[0], ANSI_RESET);
}

void COMMAND_handle_PART(const char *nick, const IRC_Message *irc_msg)
{
    const char *color = strcmp(irc_msg->source, nick) == 0 ? ANSI_BOLD_HIGH_ULINE_CYAN : ANSI_CYAN;

    if (irc_msg->params[1] != NULL)
        HELPER_msg_printer("%s%s has been removed from %s (%s)%s\n", color, irc_msg->source, irc_msg->params[0], irc_msg->params[1], ANSI_RESET);
    else
        HELPER_msg_printer("%s%s has been removed from %s%s\n", color, irc_msg->source, irc_msg->params[0], ANSI_RESET);
}

void COMMAND_handle_PRIVMSG(const char *nick, const IRC_Message *irc_msg)
{
    char targets[512];
    strlcpy(targets, irc_msg->params[0], sizeof(targets));

    const char *color = ANSI_BOLD_HIGH_WHITE;
    char *target = strtok(targets, ",");

    while (target != NULL)
    {
        if (strcmp(nick, target) == 0)
        {
            color = ANSI_BOLD_HIGH_ULINE_WHITE;
            break;
        }
        target = strtok(NULL, ",");
    }

    if (strstr(irc_msg->params[1], nick) != NULL)
        color = ANSI_BOLD_HIGH_ULINE_WHITE;

    HELPER_msg_printer("%s%s (To %s):%s %s%s%s\n", ANSI_PURPLE, irc_msg->source, irc_msg->params[0], ANSI_RESET, color, irc_msg->params[1], ANSI_RESET);
}

void COMMAND_handle_NOTICE(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s (To %s):%s %s%s%s\n", ANSI_PURPLE, irc_msg->source, irc_msg->params[0], ANSI_RESET, ANSI_BOLD_HIGH_ULINE_YELLOW, irc_msg->params[1], ANSI_RESET);
}

void COMMAND_handle_MODE(const char *nick, const IRC_Message *irc_msg)
{
    const char *color = strcmp(irc_msg->params[0], nick) == 0 ? ANSI_BOLD_HIGH_ULINE_CYAN : ANSI_CYAN;
    char *modeargs = HELPER_concat_params(irc_msg, 2);

    if (*modeargs == '\0')
        HELPER_msg_printer("%s%s set mode %s for %s%s\n", color, irc_msg->source, irc_msg->params[1], irc_msg->params[0], ANSI_RESET);
    else
        HELPER_msg_printer("%s%s set mode %s %s for %s%s\n", color, irc_msg->source, irc_msg->params[1], modeargs, irc_msg->params[0], ANSI_RESET);

    free(modeargs);
}

void COMMAND_handle_TOPIC(const IRC_Message *irc_msg)
{
    if (*irc_msg->params[1] == '\0')
    {
        HELPER_msg_printer("%sThe topic for channel %s was cleared%s\n", ANSI_CYAN, irc_msg->params[0], ANSI_RESET);
        return;
    }

    HELPER_msg_printer("%sThe topic for channel %s was changed to \"%s\"%s\n", ANSI_CYAN, irc_msg->params[0], irc_msg->params[1], ANSI_RESET);
}

void COMMAND_handle_INVITE(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%sYou were invited to the channel %s (by %s)%s\n", ANSI_BOLD_HIGH_ULINE_CYAN, irc_msg->params[0], irc_msg->source, ANSI_RESET);
}

void COMMAND_handle_KICK(const char *nick, const IRC_Message *irc_msg)
{
    const char *color = strcmp(irc_msg->params[1], nick) == 0 ? ANSI_BOLD_HIGH_ULINE_CYAN : ANSI_CYAN;

    if (irc_msg->params[2] != NULL)
        HELPER_msg_printer("%s%s was kicked from channel %s by %s (%s)%s\n", color, irc_msg->params[1], irc_msg->params[0], irc_msg->source, irc_msg->params[2], ANSI_RESET);
    else
        HELPER_msg_printer("%s%s was kicked from channel %s by %s%s\n", color, irc_msg->params[1], irc_msg->params[0], irc_msg->source, ANSI_RESET);
}

void COMMAND_handle_PING(SSL *ssl, const IRC_Message *irc_msg)
{
    CORE_ssl_write(ssl, "PONG %s\r\n", irc_msg->params[0]);
}

void COMMAND_handle_ERROR(const IRC_Message *irc_msg)
{
    HELPER_msg_printer(("%sFatal error message received from server (%s)%s\n"), ANSI_BOLD_HIGH_ULINE_CYAN, irc_msg->params[0], ANSI_RESET);
}

void COMMAND_handle_AWAY(const IRC_Message *irc_msg)
{
    if (irc_msg->params[0] != NULL && *irc_msg->params[0] != '\0')
    {
        HELPER_msg_printer(("%s%s marked themselves as away (%s)%s\n"), ANSI_BOLD_HIGH_ULINE_CYAN, irc_msg->source, irc_msg->params[0], ANSI_RESET);
    }
    else
    {
        HELPER_msg_printer(("%s%s is no longer away%s\n"), ANSI_BOLD_HIGH_ULINE_CYAN, irc_msg->source, ANSI_RESET);
    }
}

void COMMAND_handle_WALLOPS(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%sWALLOPS message \"%s\" (by %s)%s\n", ANSI_BOLD_HIGH_ULINE_CYAN, irc_msg->params[0], irc_msg->source, ANSI_RESET);
}
