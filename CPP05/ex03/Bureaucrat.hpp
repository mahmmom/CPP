#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>
#include "AForm.hpp"

class Bureaucrat
{
	public:
		Bureaucrat();
		Bureaucrat(std::string& Name, int Grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat& operator=(const Bureaucrat &other);
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;
		void gradeUp();
		void gradeDown();
		void signForm(AForm& form);

		void executeForm(AForm const & form);

		class GradeTooHighException : public std::exception
		{
			public:
			const char* what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
			const char* what() const throw();
		};

	private:
    	const std::string _name;
    	int _grade;
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& other);

#endif