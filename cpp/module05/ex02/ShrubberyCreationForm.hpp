#pragma once

#include "Form.hpp"

class ShrubberyCreationForm
{

public:

	ShrubberyCreationForm( Form const & form );
	ShrubberyCreationForm( ShrubberyCreationForm const & toCopy );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm&	operator=( ShrubberyCreationForm const & toAssign );

private:

};
