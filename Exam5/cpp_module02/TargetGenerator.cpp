#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator() {}

TargetGenerator::TargetGenerator(const TargetGenerator& other)
{
	*this = other;
}

TargetGenerator& TargetGenerator::operator=(const TargetGenerator& other)
{
	if (this != &other) {}
	return *this;
}

TargetGenerator::~TargetGenerator() {}

void TargetGenerator::learnTargetType(ATarget* t)
{
	if (t)
		tars[t->getType()] = t;
}

void TargetGenerator::forgetTargetType(std::string const & t)
{
	if(tars.find(t) != tars.end())
		tars.erase(t);
}

ATarget* TargetGenerator::createTarget(std::string const & t)
{
	ATarget* temp = NULL;
	if (tars.find(t) != tars.end())
		temp = tars[t];
	return temp;
}
