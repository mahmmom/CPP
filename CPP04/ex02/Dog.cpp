#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->_type = "Dog";
	_dogBrain = new Brain;
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->_type = other._type;
	this->_dogBrain = new Brain(*other._dogBrain);
}

Dog & Dog::operator=(Dog const &other)
{
	std::cout << "Dog copy assignment operator called" << std::endl;
	if (this != &other)
	{
		Animal::operator=(other);
        delete this->_dogBrain;
        this->_dogBrain = new Brain(*other._dogBrain);
	}
	return *this;
}

Dog::~Dog()
{
	delete _dogBrain;
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

Brain*	Dog::getBrain() const
{
	return _dogBrain;
}
