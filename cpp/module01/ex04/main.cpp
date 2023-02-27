#include <fstream>
#include <iostream>

static int	open_files( std::ifstream& input, std::ofstream& output, const std::string& filename )
{
	input.open(filename.c_str());
	if (!input.is_open())
	{
		std::cerr << "Couldn't open input file" << std::endl;
		return (1);
	}
	output.open((filename + ".replace").c_str(), std::ios::out | std::ios::trunc);
	if (!output.is_open())
	{
		std::cerr << "Couldn't open output file" << std::endl;
		return (1);
	}
	return (0);
}

static void	replace( std::ifstream& input, std::ofstream& output, const std::string& s1, const std::string& s2 )
{
	std::string				line;
	std::string::size_type 	index;

	while (std::getline(input, line))
	{
		index = 0;
		while ((index = line.find(s1, index)) != std::string::npos)
		{
			line.erase(index, s1.length());
			line.insert(index, s2);
			if (s2.length() == 0)
				index++;
			else
				index += s2.length();
		}
		output << line;
		if (!input.eof())
			output << std::endl;
	}
}

int	main( int argc, char **argv )
{
	std::ifstream	input;
	std::ofstream	output;

	if (argc != 4)
	{
		std::cerr << "Wrong number of argument(s): 3 required; file, string_to_replace, new_string." << std::endl;
		return (1);
	}

	if (open_files(input, output, argv[1]))
		return (1);

	replace(input, output, argv[2], argv[3]);

	input.close();
	output.close();

	return (0);
}
