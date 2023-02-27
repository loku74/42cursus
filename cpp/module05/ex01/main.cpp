#include "Bureaucrat.hpp"

int	main( void )
{
	std::cout << ORANGE << "- TEST 1 -" << NC << std::endl;
	{
		Bureaucrat	pascal("Pascal", 42);
		Form		form("le rachat de twitter", 42, 42);

		std::cout << pascal << form;

		form.beSigned(pascal); // works but do not print anything
		pascal.signForm(form); // works too and print something

		std::cout << form;
	}

	std::cout << ORANGE << "- TEST 2 -" << NC << std::endl;
	{
		Bureaucrat	pascal("Pascal", 43);
		Form		form("le rachat de twitter", 42, 42);

		std::cout << pascal << form;

		try
		{
			form.beSigned(pascal); // doesn't work
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << NC << std::endl; // will print the error message
		}

		pascal.signForm(form); // doesn't work too
		std::cout << form;
	}

	std::cout << ORANGE << "- TEST 3-" << NC << std::endl;
	{
		// all Forms instantiation will crash
		try
		{
			Form	form("le rachat de twitter", 420, 42);
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}

		try
		{
			Form	form("le rachat de twitter", 0, 42);
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}

		try
		{
			Form	form("le rachat de twitter", 42, 420);
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}

		try
		{
			Form	form("le rachat de twitter", 42, 0);
		}
		catch (std::exception& e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
	}

	return (0);
}
