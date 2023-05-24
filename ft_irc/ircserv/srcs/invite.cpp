#include "utils.hpp"

void	Server::invite(int userSocket, const std::string &userNickname, const std::string &channelName)
{
	if (!channelExists(channelName))
	{
		std::string msg = ERR_NOSUCHCHANNEL(_users[userSocket]->getNickname(), channelName);
		send(userSocket, msg.c_str(), msg.length(), 0);
		return ;
	}
	if (!userExists(userNickname))
		return ;
	Channel *channel = _channels[getExistingChannel(channelName, _channels)];
	User *user = getUser(userNickname);
	if (!channel->isAdmin(_users[userSocket]))
	{
		std::string msg = ERR_CHANOPRIVSNEEDED(_users[userSocket]->getNickname(), channelName);
		send(userSocket, msg.c_str(), msg.length(), 0);
		return ;
	}
	if (!channel->isUserIn(userSocket))
	{
		std::string msg = ERR_NOTONCHANNEL(_users[userSocket]->getNickname(), channelName);
		send(userSocket, msg.c_str(), msg.length(), 0);
		return ;
	}
	if (channel->isUserIn(user->getSocket()))
	{
		std::string msg = ERR_USERONCHANNEL(_users[userSocket]->getNickname(), userNickname, channelName);
		send(userSocket, msg.c_str(), msg.length(), 0);
		return ;
	}
	if (channel->checkFlag(INVITE_NON_AUTORIZHED))
		return ;
	channel->addInvite(user->getSocket(), false);
	std::string msg = RPL_INVITING(_users[userSocket]->getNickname(), userNickname, channelName);
	send(userSocket, msg.c_str(), msg.length(), 0);
}
