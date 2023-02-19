#include "Fixed.hpp"

int	main( void )
{
	int x;

	x = (42 << 8);

	std::cout << x << std::endl;

	std::cout << "x to int:\t" << ((int)(roundf((float)x/ (1 << 8)))) << std::endl;
	std::cout << "x to float:\t" << ((float)x / (1 << 8)) << std::endl;

	float	f = 42.24f;
	int		fx = ((int)roundf(f * (1 << 8)));

	std::cout << "fx to int:\t" << ((int)(roundf((float)fx/ (1 << 8)))) << std::endl;
	std::cout << "fx to float:\t" << ((float)fx / (1 << 8)) << std::endl;

	return 0;
}
