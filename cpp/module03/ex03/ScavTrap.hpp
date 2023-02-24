#pragma once

#include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{

public:

	ScavTrap( void );
	ScavTrap( ScavTrap const & src );
	ScavTrap( const std::string& name );
	~ScavTrap( void );

	ScavTrap &	operator=( ScavTrap const & rhs );

	void	attack( const std::string& target );
	void	guardGate( void );

private:

};
