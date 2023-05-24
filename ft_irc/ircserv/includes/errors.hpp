#ifndef ERRORS_HPP
# define ERRORS_HPP

# include "replies.hpp"

/* 401 */ # define ERR_NOSUCHNICK(client, target) (":" + SERVER + " 401 " + client + " " + target + " :No such nick/channel\r\n")

/* 403 */ # define ERR_NOSUCHCHANNEL(client, channel) (":" + SERVER + " 403 " + client + " " + channel + " :No such channel\r\n")

/* 404 */ # define ERR_CANNOTSENDTOCHAN(client, channel) (":" + SERVER + " 404 " + client + " " + channel + " :Cannot send to channel\r\n")

/* 411 */ # define ERR_NORECIPIENT(client, command) (":" + SERVER + " 411 " + client + " :no recpient given (" + command + ")\r\n")

/* 412 */ # define ERR_NOTEXTTOSEND(client) (":" + SERVER + " 412 " + client + " :No text to send\r\n")

/* 421 */ # define ERR_UNKNOWNCOMMAND(client, command) (":" + SERVER + " 421 " + client + " " + command + " :Unknown command\r\n")

/* 431 */ # define ERR_NONICKNAMEGIVEN(client) (":" + SERVER + " 431 " + client + " :No nickname given\r\n")

/* 432 */ # define ERR_ERRONEUSNICKNAME(client, nick) (":" + SERVER + " 432 " + client + " " + nick + " :Erroneus nickname\r\n")

/* 433 */ # define ERR_NICKNAMEINUSE(client, nick) (":" + SERVER + " 433 " + client + " " + nick + " :Nickname is already in use\r\n")

/* 441 */ # define ERR_USERNOTINCHANNEL(client, nick, channel) (":" + SERVER + " 441 " + client + " " + nick + " " + channel + " :They aren't on that channel\r\n")

/* 442 */ # define ERR_NOTONCHANNEL(client, channel) (":" + SERVER + " 442 " + client + " " + channel + " :You're not on that channel\r\n")

/* 443 */ # define ERR_USERONCHANNEL(client, nick, channel) (":" + SERVER + " 443 " + client + " " + nick + " " + channel + " :is already on channel\r\n")

/* 461 */ # define ERR_NEEDMOREPARAMS(client, command) (":" + SERVER + " 461 " + client + " " + command + " :Not enough parameters\r\n")

/* 462 */ # define ERR_ALREADYREGISTERED(client) (":" + SERVER + " 462 " + client + " :You may not reregister\r\n")

/* 464 */ # define ERR_PASSWDMISMATCH(client) (":" + SERVER + " 464 " + client + " :Password incorrect\r\n")

/* 471 */ # define ERR_CHANNELISFULL(client, channel) (":" + SERVER + " 471 " + client + " " + channel + " :Cannot join channel (+l)\r\n")

/* 473 */ # define ERR_INVITEONLYCHAN(client, channel) (":" + SERVER + " 473 " + client + " " + channel + " :Cannot join channel (+i)\r\n")

/* 474 */ # define ERR_BANNEDFROMCHAN(client, channel) (":" + SERVER + " 474 " + client + " " + channel + " :Cannot join channel (+b)\r\n")

/* 475 */ # define ERR_BACDCHANNELKEY(client, channel) (":" + SERVER + " 475 " + client + " " + channel + " :Cannot join channel (+k)\r\n")

/* 476 */ # define ERR_BADCHANMASK(channel) (":" + SERVER + " 476 " + channel + " :Bad Channel Mask\r\n")

/* 482 */ # define ERR_CHANOPRIVSNEEDED(client, channel) (":" + SERVER + " 482 " + client + " " + channel + " :You're not channel operator\r\n")

/* 501 */ # define ERR_UMODEUNKNOWNFLAG(client) (":" + SERVER + " 501 " + client + " :Unknown MODE flag\r\n")

/* 525 */ # define ERR_INVALIDKEY(client, channel) (":" + SERVER + " 525 " + client + " " + channel + " :Key is not well-formed\r\n")

#endif
