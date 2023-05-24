#include "utils.hpp"

void	print_error(std::string message)
{
	std::cerr << RED << "Error: " << WHITE << message << "." << WHITEENDL;
}
