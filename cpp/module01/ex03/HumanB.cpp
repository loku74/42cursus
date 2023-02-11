#include "HumanB.hpp"

HumanB::HumanB( const std::string &name ) : _name(name), _weapon(NULL)
{

}

HumanB::~HumanB()
{

}

void	HumanB::attack( void )
{
	if (_weapon == NULL)
		std::cout << _name << " attacks with their fists" << std::endl;
	else
		std::cout << _name << " attacks with their " << _weapon->getType() << std::endl;
}

// setter(s)
void	HumanB::setWeapon( Weapon &weapon )
{
	_weapon = &weapon;
}
