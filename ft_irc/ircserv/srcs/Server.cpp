#include "../includes/Server.hpp"

bool isRunning = true;

static void serverExit(int sign)
{
	(void)sign;
	isRunning = false;
}

Server::Server(int port, const char* password) :
_password(password),
_nbUserMax(10),
_nbUser(0),
_fds(NULL),
_port(port),
_serverSocket(socket(AF_INET, SOCK_STREAM, 0))
{

}

Server::Server(int port, const char* password, size_t nbUserMax) :
_password(password),
_nbUserMax(nbUserMax),
_nbUser(0),
_fds(NULL),
_port(port),
_serverSocket(socket(AF_INET, SOCK_STREAM, 0))
{

}


Server::~Server()
{
	for (size_t i = 1; i <= _nbUser; i++)
	{
		shutdown(_fds[i].fd, 2);
		close(_fds[i].fd);
	}

	close(_serverSocket);
	delete [] _fds;

	for (std::map<std::string, Channel*>::iterator it = _channels.begin();
		it != _channels.end() ; it++)
	{
		delete it->second;
	}
	_channels.clear();
	for (std::map<int, User*>::iterator it = _users.begin();
		it != _users.end() ; it++)
	{
		delete it->second;
	}
	_users.clear();
}

void	Server::init(void)
{
	if (_serverSocket == -1)
		throw ServerSocketFail();

	_serverIn.sin_addr.s_addr = htonl(INADDR_ANY);
	_serverIn.sin_family = AF_INET;
	_serverIn.sin_port = htons(_port);

	const int	enable = 1;

	setsockopt(_serverSocket, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));

	if (bind(_serverSocket, reinterpret_cast<sockaddr*>(&_serverIn), sizeof(_serverIn)) == -1)
		throw PortError();

	if (listen(_serverSocket, _nbUserMax) == -1)
		throw PortError();

	else if (fcntl(_serverSocket, F_SETFL, O_NONBLOCK) == -1)
		throw PortError();

	std::cout << BOLDCYAN "Server password is " << _password << WHITE << std::endl;
	std::cout << BOLDCYAN "Server running on port " << _port << " ..." WHITE << std::endl;

	_fds = new pollfd[_nbUserMax + 1];

	_fds[0].fd = _serverSocket;
	_fds[0].events = POLLIN;

	static void (Server::*functions[N_COMMANDS])(int, t_args&) = {
		&Server::join, &Server::part, &Server::quit, &Server::privmsg, &Server::notice, &Server::kick, &Server::mode, &Server::invite, &Server::topic, &Server::nick, &Server::user, &Server::pass, &Server::who
    };

    static const char   *commandNames[N_COMMANDS] = {
        JOIN, PART, QUIT, PRIVMSG, NOTICE, KICK, MODE, INVITE, TOPIC, NICK, USER, PASS, WHO
    };

    for (size_t i = 0; i < N_COMMANDS; i++)
        _functions[commandNames[i]] = functions[i];
}

std::string const	getExistingChannel(std::string const & channelName, std::map<std::string, Channel*> & channels)
{
	for (std::map<std::string, Channel*>::iterator it = channels.begin(); it != channels.end(); it++)
	{
		if (strToUpper(it->first) == strToUpper(channelName))
			return it->first;
	}
	return "";
}

bool	Server::channelExists(const std::string &channelName)
{
	for (std::map<std::string, Channel*>::iterator it = _channels.begin(); it != _channels.end(); it++)
	{
		if (strToUpper(it->first) == strToUpper(channelName))
			return true;
	}
	return false;
}


bool	Server::userExists(int socket)
{
	std::map<int, User*>::iterator it = _users.find(socket);

	if (it == _users.end())
		return (false);
	return (true);
}

void	Server::run()
{
	char		buffer[BUFFER_SIZE + 1];
	std::string	command;
	int			pollRes, recvRes;

	signal(SIGINT, serverExit);
	while (1)
	{
		_fds[0].revents = 0;
		pollRes = poll(_fds, _nbUser + 1, -1);

		if (!isRunning)
			break;

		if (pollRes == -1)
			perror(NULL);
		else if (_fds[0].revents & POLLIN)
			_connectUser();
		else
		{
			for (size_t i = 1; i <= _nbUser; i++)
			{
				if (_fds[i].revents & POLLIN)
				{
					memset(buffer, 0, BUFFER_SIZE + 1);
					recvRes = recv(_fds[i].fd, buffer, BUFFER_SIZE, 0);
					if (recvRes < 0)
					{
						perror(NULL);
						break ;
					}
					else if (recvRes == 0)
					{
						_disconnectUser(i, "Leaving");
						break ;
					}
					else
					{
						command = buffer;
						if (*command.rbegin() != '\n')
						{
							_buffers[_fds[i].fd] += command;
							continue ;
						}
						_buffers[_fds[i].fd] += command;
						command = _buffers[_fds[i].fd];
						_buffers[_fds[i].fd] = "";
						_callFunction(command, _fds[i].fd);
						break ;
					}
				}
			}
		}
	}
}

