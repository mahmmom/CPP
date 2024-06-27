#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->name = "ScavTrap";
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string scav) : ClapTrap(scav)
{
	this->HitPoints = 100;
	this->EnergyPoints = 50;
	this->AttackDamage = 20;
	std::cout << "FragTrap naming constructor called" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other)
{
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& other)
{
	std::cout << "ScavTrap copy assignment operator called" << std::endl;
	if(this != &other)
	{
		ClapTrap::operator=(other); // Assign base class part
		// We have to call the Copy assignment operator of Father Class, then any other attributes of Child class
        // Assign other members specific to ScavTrap if any
	}
	return *this;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate()
{
	std::cout << "ScavTrap has entered Gate Keeper mode" << std::endl;
}

void	ScavTrap::attack(const std::string& target)
{
	if(HitPoints > 0 && EnergyPoints > 0)
	{
		EnergyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target << " ,causing " << AttackDamage << " points of damage!" << std::endl;
		std::cout << "ScavTrap " << name << " remaining Energy Points =  " << EnergyPoints << std::endl;
	}
	else
		std::cout << "ScavTrap" << name << " has no energy or hit points left to attack!" << std::endl;
}
