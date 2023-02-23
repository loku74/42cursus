#pragma once

#include "ClapTrap.hpp"

class FlagTrap : public ClapTrap
{

public:

	FlagTrap( void );
	FlagTrap( FlagTrap const & src );
	FlagTrap( const std::string& name );
	~FlagTrap( void );

	FlagTrap &	operator=( FlagTrap const & rhs );

	void	attack( const std::string& target );
	void	highFivesGuys( void );

private:

};
