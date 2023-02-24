#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) : FragTrap(), ScavTrap()
{
	_name = "default";
	ClapTrap::_name = _name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << YELLOW << "DiamondTrap " << GREEN << _name << BLUE << " constructed !" << NC << std::endl;
}


DiamondTrap::DiamondTrap( DiamondTrap const & src ) : ClapTrap(src), FragTrap(src), ScavTrap(src)
{
	std::cout << GRAY << "DiamondTrap copy constructor called." << NC << std::endl;
	*this = src;
}


DiamondTrap::DiamondTrap( const std::string& name ) : FragTrap(), ScavTrap()
{
	_name = name;
	ClapTrap::_name = name + "_clap_name";
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
}


DiamondTrap::~DiamondTrap( void )
{
	std::cout << YELLOW << "DiamondTrap " << GREEN << _name << RED << " destructed !" << NC << std::endl;
}


DiamondTrap &	DiamondTrap::operator=( DiamondTrap const & rhs )
{
	std::cout << GRAY << "DiamondTrap assigment operator called." << NC << std::endl;
	if (this != &rhs)
	{
		_name = rhs._name;
		_attackDamage = rhs._attackDamage;
		_hitPoints = rhs._hitPoints;
		_energyPoints = rhs._energyPoints;
	}
	return (*this);
}


void	DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}


void	DiamondTrap::whoAmI( void )
{
	std::cout << YELLOW << "My name is " << GREEN << _name << YELLOW << " and my clap_trap name is " << GREEN << ClapTrap::_name << NC << std::endl;
}
