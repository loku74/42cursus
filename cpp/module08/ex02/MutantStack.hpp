#pragma once

#include <iostream>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{

public:

	MutantStack( void ) { };
	MutantStack( MutantStack const & toCopy )
	{
		*this = toCopy;
	}
	~MutantStack( void ) { };

	MutantStack&	operator=( MutantStack const & toAssign )
	{
		if (this != &toAssign)
			this->c = toAssign.c;

		return (*this);
	}

	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator begin()
	{
		return (this->c.begin());
	}

	iterator end()
	{
		return (this->c.end());
	}

};
