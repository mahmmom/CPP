#ifndef WARLOCK
#define WARLOCK

#include <iostream>
#include <map>
#include "ATarget.hpp"
#include "ASpell.hpp"
#include "SpellBook.hpp"

class Warlock
{
    private:
    std::string name;
    std::string title;
    SpellBook spellBook;
    // std::map<std::string, ASpell *>arr;


    Warlock();
    Warlock(Warlock const &other);
    Warlock &operator = (Warlock const &other);

    public:
    std::string const &getName()const;
    std::string const &getTitle()const;
    Warlock(std::string const &name, std::string const &title);
    void setTitle(std::string const &str);
    void introduce() const;
    ~Warlock();
    void learnSpell(ASpell *as);
    void forgetSpell(std::string sname);
    void launchSpell(std::string sname, ATarget const &atref);


};
#endif