#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	{
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
		Intern someRandomIntern;
		AForm* rrf = NULL;
		try
		{
			std::string name1 = "Mohamed";
			Bureaucrat B1(name1, 1);
			rrf = someRandomIntern.makeForm("presidential PARDON", "Tiger");
			std::cout << "\033[34mTesting\033[0m" << std::endl;
			B1.signForm(*rrf);
			B1.executeForm(*rrf);
			B1.executeForm(*rrf);
			std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << "\033[34mException\033[0m" << std::endl;
			std::cerr << e.what() << std::endl;
		}
		delete rrf;
	}
}
