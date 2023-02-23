#include "FlagTrap.hpp"

int	main( void )
{
	FlagTrap test;
	FlagTrap scav("flag");

	test.attack("other flagtrap");

	scav.takeDamage(99);
	scav.highFivesGuys();
	scav.takeDamage(99);
	scav.beRepaired(100);

	FlagTrap test2(test);
	test2.highFivesGuys();

	return (0);
}