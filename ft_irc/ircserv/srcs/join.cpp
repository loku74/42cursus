#include "utils.hpp"

void	Server::_serverJoin(const std::string &channelName, User *user)
{
	std::string join_message = ":" + user->getNickname()
		+ "!" + user->getUsername() + "@" + user->getHost() + " JOIN " + channelName + "\r\n";
	send(user->getSocket(), join_message.c_str(), join_message.length(), 0);
	Channel*	channel = _channels[getExistingChannel(channelName, _channels)];
	std::string	msg;
	std::string	userList = "";


	for (std::vector<User*>::iterator it = channel->getUserList().begin(); it != channel->getUserList().end(); it++)
	{
		if (channel->isAdmin(*it))
			userList += "@";
		userList += ((*it)->getNickname() + " ");
	}
	for (std::vector<User*>::iterator it = channel->getUserList().begin(); it != channel->getUserList().end(); it++)
	{
		if ((*it)->getNickname() != user->getNickname())
			send((*it)->getSocket(), join_message.c_str(), join_message.length(), 0);
	}
	msg = RPL_NAMREPLY(user->getNickname(), channelName, userList);
	send(user->getSocket(), msg.c_str(), msg.length(), 0);
	msg = RPL_ENDOFNAMES(user->getNickname(), channelName);
	if (channel->getTopic() != "")
	{
		msg = RPL_TOPIC(user->getNickname(), channelName, channel->getTopic());
		send(user->getSocket(), msg.c_str(), msg.length(), 0);
	}
	else
	{
		msg = RPL_NOTOPIC(user->getNickname(), channel->getChannelName());
		send(user->getSocket(), msg.c_str(), msg.length(), 0);
	}
}

void	Server::join(int userSocket, const std::string &channelName, const std::string &password)
{
	std::string	msg;
	User		*newUser;
	Channel		*newChannel;

	if (channelName != "" && channelName[0] != '#')
	{
		msg = ERR_BADCHANMASK(channelName);
		send(userSocket, msg.c_str(), msg.length(), 0);
		return ;
	}
	if (!channelExists(channelName))
	{
		newUser = _users[userSocket];
		try
		{
			newChannel = new Channel(channelName, newUser, password);
		}
		catch (std::exception &e)
		{
			print_error(e.what());
			return ;
		}

		newChannel->addAdmin(newUser->getSocket());
		_channels[newChannel->getChannelName()] = newChannel;
		_serverJoin(channelName, newUser);
	}
	else
	{
		Channel *channel = _channels[getExistingChannel(channelName, _channels)];

		if (channel->isBan(_users[userSocket]->getUsername(), _users[userSocket]->getHost()) && !channel->isExcept(_users[userSocket]->getUsername(), _users[userSocket]->getHost()))
		{
			msg = ERR_BANNEDFROMCHAN(_users[userSocket]->getNickname(), channel->getChannelName());
			send(userSocket, msg.c_str(), msg.length(), 0);
			return ;
		}

		if (!channel->isInvite(userSocket) && channel->getPassword() != "" && password == "" && !channel->isUserIn(_users[userSocket]))
		{
			msg = ERR_BACDCHANNELKEY(_users[userSocket]->getNickname(), getExistingChannel(channelName, _channels));
			send(userSocket, msg.c_str(), msg.length(), 0);
			return ;
		}

		if (!channel->isInvite(userSocket) && channel->getPassword() != "" && channel->getPassword() != password && !channel->isUserIn(_users[userSocket]))
		{
			msg = ERR_INVALIDKEY(_users[userSocket]->getNickname(), getExistingChannel(channelName, _channels));
			send(userSocket, msg.c_str(), msg.length(), 0);
			return ;
		}

		if (!channel->isInvite(userSocket) && channel->checkFlag(INVITE_ONLY))
		{
			msg = ERR_INVITEONLYCHAN(_users[userSocket]->getNickname(), getExistingChannel(channelName, _channels));
			send(userSocket, msg.c_str(), msg.length(), 0);
			return ;
		}

		if (channel->getNbUser() >= channel->getMaxUser())
		{
			msg = ERR_CHANNELISFULL(_users[userSocket]->getNickname(), getExistingChannel(channelName, _channels));
			send(userSocket, msg.c_str(), msg.length(), 0);
			return ;
		}

		if (!channel->isUserIn(_users[userSocket]))
		{
			newUser = _users[userSocket];
			if (channel->isEmpty())
				channel->addAdmin(newUser->getSocket());
			channel->addUser(newUser);
			_serverJoin(channel->getChannelName(), newUser);
		}
	}
}
