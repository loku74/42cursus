#include "utils.hpp"

int	main(int argc, char **argv)
{
	if (bad_input(argc, argv))
		return (1);

	int			port = std::atoi(argv[1]);
	std::string	password = argv[2];

    if (password.size() == 0)
    {
        print_error("password cannot be empty");
        return (1);
    }

	Server server(port, password.c_str());

	try
	{
		server.init();
	}
	catch (std::exception &e)
	{
		print_error(e.what());
		return (2);
	}

	server.run();

	return (0);
}
