#include "utils.hpp"

void	Server::quit(int userSocket)
{
	if (!userExists(userSocket))
		return ;

	std::string userNickname = _users[userSocket]->getNickname();

	std::map<int, User*>::iterator ittmp = _users.find(userSocket);
	
	std::map<std::string, Channel*>::iterator	it;
	std::map<std::string, Channel*>::iterator	it2 = _channels.begin();

	while (it2 != _channels.end())
	{
		it = it2;
		it2++;
		part(userSocket, it->first, "has left the server.", true);
	}


	delete ittmp->second;
	_users.erase(ittmp);
}

