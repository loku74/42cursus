#include <iostream>

int	main( void )
{
	std::string		string		= "HI THIS IS BRAIN";
	std::string*	stringPTR	= &string;
	std::string&	stringREF	= string;

	// printing addresses
	std::cout << "string		address: " << &string << std::endl;
	std::cout << "stringPTR	address: " << stringPTR << std::endl;
	std::cout << "stringREF	address: " << &stringREF << std::endl;

	// printing values
	std::cout << "string		value: " << string << std::endl;
	std::cout << "stringPTR	value: " << *stringPTR << std::endl;
	std::cout << "stringREF	value: " << stringREF << std::endl;

	return (0);
}