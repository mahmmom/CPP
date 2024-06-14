#ifndef EXAMPLE_HPP
#define EXAMPLE_HPP


#include <iostream>
#include <string>

class FixedPoint {
private:
    int value; // The underlying integer value
    static const int SCALE = 100; // The scaling factor (100 for two decimal places)

public:
    // Constructor
    FixedPoint(int integerPart, int fractionalPart)
	{
        value = integerPart * SCALE + fractionalPart;
		std::cout << "Int Part = " <<integerPart << std::endl;
		std::cout << "Frac Part = " << fractionalPart << std::endl;
		std::cout << "Val Part = " << value << std::endl;
    }

    // Conversion constructor from a floating-point number
    FixedPoint(double number)
	{
        value = static_cast<int>(number * SCALE);
    }

    // Addition operator
    FixedPoint operator+(const FixedPoint &other) const
	{
        return FixedPoint((value + other.value) / static_cast<double>(SCALE));
    }

    // Subtraction operator
    FixedPoint operator-(const FixedPoint &other) const
	{
        return FixedPoint((value - other.value) / static_cast<double>(SCALE));
    }

    // Multiplication operator
    FixedPoint operator*(const FixedPoint &other) const
	{
        return FixedPoint((value * other.value) / (SCALE * SCALE));
    }

    // Division operator
    FixedPoint operator/(const FixedPoint &other) const
	{
        return FixedPoint((value * SCALE) / other.value);
    }

    // Conversion to double for display purposes
    double toDouble() const
	{
        return static_cast<double>(value) / SCALE;
    }

    // Print the fixed-point value
    void print() const {
        std::cout << "FixedPoint value: " << toDouble() << std::endl;
    }
};




#endif

// int main()
// {
//     FixedPoint a(12, 34); // Represents 12.34
//     FixedPoint b(56, 78); // Represents 56.78

//     FixedPoint c = a + b;
//     c.print(); // Should print 69.12

//     FixedPoint d = b - a;
//     d.print(); // Should print 44.44

//     FixedPoint e = a * b;
//     e.print(); // Should print 700.6652 (approx)

//     FixedPoint f = b / a;
//     f.print(); // Should print 4.60 (approx)

//     return 0;
// }