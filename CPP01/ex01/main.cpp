#include "Zombie.hpp"

int main()
{
	int	N = 3;
	std::string name = "Mohamed";
	
	Zombie* GenZ = zombieHorde(N, name);
	if(!GenZ)
	{
		std::cout << "Number should be > 0" << std::endl;
		return(1);
	}

	for (int i = 0; i < N; i++)
		GenZ[i].announce();

	delete [] GenZ;

	return (0);
}
