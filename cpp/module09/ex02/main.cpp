#include "PmergeMe.hpp"

#include <vector>
#include <list>
#include <deque>
#include <chrono>

template<typename T>
static void	insertionSort( T& A )
{
	int	value;
	int	hole;

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


template<typename T>
static void merge( T& L , T& R, T& A )
{
	size_t	i;
	size_t	j;
	size_t	k;

	size_t	leftSize = L.size();
	size_t	rightSize = R.size();

	i = j = k = 0;

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

template<typename T>
static void	mergeInsertSort( T& A, size_t threshold )
{
	size_t	mid;
	size_t	n = A.size();

	if (n < threshold)
	{
		insertionSort(A);
		return ;
	}

	mid = n / 2;

	T	left(A.begin(), A.begin() + mid);
	T	right(A.begin() + mid, A.end());

	mergeInsertSort(left, threshold);
	mergeInsertSort(right, threshold);
	merge(left, right, A);
}


int	main( void )
{
	std::vector<int> A;

	for (int i = 5; i > 0; i--)
		A.push_back(i);

	auto start = std::chrono::high_resolution_clock::now();

	mergeInsertSort(A, 20);
	auto end = std::chrono::high_resolution_clock::now();

	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
	std::cout << "Time taken by function: " << duration.count() << " microseconds" << std::endl;

	return (0);
}