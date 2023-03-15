#include "BitcoinExchange.hpp"

bool	open_file( std::ifstream& fd, const char* filename )
{
	fd.open(filename);
	if (!fd.is_open())
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


static bool	isLeap(int year)
{
	if (year % 4 != 0)
		return false;
	else if (year % 100 != 0)
		return true;
	else if (year % 400 != 0)
		return false;
	return true;
}

bool	check_values( const char* right, std::string& left )
{
	unsigned int	dotCount(0);
	size_t size = strlen(right);

	if (size == 0)
	{
		std::cerr << RED << "Error: no value found." << NC << std::endl;
		return (false);
	}
	if (right[0] != ' ')
	{
		std::cerr << RED << "Error: invalid value input. Space needed after \"|\"" << NC << std::endl;
		return (false);
	}
	right++; // to pass the first ' ' in the char*
	size--; // adjusting right length
	if (size <= 1 && !isdigit(right[0]))
	{
		std::cerr << RED << "Error: invalid value input; number required." << NC << std::endl;
		return (false);
	}

	for (size_t i = 0; i < size; i++)
	{
		if (dotCount > 1)
		{
			std::cerr << RED << "Error: invalid float value." << NC << std::endl;
			return (false);
		}
		if (i != 0 && right[i] != '.' && !isdigit(right[i]))
		{
			std::cerr << RED << "Error: invalid value (numeric characters required)." << NC << std::endl;
			return (false);
		}

		switch (right[i])
		{
			case '.':
				if (i + 1 == size)
				{
					std::cerr << RED << "Error: invalid float value." << NC << std::endl;
					return (false);
				}
				dotCount++;
				continue ;

			case '-':
				std::cerr << RED << "Error: value is not a positive number." << NC << std::endl;
				return (false);
		}
	}

	if (left.size() != 11 || left[left.size() - 1] != ' ')
	{
		std::cerr << RED << "Error: invalid date format." << NC << std::endl;
		return (false);
	}
	for (size_t i = 0; i < left.size(); i++)
	{
		if (i < 4 && !isdigit((left.c_str())[i]))
		{
			std::cerr << RED << "Error: invalid year." << NC << std::endl;
			return (false);
		}
		else if (i > 4 && i < 7 && !isdigit((left.c_str())[i]))
		{
			std::cerr << RED << "Error: invalid month." << NC << std::endl;
			return (false);
		}
		else if (i > 7 && i < 10 && !isdigit((left.c_str())[i]))
		{
			std::cerr << RED << "Error: invalid month." << NC << std::endl;
			return (false);
		}
		else if ((i == 4 || i == 7) && left[i] != '-')
		{
			std::cerr << RED << "Error: invalid date format." << NC << std::endl;
			return (false);
		}
	}

	left.resize(left.size() - 1);

	int year, month, day;
	int	days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	year = atoi(left.c_str());
	if (isLeap(year))
		days[1] = 29;
	month = atoi(left.c_str() + 5);
	day = atoi(left.c_str() + 8);

	if (month <= 0 || month > 12)
	{
		std::cerr << RED << "Error: " << month << " is not a valid month." << NC << std::endl;
		return (false);
	}
	if (day <= 0 || day > 31)
	{
		std::cerr << RED << "Error: " << day << " is not valid day." << NC << std::endl;
		return (false);
	}
	if (day > days[month - 1])
	{
		std::cerr << RED << "Error: " << day << " is not a valid day in month " << month << "." << NC;
		if (month == 2 && days[1] == 28)
			std::cerr << RED << " Year is not leap." << NC;
		std::cerr << std::endl;
		return (false);
	}

	return (true);
}
