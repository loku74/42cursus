#ifndef UTILS_HPP
# define UTILS_HPP

# include <string>
# include <iostream>
# include <cstdlib>
# include <vector>
# include <algorithm>
# include <map>
# include <unistd.h>
# include <sys/poll.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <stdio.h>
# include <poll.h>
# include <cstring>
# include <fcntl.h>
# include <signal.h>
# include <ctime>
# include <sstream>
# include "colors.hpp"
# include "Server.hpp"
# include "User.hpp"
# include "Channel.hpp"
# include "parsing.hpp"
# include "replies.hpp"
# include "errors.hpp"

# define BUFFER_SIZE 512


void	print_error(std::string message);
int		bad_input(int argc, char **argv);


#endif
