#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default Constructor called" << std::endl;
	this->fp_Val = 0;
}

Fixed::Fixed(const Fixed& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	if (this != &other)
	{
		this->fp_Val = other.fp_Val;
	}
	std::cout << "Copy assignment operator called" << std::endl;
	return *this;
}

int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return fp_Val;
}

void	Fixed::setRawBits(int const raw)
{
	fp_Val = raw;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}
