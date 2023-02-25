#include "Dog.hpp"
#include "Cat.hpp"

int	main ( void )
{
	Animal* animal[20];

	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
			animal[i] = new Dog();
		else
			animal[i] = new Cat();
	}

	for (int i = 0; i < 20; i++)
		delete animal[i];
	
	return (0);
}