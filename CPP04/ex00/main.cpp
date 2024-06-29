#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"

int main()
{
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	const Animal* meta = new Animal();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	const Animal* j = new Dog();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	const Animal* i = new Cat();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << i->getType() << " " << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	i->makeSound();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	j->makeSound();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	meta->makeSound();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << "---------------------------WRONG-ANIMAL--------------------------------------" << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	const WrongAnimal* meta1 = new WrongAnimal();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	const WrongAnimal* j1 = new WrongCat();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	const WrongAnimal* i1 = new WrongCat();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << j1->getType() << " " << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	std::cout << i1->getType() << " " << std::endl;
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	i1->makeSound();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	j1->makeSound();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	meta1->makeSound();
	std::cout << "-----------------------------------------------------------------------------" << std::endl;
	delete meta;
	delete meta1;
	delete i;
	delete i1;
	delete j;
	delete j1;
	return 0;
}