#include "ScavTrap.hpp"

ScavTrap::ScavTrap( void ) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << YELLOW << "ScavTrap " << GREEN << _name << BLUE << " constructed !" << NC << std::endl;
}


ScavTrap::ScavTrap( const std::string& name ) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
	std::cout << YELLOW << "ClapTrap " << GREEN << _name << BLUE << " constructed !" << NC << std::endl;
}


ScavTrap::ScavTrap( ScavTrap const & src )
{
	std::cout << GRAY << "ScavTrap copy constructor called" << NC << std::endl;

	*this = src;
}


ScavTrap::~ScavTrap( void )
{
	std::cout << YELLOW << "ScavTrap " << GREEN << _name << RED << " destructed !" << NC << std::endl;
}


ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs )
{
	(void)rhs;
	std::cout << GRAY << "ScavTrap assignment operator called" << NC << std::endl;

	return (*this);
}


void	ScavTrap::attack(const std::string &target)
{
	std::cout << GREEN << _name << YELLOW << " slices " << BLUE << target << YELLOW << " ! " << RED << "-" << _attackDamage << "HP" << YELLOW << "." << std::endl;
}


void	ScavTrap::guardGate( void )
{
	if (_hitPoints == 0)
	{
		std::cout << YELLOW << "Scavtrap " << RED << "is dead !" << YELLOW << " He can't guard any gate." << NC << std::endl;
		return ;
	}
	std::cout << YELLOW << "Scavtrap " << GREEN <<  _name << PURPLE << " is now in Gate keeper mode." << NC << std::endl;
}
