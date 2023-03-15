#include "BitcoinExchange.hpp"

static bool	isLeap( int& year )
{
	if (year % 4 != 0)
		return (false);
	else if (year % 100 != 0)
		return (true);
	else if (year % 400 != 0)
		return (false);
	return (true);
}


int	main( int ac, char **av )
{
	if (check_args(ac))
		return (1);

	std::ifstream	dataSetFd;
	std::ifstream	inputFd;
	if (!openCsv(dataSetFd, "data.csv") || !openCsv(inputFd, av[1]))
		return (2);

	std::map<std::string, float>	dataSet;
	std::string						line, left, right;
	while (std::getline(dataSetFd, line))
	{
		split(line, ',', left, right);
		dataSet[left] = std::strtof(right.c_str(), NULL);
	}
	dataSetFd.close();

	float		value;
	std::string	toFind;
	int	year, month, day;
	int	days[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	while (std::getline(inputFd, line))
	{
		if (line == "date | value")
			continue;
		if (line.find('|') == std::string::npos)
		{
			std::cerr << RED << "Error: bad input -> \"" << line << "\"" << NC << std::endl;
			continue ;
		}

		split(line, '|', left, right);
		if (!check_values(right.c_str(), left))
			continue ;

		value = std::strtof(right.c_str(), NULL);

		if (errno != 0 || value > 1000)
		{
			std::cerr << RED << "Error: number too large." << NC << std::endl;
			errno = 0;
			continue ;
		}


		year = atoi(left.c_str());
		if (isLeap(year))
			days[1] = 29;
		else
			days[1] = 28;
		month = atoi(left.c_str() + 5);
		if (month < 1 || month > 12)
		{
			std::cerr << RED << "Error: invalid month." << NC << std::endl;
			continue ;
		}
		day = atoi(left.c_str() + 8);
		if (day < 1 || day > days[month])
		{
			std::cerr << RED << "Error: invalid day." << NC << std::endl;
			continue ;
		}
		while (true)
		{
			toFind = next_date(year, month, day);
			std::cout << left << " -> " << value << " = " << value * dataSet[left] << std::endl;
		}
	}
	inputFd.close();

	return (0);
}