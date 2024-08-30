#include "Warlock.hpp"


std::string const &Warlock::getName() const
{
    return(this->name);//std::string const &Warlock ::getName()const;
}

std::string const &Warlock::getTitle() const//std::string const &Warlock ::getTitle()const
{
    return(this->title);
}

Warlock::Warlock(std::string const &name, std::string const &title)
{
     this->name= name;
    this->title =title;
    std::cout<<this->name<<": This looks like another boring day.\n";

}

void Warlock::introduce() const
{
    std::cout<<this->name<<": I am "<<this->name<<", "<<this->title<<"!\n";
}

void Warlock::setTitle(std::string const &str)
{
    this->title =str;
}

Warlock::~Warlock()
{
    std::cout<<this->name<<": My job here is done!\n";
}

