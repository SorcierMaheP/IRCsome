#pragma once

#include "global.h"

typedef enum IRC_Numeric
{
    /* 1. Server */

    RPL_WELCOME = 1,
    RPL_YOURHOST = 2,
    RPL_CREATED = 3,
    RPL_MYINFO = 4,
    RPL_ISUPPORT = 5,
    RPL_BOUNCE = 10,

    RPL_STATSCOMMANDS = 212,
    RPL_ENDOFSTATS = 219,
    RPL_UMODEIS = 221,
    RPL_STATSUPTIME = 242,

    RPL_LUSERCLIENT = 251,
    RPL_LUSEROP = 252,
    RPL_LUSERUNKNOWN = 253,
    RPL_LUSERCHANNELS = 254,
    RPL_LUSERME = 255,

    RPL_ADMINME = 256,
    RPL_ADMINLOC1 = 257,
    RPL_ADMINLOC2 = 258,
    RPL_ADMINEMAIL = 259,
    RPL_TRYAGAIN = 263,
    RPL_LOCALUSERS = 265,
    RPL_GLOBALUSERS = 266,

    RPL_VERSION = 351,
    RPL_INFO = 371,
    RPL_MOTD = 372,
    RPL_ENDOFINFO = 374,
    RPL_MOTDSTART = 375,
    RPL_ENDOFMOTD = 376,

    RPL_YOUREOPER = 381,
    RPL_REHASHING = 382,
    RPL_TIME = 391,

    /* 2. User */

    RPL_NONE = 300,
    RPL_AWAY = 301,
    RPL_USERHOST = 302,
    RPL_UNAWAY = 305,
    RPL_NOWAWAY = 306,

    RPL_WHOISREGNICK = 307,
    RPL_WHOISUSER = 311,
    RPL_WHOISSERVER = 312,
    RPL_WHOISOPERATOR = 313,
    RPL_WHOWASUSER = 314,
    RPL_ENDOFWHO = 315,
    RPL_WHOISIDLE = 317,
    RPL_ENDOFWHOIS = 318,
    RPL_WHOISCHANNELS = 319,
    RPL_WHOISSPECIAL = 320,

    RPL_WHOISACCOUNT = 330,
    RPL_WHOISACTUALLY = 338,

    RPL_WHOREPLY = 352,

    RPL_ENDOFWHOWAS = 369,

    RPL_WHOISCERTFP = 276,
    RPL_WHOISHOST = 378,
    RPL_WHOISMODES = 379,

    RPL_STARTTLS = 670,
    RPL_WHOISSECURE = 671,

    RPL_HELPSTART = 704,
    RPL_HELPTXT = 705,
    RPL_ENDOFHELP = 706,

    RPL_LOGGEDIN = 900,
    RPL_LOGGEDOUT = 901,
    RPL_SASLSUCCESS = 903,
    RPL_SASLMECHS = 908,

    /* 3. Channel */

    RPL_LISTSTART = 321,
    RPL_LIST = 322,
    RPL_LISTEND = 323,
    RPL_CHANNELMODEIS = 324,
    RPL_CREATIONTIME = 329,

    RPL_NOTOPIC = 331,
    RPL_TOPIC = 332,
    RPL_TOPICWHOTIME = 333,

    RPL_INVITELIST = 336,
    RPL_ENDOFINVITELIST = 337,
    RPL_INVITING = 341,

    RPL_INVEXLIST = 346,
    RPL_ENDOFINVEXLIST = 347,
    RPL_EXCEPTLIST = 348,
    RPL_ENDOFEXCEPTLIST = 349,

    RPL_NAMREPLY = 353,
    RPL_LINKS = 364,
    RPL_ENDOFLINKS = 365,
    RPL_ENDOFNAMES = 366,
    RPL_BANLIST = 367,
    RPL_ENDOFBANLIST = 368,

    /* 4. Errors */

    ERR_UNKNOWNERROR = 400,
    ERR_NOSUCHNICK = 401,
    ERR_NOSUCHSERVER = 402,
    ERR_NOSUCHCHANNEL = 403,
    ERR_CANNOTSENDTOCHAN = 404,
    ERR_TOOMANYCHANNELS = 405,
    ERR_WASNOSUCHNICK = 406,

    ERR_NOORIGIN = 409,
    ERR_NORECIPIENT = 411,
    ERR_NOTEXTTOSEND = 412,
    ERR_INPUTTOOLONG = 417,

    ERR_UNKNOWNCOMMAND = 421,
    ERR_NOMOTD = 422,

    ERR_NONICKNAMEGIVEN = 431,
    ERR_ERRONEUSNICKNAME = 432,
    ERR_NICKNAMEINUSE = 433,
    ERR_NICKCOLLISION = 436,

    ERR_USERNOTINCHANNEL = 441,
    ERR_NOTONCHANNEL = 442,
    ERR_USERONCHANNEL = 443,

    ERR_NOTREGISTERED = 451,
    ERR_NEEDMOREPARAMS = 461,
    ERR_ALREADYREGISTERED = 462,
    ERR_PASSWDMISMATCH = 464,
    ERR_YOUREBANNEDCREEP = 465,

    ERR_CHANNELISFULL = 471,
    ERR_UNKNOWNMODE = 472,
    ERR_INVITEONLYCHAN = 473,
    ERR_BANNEDFROMCHAN = 474,
    ERR_BADCHANNELKEY = 475,
    ERR_BADCHANMASK = 476,

    ERR_NOPRIVILEGES = 481,
    ERR_CHANOPRIVSNEEDED = 482,
    ERR_CANTKILLSERVER = 483,
    ERR_NOOPERHOST = 491,

    ERR_UMODEUNKNOWNFLAG = 501,
    ERR_USERSDONTMATCH = 502,
    ERR_HELPNOTFOUND = 524,
    ERR_INVALIDKEY = 525,

    ERR_STARTTLS = 691,
    ERR_INVALIDMODEPARAM = 696,
    ERR_NOPRIVS = 723,

    ERR_NICKLOCKED = 902,
    ERR_SASLFAIL = 904,
    ERR_SASLTOOLONG = 905,
    ERR_SASLABORTED = 906,
    ERR_SASLALREADY = 907,
} IRC_Numeric;

