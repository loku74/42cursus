#include "PmergeMe.hpp"

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

	std::deque<size_t>	deque(vector.begin(), vector.end());

	printFirst("Before:  ", YELLOW, vector);

	clock_t	start, end;
	double	elapsed_time;

	start = clock();
	mergeInsertSort(vector, (vector.size() / 100) + 2);
	end = clock();

	elapsed_time = (double)(end - start) / (double)CLOCKS_PER_SEC * 1000000.0;

	printFirst("After:   ", GREEN, vector);

	if (!isSorted(vector.begin(), vector.end()))
		std::cout << RED << "Error while sorting std::vector" << NC << std::endl;
	std::cout << "Time to process a range of " << ORANGE << ac - 1 << NC << " elements with " << PURPLE << "std::vector" << NC << ": " << BLUE << elapsed_time << NC << " microseconds." << std::endl;

	start = clock();
	mergeInsertSort(deque, (vector.size() / 100) + 2);
	end = clock();

	elapsed_time = (double)(end - start) / (double)CLOCKS_PER_SEC * 1000000.0;

	if (!isSorted(deque.begin(), deque.end()))
		std::cout << RED << "Error while sorting std::deque" << NC << std::endl;
	std::cout << "Time to process a range of " << ORANGE << ac - 1 << NC << " elements with " << PURPLE << "std::deque" << NC << ": " << BLUE << elapsed_time << NC << " microseconds." << std::endl;

	return (0);
}
