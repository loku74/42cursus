#include <iostream>
#include <cstdlib>
#include <ostream>
#include "colors.h"

enum e_type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE
};

static e_type	get_type( const char* type_c )
{
	std::string type(type_c);

	// char check
	if (type.size() == 1 && type_c[0] >= 32 && type_c[0] <= 126)
		return (CHAR);
	
	// int check
	
}

int	main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: Wrong number of arguments; 1 required: litteral_value." << NC << std::endl;
		return (1);
	}

	e_type	type = get_type(argv[1]);

	return (0);
}