void NUMERIC_handle_WELCOME(const IRC_Message *);
void NUMERIC_handle_YOURHOST(const IRC_Message *);
void NUMERIC_handle_CREATED(const IRC_Message *);
void NUMERIC_handle_MYINFO(const IRC_Message *);
void NUMERIC_handle_ISUPPORT(const IRC_Message *);
void NUMERIC_handle_BOUNCE(const IRC_Message *);

void NUMERIC_handle_STATSCOMMANDS(const IRC_Message *);
void NUMERIC_handle_ENDOFSTATS(const IRC_Message *);
void NUMERIC_handle_UMODEIS(const IRC_Message *);
void NUMERIC_handle_STATSUPTIME(const IRC_Message *);

void NUMERIC_handle_LUSERCLIENT(const IRC_Message *);
void NUMERIC_handle_LUSEROP(const IRC_Message *);
void NUMERIC_handle_LUSERUNKNOWN(const IRC_Message *);
void NUMERIC_handle_LUSERCHANNELS(const IRC_Message *);
void NUMERIC_handle_LUSERME(const IRC_Message *);

void NUMERIC_handle_ADMINME(const IRC_Message *);
void NUMERIC_handle_ADMINLOC1(const IRC_Message *);
void NUMERIC_handle_ADMINLOC2(const IRC_Message *);
void NUMERIC_handle_ADMINEMAIL(const IRC_Message *);
void NUMERIC_handle_TRYAGAIN(const IRC_Message *);
void NUMERIC_handle_LOCALUSERS(const IRC_Message *);
void NUMERIC_handle_GLOBALUSERS(const IRC_Message *);

void NUMERIC_handle_VERSION(const IRC_Message *);
void NUMERIC_handle_INFO(const IRC_Message *);
void NUMERIC_handle_MOTD(const IRC_Message *);
void NUMERIC_handle_ENDOFINFO(const IRC_Message *);
void NUMERIC_handle_MOTDSTART(const IRC_Message *);
void NUMERIC_handle_ENDOFMOTD(const IRC_Message *);

