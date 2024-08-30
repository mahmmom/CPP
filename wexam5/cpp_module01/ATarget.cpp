#include "ATarget.hpp"

ATarget::ATarget(ATarget const &other)
{
    *this = other;
}

ATarget &ATarget::operator=(ATarget const &at)
{
    this->type = at.type;
    return(*this);
}

ATarget::ATarget()
{
}

ATarget::~ATarget()
{
}

ATarget::ATarget(std::string const &type)
{
    this->type = type;
}

std::string const &ATarget::getType() const
{
    return(this->type);
}

void ATarget::getHitBySpell(ASpell const &asref) const
{
    std::cout<<this->type<<" has been "<<asref.getEffects()<<"!\n";
}
