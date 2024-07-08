#include "Bureaucrat.hpp"

int main()
{
    try
    {
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
        std:: string name1 = "Mohamed";
        Bureaucrat b1(name1, 3);

        std::cout << "\033[34mTesting\033[0m" << std::endl;
        std::cout << b1 << std::endl;
		b1.gradeUp();
        std::cout << b1 << std::endl;
        b1.gradeUp();
		std::cout << "This line will be printed if grade > 2" << std::endl;
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
    }
    catch (std::exception& e)
    {
		std::cout << "\033[34mException\033[0m" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
		std::cout << "\033[34mConstructing\033[0m" << std::endl;
        std:: string name1 = "Mohamed";
        Bureaucrat b1(name1, 148);

        std::cout << "\033[34mTesting\033[0m" << std::endl;
        std::cout << b1 << std::endl;
		b1.gradeDown();
        std::cout << b1 << std::endl;
        b1.gradeDown();
		std::cout << "This line will be printed if grade < 149" << std::endl;
		std::cout << "\033[34mDeconstructing\033[0m" << std::endl;
    }
    catch (std::exception& e)
    {
		std::cout << "\033[34mException\033[0m" << std::endl;
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
