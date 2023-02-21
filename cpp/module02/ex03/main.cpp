#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point );

static std::string	boolToString(bool status)
{
	if (status)
		return ("true");
	return ("false");
}

int	main( void )
{
	{
		Point const	A( 5, 5);
		Point const	B( 4.76, 1.68);
		Point const	C( 0.8, 4.08 );

		Point const	point( 6, 4);

		std::cout << boolToString(bsp( A, B, C, point )) << std::endl;
	}

	{
		Point const	A( 5, 5);
		Point const	B( 4.76, 1.68);
		Point const	C( 0.8, 4.08 );

		Point const	point( 2, 2);

		std::cout << boolToString(bsp( A, B, C, point )) << std::endl;
	}

	{
		Point const	A( 5, 5);
		Point const	B( 4.76, 1.68);
		Point const	C( 0.8, 4.08 );

		Point const	point( 4, 3.5);

		std::cout << boolToString(bsp( A, B, C, point )) << std::endl;
	}
	return (0);
}
