#include "../includes/utils.hpp"

# define EXCEPTION_LIST	0x1
# define BAN_LIST		0x2

void	 Server::_reply(int userSocket, std::string mode, int isAdd, Channel* channel, uint32_t flag)
{
	if (isAdd && !channel->checkFlag(flag))
	{
		std::string msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), "", "+" + mode);
		channel->sendAll(msg);
	}
	else if (!isAdd && channel->checkFlag(flag))
	{
		std::string msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), "", "-" + mode);
		channel->sendAll(msg);
	}
}

void	Server::_badArgs(Channel* channel, int userSocket, int flag)
{
	std::string					msg;
	std::vector<std::string>	list;

	if (flag & EXCEPTION_LIST)
	{
		list = channel->getExceptList();
		for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); it++)
		{
			msg = RPL_EXCEPTLIST(_users[userSocket]->getNickname(), channel->getChannelName(), *it);
			send(userSocket, msg.c_str(), msg.length(), 0);
		}
		msg = RPL_ENDOFEXCEPTLIST(_users[userSocket]->getNickname(), channel->getChannelName());
		send(userSocket, msg.c_str(), msg.length(), 0);
	}
	else if (flag & BAN_LIST)
	{
		list = channel->getBanList();
		for (std::vector<std::string>::iterator it = list.begin(); it != list.end(); it++)
		{
			msg = RPL_BANLIST(_users[userSocket]->getNickname(), channel->getChannelName(), channel->getBanName(*it),  channel->getBanTime(*it), channel->getBanFrom(*it)); 
			send(userSocket, msg.c_str(), msg.length(), 0);
		}
		msg = RPL_ENDOFBANLIST(_users[userSocket]->getNickname(), channel->getChannelName());
		send(userSocket, msg.c_str(), msg.length(), 0);
	}
}

static bool badModes(const std::string &mode)
{
	if (mode == "")
		return (false);

	if (mode[0] != '-' && mode[0] != '+')
		return (true);
	return (false);
}

void	Server::_putChannelModes(User *user, Channel *channel)
{
	std::string modes;
	std::string	args;

	if (channel->checkFlag(INVITE_ONLY))
		modes += "i";
	if (channel->checkFlag(EXTERNAL_MESSAGE_NON_AUTHORIZED))
		modes += "n";
	if (channel->checkFlag(PERMANENT))
		modes += "P";
	if (channel->checkFlag(NOTICE_NON_AUTHORIZED))
		modes += "T";
	if (channel->checkFlag(INVITE_NON_AUTORIZHED))
		modes += "V";
	if (channel->checkFlag(PROTECTED_TOPIC))
		modes += "t";
	if (channel->checkFlag(MODERATED))
		modes += "m";
	if (channel->getPassword() != "")
	{
		modes += "k";
		args += " " + channel->getPassword();
	}
	if (channel->getMaxUser() != __UINT32_MAX__)
	{
		std::stringstream	stream; // on est sur twitch ou koala
		std::string			str;

		stream << channel->getMaxUser();
		stream >> str;
		modes += "l";
		args += " " + str;
	}

	modes += args;
	std::string msg = RPL_CHANNELMODEIS(user->getNickname(), channel->getChannelName(), modes);
	send(user->getSocket(), msg.c_str(), msg.length(), 0);
}

