#pragma once

#include "Form.hpp"

class ShrubberyCreationForm : public Form
{

public:

	ShrubberyCreationForm( std::string const target );
	ShrubberyCreationForm( ShrubberyCreationForm const & toCopy );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm&	operator=( ShrubberyCreationForm const & toAssign );

	void	execute( Bureaucrat const & executor) const;

private:

	std::string	_target;

};
