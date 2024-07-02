#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	*this = other;
}

Dog & Dog::operator=(Dog const &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << _type <<" say Woof Woof Woof" << std::endl;
}

std::string	Dog::getType() const
{
	return _type;
}
