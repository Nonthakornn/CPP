#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
		return (std::cerr << "Error Input!" << std::endl, EXIT_FAILURE);
	Harl harl;
	harl.complain(std::string(av[1]));
	return (0);
}