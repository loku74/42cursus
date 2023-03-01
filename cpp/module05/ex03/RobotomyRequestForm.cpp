#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( std::string const target ) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
	std::srand(std::time(NULL));
}


RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & toCopy ) : Form(toCopy.getName(), toCopy.getGradeToSign(), toCopy.getGradeToExecute())
{
	*this = toCopy;
}


RobotomyRequestForm::~RobotomyRequestForm( void )
{

}


RobotomyRequestForm&	RobotomyRequestForm::operator=( RobotomyRequestForm const & toAssign )
{
	if (this != &toAssign)
	{
		Form::operator=(toAssign);
		_target = toAssign._target;
	}
	return (*this);
}


void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
	{
		throw FormNotSignedException();
	}

	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	if (rand() % 2)
		std::cout << GREEN << _target << " has been robotomized successfully." << NC << std::endl;
	else
		std::cout << RED << "Robotomy failed." << NC << std::endl;

}