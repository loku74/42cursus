#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( Form const & form )
{

}


ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & toCopy )
{
	*this = toCopy;
}


ShrubberyCreationForm::~ShrubberyCreationForm( void )
{

}


ShrubberyCreationForm&	ShrubberyCreationForm::operator=( ShrubberyCreationForm const & toAssign )
{
	return (*this);
}
