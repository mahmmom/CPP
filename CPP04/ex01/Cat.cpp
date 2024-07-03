#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	catBrain = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
}


Cat::Cat(Cat const &other) : Animal(other)
{
	// explained down
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = other._type;
	this->catBrain = new Brain(*other.catBrain);
}

Cat & Cat::operator=(Cat const &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
        Animal::operator=(other); // Call the base class assignment operator
        delete this->catBrain; // Free existing resource
        this->catBrain = new Brain(*other.catBrain); // Proper deep copy
	}
	return *this;
}

Cat::~Cat()
{
	delete catBrain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << _type <<" say Meow Meow Meow" << std::endl;
}

std::string	Cat::getType() const
{
	return _type;
}

Brain*	Cat::getBrain() const
{
	return catBrain;
}

/*
	A deep copy involves creating a new instance of a dynamically allocated object and copying the actual data,
	not just the pointer to the data. This is crucial to ensure that each Cat object has its own separate Brain object.
	Without a deep copy, multiple Cat objects would share the same Brain object,
	leading to potential issues when one object modifies the shared Brain.
*/
