#ifndef REPLIES_HPP
# define REPLIES_HPP

# define SERVER std::string("ircserv")
# define VERSION std::string("1.0.0")

/*001*/
# define RPL_WELCOME(nickname, username, host) (":" + SERVER + " 001 " + nickname + " :Welcome to the " + SERVER + " Network, " + nickname + "[!" + username + "@" + host + "]\r\n")

/*002*/
# define RPL_YOURHOST(nickname) (":" + SERVER + " 002 " + nickname + " :Your host is " + SERVER + ", running version " + VERSION + "\r\n")

/*315*/
# define RPL_ENDOFWHO(nickname, channelName) (":" + SERVER + " 315 " + nickname + " " + channelName + " :End of WHO list\r\n")

/*324*/
# define RPL_CHANNELMODEIS(client, channel, modes) (":" + SERVER + " 324 " + client + " " + channel + " +" + modes + "\r\n")

/*331*/
# define RPL_NOTOPIC(nickname, channelName) (":" + SERVER + " 331 " + nickname + " " + channelName + " :No topic is set\r\n")

/*332*/
# define RPL_TOPIC(nickname, channelName, topic) (":" + SERVER + " 332 " + nickname + " " + channelName + " :" + topic + "\r\n")

/*341*/
# define RPL_INVITING(client, nickname, channel) (":" + SERVER + " 341 " + client + " " + nickname + " " + channel + " :Inviting " + nickname + " to join " + channel + "\r\n")

/*348*/
# define RPL_EXCEPTLIST(client, channelName, mask) (":" + SERVER + " 348 " + client + " " + channelName + " " + mask + "\r\n")

/*349*/
# define RPL_ENDOFEXCEPTLIST(client, channelName) (":" + SERVER + " 349 " + client + " " + channelName + " :End of channel exception list\r\n")

/*352*/
# define RPL_WHOREPLY(nickname, channelName, username, host, user, realname) (":" + SERVER + " 352 " + nickname + " " + channelName + " " + username + " " + host + " " + SERVER + " " + user + " " + "H*@ :0 " + realname + "\r\n")

/*353*/
# define RPL_NAMREPLY(nickname, channelName, users) (":" + SERVER + " 353 " + nickname + " = " + channelName + " :" + users + "\r\n")

/*366*/
# define RPL_ENDOFNAMES(nickname, channelName) (":" + SERVER + " 366 " + nickname + " " + channelName + " :End of /NAMES list\r\n")

/*367*/
# define RPL_BANLIST(nickname, channelName, mask, time, from) (":" + SERVER + " 367 " + nickname + " " + channelName + " " + mask + " " + from + " " + time + "\r\n")

/*368*/
# define RPL_ENDOFBANLIST(nickname, channelName) (":" + SERVER + " 368 " + nickname + " " + channelName + " :End of channel ban list\r\n")

/*--------------------------------------------------------------------------------*/

/*KICK*/
# define RPL_KICK(nickname, kicked, channelName, msg) (":" + nickname + "!" + kicked + "@" + SERVER + " KICK " + channelName + " " + kicked + " " + msg + "\r\n")

/*MODE*/
# define RPL_MODE(nickname, channelName, target, mode) (":" + nickname + " MODE " + channelName + " " + mode + " " + target + "\r\n")

/*PRIVMSG*/
# define RPL_PRIVMSG(nickname, username, host, target, msg) (":" + nickname + "!" + username + "@" + host + " PRIVMSG " + target + " " + msg + "\r\n")

/*NOTICE*/
# define RPL_NOTICE(nickname, username, host, target, msg) (":" + nickname + "!" + username + "@" + host + " NOTICE " + target + " " + msg + "\r\n")

/*NICK*/
# define RPL_NICK(oldNickname, newNickname) (":" + oldNickname + " NICK " + newNickname + "\r\n")

#endif
