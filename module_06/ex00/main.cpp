#include "Conversion.hpp"

int main(int ac , char **av)
{

	if (ac != 2)
	{
		std::cerr << "Error: Invalid Argument" << std::endl;
		return (EXIT_FAILURE);
	}
	ScalarConverter::convert(av[1]);
	return EXIT_SUCCESS;
}
