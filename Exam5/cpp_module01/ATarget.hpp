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
	ATarget(std::string type);
	ATarget(const ATarget& other);
	ATarget& operator=(const ATarget& other);
	virtual ~ATarget();
	const std::string& getType() const;
	virtual ATarget*	clone() const = 0;
	void	getHitBySpell(const ASpell& ref) const;

};


#endif