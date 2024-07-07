#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Default") , _grade(1)
{
    std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string& Name, int Grade) : _name(Name) , _grade(Grade)
{
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
    std::cout << "Bureaucrat naming constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy constructor called" << std::endl;
    *this = other;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat copy assignment constructor called" << std::endl;
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return *this;
}

Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() const
{
    return _name;
}

int Bureaucrat::getGrade() const
{
    return _grade;
}

void Bureaucrat::gradeUp()
{
    if(_grade < 2)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::gradeDown()
{
    if(_grade > 151)
        throw GradeTooLowException();
    _grade++; 
}

const char* what() throw()
{
    return "Grade is too high!";
}

const char* what() throw()
{
    return "Grade is too low!";
}
