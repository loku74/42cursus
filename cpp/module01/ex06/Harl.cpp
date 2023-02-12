#include "Harl.hpp"

Harl::Harl() { }

Harl::~Harl() { }

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]\n"
	"I love having extra bacon for my 7XL-double-cheese-"
	"triple-pickle-specialketchup burger. I really do!\n"
	<< std::endl;

}

void	Harl::info( void )
{
	std::cout << "[ INFO ]\n"
	"I cannot believe adding extra bacon costs more money.\nYou didn’t put "
	"enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
	<< std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]\n"
	"I think I deserve to have some extra bacon for free.\nI’ve been coming for "
	"years whereas you started working here since last month.\n"
	<< std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]\n"
	"This is unacceptable! I want to speak to the manager now.\n"
	<< std::endl;
}

void	Harl::complain( std::string level )
{
	std::string	levels[4] = {
			"DEBUG",
			"INFO",
			"WARNING",
			"ERROR"
	};

	void (Harl::*functions[4])(void) = {
			&Harl::debug,
			&Harl::info,
			&Harl::warning,
			&Harl::error
	};

	int	index = -1;
	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			index = i;
			break ;
		}
	}

	e_filter	filter;
	switch (index)
	{
		case DEBUG:		filter = DEBUG;		break ;
		case INFO:		filter = INFO;		break ;
		case WARNING:	filter = WARNING;	break ;
		case ERROR:		filter = ERROR;		break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			return ;
	}

	for (int i = filter; i < 4; i++)
		(this->*functions[i])();
}
