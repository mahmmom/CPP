#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : Name("ClapTrap") , HitPoints(10) , EnergyPoints (10) , AttackDamage(10)
{
	std::cout << "ClapTrap default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string str) : Name(str) , HitPoints(10) , EnergyPoints (10) , AttackDamage(10)
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
		this->Name = other.Name;
		this->HitPoints = other.HitPoints;
		this->EnergyPoints = other.EnergyPoints;
		this->AttackDamage = other.AttackDamage;
	}
	return *this;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}


void	ClapTrap::attack(const std::string& target)
{
	if(HitPoints > 0 && EnergyPoints > 0)
	{
		EnergyPoints--;
		std::cout << "ClapTrap " << Name << " attacks " << target << " ,causing " << AttackDamage << " points of damage!" << std::endl;
		std::cout << "ClapTrap " << Name << " remaining Energy Points =  " << EnergyPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << Name << " has no energy or hit points left to attack!" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	HitPoints -= amount;
	if(HitPoints < 0)
		HitPoints = 0;
	std::cout << "ClapTrap " << Name << " taken " << amount << " points of damage! Remaining Hit Points: " << HitPoints  << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if(EnergyPoints > 0 && HitPoints > 0)
	{
		EnergyPoints--;
		HitPoints += amount;
		std::cout << "ClapTrap " << Name << " repaired itself, recovering " << amount << " of points, Total Hit Points: " << HitPoints << std::endl;
		std::cout << "ClapTrap " << Name << " remaining Energy Points =  " << EnergyPoints << std::endl;
	}
	else
		std::cout << "ClapTrap " << Name << " has no energy or hit points left to repair!" << std::endl;
}

