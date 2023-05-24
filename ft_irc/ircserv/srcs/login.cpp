#include "utils.hpp"

void	Server::user(int userSocket, const std::string &username)
{
	User *user = _users[userSocket];
	if (user->getLogged())
	{
		std::string msg = ERR_ALREADYREGISTERED(_users[userSocket]->getNickname());
		send(userSocket, msg.c_str(), msg.length(), 0);
	}
	if (!user->getAccepted())
		return ;
	user->setUsername(username);
	if (user->getUsername() != "" && user->getNickname() != "" && user->getAccepted() == true)
	{
		user->setLogged();
		std::string msg = RPL_WELCOME(user->getNickname(), user->getUsername(), user->getHost());
		send(userSocket, msg.c_str(), msg.length(), 0);
	}
}

bool	Server::_isNickError(int userSocket, const std::string &newNickname)
{
	User *user = _users[userSocket];
	if (newNickname == "")
	{
		std::string msg = ERR_NONICKNAMEGIVEN(_users[userSocket]->getNickname());
		send(userSocket, msg.c_str(), msg.length(), 0);
		if (!user->getLogged())
			_disconnectUser(userSocket, "Empty nickname");
		return (1);
	}
	size_t	notGoodCharInd = newNickname.find_first_of(" ,*?!@");
	size_t	notGoodCharStartInd = newNickname.find_first_of("$:#&");
	if (notGoodCharInd != std::string::npos || notGoodCharStartInd == 0)
	{
		std::string msg = ERR_ERRONEUSNICKNAME(_users[userSocket]->getNickname(), newNickname);
		send(userSocket, msg.c_str(), msg.length(), 0);
		if (!user->getLogged())
			_disconnectUser(userSocket, "Invalid nickname");
		return (1);
	}
	// check if nickname allready exists
	for (std::map<int, User*>::iterator it = _users.begin();
		it != _users.end(); it++)
	{
		if (strToUpper(it->second->getNickname()) == strToUpper(newNickname) && user->getLogged())
		{
			std::string msg = ERR_NICKNAMEINUSE(_users[userSocket]->getNickname(), newNickname);
			send(userSocket, msg.c_str(), msg.length(), 0);
			return (1);
		}
		else if (strToUpper(it->second->getNickname()) == strToUpper(newNickname) && !user->getLogged())
		{
			std::string msg = ERR_NICKNAMEINUSE(_users[userSocket]->getNickname(), newNickname);
			send(userSocket, msg.c_str(), msg.length(), 0);
			_disconnectUser(userSocket, "Nickname already used");
			return (1);
		}
	}
	return (0);
}

void	Server::nick(int userSocket, const std::string &newNickname)
{
	User	*user = _users[userSocket];
	std::string	oldNickname(user->getNickname());
	if (_isNickError(userSocket, newNickname))
		return ;

	if (user->getLogged())
	{
		std::string msg = RPL_NICK(user->getNickname(), newNickname);
		_sendInAllChannels(user->getSocket(), msg);
	}

	if (!user->getAccepted())
		return ;

	user->setNickname(newNickname);
	if (!user->getLogged() && user->getUsername() != "" && user->getNickname() != "" && user->getAccepted() == true)
	{
		user->setLogged();
		std::string msg = RPL_WELCOME(user->getNickname(), user->getUsername(), user->getHost());
		send(userSocket, msg.c_str(), msg.length(), 0);
	}
}

void	Server::pass(int userSocket, const std::string &password)
{
	User *user = _users[userSocket];
	if (user->getLogged())
	{
		std::string msg = ERR_ALREADYREGISTERED(_users[userSocket]->getNickname());
		send(userSocket, msg.c_str(), msg.length(), 0);
	}
	if (user->getAccepted())
		return ;
	if (password == getPassword())
		user->setAccepted();
	else
	{
		std::string msg = ERR_PASSWDMISMATCH(_users[userSocket]->getNickname());
		send(userSocket, msg.c_str(), msg.length(), 0);
		_disconnectUser(userSocket, "Wrong password");
		return ;
	}
}
