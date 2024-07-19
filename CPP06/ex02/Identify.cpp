#include "Identify.hpp"

char getRandomItem()
{
	std::srand(static_cast<unsigned int>(time(0)));
    const char items[3] = {'A', 'B', 'C'};
    int index = 0 + (std::rand() % (2 - 0 + 1));
	std::cout << "print = " << items[index] << std::endl;
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

}

void identify(Base &p)
{

}
