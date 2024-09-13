#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

class ATarget;

class ASpell
{
	private:
	std::string _name;
	std::string	_effects;

	public:
	ASpell();
	ASpell(std::string const& name, std::string const& effects);
	ASpell(const ASpell& other);
	ASpell& operator=(const ASpell& other);
	virtual ~ASpell();

	std::string const& getName() const;
	std::string const& getEffects() const;

	virtual ASpell* clone() = 0;

	void launch(ATarget const& tref) const;
};


#endif