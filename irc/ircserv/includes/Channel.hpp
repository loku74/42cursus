#ifndef CHANNEL_HPP
# define CHANNEL_HPP

# include "utils.hpp"

# define INVITE_ONLY						0x01
# define EXTERNAL_MESSAGE_NON_AUTHORIZED	0x02
# define PERMANENT							0x04
# define NOTICE_NON_AUTHORIZED				0x08
# define INVITE_NON_AUTORIZHED				0x10
# define PROTECTED_TOPIC					0x20
# define MODERATED							0x40

class Server;

class	Channel {

	public :
		Channel(std::string channelName, User *user, const std::string &password);
		~Channel(void);

		void	setPassword(std::string newPassword);
		void	setTopic(std::string topic);
		void	setMaxUser(std::string maxUser);

		uint32_t						getMaxUser() const;
		uint32_t						getNbUser() const;
		std::string	const 				&getChannelName() const;
		std::string const 				&getTopic() const;
		const std::string				&getPassword() const;
		std::vector<User*>				&getUserList();
		User							*getUser(std::string userNickname);
		std::vector<std::string> const	&getBanList() const;
		std::vector<std::string> const	&getExceptList() const;

		void	addFlags(uint32_t const & flags);
		void	removeFlags(uint32_t const & flags);
		bool	checkFlag(uint32_t const & flag);

		void	addUser(User *user);
		void	removeUser(std::string nickname);
		bool	isUserIn(User *user);
		bool	isUserIn(int userSocket);

		void	addAdmin(int userSocket);
		void	removeAdmin(int userSocket);
		bool	isAdmin(User *user);
		bool	isInvite(int userSocket);
		bool	isAlwaysInvite(int userSocket);
		void	addInvite(int userSocket, bool permanent);
		void	removeInvite(int userSocket);

		bool	isEmpty() const;

		void		addToBanList(std::string username, std::string host, std::string from);
		void		delFromBanList(std::string username, std::string host);
		bool		isBan(std::string username, std::string host);
		std::string	getBanName(std::string ban) const;
		std::string	getBanTime(std::string ban) const;
		std::string getBanFrom(std::string ban) const;

		void		addToExceptList(std::string username, std::string host);
		void		delFromExceptList(std::string username, std::string host);
		bool		isExcept(std::string username, std::string host);

		void	sendAll(std::string const & msg);
		void	sendAllExceptSender(int socket, std::string const & msg);

	private :
		std::string							_channelName;
		std::string							_password;
		uint32_t							_maxUser;
		uint32_t							_flags;
		std::string							_topic;
		std::vector<User*>					_userList;
		std::vector<std::string>			_banList;
		std::vector<std::string>			_exceptList;
		std::vector< std::pair<int,bool> >	_inviteList;
		std::vector<int>					_operList;
};

#endif
