#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->_type = "Cat";
	std::cout << "Cat default constructor called" << std::endl;
}


Cat::Cat(Cat const &other) : Animal(other)
{
	std::cout << "Cat copy constructor called" << std::endl;
	*this = other;
}

Cat & Cat::operator=(Cat const &other)
{
	std::cout << "Cat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

Cat::~Cat()
{
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
