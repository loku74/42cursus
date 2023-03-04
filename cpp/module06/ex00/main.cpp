#include <cctype>
#include <iostream>
#include "colors.h"
#include <cerrno>
#include <cstdio>
#include <cstdlib>
#include <cfloat>
#include <climits>

static void	printChar( const std::string& type )
{
	char	toPrint = type[0];

	std::cout << "char: " << toPrint << std::endl;
	std::cout << "int: " << static_cast<int>(toPrint) << std::endl;
	std::cout << "float: " << static_cast<float>(toPrint) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(toPrint) << std::endl;
}


static void printDouble( const char* type )
{
	double	toPrint = std::strtod(type, NULL);

	std::cout << "char: ";
	if (toPrint > 31.0 && toPrint < 127.0)
		std::cout << static_cast<char>(toPrint) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (toPrint >= -2147483648.0 && toPrint <= 2147483647.0)
		std::cout << static_cast<int>(toPrint) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: ";
	if (static_cast<float>(toPrint) >= FLT_MIN && static_cast<float>(toPrint) <= FLT_MAX)
		std::cout << static_cast<float>(toPrint) << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "double: ";
	if (errno != 0)
	{
		std::cout << "impossible" << std::endl;
		errno = 0;
	}
	else
		std::cout << toPrint << std::endl;
}


static void printFloat( const float toPrint )
{
	std::cout << "char: ";
	if (toPrint > 31.0f && toPrint < 127.0f)
		std::cout << static_cast<char>(toPrint) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "int: ";
	if (toPrint >= -2147483648.0f && toPrint <= 2147483647.0f)
		std::cout << static_cast<int>(toPrint) << std::endl;
	else
		std::cout << "impossible" << std::endl;
	std::cout << "float: " << static_cast<float>(toPrint) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(toPrint) << std::endl;
}

static void	printInt( const char* type )
{
	long	numLong = std::strtol(type, NULL, 10);

	std::cout << "char: ";
	if (numLong > 31 && numLong < 127)
		std::cout << static_cast<char>(numLong) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "int: ";
	if (numLong >= INT_MIN && numLong <= INT_MAX)
		std::cout << static_cast<int>(numLong) << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "float: ";
	if (numLong >= INT_MIN && numLong <= INT_MAX)
		std::cout << static_cast<float>(numLong) << "f" << std::endl;
	else
		std::cout << "impossible" << std::endl;

	std::cout << "double: ";
	if (numLong >= INT_MIN && numLong <= INT_MAX)
		std::cout << static_cast<double>(numLong) << std::endl;
	else
		std::cout << "impossible" << std::endl;

}


static bool	checkNum ( const std::string& type )
{
	int	pc;

	pc = 0;
	for (size_t i = 0; i < type.size(); i++)
	{
		if (!isdigit(type[i]))
		{
			if (type[i] == '.')
			{
				pc++;
				continue ;
			}
			if (pc > 1)
				return (false);
			else
				return (false);
		}
	}
	return (true);
}


int	main( int argc, char** argv )
{
	if (argc != 2)
	{
		std::cerr << RED << "Error: Wrong number of arguments; 1 required: literal_value." << NC << std::endl;
		return (1);
	}

	char*		type_c = argv[1];
	std::string	type(argv[1]);

	if (type == "nan" || type == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (0);
	}
	else if (type == "+inf" || type == "inf" || type == "inff" || type == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: inff" << std::endl;
		std::cout << "double: inf" << std::endl;
		return (0);
	}
	else if (type == "-inf" || type == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (0);
	}

	if (type.size() == 1 && std::isprint(type_c[0]))
	{
		printChar(type);
		return (0);
	}
	else if (!checkNum(type))
	{
		std::cerr << RED << "Invalid literal_value input" << NC << std::endl;
		return (1);
	}

	if (type.find(".", 0) != std::string::npos)
	{
		float	floatValue;

		floatValue = std::strtof(type_c, NULL);
		if (errno != 0)
		{
			errno = 0;
			printDouble(type_c);
		}
		else
			printFloat(floatValue);
	}
	else
		printInt(type_c);

	return (0);
}
