#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell()
{

}

ASpell::ASpell(const ASpell& other)
{
	*this = other;
}

ASpell::~ASpell()
{

}

ASpell& ASpell::operator=(const ASpell& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_effects = other._effects;
	}
	return *this;
}

ASpell::ASpell(std::string name, std::string effects) : _name(name) , _effects(effects)
{

}

std::string  ASpell::getName() const
{
	return this->_name;
}

std::string  ASpell::getEffects() const
{
	return this->_effects;
}

void	ASpell::launch(const ATarget& ref) const
{
	ref.getHitBySpell(*this);
}