void	Server::_setModes(Channel *channel, const std::string &mode, const std::vector<std::string> &args, int userSocket)
{
	User		*user;
	std::string	pw;
	std::string msg;
	size_t		arg_i = 2;
	bool		isAdd = 0;
	void (Channel::*func)(uint32_t const &);

	if (mode[0] == '-')
		func = &Channel::removeFlags;
	if (mode[0] == '+')
	{
		func = &Channel::addFlags;
		isAdd = 1;
	}
	for (size_t i = 0; i < mode.size(); i++)
	{
		if (mode[i] != '+' && mode[i] != '-' && !channel->isAdmin(_users[userSocket]))
		{
			msg = ERR_CHANOPRIVSNEEDED(_users[userSocket]->getNickname(), channel->getChannelName());
			send(userSocket, msg.c_str(), msg.length(), 0);
			return ;
		}
		switch(mode[i])
		{
			case 'i':
				_reply(userSocket, "i", isAdd, channel, INVITE_ONLY);
				(channel->*func)(INVITE_ONLY);
				break ;
			case 'n':
				_reply(userSocket, "n", isAdd, channel, EXTERNAL_MESSAGE_NON_AUTHORIZED);
				(channel->*func)(EXTERNAL_MESSAGE_NON_AUTHORIZED);
				break;
			case 'P':
				_reply(userSocket, "P", isAdd, channel, PERMANENT);
				(channel->*func)(PERMANENT);
				break ;
			case 'V':
				_reply(userSocket, "V", isAdd, channel, INVITE_NON_AUTORIZHED);
				(channel->*func)(INVITE_NON_AUTORIZHED);
				break ;
			case 'T':
				_reply(userSocket, "T", isAdd, channel, NOTICE_NON_AUTHORIZED);
				(channel->*func)(NOTICE_NON_AUTHORIZED);
				break ;
			case 't':
				_reply(userSocket, "t", isAdd, channel, PROTECTED_TOPIC);
				(channel->*func)(PROTECTED_TOPIC);
				break ;
			case 'm':
				_reply(userSocket, "m", isAdd, channel, MODERATED);
				(channel->*func)(MODERATED);
				break ;
			case 'k':
				if (arg_i >= args.size() - 2)
				{
					msg = ERR_NEEDMOREPARAMS(_users[userSocket]->getNickname(), MODE);
					send(userSocket, msg.c_str(), msg.size(), 0);
					break;
				}
				pw = args[arg_i];
				arg_i++;
				if (isAdd && channel->getPassword() != "")
					break;
				else if (isAdd)
				{
					msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), pw, "+k");
					channel->sendAll(msg);
					channel->setPassword(pw);
				}
				else if (!isAdd && channel->getPassword() == pw)
				{
					msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), "", "-k");
					channel->sendAll(msg);
					channel->setPassword("");
				}
				break;
			case 'l':
				if (isAdd)
				{
					if (arg_i >= args.size() - 2)
					{
						msg = ERR_NEEDMOREPARAMS(_users[userSocket]->getNickname(), MODE);
						send(userSocket, msg.c_str(), msg.size(), 0);
						break;
					}
					std::string	nbUser = args[arg_i];
					arg_i++;
					channel->setMaxUser(nbUser);
					if (strtol(nbUser.c_str(), NULL, 10) > 0)
					{
						msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), nbUser, "+l");
						channel->sendAll(msg);
					}
					else
					{
						msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), "1", "+l");
						channel->sendAll(msg);
					}
				}
				else if (!isAdd)
				{
					msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), "", "-l");
					channel->sendAll(msg);
					channel->setMaxUser("4294967295");
				}
				break;
			case 'o':
				if (arg_i >= args.size() - 2)
				{
					msg = ERR_NEEDMOREPARAMS(_users[userSocket]->getNickname(), MODE);
					send(userSocket, msg.c_str(), msg.size(), 0);
					break;
				}
				user = channel->getUser(args[arg_i]);
				if (user)
				{
					if (isAdd && !channel->isAdmin(user))
					{
						msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), user->getNickname(), "+o");
						channel->sendAll(msg);
						channel->addAdmin(user->getSocket());
					}
					if (!isAdd && channel->isAdmin(user))
					{
						msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), user->getNickname(), "-o");
						channel->sendAll(msg);
						channel->removeAdmin(user->getSocket());
					}

				}
				else
				{
					msg = ERR_NOSUCHNICK(_users[userSocket]->getNickname(), args[arg_i]);
					send(userSocket, msg.c_str(), msg.size(), 0);
				}
				arg_i++;
				break ;
			case 'b':
				if (arg_i >= args.size() - 2)
				{
					_badArgs(channel, userSocket, BAN_LIST);
					break;
				}
				user = getUser(args[arg_i]);
				arg_i++;
				if (isAdd && user)
				{
					if (!channel->isBan(user->getUsername(), user->getHost()))
					{
						msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), user->getNickname(), "+b");
						channel->sendAll(msg);
						channel->addToBanList(user->getUsername(), user->getHost(), _users[userSocket]->getNickname());
					}
				}
				else if (!isAdd && user)
				{
					if (channel->isBan(user->getUsername(), user->getHost()))
					{
						msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), user->getNickname(), "-b");
						channel->sendAll(msg);
						channel->delFromBanList(user->getUsername(), user->getHost());
					}
				}
				else if (!user)
				{
					msg = ERR_NOSUCHNICK(_users[userSocket]->getNickname(), args[arg_i]);
					send(userSocket, msg.c_str(), msg.size(), 0);
				}
				break;
			case 'e':
				if (arg_i >= args.size() - 2)
				{
					_badArgs(channel, userSocket, EXCEPTION_LIST);
					break;
				}
				user = getUser(args[arg_i]);
				arg_i++;
				if (isAdd && user)
				{
					if (!channel->isExcept(user->getUsername(), user->getHost()))
					{
						msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), user->getNickname(), "+e");
						channel->sendAll(msg);
						channel->addToExceptList(user->getUsername(), user->getHost());
					}
				}
				else if (!isAdd && user)
				{
					if (channel->isExcept(user->getUsername(), user->getHost()))
					{
						msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), user->getNickname(), "-e");
						channel->sendAll(msg);
						channel->delFromExceptList(user->getUsername(), user->getHost());
					}
				}
				else if (!user)
				{
					msg = ERR_NOSUCHNICK(_users[userSocket]->getNickname(), args[arg_i]);
					send(userSocket, msg.c_str(), msg.size(), 0);
				}
				break;
			case 'I':
				if (arg_i >= args.size() - 2)
				{
					_badArgs(channel, userSocket, 0);
					break;
				}
				user = getUser(args[arg_i]);
				arg_i++;
				if (user && isAdd)
				{
					msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), user->getNickname(), "+I");
					channel->sendAll(msg);
					channel->addInvite(user->getSocket(), true);
				}
				else if (user && !isAdd)
				{
					msg = RPL_MODE(_users[userSocket]->getNickname(), channel->getChannelName(), user->getNickname(), "-I");
					channel->sendAll(msg);
					channel->removeInvite(user->getSocket());
				}
				else if (!user)
				{
					msg = ERR_NOSUCHNICK(_users[userSocket]->getNickname(), args[arg_i]);
					send(userSocket, msg.c_str(), msg.size(), 0);
				}
				break;
			case '+':
				func = &Channel::addFlags;
				isAdd = 1;
				break ;
			case '-':
				func = &Channel::removeFlags;
				isAdd = 0;
				break ;
			default :
				user = _users[userSocket];
				msg = ERR_UMODEUNKNOWNFLAG(user->getNickname());
				send(user->getSocket(), msg.c_str(), msg.length(), 0);
				user = NULL;
				break;
		}
	}
}

