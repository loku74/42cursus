#include "utils.hpp"

void	Server::notice(int userSocket, const std::string &target, const std::string &message)
{
	if (channelExists(target))
	{
		User *user = _users[userSocket];
		Channel *channel = _channels[getExistingChannel(target, _channels)];

		if (channel->isBan(user->getUsername(), user->getHost()) && !channel->isExcept(user->getUsername(), user->getHost()) && !channel->isAdmin(user))
			return ;

		if (channel->checkFlag(MODERATED) && !channel->isAdmin(user))
			return ;

		if ((channel->checkFlag(EXTERNAL_MESSAGE_NON_AUTHORIZED) && !channel->isUserIn(user)) || channel->checkFlag(NOTICE_NON_AUTHORIZED))
			return ;
		std::string msg = RPL_NOTICE(user->getNickname(), user->getUsername(), user->getHost(), channel->getChannelName(), message);
		channel->sendAllExceptSender(userSocket, msg);
	}
	else if (userExists(target))
	{
		User *user = _users[userSocket];
		User *userTo = getUser(target);
		std::string msg = RPL_NOTICE(user->getNickname(), user->getUsername(), user->getHost(), target, message);
		send(userTo->getSocket(), msg.c_str(), msg.length(), 0);
	}
}
