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
	std::cout << YELLOW << "ScavTrap " << GREEN << _name << BLUE << " constructed !" << NC << std::endl;
}


ScavTrap::ScavTrap( ScavTrap const & src ) : ClapTrap()
{
	std::cout << GRAY << "ScavTrap copy constructor called." << NC << std::endl;

	*this = src;
}


ScavTrap::~ScavTrap( void )
{
	std::cout << YELLOW << "ScavTrap " << GREEN << _name << RED << " destructed !" << NC << std::endl;
}


ScavTrap &	ScavTrap::operator=( ScavTrap const & rhs )
{
	std::cout << GRAY << "ScavTrap assignment operator called." << NC << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	return (*this);
}


void	ScavTrap::attack(const std::string &target)
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << GREEN << _name << YELLOW << " slices " << BLUE << target << YELLOW << " ! " << RED << "-" << _attackDamage << "HP" << YELLOW << "." << NC << std::endl;
		_energyPoints--;
	}
	else if (_energyPoints > 0)
		std::cout << GREEN << _name << RED << " is dead !" << YELLOW << " He can't attack anyone." << NC << std::endl;
	else
		std::cout << GREEN << _name << ORANGE << " has no energy left !" << NC << std::endl;
}


void	ScavTrap::guardGate( void )
{
	if (_hitPoints == 0)
	{
		std::cout << GREEN << _name << RED << " is dead !" << YELLOW << " He can't guard any gate." << NC << std::endl;
		return ;
	}
	std::cout << YELLOW << "Scavtrap " << GREEN <<  _name << PURPLE << " is now in Gate keeper mode." << NC << std::endl;
}
