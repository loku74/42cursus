#pragma once

#include "Animal.hpp"

class Dog : public Animal
{

public:

	Dog( void );
	Dog( Dog const & toCopy );
	~Dog( void );

	Dog &	operator=( Dog const & toAssign );

	void	makeSound( void ) const;

private:

	Brain*	_brain;

};
