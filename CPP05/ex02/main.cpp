#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"

// int main()
// {
//     try
//     {
// 		std::cout << "\033[34mConstructing\033[0m" << std::endl;
//         std:: string name1 = "Mohamed";
//         std:: string name2 = "Nour";
//         Bureaucrat b1(name1, 6);
//         Bureaucrat b2(name2, 140);
// 		Form f1("Form A", 5, 10);
// 		Form f2("Form B",145, 100);

//         std::cout << "\033[34mTesting\033[0m" << std::endl;
// 		std::cout << b1 << std::endl;
// 		std::cout << f1 << std::endl;
// 		b1.signForm(f1);
// 		b2.signForm(f2);
// 		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
//     }
//     catch (std::exception& e)
//     {
// 		std::cout << "\033[34mException\033[0m" << std::endl;
//         std::cout << e.what() << std::endl;
//     }

//     return 0;
// }

int main()
{
	{
		try
		{
			/* code */
		}
		catch(AForm::GradeTooLowException &e)
		{
			std::cerr << e.what() << '\n';
		}
		
		std::string name = "Mohamed";
		Bureaucrat B(name, 151);
		ShrubberyCreationForm A("target");
		B.signForm(A);
		B.executeForm(A);
	}
}