void NUMERIC_handle_YOUREOPER(const IRC_Message *);
void NUMERIC_handle_REHASHING(const IRC_Message *);
void NUMERIC_handle_TIME(const IRC_Message *);

void NUMERIC_handle_NONE(const IRC_Message *);
void NUMERIC_handle_AWAY(const IRC_Message *);
void NUMERIC_handle_USERHOST(const IRC_Message *);
void NUMERIC_handle_UNAWAY(const IRC_Message *);
void NUMERIC_handle_NOWAWAY(const IRC_Message *);

void NUMERIC_handle_WHOISREGNICK(const IRC_Message *);
void NUMERIC_handle_WHOISUSER(const IRC_Message *);
void NUMERIC_handle_WHOISSERVER(const IRC_Message *);
void NUMERIC_handle_WHOISOPERATOR(const IRC_Message *);
void NUMERIC_handle_WHOWASUSER(const IRC_Message *);
void NUMERIC_handle_ENDOFWHO(const IRC_Message *);
void NUMERIC_handle_WHOISIDLE(const IRC_Message *);
void NUMERIC_handle_ENDOFWHOIS(const IRC_Message *);
void NUMERIC_handle_WHOISCHANNELS(const IRC_Message *);
void NUMERIC_handle_WHOISSPECIAL(const IRC_Message *);

void NUMERIC_handle_WHOISACCOUNT(const IRC_Message *);
void NUMERIC_handle_WHOISACTUALLY(const IRC_Message *);

void NUMERIC_handle_WHOREPLY(const IRC_Message *);

void NUMERIC_handle_ENDOFWHOWAS(const IRC_Message *);

void NUMERIC_handle_WHOISCERTFP(const IRC_Message *);
void NUMERIC_handle_WHOISHOST(const IRC_Message *);
void NUMERIC_handle_WHOISMODES(const IRC_Message *);

void NUMERIC_handle_RPLSTARTTLS(const IRC_Message *);
void NUMERIC_handle_WHOISSECURE(const IRC_Message *);

void NUMERIC_handle_HELPSTART(const IRC_Message *);
void NUMERIC_handle_HELPTXT(const IRC_Message *);
void NUMERIC_handle_ENDOFHELP(const IRC_Message *);

void NUMERIC_handle_LOGGEDIN(const IRC_Message *);
void NUMERIC_handle_LOGGEDOUT(const IRC_Message *);
void NUMERIC_handle_SASLSUCCESS(const IRC_Message *);
void NUMERIC_handle_SASLMECHS(const IRC_Message *);

void NUMERIC_handle_LISTSTART(const IRC_Message *);
void NUMERIC_handle_LIST(const IRC_Message *);
void NUMERIC_handle_LISTEND(const IRC_Message *);
void NUMERIC_handle_CHANNELMODEIS(const IRC_Message *);
void NUMERIC_handle_CREATIONTIME(const IRC_Message *);

void NUMERIC_handle_NOTOPIC(const IRC_Message *);
void NUMERIC_handle_TOPIC(const IRC_Message *);
void NUMERIC_handle_TOPICWHOTIME(const IRC_Message *);

void NUMERIC_handle_INVITELIST(const IRC_Message *);
void NUMERIC_handle_ENDOFINVITELIST(const IRC_Message *);
void NUMERIC_handle_INVITING(const IRC_Message *);

void NUMERIC_handle_INVEXLIST(const IRC_Message *);
void NUMERIC_handle_ENDOFINVEXLIST(const IRC_Message *);
void NUMERIC_handle_EXCEPTLIST(const IRC_Message *);
void NUMERIC_handle_ENDOFEXCEPTLIST(const IRC_Message *);

