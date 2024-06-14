#include "Zombie.hpp"

int main()
{
	std::string name1 = "Mohamed";
	
	std::string name2 = "Nour";

	Zombie *GenZ = newZombie(name1);

	GenZ->announce();

	randomChump(name2);

	delete GenZ;

	return (0);
}
