#pragma once

#include "Fixed.hpp"

class Point
{

public:

	Point( void );
	Point( float const & x, float const & y );
	Point( Point const & src );
	~Point( void );

	Point &	operator=( Point const & rhs );

	// getter(s)
	float	getX( void ) const;
	float	getY( void ) const;

private:

	Fixed const _x;
	Fixed const _y;

};

std::ostream&	operator<<( std::ostream& stream, Point const & point );
