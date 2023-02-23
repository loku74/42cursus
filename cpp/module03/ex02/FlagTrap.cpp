#include "FlagTrap.hpp"

FlagTrap::FlagTrap( void ) : ClapTrap()
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << YELLOW << "FlagTrap " << GREEN << _name << BLUE << " constructed !" << NC << std::endl;
}


FlagTrap::FlagTrap( const std::string& name ) : ClapTrap(name)
{
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << YELLOW << "FlagTrap " << GREEN << _name << BLUE << " constructed !" << NC << std::endl;
}


FlagTrap::FlagTrap( FlagTrap const & src ) : ClapTrap()
{
	std::cout << GRAY << "FlagTrap copy constructor called." << NC << std::endl;

	*this = src;
}


FlagTrap::~FlagTrap( void )
{
	std::cout << YELLOW << "FlagTrap " << GREEN << _name << RED << " destructed !" << NC << std::endl;
}


FlagTrap &	FlagTrap::operator=( FlagTrap const & rhs )
{
	std::cout << GRAY << "FlagTrap assignment operator called." << NC << std::endl;
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hitPoints = rhs._hitPoints;
		this->_energyPoints = rhs._energyPoints;
		this->_attackDamage = rhs._attackDamage;
	}

	return (*this);
}


void	FlagTrap::attack(const std::string &target)
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


void	FlagTrap::highFivesGuys( void )
{
	if (_hitPoints == 0)
	{
		std::cout << GREEN << _name << RED << " is dead !" << YELLOW << " He can't high fives anyone..." << NC << std::endl;
		return ;
	}
	std::cout << YELLOW << "FlagTrap " << GREEN <<  _name << PURPLE << " is requesting for an high five !" << NC << std::endl;
}
