#include "Point.hpp"

Point::Point() : x(0) , y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(const float xNum, const float yNum) : x(xNum) , y(yNum)
{
	// std::cout << "Parameters constructor called" << std::endl;
}

Point::Point(const Point& other) : x(other.x) , y(other.y) // this is how you initialize const attributes
{
	// std::cout << "Copy constructor called" << std::endl;
	// No need for *this = other; since x and y are already initialized.
}

Point&	Point::operator=(const Point& other)
{
	// std::cout << "Copy assignment operator called" << std::endl;
	if(this != &other)
	{
		// Const members cannot be reassigned, so nothing to do here
        // Normally, you would assign non-const members here but
		// Since x and y are const, they can't be assigned to
		(Fixed) this->x = other.getX();
		(Fixed) this->y = other.getY();
	}
	return *this;
}

Point::~Point()
{
	// std::cout << "Destructor called" << std::endl;
}

Fixed	Point::getX() const
{
	return x;
}

Fixed	Point::getY() const
{
	return y;
}
