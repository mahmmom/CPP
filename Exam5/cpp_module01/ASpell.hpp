#ifndef ASPELL_HPP
#define ASPELL_HPP

#include <iostream>
#include <string>

class ATarget;

class ASpell
{
	private:
	std::string _name;
	std::string _effects;


	public:
	ASpell();
	ASpell(std::string name, std::string effects);
	ASpell(const ASpell& other);
	ASpell& operator=(const ASpell& other);
	virtual ~ASpell();

	std::string  getName() const;
	std::string getEffects() const;
	virtual ASpell*  clone() = 0;
	void	launch(const ATarget& ref) const;
};


#endif