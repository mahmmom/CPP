#ifndef ATARGET
#define ATARGET
#include <iostream>
#include "ASpell.hpp"

class ASpell;

class ATarget
{
    private:
    std::string type;
    

    public:
    ATarget(ATarget const &other);
    ATarget &operator = (ATarget const &at);
    ATarget();
    virtual ~ATarget();
    ATarget(std::string const &type);
    std::string const &getType()const;
  

    virtual ATarget *clone() const = 0;
    void getHitBySpell(ASpell const &asref)const;

};

#endif