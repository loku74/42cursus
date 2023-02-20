#include "Point.hpp"

static float	ft_abs( float const num )
{
	if (num < 0)
		return (-num);
	return (num);
}

/* Getting the triangle area of a triangle which 3 corners are A, B and C:
  triangleArea = 0.5 * (Ax * (By - Cy) + Bx * (Cy - Ay) + Cx * (Ay - By) */
static float	getTriangleArea( Point const a, Point const b, Point const c )
{
	float	res;

	res = ( a.getX() * ( b.getY() - c.getY() ) + b.getX() * ( c.getY() - a.getY() ) + c.getX() * ( a.getY() - b.getY() ) );
	return ( res / 2.0f );
}

bool	bsp( Point const a, Point const b, Point const c, Point const point )
{
	float	triangleArea;

	float	area1;
	float	area2;
	float	area3;
	float	totalArea;

	triangleArea = ft_abs( getTriangleArea( a, b, c ) );

	area1 = ft_abs( getTriangleArea( point, a, b ) );
	area2 = ft_abs( getTriangleArea( point, a, c ) );
	area3 = ft_abs( getTriangleArea( point, b, c ) );
	totalArea = area1 + area2 + area3;
	
	if ( totalArea != triangleArea || area1 == 0 || area2 == 0 || area3 == 0 )
		return (false);

	return (true);
}
