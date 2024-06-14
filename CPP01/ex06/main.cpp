#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Error: usage <./harlFilter <Level>" << std::endl;
		return(1); 
	}
	
	Harl    harl;

    harl.complain(av[1]);

}
