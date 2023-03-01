#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) : Form("ShrubberyCreationForm", 25 , 5), _target(target)
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
	if (this != &toAssign)
	{
		Form::operator=(toAssign);
		_target = toAssign._target
	}
	return (*this);
}
