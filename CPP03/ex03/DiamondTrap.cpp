#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap default constructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name)
{
    std::cout << "DiamondTrap name constructor called!" << std::endl;
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : ClapTrap(other), FragTrap(other), ScavTrap(other)
{
    std::cout << "DiamondTrap copy constructor called!" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
    std::cout << "DiamondTrap copy assignment operator called!" << std::endl;
    if (this != &other) {
        ClapTrap::operator=(other);
        FragTrap::operator=(other);
        ScavTrap::operator=(other);
        name = other.name;
    }
    return *this;
}

void DiamondTrap::attack(const std::string& target)
{
    std::cout << "DiamondTrap " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << name << " and my ClapTrap name is " << ClapTrap::name << "." << std::endl;
}