void NUMERIC_handle_NAMREPLY(const IRC_Message *);
void NUMERIC_handle_LINKS(const IRC_Message *);
void NUMERIC_handle_ENDOFLINKS(const IRC_Message *);
void NUMERIC_handle_ENDOFNAMES(const IRC_Message *);
void NUMERIC_handle_BANLIST(const IRC_Message *);
void NUMERIC_handle_ENDOFBANLIST(const IRC_Message *);

void NUMERIC_handle_UNKNOWNERROR(const IRC_Message *);
void NUMERIC_handle_NOSUCHNICK(const IRC_Message *);
void NUMERIC_handle_NOSUCHSERVER(const IRC_Message *);
void NUMERIC_handle_NOSUCHCHANNEL(const IRC_Message *);
void NUMERIC_handle_CANNOTSENDTOCHAN(const IRC_Message *);
void NUMERIC_handle_TOOMANYCHANNELS(const IRC_Message *);
void NUMERIC_handle_WASNOSUCHNICK(const IRC_Message *);

void NUMERIC_handle_NOORIGIN(const IRC_Message *);
void NUMERIC_handle_NORECIPIENT(const IRC_Message *);
void NUMERIC_handle_NOTEXTTOSEND(const IRC_Message *);
void NUMERIC_handle_INPUTTOOLONG(const IRC_Message *);

void NUMERIC_handle_UNKNOWNCOMMAND(const IRC_Message *);
void NUMERIC_handle_NOMOTD(const IRC_Message *);

void NUMERIC_handle_NONICKNAMEGIVEN(const IRC_Message *);
void NUMERIC_handle_ERRONEUSNICKNAME(const IRC_Message *);
void NUMERIC_handle_NICKNAMEINUSE(const IRC_Message *);
void NUMERIC_handle_NICKCOLLISION(const IRC_Message *);

void NUMERIC_handle_USERNOTINCHANNEL(const IRC_Message *);
void NUMERIC_handle_NOTONCHANNEL(const IRC_Message *);
void NUMERIC_handle_USERONCHANNEL(const IRC_Message *);

void NUMERIC_handle_NOTREGISTERED(const IRC_Message *);
void NUMERIC_handle_NEEDMOREPARAMS(const IRC_Message *);
void NUMERIC_handle_ALREADYREGISTERED(const IRC_Message *);
void NUMERIC_handle_PASSWDMISMATCH(const IRC_Message *);
void NUMERIC_handle_YOUREBANNEDCREEP(const IRC_Message *);

void NUMERIC_handle_CHANNELISFULL(const IRC_Message *);
void NUMERIC_handle_UNKNOWNMODE(const IRC_Message *);
void NUMERIC_handle_INVITEONLYCHAN(const IRC_Message *);
void NUMERIC_handle_BANNEDFROMCHAN(const IRC_Message *);
void NUMERIC_handle_BADCHANNELKEY(const IRC_Message *);
void NUMERIC_handle_BADCHANMASK(const IRC_Message *);

void NUMERIC_handle_NOPRIVILEGES(const IRC_Message *);
void NUMERIC_handle_CHANOPRIVSNEEDED(const IRC_Message *);
void NUMERIC_handle_CANTKILLSERVER(const IRC_Message *);
void NUMERIC_handle_NOOPERHOST(const IRC_Message *);

void NUMERIC_handle_UMODEUNKNOWNFLAG(const IRC_Message *);
void NUMERIC_handle_USERSDONTMATCH(const IRC_Message *);
void NUMERIC_handle_HELPNOTFOUND(const IRC_Message *);
void NUMERIC_handle_INVALIDKEY(const IRC_Message *);

void NUMERIC_handle_ERRSTARTTLS(const IRC_Message *);
void NUMERIC_handle_INVALIDMODEPARAM(const IRC_Message *);
void NUMERIC_handle_NOPRIVS(const IRC_Message *);

void NUMERIC_handle_NICKLOCKED(const IRC_Message *);
void NUMERIC_handle_SASLFAIL(const IRC_Message *);
void NUMERIC_handle_SASLTOOLONG(const IRC_Message *);
void NUMERIC_handle_SASLABORTED(const IRC_Message *);
void NUMERIC_handle_SASLALREADY(const IRC_Message *);