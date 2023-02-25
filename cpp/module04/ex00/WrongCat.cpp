#include "WrongCat.hpp"

WrongCat::WrongCat( void )
{
	std::cout << GRAY << "(WrongCat)" << GREEN << " -> Default constructor called" << NC << std::endl;

	type = "WrongCat";
}


WrongCat::WrongCat( WrongCat const & toCopy ) : WrongAnimal()
{
	std::cout << GRAY << "(WrongCat) -> Copy constructor called" << NC << std::endl;

	*this = toCopy;
}


WrongCat::~WrongCat( void )
{
	std::cout << GRAY << "(WrongCat)" << RED << " -> Destructor called" <<  NC << std::endl;
}


WrongCat &	WrongCat::operator=( WrongCat const & toAssign )
{
	std::cout << GRAY << "(WrongCat) -> Assignment operator called" << NC << std::endl;

	if (this != &toAssign)
	{
		type = toAssign.type;
	}

	return (*this);
}


void	WrongCat::makeSound( void ) const
{
	std::cout << "meow!" << std::endl;
}
