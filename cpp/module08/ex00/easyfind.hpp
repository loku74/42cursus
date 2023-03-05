#pragma once

#include <algorithm>

template<typename T>
typename T::iterator	easyfind( T& t, int n )
{
	return (std::find(t.begin(), t.end(), n));
}
