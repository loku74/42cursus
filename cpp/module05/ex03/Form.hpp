#pragma once

#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
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

	class FormNotSignedException: public std::exception
	{
		virtual const char* what( void ) const throw()
		{
			return ("Form not signed");
		}
	};

	Form( std::string name, int const gradeToSign, int const gradeToExecute );
	Form( Form const & toCopy );
	~Form( void );

	Form&	operator=( Form const & toAssign );

	// getter(s)
	std::string const &	getName( void ) 			const;
	bool				isSigned( void ) 			const;
	int const &			getGradeToSign( void ) 		const;
	int const &			getGradeToExecute( void ) 	const;

	void			beSigned( Bureaucrat const & bureaucrat );
	virtual void	execute( Bureaucrat const & executor ) const = 0;

private:

	std::string const	_name;
	bool				_isSigned;
	int const			_gradeToSign;
	int const			_gradeToExecute;

};

std::ostream&	operator<<( std::ostream& stream, Form const & form );
