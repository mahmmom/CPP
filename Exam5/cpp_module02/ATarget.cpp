#include "ATarget.hpp"
#include "ASpell.hpp"

ATarget::ATarget() : _type("") 
{

}

ATarget::ATarget(std::string const& type) : _type(type)
{
	
}

ATarget::ATarget(const ATarget& other)
{
	*this = other;
}

ATarget&  ATarget::operator=(const ATarget& other)
{
	if (this != &other)
	{
		this->_type = other._type;
	}
	return *this;
}

ATarget::~ATarget()
{
	
}

std::string const& ATarget::getType() const
{
	return this->_type;
}

void	ATarget::getHitBySpell(ASpell const& ref) const
{
	std::cout << this->_type << " has been " << ref.getEffects() << "!" << std::endl;
}
