#ifndef BOT_HPP
# define BOT_HPP

# include <iostream>
# include <sys/socket.h>
# include <unistd.h>
# include <arpa/inet.h>
# include <netinet/in.h>
# include <sys/poll.h>
# include <fcntl.h>
# include <string>
# include <cstring>
# include <cstdlib>
# include <stdio.h>

# define PRIVMSG	0x01
# define NOTICE		0x02
# define JOIN		0x04
# define PART		0x08
# define UNKNOW		0x10
# define CHANNEL	0x20
# define PRIVATE	0x40

typedef struct s_info
{
	uint32_t	type;
	std::string	sender;
	std::string	receiver;
}	t_info;

typedef struct s_cmd
{
	std::string	cmd;
	std::string	arg;
}	t_cmd;


class Bot
{
public:
	Bot(std::string const & botName);
	~Bot();

	int			connectBot(std::string ipAddr, int port);
	void		disconnectBot();
	int			identification(std::string const password) const;
	int			sendData(std::string const data, std::string const & target, uint32_t flags) const;
	int			recvData(std::string & buff);
	t_cmd		getCmd(std::string const & buffer);
	t_info		getInfo(std::string buffer) const;
	std::string	getBotName() const;
	bool		getRunning() const;
	void		stopBot();

private:
	std::string	_botName;
	int			_botSocket;
	bool		_isConnected;
	pollfd		_incommingData;
	bool		_running;
};

#endif