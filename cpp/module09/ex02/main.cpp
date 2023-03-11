#include "PmergeMe.hpp"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cerrno>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[38;5;208m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;36m"
# define GRAY "\033[1;90m"
# define NC "\033[0m"


static bool	check_input( int& ac, char** av, std::vector<size_t>& vector )
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


static void	printFirst( std::string text, std::string color, std::vector<size_t>& vector )
{
	std::cout << color << text;

	size_t	size = vector.size();

	for (size_t i = 0; i < size && i < 10; i++)
		std::cout << vector[i] << " ";

	if (size > 10)
		std::cout << NC << "[...]";

	std::cout << NC << std::endl;
}


int	main( int ac, char** av )
{

	if (ac == 1)
	{
		std::cout << RED << "Error: no inputs detected." << NC << std::endl;
		return (1);
	}

	std::vector<size_t>	vector;

	if (!check_input(ac, av, vector))
		return (2);

	printFirst("Before:  ", YELLOW, vector);

	clock_t	start, end;
	double	elapsed_time;

	start = clock();

	mergeInsertSort(vector, (vector.size() / 100) + 2);

	end = clock();

	elapsed_time = (double)(end - start) / (double)CLOCKS_PER_SEC * 1000000.0;

	printFirst("After:   ", GREEN, vector);
	std::cout << "Time to process a range of " << ORANGE << ac - 1 << NC << " elements with " << PURPLE << "std::vector" << NC << ": " << BLUE << elapsed_time << NC << " microseconds." << std::endl;

	return (0);
}
