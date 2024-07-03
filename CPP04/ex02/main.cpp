#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* animals[4];
    for (int i = 0; i < 2; ++i)
	{
		animals[i] = new Dog();
	}

    for (int i = 2; i < 4; ++i)
    {
		animals[i] = new Cat();
	}

    for (int i = 0; i < 4; ++i)
    {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    for (int i = 0; i < 4; ++i)
    {
		delete animals[i];
	}

    return 0;
}
