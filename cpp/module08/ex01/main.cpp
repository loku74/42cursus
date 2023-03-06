#include "Span.hpp"

int	main( void )
{

	std::cout << ORANGE << "--- TEST 1: Subject test ---" << NC << std::endl;
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	std::cout << ORANGE << "--- TEST 2: 0 to 100,000 ---" << NC << std::endl;
	{
		Span	test(100000);

		for (int i = 0; i < 100000; i++)
			test.addNumber(i);

		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}

	std::cout << ORANGE << "--- TEST 3: filling with iterators---" << NC << std::endl;
	{
		Span				test(4242);
		std::vector<int>	fill;

		for (int i = 0; i < 4242; i++)
			fill.push_back(i * i);

		test.addNumbers(fill.begin(), fill.end());
		std::cout << test.shortestSpan() << std::endl;
		std::cout << test.longestSpan() << std::endl;
	}

	std::cout << ORANGE << "--- TEST 4: Exceptions: ---" << NC << std::endl;
	std::cout << YELLOW << "-> With the addNumber function:" << NC << std::endl;
	{
		Span				test(1);

		try
		{
			test.addNumber(42);
			test.addNumber(42);
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
	}

	std::cout << YELLOW << "-> With the addNumbers function (using iterators):" << NC << std::endl;
	{
		Span				test(1);
		std::vector<int>			fill;

		for (int i = 0; i < 10; i++)
			fill.push_back(i);

		try
		{
			test.addNumbers(fill.begin(), fill.end());
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
	}

	std::cout << YELLOW << "-> longestSpan() without a Span long enough:" << NC << std::endl;
	{
		Span				test(1);

		test.addNumber(42);
		try
		{
			std::cout << test.longestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
	}

	std::cout << YELLOW << "-> shortestSpan() without a Span long enough:" << NC << std::endl;
	{
		Span				test(1);

		test.addNumber(42);
		try
		{
			std::cout << test.shortestSpan() << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
		}
	}

	return (0);
}