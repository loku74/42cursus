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

	float		value;
	std::map<std::string, float>::iterator it;

	while (std::getline(inputFd, line))
	{
		if (line == "date | value")
			continue;
		if (line.find('|') == std::string::npos)
		{
			std::cerr << RED << "Error: bad input -> \"" << line << "\"." << NC << std::endl;
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

		it = dataSet.lower_bound(left);
		if (left != dataSet.begin()->first && it == dataSet.begin())
		{
			std::cerr << RED << "Error: bitcoin did not exist in " << left << "." << NC << std::endl;
			continue ;
		}
		while (it->first > left && it != dataSet.begin())
			it--;

		std::cout << left << " -> " << value << " = " << GREEN << value * it->second << NC << std::endl;
	}
	inputFd.close();

	return (0);
}
