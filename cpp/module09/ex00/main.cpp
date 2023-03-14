#include "BitcoinExchange.hpp"

static void	split( const std::string& str, const char delimiter, std::string& left, std::string& right )
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

int	main( int ac, char **av )
{
	(void)ac;
	(void)av;
	std::ifstream	dataSetFd;
	if (!openCsv(dataSetFd))
		return (1);

	std::map<std::string, float>	dataSet;
	std::string						line, left, right;

	while (std::getline(dataSetFd, line))
	{
		split(line, ',', left, right);
		dataSet[left] = std::strtof(right.c_str(), NULL);
	}

	for (std::map<std::string, float>::iterator it = dataSet.begin(); it != dataSet.end(); it++)
		std::cout << it->first << "," << it->second << "\n";

	return (0);
}