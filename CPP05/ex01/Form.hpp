#ifndef FORM_HPP
#define FORM_HPP

#include "Bureaucrat.hpp"

/*
	Then, let’s make a Form class. It has:
	• A constant name.
	• A boolean indicating whether it is signed (at construction, it’s not).
	• A constant grade required to sign it.
	• And a constant grade required to execute it.
	All these attributes are private, not protected
*/

class Form
{
	private:
		const std::string _name;
		bool	_ifSigned;
		const int _signGrade;
		const int _executeGrade;

	public:
		Form();
		Form(const Form& other);
		Form& operator=(const Form& other);
		~Form();

		std::string getName() const;
		bool	getSignStatus() const;
		const int	getSignGrade() const;
		const int	getExecuteGrade() const;
		void	beSigned(Bureaucrat& b1);
		void	signForm(Bureaucrat &b2) const;


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

#endif