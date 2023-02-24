#pragma once

#include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap
{

public:

	FragTrap( void );
	FragTrap( FragTrap const & src );
	FragTrap( const std::string& name );
	~FragTrap( void );

	FragTrap &	operator=( FragTrap const & rhs );

	void	attack( const std::string& target );
	void	highFivesGuys( void );

private:

};
