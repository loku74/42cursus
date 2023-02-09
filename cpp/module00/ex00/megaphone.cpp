#include <iostream>

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; argv[i]; i++)
	{
		for (int k = 0; argv[i][k]; k++)
			std::cout << (char)toupper(argv[i][k]);
	}
	std::cout << std::endl;
	return (0);
}
