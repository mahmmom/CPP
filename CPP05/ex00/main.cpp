#include "Bureaucrat.hpp"

int main()
{
    try
    {
        std:: string name1 = "Mohamed";
        Bureaucrat b1(name1, 2);
        std::cout << b1 << std::endl;

        b1.gradeUp();
        std::cout << b1 << std::endl;

        b1.gradeUp();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    try
    {
        std:: string name2 = "Adil";
        Bureaucrat b2(name2, 150);
        std::cout << b2 << std::endl;

        b2.gradeDown();
        std::cout << b2 << std::endl;

        b2.gradeDown();
    }
    catch (std::exception& e)
    {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
