#include "Intern.hpp"

int	main( void )
{
	Intern		slave;
	Bureaucrat	master("class", 1);

	Form* form = slave.makeForm("RobotomyRequestForm", "lol");
	master.signForm(*form);
	master.executeForm(*form);
	return (0);
}
