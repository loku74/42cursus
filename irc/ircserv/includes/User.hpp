#ifndef USER_HPP
# define USER_HPP

class	User {

	public :
		User(int socket);
		~User(void);

		const std::string	&getNickname() const;
		const std::string	&getUsername() const;
		const std::string	&getHost() const;
		const int			&getSocket() const;
		void				setUsername(std::string const & username);
		void				setNickname(std::string const & nickname);
		void				setHost(std::string const & host);
		void				setLogged();
		bool				getLogged() const;
		void				setAccepted();
		bool				getAccepted() const;

	private :
		std::string	_nickname;
		std::string	_username;
		int			_socket;
		bool		_isLogged;
		bool		_isAccepted;
		std::string	_host;
};

#endif
