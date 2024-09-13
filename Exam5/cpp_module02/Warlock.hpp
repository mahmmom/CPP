#ifndef WARLOCK_HPP
#define WARLOCK_HPP

#include <iostream>
#include <string>
#include <map>
#include "SpellBook.hpp"

class Warlock
{
	private:
	std::string _name;
	std::string _title;
	//std::map<std::string, ASpell*> spells;
	SpellBook sb;
	Warlock();
	Warlock(const Warlock& other);
	Warlock& operator=(const Warlock& other);

	public:
	Warlock(std::string const& name, std::string const& title);
	~Warlock();

	std::string const&	getName() const;
	std::string const&	getTitle() const;

	void	setTitle(std::string const& str);
	void	introduce() const;

	void	learnSpell(ASpell* s);
	void	forgetSpell(std::string s);
	void	launchSpell(std::string sn, ATarget const& tar);
};


#endif