#include "Warlock.hpp"


Warlock::Warlock() : _name("") , _title("")
{

}

Warlock::Warlock(const Warlock& other)
{
	*this = other;
}

Warlock& Warlock::operator=(const Warlock& other)
{
	if (this != &other)
	{
		this->_name = other._name;
		this->_title = other._title;
	}
	return *this;
}

Warlock::Warlock(std::string const& name, std::string const& title) : _name(name) , _title(title) , sb()
{
	std::cout << this->_name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	std::cout << this->_name << ": My job here is done!" << std::endl;
}


std::string const&	Warlock::getName() const
{
	return this->_name;
}

std::string const&	Warlock::getTitle() const
{
	return this->_title;
}

void	Warlock::setTitle(std::string const& str)
{
	this->_title = str;
}

void Warlock::introduce() const
{
	std::cout << this->_name << ": I am " << this->_name << ", " << this->_title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* s)
{
	if(s)
		sb.learnSpell(s);
}

void	Warlock::forgetSpell(std::string s)
{
	sb.forgetSpell(s);
}

void	Warlock::launchSpell(std::string sn, ATarget const& tar)
{
	if (sb.createSpell(sn))
		sb.createSpell(sn)->launch(tar);
}