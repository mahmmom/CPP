#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"


class ShrubberyCreationForm : public AForm
{
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();
		void beSigned(Bureaucrat& b1);
		void execute(Bureaucrat const & executor) const;

		class InvalidFileException : public std::exception
		{
			public:
				const char* what() const throw();
		};

		class CantExecuteException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};


#endif