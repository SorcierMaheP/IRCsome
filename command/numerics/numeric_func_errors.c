#include "command/numerics/numeric_def.h"
#include "command/command.h"

void NUMERIC_handle_UNKNOWNERROR(IRC_Message *irc_msg) {}
void NUMERIC_handle_NOSUCHNICK(IRC_Message *irc_msg) {}
void NUMERIC_handle_NOSUCHSERVER(IRC_Message *irc_msg) {}
void NUMERIC_handle_NOSUCHCHANNEL(IRC_Message *irc_msg) {}
void NUMERIC_handle_CANNOTSENDTOCHAN(IRC_Message *irc_msg) {}
void NUMERIC_handle_TOOMANYCHANNELS(IRC_Message *irc_msg) {}
void NUMERIC_handle_WASNOSUCHNICK(IRC_Message *irc_msg) {}

void NUMERIC_handle_NOORIGIN(IRC_Message *irc_msg) {}
void NUMERIC_handle_NORECIPIENT(IRC_Message *irc_msg) {}
void NUMERIC_handle_NOTEXTTOSEND(IRC_Message *irc_msg) {}
void NUMERIC_handle_INPUTTOOLONG(IRC_Message *irc_msg) {}

void NUMERIC_handle_UNKNOWNCOMMAND(IRC_Message *irc_msg) {}
void NUMERIC_handle_NOMOTD(IRC_Message *irc_msg) {}

void NUMERIC_handle_NONICKNAMEGIVEN(IRC_Message *irc_msg) {}
void NUMERIC_handle_ERRONEUSNICKNAME(IRC_Message *irc_msg) {}
void NUMERIC_handle_NICKNAMEINUSE(IRC_Message *irc_msg) {}
void NUMERIC_handle_NICKCOLLISION(IRC_Message *irc_msg) {}

void NUMERIC_handle_USERNOTINCHANNEL(IRC_Message *irc_msg) {}
void NUMERIC_handle_NOTONCHANNEL(IRC_Message *irc_msg) {}
void NUMERIC_handle_USERONCHANNEL(IRC_Message *irc_msg) {}

void NUMERIC_handle_NOTREGISTERED(IRC_Message *irc_msg) {}
void NUMERIC_handle_NEEDMOREPARAMS(IRC_Message *irc_msg) {}
void NUMERIC_handle_ALREADYREGISTERED(IRC_Message *irc_msg) {}
void NUMERIC_handle_PASSWDMISMATCH(IRC_Message *irc_msg) {}
void NUMERIC_handle_YOUREBANNEDCREEP(IRC_Message *irc_msg) {}

void NUMERIC_handle_CHANNELISFULL(IRC_Message *irc_msg) {}
void NUMERIC_handle_UNKNOWNMODE(IRC_Message *irc_msg) {}
void NUMERIC_handle_INVITEONLYCHAN(IRC_Message *irc_msg) {}
void NUMERIC_handle_BANNEDFROMCHAN(IRC_Message *irc_msg) {}
void NUMERIC_handle_BADCHANNELKEY(IRC_Message *irc_msg) {}
void NUMERIC_handle_BADCHANMASK(IRC_Message *irc_msg) {}

void NUMERIC_handle_NOPRIVILEGES(IRC_Message *irc_msg) {}
void NUMERIC_handle_CHANOPRIVSNEEDED(IRC_Message *irc_msg) {}
void NUMERIC_handle_CANTKILLSERVER(IRC_Message *irc_msg) {}
void NUMERIC_handle_NOOPERHOST(IRC_Message *irc_msg) {}

void NUMERIC_handle_UMODEUNKNOWNFLAG(IRC_Message *irc_msg) {}
void NUMERIC_handle_USERSDONTMATCH(IRC_Message *irc_msg) {}
void NUMERIC_handle_HELPNOTFOUND(IRC_Message *irc_msg) {}
void NUMERIC_handle_INVALIDKEY(IRC_Message *irc_msg) {}

void NUMERIC_handle_ERRSTARTTLS(IRC_Message *irc_msg) {}
void NUMERIC_handle_INVALIDMODEPARAM(IRC_Message *irc_msg) {}
void NUMERIC_handle_NOPRIVS(IRC_Message *irc_msg) {}

void NUMERIC_handle_NICKLOCKED(IRC_Message *irc_msg) {}
void NUMERIC_handle_SASLFAIL(IRC_Message *irc_msg) {}
void NUMERIC_handle_SASLTOOLONG(IRC_Message *irc_msg) {}
void NUMERIC_handle_SASLABORTED(IRC_Message *irc_msg) {}
void NUMERIC_handle_SASLALREADY(IRC_Message *irc_msg) {}