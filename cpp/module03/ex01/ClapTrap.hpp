#pragma once

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define ORANGE "\033[38;5;208m"
#define PURPLE "\033[1;35m"
#define BLUE "\033[1;36m"
#define GRAY "\033[1;90m"
#define NC "\033[0m"

#include <iostream>

class ClapTrap
{

public:

	ClapTrap( void );
	ClapTrap( ClapTrap const & src );
	ClapTrap( const std::string& name );
	~ClapTrap( void );

	ClapTrap &	operator=( ClapTrap const & rhs );

	void	attack( const std::string& target );
	void	takeDamage( unsigned int amount );
	void	beRepaired( unsigned int amount );

protected:

	std::string		_name;
	unsigned int	_hitPoints;
	unsigned int	_energyPoints;
	unsigned int	_attackDamage;

};
