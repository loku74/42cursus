#include "utils.hpp"

User::User(int socket) :
_nickname(""),
_username(""),
_socket(socket),
_isLogged(false),
_isAccepted(false)
{
}

User::~User(void)
{

}

const std::string	&User::getNickname() const
{
	return (_nickname);
}

const std::string	&User::getUsername() const
{
	return (_username);
}

const std::string	&User::getHost() const
{
	return (_host);
}

void	User::setNickname(std::string const & nickname)
{
	_nickname = nickname;
}

void	User::setUsername(std::string const & username)
{
	_username = username;
}

void	User::setHost(std::string const & host)
{
	_host = host;
}

const int	&User::getSocket() const
{
	return (_socket);
}

void	User::setLogged()
{
	_isLogged = true;
}

bool	User::getLogged() const
{
	return _isLogged;
}

void	User::setAccepted()
{
	_isAccepted = true;
}

bool	User::getAccepted() const
{
	return _isAccepted;
}
