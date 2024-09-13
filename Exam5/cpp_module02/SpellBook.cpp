#include "SpellBook.hpp"

SpellBook::SpellBook() {}

SpellBook::SpellBook(const SpellBook& other)
{
	*this = other;
}

SpellBook& SpellBook::operator=(const SpellBook& other)
{
	if (this != &other) {}
	return *this;
}

SpellBook::~SpellBook() {}

void SpellBook::learnSpell(ASpell* s)
{
	if (s)
		spells[s->getName()] = s;
}

void SpellBook::forgetSpell(std::string const & s)
{
	if(spells.find(s) != spells.end())
		spells.erase(s);
}

ASpell* SpellBook::createSpell(std::string const & s)
{
	ASpell* temp = NULL;
	if (spells.find(s) != spells.end())
		temp = spells[s];
	return temp;
}
