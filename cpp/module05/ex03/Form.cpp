#include "Bureaucrat.hpp"

Form::Form( std::string name, int const gradeToSign, int const gradeToExecute ) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooLowException();
}


Form::Form( Form const & toCopy ) : _name(toCopy.getName()), _gradeToSign(toCopy.getGradeToSign()), _gradeToExecute(toCopy._gradeToExecute)
{
	*this = toCopy;
}


Form::~Form( void )
{

}


Form&	Form::operator=( Form const & toAssign )
{
	if (this != &toAssign)
	{
		_isSigned = toAssign.isSigned();
	}
	return (*this);
}


// getter(s)
std::string const &	Form::getName( void ) 			const	{ return _name;				}
bool				Form::isSigned( void )			const	{ return _isSigned;			}
int const &			Form::getGradeToSign( void )	const	{ return _gradeToSign;		}
int const &			Form::getGradeToExecute( void )	const	{ return _gradeToExecute;	}


static std::string	boolToString( bool status )
{
	if (status)
		return ("true");
	return ("false");
}


std::ostream&	operator<<( std::ostream& stream, Form const & form )
{
	stream << "Form name: " << form.getName() << std::endl;
	stream << "Form signed status: " << boolToString(form.isSigned()) << std::endl;
	stream << "Form grade to sign: " << form.getGradeToSign() << std::endl;
	stream << "Form grade to execute: " << form.getGradeToExecute() << std::endl;
	return (stream);
}


void	Form::beSigned( Bureaucrat const & bureaucrat )
{
	if (_gradeToSign < bureaucrat.getGrade())
		throw GradeTooLowException();
	_isSigned = true;
}
