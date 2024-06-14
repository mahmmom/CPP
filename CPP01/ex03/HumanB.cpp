#include "HumanB.hpp"

HumanB::HumanB(std::string name)
{
	this->name = name;
	this->wep = NULL;
	//std::cout << "Constructor called" << std::endl;
}

HumanB::~HumanB()
{
	//std::cout << "Destructor called" << std::endl;
}

void HumanB::attack()
{
	std::cout << name << " attacks with their " << wep->getType() << std::endl;
}

void HumanB::setWeapon(Weapon &type)
{
	wep = &type;
}

Weapon* HumanB::getWeapon()
{
	return (wep);
}