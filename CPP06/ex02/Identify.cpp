#include "Identify.hpp"

char getRandomItem()
{
	std::srand(static_cast<unsigned int>(time(0)));
    const char items[3] = {'A', 'B', 'C'};
    int index = 0 + (std::rand() % (2 - 0 + 1));
	std::cout << CYAN << "print = " << items[index] << RESET << std::endl;
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
