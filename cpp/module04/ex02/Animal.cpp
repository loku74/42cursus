#include "Animal.hpp"

Animal::Animal( void ) : type("animalType")
{
	std::cout << GRAY << "(Animal)" << GREEN << " -> Default constructor called" << NC << std::endl;
}


Animal::Animal( Animal const & toCopy )
{
	std::cout << GRAY << "(Animal) -> Copy constructor called" << NC << std::endl;

	*this = toCopy;
}


Animal::~Animal( void )
{
	std::cout << GRAY << "(Animal)" << RED << " -> Destructor called" << NC << std::endl;
}


Animal &	Animal::operator=( Animal const & toAssign )
{
	std::cout << GRAY << "(Animal) -> Assignment operator called" << NC << std::endl;

	if (this != &toAssign)
	{
		type = toAssign.type;
	}

	return (*this);
}


std::string	Animal::getType( void ) const
{
	return (type);
}
