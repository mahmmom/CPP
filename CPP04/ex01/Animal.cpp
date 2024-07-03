#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(Animal const &other)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = other;
}

Animal & Animal::operator=(Animal const &other)
{
	std::cout << "Animal copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

Animal::~Animal()
{
	std::cout << "Animal destructor called" << std::endl;
}

void	Animal::makeSound() const
{
	std::cout << "Animal makes a sound ..." << std::endl;
}

std::string Animal::getType() const
{
	return _type;
}
