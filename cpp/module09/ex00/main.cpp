#include "BitcoinExchange.hpp"

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

	float	value;

	while (std::getline(inputFd, line))
	{
		if (line == "date | value")
			continue;

		split(line, '|', left, right);

		if (right == "")
		{
			std::cerr << RED << "Error: bad input -> \"" << line << "\"" << NC << std::endl;
			continue ;
		}
		if (left[left.size() - 1] != ' ' || !check_value(right.c_str(), right.length() - 1))
		{
			std::cerr << RED << "Error: invalid value: \"" << left << "\"." << NC << std::endl;
			continue ;
		}

		left.resize(left.size() - 1);
		value = std::strtof(right.c_str(), NULL);

		if (errno != 0 || value < 0)
		{
			std::cerr << RED << "Error: not a positive number." << NC << std::endl;
			errno = 0;
			continue ;
		}
		if (errno != 0 || value > 1000)
		{
			std::cerr << RED << "Error: number too large." << NC << std::endl;
			errno = 0;
			continue ;
		}
		if (dataSet.find(left) == dataSet.end())
		{
			std::cerr << RED << "Error: couldn't find bitcoin value at date: " << left << "." << NC << std::endl;
			continue ;
		}

		std::cout << left << " -> " << value << " = " << value * dataSet[left] << std::endl;
	}
	inputFd.close();

	return (0);
}