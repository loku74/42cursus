#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( std::string const target ) : Form("PresidentialPardonForm", 25, 5), _target(target)
{

}


PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & toCopy ) : Form(toCopy.getName(), toCopy.getGradeToSign(), toCopy.getGradeToExecute())
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
		_target = toAssign._target;
	}
	return (*this);
}


void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	if (!isSigned())
	{
		throw FormNotSignedException();
	}

	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << GREEN << _target << " has been pardoned by Zaphod Beeblebrox." << NC << std::endl;
}
