#include "Dog.hpp"


Dog::Dog(): _type("Dog")
{
	std::cout << "Dog Default Constructor called" << std::endl;
}


Dog::Dog(Dog const &object): Animal::Animal(object)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = object;
}

Dog & Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog Copy Assignment Operator called" << std::endl;
	if (this != &rhs)
		this->_type = rhs._type;
	return (*this);
}

Dog::~Dog()
{
	std::cout << "Dog Destructor called" << std::endl;
}

void	Dog::makeSound() const
{
	std::cout << "Dog::makeSound() called" << std::endl;
	std::cout << "Dog makes sound ... Bark" << std::endl;
}

std::string	Dog::getType() const
{
	std::cout << "Dog::getType() called" << std::endl;
	return (this->_type);
}
