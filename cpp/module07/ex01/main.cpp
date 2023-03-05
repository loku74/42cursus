#include "iter.hpp"

template<typename T>
static void	f( const T& element )
{
	std::cout << element << " ";
}


int	main( void )
{
	std::cout << "--- int ---" << std::endl;
	{
	int test[6] = {0, 1, 2, 4, 8, 16};

	iter(test, 6, f);
	}

	std::cout << "\n--- string ---" << std::endl;
	{
		std::string test[6] = {"masterclass", "akhy", "t'es", "à", "ton", "prime"};

		iter(test, 6, f);
	}

	std::cout << "\n--- char ---" << std::endl;
	{
		char test[8] = {'t', 'e', 'm', 'p', 'l', 'a', 't', 'e'};

		iter(test, 8, f);
	}

	return (0);
}
