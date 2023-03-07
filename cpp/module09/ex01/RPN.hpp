#pragma once

#include <iostream>
#include <stack>

class RPN
{

public:

	/* Default constructor */
	RPN( void );

	/* Copy constructor */
	RPN( RPN const & toCopy );

	/* Default destructor */
	~RPN( void );

	/* Assignment operator */
	RPN &	operator=( RPN const & toAssign );


	/* Exception(s) */
	class OutOfStackException : public std::exception
	{
		virtual const char* what( void ) const throw()
		{
			return ("Error: Invalid operation(s).");
		}

	};

	/* Member function(s) */
	void	push( int n );
	void	add( void );
	void	subtract( void );
	void	multiply( void );
	void	divide( void );

	/* Getter(s) */
	std::stack<int>&	getStack( void );


private:

	std::stack<int>	_rpnStack;
	size_t			_stored;

};
