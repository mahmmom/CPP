#ifndef ZOMBIE_H
#define ZOMBIE_H

#include <iostream>
#include <string>

class Zombie {
	public:
		Zombie(void);
		~Zombie(void);
		void announce(void) const;
		void setZombie(const std::string &name);
		std::string getZombie() const;

	private:
		std::string name;
};

Zombie* zombieHorde(int N, std::string name);

#endif