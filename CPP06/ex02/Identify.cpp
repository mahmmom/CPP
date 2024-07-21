#include "Identify.hpp"

char getRandomItem()
{
	std::srand(static_cast<unsigned int>(time(0)));
    const char items[3] = {'A', 'B', 'C'};
    int index = std::rand() % 3;
	std::cout << CYAN << "Pointer from random = " << items[index] << RESET << std::endl;
    return items[index];
}

Base *generate()
{
	char random = getRandomItem();
	switch (random)
	{
		case 'A':
			return new A;
		case 'B':
			return new B;
		case 'C':
			return new C;
		default:
			return NULL;
	}
}

void identify(Base *p)
{
	if(!p)
	{
		std::cerr << RED << "Pointer cannot be NULL" << RESET << std::endl;
		return;
	}	
	if (dynamic_cast<A*>(p))
		std::cout << GREEN << "The pointer is for Class A" << RESET << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << GREEN << "The pointer is for Class B" << RESET << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << GREEN << "The pointer is for Class C" << RESET << std::endl;
	else
		std::cerr << GREEN << "The pointer is not A or B or C" << RESET << std::endl;
}

void identify(Base &p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << YELLOW << "The pointer is for Class A" << RESET << std::endl;
	}
	catch(std::exception &e)
	{
		try
		{
			B& b = dynamic_cast<B&>(p);
			(void)b;
			std::cout << YELLOW << "The pointer is for Class B" << RESET << std::endl;
		}
		catch (std::exception &e)
		{
			try
			{
				C& c = dynamic_cast<C&>(p);
				(void)c;
				std::cout << YELLOW << "The pointer is for Class C" << RESET << std::endl;
			}
			catch(std::exception &e)
			{
				std::cerr << YELLOW << "The pointer is not A , B or C" << RESET << std::endl;
			}
		}
	}
}


/*

+----------------------+-------------------------------+---------------------------------+----------------------------------------------+
| Feature              | static_cast                   | reinterpret_cast                | dynamic_cast                                 |
+----------------------+-------------------------------+---------------------------------+----------------------------------------------+
| Safety               | Type-safe at compile time     | Not type-safe, can cast         | Type-safe at runtime, performs type checking |
|                      |                               | unrelated types                 |                                              |
+----------------------+-------------------------------+---------------------------------+----------------------------------------------+
| Use Case             | Related types, numeric        | Low-level casting,              | Safe downcasting, cross-casting in           |
|                      | conversions, void pointers    | bit manipulation                | class hierarchy                              |
+----------------------+-------------------------------+---------------------------------+----------------------------------------------+
| Runtime Check        | No                            | No                              | Yes                                          |
+----------------------+-------------------------------+---------------------------------+----------------------------------------------+
| Polymorphism         | Not required                  | Not required                    | Required (must have virtual functions)       |
+----------------------+-------------------------------+---------------------------------+----------------------------------------------+
| Invalid Cast         | Undefined behavior            | Undefined behavior              | Returns nullptr (pointers), throws           |
|                      |                               |                                 | std::bad_cast (references)                   |
+----------------------+-------------------------------+---------------------------------+----------------------------------------------+
| Example Usage        | Upcasting, downcasting within | Casting pointers to unrelated   | Downcasting base to derived safely           |
|                      | class hierarchy               | types                           |                                              |
+----------------------+-------------------------------+---------------------------------+----------------------------------------------+
| Overhead             | None                          | None                            | Runtime overhead due to type checking        |
+----------------------+-------------------------------+---------------------------------+----------------------------------------------+

Static_cast: Safe for compile-time type conversions between related types,
			 no runtime checks, no overhead.

Reinterpret_cast: Unsafe for type conversion, no runtime checks,
				  used for low-level casting.

Dynamic_cast: Safe for runtime type checking within class hierarchies, incurs runtime overhead,
	          requires polymorphic types.

*/