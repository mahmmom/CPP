#include "Zombie.hpp"

Zombie* zombieHorde( int N, std::string name)
{
	if (N<=0)
		return(NULL);

	Zombie* zom = new Zombie[N];

	for (int i = 0; i < N; i++)
		zom[i].setZombie(name);
	
	return(zom);
}
