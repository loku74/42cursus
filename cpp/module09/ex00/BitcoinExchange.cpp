#include "BitcoinExchange.hpp"

bool	openCsv( std::ifstream& dataSetFd, const char* filename )
{
	dataSetFd.open(filename);
	if (!dataSetFd.is_open())
	{
		std::cerr << RED << "Couldn't open " << filename << "." << NC << std::endl;
		return (false);
	}
	return (true);
}


void	split( const std::string& str, const char delimiter, std::string& left, std::string& right )
{
	size_t pos = str.find(delimiter);
	if (pos != std::string::npos)
	{
		left = str.substr(0, pos);
		right = str.substr(pos + 1);
	}
	else
	{
		left = str;
		right = "";
	}
}


bool	check_args( const int& ac )
{
	if (ac == 1)
	{
		std::cerr << RED << "Error: please pass as an argument a database with the following format: date | value." << NC << std::endl;
		return (true);
	}
	else if (ac != 2)
	{
		std::cerr << RED << "Error: too much arguments." << NC << std::endl;
		return (true);
	}
	return (false);
}


bool	check_value( const char* str, size_t size )
{
	unsigned int	dotCount(0);

	if (str[0] == ' ')
		str++;
	else
		return (false);

	for (size_t i = 0; i < size; i++)
	{
		if (dotCount > 1 || (i == 0 && !isdigit(str[i]) && str[i] != '-'))
			return (false);

		if (str[i] == '.')
		{
			dotCount++;
			continue ;
		}

		if (!isdigit(str[i]) && str[i] != '-')
			return (false);
	}
	return (true);
}