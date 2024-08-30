#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(TargetGenerator const &other)
{
    *this = other;
}

TargetGenerator &TargetGenerator::operator=(TargetGenerator const &other)
{
   this->arrt= other.arrt;
   return(*this);
}

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget *at)
{
      if(at)
    arrt[at->getType()]=at;
}

void TargetGenerator::forgetTargetType(std::string const &tname)
{
     if(arrt.find(tname)!= arrt.end())
    arrt.erase(arrt.find(tname));
}

ATarget *TargetGenerator::createTarget(std::string const &tname)
{
     ATarget* tmp= NULL;
     if(arrt.find(tname) != arrt.end())
     tmp= arrt[tname];
     return(tmp);
}
