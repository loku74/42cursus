#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	test("lol");
	ClapTrap	test2;

	test2.attack("lol");
	test.beRepaired( 5);
	//test.takeDamage(10);
	test.attack("lol");
	test.attack("lol");
	test.attack("lol");
	test.attack("lol");
	test.attack("lol");
	test.attack("lol");
	test.attack("lol");
	test.attack("lol");
	test.attack("lol");
	test.attack("lol");
	test.attack("lol");
	test.beRepaired(10);
	test.takeDamage(10);
	return (0);
}