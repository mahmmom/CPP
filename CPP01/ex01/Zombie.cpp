#include "Zombie.hpp"

Zombie::Zombie(void)
{
	std::cout << "Constructor called" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << "Zombie:: " << getZombie() << " is destroyed" <<  std::endl;
}

void	Zombie::announce(void) const
{
	std::cout << name << ":BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setZombie(const std::string &name)
{
	this->name = name;
}

std::string Zombie::getZombie() const
{
	return name;
}