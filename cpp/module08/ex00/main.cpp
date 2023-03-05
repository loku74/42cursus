#include "easyfind.hpp"
#include "colors.h"

#include <iostream>
#include <vector>
#include <list>

int	main( void )
{
	std::vector<int>	test;

	for (int i = 0; i < 50; i++)
		test.push_back(i * i);

	std::cout << BLUE << "[vector] All values in the vector:" << NC << std::endl;
	for (std::vector<int>::const_iterator it = test.begin(); it != test.end(); it++)
		std::cout << *it << " ";

	std::cout << "\n";

	std::cout << ORANGE << "--- TEST 1: value in the vector ---" << NC << std::endl;
	{
		int value = 2025;
		if (easyfind(test, value) != test.end())
			std::cout << YELLOW << value << GREEN << " is in the vector" << NC << std::endl;
		else
			std::cout << YELLOW << value << RED << " is not in the vector" << NC << std::endl;
	}

	std::cout << ORANGE << "--- TEST 2: value not in the vector ---" << NC << std::endl;
	{
		int value = 2026;
		if (easyfind(test, value) != test.end())
			std::cout << YELLOW << value << GREEN << " is in the vector" << NC << std::endl;
		else
			std::cout << YELLOW << value << RED << " is not in the vector" << NC << std::endl;
	}

	std::list<int>	test2;

	for (int i = 0; i < 50; i++)
		test2.push_back(i * i);

	std::cout << BLUE << "\n[list] All values in the list:" << NC << std::endl;
	for (std::list<int>::const_iterator it = test2.begin(); it != test2.end(); it++)
		std::cout << *it << " ";

	std::cout << "\n";

	std::cout << ORANGE << "--- TEST 3: value in the list ---" << NC << std::endl;
	{
		int value = 49;
		if (easyfind(test2, value) != test2.end())
			std::cout << YELLOW << value << GREEN << " is in the list" << NC << std::endl;
		else
			std::cout << YELLOW << value << RED << " is not in the list" << NC << std::endl;
	}

	std::cout << ORANGE << "--- TEST 4: value not in the list ---" << NC << std::endl;
	{
		int value = 42;
		if (easyfind(test2, value) != test2.end())
			std::cout << YELLOW << value << GREEN << " is in the list" << NC << std::endl;
		else
			std::cout << YELLOW << value << RED << " is not in the list" << NC << std::endl;
	}

	return (0);
}