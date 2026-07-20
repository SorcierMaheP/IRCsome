#include "command/command.h"
#include "command/numerics/numeric_def.h"

#include <stdlib.h>

void NUMERIC_irc_dispatch(Client *client, IRC_Message *irc_msg)
{
    char *numeric = irc_msg->command;
    client = client;
    switch ((IRC_Numeric)atoi(numeric))
    {
    /* 1. Server */
    case RPL_WELCOME:
        NUMERIC_handle_WELCOME(irc_msg);
        break;
    case RPL_YOURHOST:
        NUMERIC_handle_YOURHOST(irc_msg);
        break;
    case RPL_CREATED:
        NUMERIC_handle_CREATED(irc_msg);
        break;
    case RPL_MYINFO:
        NUMERIC_handle_MYINFO(irc_msg);
        break;
    case RPL_ISUPPORT:
        NUMERIC_handle_ISUPPORT(irc_msg);
        break;
    case RPL_BOUNCE:
        NUMERIC_handle_BOUNCE(irc_msg);
        break;

    case RPL_STATSCOMMANDS:
        NUMERIC_handle_STATSCOMMANDS(irc_msg);
        break;
    case RPL_ENDOFSTATS:
        NUMERIC_handle_ENDOFSTATS(irc_msg);
        break;
    case RPL_UMODEIS:
        NUMERIC_handle_UMODEIS(irc_msg);
        break;
    case RPL_STATSUPTIME:
        NUMERIC_handle_STATSUPTIME(irc_msg);
        break;

    case RPL_LUSERCLIENT:
        NUMERIC_handle_LUSERCLIENT(irc_msg);
        break;
    case RPL_LUSEROP:
        NUMERIC_handle_LUSEROP(irc_msg);
        break;
    case RPL_LUSERUNKNOWN:
        NUMERIC_handle_LUSERUNKNOWN(irc_msg);
        break;
    case RPL_LUSERCHANNELS:
        NUMERIC_handle_LUSERCHANNELS(irc_msg);
        break;
    case RPL_LUSERME:
        NUMERIC_handle_LUSERME(irc_msg);
        break;

    case RPL_ADMINME:
        NUMERIC_handle_ADMINME(irc_msg);
        break;
    case RPL_ADMINLOC1:
        NUMERIC_handle_ADMINLOC1(irc_msg);
        break;
    case RPL_ADMINLOC2:
        NUMERIC_handle_ADMINLOC2(irc_msg);
        break;
    case RPL_ADMINEMAIL:
        NUMERIC_handle_ADMINEMAIL(irc_msg);
        break;
    case RPL_TRYAGAIN:
        NUMERIC_handle_TRYAGAIN(irc_msg);
        break;
    case RPL_LOCALUSERS:
        NUMERIC_handle_LOCALUSERS(irc_msg);
        break;
    case RPL_GLOBALUSERS:
        NUMERIC_handle_GLOBALUSERS(irc_msg);
        break;

    case RPL_VERSION:
        NUMERIC_handle_VERSION(irc_msg);
        break;
    case RPL_INFO:
        NUMERIC_handle_INFO(irc_msg);
        break;
    case RPL_MOTD:
        NUMERIC_handle_MOTD(irc_msg);
        break;
    case RPL_ENDOFINFO:
        NUMERIC_handle_ENDOFINFO(irc_msg);
        break;
    case RPL_MOTDSTART:
        NUMERIC_handle_MOTDSTART(irc_msg);
        break;
    case RPL_ENDOFMOTD:
        NUMERIC_handle_ENDOFMOTD(irc_msg);
        break;

    case RPL_YOUREOPER:
        NUMERIC_handle_YOUREOPER(irc_msg);
        break;
    case RPL_REHASHING:
        NUMERIC_handle_REHASHING(irc_msg);
        break;
    case RPL_TIME:
        NUMERIC_handle_TIME(irc_msg);
        break;

    /* 2. User */
    case RPL_NONE:
        NUMERIC_handle_NONE(irc_msg);
        break;
    case RPL_AWAY:
        NUMERIC_handle_AWAY(irc_msg);
        break;
    case RPL_USERHOST:
        NUMERIC_handle_USERHOST(irc_msg);
        break;
    case RPL_UNAWAY:
        NUMERIC_handle_UNAWAY(irc_msg);
        break;
    case RPL_NOWAWAY:
        NUMERIC_handle_NOWAWAY(irc_msg);
        break;

    case RPL_WHOISREGNICK:
        NUMERIC_handle_WHOISREGNICK(irc_msg);
        break;
    case RPL_WHOISUSER:
        NUMERIC_handle_WHOISUSER(irc_msg);
        break;
    case RPL_WHOISSERVER:
        NUMERIC_handle_WHOISSERVER(irc_msg);
        break;
    case RPL_WHOISOPERATOR:
        NUMERIC_handle_WHOISOPERATOR(irc_msg);
        break;
    case RPL_WHOWASUSER:
        NUMERIC_handle_WHOWASUSER(irc_msg);
        break;
    case RPL_ENDOFWHO:
        NUMERIC_handle_ENDOFWHO(irc_msg);
        break;
    case RPL_WHOISIDLE:
        NUMERIC_handle_WHOISIDLE(irc_msg);
        break;
    case RPL_ENDOFWHOIS:
        NUMERIC_handle_ENDOFWHOIS(irc_msg);
        break;
    case RPL_WHOISCHANNELS:
        NUMERIC_handle_WHOISCHANNELS(irc_msg);
        break;
    case RPL_WHOISSPECIAL:
        NUMERIC_handle_WHOISSPECIAL(irc_msg);
        break;

    case RPL_WHOISACCOUNT:
        NUMERIC_handle_WHOISACCOUNT(irc_msg);
        break;
    case RPL_WHOISACTUALLY:
        NUMERIC_handle_WHOISACTUALLY(irc_msg);
        break;

    case RPL_WHOREPLY:
        NUMERIC_handle_WHOREPLY(irc_msg);
        break;

    case RPL_ENDOFWHOWAS:
        NUMERIC_handle_ENDOFWHOWAS(irc_msg);
        break;

    case RPL_WHOISCERTFP:
        NUMERIC_handle_WHOISCERTFP(irc_msg);
        break;
    case RPL_WHOISHOST:
        NUMERIC_handle_WHOISHOST(irc_msg);
        break;
    case RPL_WHOISMODES:
        NUMERIC_handle_WHOISMODES(irc_msg);
        break;

    case RPL_STARTTLS:
        NUMERIC_handle_RPLSTARTTLS(irc_msg);
        break;
    case RPL_WHOISSECURE:
        NUMERIC_handle_WHOISSECURE(irc_msg);
        break;

    case RPL_HELPSTART:
        NUMERIC_handle_HELPSTART(irc_msg);
        break;
    case RPL_HELPTXT:
        NUMERIC_handle_HELPTXT(irc_msg);
        break;
    case RPL_ENDOFHELP:
        NUMERIC_handle_ENDOFHELP(irc_msg);
        break;

    case RPL_LOGGEDIN:
        NUMERIC_handle_LOGGEDIN(irc_msg);
        break;
    case RPL_LOGGEDOUT:
        NUMERIC_handle_LOGGEDOUT(irc_msg);
        break;
    case RPL_SASLSUCCESS:
        NUMERIC_handle_SASLSUCCESS(irc_msg);
        break;
    case RPL_SASLMECHS:
        NUMERIC_handle_SASLMECHS(irc_msg);
        break;

        // /* 3. Channel */
        // case RPL_LISTSTART:
        //     NUMERIC_handle_LISTSTART(irc_msg);
        //     break;
        // case RPL_LIST:
        //     NUMERIC_handle_LIST(irc_msg);
        //     break;
        // case RPL_LISTEND:
        //     NUMERIC_handle_LISTEND(irc_msg);
        //     break;
        // case RPL_CHANNELMODEIS:
        //     NUMERIC_handle_CHANNELMODEIS(irc_msg);
        //     break;
        // case RPL_CREATIONTIME:
        //     NUMERIC_handle_CREATIONTIME(irc_msg);
        //     break;

        // case RPL_NOTOPIC:
        //     NUMERIC_handle_NOTOPIC(irc_msg);
        //     break;
        // case RPL_TOPIC:
        //     NUMERIC_handle_TOPIC(irc_msg);
        //     break;
        // case RPL_TOPICWHOTIME:
        //     NUMERIC_handle_TOPICWHOTIME(irc_msg);
        //     break;

        // case RPL_INVITELIST:
        //     NUMERIC_handle_INVITELIST(irc_msg);
        //     break;
        // case RPL_ENDOFINVITELIST:
        //     NUMERIC_handle_ENDOFINVITELIST(irc_msg);
        //     break;
        // case RPL_INVITING:
        //     NUMERIC_handle_INVITING(irc_msg);
        //     break;

        // case RPL_INVEXLIST:
        //     NUMERIC_handle_INVEXLIST(irc_msg);
        //     break;
        // case RPL_ENDOFINVEXLIST:
        //     NUMERIC_handle_ENDOFINVEXLIST(irc_msg);
        //     break;
        // case RPL_EXCEPTLIST:
        //     NUMERIC_handle_EXCEPTLIST(irc_msg);
        //     break;
        // case RPL_ENDOFEXCEPTLIST:
        //     NUMERIC_handle_ENDOFEXCEPTLIST(irc_msg);
        //     break;

        // case RPL_NAMREPLY:
        //     NUMERIC_handle_NAMREPLY(irc_msg);
        //     break;
        // case RPL_LINKS:
        //     NUMERIC_handle_LINKS(irc_msg);
        //     break;
        // case RPL_ENDOFLINKS:
        //     NUMERIC_handle_ENDOFLINKS(irc_msg);
        //     break;
        // case RPL_ENDOFNAMES:
        //     NUMERIC_handle_ENDOFNAMES(irc_msg);
        //     break;
        // case RPL_BANLIST:
        //     NUMERIC_handle_BANLIST(irc_msg);
        //     break;
        // case RPL_ENDOFBANLIST:
        //     NUMERIC_handle_ENDOFBANLIST(irc_msg);
        //     break;

        // /* 4. Errors */
        // case ERR_UNKNOWNERROR:
        //     NUMERIC_handle_UNKNOWNERROR(irc_msg);
        //     break;
        // case ERR_NOSUCHNICK:
        //     NUMERIC_handle_NOSUCHNICK(irc_msg);
        //     break;
        // case ERR_NOSUCHSERVER:
        //     NUMERIC_handle_NOSUCHSERVER(irc_msg);
        //     break;
        // case ERR_NOSUCHCHANNEL:
        //     NUMERIC_handle_NOSUCHCHANNEL(irc_msg);
        //     break;
        // case ERR_CANNOTSENDTOCHAN:
        //     NUMERIC_handle_CANNOTSENDTOCHAN(irc_msg);
        //     break;
        // case ERR_TOOMANYCHANNELS:
        //     NUMERIC_handle_TOOMANYCHANNELS(irc_msg);
        //     break;
        // case ERR_WASNOSUCHNICK:
        //     NUMERIC_handle_WASNOSUCHNICK(irc_msg);
        //     break;

        // case ERR_NOORIGIN:
        //     NUMERIC_handle_NOORIGIN(irc_msg);
        //     break;
        // case ERR_NORECIPIENT:
        //     NUMERIC_handle_NORECIPIENT(irc_msg);
        //     break;
        // case ERR_NOTEXTTOSEND:
        //     NUMERIC_handle_NOTEXTTOSEND(irc_msg);
        //     break;
        // case ERR_INPUTTOOLONG:
        //     NUMERIC_handle_INPUTTOOLONG(irc_msg);
        //     break;

        // case ERR_UNKNOWNCOMMAND:
        //     NUMERIC_handle_UNKNOWNCOMMAND(irc_msg);
        //     break;
        // case ERR_NOMOTD:
        //     NUMERIC_handle_NOMOTD(irc_msg);
        //     break;

        // case ERR_NONICKNAMEGIVEN:
        //     NUMERIC_handle_NONICKNAMEGIVEN(irc_msg);
        //     break;
        // case ERR_ERRONEUSNICKNAME:
        //     NUMERIC_handle_ERRONEUSNICKNAME(irc_msg);
        //     break;
        // case ERR_NICKNAMEINUSE:
        //     NUMERIC_handle_NICKNAMEINUSE(irc_msg);
        //     break;
        // case ERR_NICKCOLLISION:
        //     NUMERIC_handle_NICKCOLLISION(irc_msg);
        //     break;

        // case ERR_USERNOTINCHANNEL:
        //     NUMERIC_handle_USERNOTINCHANNEL(irc_msg);
        //     break;
        // case ERR_NOTONCHANNEL:
        //     NUMERIC_handle_NOTONCHANNEL(irc_msg);
        //     break;
        // case ERR_USERONCHANNEL:
        //     NUMERIC_handle_USERONCHANNEL(irc_msg);
        //     break;

        // case ERR_NOTREGISTERED:
        //     NUMERIC_handle_NOTREGISTERED(irc_msg);
        //     break;
        // case ERR_NEEDMOREPARAMS:
        //     NUMERIC_handle_NEEDMOREPARAMS(irc_msg);
        //     break;
        // case ERR_ALREADYREGISTERED:
        //     NUMERIC_handle_ALREADYREGISTERED(irc_msg);
        //     break;
        // case ERR_PASSWDMISMATCH:
        //     NUMERIC_handle_PASSWDMISMATCH(irc_msg);
        //     break;
        // case ERR_YOUREBANNEDCREEP:
        //     NUMERIC_handle_YOUREBANNEDCREEP(irc_msg);
        //     break;

        // case ERR_CHANNELISFULL:
        //     NUMERIC_handle_CHANNELISFULL(irc_msg);
        //     break;
        // case ERR_UNKNOWNMODE:
        //     NUMERIC_handle_UNKNOWNMODE(irc_msg);
        //     break;
        // case ERR_INVITEONLYCHAN:
        //     NUMERIC_handle_INVITEONLYCHAN(irc_msg);
        //     break;
        // case ERR_BANNEDFROMCHAN:
        //     NUMERIC_handle_BANNEDFROMCHAN(irc_msg);
        //     break;
        // case ERR_BADCHANNELKEY:
        //     NUMERIC_handle_BADCHANNELKEY(irc_msg);
        //     break;
        // case ERR_BADCHANMASK:
        //     NUMERIC_handle_BADCHANMASK(irc_msg);
        //     break;

        // case ERR_NOPRIVILEGES:
        //     NUMERIC_handle_NOPRIVILEGES(irc_msg);
        //     break;
        // case ERR_CHANOPRIVSNEEDED:
        //     NUMERIC_handle_CHANOPRIVSNEEDED(irc_msg);
        //     break;
        // case ERR_CANTKILLSERVER:
        //     NUMERIC_handle_CANTKILLSERVER(irc_msg);
        //     break;
        // case ERR_NOOPERHOST:
        //     NUMERIC_handle_NOOPERHOST(irc_msg);
        //     break;

        // case ERR_UMODEUNKNOWNFLAG:
        //     NUMERIC_handle_UMODEUNKNOWNFLAG(irc_msg);
        //     break;
        // case ERR_USERSDONTMATCH:
        //     NUMERIC_handle_USERSDONTMATCH(irc_msg);
        //     break;
        // case ERR_HELPNOTFOUND:
        //     NUMERIC_handle_HELPNOTFOUND(irc_msg);
        //     break;
        // case ERR_INVALIDKEY:
        //     NUMERIC_handle_INVALIDKEY(irc_msg);
        //     break;

        // case ERR_STARTTLS:
        //     NUMERIC_handle_ERRSTARTTLS(irc_msg);
        //     break;
        // case ERR_INVALIDMODEPARAM:
        //     NUMERIC_handle_INVALIDMODEPARAM(irc_msg);
        //     break;
        // case ERR_NOPRIVS:
        //     NUMERIC_handle_NOPRIVS(irc_msg);
        //     break;

        // case ERR_NICKLOCKED:
        //     NUMERIC_handle_NICKLOCKED(irc_msg);
        //     break;
        // case ERR_SASLFAIL:
        //     NUMERIC_handle_SASLFAIL(irc_msg);
        //     break;
        // case ERR_SASLTOOLONG:
        //     NUMERIC_handle_SASLTOOLONG(irc_msg);
        //     break;
        // case ERR_SASLABORTED:
        //     NUMERIC_handle_SASLABORTED(irc_msg);
        //     break;
        // case ERR_SASLALREADY:
        //     NUMERIC_handle_SASLALREADY(irc_msg);
        //     break;

    default:
        HELPER_irc_msg_printer(irc_msg);
        break;
    }
}
