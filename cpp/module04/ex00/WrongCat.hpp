#pragma once

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{

public:

	WrongCat( void );
	WrongCat( WrongCat const & toCopy );
	~WrongCat( void );

	WrongCat &	operator=( WrongCat const & toAssign );

	void	makeSound( void ) const;

private:

};
