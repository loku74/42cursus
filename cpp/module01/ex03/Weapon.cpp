#include "Weapon.hpp"

Weapon::Weapon( const std::string& name ) : _type(name)
{

}

Weapon::~Weapon()
{

}

// getter(s)
const std::string	&Weapon::getType( void ) { return _type; }

// setter(s)
void	Weapon::setType( const std::string& to_set )
{
	_type = to_set;
}
