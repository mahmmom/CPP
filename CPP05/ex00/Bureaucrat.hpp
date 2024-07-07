#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

class Bureaucrat
{
    private:
        const std::string _name;
        int _grade;

    public:
        Bureaucrat();
        Bureaucrat(std::string& Name, int Grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        std::string getName() const;
        int getGrade() const;
        void    gradeUp();
        void    gradeDown();

};

 // Exception classes
class GradeTooHighException : public std::exception
{
    public:
    virtual const char* what() throw();
};

class GradeTooLowException : public std::exception
{
    public:
    virtual const char* what() throw();
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);


#endif