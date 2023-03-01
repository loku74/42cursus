#include "Intern.hpp"

Intern::Intern( void )
{
	//std::cout << GRAY << "(Intern)" << GREEN << " -> Default constructor called" << NC << std::endl;
}


Intern::Intern( Intern const & toCopy )
{
	std::cout << GRAY << "(Intern) -> Copy constructor called" << NC << std::endl;

	*this = toCopy;
}


Intern::~Intern( void )
{
	//std::cout << GRAY << "(Intern)" << RED << " -> Default destructor called" << NC << std::endl;
}


Intern&	Intern::operator=( Intern const & toAssign )
{
	std::cout << GRAY << "(Intern) -> Assignment operator called" << NC << std::endl;
	(void)toAssign;

	return (*this);
}


static Form*	createPresidentialPardonForm( std::string target )
{
	return (new PresidentialPardonForm(target));
}


static Form*	createRobotomyRequestForm( std::string target )
{
	return (new RobotomyRequestForm(target));
}


static Form*	createShrubberyCreationForm( std::string target )
{
	return (new ShrubberyCreationForm(target));
}


Form*	Intern::makeForm(std::string form_name, std::string target) const
{
	static const std::string	forms[3] = {
			"PresidentialPardonForm",
			"RobotomyRequestForm",
			"ShrubberyCreationForm"
	};

	static Form* (*formFunctions[3])(std::string) = {
		&createPresidentialPardonForm,
		&createRobotomyRequestForm,
		&createShrubberyCreationForm
	};

	int	index;
	for ( index = 0; index < 3; index++)
	{
		if (forms[index] == form_name)
			break ;
	}

	if (index > 2)
	{
		std::cerr << RED << "Error: Form not found." << NC << std::endl;
		return (NULL);
	}

	return ( (*formFunctions[index])(target) );
}