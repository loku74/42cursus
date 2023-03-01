#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string const target ) : Form("PresidentialPardonForm", 145, 137), _target(target)
{

}


PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & toCopy )
{
	*this = toCopy;
}


PresidentialPardonForm::~PresidentialPardonForm( void )
{

}


PresidentialPardonForm&	PresidentialPardonForm::operator=( PresidentialPardonForm const & toAssign )
{
	if (this != &toAssign)
	{
		Form::operator=(toAssign);
		_target = toAssign._target
	}
	return (*this);
}


void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
	{
		std::cerr << RED << "Form is not signed: cannot be executed." << NC << std::endl;
		return ;
	}

	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();
	else
		std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox." << NC << std::endl;
}
