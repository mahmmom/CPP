#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat
{
	private:
    	const std::string _name;
		int _grade;

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
};

std::ostream& operator<<(std::ostream& outputStream, const Bureaucrat& other);

#endif