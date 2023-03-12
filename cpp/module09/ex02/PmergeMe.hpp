#pragma once

/* Colors */
# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define YELLOW "\033[1;33m"
# define ORANGE "\033[38;5;208m"
# define PURPLE "\033[1;35m"
# define BLUE "\033[1;36m"
# define GRAY "\033[1;90m"
# define NC "\033[0m"

#include <iostream>
#include <vector>
#include <deque>
#include <stddef.h>

bool	check_input( int& ac, char** av, std::vector<size_t>& vector );
void	printFirst( std::string text, std::string color, std::vector<size_t>& vector );

template<typename T>
static void	insertionSort( T start, T end )
{
	size_t	value;
	T 		hole;
	T 		startCopy(start);

	start++;
	while (start != end)
	{
		value = *start;
		hole = start;
		while (hole != startCopy && *(hole - 1) > value)
		{
			*hole = *(hole - 1);
			hole--;
		}
		*hole = value;
		start++;
	}
}


template<typename T>
void	mergeInsertSort( T& A, size_t threshold )
{
	size_t	mid;
	size_t	n = A.size();

	if (n < threshold)
	{
		insertionSort(A.begin(), A.end());
		return ;
	}

	mid = n / 2;

	T	left(A.begin(), A.begin() + mid);
	T	right(A.begin() + mid, A.end());

	mergeInsertSort(left, threshold);
	mergeInsertSort(right, threshold);
	std::merge(left.begin(), left.end(), right.begin(), right.end(), A.begin());
}


template<typename T>
bool	isSorted( T start, T end )
{
	while (start != end - 1)
	{
		if (*start > *(start + 1))
		{
			std::cout << *start;
			return (false);
		}
		start++;
	}

	return (true);
}
