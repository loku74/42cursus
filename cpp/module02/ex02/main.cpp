#include "Fixed.hpp"

static std::string	boolToString(bool status)
{
	if (status)
		return ("true");
	return ("false");
}

int	main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.42f ) * Fixed( 2 ) );

	std::cout << "a = " << a << std::endl;
	std::cout << "++a = " << ++a << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "a++ = " << a++ << std::endl;
	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;

	std::cout << "a * b = " << a * b << std::endl;
	std::cout << "a / b = " << a / b << std::endl;
	std::cout << "a + b = " << a + b << std::endl;
	std::cout << "a - b + " << a - b << std::endl;

	std::cout << "a > b = " << boolToString(a > b) << std::endl;
	std::cout << "a >= b = " << boolToString(a >= b) << std::endl;
	std::cout << "a < b = " << boolToString(a < b) << std::endl;
	std::cout << "a <= b = " << boolToString(a <= b) << std::endl;

	std::cout << "max(a, b) = " << Fixed::max( a, b ) << std::endl;
	std::cout << "min(a, b) = " << Fixed::min( a, b ) << std::endl;

	return (0);
}
