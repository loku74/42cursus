#include "utils.hpp"
#include "replies.hpp"

void	Server::who(int userSocket, const std::string &target)
{
	if (channelExists(target))
	{
		Channel *channel = _channels[getExistingChannel(target, _channels)];
		std::string	msg;
		std::vector<User*> userList = channel->getUserList();
		for (std::vector<User*>::iterator it = userList.begin(); it != userList.end(); it++)
		{
			msg = RPL_WHOREPLY(_users[userSocket]->getNickname(), target, _users[userSocket]->getUsername(), (*it)->getHost(), (*it)->getNickname(), (*it)->getUsername());
			send(userSocket, msg.c_str(), msg.length(), 0);
		}
		msg = RPL_ENDOFWHO(_users[userSocket]->getUsername(), target);
		send(userSocket, msg.c_str(), msg.length(), 0);
	}
	else if (userExists(target))
	{
		User *userTarget = getUser(target);
		notice(userSocket, _users[userSocket]->getNickname(), userTarget->getNickname() + ": " + userTarget->getUsername());
	}
}
