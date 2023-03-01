#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main( void )
{
	std::cout << ORANGE << "--- TEST 1: RobotomyRequestForm ---" << NC << std::endl;
	{
		RobotomyRequestForm form("target");
		Bureaucrat			pascal("Pascal", 1);
		Bureaucrat			pascal_mais_nul("Pascal_mais_nul", 150);


		std::cout << PURPLE << "-> Trying to execute when the form is not signed:" << NC << std::endl;
		std::cout << "Pascal tries to execute: ";
		pascal.executeForm(form);
		std::cout << "Pascal_mais_nul tries to execute: ";
		pascal_mais_nul.executeForm(form);
		try
		{
			std::cout << "Form trying to be executed by Pascal: ";
			form.execute(pascal);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
		try
		{
			std::cout << "Form trying to be executed by Pascal_mais_nul: ";
			form.execute(pascal_mais_nul);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}


		std::cout << PURPLE << "-> Trying to sign the form:" << NC << std::endl;
		std::cout << "Pascal tries to sign: ";
		pascal.signForm(form);
		std::cout << "Pascal_mais_nul tries to execute: ";
		pascal_mais_nul.signForm(form);
		try
		{
			std::cout << "Form trying to be signed by Pascal: ";
			form.beSigned(pascal_mais_nul);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
		try
		{
			std::cout << "Form trying to be signed by Pascal_mais_nul: ";
			form.beSigned(pascal_mais_nul);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}


		std::cout << PURPLE << "-> Trying to execute: " << NC << std::endl;
		std::cout << "Pascal tries to execute: ";
		pascal.executeForm(form);
		std::cout << "Pascal_mais_nul tries to execute: ";
		pascal_mais_nul.executeForm(form);
		try
		{
			std::cout << "Form trying to be executed by Pascal: ";
			form.execute(pascal);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
		try
		{
			std::cout << "Form trying to be executed by Pascal_mais_nul: ";
			form.execute(pascal_mais_nul);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
	}

	std::cout << ORANGE << "--- TEST 2: ShrubberyCreationForm ---" << NC << std::endl;
	{
		ShrubberyCreationForm	form("target");
		Bureaucrat				pascal("pascal", 1);
		Bureaucrat				pascal_mais_nul("pascal_mais_nul", 150);


		std::cout << PURPLE << "-> Trying to execute when the form is not signed:" << NC << std::endl;
		std::cout << "Pascal tries to execute: ";
		pascal.executeForm(form);
		std::cout << "Pascal_mais_nul tries to execute: ";
		pascal_mais_nul.executeForm(form);
		try
		{
			std::cout << "Form trying to be executed by Pascal: ";
			form.execute(pascal);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
		try
		{
			std::cout << "Form trying to be executed by Pascal_mais_nul: ";
			form.execute(pascal_mais_nul);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}


		std::cout << PURPLE << "-> Trying to sign the form:" << NC << std::endl;
		std::cout << "Pascal tries to sign: ";
		pascal.signForm(form);
		std::cout << "Pascal_mais_nul tries to execute: ";
		pascal_mais_nul.signForm(form);
		try
		{
			std::cout << "Form trying to be signed by Pascal: ";
			form.beSigned(pascal_mais_nul);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
		try
		{
			std::cout << "Form trying to be signed by Pascal_mais_nul: ";
			form.beSigned(pascal_mais_nul);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}


		std::cout << PURPLE << "-> Trying to execute: " << NC << std::endl;
		std::cout << "Pascal tries to execute: ";
		pascal.executeForm(form);
		std::cout << "Pascal_mais_nul tries to execute: ";
		pascal_mais_nul.executeForm(form);
		try
		{
			std::cout << "Form trying to be executed by Pascal: ";
			form.execute(pascal);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
		try
		{
			std::cout << "Form trying to be executed by Pascal_mais_nul: ";
			form.execute(pascal_mais_nul);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
	}

	std::cout << ORANGE << "--- TEST 3: PresidentialPardonForm ---" << NC << std::endl;
	{
		PresidentialPardonForm	form("target");
		Bureaucrat				pascal("pascal", 1);
		Bureaucrat				pascal_mais_nul("pascal_mais_nul", 150);


		std::cout << PURPLE << "-> Trying to execute when the form is not signed:" << NC << std::endl;
		std::cout << "Pascal tries to execute: ";
		pascal.executeForm(form);
		std::cout << "Pascal_mais_nul tries to execute: ";
		pascal_mais_nul.executeForm(form);
		try
		{
			std::cout << "Form trying to be executed by Pascal: ";
			form.execute(pascal);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
		try
		{
			std::cout << "Form trying to be executed by Pascal_mais_nul: ";
			form.execute(pascal_mais_nul);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}


		std::cout << PURPLE << "-> Trying to sign the form:" << NC << std::endl;
		std::cout << "Pascal tries to sign: ";
		pascal.signForm(form);
		std::cout << "Pascal_mais_nul tries to execute: ";
		pascal_mais_nul.signForm(form);
		try
		{
			std::cout << "Form trying to be signed by Pascal: ";
			form.beSigned(pascal_mais_nul);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
		try
		{
			std::cout << "Form trying to be signed by Pascal_mais_nul: ";
			form.beSigned(pascal_mais_nul);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}


		std::cout << PURPLE << "-> Trying to execute: " << NC << std::endl;
		std::cout << "Pascal tries to execute: ";
		pascal.executeForm(form);
		std::cout << "Pascal_mais_nul tries to execute: ";
		pascal_mais_nul.executeForm(form);
		try
		{
			std::cout << "Form trying to be executed by Pascal: ";
			form.execute(pascal);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
		try
		{
			std::cout << "Form trying to be executed by Pascal_mais_nul: ";
			form.execute(pascal_mais_nul);
			std::cout << GREEN << "success" << NC << std::endl;
		}
		catch (std::exception const & e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
	}
	return (0);
}
