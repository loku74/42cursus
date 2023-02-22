#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap test;
	ScavTrap scav("scav");

	test.attack("lol");

	test.guardGate();
	scav.takeDamage(99);
	scav.takeDamage(99);
	scav.guardGate();

	return (0);
}