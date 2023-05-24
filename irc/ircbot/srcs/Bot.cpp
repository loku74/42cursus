#include <Bot.hpp>

Bot::Bot(std::string const & botName) :
_botName(botName),
_isConnected(false),
_running(true)
{
}

Bot::~Bot()
{
	if (_isConnected)
		disconnectBot();
}

int Bot::connectBot(std::string ipAddr, int port)
{
	if (ipAddr == "localhost")
		ipAddr = "127.0.0.1";
	
	_botSocket = socket(AF_INET, SOCK_STREAM, 0);
	if (_botSocket == -1)
		return -1;
	

	sockaddr_in	botIn;
	botIn.sin_family = AF_INET;
	botIn.sin_addr.s_addr = inet_addr(ipAddr.c_str());
	botIn.sin_port = htons(port);

	if (connect(_botSocket, reinterpret_cast<sockaddr*>(&botIn), sizeof(botIn)) == -1)
		return -1;

	_incommingData.fd = _botSocket;
	_incommingData.events = POLLIN;

	_isConnected = true;

	return 0;
}

void	Bot::disconnectBot()
{
	if (_isConnected)
	{
		close(_botSocket);
		_isConnected = false;
	}
}

int	Bot::identification(std::string const password) const
{
	std::string	message = "PASS " + password + "\n";
	if (send(_botSocket, message.c_str(), message.length(), 0) == -1)
		return -1;
	message = "NICK " + _botName + "\n";
	if (send(_botSocket, message.c_str(), message.length(), 0) == -1)
		return -1;
	message = "USER big_bot 0 * :realname\n";
	if (send(_botSocket, message.c_str(), message.length(), 0) == -1)
		return -1;
	return 0;
}

int Bot::sendData(std::string const data, std::string const & target, uint32_t flags) const
{
	std::string message;
	if (flags & PRIVMSG)
	{
		if (flags & CHANNEL)
			message = "PRIVMSG #" + target + " " + data + "\n";
		else
			message = "PRIVMSG " + target + " " + data + "\n";
		return (send(_botSocket, message.c_str(), message.length(), 0) == -1);
	}
	if (flags & NOTICE)
	{
		if (flags & CHANNEL)
			message = "NOTICE #" + target + " " + data + "\n";
		else
			message = "NOTICE " + target + " " + data + "\n";
		return (send(_botSocket, message.c_str(), message.length(), 0) == -1);
	}
	if (flags & JOIN)
	{
		message = "JOIN " + target + "\n";
		return (send(_botSocket, message.c_str(), message.length(), 0) == -1);
	}
	if (flags & PART)
	{
		if (data != "")
			message = "PART " + target + " " + data + "\n";
		else
			message = "PART " + target + "\n";
		return (send(_botSocket, message.c_str(), message.length(), 0) == -1);
	}
	return 0;
}

int Bot::recvData(std::string & buff)
{
	char	buffer[1024];
	int		ret, pollRes;

	_incommingData.revents = 0;
	pollRes = poll(&_incommingData, 1, -1);

	if (pollRes == -1)
		perror(NULL);
	else if (_incommingData.revents & POLLIN)
	{
		memset(buffer, 0, 1024);
		ret = recv(_botSocket, buffer, 1024, 0);
		if (ret == 0)
			_running = false;
		buff = reinterpret_cast<char*>(buffer);
	}

	return ret;
}

t_cmd	Bot::getCmd(std::string const & buffer)
{
	size_t	begin, end = 0;
	t_cmd	cmd;

	cmd.cmd = "";
	cmd.arg = "";
	std::string	buff = buffer;
	begin = buff.find_first_of('@', 0);

	if (begin != std::string::npos)
	{
		buff = std::string(buff, begin + 1, buff.length());

		begin = buff.find_first_of('@', 0);

		if (begin != std::string::npos)
		{
			buff = std::string(buff, begin + 1, buff.length());
			for (std::string::iterator it = buff.begin(); it != buff.end(); it++)
			{
				if (!isprint(*it))
					break;
				end++;
			}
			buff = std::string(buff, 0, end);
		}
	}
	end = buff.find_first_of(' ', 0);
	if (end != std::string::npos)
	{
		cmd.cmd = std::string(buff, 0, end);
		cmd.arg = std::string(buff, end + 1, buff.length());
	}
	else
		cmd.cmd = buff;
	return cmd;
}

t_info	Bot::getInfo(std::string buffer) const
{
	t_info	info;
	size_t	finder = 0;

	info.type = 0;
	info.receiver = "";
	info.sender = "";
	if (buffer.length() > 1)
		buffer = std::string(buffer, 1, buffer.length());
	
	finder = buffer.find_first_of('!', 0);
	if (finder != std::string::npos)
		info.sender = std::string(buffer, 0, finder);

	finder = buffer.find_first_of(' ', 0);
	if (finder != std::string::npos)
		buffer = std::string(buffer, finder + 1, buffer.length());

	finder = buffer.find_first_of(' ', 0);
	if (finder != std::string::npos)
	{
		std::string	type(buffer, 0, finder);
		if (type == "JOIN")
			info.type |= JOIN;
		else if (type == "PART")
			info.type |= PART;
		else if (type == "PRIVMSG")
			info.type |= PRIVMSG;
		else if (type == "NOTICE")
			info.type |= NOTICE;
		else
			info.type |= UNKNOW;
		buffer = std::string(buffer, finder + 1, buffer.length());
	}

	size_t	nameStart = 0;
	finder = buffer.find_first_of(' ', 0);
	if (buffer[0] == '#' || buffer[0] == '&')
	{
		nameStart = 1;
		info.type |= CHANNEL;
	}
	else
		info.type |= PRIVATE;
	if (finder != std::string::npos)
		info.receiver = std::string(buffer, nameStart, finder);
	else
	{
		size_t end = 0;
		for (std::string::iterator it = buffer.begin(); it != buffer.end(); it++)
		{
			if (!isprint(*it))
				break;
			end++;
		}
		info.receiver = std::string(buffer, nameStart, end);
	}

	return info;
}

std::string	Bot::getBotName() const
{
	return _botName;
}

bool	Bot::getRunning() const
{
	return _running;
}

void	Bot::stopBot()
{
	_running = false;
}