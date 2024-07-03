#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	_catBrain = new Brain;
	std::cout << "Cat default constructor called" << std::endl;
}


Cat::Cat(Cat const &other) : Animal(other)
{
	// explained down
	std::cout << "Cat copy constructor called" << std::endl;
	this->_type = other._type;
	this->_catBrain = new Brain(*other._catBrain);
}

Cat & Cat::operator=(Cat const &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
        Animal::operator=(other);
        delete this->_catBrain;
        this->_catBrain = new Brain(*other._catBrain);
	}
	return *this;
}

Cat::~Cat()
{
	delete _catBrain;
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
	return _catBrain;
}

/*
	Deep Copy:
	A deep copy duplicates all objects referenced by the original object.
	This means that any dynamically allocated memory is reallocated,
	and the actual data is copied. Each new object has its own independent copy of the data.

	Shallow Copy:
	A shallow copy duplicates only the top-level objects, copying pointers to
	dynamically allocated memory without duplicating the underlying objects.
	As a result, multiple objects may end up sharing the same memory,
	leading to unintended side effects when one object modifies the shared data.
	
	A deep copy involves creating a new instance of a dynamically allocated object and copying the actual data,
	not just the pointer to the data. This is crucial to ensure that each Cat object has its own separate Brain object.
	Without a deep copy, multiple Cat objects would share the same Brain object,
	leading to potential issues when one object modifies the shared Brain.

	By using a deep copy:
	Each Cat has its own unique Brain object.
	Changes to one Brain do not affect others.
	Deleting one Cat does not interfere with the others, avoiding double deletion issues.

*/
