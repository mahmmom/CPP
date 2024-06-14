#ifndef HUMANB_HPP
#define	HUMANB_HPP

#include <string>
#include <iostream>
#include "Weapon.hpp"


class HumanB {
	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &type);
		Weapon* getWeapon();

	private:
		std::string	name;
		Weapon	*wep;
};



#endif