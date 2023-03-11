#include "PmergeMe.hpp"

static void	insertionSort( std::vector<size_t>& A )
{
	size_t	value;
	size_t	hole;

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


static void merge( std::vector<size_t>& L , std::vector<size_t>& R, std::vector<size_t>& A )
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


void	mergeInsertSort( std::vector<size_t>& A, size_t threshold )
{
	size_t	mid;
	size_t	n = A.size();

	if (n < threshold)
	{
		insertionSort(A);
		return ;
	}

	mid = n / 2;

	std::vector<size_t>	left(A.begin(), A.begin() + mid);
	std::vector<size_t>	right(A.begin() + mid, A.end());

	mergeInsertSort(left, threshold);
	mergeInsertSort(right, threshold);
	merge(left, right, A);
}
