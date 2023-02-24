#include "DiamondTrap.hpp"

int	main( void )
{
	DiamondTrap d;

	d.beRepaired(100);
	d.attack("lol");
	d.takeDamage(100);

	DiamondTrap test(d);
	test.attack("qw");

	test.whoAmI();

	DiamondTrap lol("lol");
	lol.whoAmI();

	return (0);
}