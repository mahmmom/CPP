#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
class Brain;

class Dog: public Animal
{
	public:
		Dog();
		Dog(Dog const &object);
		Dog &operator=(Dog const &rhs);
		~Dog();

		void	makeSound() const;
		std::string	getType() const;
		Brain* getBrain() const;

	private:
		Brain* _dogBrain;
};

#endif