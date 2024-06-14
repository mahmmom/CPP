#include "Zombie.hpp"

void randomChump( std::string name )
{
	Zombie Zombie;

	Zombie.setZombie(name);
	Zombie.announce();
}
