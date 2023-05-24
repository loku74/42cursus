#include "Server.hpp"

void	Server::join(int userSocket, t_args& args)
{
	if (!_users[userSocket]->getLogged())
		return ;
	if (checkArgs(userSocket, args.command, args.argCount, 1))
		return ;

	std::vector<std::string>    arr1, arr2;

	split(args.args[0], ',', arr1);
	if (args.argCount > 0)
		split(args.args[1], ',', arr2);

	for (size_t i = 0; i < arr1.size(); i++)
	{
		if (i < arr2.size())
		{
			join(userSocket, arr1[i], arr2[i]);
			continue ;
		}

		join(userSocket, arr1[i], "");
	}
}

void	Server::part(int userSocket, t_args& args)
{
	if (!_users[userSocket]->getLogged())
		return ;
	if (checkArgs(userSocket, args.command, args.argCount, 1))
		return ;

	std::vector<std::string>    arr1;

	split(args.args[0], ',', arr1);
	for (size_t i = 0; i < arr1.size(); i++)
		part(userSocket, arr1[i], args.args[1], false);
}

void	Server::quit(int userSocket, t_args& args)
{
	if (checkArgs(userSocket, args.command, args.argCount, 0))
		return ;

	_disconnectUser(userSocket, args.args[0]);
}

void	Server::privmsg(int userSocket, t_args& args)
{
	if (!_users[userSocket]->getLogged())
		return ;
	if (args.args[0] == "")
	{
		std::string msg = ERR_NORECIPIENT(_users[userSocket]->getNickname(), "privmsg");
		send(userSocket, msg.c_str(), msg.length(), 0);
		return ;
	}
	if (args.args[1] == "")
	{
		std::string msg = ERR_NOTEXTTOSEND(_users[userSocket]->getNickname());
		send(userSocket, msg.c_str(), msg.length(), 0);
		return ;
	}
	std::vector<std::string>	arr1;

	split(args.args[0], ',', arr1);
	for (size_t i = 0; i < arr1.size(); i++)
		privmsg(userSocket, arr1[i], args.args[1]);
}

void	Server::notice(int userSocket, t_args& args)
{
	if (!_users[userSocket]->getLogged())
		return ;
	if (checkArgs(userSocket, args.command, args.argCount, 2))
		return ;

	std::vector<std::string>    arr1;

	split(args.args[0], ',', arr1);
	for (size_t i = 0; i < arr1.size(); i++)
		notice(userSocket, arr1[i], args.args[1]);
}

void	Server::kick(int userSocket, t_args& args)
{
	if (!_users[userSocket]->getLogged())
		return ;
	if (checkArgs(userSocket, args.command, args.argCount, 2))
		return ;

	std::vector<std::string>    arr1;

	split(args.args[1], ',', arr1);
	for (size_t i = 0; i < arr1.size(); i++)
		kick(userSocket, args.args[0], arr1[i], args.args[2]);
}

void	Server::mode(int userSocket, t_args& args)
{
	if (!_users[userSocket]->getLogged())
		return ;
	if (checkArgs(userSocket, args.command, args.argCount, 1))
		return ;
	mode(userSocket, args.args[0], args.args[1], args.args);
}

void	Server::invite(int userSocket, t_args& args)
{
	if (!_users[userSocket]->getLogged())
		return ;
	if (checkArgs(userSocket, args.command, args.argCount, 2))
		return ;

	invite(userSocket, args.args[0], args.args[1]);
}

void	Server::topic(int userSocket, t_args& args)
{
	if (!_users[userSocket]->getLogged())
		return ;
	if (checkArgs(userSocket, args.command, args.argCount, 1))
		return ;

	topic(userSocket, args.args[0], args.args[1]);
}

void	Server::nick(int userSocket, t_args& args)
{
	if (checkArgs(userSocket, args.command, args.argCount, 1))
		return ;
	nick(userSocket, args.args[0]);

}

void	Server::user(int userSocket, t_args& args)
{
	// a voir si c'est pas 4 avec 0 * :realname
	if (checkArgs(userSocket, args.command, args.argCount, 4))
		return ;

	user(userSocket, args.args[0]);
}

void	Server::pass(int userSocket, t_args& args)
{
	if (checkArgs(userSocket, args.command, args.argCount, 1))
		return ;

	pass(userSocket, args.args[0]);
}

void	Server::who(int userSocket, t_args& args)
{
	if (!_users[userSocket]->getLogged())
		return ;
	if (checkArgs(userSocket, args.command, args.argCount, 1))
		return ;

	who(userSocket, args.args[0]);
}
