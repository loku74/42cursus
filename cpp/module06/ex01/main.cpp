#include "struct.hpp"
#include <iostream>

static uintptr_t	serialize( Data* ptr )
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

static Data*	deserialize( uintptr_t raw )
{
	return (reinterpret_cast<Data*>(raw));
}

int	main( void )
{
	Data data;

	data.a = 42;
	data.b = 42.42f;
	data.c = '6';

	std::cout << data.a << " " << data.b << " " << data.c << std::endl;

	uintptr_t ptr = serialize(&data);
	Data* data2 = deserialize(ptr);

	std::cout << data2->a << " " << data2->b << " " << data2->c << std::endl;

	return (0);
}