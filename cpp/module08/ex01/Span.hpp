#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include "colors.h"

class Span
{

public:

	/* Class Exception(s) */
	class SpanIsFullException : public std::exception
	{
		virtual const char* what( void ) const throw()
		{
			return "Span is full";
		}
	};

	class SpanTooShortException : public std::exception
	{
		virtual const char* what( void ) const throw()
		{
			return "Span too short";
		}
	};

	/* Constructor(s) */
	Span( unsigned int N );
	Span( Span const & toCopy );

	/* Destructor */
	~Span( void );

	/* Assignment operator */
	Span&	operator=( Span const & toAssign );

	/* Member function(s) */
	void			addNumber( int number );
	unsigned int	shortestSpan( void ) const;
	unsigned int	longestSpan( void ) const;

	/* Templated functions(s) */
	template<typename it>
	void			addNumbers( it first, it last )
	{
		while (first != last)
		{
			addNumber(*first);
			first++;
		}
	}

private:

	unsigned int		_size;
	std::vector<int>	_span;
	unsigned int		_stored;

};
