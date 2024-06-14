/*
In C++98, the concept of move semantics (which introduced move constructors and move assignment operators) does not exist.
Therefore, the focus is on what is known as the Rule of Three, which ensures proper management of resources through the following three special member functions:

1- Destructor (~ClassName())
2- Copy Constructor (ClassName(const ClassName& other))
3- Copy Assignment Operator (ClassName& operator=(const ClassName& other))
These functions handle the creation, copying, and destruction of objects, ensuring that resources such as memory are managed correctly. Let’s go through each component in detail:
*/

/*
1. Destructor
The destructor is responsible for cleaning up resources when an object is destroyed. It is declared like this:
*/

/*
2. Copy Constructor
The copy constructor initializes a new object as a copy of an existing object.
It is used when an object is passed by value, returned by value, or explicitly copied:
*/

/*
3. Copy Assignment Operator
The copy assignment operator is used to copy the value from one existing object to another existing object:
*/

/*Rule of Three
The Rule of Three states that if a class requires a user-defined destructor, copy constructor, or copy assignment operator, it likely needs all three. This is because if a class manages resources like dynamic memory, it needs to handle copying and cleanup properly to prevent resource leaks and ensure deep copies of the resources.

Example
Here is a class implementing the Rule of Three in C++98:
*/

// #include <iostream>

// class Example {
//     int* data;

// 	public:
//     // Constructor
//     Example(int value) : data(new int(value))
// 	{
//         std::cout << "Constructor called" << std::endl;
//     }

//     // Destructor
//     ~Example()
// 	{
//         delete data;
//         std::cout << "Destructor called" << std::endl;
//     }

//     // Copy Constructor
//     Example(const Example& other) : data(new int(*other.data))
// 	{
//         std::cout << "Copy Constructor called" << std::endl;
//     }

//     // Copy Assignment Operator
//     Example& operator=(const Example& other)
// 	{
//         if (this != &other)
// 		{  // Self-assignment check
//             delete data;
//             data = new int(*other.data);
//             std::cout << "Copy Assignment Operator called" << std::endl;
//         }
//         return *this;
//     }

//     // Function to display the value
//     void display() const
// 	{
//         std::cout << "Value: " << *data << std::endl;
//     }
// };


// int main() {
//     Example a(5);
//     Example b = a;  // Copy Constructor
//     Example c(10);
//     c = b;  // Copy Assignment Operator
//     a.display();
//     b.display();
//     c.display();
//     return 0;
// }

/*
In this example, the Example class correctly manages its dynamically allocated resource (data) by defining the necessary destructor, copy constructor, and copy assignment operator.
This ensures that resources are properly copied and cleaned up, preventing memory leaks and ensuring correct behavior when objects are copied.
*/

#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed b(a);
	Fixed c;
	c = b;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	return 0;
}
