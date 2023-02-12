#include "Harl.hpp"

Harl::Harl() { }

Harl::~Harl() { }

void	Harl::debug( void )
{
	std::cout <<
	"I love having extra bacon for my 7XL-double-cheese-"
	"triple-pickle-specialketchup burger. I really do!"
	<< std::endl;

}

void	Harl::info( void )
{
	std::cout <<
	"I cannot believe adding extra bacon costs more money. You didn’t put "
	"enough bacon in my burger! If you did, I wouldn’t be asking for more!"
	<< std::endl;
}

void	Harl::warning( void )
{
	std::cout <<
	"I think I deserve to have some extra bacon for free. I’ve been coming for "
	"years whereas you started working here since last month."
	<< std::endl;
}

void	Harl::error( void )
{
	std::cout <<
	"This is unacceptable! I want to speak to the manager now."
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
			return ;
	}

	for (int i = filter; i < 4; i++)
		(this->*functions[i])();
}
