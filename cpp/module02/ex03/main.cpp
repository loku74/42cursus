#include "Point.hpp"

bool	bsp( Point const a, Point const b, Point const c, Point const point );

int	main( void )
{
	Point const	A( 5, 7);
	Point const	B( 6, 4);
	Point const	C( -1, 2 );

	Point const	point( 6, 4);

	std::cout << bsp( A, B, C, point ) << std::endl;
	return (0);
}
