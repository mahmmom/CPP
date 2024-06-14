#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

class Fixed {
	public:
	Fixed();
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& other);
	~Fixed();
	int getRawBits(void) const; // returns the raw value of the fixed-point value.
	void setRawBits(int const raw); // sets the raw value of the fixed-point number.

	private:
	int fp_Val;
	static const int bits = 8;
};


#endif