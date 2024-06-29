#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap(), ScavTrap(), FragTrap()
{
    this->name = "DiamondTrap";
    hitPoints = hitPoints;
    energyPoints = energyPoints;
    attackDamage = attackDamage;
    std::cout << "DiamondTrap default constructor called" << std::endl;
	// std::cout << "naming = " << name << std::endl;
	// std::cout << "hitPoints = " << hitPoints << std::endl;
	// std::cout << "energyPoints = " << energyPoints << std::endl;
	// std::cout << "FragTrap = " << attackDamage << std::endl;
}

// we give the string "_clap_trap" to the ClapTrap only because
// we need to distinguish it from the other ones, and it will be unique this way
// that only diamond name will be shared between base and Diamond Class

DiamondTrap::DiamondTrap(std::string dTrap)
    : ClapTrap(dTrap + "_clap_trap"), ScavTrap(dTrap), FragTrap(dTrap)
{
    this->name = dTrap;
    hitPoints = FragTrap::hitPoints;
    energyPoints = ScavTrap::energyPoints;
    attackDamage = FragTrap::attackDamage;
    std::cout << "DiamondTrap naming constructor called" << std::endl;
	// std::cout << "naming = " << ClapTrap::name << std::endl;
	// std::cout << "hitPoints = " << FragTrap::hitPoints << std::endl;
	// std::cout << "energyPoints = " << ScavTrap::energyPoints << std::endl;
	// std::cout << "FragTrap = " << FragTrap::attackDamage << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) 
    : ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
    std::cout << "DiamondTrap copy constructor called!" << std::endl;
    *this = other;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "DiamondTrap copy assignment operator called!" << std::endl;
    if (this != &other)
    {
		// Explained down
        ClapTrap::operator=(other);
        ScavTrap::operator=(other);
        FragTrap::operator=(other);
        this->name = other.name;
    }
    return *this;
}

void DiamondTrap::whoAmI()
{
    std::cout << "My name is " << name << " and my ClapTrap name is " << ClapTrap::name << "." << std::endl;
}


/*
	When you implement a copy assignment operator in C++ for classes that use inheritance,
	you need to make sure that all relevant base class members are copied correctly.
	If your derived classes (ScavTrap, FragTrap,DiamondTrap) do not introduce any new member variables and only rely on the base class members (which are protected),
	your copy assignment operator should correctly copy these protected members by calling the base class's copy assignment operator.

	The key idea is to leverage the base class copy assignment operators to ensure all relevant members are copied correctly.
	Since your DiamondTrap class inherits from both ScavTrap and FragTrap,
	you call the assignment operators for both base classes to ensure that all inherited members are copied.
	This approach avoids duplicating code and ensures consistency in how members are copied across the inheritance hierarchy.
*/
