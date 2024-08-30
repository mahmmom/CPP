#include "Warlock.hpp"

Warlock::Warlock()
{

}

Warlock::Warlock(const Warlock& other)
{
	*this = other;
}

Warlock::~Warlock()
{
	std::cout << _name << ": My job here is done!" << std::endl;
	for (std::map<std::string, ASpell*>::iterator it = spells.begin(); it != spells.end(); ++it)
	{
        delete it->second;
    }
    spells.clear();
}

Warlock& Warlock::operator=(const Warlock& other)
{
	if(this != &other)
	{
		this->_name = other._name;
		this->_title = other._title;
	}
	return *this;
}

Warlock::Warlock(const std::string& name, const std::string& title) : _name(name) , _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

const std::string& Warlock::getName() const
{
	return this->_name;
}

const std::string& Warlock::getTitle() const
{
	return this->_title;
}

void	Warlock::setTitle(const std::string& str)
{
	this->_title = str;
}

void	Warlock::introduce() const
{
	std::cout << _name << ": I am "<< _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell)
{
    if (spell)
        spells[spell->getName()] = spell->clone();
}

void	Warlock::forgetSpell(std::string spellName)
{
	std::map<std::string, ASpell*>::iterator it = spells.find(spellName);
	if (it->second)
		delete it->second;
	spells.erase(it);


	// if (spells[spellName])
	// 	spells.erase(spellName);
}

void	Warlock::launchSpell(std::string spellName, const ATarget& target)
{
	std::map<std::string, ASpell*>::const_iterator it = spells.find(spellName);
	if (it != spells.end())
		it->second->launch(target);
}
