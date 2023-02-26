#include "Dog.hpp"
#include "Cat.hpp"

int	main ( void )
{
	Animal* animals[20];

	for (int i = 0; i < 20; i++)
	{
		if (i < 10)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	for (int i = 0; i < 20; i++)
	{
		std::cout << animals[i]->getType() << " | ";
		animals[i]->makeSound();
	}

	for (int i = 0; i < 20; i++)
		delete animals[i];

	std::cout << ORANGE << " --- COPY --- " << NC << std::endl;
	Dog dog;
	Dog dogCopy(dog);
	Cat cat;
	Cat catCopy;

	dog = dogCopy;
	cat = catCopy;

	std::cout << "dog brain adress: " << dog.getBrain() << std::endl;
	std::cout << "dogCopy brain adress: " << dogCopy.getBrain() << std::endl;

	std::cout << "cat brain adress: " << cat.getBrain() << std::endl;
	std::cout << "catCopy brain adress: " << catCopy.getBrain() << std::endl;

	std::cout << dog.getType() << " | " << dogCopy.getType() << std::endl;
	std::cout << cat.getType() << " | " << catCopy.getType() << std::endl;
	dog.makeSound(); dogCopy.makeSound();
	cat.makeSound(); catCopy.makeSound();

	return (0);
}