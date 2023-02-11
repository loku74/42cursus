#include "Zombie.hpp"

Zombie*	newZombie( std::string name )
{
	Zombie	*zombie;

	zombie = new (std::nothrow) Zombie(name);
	if (zombie == NULL)
		return (NULL);
	return (zombie);
}
