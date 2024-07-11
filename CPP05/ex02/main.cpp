#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	{
		try
		{
			std::cout << "\033[34mConstructing\033[0m" << std::endl;
			std::string name1 = "Mohamed";
			Bureaucrat B1(name1, 1);
			ShrubberyCreationForm A1("target");
			std::cout << "\033[34mTesting\033[0m" << std::endl;
			B1.signForm(A1);
			B1.executeForm(A1);
			std::cout <<"==========================================" << std::endl;
			std::cout << "\033[34mConstructing\033[0m" << std::endl;
			std::string name2 = "Mohamed";
			Bureaucrat B2(name2, 3);
			RobotomyRequestForm A2("target");
			std::cout << "\033[34mTesting\033[0m" << std::endl;
			B2.signForm(A2);
			B2.executeForm(A2);
			B2.executeForm(A2);
			B2.executeForm(A2);
			B2.executeForm(A2);
			std::cout <<"==========================================" << std::endl;
			std::cout << "\033[34mConstructing\033[0m" << std::endl;
			std::string name3 = "Mohamed";
			Bureaucrat B3(name3, 5);
			PresidentialPardonForm A3("target");
			std::cout << "\033[34mTesting\033[0m" << std::endl;
			B3.signForm(A3);
			B3.executeForm(A3);
			std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
		}
		catch(std::exception& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
}