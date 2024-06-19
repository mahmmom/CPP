#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>
#include <cmath>

class Fixed {
	public:
	Fixed();
	Fixed(const int Num);
	Fixed(const float Num);
	Fixed(const Fixed& other);
	Fixed&	operator=(const Fixed& other);
	~Fixed();
	int getRawBits(void) const; // returns the raw value of the fixed-point value.
	void setRawBits(int const raw); // sets the raw value of the fixed-point number.
	float toFloat( void ) const; // converts the fixed-point value to a floating-point value.
	int toInt( void ) const; // converts the fixed-point value to an integer value.
	double ToFixed();

	private:
	int fp_Val;
	static const int bits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fp);

#endif