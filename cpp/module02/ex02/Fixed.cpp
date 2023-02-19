#include "Fixed.hpp"

const int	Fixed::_fractBits(8);

Fixed::Fixed( void ) : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}


Fixed::Fixed( Fixed const & src )
{
	std::cout << "Copy constructor called" << std::endl;

	*this = src;
}


Fixed::Fixed( const int num ) : _value(num << 8)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed( const float num ) : _value( (int)roundf( num * (1 << 8) ) )
{
	std::cout << "Float constructor called" << std::endl;
}


Fixed::~Fixed( void )
{
	std::cout << "Destructor called" << std::endl;
}


Fixed &	Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
		_value = rhs.getRawBits();

	return (*this);
}


int		Fixed::getRawBits( void ) const
{
	std::cout << "getRawBits member function called" << std::endl;

	return (_value);
}


void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;

	_value = raw;
}


float	Fixed::toFloat() const
{
	return ( (float)_value / (1 << _fractBits) );
}


int		Fixed::toInt() const
{
	return ( (int)roundf( (float)_value / (1 << _fractBits) ) );
}


std::ostream &	operator<<( std::ostream & out, Fixed const & fp )
{
	out << fp.toFloat();
	return (out);
}
