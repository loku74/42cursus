#include "utils.hpp"

int	bad_input(int argc, char **argv)
{
	if (argc != 3)
	{
		print_error("Usage : ./ircserv <port> <password>");
		return (1);
	}
	int	port = atof(argv[1]);
	if (port <= 1024 || port >= 65536)
	{
		print_error("Port should be between 1024 and 65536");
		return (1);
	}
	return (0);
}
