#pragma once

#include <iostream>

template<typename T>
class Array
{

public:

	/* Default constructor */
	Array( void ) : _array(NULL), _size(0) { };

	/* Constructor with the size of the array as a parameter */
	Array( unsigned int size );

	/* Copy constructor */
	Array( Array const & toCopy )
	{
		*this = toCopy;
	}

	/* Default destructor */
	~Array( void )
	{
		delete[] _array;
	}

	/* Assignment operator */
	Array &	operator=( Array const & toAssign )
	{
		if (this != &toAssign)
		{
			_size = toAssign._size;

			if (_array)
			{
				delete _array;

				_array = new T[_size];

				for (unsigned int i = 0; i < _size; i++)
					_array[i] = toAssign._array[i];
			}
			else
				_array = NULL;
		}

		return (*this);
	}

	class OutOfRangeException : public std::exception
	{
		virtual const char* what( void ) const throw()
		{
			return ("Index out of range");
		}
	};

	/*  Operator[] overload */
	T&	operator[]( unsigned int index );

	/* size() method that returns the size of the array */
	unsigned int	size( void ) { return _size; }

private:

	T*				_array;
	unsigned int	_size;

};

/* Constructor with the size of the array as a parameter */
template<typename T>
Array<T>::Array( unsigned int size ) : _size(size)
{
	_array = new T[size];
}


/*  Operator[] overload */
template<typename T>
T&	Array<T>::operator[]( unsigned int index )
{
	if (index >= _size)
		throw OutOfRangeException();

	return (_array[index]);
}
