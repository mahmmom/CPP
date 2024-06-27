#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap() 
{
	std::cout << "DiamondTrap default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string DiamondTrap) :  FragTrap(DiamondTrap), ScavTrap(DiamondTrap), name(DiamondTrap)
{
	std::cout << "DiamondTrap name constructor called!" << std::endl;
	ClapTrap::name = (DiamondTrap + "_clap_name");
	HitPoints = 100;
	EnergyPoints = 50;
	AttackDamage = 30;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap destructor is called!" << std::endl;
}
DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{	
	std::cout << "DiamondTrap copy constructor is called!" << std::endl;
	*this = other;
}
DiamondTrap& DiamondTrap::operator=(const DiamondTrap& rhs)
{
	std::cout << "DiamondTrap copy constructor is called!" << std::endl;
	if (this != &rhs)
	{
		this->_hitPoints = rhs._hitPoints;
		this->_attackDamage = rhs._attackDamage;
		this->_energyPoints = rhs._energyPoints;
		this->name = rhs.name;
	}
	return (*this);
}
void DiamondTrap::whoAmI()
{
	std::cout << "My name is " << this->name << " my ClapTrap name is " << ClapTrap::_name << "." << std::endl;
}