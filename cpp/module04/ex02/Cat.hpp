#pragma once

#include "Animal.hpp"

class Cat : public Animal
{

public:

	Cat( void );
	Cat( Cat const & toCopy );
	~Cat( void );

	Cat &	operator=( Cat const & toAssign );

	void	makeSound( void ) const;

	// getter(s)
	Brain*	getBrain( void );

private:

	Brain*	_brain;

};
