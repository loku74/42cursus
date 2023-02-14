#include "Zombie.hpp"

Zombie::Zombie() : _name("zombie")
{

}

void Zombie::announce( void )
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie ( const std::string& name ) : _name(name)
{

}

Zombie::~Zombie()
{
	std::cout << _name << " deleted" << std::endl;
}
