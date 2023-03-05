#include "Class.hpp"
#include <iostream>
#include <ctime>

Base*	generate( void )
{
	switch (rand() % 3)
	{
		case 0: return (new A());
		case 1: return (new B());
		case 2: return (new C());
		default: return (NULL);
	}
}


void	identify( Base* p )
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}


void	identify( Base& p )
{
	Base	ret;

	try
	{
		ret = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
	}
	catch (...) { }
	try
	{
		ret = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
	}
	catch (...) { }
	try
	{
		ret = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	}
	catch (...) { }
}


int	main( void )
{
	std::srand(std::time(NULL));

	Base*	ptr = generate();

	if (ptr != NULL)
	{
		identify(ptr);
		identify(*ptr);

		delete (ptr);
	}

	return (0);
}
