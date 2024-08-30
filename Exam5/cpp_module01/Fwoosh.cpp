#include "Fwoosh.hpp"

Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed")
{

}

Fwoosh::Fwoosh(const Fwoosh& other)
{
	*this = other;
}

Fwoosh&	 Fwoosh::operator=(const Fwoosh& other)
{
	if (this != &other) {}
	return *this;
}

Fwoosh::~Fwoosh()
{
	
}

Fwoosh*	Fwoosh::clone()
{
	Fwoosh* fwoosh = new Fwoosh;

	return fwoosh;
}