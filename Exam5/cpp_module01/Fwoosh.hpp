#ifndef FWOOSH_HPP
#define FWOOSH_HPP

#include <iostream>
#include <string>
#include "ASpell.hpp"

class Fwoosh : public ASpell
{
	public:
	Fwoosh();
	Fwoosh(const Fwoosh& other);
	Fwoosh& operator=(const Fwoosh& other);
	~Fwoosh();


	Fwoosh* clone();
};


#endif