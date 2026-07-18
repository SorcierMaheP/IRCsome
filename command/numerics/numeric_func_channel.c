#include "command/numerics/numeric_def.h"
#include "command/command.h"

void NUMERIC_handle_LISTSTART(IRC_Message *irc_msg) {}
void NUMERIC_handle_LIST(IRC_Message *irc_msg) {}
void NUMERIC_handle_LISTEND(IRC_Message *irc_msg) {}
void NUMERIC_handle_CHANNELMODEIS(IRC_Message *irc_msg) {}
void NUMERIC_handle_CREATIONTIME(IRC_Message *irc_msg) {}

void NUMERIC_handle_NOTOPIC(IRC_Message *irc_msg) {}
void NUMERIC_handle_TOPIC(IRC_Message *irc_msg) {}
void NUMERIC_handle_TOPICWHOTIME(IRC_Message *irc_msg) {}

void NUMERIC_handle_INVITELIST(IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFINVITELIST(IRC_Message *irc_msg) {}
void NUMERIC_handle_INVITING(IRC_Message *irc_msg) {}

void NUMERIC_handle_INVEXLIST(IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFINVEXLIST(IRC_Message *irc_msg) {}
void NUMERIC_handle_EXCEPTLIST(IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFEXCEPTLIST(IRC_Message *irc_msg) {}

void NUMERIC_handle_NAMREPLY(IRC_Message *irc_msg) {}
void NUMERIC_handle_LINKS(IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFLINKS(IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFNAMES(IRC_Message *irc_msg) {}
void NUMERIC_handle_BANLIST(IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFBANLIST(IRC_Message *irc_msg) {}