#include "Cat.hpp"

Cat::Cat( void )
{
	std::cout << GRAY << "(Cat)" << GREEN << " -> Default constructor called" << NC << std::endl;

	type = "Cat";
	_brain = new (std::nothrow) Brain();
	if (_brain == NULL)
		std::cout << RED << type << "was born without brain." << NC << std::endl;
}


Cat::Cat( Cat const & toCopy ) : Animal()
{
	std::cout << GRAY << "(Cat) -> Copy constructor called" << NC << std::endl;

	*this = toCopy;
}


Cat::~Cat( void )
{
	std::cout << GRAY << "(Cat)" << RED << " -> Destructor called" <<  NC << std::endl;

	delete _brain;
}


Cat &	Cat::operator=( Cat const & toAssign )
{
	std::cout << GRAY << "(Cat) -> Assignment operator called" << NC << std::endl;

	if (this != &toAssign)
	{
		type = "Cat";
		_brain = new (std::nothrow) Brain(*toAssign._brain);
		if (_brain == NULL)
			std::cout << RED << type << "was born without brain." << NC << std::endl;
	}

	return (*this);
}


void	Cat::makeSound( void ) const
{
	std::cout << "meow!" << std::endl;
}
