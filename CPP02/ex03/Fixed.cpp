#include "Fixed.hpp"

Fixed::Fixed()
{
	// std::cout << "Default constructor called" << std::endl;
	this->fp_Val = 0;
}

Fixed::Fixed(const int Num)
{
	// std::cout << "Int constructor called" << std::endl;
	fp_Val = Num<<bits; // Num << left shift is = Num * 2^8, but its faster because binary
}

Fixed::Fixed(const float Num)
{
	// std::cout << "Float constructor called" << std::endl;
	fp_Val = roundf(Num *(1<<bits));
}

Fixed::Fixed(const Fixed& other)
{
	// std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed&	Fixed::operator=(const Fixed& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->fp_Val = other.fp_Val;
	}
	return *this;
}

int		Fixed::getRawBits(void) const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return fp_Val;
}

void	Fixed::setRawBits(int const raw)
{
	fp_Val = raw;
}

int Fixed::toInt( void ) const
{
	return (fp_Val>>bits);
}

float Fixed::toFloat( void ) const
{
	float temp = static_cast<float>(fp_Val);
	return temp / (1 << bits);
}

Fixed::~Fixed()
{
	// std::cout << "Destructor called" << std::endl;
}

std::ostream& operator<<(std::ostream &out, const Fixed &fp)
{
    out << fp.toFloat();
	return (out);
}

bool Fixed::operator>(const Fixed& other) const
{
    return this->fp_Val > other.fp_Val;
}

bool Fixed::operator<(const Fixed& other) const
{
	return this->fp_Val < other.fp_Val;
}

bool Fixed::operator>=(const Fixed& other) const
{
	return this->fp_Val >= other.fp_Val;
}

bool Fixed::operator<=(const Fixed& other) const
{
	return this->fp_Val <= other.fp_Val;
}

bool Fixed::operator==(const Fixed& other) const
{
	return this->fp_Val == other.fp_Val;
}

bool Fixed::operator!=(const Fixed& other) const
{
	return this->fp_Val != other.fp_Val;
}

Fixed&	Fixed::operator+(const Fixed& other)
{
	this->fp_Val += other.fp_Val;
	return *this;
}

Fixed&	Fixed::operator-(const Fixed& other)
{
	this->fp_Val -= other.fp_Val;
	return *this;
}

Fixed&	Fixed::operator*(const Fixed& other)
{
	this->fp_Val = (this->fp_Val * other.fp_Val) >> bits;
	return *this;
}

Fixed&	Fixed::operator/(const Fixed& other)
{
	this->fp_Val = ((this->fp_Val << bits) / other.fp_Val);
	return *this;
}

Fixed& Fixed::operator++()
{
    // Pre-increment: increment fp_Val by the smallest representable epsilon
    ++fp_Val;
    return *this;
}

Fixed Fixed::operator++(int)
{
    // Post-increment: increment fp_Val by the smallest representable epsilon
	// but return the original value
    Fixed temp = *this;
    ++fp_Val;
    return temp;
}

Fixed& Fixed::operator--()
{
    // Pre-increment: increment fp_Val by the smallest representable epsilon
    --fp_Val;
    return *this;
}

Fixed Fixed::operator--(int)
{
    // Post-increment: increment fp_Val by the smallest representable epsilon 
	// but return the original value
    Fixed temp = *this;
    --fp_Val;
    return temp;
}

Fixed& 	Fixed::max(Fixed& A, Fixed& B)
{
	if(A.fp_Val > B.fp_Val)
		return A;
	return B;
}

const Fixed& 	Fixed::max(const Fixed& A, const Fixed& B)
{
	if(A.fp_Val > B.fp_Val)
		return A;
	return B;
}

Fixed& 	Fixed::min(Fixed& A, Fixed& B)
{
	if(A.fp_Val < B.fp_Val)
		return A;
	return B;
}

const Fixed& 	Fixed::min(const Fixed& A, const Fixed& B)
{
	if(A.fp_Val < B.fp_Val)
		return A;
	return B;
}
