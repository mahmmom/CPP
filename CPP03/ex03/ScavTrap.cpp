#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap()
{
	this->name = "ScavTrap";
	this->energyPoints = 50;
	std::cout << "ScavTrap default constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string scav) : ClapTrap(scav)
{
	this->energyPoints = 50;
	std::cout << "ScavTrap naming constructor called" << std::endl;
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
		ClapTrap::operator=(other);
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
	if(hitPoints > 0 && energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ScavTrap " << name << " attacks " << target << " ,causing " << attackDamage << " points of damage!" << std::endl;
		std::cout << "ScavTrap " << name << " remaining Energy Points =  " << energyPoints << std::endl;
	}
	else
		std::cout << "ScavTrap" << name << " has no energy or hit points left to attack!" << std::endl;
}
