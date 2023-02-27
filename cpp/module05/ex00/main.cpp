#include "Bureaucrat.hpp"
#include "colors.h"

int	main( void )
{

	std::cout << ORANGE << "- ERROR IN CONSTRUCTOR -" << NC << std::endl;
	try
	{
		Bureaucrat fail("test", 0);
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat fail("test", 151);
		std::cout << fail << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << ORANGE << "- ERROR IN INCREMENT/DECREMENT -" << NC << std::endl;
	try
	{
		Bureaucrat fail("test", 150);
		std::cout << fail << std::endl;
		fail.gradeDecrement();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat fail("test", 1);
		std::cout << fail << std::endl;
		fail.gradeIncrement();
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << GREEN << "- SUCCESS - " << NC << std::endl;
	Bureaucrat lol("lol", 42);
	lol.gradeIncrement();
	lol.gradeDecrement();
	std::cout << lol << std::endl;

	return (0);
}
