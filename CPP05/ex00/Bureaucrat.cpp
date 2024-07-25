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

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
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
    if(_grade <= 1)
        throw GradeTooHighException();
    _grade--;
}

void Bureaucrat::gradeDown()
{
    if(_grade >= 150)
        throw GradeTooLowException();
    _grade++; 
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw()
{
    return "Grade is too low!";
}

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& other)
{
    outputStream << other.getName() << ", bureaucrat grade " << other.getGrade();
    return outputStream;
}


/*
	throw()
	1) The throw() specifier at the end of the what method declaration indicates that 
	   this method does not throw any exceptions.

	2) In modern C++, the noexcept specifier is preferred, but throw() is still valid
	   and often seen in older codebases.
*/

/*
	const char*

	1) Efficiency: Returning a const char* is efficient because it doesn't involve any dynamic memory allocation or complex object management.
	   The string literal is stored in the program's read-only memory segment and can be returned quickly.

	2) Simplicity: Exception messages are often simple and static. 
	   A string literal can easily be used to convey the error message without the overhead of managing a std::string object.

	3) Compatibility: The what method in the std::exception class, which is the base class for all standard exception types,
	   returns a const char*. Using the same return type ensures compatibility with standard library exception handling mechanisms.
*/


/*
	Reasons for Using const std::exception& e in Catch Blocks
	
	1) Polymorphism:
	- Base Class for Exceptions: The std::exception class is the base class for all standard exception types in C++.
	  By catching std::exception, you can handle any standard exception type (e.g., std::runtime_error, std::logic_error, std::bad_alloc, etc.) using a single catch block.
	- Derived Classes: Custom exception classes (like GradeTooHighException and GradeTooLowException in your Bureaucrat example) can also inherit from std::exception.
	  This allows you to catch custom exceptions as well.
	
	2) Read-Only Access:
	- Const Correctness: By catching the exception by const reference, you ensure that the exception object is not modified within the catch block.
	  This promotes const correctness and makes it clear that the catch block is only inspecting the exception, not altering it.
	
	3) Avoiding Slicing:
	- Object Slicing: If you catch by value (e.g., catch(std::exception e)), the exception object might be sliced.
	  Object slicing occurs when a derived class object is assigned to a base class object, resulting in the loss of the derived class’s data members.
	  Catching by reference avoids this issue and preserves the complete exception object.

	4) Access to what() Method:
	- Descriptive Error Message: The std::exception class defines a virtual what() method that returns a C-style string describing the error.
	  By catching std::exception, you can call this method to get a human-readable description of the error, which is useful for logging or displaying error messages.
*/
