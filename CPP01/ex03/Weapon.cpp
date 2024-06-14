#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
	this->type = type;
	//std::cout << "Constructor called" << std::endl;
}

Weapon::~Weapon()
{
	//std::cout << "Destructor called" << std::endl;
}

std::string Weapon::getType() const
{
	return (std::string(type));
}


void Weapon::setType(std::string wep)
{
	type = wep;
}
