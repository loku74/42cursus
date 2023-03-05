#include "Array.hpp"

int	main( void )
{
	std::cout << "--- int ---" << std::endl;
	{
		Array<int> test(5);

		test[2] = 42;

		for (unsigned int i = 0; i < test.size(); i++)
			std::cout << test[i] << " ";

		std::cout << std::endl;

		for (unsigned int i = 0; i < test.size(); i++) {
			test[i] = (i + 1) * 42;
			std::cout << test[i] << " ";
		}
	}

	std::cout << "\n--- strings ---" << std::endl;
	{
		Array<std::string>	test(3);

		test[0] = "CPP";
		test[1] = "Module";
		test[2] = "7";

		for (unsigned int i = 0; i < test.size(); i++)
			std::cout << test[i] << " ";
		std::cout << std::endl;
	}

	std::cout << "--- long ---" << std::endl;
	{
		Array<long>	test(100);

		for (long i = 0; i < test.size(); i++)
		{
			test[i] = (i + 1) * 42;
			std::cout << test[i] << " ";
		}
		std::cout << std::endl;
	}

	std::cout << "--- char ---" << std::endl;
	{
		Array<char>	test(95);

		for (long i = 0; i < test.size(); i++)
		{
			test[i] = (i + 32);
			std::cout << test[i] << " ";
		}

		std::cout << std::endl;
	}

	std::cout << "--- exception ---" << std::endl;
	{
		Array<int> test(10);

		try {
			std::cout << test[11];
		}
		catch (const std::exception &e) {
			std::cerr << e.what() << std::endl;
		}
	}

	return (0);
}
