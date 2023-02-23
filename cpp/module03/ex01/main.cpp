#include "ScavTrap.hpp"

int	main( void )
{
	ScavTrap test;
	ScavTrap scav("scav");

	test.attack("other scavtrap");

	test.guardGate();
	scav.takeDamage(99);
	scav.takeDamage(99);
	scav.beRepaired(100);
	scav.guardGate();

	ScavTrap test2(test);
	test2.guardGate();

	return (0);
}