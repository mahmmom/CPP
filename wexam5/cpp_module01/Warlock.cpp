#include "Warlock.hpp"


std::string const &Warlock::getName() const
{
   return(this->name);
}

std::string const &Warlock::getTitle() const
{
    return(this->title);
}

Warlock::Warlock(std::string const &name, std::string const &title)
{
    this->name = name;
    this->title = title;
    std::cout<<this->name<<": This looks like another boring day.\n";
}

void Warlock::setTitle(std::string const &str)
{
    this->title= str;
}

void Warlock::introduce() const
{
    std::cout<<this->name<<": I am "<<this->name<<", "<<this->title<<"!\n";
}

Warlock::~Warlock()
{
    std::cout<<this->name<<": My job here is done!\n";
}


void Warlock::learnSpell(ASpell *as)
{
    if(as)
    s_arr[as->getName()]=as;

}

void Warlock::forgetSpell(std::string sname)
{
    if(s_arr.find(sname)!= s_arr.end())
    s_arr.erase(s_arr.find(sname));
    
}

void Warlock::launchSpell(std::string sname, ATarget const &atref)
{
    if(s_arr.find(sname) != s_arr.end())
   s_arr[sname]->launch(atref);
}



