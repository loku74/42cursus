#include <fstream>
#include <iostream>

static void	create_src_file(std::ofstream& src_file, std::string& class_name)
{
	src_file << "#include \"" << class_name + ".hpp" << "\"\n\n";
	src_file << class_name << "::" << class_name << "( void )\n";
	src_file << "{\n\tstd::cout << \"Default constructor called\" << std::endl;\n}\n\n\n";
	src_file << class_name << "::" << class_name << "( " << class_name << " const & src )\n";
	src_file << "{\n\t" << "std::cout << \"Copy constructor called\" << std::endl;\n\n";
	src_file << "\t*this = src;\n}\n\n\n";
	src_file << class_name << "::~" << class_name << "( void )\n{\n";
	src_file << "\tstd::cout << \"Destructor called\" << std::endl;\n}\n\n\n";
	src_file << class_name << " &\t" << class_name << "::operator=( " << class_name << " const & rhs )\n";
	src_file << "{\n\t" << "std::cout << \"Assignment operator called\" << std::endl;\n";
	src_file << "\n\treturn (*this)\n}" << std::endl;
}

static void	create_header_file(std::ofstream& header_file, std::string& class_name)
{
	header_file << "#prama once\n\n" << "#include <iostream>\n\n";
	header_file << "class " << class_name << "\n{\n\n";
	header_file << "public:\n\n";
	header_file << "\t" << class_name << "( void );\n";
	header_file << "\t" << class_name << "( " << class_name << " const & src );\n";
	header_file << "\t~" << class_name << "( void );\n\n";
	header_file << "\t" << class_name << " &\toperator=( " << class_name << " const & rhs );\n\n";
	header_file << "private:\n\n};" << std::endl;
}

static int	create_files(std::string& class_name, std::ofstream& class_header, std::ofstream& class_src)
{
	class_header.open(class_name + ".hpp", std::ios::out | std::ios::trunc);
	if (!class_header.is_open())
	{
		std::cerr << "Couldn't create header file" << std::endl;
		return (1);
	}
	class_src.open(class_name + ".cpp", std::ios::out | std::ios::trunc);
	if (!class_src.is_open())
	{
		class_header.close();
		std::cerr << "Couldn't create src file" << std::endl;
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	std::ofstream	class_header;
	std::ofstream	class_src;
	std::string		class_name;

	if (argc != 2)
	{
		std::cerr << "Wrong number of argument: 1 required; Class name" << std::endl;
		return (1);
	}
	class_name = std::string(argv[1]);
	if (create_files(class_name, class_header, class_src))
		return (1);

	create_header_file(class_header, class_name);
	create_src_file(class_src, class_name);

	return (0);
}
