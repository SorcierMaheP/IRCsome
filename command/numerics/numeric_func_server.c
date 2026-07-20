#include "command/numerics/numeric_def.h"
#include "command/command.h"

//============================
void NUMERIC_handle_WELCOME(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_YOURHOST(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_CREATED(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_MYINFO(const IRC_Message *irc_msg)
{
    if (irc_msg->params_len > 5)
    {
        HELPER_msg_printer("%s%s, %s, %s, %s, %s%s\n",
                           ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], irc_msg->params[3], irc_msg->params[4], irc_msg->params[5], ANSI_RESET);
        return;
    }
    HELPER_msg_printer("%s%s, %s, %s, %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], irc_msg->params[3], irc_msg->params[4], ANSI_RESET);
}

void NUMERIC_handle_ISUPPORT(const IRC_Message *irc_msg)
{
    char *params = HELPER_concat_params(irc_msg, 1);
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, params, ANSI_RESET);
    free(params);
}

void NUMERIC_handle_BOUNCE(const IRC_Message *irc_msg)
{
    if (irc_msg->params_len > 3)
    {
        HELPER_msg_printer("%sPlease reconnect to %s:%s (%s)%s\n",
                           ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], irc_msg->params[3], ANSI_RESET);
        return;
    }
    HELPER_msg_printer("%sPlease reconnect to %s:%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

//============================

void NUMERIC_handle_STATSCOMMANDS(const IRC_Message *irc_msg)
{
    if (irc_msg->params_len > 2)
    {
        HELPER_msg_printer("%s%s Count: %s Byte Count: %s Remote Count: %s%s\n",
                           ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], irc_msg->params[3], irc_msg->params[4], ANSI_RESET);
        return;
    }
    HELPER_msg_printer("%s%s Count: %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

void NUMERIC_handle_ENDOFSTATS(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s (%s)%s\n",
                       ANSI_CYAN, irc_msg->params[2], irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_UMODEIS(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%sSet user modes: %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_STATSUPTIME(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}
//============================

void NUMERIC_handle_LUSERCLIENT(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_LUSEROP(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

void NUMERIC_handle_LUSERUNKNOWN(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

void NUMERIC_handle_LUSERCHANNELS(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

void NUMERIC_handle_LUSERME(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

//============================

void NUMERIC_handle_ADMINME(const IRC_Message *irc_msg)
{
    char *server = irc_msg->params_len > 2 ? irc_msg->params[1] : irc_msg->source;
    HELPER_msg_printer("%s%s: %s%s\n",
                       ANSI_CYAN, server, irc_msg->params[irc_msg->params_len - 1], ANSI_RESET);
}

void NUMERIC_handle_ADMINLOC1(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_ADMINLOC2(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_ADMINEMAIL(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_TRYAGAIN(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s: %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

void NUMERIC_handle_LOCALUSERS(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[irc_msg->params_len - 1], ANSI_RESET);
}

void NUMERIC_handle_GLOBALUSERS(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[irc_msg->params_len - 1], ANSI_RESET);
}

//============================

void NUMERIC_handle_VERSION(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%sVersion: %s for %s (%s)%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], irc_msg->params[3], ANSI_RESET);
}

void NUMERIC_handle_INFO(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_MOTD(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_BOLD_HIGH_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_ENDOFINFO(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_MOTDSTART(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_BOLD_HIGH_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_ENDOFMOTD(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_BOLD_HIGH_CYAN, irc_msg->params[1], ANSI_RESET);
}

//============================

void NUMERIC_handle_YOUREOPER(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_REHASHING(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s: %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

void NUMERIC_handle_TIME(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%sTime for %s: %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[irc_msg->params_len - 1], ANSI_RESET);
}

//============================