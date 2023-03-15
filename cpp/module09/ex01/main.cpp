#include "RPN.hpp"

# define RED "\033[1;31m"
# define NC "\033[0m"

int	main( int ac, char **av )
{

	if (ac != 2)
	{
		std::cerr << RED << "Error: invalid number of argument(s)." << NC << std::endl;
		return (1);
	}

	std::string	input(av[1]);
	RPN			stack;

	for (size_t i = 0; i < input.size(); i++)
	{
		if (isdigit(input[i]))
		{
			stack.push(input[i] - '0');
			continue ;
		}
		else if (i + 1 < input.size() && input[i] == '-' && isdigit(input[i + 1]))
		{
			stack.push(-(input[i + 1] - '0'));
			i++;
			continue ;
		}
		try
		{
			switch (input[i])
			{
				case '+': stack.add();		continue ;
				case '-': stack.subtract();	continue ;
				case '*': stack.multiply();	continue ;
				case '/': stack.divide();	continue ;
				case ' ': 					continue ;
				default:
					std::cerr << RED << "Error: invalid character(s)." << NC << std::endl;
					return (3);
			}
		}
		catch (const std::exception& e)
		{
			std::cerr << RED << e.what() << NC << std::endl;
			return (2);
		}
	}

	std::stack<int> final = stack.getStack();

	if (final.size() != 1)
	{
		std::cerr << RED << "Error: Input not valid; missing operator(s) or operation(s)." << NC << std::endl;
		return (4);
	}

	std::cout << final.top() << std::endl;

	return (0);
}
