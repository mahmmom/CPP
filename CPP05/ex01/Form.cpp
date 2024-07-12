#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form() : _name("Default"), _ifSigned(false), _signGrade(1), _executeGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string name, int signGrade, int executeGrade) 
	: _name(name), _ifSigned(false), _signGrade(signGrade), _executeGrade(executeGrade)
{
	if (_signGrade < 1 || _executeGrade < 1)
		throw Form::GradeTooHighException();
	if (_signGrade > 150 || _executeGrade > 150)
		throw Form::GradeTooLowException();
	std::cout << "Form naming constructor called" << std::endl;
}

Form::Form(const Form &other) 
	: _name(other._name), _ifSigned(other._ifSigned),
	_signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	std::cout << "Form copy constructor called" << std::endl;
	*this = other;
}

Form &Form::operator=(const Form &other)
{
	std::cout << "Form copy assigment operator called" << std::endl;
	if (this != &other)
	{
		this->_ifSigned = other._ifSigned;
	}
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const
{
	return _name;
}

bool Form::getSignStatus() const
{
	return _ifSigned;
}

int Form::getSignGrade() const
{
	return _signGrade;
}

int Form::getExecuteGrade() const
{
	return _executeGrade;
}

void Form::beSigned(Bureaucrat& b1)
{
	if (b1.getGrade() <= _signGrade)
	{
		_ifSigned = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Can't sign: Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Can't sign: Grade is too low!";
}

std::ostream& operator<<(std::ostream& outputStream, const Form& other)
{
    outputStream << "Form name: " << other.getName() << std::endl
	<< "Form sign status: " << other.getSignStatus() << std::endl
	<< "Form sign grade: " << other.getSignGrade() << std::endl
	<< "Form execute grade: " << other.getExecuteGrade();
    return outputStream;
}