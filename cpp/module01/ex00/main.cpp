#include "Zombie.hpp"

int	main( void )
{

	// Zombie on heap memory
	Zombie	*zombie1;

	zombie1 = newZombie("zombie on heap");
	if (zombie1 == NULL)
		return (1);
	zombie1->announce();
	delete zombie1;

	// Zombie on stack memory
	randomChump("zombie on stack");

	// Zombie on stack without a defined name
	Zombie zombie2;

	zombie2.announce();

	return (0);
}
