#include "Dog.hpp"

Dog::Dog( void )
{
	std::cout << GRAY << "(Dog)" << GREEN << " -> Default constructor called" << NC << std::endl;

	type = "Dog";
}


Dog::Dog( Dog const & toCopy ) : Animal()
{
	std::cout << GRAY << "(Dog) -> Copy constructor called" << NC << std::endl;

	*this = toCopy;
}


Dog::~Dog( void )
{
	std::cout << GRAY << "(Dog)" << RED << " -> Destructor called" << NC << std::endl;
}


Dog &	Dog::operator=( Dog const & toAssign )
{
	std::cout << GRAY << "(Dog) -> Assignment operator called" << NC << std::endl;

	if (this != &toAssign)
	{
		type = toAssign.type;
	}

	return (*this);
}


void	Dog::makeSound( void ) const
{
	std::cout << "woof!" << std::endl;
}
