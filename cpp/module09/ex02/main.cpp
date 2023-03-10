#include "PmergeMe.hpp"

#include <vector>

static void	insertionSort( std::vector<int>& A )
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


static void merge( std::vector<int>& L, std::vector<int>& R, std::vector<int>& A )
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


static void	mergeSort( std::vector<int>& A )
{
	std::vector<int>	left;
	std::vector<int>	right;

	size_t	mid;
	size_t	n = A.size();

	if (n < 2)
		return ;

	mid = n / 2;

	for (size_t i = 0; i < mid; i++)
		left.push_back(A[i]);

	for (size_t i = mid; i < n; i++)
		right.push_back(A[i]);

	mergeSort(left);
	mergeSort(right);
	merge(left, right, A);
}


int	main( void )
{
	std::vector<int> A;

	for (int i = 11; i > 0; i--)
		A.push_back(i);

	for (int i = 0; i < A.size(); i++)
		std::cout << A[i] << " ";

	mergeSort(A);
	std::cout << "\n";

	for (int i = 0; i < A.size(); i++)
		std::cout << A[i] << " ";
	return (0);
}