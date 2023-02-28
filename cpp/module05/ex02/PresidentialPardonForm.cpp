#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( Form const & form )
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
	return (*this);
}
