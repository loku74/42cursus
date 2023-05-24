#include "utils.hpp"

Channel::Channel(std::string channelName, User *user, const std::string &password) :
_channelName(channelName),
_password(password),
_maxUser(__UINT32_MAX__),
_flags(),
_topic("")
{
	addUser(user);
}

Channel::~Channel(void)
{
}

void	Channel::setPassword(std::string newPassword)
{
	_password = newPassword;
}

void	Channel::addFlags(uint32_t const & flags)
{
	_flags |= flags;
}

void	Channel::removeFlags(uint32_t const & flags)
{
	uint32_t mod_flags = flags ^ 0xffffffff;
	_flags &= mod_flags;
}

bool	Channel::checkFlag(uint32_t const & flag)
{
	return _flags & flag;
}

void	Channel::setTopic(std::string topic)
{
	if (topic.length() && topic[0] == ':')
		topic = std::string(topic, 1, topic.length());
	_topic = topic;
}

std::string	const & Channel::getChannelName() const
{
	return (_channelName);
}

std::string const &	Channel::getTopic() const
{
	return _topic;
}

std::vector<User*>	&Channel::getUserList()
{
	return (_userList);
}

const std::string	&Channel::getPassword() const
{
	return(_password);
}

void	Channel::addUser(User *user)
{
	if (user && !isUserIn(user))
		_userList.push_back(user);
}

bool	Channel::isUserIn(User *user)
{
	if (user)
	{
		if (std::find(_userList.begin(), _userList.end(), user) != _userList.end())
			return (true);
	}
	return (false);
}

bool	Channel::isUserIn(int userSocket)
{
	for (std::vector<User*>::iterator it = _userList.begin();
		it != _userList.end(); it++)
	{
		if ((*it)->getSocket() == userSocket)
			return (true);
	}
	return (false);
}

bool	Channel::isAdmin(User *user)
{
	if (user)
	{
		std::vector<int>::iterator it = std::find(_operList.begin(), _operList.end(), user->getSocket());
		if (it != _operList.end())
			return (true);
	}
	return (false);
}

void	Channel::removeUser(std::string nickname)
{
	User *user = getUser(nickname);
	std::vector<User*>::iterator it = std::find(_userList.begin(), _userList.end(), user);
	if (it == _userList.end())
		return ;
	_userList.erase(it);
	if (!isAlwaysInvite(user->getSocket()))
		removeInvite(user->getSocket());
	removeAdmin(user->getSocket());
}

void	Channel::setMaxUser(std::string MaxUser)
{
	for (size_t i = 0; i < MaxUser.size(); i++)
	{
		if (MaxUser[i] < '0' || MaxUser[i] > '9')
			return ;
	}
	unsigned long maxUser = strtol(MaxUser.c_str(), NULL, 10);
	if (maxUser == 0 && MaxUser != "0")
		return ;
	if (maxUser > __UINT32_MAX__)
		_maxUser = __UINT32_MAX__;
	else if (maxUser <= 1)
		_maxUser = 1;
	else
		_maxUser = maxUser;

}

User	*Channel::getUser(std::string userNickname)
{
	for (std::vector<User*>::iterator it = _userList.begin(); it != _userList.end(); it++)
	{
		if ((*it)->getNickname() == userNickname)
			return (*it);
	}
	return (NULL);
}

bool	Channel::isInvite(int userSocket)
{
	for (std::vector< std::pair<int,bool> >::iterator it = _inviteList.begin();
		it != _inviteList.end(); it++)
	{
		if (userSocket == (*it).first)
			return (true);
	}
	return (false);
}

bool	Channel::isAlwaysInvite(int userSocket)
{
	for (std::vector< std::pair<int,bool> >::iterator it = _inviteList.begin();
		it != _inviteList.end(); it++)
	{
		if (userSocket == (*it).first)
			return (*it).second;
	}
	return (false);
}

void	Channel::addInvite(int userSocket, bool permanent)
{
	if (!isInvite(userSocket))
		_inviteList.push_back(std::make_pair(userSocket, permanent));
}

