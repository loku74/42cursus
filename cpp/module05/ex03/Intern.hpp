#pragma once

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{

public:

	Intern( void );
	Intern( Intern const & toCopy );
	~Intern( void );

	Intern&	operator=( Intern const & toAssign );

	Form*	makeForm( std::string form_name, std::string target ) const;

private:

};
