#include "Intern.hpp"

int	main( void )
{
	std::cout << ORANGE << "--- TEST 1: RobotomyRequestForm ---" << NC << std::endl;
	{
		Intern		intern;
		Bureaucrat	master("class", 1);

		Form* form = intern.makeForm("RobotomyRequestForm", "lol");
		master.signForm(*form);
		master.executeForm(*form);

		delete form;
	}

	std::cout << ORANGE << "--- TEST 2: ShrubberyCreationForm ---" << NC << std::endl;
	{
		Intern		intern;
		Bureaucrat	master("class", 1);

		Form* form = intern.makeForm("ShrubberyCreationForm", "lol");
		master.signForm(*form);
		master.executeForm(*form);

		delete form;
	}

	std::cout << ORANGE << "--- TEST 3: PresidentialPardonForm ---" << NC << std::endl;
	{
		Intern		intern;
		Bureaucrat	master("class", 1);

		Form* form = intern.makeForm("PresidentialPardonForm", "lol");
		master.signForm(*form);
		master.executeForm(*form);

		delete form;
	}

	std::cout << ORANGE << "--- TEST 4: ERRORS ---" << NC << std::endl;
	{
		Intern		intern;
		Bureaucrat	master("class", 1);

		Form* form = intern.makeForm("Form", "lol");
		if (form)
		{
			master.signForm(*form);
			master.executeForm(*form);
		}

		delete form;
	}
	return (0);
}
