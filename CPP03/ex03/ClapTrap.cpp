#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("ClapTrap") , hitPoints(10) , energyPoints (10) , attackDamage(0)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string str) : name(str) , hitPoints(10) , energyPoints (10) , attackDamage(0)
{
	std::cout << "ClapTrap naming constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
{
	std::cout << "ClapTrap Copy constructor called" << std::endl;
	
	*this = other;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& other)
{
	std::cout << "ClapTrap copy assigment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hitPoints = other.hitPoints;
		this->energyPoints = other.energyPoints;
		this->attackDamage = other.attackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}


void	ClapTrap::attack(const std::string& target)
{
	if(hitPoints > 0 && energyPoints > 0)
	{
		energyPoints--;
		std::cout << "ClapTrap " << name << " attacks " << target << " ,causing " << attackDamage << " points of damage!" << std::endl;
		std::cout << "ClapTrap " << name << " remaining Energy Points =  " << energyPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " has no energy or hit points left to attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	hitPoints -= amount;
	if(hitPoints < 0)
		hitPoints = 0;
	std::cout << "ClapTrap " << name << " taken " << amount << " points of damage! Remaining Hit Points: " << hitPoints  << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if(energyPoints > 0 && hitPoints > 0)
	{
		energyPoints--;
		hitPoints += amount;
		std::cout << "ClapTrap " << name << " repaired itself, recovering " << amount << " of points, Total Hit Points: " << hitPoints << std::endl;
		std::cout << "ClapTrap " << name << " remaining Energy Points =  " << energyPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << name << " has no energy or hit points left to repair!" << std::endl;
}

