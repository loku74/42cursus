#pragma once

#include "Form.hpp"

class RobotomyRequestForm : public Form
{

public:

	RobotomyRequestForm( Form const & form );
	RobotomyRequestForm( RobotomyRequestForm const & toCopy );
	~RobotomyRequestForm( void );

	RobotomyRequestForm&	operator=( RobotomyRequestForm const & toAssign );

private:

};
