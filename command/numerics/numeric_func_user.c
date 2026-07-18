#include "command/numerics/numeric_def.h"
#include "command/command.h"

void NUMERIC_handle_NONE(IRC_Message *irc_msg) {}
void NUMERIC_handle_AWAY(IRC_Message *irc_msg) {}
void NUMERIC_handle_USERHOST(IRC_Message *irc_msg) {}
void NUMERIC_handle_UNAWAY(IRC_Message *irc_msg) {}
void NUMERIC_handle_NOWAWAY(IRC_Message *irc_msg) {}

void NUMERIC_handle_WHOISREGNICK(IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISUSER(IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISSERVER(IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISOPERATOR(IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOWASUSER(IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFWHO(IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISIDLE(IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFWHOIS(IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISCHANNELS(IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISSPECIAL(IRC_Message *irc_msg) {}

void NUMERIC_handle_WHOISACCOUNT(IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISACTUALLY(IRC_Message *irc_msg) {}

void NUMERIC_handle_WHOREPLY(IRC_Message *irc_msg) {}

void NUMERIC_handle_ENDOFWHOWAS(IRC_Message *irc_msg) {}

void NUMERIC_handle_WHOISCERTFP(IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISHOST(IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISMODES(IRC_Message *irc_msg) {}

void NUMERIC_handle_RPLSTARTTLS(IRC_Message *irc_msg) {}
void NUMERIC_handle_WHOISSECURE(IRC_Message *irc_msg) {}

void NUMERIC_handle_HELPSTART(IRC_Message *irc_msg) {}
void NUMERIC_handle_HELPTXT(IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFHELP(IRC_Message *irc_msg) {}

void NUMERIC_handle_LOGGEDIN(IRC_Message *irc_msg) {}
void NUMERIC_handle_LOGGEDOUT(IRC_Message *irc_msg) {}
void NUMERIC_handle_SASLSUCCESS(IRC_Message *irc_msg) {}
void NUMERIC_handle_SASLMECHS(IRC_Message *irc_msg) {}