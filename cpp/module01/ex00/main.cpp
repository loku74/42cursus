#include "Zombie.hpp"

int	main( void )
{
	Zombie	*zombie;

	zombie = newZombie("zombie on heap");
	if (zombie == NULL)
		return (1);
	zombie->announce();
	delete zombie;

	randomChump("zombie on stack");
	return (0);
}