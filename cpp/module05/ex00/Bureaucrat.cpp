#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name(name), _grade(grade)
{
	if (_grade > 150)
		throw GradeTooLowException();
	else if (_grade < 1)
		throw GradeTooHighException();
}

Bureaucrat::Bureaucrat( Bureaucrat const & toCopy ) : _name(toCopy.getName())
{
	*this = toCopy;
}


Bureaucrat::~Bureaucrat( void )
{

}


Bureaucrat&	Bureaucrat::operator=( Bureaucrat const & toAssign )
{
	if (this != &toAssign)
	{
		_grade = toAssign.getGrade();
	}
	return (*this);
}


void	Bureaucrat::gradeIncrement( void )
{
	_grade--;
	if (_grade < 1)
		throw GradeTooHighException();
}


void	Bureaucrat::gradeDecrement( void )
{
	_grade++;
	if (_grade > 150)
		throw GradeTooHighException();
}


// getter(s)
int					Bureaucrat::getGrade( void )	const	{ return _grade;	}
std::string	const	Bureaucrat::getName( void )		const	{ return _name;		}

std::ostream&	operator<<( std::ostream& stream, Bureaucrat const & bureaucrat )
{
	stream << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (stream);
}
