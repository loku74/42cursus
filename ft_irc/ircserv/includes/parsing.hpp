#ifndef PARSING_HPP
# define PARSING_HPP

# include <sstream>
# include <vector>
# include <string>

# define JOIN		"JOIN"
# define PART		"PART"
# define QUIT       "QUIT"
# define PRIVMSG	"PRIVMSG"
# define NOTICE		"NOTICE"
# define KICK		"KICK"
# define MODE		"MODE"
# define INVITE		"INVITE"
# define TOPIC		"TOPIC"
# define NICK		"NICK"
# define USER		"USER"
# define PASS		"PASS"
# define WHO        "WHO"

# define N_COMMANDS 13

void				split(const std::string& str, const char delim, std::vector<std::string>& out);
std::string const	strToUpper(std::string const & ref);

#endif
