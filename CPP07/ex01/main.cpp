#include "iter.hpp"

template <typename T>
void print(T const &element)
{
    std::cout << YELLOW << "Template = " << element << RESET << std::endl;
}

int main()
{
    int intArray[5] = {1, 2, 3, 4, 5};
    std::cout << BLUE << "Testing iter with int array:" << RESET << std::endl;
    ::iter(intArray, 10, print<int>);

	std::string strArray[5] = {"A", "B", "C", "D", "E"};
    std::cout << GREEN << "Testing iter with string array:" << RESET << std::endl;
    ::iter(strArray, 5, print<std::string>);

	// int *arr = new int[5];
	// arr[0] = 0;
	// arr[1] = 1;
	// arr[2] = 2;
	// arr[3] = 3;
	// arr[4] = 4;

	// ::iter(arr[0], 5, print<int>);

    return 0;
}
