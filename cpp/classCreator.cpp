#include <fstream>
#include <iostream>
#include <vector>
#include <filesystem>

static void	create_src_file( std::ofstream & src_file, std::string & class_name, bool & status, bool & colors )
{
	src_file << "#include \"" << class_name + ".hpp" << "\"\n\n";
	src_file << class_name << "::" << class_name << "( void )\n{\n";
	if (status)
	{
		src_file << "\tstd::cout << ";
		if (colors)
			src_file << "GRAY << ";
		src_file << "\"(" << class_name << ")";
		if (colors)
			src_file << "\" << GREEN << \"";
		src_file << " -> Default constructor called\" << ";
		if (colors)
			src_file << "NC << ";
		src_file << "std::endl;";
	}
	src_file << "\n}\n\n\n";
	src_file << class_name << "::" << class_name << "( " << class_name << " const & toCopy )\n{\n";
	if (status)
	{
		src_file << "\t" << "std::cout << ";
		if (colors)
			src_file << "GRAY << ";
		src_file << "\"(" << class_name << ") -> Copy constructor called\" << ";
		if (colors)
			src_file << "NC << ";
		src_file << "std::endl;\n\n";
	}
	src_file << "\t*this = toCopy;\n}\n\n\n";
	src_file << class_name << "::~" << class_name << "( void )\n{\n";
	if (status)
	{
		src_file << "\tstd::cout << ";
		if (colors)
			src_file << "GRAY << ";
		src_file << "\"(" << class_name << ")";
		if (colors)
			src_file << "\" << RED << \"";
		src_file << " -> Default destructor called\" << ";
		if (colors)
			src_file << "NC << ";
		src_file << "std::endl;";
	}
	src_file << "\n}\n\n\n";
	src_file << class_name << "&\t" << class_name << "::operator=( " << class_name << " const & toAssign )\n{\n";
	if (status)
	{
		src_file << "\t" << "std::cout << ";
		if (colors)
			src_file << "GRAY << ";
		src_file << "\"(" << class_name << ") -> Assignment operator called\" << ";
		if (colors)
			src_file << "NC << ";
		src_file << "std::endl;\n\n";
	}
	src_file << "\treturn (*this);\n}" << std::endl;
}


static void	create_header_file( std::ofstream & header_file, std::string & class_name, bool& setDefineColors )
{
	header_file << "#pragma once\n\n" << "#include <iostream>\n";
	if (setDefineColors)
		header_file << "#include \"colors.h\"\n";
	header_file << "\nclass " << class_name << "\n{\n\n";
	header_file << "public:\n\n";
	header_file << "\t" << class_name << "( void );\n";
	header_file << "\t" << class_name << "( " << class_name << " const & toCopy );\n";
	header_file << "\t~" << class_name << "( void );\n\n";
	header_file << "\t" << class_name << "&\toperator=( " << class_name << " const & toAssign );\n\n";
	header_file << "private:\n\n};" << std::endl;
}


static void	create_color_header( void )
{
	std::ofstream	color_header;

	color_header.open("colors.h", std::ios::out);
	if (!color_header.is_open())
	{
		std::cerr << "Couldn't create the \"colors.h\" header." << std::endl;
		return ;
	}
	color_header << "#ifndef COLORS_H\n";
	color_header << "# define COLORS_H\n\n";
	color_header << "# define RED \"\\033[1;31m\"\n";
	color_header << "# define GREEN \"\\033[1;32m\"\n";
	color_header << "# define YELLOW \"\\033[1;33m\"\n";
	color_header << "# define ORANGE \"\\033[38;5;208m\"\n";
	color_header << "# define PURPLE \"\\033[1;35m\"\n";
	color_header << "# define BLUE \"\\033[1;36m\"\n";
	color_header << "# define GRAY \"\\033[1;90m\"\n";
	color_header << "# define NC \"\\033[0m\"\n";
	color_header << "\n#endif" << std::endl;
}


static int	create_files( std::string & class_name, std::ofstream & class_header, std::ofstream & class_src )
{
	class_header.open(class_name + ".hpp", std::ios::out | std::ios::trunc);
	if (!class_header.is_open())
	{
		std::cerr << "Couldn't create " << class_name << ".hpp file." << std::endl;
		return (1);
	}
	class_src.open(class_name + ".cpp", std::ios::out | std::ios::trunc);
	if (!class_src.is_open())
	{
		class_header.close();
		std::cerr << "Couldn't create " << class_name << ".cpp file." << std::endl;
		return (1);
	}
	return (0);
}


int	main( int argc, char **argv )
{
	bool						debugMessage = false;
	bool						setDefineColors = false;

	std::ofstream				class_header;
	std::ofstream				class_src;
	std::vector<std::string>	class_names;

	if (argc == 1)
	{
		std::cerr << "Error: no argument(s)." << std::endl;
		return (1);
	}

	std::string	input;
	for (int i = 1; argv[i]; i++)
	{
		input = std::string(argv[i]);
		if (class_names.size() == 0 && input[0] == '-')
		{
			if (input.find("s") != std::string::npos)
				debugMessage = true;
			if (input.find("c") != std::string::npos)
				setDefineColors = true;
		}
		else
			class_names.push_back(input);
	}

	if (class_names.size() == 0)
	{
		std::cerr << "Error: no file(s) to create." << std::endl;
		return (2);
	}

	if (setDefineColors && !std::filesystem::exists("colors.h"))
		create_color_header();

	for (int i = 0; i < class_names.size(); i++)
	{
		if (!create_files(class_names[i], class_header, class_src))
		{
			create_header_file(class_header, class_names[i], setDefineColors);
			create_src_file(class_src, class_names[i], debugMessage, setDefineColors);

			class_header.close();
			class_src.close();
		}
	}

	return (0);
}
