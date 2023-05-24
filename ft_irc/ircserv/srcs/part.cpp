#include "utils.hpp"

void	Server::part(int userSocket, const std::string &channelName, const std::string &message, const bool quit)
{
	(void) message;
	User	*user = _users[userSocket];
	std::string part_message;
	if (!channelExists(channelName))
	{
		part_message = ERR_NOSUCHCHANNEL(user->getNickname(), channelName);
		send(user->getSocket(), part_message.c_str(), part_message.length(), 0);
		return ;
	}
	Channel	*channel = _channels[getExistingChannel(channelName, _channels)];

	if (!channel->isUserIn(user))
	{
		part_message = ERR_NOTONCHANNEL(user->getNickname(), channelName);
		send(user->getSocket(), part_message.c_str(), part_message.length(), 0);
		return ;
	}

	part_message = ":" + user->getNickname()
		+ "!" + user->getUsername() + "@" + user->getHost() + " PART " + channel->getChannelName() + "\r\n";
	if (quit)
		channel->sendAllExceptSender(userSocket, part_message);
	else
		channel->sendAll(part_message);

	channel->removeUser(user->getNickname());
	if (!channel->checkFlag(PERMANENT) && channel->isEmpty())
	{
		std::map<std::string, Channel*>::iterator it = _channels.find(channel->getChannelName());
		delete (it->second);
		_channels.erase(it);
	}
}
