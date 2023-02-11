#pragma once

#include "Weapon.hpp"

class HumanB
{
public:

	HumanB( const std::string &name );
	~HumanB();

	void	attack( void );

	// setter(s)
	void	setWeapon( Weapon& weapon );

private:

	std::string _name;
	Weapon*		_weapon;

};