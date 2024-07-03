#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    // const Animal* animals[4];
    // for (int i = 0; i < 2; ++i)
	// {
	// 	animals[i] = new Dog();
	// }

    // for (int i = 2; i < 4; ++i)
    // {
	// 	animals[i] = new Cat();
	// }

    // for (int i = 0; i < 4; ++i)
    // {
    //     std::cout << animals[i]->getType() << " says: ";
    //     animals[i]->makeSound();
    // }

    // for (int i = 0; i < 4; ++i)
    // {
	// 	delete animals[i];
	// }

	Cat jaafar;

	std::cout << "Before checking Deep copy " <<jaafar.getBrain()->getIdea(5) << std::endl;

	Cat	Abood = jaafar;

	jaafar.getBrain()->setIdea(5, "New Idea here");

	std::cout << "Deep copy check [1] = " << jaafar.getBrain()->getIdea(5) << std::endl;

	std::cout << "Deep copy check [2] = " << Abood.getBrain()->getIdea(5) << std::endl;

    return 0;
}