void	Server::_callFunction(std::string & command, int inSocket)
{
	std::vector<std::string>	arr;

	if (!userExists(inSocket))
		return ;
	split(command, '\n', arr);
	for (std::vector<std::string>::iterator it = arr.begin(), ite = arr.end(); it != ite; it++)
	{
		if (!userExists(inSocket))
			return ;
		_parsing(inSocket, *it);
	}
}

void	Server::_connectUser()
{
	socklen_t	userInSize = sizeof(_userIn);
	int userSocket = accept(_serverSocket, reinterpret_cast<sockaddr*>(&_userIn), &userInSize);
	if (userSocket == -1)
	{
		print_error("failed to connect the user.");
		return ;
	}
	else if (fcntl(userSocket, F_SETFL, O_NONBLOCK) == -1)
	{
		perror("fcntl");
		return ;
	}
	if (_nbUser >= _nbUserMax)
	{
		close(userSocket);
		print_error("too many users.");
	}
	else
	{
		_fds[_nbUser + 1].fd = userSocket;
		_fds[_nbUser + 1].events = POLLIN;
		_nbUser++;
		std::cout << BOLDGREEN "User connected." WHITE << std::endl;
	}
	User * user = new (std::nothrow)User(userSocket);
	if (user)
	{
		sockaddr_in	userAddr = *(reinterpret_cast<sockaddr_in*>(&_userIn));
		user->setHost(inet_ntoa(userAddr.sin_addr));
		_users[userSocket] = user;
		std::cout << GREEN << "User ip: " << _users[userSocket]->getHost() << WHITEENDL;
		_buffers.insert(std::pair<int, std::string>(userSocket, ""));
	}
	else
	{
		_disconnectUser(userSocket, "server memory error");
	}
}

int	Server::_disconnectUser(size_t userIndex, const std::string reason)
{
	if (userIndex < 1 || userIndex > _nbUser + 1)
		return (0);

	if (_users[_fds[userIndex].fd]->getLogged())
		std::cout << YELLOW << _users[_fds[userIndex].fd]->getNickname() << " has left the server. (" << reason << ")" << WHITEENDL;
	else
		std::cout << YELLOW << "Someone left the server. (" << reason << ")" << WHITEENDL;
	if (!userExists(_fds[userIndex].fd))
			return 0;

	quit(_fds[userIndex].fd);
	close(_fds[userIndex].fd);
	_buffers[_fds[userIndex].fd] = "";

	for (size_t i = userIndex; i < _nbUser; i++)
		_fds[i] = _fds[i + 1];

	_nbUser--;

	return (0);
}

int	Server::_disconnectUser(int fd, const std::string reason)
{
	if (_users[fd]->getLogged())
		std::cout << YELLOW << _users[fd]->getNickname() << " has left the server. (" << reason << ")" << WHITEENDL;
	else
		std::cout << YELLOW << "Someone left the server. (" << reason << ")" << WHITEENDL;

	quit(fd);
	close(fd);
	_buffers[fd] = "";

	int	userIndex = 0;
	for (int i = 0; i < (int)_nbUser; i++)
	{
		if (_fds[i].fd == fd)
			break;
		userIndex++;
	}
	for (size_t i = userIndex; i < _nbUser; i++)
		_fds[i] = _fds[i + 1];

	_nbUser--;

	return (0);
}

bool	Server::userExists(const std::string &nickname)
{
	for (std::map<int, User*>::iterator it = _users.begin();
		it != _users.end(); it++)
	{
		if (it->second->getNickname() == nickname)
			return (true);
	}
	return (false);
}

User	*Server::getUser(const std::string &nickname)
{
	for (std::map<int, User*>::iterator it = _users.begin();
		it != _users.end(); it++)
	{
		if (it->second->getNickname() == nickname)
			return (it->second);
	}
	return (NULL);
}


std::string const	&Server::getPassword() const
{
	return (_password);
}

int	Server::checkArgs(int userSocket, std::string& commandName, int argCount, int min)
{
	if (argCount < min)
	{
		std::string message;
		message = ERR_NEEDMOREPARAMS(_users[userSocket]->getNickname(), commandName);
		send(userSocket, message.c_str(), message.length(), 0);
		return (1);
	}

	return (0);
}

void	Server::_sendInAllChannels(int socket, std::string& msg)
{
	for (std::map<std::string, Channel*>::iterator it = _channels.begin(); it != _channels.end(); it++)
		if ((*it).second->isUserIn(socket))
			(*it).second->sendAll(msg);
}
