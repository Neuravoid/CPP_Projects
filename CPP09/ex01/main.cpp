#include "RPN.hpp"


int main(int ac, char **av)
{
	if (ac != 2)
		return 1;
	RPN r1(av[1]);
	if (r1.getError())
		return 1;
	return 0;
}