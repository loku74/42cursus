#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : FragTrap(), ScavTrap()
{

}


DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap(DiamondTrap), FragTrap(DiamondTrap), ScavTrap(DiamondTrap)
{
	*this = src;
}


DiamondTrap::~DiamondTrap( void )
{

}


DiamondTrap &	DiamondTrap::operator=( DiamondTrap const & rhs )
{
	if (this != &rhs)
	{
		_name = rhs._name;
		_attackDamage = rhs._attackDamage;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
	}
	return (*this);
}
