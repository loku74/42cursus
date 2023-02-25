#pragma once

#include <iostream>
#include "colors.h"

class WrongAnimal
{

public:

	WrongAnimal( void );
	WrongAnimal( WrongAnimal const & toCopy );
	virtual ~WrongAnimal( void );

	WrongAnimal &	operator=( WrongAnimal const & toAssign );

	void	makeSound( void ) const;

	// getter(s)
	std::string	getType( void ) const;

protected:

	std::string	type;

};
