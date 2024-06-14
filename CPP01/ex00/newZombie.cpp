#include "Zombie.hpp"

Zombie* newZombie(std::string name)
{
	Zombie *Z = new Zombie();

	Z->setZombie(name);

	return (Z);
}
