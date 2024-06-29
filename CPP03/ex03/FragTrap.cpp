#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	this->name = "FragTrap";
	this->hitPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string Frag) : ClapTrap(Frag)
{
	this->hitPoints = 100;
	this->attackDamage = 30;
	std::cout << "FragTrap naming constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	*this = other;
}

FragTrap&	FragTrap::operator=(const FragTrap& other)
{
	std::cout << "FragTrap copy constructor called" << std::endl;
	if (this != &other)
	{
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap demands a high five Now!!!" << std::endl;
}
