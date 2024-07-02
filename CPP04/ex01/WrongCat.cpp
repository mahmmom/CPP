#include "WrongCat.hpp"

WrongCat::WrongCat(): _type("WrongCat")
{
	std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(WrongCat const &other) : WrongAnimal(other)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = other;
}

WrongCat & WrongCat::operator=(WrongCat const &other)
{
	std::cout << "WrongCat copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
	}
	return (*this);
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called" << std::endl;
}

// void	WrongCat::makeSound() const
// {
// 	std::cout << "WrongCat makes sound ... Bark" << std::endl;
// }
