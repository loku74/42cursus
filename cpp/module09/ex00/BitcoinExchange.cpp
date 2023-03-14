#include "BitcoinExchange.hpp"

bool	openCsv( std::ifstream& dataSetFd )
{
	dataSetFd.open("data.csv");
	if (!dataSetFd.is_open())
	{
		std::cerr << RED << "Couldn't open data.csv file" << NC << std::endl;
		return (false);
	}
	return (true);
}