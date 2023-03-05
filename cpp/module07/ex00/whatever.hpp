#pragma once

template<typename T>
void	swap( T& a, T& b )
{
	T	temp;

	temp = a;
	a = b;
	b = temp;
}


template<typename T>
T&	min( const T& a, const T& b )
{
	return (a > b ? b : a);
}


template<typename T>
T&	max( const T& a, const T& b )
{
	return (a > b ? a : b);
}