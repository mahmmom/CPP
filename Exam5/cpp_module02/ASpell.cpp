#include "ASpell.hpp"
#include "ATarget.hpp"

ASpell::ASpell() : _name("") , _effects("")
{

}

ASpell::ASpell(std::string const& name, std::string const& effects) : _name(name) , _effects(effects)
{
	
}

ASpell::ASpell(const ASpell& other)
{
	*this = other;
}

ASpell&  ASpell::operator=(const ASpell& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_effects = other._effects;
	}
	return *this;
}

ASpell::~ASpell()
{
	
}

std::string const& ASpell::getName() const
{
	return this->_name;
}

std::string const& ASpell::getEffects() const
{
	return this->_effects;
}

void ASpell::launch(ATarget const& tref) const
{
	tref.getHitBySpell(*this);
}