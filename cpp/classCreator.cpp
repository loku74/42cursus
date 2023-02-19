#include <fstream>
#include <iostream>
#include <vector>

static void	create_src_file( std::ofstream & src_file, std::string & class_name, bool & status)
{
	src_file << "#include \"" << class_name + ".hpp" << "\"\n\n";
	src_file << class_name << "::" << class_name << "( void )\n{\n";
	if (status)
		src_file << "\tstd::cout << \"Default constructor called\" << std::endl;";
	src_file << "\n}\n\n\n";
	src_file << class_name << "::" << class_name << "( " << class_name << " const & src )\n{\n";
	if (status)
		src_file << "\t" << "std::cout << \"Copy constructor called\" << std::endl;\n\n";
	src_file << "\t*this = src;\n}\n\n\n";
	src_file << class_name << "::~" << class_name << "( void )\n{\n";
	if (status)
		src_file << "\tstd::cout << \"Destructor called\" << std::endl;";
	src_file << "\n}\n\n\n";
	src_file << class_name << " &\t" << class_name << "::operator=( " << class_name << " const & rhs )\n{\n";
	if (status)
		src_file << "\t" << "std::cout << \"Copy assignment operator called\" << std::endl;\n\n";
	src_file << "\treturn (*this);\n}" << std::endl;
}


static void	create_header_file( std::ofstream & header_file, std::string & class_name )
{
	header_file << "#pragma once\n\n" << "#include <iostream>\n\n";
	header_file << "class " << class_name << "\n{\n\n";
	header_file << "public:\n\n";
	header_file << "\t" << class_name << "( void );\n";
	header_file << "\t" << class_name << "( " << class_name << " const & src );\n";
	header_file << "\t~" << class_name << "( void );\n\n";
	header_file << "\t" << class_name << " &\toperator=( " << class_name << " const & rhs );\n\n";
	header_file << "private:\n\n};" << std::endl;
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
	bool						status = false;

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
		if (class_names.size() == 0 && input == "-s")
			status = true;
		else
			class_names.push_back(input);
	}

	if (class_names.size() == 0)
	{
		std::cerr << "Error: no file(s) to create." << std::endl;
		return (2);
	}

	for (int i = 0; i < class_names.size(); i++)
	{
		if (!create_files(class_names[i], class_header, class_src))
		{
			create_header_file(class_header, class_names[i]);
			create_src_file(class_src, class_names[i], status);

			class_header.close();
			class_src.close();
		}
	}

	return (0);
}
