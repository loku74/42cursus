#include "utils.hpp"

void	Server::privmsg(int userSocket, const std::string &target, const std::string &message)
{
	if (channelExists(target))
	{
		User *user = _users[userSocket];
		Channel *channel = _channels[getExistingChannel(target, _channels)];

		if (channel->isBan(user->getUsername(), user->getHost()) && !channel->isExcept(user->getUsername(), user->getHost()) && !channel->isAdmin(user))
		{
			std::string msg = ERR_CANNOTSENDTOCHAN(user->getNickname(), channel->getChannelName());
			send(userSocket, msg.c_str(), msg.length(), 0);
			return ;
		}

		if (channel->checkFlag(EXTERNAL_MESSAGE_NON_AUTHORIZED) && !channel->isUserIn(user))
		{
			std::string msg = ERR_CANNOTSENDTOCHAN(_users[userSocket]->getNickname(), target);
			send(userSocket, msg.c_str(), msg.length(), 0);
			return ;
		}

		if (channel->checkFlag(MODERATED) && !channel->isAdmin(user))
		{
			std::string msg = ERR_CANNOTSENDTOCHAN(user->getNickname(), channel->getChannelName());
			send(userSocket, msg.c_str(), msg.length(), 0);
			return ;
		}

		std::string msg = RPL_PRIVMSG(user->getNickname(), user->getUsername(), user->getHost(), channel->getChannelName(), message);
		channel->sendAllExceptSender(userSocket, msg);
	}
	else if (userExists(target))
	{
		User *user = _users[userSocket];
		User *userTo = getUser(target);

		std::string msg = RPL_PRIVMSG(user->getNickname(), user->getUsername(), user->getHost(), target, message);
		send(userTo->getSocket(), msg.c_str(), msg.length(), 0);
	}
	else if (target.length())
	{
		std::string msg = ERR_NOSUCHNICK(_users[userSocket]->getNickname(), target);
		send(userSocket, msg.c_str(), msg.length(), 0);
	}
}
