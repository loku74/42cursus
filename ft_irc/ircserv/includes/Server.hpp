#ifndef SERVER_HPP
# define SERVER_HPP

# include "utils.hpp"

class User;
class Channel;

typedef struct s_args
{
	std::string					command;
	std::vector<std::string>	args;
	size_t						argCount;
} t_args;

class	Server {

	public :
		Server(int port, const char* password);
		Server(int port, const char* password, size_t nbUserMax);
		~Server(void);
		void	init(void);
		bool	userExists(int socket);
		bool	userExists(const std::string &nickname);
		User	*getUser(const std::string &nickname);
		bool	channelExists(const std::string &channelName);

		void	join(int userSocket, t_args& args);		//
		void	part(int userSocket, t_args& args);		//
		void	quit(int userSocket, t_args& args);		//
		void	privmsg(int userSocket, t_args& args);	//
		void	notice(int userSocket, t_args& args);	//
		void	kick (int userSocket, t_args& args);	//
		void	mode(int userSocket, t_args& args);		//
		void	invite(int userSocket, t_args& args);	//
		void	topic(int userSocket, t_args& args);	//
		void	nick(int userSocket, t_args& args);		//
		void	user(int userSocket, t_args& args);		//
		void	pass(int userSocket, t_args& args);		//
		void	who(int userSocket, t_args& args);		//

		void	join(int userSocket, const std::string &channelName, const std::string &password);
		void	part(int userSocket, const std::string &channelName, const std::string &message, const bool quit);
		void	quit(int userSocket);
		void	privmsg(int userSocket, const std::string &target, const std::string &message);
		void	notice(int userSocket, const std::string &target, const std::string &message);
		void	kick(int userKickingSocket, const std::string &channelName, const std::string &userKickedName, const std::string &message);
		void	mode(int userSocket, const std::string &channelName, const std::string &mode, std::vector<std::string>& args);
		void	invite(int userSocket, const std::string &userNickname, const std::string &channelName);
		void	topic(int userSocket, const std::string &channelName, const std::string &newTopic);
		void	nick(int userSocket, const std::string &nickname);
		void	user(int userSocket, const std::string &username);
		void	pass(int userSocket, const std::string &password);
		void	who(int userSocket, const std::string &target);

		int   checkArgs(int userSocket, std::string& commandName, int argCount, int min);

		void				run();
		std::string const	&getPassword() const;

		class ServerSocketFail : public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "Failed to create server socket.";
			}
		};

		class PortError : public std::exception
		{
		public:
			virtual const char* what() const throw()
			{
				return "\033[1m\033[31mFailed to use specified port !\033[0m\033[37m";
			}
		};

	typedef void (Server::*FuncPtr)(int, t_args&);

	private :
		std::map<std::string, Channel*> _channels; /*channel name and channel*/
		std::map<int, User*>			_users; /*user socket and user*/
		std::map<int, std::string>		_buffers;
		std::map<std::string, FuncPtr>  _functions; // Function name -> function itself (initialized at server.init())

		/*Lil yang part*/
		std::string	_buffer;
		std::string	_password;
		size_t		_nbUserMax;
		size_t		_nbUser;
		pollfd*		_fds;
		int			_port;
		int			_serverSocket;
		sockaddr_in	_serverIn;
		sockaddr	_userIn;

		void	_serverJoin(const std::string &channelName, User *user);
		void	_callFunction(std::string & command, int inSocket);
		void	_connectUser();
		int		_disconnectUser(size_t userIndex, const std::string reason);
		int		_disconnectUser(int fd, const std::string reason);
		void	_parsing(const int socket, std::string& buffer);
		void	_putChannelModes(User *user, Channel *channel);
		void	_setModes(Channel *channel, const std::string &mode, const std::vector<std::string> &args, int userSocket);
		bool	_isNickError(int userSocket, const std::string &newNickname);
		bool	_isModeError(int userSocket, const std::string &channelName, const std::string &mode);

		void	_badArgs(Channel* channel, int userSocket, int flag);
		void	_reply(int userSocket, std::string mode, int isAdd, Channel* channel, uint32_t flag);

		void	_sendInAllChannels(int socket, std::string& msg);
};

std::string const	getExistingChannel(std::string const & channelName, std::map<std::string, Channel*> & channels);

#endif
