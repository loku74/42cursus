#include "Brain.hpp"

Brain::Brain( void )
{
	std::cout << GRAY << "(Brain)" << GREEN << " -> Default constructor called" << NC << std::endl;
}


Brain::Brain( Brain const & toCopy )
{
	std::cout << GRAY << "(Brain) -> Copy constructor called" << NC << std::endl;

	*this = toCopy;
}


Brain::~Brain( void )
{
	std::cout << GRAY << "(Brain)" << RED << " -> Default destructor called" << NC << std::endl;
}


Brain &	Brain::operator=( Brain const & toAssign )
{
	std::cout << GRAY << "(Brain) -> Assignment operator called" << NC << std::endl;

	if (this != &toAssign)
	{
		for (size_t i = 0; i < ideas->size(); i++)
			ideas[i] = toAssign.ideas[i];
	}

	return (*this);
}
