#pragma once

#include "Form.hpp"

class PresidentialPardonForm : public Form
{

public:

	PresidentialPardonForm( Form const & form );
	PresidentialPardonForm( PresidentialPardonForm const & toCopy );
	~PresidentialPardonForm( void );

	PresidentialPardonForm&	operator=( PresidentialPardonForm const & toAssign );

private:

};
