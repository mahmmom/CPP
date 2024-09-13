#ifndef ATARGET_HPP
#define ATARGET_HPP

#include <iostream>
#include <string>

class ASpell;

class ATarget
{
	private:
	std::string _type;

	public:
	ATarget();
	ATarget(std::string const& type);
	ATarget(const ATarget& other);
	ATarget& operator=(const ATarget& other);
	virtual~ATarget();

	std::string const& getType() const;

	virtual ATarget* clone() = 0;

	void	getHitBySpell(ASpell const& ref) const;

};


#endif