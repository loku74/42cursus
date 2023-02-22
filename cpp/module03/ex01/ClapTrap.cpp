#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ) : _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	this->_name = "default";
	std::cout << YELLOW << "ClapTrap " << GREEN << _name << BLUE << " constructed !" << NC << std::endl;
}


ClapTrap::ClapTrap( ClapTrap const & src )
{
	std::cout << GRAY << "ClapTrap copy constructor called" << NC << std::endl;

	*this = src;
}


ClapTrap::ClapTrap( const std::string& name ) : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << YELLOW << "ClapTrap " << GREEN << _name << BLUE << " constructed !" << NC << std::endl;
}


ClapTrap::~ClapTrap( void )
{
	std::cout << YELLOW << "ClapTrap " << GREEN << _name << RED << " destructed !" << NC << std::endl;
}


ClapTrap &	ClapTrap::operator=( ClapTrap const & rhs )
{
	std::cout << GRAY << "ClapTrap assignment constructor called" << NC << std::endl;

	if (this != &rhs)
	{
		this->_name			= rhs._name;
		this->_hitPoints	= rhs._hitPoints;
		this->_energyPoints	= rhs._energyPoints;
		this->_attackDamage	= rhs._attackDamage;
	}
	return (*this);
}

void	ClapTrap::attack( const std::string& target )
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << GREEN << _name << YELLOW << " attacks " << BLUE << target << YELLOW << " ! " << RED << "-" << _attackDamage << "HP" << YELLOW << "." << NC << std::endl;
		_energyPoints--;
	}
	else if (_energyPoints > 0)
		std::cout << GREEN << _name << RED << " is dead !" << YELLOW << " He can't attack anyone." << NC << std::endl;
	else
		std::cout << GREEN << _name << ORANGE << " has no energy left !" << NC << std::endl;
}


void	ClapTrap::takeDamage( unsigned int amount )
{
	if (_hitPoints == 0)
	{
		std::cout << GREEN << _name << RED << " is dead ! " << YELLOW << "He can't take more damage." << NC << std::endl;
		return ;
	}

	if (amount > _hitPoints)
		_hitPoints = 0;
	else
		_hitPoints -= amount;

	std::cout << GREEN << _name << YELLOW << " took " << RED << amount << YELLOW << " damage" << " (" << _hitPoints << " HP left)." << NC << std::endl;
}


void	ClapTrap::beRepaired( unsigned int amount )
{
	if (_energyPoints > 0 && _hitPoints > 0)
	{
		std::cout << GREEN << _name << YELLOW << " gained " << BLUE << amount << YELLOW << " HP!" << NC << std::endl;
		_hitPoints += amount;
		_energyPoints--;
	}
	else if (_hitPoints > 0)
		std::cout << GREEN << _name << ORANGE << " has no energy left !" << NC << std::endl;
	else
		std::cout << GREEN << _name << RED << " is dead !" << YELLOW << " He can't live again..." <<  NC << std::endl;
}
