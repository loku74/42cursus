#pragma once

#include "Weapon.hpp"

class HumanA
{
public:

	HumanA( const std::string& name, Weapon &weapon );
	~HumanA();

	void	attack( void );

private:

	std::string _name;
	Weapon&		_weapon;

};