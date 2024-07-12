#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm("Default", 25, 5)
{
	this->_target= "Default"; 
	std::cout << "PresidentialPardon default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm(target, 25, 5)
{
	this->_target = target;
	std::cout << "PresidentialPardon naming constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other)
{
	std::cout << "PresidentialPardon copy constructor called" << std::endl;
	*this = other;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	std::cout << "PresidentialPardon copy assignment operator called" << std::endl;
	if(this != &other)
	{
		AForm::operator=(other);
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardon destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (this->getSignStatus() == true && executor.getGrade() <= this->getExecuteGrade())
		std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
	else
		throw CantExecuteException();
}

const char* PresidentialPardonForm::CantExecuteException::what() const throw()
{
	return "Can't execute: Grade is too low!";
}
