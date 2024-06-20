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

	// Comparison operators
	bool operator>(const Fixed& other) const;
    bool operator<(const Fixed& other) const;
    bool operator>=(const Fixed& other) const;
    bool operator<=(const Fixed& other) const;
    bool operator==(const Fixed& other) const;
    bool operator!=(const Fixed& other) const;

	// Arithmetic operators
	Fixed&	operator+(const Fixed& other);
	Fixed&	operator-(const Fixed& other);
	Fixed&	operator*(const Fixed& other);
	Fixed&	operator/(const Fixed& other);

	// Increment and decrement operators
	Fixed& operator++(); // Pre-increment
    Fixed operator++(int); // Post-increment
    Fixed& operator--(); // Pre-decrement
    Fixed operator--(int); // Post-decrement

	// Overloader operators
	static Fixed& max(Fixed& A, Fixed& B);
	static const Fixed& max(const Fixed& A, const Fixed& B);
	static Fixed& min(Fixed& A, Fixed& B);
	static const Fixed& min(const Fixed& A, const Fixed& B);

	private:
	int fp_Val;
	static const int bits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fp);


#endif