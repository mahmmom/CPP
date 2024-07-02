#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    const Animal* animals[4];

    // Create an array of Animal objects (2 Dogs and 2 Cats)
    for (int i = 0; i < 2; ++i)
    {
        animals[i] = new Dog();
    }

    for (int i = 2; i < 4; ++i)
    {
        animals[i] = new Cat();
    }

    // Display types and sounds
    for (int i = 0; i < 4; ++i)
    {
        std::cout << animals[i]->getType() << " says: ";
        animals[i]->makeSound();
    }

    // Delete the animals and check for proper destructor calls
    for (int i = 0; i < 4; ++i)
    {
        delete animals[i];
    }

    // Test deep copy
    Dog originalDog;
    {
        Dog copiedDog = originalDog; // Calls copy constructor
    } // copiedDog goes out of scope, destructor is called

    Cat originalCat;
    {
        Cat copiedCat = originalCat; // Calls copy constructor
    } // copiedCat goes out of scope, destructor is called

    return 0;
}
