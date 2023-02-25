#include "Cat.hpp"

Cat::Cat( void )
{
	std::cout << GRAY << "(Cat)" << GREEN << " -> Default constructor called" << NC << std::endl;

	type = "Cat";
}


Cat::Cat( Cat const & toCopy ) : Animal()
{
	std::cout << GRAY << "(Cat) -> Copy constructor called" << NC << std::endl;

	*this = toCopy;
}


Cat::~Cat( void )
{
	std::cout << GRAY << "(Cat)" << RED << " -> Destructor called" <<  NC << std::endl;
}


Cat &	Cat::operator=( Cat const & toAssign )
{
	std::cout << GRAY << "(Cat) -> Assignment operator called" << NC << std::endl;

	if (this != &toAssign)
	{
		type = toAssign.type;
	}

	return (*this);
}


void	Cat::makeSound( void ) const
{
	std::cout << "meow!" << std::endl;
}
