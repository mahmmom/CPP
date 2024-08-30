#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const &other)
{
    *this =other;
}

SpellBook &SpellBook::operator=(SpellBook const &other)
{
    this->arrs = other.arrs;
    return(*this);
}

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
}

void SpellBook::learnSpell(ASpell *as)
{
     if(as)
    arrs[as->getName()]=as;
}

void SpellBook::forgetSpell(std::string const &sname)
{
    if(arrs.find(sname)!= arrs.end())
    arrs.erase(arrs.find(sname));
}

ASpell *SpellBook::createSpell(std::string const &sname)
{
    ASpell* tmp= NULL;
     if(arrs.find(sname) != arrs.end())
     tmp= arrs[sname];
     return(tmp);


}
