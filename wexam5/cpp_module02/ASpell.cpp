#include "ASpell.hpp"

ASpell::ASpell(ASpell const &other)
{
     *this = other;
}

ASpell &ASpell::operator=(ASpell const &as)
{
    this->name = as.name;
    this->effects = as.effects;
    return(*this);
}

ASpell::ASpell()
{
}

ASpell::~ASpell()
{
}

ASpell::ASpell(std::string const &name, std::string const &effects)
{
    this->name = name;
    this->effects = effects;
}

std::string const &ASpell::getName() const
{
    return(this->name);
}

std::string const &ASpell::getEffects() const
{
    return(this->effects);
}

void ASpell::launch(ATarget const &atref) const
{ 
    atref.getHitBySpell(*this);
}
