#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name), name(name)
{
    // if we put ClapTrap(name + "_clap_name") in above initialization list
    // we get 2 FragTraps constructor naming called
    // need to check this issue
    std::cout << "DiamondTrap name constructor called!" << std::endl;
    ClapTrap::name = name + "_clap_name";
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
    std::cout << "DiamondTrap copy constructor called!" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy assignment operator called!" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        this->hitPoints = other.hitPoints;
		this->attackDamage = other.attackDamage;
		this->energyPoints = other.energyPoints;
		this->name = other.name;
    }
    return *this;
}


void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << name << " and my ClapTrap name is " << ClapTrap::name << "." << std::endl;
}
