#include "utils.hpp"

void	Server::topic(int userSocket, const std::string &channelName, const std::string &newTopic)
{
	User *user = _users[userSocket];
	if (!channelExists(channelName))
	{
		std::string msg = ERR_NOSUCHCHANNEL(_users[userSocket]->getNickname(), channelName);
		send(userSocket, msg.c_str(), msg.length(), 0);
		return ;
	}

	Channel *channel = _channels[getExistingChannel(channelName, _channels)];
	if (!channel->isUserIn(userSocket))
	{
		std::string msg = ERR_NOTONCHANNEL(_users[userSocket]->getNickname(), channelName);
		send(userSocket, msg.c_str(), msg.length(), 0);
		return ;
	}

	if (channel->checkFlag(PROTECTED_TOPIC) && !channel->isAdmin(user)) // check si le user est admin dans le channel
	{
		std::string msg = ERR_CHANOPRIVSNEEDED(_users[userSocket]->getNickname(), channelName);
		send(userSocket, msg.c_str(), msg.length(), 0);
		return ;
	}

	channel->setTopic(newTopic);
	std::string msg = RPL_TOPIC(user->getNickname(), channel->getChannelName(), channel->getTopic());
	channel->sendAll(msg);
}
