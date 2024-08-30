#include "Dummy.hpp"

Dummy::Dummy() : ATarget("Target Practice Dummy")
{

}

Dummy::~Dummy()
{
	
}

ATarget* Dummy::clone() const
{
	return new Dummy();
}

// Dummy::Dummy(const Dummy& other)
// {
// 	*this = other;
// }

// Dummy& Dummy::operator=(const Dummy& other)
// {
// 	(void)other;
// 	return *this;
// }


// const std::string& Dummy::getType() const
// {
// 	return this->_type;
// }

// void	Dummy::getHitBySpell(const ASpell& ref) const
// {
// 	std::cout << this->_type << " has been " << ref.getEffects() << "!" << std::endl;
// }