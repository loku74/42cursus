#include "FragTrap.hpp"

int	main( void )
{
	FragTrap test;
	FragTrap scav("flag");

	test.attack("other FragTrap");

	scav.takeDamage(99);
	scav.highFivesGuys();
	scav.takeDamage(99);
	scav.beRepaired(100);

	FragTrap test2(test);
	test2.highFivesGuys();

	return (0);
}