#ifndef SPELLBOOK
#define SPELLBOOK
#include "ASpell.hpp"
#include "ATarget.hpp"
#include <map>

class SpellBook
{
    private:
    std::map<std::string , ASpell *>arrs;
    SpellBook(SpellBook const &other);
    SpellBook &operator=(SpellBook const &other);

    public:
    SpellBook();
    ~SpellBook();
    
    void learnSpell(ASpell*as);
    void forgetSpell(std::string const &as);
    ASpell* createSpell(std::string const &as);


};



#endif