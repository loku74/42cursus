#pragma once

#include <cstddef>
#include <iostream>

template<typename T>
void	iter( T* array, size_t length, void f(const T& element))
{
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}
