#include "Zombie.hpp"

int	main( void )
{
	Zombie		*horde;
	int		hordeSize = 10;

	horde = zombieHorde(hordeSize, "zombie");
	if (horde == NULL)
		return (1);

	for (int i = 0; i < hordeSize; i++)
		horde[i].announce();

	delete[] horde;

	return (0);
}
