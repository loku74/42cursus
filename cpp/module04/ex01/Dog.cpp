#include "Dog.hpp"

Dog::Dog( void )
{
	std::cout << GRAY << "(Dog)" << GREEN << " -> Default constructor called" << NC << std::endl;

	type = "Dog";
	_brain = new (std::nothrow) Brain();
	if (_brain == NULL)
		std::cout << RED << type << "was born without brain." << NC << std::endl;
}


Dog::Dog( Dog const & toCopy ) : Animal()
{
	std::cout << GRAY << "(Dog) -> Copy constructor called" << NC << std::endl;

	*this = toCopy;
}


Dog::~Dog( void )
{
	std::cout << GRAY << "(Dog)" << RED << " -> Destructor called" << NC << std::endl;

	delete _brain;
}


Dog &	Dog::operator=( Dog const & toAssign )
{
	std::cout << GRAY << "(Dog) -> Assignment operator called" << NC << std::endl;

	if (this != &toAssign)
	{
		type = "Dog";
		_brain = new (std::nothrow) Brain(*toAssign._brain);
		if (_brain == NULL)
			std::cout << RED << type << "was born without brain." << NC << std::endl;
	}

	return (*this);
}


void	Dog::makeSound( void ) const
{
	std::cout << "woof!" << std::endl;
}
