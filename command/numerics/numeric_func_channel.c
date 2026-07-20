#include "command/numerics/numeric_def.h"
#include "command/command.h"

void NUMERIC_handle_LISTSTART(const IRC_Message *irc_msg) {}
void NUMERIC_handle_LIST(const IRC_Message *irc_msg) {}
void NUMERIC_handle_LISTEND(const IRC_Message *irc_msg) {}
void NUMERIC_handle_CHANNELMODEIS(const IRC_Message *irc_msg) {}
void NUMERIC_handle_CREATIONTIME(const IRC_Message *irc_msg) {}

void NUMERIC_handle_NOTOPIC(const IRC_Message *irc_msg) {}
void NUMERIC_handle_TOPIC(const IRC_Message *irc_msg) {}
void NUMERIC_handle_TOPICWHOTIME(const IRC_Message *irc_msg) {}

void NUMERIC_handle_INVITELIST(const IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFINVITELIST(const IRC_Message *irc_msg) {}
void NUMERIC_handle_INVITING(const IRC_Message *irc_msg) {}

void NUMERIC_handle_INVEXLIST(const IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFINVEXLIST(const IRC_Message *irc_msg) {}
void NUMERIC_handle_EXCEPTLIST(const IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFEXCEPTLIST(const IRC_Message *irc_msg) {}

void NUMERIC_handle_NAMREPLY(const IRC_Message *irc_msg) {}
void NUMERIC_handle_LINKS(const IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFLINKS(const IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFNAMES(const IRC_Message *irc_msg) {}
void NUMERIC_handle_BANLIST(const IRC_Message *irc_msg) {}
void NUMERIC_handle_ENDOFBANLIST(const IRC_Message *irc_msg) {}