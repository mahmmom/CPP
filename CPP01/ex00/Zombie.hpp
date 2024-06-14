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

void randomChump( std::string name );
Zombie* newZombie( std::string name);

#endif