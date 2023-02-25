#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int	main ( void )
{
	const Animal* animal = new Animal();
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << dog->getType() << std::endl;
	std::cout << cat->getType() << std::endl;

	dog->makeSound(); //will output the cat sound!
	cat->makeSound();
	animal->makeSound();

	delete animal;
	delete dog;
	delete cat;

	const WrongAnimal* wronganimal = new WrongCat();
	std::cout << wronganimal->getType() << std::endl;
	wronganimal->makeSound();
	delete wronganimal;

	const WrongCat* wrongcat = new WrongCat();
	std::cout << wrongcat->getType() << std::endl;
	wrongcat->makeSound();
	delete wrongcat;

	return (0);
}