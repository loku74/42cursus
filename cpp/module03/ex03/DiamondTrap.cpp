#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : ScavTrap(), FragTrap()
{

}


DiamondTrap::DiamondTrap( DiamondTrap const & src )
{
	*this = src;
}


DiamondTrap::~DiamondTrap( void )
{

}


DiamondTrap &	DiamondTrap::operator=( DiamondTrap const & rhs )
{
	return (*this);
}
