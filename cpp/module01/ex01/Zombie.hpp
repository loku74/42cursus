#pragma once

#include <string>
#include <iostream>

class Zombie
{
public:

	Zombie();
	Zombie( const std::string& name );
	~Zombie();

	void	announce( void );

	// setter(s)
	void	setName( const std::string& name );

private:

	std::string	_name;
};

Zombie*	zombieHorde( int N, std::string name );
