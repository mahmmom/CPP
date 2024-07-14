#include "Intern.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
	levels[0] = "shrubbery creation";
    levels[1] = "robotomy request";
    levels[2] = "presidential pardon";

    formFunc[0] = &Intern::ShrubberyCreation;
    formFunc[1] = &Intern::RobotomyRequest;
    formFunc[2] = &Intern::PresidentialPardon;
	
	std::cout << "Intern default constructor" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor" << std::endl;
	*this = other;
}

Intern &Intern::operator=(const Intern &other)
{
	std::cout << "Intern copy assignment operator called" << std::endl;
	if(this != &other){}
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor" << std::endl;
}

// int	levFinder(std::string level)
// {
// 	std::string levels[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
// 	std::cout << level << std::endl;
//     for (int i = 0; i < 3; ++i)
// 	{
//         if (levels[i] == level)
//             return(i);
//     }
// 	return(3);
// }

// AForm *Intern::makeForm(std::string formName, std::string target)
// {
// 	std::string newName;
// 	int	j = 0;
// 	for (size_t i = 0; i < formName.size(); i++)
// 	{
// 		while(formName[j] == ' ')
// 			j++;
// 		std::cout << formName << std::endl;
// 		newName[i] = (char)std::towlower(formName[i]);
// 		// std::cout << newName[i] << std::endl;
// 		if (i == formName.size()) {
// 			newName[i] = 0;
// 			break;
// 		}
// 	}
// 	std::cout << newName << std::endl;
// 	int formLevel = levFinder(newName);
// 	switch (formLevel)
// 	{
// 	case 0:
// 		return new ShrubberyCreationForm(target);
// 		// break;
// 	case 1:
// 		return new RobotomyRequestForm(target);
// 		// break;
// 	case 2:
// 		return new PresidentialPardonForm(target);
// 		// break;
// 	default:
// 		std::cout << "Form name given doesn't exist" << std::endl;
// 		return NULL;
// 		// break;
// 	}
// 	return NULL;
// }

// AForm *Intern::makeForm(std::string formName, std::string target)
// {
//     // Initialize newName with the size of formName
//     std::string newName(formName.size(), '\0');

// 	for (size_t i = 0; i < formName.size(); i++)
//     {
//         newName[i] = (char)std::tolower(formName[i]); // Use std::tolower for char
//     }
//     std::cout << "Form name in lowercase: " << newName << std::endl;
//     int formLevel = levFinder(newName);
//     switch (formLevel)
//     {
// 		case 0:
// 			return new ShrubberyCreationForm(target);
// 		case 1:
// 			return new RobotomyRequestForm(target);
// 		case 2:
// 			return new PresidentialPardonForm(target);
// 		default:
// 			std::cout << "Form name given doesn't exist" << std::endl;
// 			return NULL;
//     }
// }

AForm* Intern::ShrubberyCreation(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::RobotomyRequest(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::PresidentialPardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

const char* Intern::InvalidFormException::what() const throw()
{
	return "Form not found";
}

AForm*	Intern::makeForm(std::string formName, std::string target)
{
	std::string newName(formName.size(), '\0');
	for (size_t i = 0; i < formName.size(); i++)
		newName[i] = (char)std::tolower(formName[i]);
    for (int i = 0; i < 3; ++i)
	{
		if (levels[i] == newName)
            return (this->*formFunc[i])(target);
    }
	throw InvalidFormException();
	return NULL;
}
