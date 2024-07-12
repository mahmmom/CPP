#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm() : _name("Default"), _ifSigned(false), _signGrade(1), _executeGrade(1)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(std::string name, int signGrade, int executeGrade) 
	: _name(name), _ifSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw AForm::GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw AForm::GradeTooLowException();
	std::cout << "AForm naming constructor called" << std::endl;
}

AForm::AForm(const AForm &other) 
	: _name(other._name), _ifSigned(other._ifSigned),
	_signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "AForm copy constructor called" << std::endl;
	*this = other;
}

AForm &AForm::operator=(const AForm &other)
{
	std::cout << "AForm copy assigment operator called" << std::endl;
	if (this != &other)
	{
		this->_ifSigned = other._ifSigned;
	}
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

std::string AForm::getName() const
{
	return _name;
}

bool AForm::getSignStatus() const
{
	return _ifSigned;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecuteGrade() const
{
	return _executeGrade;
}

void AForm::beSigned(Bureaucrat& b1)
{
	if (b1.getGrade() <= _signGrade)
		_ifSigned = true;
	else
		throw AForm::GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& outputStream, const AForm& other)
{
    outputStream << "AForm name: " << other.getName() << std::endl
	<< "AForm sign status: " << other.getSignStatus() << std::endl
	<< "AForm sign grade: " << other.getSignGrade() << std::endl
	<< "AForm execute grade: " << other.getExecuteGrade();
    return outputStream;
}
