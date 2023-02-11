#include <fstream>
#include <iostream>

int	open_files(std::fstream& input, std::ofstream& output, const std::string& filename)
{
	input.open(filename);
	if (!input.is_open())
	{
		std::cerr << "Couldn't open input file" << std::endl;
		return (1);
	}
	output.open(filename + ".replace", std::ios::out | std::ios::trunc);
	if (!output.is_open())
	{
		std::cerr << "Couldn't create output file" << std::endl;
		return (1);
	}
	return (0);
}

int	main( int argc, char **argv)
{
	std::fstream	input;
	std::ofstream	output;

	(void) argc;
	if (open_files(input, output, argv[1]) != 0)
		return (1);
	return (0);
}