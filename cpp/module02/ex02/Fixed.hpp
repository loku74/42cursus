#pragma once

#include <iostream>
#include <cmath>

class Fixed
{

public:

	Fixed( void );
	Fixed( Fixed const & src );
	Fixed( const int num );
	Fixed( const float num);
	~Fixed( void );

	Fixed &	operator=( Fixed const & rhs );

	int		getRawBits( void ) const;
	void	setRawBits( int const raw);
	float	toFloat( void ) const;
	int		toInt( void ) const;

private:

	int					_value;
	static const int	_fractBits;
};

std::ostream &	operator<<( std::ostream & out, Fixed const & fp );
