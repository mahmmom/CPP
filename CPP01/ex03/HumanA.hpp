#ifndef HUMANA_HPP
#define	HUMANA_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"


class HumanA {
	public:
		HumanA(std::string name, Weapon &type);
		~HumanA();
		void attack();
		std::string getName();
		Weapon getWeapon();

	private:
		std::string	name;
		Weapon	&weapon;
};


#endif