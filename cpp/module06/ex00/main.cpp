#include <cctype>
#include <iostream>
#include "colors.h"

static void	printChar( const std::string& type )
{
	char	toPrint = type[0];

	std::cout << "char: " << toPrint << std::endl;
	std::cout << "int: " << static_cast<int>(toPrint) << std::endl;
	std::cout << "float: " << static_cast<float>(toPrint) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(toPrint) << std::endl;
}

int	main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: Wrong number of arguments; 1 required: litteral_value." << NC << std::endl;
		return (1);
	}

	char*		type_c = argv[1];
	std::string	type(argv[1]);

	if (type.size() == 1 && std::isprint(type_c[0]))
		printChar(type);



	return (0);
}
