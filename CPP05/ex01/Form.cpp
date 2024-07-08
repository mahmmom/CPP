#include "Form.hpp"

Form::Form() : _name("Default"), _ifSigned(false), _signGrade(1), _executeGrade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}


Form::Form(const Form &other) : _name(other._name), _ifSigned(other._ifSigned), _signGrade(other._signGrade), _executeGrade(other._executeGrade)
{
	*this = other;
}

Form &Form::operator=(const Form &other)
{
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

const int Form::getSignGrade() const
{
	return _signGrade;
}

const int Form::getExecuteGrade() const
{
	return _executeGrade;
}

void Form::beSigned(Bureaucrat &b1)
{
	if (b1.getGrade() >= _signGrade)
	{
		_ifSigned = true;
	}
	else
	{
		throw Form::GradeTooLowException();
	}
}

void Form::signForm(Bureaucrat &b2) const
{
	if(_ifSigned == true)
	{
		std::cout << b2.getName() << "signed" << _name << std::endl;
	}
	else
	{
		std::cout << b2.getName() << " couldn't sign " << _name << " because " << e.what() << std::endl;
	}
}

const char* Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high!";
}

const char* Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low!";
}
