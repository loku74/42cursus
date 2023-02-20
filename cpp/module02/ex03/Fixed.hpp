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


	// COMPARISON OPERATORS
	bool	operator<( Fixed const & fixed ) const;
	bool	operator>( Fixed const & fixed ) const;
	bool	operator<=( Fixed const & fixed ) const;
	bool	operator>=( Fixed const & fixed ) const;
	bool	operator==( Fixed const & fixed ) const;
	bool	operator!=( Fixed const & fixed ) const;


	// ARITHMETIC OPERATORS
	Fixed	operator+( Fixed const & fixed ) const;
	Fixed	operator-( Fixed const & fixed ) const;
	Fixed	operator*( Fixed const & fixed ) const;
	Fixed	operator/( Fixed const & fixed ) const;


	// INCREMENT/DECREMENT OPERATORS
	Fixed&	operator++( void );
	Fixed	operator++( int );
	Fixed&	operator--( void );
	Fixed	operator--( int );


	// min & max static member functions
	static			Fixed&	min( Fixed& fixed1, Fixed& fixed2 );
	static const	Fixed&	min( Fixed const & fixed1, Fixed const & fixed2 );
	static			Fixed&	max( Fixed& fixed1, Fixed& fixed2);
	static const	Fixed&	max( Fixed const & fixed1, Fixed const & fixed2);


private:

	int					_value;
	static const int	_fractBits;
};

std::ostream &	operator<<( std::ostream & out, Fixed const & fp );
