#include "Point.hpp"

Point::Point( void ) : _x(Fixed(0)), _y(Fixed(0))
{

}

Point::Point( float const & x, float const & y ) : _x(Fixed(x)), _y(Fixed(y))
{

}

Point::Point( Point const & src ) : _x(src._x), _y(src._y)
{
	*this = src;
}


Point::~Point( void )
{

}


Point &	Point::operator=( Point const & rhs )
{
	(void) rhs;
	return (*this);
}

// getter(s)
float	Point::getX( void ) const
{
	return (this->_x.toFloat());
}

float	Point::getY( void ) const
{
	return (this->_y.toFloat());
}


std::ostream&	operator<<( std::ostream& stream, Point const & point )
{
	stream << "(" << point.getX() << ", " << point.getY() << ")";
	return (stream);
}
