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

	int position = 500;

	if(position > 100 || position < 0)
	{
		std::cout << "Error, position is out of range" << std::endl;
		return (1);
	}
	
	Cat Tom;

	Cat	Jerry = Tom;

	Tom.getBrain()->setIdea(5, "New Idea here");

	std::cout << "Deep copy check [1] = " << Tom.getBrain()->getIdea(position) << std::endl;

	std::cout << "Deep copy check [2] = " << Jerry.getBrain()->getIdea(position) << std::endl;

    return 0;
}
