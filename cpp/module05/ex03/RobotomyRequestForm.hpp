#pragma once

#include "Form.hpp"
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public Form
{

public:

	RobotomyRequestForm( std::string const target );
	RobotomyRequestForm( RobotomyRequestForm const & toCopy );
	~RobotomyRequestForm( void );

	RobotomyRequestForm&	operator=( RobotomyRequestForm const & toAssign );

	void	execute( Bureaucrat const & executor ) const;

private:

	std::string	_target;

};