bool	Server::_isModeError(int userSocket, const std::string &channelName, const std::string &mode)
{
	if (!channelExists(channelName))
	{
		std::string msg = ERR_NOSUCHCHANNEL(_users[userSocket]->getNickname(), channelName);
		send(userSocket, msg.c_str(), msg.length(), 0);
		return (1);
	}
	Channel	*channel = _channels[getExistingChannel(channelName, _channels)];
	User	*user = _users[userSocket];
	if (badModes(mode))
	{
		std::string msg = ERR_UMODEUNKNOWNFLAG(user->getNickname());
		send(user->getSocket(), msg.c_str(), msg.length(), 0);
		return (1);
	}
	if (channel->isAdmin(user) == false && mode != "")
	{
		std::string msg = ERR_CHANOPRIVSNEEDED(_users[userSocket]->getNickname(), channelName);
		send(userSocket, msg.c_str(), msg.length(), 0);
		return (1);
	}
	return (0);
}

void	Server::mode(int userSocket, const std::string &channelName, const std::string &mode, std::vector<std::string> &args)
{
	if (_isModeError(userSocket, channelName, mode))
		return ;
	Channel	*channel = _channels[getExistingChannel(channelName, _channels)];
	User	*user = _users[userSocket];
	if (mode == "")
	{
		_putChannelModes(user, channel);
		return ;
	}
	_setModes(channel, mode, args, userSocket);
}
