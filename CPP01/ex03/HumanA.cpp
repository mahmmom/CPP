#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon &type) : weapon(type)
{
	this->name = name;
	// this->weapon = type;
	//std::cout << "Constructor called" << std::endl;
}

HumanA::~HumanA()
{
	//std::cout << "Destructor called" << std::endl;
}

std::string HumanA::getName()
{
	return std::string(name);
}

Weapon HumanA::getWeapon()
{
	return (weapon);
}

void HumanA::attack()
{
	std::cout << getName() << " attacks with their " << weapon.getType() << std::endl;
}
