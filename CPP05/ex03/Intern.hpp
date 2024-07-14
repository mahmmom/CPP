#ifndef INTERN_HPP
#define INTERN_HPP
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
	private:
		typedef AForm* (Intern::*func)(std::string target);
		func formFunc[3];
		std::string levels[3];
		AForm* ShrubberyCreation(std::string target);
		AForm* RobotomyRequest(std::string target);
		AForm* PresidentialPardon(std::string target);
		
	public:
		Intern();
		Intern(const Intern& other);
		Intern& operator=(const Intern& other);
		~Intern();

		AForm *makeForm(std::string formName, std::string target);

		class InvalidFormException : public std::exception
		{
			public:
				const char* what() const throw();
		};
};

// int	levFinder(std::string level);

#endif