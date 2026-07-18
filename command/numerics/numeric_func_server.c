#include "command/numerics/numeric_def.h"
#include "command/command.h"

//============================
void NUMERIC_handle_WELCOME(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_YOURHOST(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_CREATED(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_MYINFO(IRC_Message *irc_msg)
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

void NUMERIC_handle_ISUPPORT(IRC_Message *irc_msg)
{
    char *params = HELPER_concat_params(irc_msg, 1);
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, params, ANSI_RESET);
    free(params);
}

void NUMERIC_handle_BOUNCE(IRC_Message *irc_msg)
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

void NUMERIC_handle_STATSCOMMANDS(IRC_Message *irc_msg)
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

void NUMERIC_handle_ENDOFSTATS(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s (%s)%s\n",
                       ANSI_CYAN, irc_msg->params[2], irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_UMODEIS(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%sSet user modes: %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_STATSUPTIME(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}
//============================

void NUMERIC_handle_LUSERCLIENT(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_LUSEROP(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

void NUMERIC_handle_LUSERUNKNOWN(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

void NUMERIC_handle_LUSERCHANNELS(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

void NUMERIC_handle_LUSERME(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

//============================

void NUMERIC_handle_ADMINME(IRC_Message *irc_msg)
{
    char *server = irc_msg->params_len > 2 ? irc_msg->params[1] : irc_msg->source;
    HELPER_msg_printer("%s%s: %s%s\n",
                       ANSI_CYAN, server, irc_msg->params[irc_msg->params_len - 1], ANSI_RESET);
}

void NUMERIC_handle_ADMINLOC1(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_ADMINLOC2(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_ADMINEMAIL(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_TRYAGAIN(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s: %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

void NUMERIC_handle_LOCALUSERS(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[irc_msg->params_len - 1], ANSI_RESET);
}

void NUMERIC_handle_GLOBALUSERS(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[irc_msg->params_len - 1], ANSI_RESET);
}

//============================

void NUMERIC_handle_VERSION(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%sVersion: %s for %s (%s)%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], irc_msg->params[3], ANSI_RESET);
}

void NUMERIC_handle_INFO(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_MOTD(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_BOLD_HIGH_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_ENDOFINFO(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_MOTDSTART(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_BOLD_HIGH_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_ENDOFMOTD(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_BOLD_HIGH_CYAN, irc_msg->params[1], ANSI_RESET);
}

//============================

void NUMERIC_handle_YOUREOPER(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_REHASHING(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s: %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

void NUMERIC_handle_TIME(IRC_Message *irc_msg)
{
    HELPER_msg_printer("%sTime for %s: %s%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[irc_msg->params_len - 1], ANSI_RESET);
}

//============================