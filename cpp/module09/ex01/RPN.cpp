#include "RPN.hpp"

/* Default constructor */
RPN::RPN( void ) : _stored(0)
{

}


/* Copy constructor */
RPN::RPN( RPN const & toCopy )
{
	*this = toCopy;
}


/* Default destructor */
RPN::~RPN( void )
{

}


/* Assignment operator */
RPN &	RPN::operator=( RPN const & toAssign )
{
	if (this != &toAssign)
	{
		_rpnStack = toAssign._rpnStack;
		_stored = toAssign._stored;
	}

	return (*this);
}


/* Member function(s) */
void	RPN::push( int n )
{
	_rpnStack.push(n);
	_stored++;
}


void	RPN::add( void )
{
	if (_stored < 2)
		throw OutOfStackException();

	int	a = _rpnStack.top();
	_rpnStack.pop();

	int b = _rpnStack.top();
	_rpnStack.pop();

	_rpnStack.push(b + a);
	_stored--;
}


void	RPN::subtract( void )
{
	if (_stored < 2)
		throw OutOfStackException();

	int	a = _rpnStack.top();
	_rpnStack.pop();

	int b = _rpnStack.top();
	_rpnStack.pop();

	_rpnStack.push(b - a);
	_stored--;
}


void	RPN::multiply( void )
{
	if (_stored < 2)
		throw OutOfStackException();

	int	a = _rpnStack.top();
	_rpnStack.pop();

	int b = _rpnStack.top();
	_rpnStack.pop();

	_rpnStack.push(b * a);
	_stored--;
}


void	RPN::divide( void )
{
	if (_stored < 2)
		throw OutOfStackException();

	int	a = _rpnStack.top();
	_rpnStack.pop();

	if (a == 0)
		throw DivisionByZeroException();

	int b = _rpnStack.top();
	_rpnStack.pop();

	if (a == 0)
		throw DivisionByZeroException();

	_rpnStack.push(b / a);
	_stored--;
}


/* Getter(s) */
std::stack<int>&	RPN::getStack( void ) { return _rpnStack; }
