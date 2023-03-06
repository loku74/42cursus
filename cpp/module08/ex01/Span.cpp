#include "Span.hpp"

/* Constructor */
Span::Span( unsigned int N ) : _size(N), _stored(0)
{

}

Span::Span( Span const & toCopy )
{
	*this = toCopy;
}


Span::~Span( void )
{

}


/* Assignment operator */
Span&	Span::operator=( Span const & toAssign )
{
	if (this != &toAssign)
	{
		_size = toAssign._size;
		_span = toAssign._span;
		_stored = toAssign._stored;
	}
	return (*this);
}


/* Member functions */
void	Span::addNumber(int number)
{
	if (_stored == _size)
		throw SpanIsFullException();

	_span.push_back(number);
	_stored++;
}


unsigned int	Span::shortestSpan( void ) const
{
	std::vector<int>				temp = _span;
	std::vector<int64_t>			mins;

	if (_stored <= 1)
		throw SpanTooShortException();

	std::sort(temp.begin(), temp.end());
	for (unsigned int i = 0; i < _stored - 1; i++)
		mins.push_back((temp[i + 1]) - (temp[i]));

	return (*std::min_element(mins.begin(), mins.end()));
}


unsigned int	Span::longestSpan( void ) const
{
	if (_stored <= 1)
		throw SpanTooShortException();

	unsigned int	max = *std::max_element(_span.begin(), _span.end());
	unsigned int	min = *std::min_element(_span.begin(), _span.end());

	return (max - min);
}
