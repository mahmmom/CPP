#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"


RobotomyRequestForm::RobotomyRequestForm() : AForm("Default", 72, 45)
{
	this->_target= "Default"; 
	std::cout << "Robotomy default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45)
{
	this->_target = target;
	std::cout << "Robotomy naming constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other)
{
	std::cout << "Robotomy copy constructor called" << std::endl;
	*this = other;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	std::cout << "Robotomy copy assignment operator called" << std::endl;
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "Robotomy destructor called" << std::endl;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (this->getSignStatus() == true && executor.getGrade() <= this->getExecuteGrade())
	{
		static long long tracker;
		if(tracker % 2 == 0)
			std::cout << _target << " has been robotomized" << std::endl;
		else
			std::cout << _target << " robotomy failed" << std::endl;
		tracker++;
	}
	else
	{
		throw CantExecuteException();
	}
}

const char* RobotomyRequestForm::CantExecuteException::what() const throw()
{
	return "Can't execute: Grade is too low!";
}
