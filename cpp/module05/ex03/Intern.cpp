#include "Intern.hpp"

Intern::Intern( void )
{
	std::cout << GRAY << "(Intern)" << GREEN << " -> Default constructor called" << NC << std::endl;
}


Intern::Intern( Intern const & toCopy )
{
	std::cout << GRAY << "(Intern) -> Copy constructor called" << NC << std::endl;

	*this = toCopy;
}


Intern::~Intern( void )
{
	std::cout << GRAY << "(Intern)" << RED << " -> Default destructor called" << NC << std::endl;
}


Intern&	Intern::operator=( Intern const & toAssign )
{
	std::cout << GRAY << "(Intern) -> Assignment operator called" << NC << std::endl;
	(void)toAssign;

	return (*this);
}


Form*	Intern::makeForm(std::string form_name, std::string target) const
{
	static const std::string	forms[3] = {
			"PresidentialPardonForm",
			"RobotomyRequestForm",
			"ShrubberyCreationForm"
	};

	int	index;
	for ( index = 0; index < 3; index++)
	{
		if (forms[index] == form_name)
			break ;
	}

	switch (index)
	{
		case (0): return (new PresidentialPardonForm(target)); break ;
		case (1): return (new RobotomyRequestForm(target)); break ;
		case (2): return (new ShrubberyCreationForm(target)); break ;
		default :
			std::cerr << RED << "Form not found" << NC << std::endl;
			break ;
	}

	return (NULL);
}