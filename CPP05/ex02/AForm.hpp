#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm
{
	private:
		const std::string _name;
		bool	_ifSigned;
		const int _signGrade;
		const int _executeGrade;

	public:
		AForm();
		AForm(std::string name, int signGrade, int executeGrade);
		AForm(const AForm& other);
		AForm& operator=(const AForm& other);
		virtual ~AForm();

		std::string getName() const;
		bool getSignStatus() const;
		void beSigned(Bureaucrat& b1) ;
		int getExecuteGrade() const;
		int getSignGrade() const;

		virtual void execute(Bureaucrat const & executor) const = 0;
		
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

std::ostream& operator<<(std::ostream& outputStream, const AForm& other);

#endif