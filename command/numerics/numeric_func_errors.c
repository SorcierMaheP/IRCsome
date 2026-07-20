#include "command/numerics/numeric_def.h"
#include "command/command.h"

void NUMERIC_handle_UNKNOWNERROR(const IRC_Message *irc_msg) {}
void NUMERIC_handle_NOSUCHNICK(const IRC_Message *irc_msg) {}
void NUMERIC_handle_NOSUCHSERVER(const IRC_Message *irc_msg) {}
void NUMERIC_handle_NOSUCHCHANNEL(const IRC_Message *irc_msg) {}
void NUMERIC_handle_CANNOTSENDTOCHAN(const IRC_Message *irc_msg) {}
void NUMERIC_handle_TOOMANYCHANNELS(const IRC_Message *irc_msg) {}
void NUMERIC_handle_WASNOSUCHNICK(const IRC_Message *irc_msg) {}

void NUMERIC_handle_NOORIGIN(const IRC_Message *irc_msg) {}
void NUMERIC_handle_NORECIPIENT(const IRC_Message *irc_msg) {}
void NUMERIC_handle_NOTEXTTOSEND(const IRC_Message *irc_msg) {}
void NUMERIC_handle_INPUTTOOLONG(const IRC_Message *irc_msg) {}

void NUMERIC_handle_UNKNOWNCOMMAND(const IRC_Message *irc_msg) {}
void NUMERIC_handle_NOMOTD(const IRC_Message *irc_msg) {}

void NUMERIC_handle_NONICKNAMEGIVEN(const IRC_Message *irc_msg) {}
void NUMERIC_handle_ERRONEUSNICKNAME(const IRC_Message *irc_msg) {}
void NUMERIC_handle_NICKNAMEINUSE(const IRC_Message *irc_msg) {}
void NUMERIC_handle_NICKCOLLISION(const IRC_Message *irc_msg) {}

void NUMERIC_handle_USERNOTINCHANNEL(const IRC_Message *irc_msg) {}
void NUMERIC_handle_NOTONCHANNEL(const IRC_Message *irc_msg) {}
void NUMERIC_handle_USERONCHANNEL(const IRC_Message *irc_msg) {}

void NUMERIC_handle_NOTREGISTERED(const IRC_Message *irc_msg) {}
void NUMERIC_handle_NEEDMOREPARAMS(const IRC_Message *irc_msg) {}
void NUMERIC_handle_ALREADYREGISTERED(const IRC_Message *irc_msg) {}
void NUMERIC_handle_PASSWDMISMATCH(const IRC_Message *irc_msg) {}
void NUMERIC_handle_YOUREBANNEDCREEP(const IRC_Message *irc_msg) {}

void NUMERIC_handle_CHANNELISFULL(const IRC_Message *irc_msg) {}
void NUMERIC_handle_UNKNOWNMODE(const IRC_Message *irc_msg) {}
void NUMERIC_handle_INVITEONLYCHAN(const IRC_Message *irc_msg) {}
void NUMERIC_handle_BANNEDFROMCHAN(const IRC_Message *irc_msg) {}
void NUMERIC_handle_BADCHANNELKEY(const IRC_Message *irc_msg) {}
void NUMERIC_handle_BADCHANMASK(const IRC_Message *irc_msg) {}

void NUMERIC_handle_NOPRIVILEGES(const IRC_Message *irc_msg) {}
void NUMERIC_handle_CHANOPRIVSNEEDED(const IRC_Message *irc_msg) {}
void NUMERIC_handle_CANTKILLSERVER(const IRC_Message *irc_msg) {}
void NUMERIC_handle_NOOPERHOST(const IRC_Message *irc_msg) {}

void NUMERIC_handle_UMODEUNKNOWNFLAG(const IRC_Message *irc_msg) {}
void NUMERIC_handle_USERSDONTMATCH(const IRC_Message *irc_msg) {}
void NUMERIC_handle_HELPNOTFOUND(const IRC_Message *irc_msg) {}
void NUMERIC_handle_INVALIDKEY(const IRC_Message *irc_msg) {}

void NUMERIC_handle_ERRSTARTTLS(const IRC_Message *irc_msg) {}
void NUMERIC_handle_INVALIDMODEPARAM(const IRC_Message *irc_msg) {}
void NUMERIC_handle_NOPRIVS(const IRC_Message *irc_msg) {}

void NUMERIC_handle_NICKLOCKED(const IRC_Message *irc_msg) {}
void NUMERIC_handle_SASLFAIL(const IRC_Message *irc_msg) {}
void NUMERIC_handle_SASLTOOLONG(const IRC_Message *irc_msg) {}
void NUMERIC_handle_SASLABORTED(const IRC_Message *irc_msg) {}
void NUMERIC_handle_SASLALREADY(const IRC_Message *irc_msg) {}