#pragma once

#include <iostream>

class PmergeMe
{

public:

	PmergeMe( void );
	PmergeMe( PmergeMe const & toCopy );
	~PmergeMe( void );

	PmergeMe&	operator=( PmergeMe const & toAssign );

private:

};
