#include "ClapTrap.hpp"

int	main( void )
{
	ClapTrap	test("lol");

	std::cout << "--- TEST ---" << std::endl;
	test.beRepaired( 5);
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
	test.takeDamage(10);
	test.takeDamage(10);

	std::cout << "--- TEST 2 ---" << std::endl;
	ClapTrap test2(test);
	test2.attack("lol");
	test2.beRepaired( 5);
	test2.takeDamage(10);

	std::cout << "--- TEST 3 ---" << std::endl;
	ClapTrap test3;
	test3 = test2;
	test3.attack("lol");
	test3.beRepaired( 5);
	test3.takeDamage(10);

	return (0);
}