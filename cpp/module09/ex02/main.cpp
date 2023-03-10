#include "PmergeMe.hpp"

#include <vector>
#include <chrono>

static void	insertionSort( std::vector<unsigned int>& A )
{
	unsigned int	value;
	unsigned int	hole;

	for (size_t i = 1; i < A.size(); i++)
	{
		value = A[i];
		hole = i;
		while (hole > 0 && A[hole - 1] > value)
		{
			A[hole] = A[hole - 1];
			hole--;
		}
		A[hole] = value;
	}
}


static void merge( std::vector<unsigned int>& L , std::vector<unsigned int>& R, std::vector<unsigned int>& A )
{
	size_t	i(0), j(0), k(0);

	size_t	leftSize = L.size();
	size_t	rightSize = R.size();

	while (i < leftSize && j < rightSize)
	{
		if (L[i] <= R[j])
		{
			A[k] = L[i];
			i++;
		}
		else
		{
			A[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < leftSize)
	{
		A[k] = L[i];
		k++;
		i++;
	}
	while (j < rightSize)
	{
		A[k] = R[j];
		k++;
		j++;
	}
}


static void	mergeInsertSort( std::vector<unsigned int>& A, unsigned int thresold )
{
	size_t	mid;
	size_t	n = A.size();

	if (n < thresold)
	{
		insertionSort(A);
		return ;
	}

	mid = n / 2;

	std::vector<unsigned int>	left(A.begin(), A.begin() + mid);
	std::vector<unsigned int>	right(A.begin() + mid, A.end());

	mergeInsertSort(left, thresold);
	mergeInsertSort(right, thresold);
	merge(left, right, A);
}


int	main( int ac, char** av )
{
	std::vector<unsigned int> A;

	for (int i = 0; av[i]; i++)
		A.push_back(static_cast<unsigned int>(std::atoi(av[i])));

	std::chrono::high_resolution_clock::time_point start = std::chrono::high_resolution_clock::now();

	mergeInsertSort(A, (A.size() / 100) + 2);
	std::chrono::high_resolution_clock::time_point  end = std::chrono::high_resolution_clock::now();

	std::chrono::microseconds duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

	return (0);
}