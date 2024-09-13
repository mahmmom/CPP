#ifndef TARGETGENERATOR_HPP
#define TARGETGENERATOR_HPP

#include <iostream>
#include <string>
#include <map>
#include "ATarget.hpp"

class TargetGenerator
{
	private:
	std::map<std::string, ATarget*> tars;
	TargetGenerator(const TargetGenerator& other);
	TargetGenerator& operator=(const TargetGenerator& other);

	public:
	TargetGenerator();
	~TargetGenerator();

	void learnTargetType(ATarget* t);
	void forgetTargetType(std::string const & t);
	ATarget* createTarget(std::string const & t);
};

#endif