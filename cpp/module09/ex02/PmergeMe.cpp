#include "PmergeMe.hpp"

bool	check_input( int& ac, char** av, std::vector<size_t>& vector )
{
	for (int i = 1; i < ac; i++)
	{
		for (int k = 0; av[i][k]; k++)
		{
			if (!std::isdigit(av[i][k]) || strlen(av[i]) > 10)
			{
				std::cout << RED << "Error: invalid numbers input.";
				if (av[i][k] == '-')
					std::cout << " Negative numbers are not allowed.";
				else if (strlen(av[i]) > 10)
					std::cout << " Possible overflow detected.";
				std::cout << NC << std::endl;
				return (false);
			}
		}

		unsigned long	num = std::strtoul(av[i], NULL, 10);

		if (errno != 0 || num > 4294967295)
		{
			std::cout << RED << "Error: overflow detected; please insert size_t numbers." << NC << std::endl;
			return (false);
		}

		vector.push_back(static_cast<size_t>(num));
	}
	return (true);
}


void	printFirst( std::string text, std::string color, std::vector<size_t>& vector )
{
	std::cout << color << text;

	size_t	size = vector.size();

	for (size_t i = 0; i < size && i < 10; i++)
		std::cout << vector[i] << " ";

	if (size > 10)
		std::cout << NC << "[...]";

	std::cout << NC << std::endl;
}
