#include "utils.hpp"

void	Server::kick(int userKickingSocket, const std::string &channelName, const std::string &userKickedName, const std::string &message)
{
	User *userKicked = getUser(userKickedName);
	User *userKicking = _users[userKickingSocket];
	std::string	msg;
	if (!channelExists(channelName))
	{
		msg = ERR_NOSUCHCHANNEL(userKicking->getNickname(), channelName);
		send(userKickingSocket, msg.c_str(), msg.length(), 0);
		return ;
	}
	Channel *channel = _channels[getExistingChannel(channelName, _channels)];

	if (!channel->isUserIn(userKickingSocket))
	{
		msg = ERR_NOTONCHANNEL(userKicking->getNickname(), channel->getChannelName());
		send(userKickingSocket, msg.c_str(), msg.length(), 0);
		return ;
	}

	if (!channel->isAdmin(userKicking))
	{
		msg = ERR_CHANOPRIVSNEEDED(userKicking->getNickname(), channelName);
		send(userKickingSocket, msg.c_str(), msg.length(), 0);
		return ;
	}
	if (!userKicked)
	{
		msg = ERR_USERNOTINCHANNEL(userKicking->getNickname(), userKickedName, channelName);
		send(userKickingSocket, msg.c_str(), msg.length(), 0);
		return ;
	}
	if (channel->isUserIn(userKicked))
	{
		msg = RPL_KICK(userKicking->getNickname(), userKickedName, channelName, message);
		channel->sendAll(msg);
		channel->removeUser(userKicked->getNickname());
	}
}