void	Channel::removeInvite(int userSocket)
{
	for (std::vector< std::pair<int,bool> >::iterator it = _inviteList.begin();
		it != _inviteList.end(); it++)
	{
		if (userSocket == (*it).first)
		{
			_inviteList.erase(it);
			return ;
		}
	}
}

bool	Channel::isEmpty() const
{
	return (!(_userList.size()));
}

uint32_t	Channel::getMaxUser() const
{
	return (_maxUser);
}

uint32_t	Channel::getNbUser() const
{
	return (_userList.size());
}

std::vector<std::string> const	&Channel::getBanList() const
{
	return _banList;
}

std::vector<std::string> const	&Channel::getExceptList() const
{
	return _exceptList;
}

void	Channel::addToBanList(std::string username, std::string host, std::string from)
{
	std::string	mask = username + "@" + host;
	clock_t banTime;

	banTime = time(NULL);

	std::stringstream	timeToStr;
	timeToStr << banTime;
	std::string timeStr;
	timeToStr >> timeStr;
	for (std::vector<std::string>::iterator it = _banList.begin(); it != _banList.end(); it++)
		if (*it == mask)
			return ;
	_banList.insert(_banList.begin(), mask + ":" + from + ":" + timeStr);
}

void	Channel::delFromBanList(std::string username, std::string host)
{
	std::string	mask = username + "@" + host;

	for (std::vector<std::string>::iterator it = _banList.begin(); it != _banList.end(); it++)
	{
		if ((*it).substr(0, (*it).find_first_of(':')) == mask)
		{
			_banList.erase(it);
			return ;
		}
	}
}

bool	Channel::isBan(std::string username, std::string host)
{
	std::string	mask = username + "@" + host;

	for (std::vector<std::string>::iterator it = _banList.begin(); it != _banList.end(); it++)
		if ((*it).substr(0, (*it).find_first_of(':')) == mask)
			return true;
	return false;
}

void	Channel::addToExceptList(std::string username, std::string host)
{
	std::string	mask = username + "@" + host;

	for (std::vector<std::string>::iterator it = _exceptList.begin(); it != _exceptList.end(); it++)
		if (*it == mask)
			return ;
	_exceptList.insert(_exceptList.begin(), mask);
}

void	Channel::delFromExceptList(std::string username, std::string host)
{
	std::string	mask = username + "@" + host;

	for (std::vector<std::string>::iterator it = _exceptList.begin(); it != _exceptList.end(); it++)
	{
		if (*it == mask)
		{
			_exceptList.erase(it);
			return ;
		}
	}
}

bool	Channel::isExcept(std::string username, std::string host)
{
	std::string	mask = username + "@" + host;

	for (std::vector<std::string>::iterator it = _exceptList.begin(); it != _exceptList.end(); it++)
		if (*it == mask)
			return true;
	return false;
}

void	Channel::sendAll(std::string const & msg)
{
	for (std::vector<User*>::iterator it = _userList.begin(); it != _userList.end(); it++)
		send((*it)->getSocket(), msg.c_str(), msg.length(), 0);
}

void	Channel::sendAllExceptSender(int socket, std::string const & msg)
{
	for (std::vector<User*>::iterator it = _userList.begin(); it != _userList.end(); it++)
		if ((*it)->getSocket() != socket)
			send((*it)->getSocket(), msg.c_str(), msg.length(), 0);
}

void	Channel::addAdmin(int userSocket)
{
	_operList.push_back(userSocket);
}

void	Channel::removeAdmin(int userSocket)
{
	std::vector<int>::iterator it = std::find(_operList.begin(), _operList.end(), userSocket);

	if (it != _operList.end())
		_operList.erase(it);
}

std::string	Channel::getBanName(std::string ban) const
{
	return ban.substr(0, ban.find_first_of(':'));
}

std::string	Channel::getBanTime(std::string ban) const
{
	size_t	begin = ban.find_last_of(':') + 1;
	return ban.substr(begin, ban.length() - begin);
}

std::string Channel::getBanFrom(std::string ban) const
{
	size_t	begin = ban.find_first_of(':') + 1, end = ban.find_last_of(':');
	return ban.substr(begin, end - begin);
}

