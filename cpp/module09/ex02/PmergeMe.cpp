#include "PmergeMe.hpp"

PmergeMe::PmergeMe( void )
{

}


PmergeMe::PmergeMe( PmergeMe const & toCopy )
{
	*this = toCopy;
}


PmergeMe::~PmergeMe( void )
{

}


PmergeMe&	PmergeMe::operator=( PmergeMe const & toAssign )
{
	return (*this);
}
