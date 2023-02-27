#pragma once

#include <iostream>
#include <stdexcept>
#include "Bureaucrat.hpp"

class Bureaucrat
{

public:

	class GradeTooLowException: public std::exception
	{
		virtual const char* what( void ) const throw()
		{
			return ("Grade too low");
		}
	};

	class GradeTooHighException: public std::exception
	{
		virtual const char* what( void ) const throw()
		{
			return ("Grade too high");
		}
	};

	Bureaucrat( std::string name, int grade );
	Bureaucrat( Bureaucrat const & toCopy );
	~Bureaucrat( void );

	Bureaucrat&	operator=( Bureaucrat const & toAssign );

	void	gradeIncrement( void );
	void	gradeDecrement( void );

	// getter(s)

	int					getGrade( void ) const;
	std::string	const	getName( void ) const;

private:

	std::string const	_name;
	int					_grade;

};

std::ostream&	operator<<( std::ostream& stream, Bureaucrat const & bureaucrat );
