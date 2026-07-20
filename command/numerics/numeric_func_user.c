#include "command/numerics/numeric_def.h"
#include "command/command.h"

//============================

void NUMERIC_handle_NONE(const IRC_Message *irc_msg)
{
    (void)irc_msg;
}

void NUMERIC_handle_AWAY(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s is away (%s)%s\n",
                       ANSI_CYAN, irc_msg->params[1], irc_msg->params[2], ANSI_RESET);
}

void NUMERIC_handle_USERHOST(const IRC_Message *irc_msg)
{
    if (irc_msg->params_len > 1)
    {
        for (size_t i = 1; i < irc_msg->params_len && *irc_msg->params[i] != '\0'; i++)
        {
            char *operator_str;
            char *away_str;

            char *equal = strchr(irc_msg->params[i], '=');

            if (equal)
            {
                operator_str = *(equal - 1) == '*' ? "IRC operator" : "not IRC operator";
                away_str = *(equal + 1) == '-' ? "away" : "not away";

                /* Nickname */
                size_t nick_len = equal - irc_msg->params[i];
                if (strcmp(operator_str, "IRC operator") == 0)
                    nick_len--;

                char nickname[64];
                memcpy(nickname, irc_msg->params[i], nick_len);
                nickname[nick_len] = '\0';

                /* Hostname */
                char *hostname = equal + 2;

                HELPER_msg_printer("%s%s (%s, %s) has hostname %s%s\n",
                                   ANSI_CYAN, nickname, operator_str, away_str, hostname, ANSI_RESET);
            }
            else
            {
                CUST_ERROR("Malformed numeric found in message received from server");
                exit(EXIT_FAILURE);
            }
        }
    }
    else
        HELPER_msg_printer("%sNo results for USERHOST command%s\n",
                           ANSI_CYAN, ANSI_RESET);
}

void NUMERIC_handle_UNAWAY(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

void NUMERIC_handle_NOWAWAY(const IRC_Message *irc_msg)
{
    HELPER_msg_printer("%s%s%s\n",
                       ANSI_CYAN, irc_msg->params[1], ANSI_RESET);
}

//============================

void NUMERIC_handle_WHOISREGNICK(const IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISUSER(const IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISSERVER(const IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISOPERATOR(const IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOWASUSER(const IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFWHO(const IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISIDLE(const IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFWHOIS(const IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISCHANNELS(const IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISSPECIAL(const IRC_Message *irc_msg) {}

//============================

void NUMERIC_handle_WHOISACCOUNT(const IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISACTUALLY(const IRC_Message *irc_msg) {}

//============================

void NUMERIC_handle_WHOREPLY(const IRC_Message *irc_msg) {}

//============================

void NUMERIC_handle_ENDOFWHOWAS(const IRC_Message *irc_msg) {}

//============================

void NUMERIC_handle_WHOISCERTFP(const IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISHOST(const IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISMODES(const IRC_Message *irc_msg) {}

//============================

void NUMERIC_handle_RPLSTARTTLS(const IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISSECURE(const IRC_Message *irc_msg) {}

//============================

void NUMERIC_handle_HELPSTART(const IRC_Message *irc_msg) {}
void NUMERIC_handle_HELPTXT(const IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFHELP(const IRC_Message *irc_msg) {}

//============================

void NUMERIC_handle_LOGGEDIN(const IRC_Message *irc_msg) {}
void NUMERIC_handle_LOGGEDOUT(const IRC_Message *irc_msg) {}
void NUMERIC_handle_SASLSUCCESS(const IRC_Message *irc_msg) {}
void NUMERIC_handle_SASLMECHS(const IRC_Message *irc_msg) {}

//============================