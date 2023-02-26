#pragma once

#include <iostream>
#include "Brain.hpp"
#include "colors.h"

class Animal
{

public:

	Animal( void );
	Animal( Animal const & toCopy );
	virtual ~Animal( void );

	Animal &	operator=( Animal const & toAssign );

	virtual void	makeSound( void ) const = 0;

	// getter(s)
	std::string	getType( void ) const;

protected:

	std::string	type;

};
