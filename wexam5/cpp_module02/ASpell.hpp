#ifndef ASPELL
#define ASPELL
#include <iostream>
#include "ATarget.hpp"

class ATarget;

class ASpell
{
    private:
    std::string name;
    std::string effects;

    public:
    ASpell(ASpell const &other);
    ASpell &operator = (ASpell const &as);
    ASpell();
    virtual ~ASpell();
    ASpell(std::string const &name,std::string const &effects);
    std::string const &getName()const;
    std::string const &getEffects()const;

    virtual ASpell *clone() const = 0;
    void  launch(ATarget const &atref)const;

};

#endif