#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class Form
{
	private:
		const std::string _name;
		bool	_ifSigned;
		const int _signGrade;
		const int _executeGrade;

	public:
		Form();
		Form(std::string name, int signGrade, int executeGrade);
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const;
		bool getSignStatus() const;
		void beSigned(Bureaucrat& b1);
		int getExecuteGrade() const;
		int getSignGrade() const;
		
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

		class CantSignException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& outputStream, const Form& other);

#endif