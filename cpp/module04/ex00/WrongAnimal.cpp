#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : type("animalType")
{
	std::cout << GRAY << "(WrongAnimal)" << GREEN << " -> Default constructor called" << NC << std::endl;
}


WrongAnimal::WrongAnimal( WrongAnimal const & toCopy )
{
	std::cout << GRAY << "(WrongWrongAnimal) -> Copy constructor called" << NC << std::endl;

	*this = toCopy;
}


WrongAnimal::~WrongAnimal( void )
{
	std::cout << GRAY << "(WrongAnimal)" << RED << " -> Destructor called" << NC << std::endl;
}


WrongAnimal &	WrongAnimal::operator=( WrongAnimal const & toAssign )
{
	std::cout << GRAY << "(WrongAnimal) -> Assignment operator called" << NC << std::endl;

	if (this != &toAssign)
	{
		type = toAssign.type;
	}

	return (*this);
}


void	WrongAnimal::makeSound( void ) const
{
	std::cout << "*animal noises*" << std::endl;
}


std::string	WrongAnimal::getType( void ) const
{
	return (type);
}
