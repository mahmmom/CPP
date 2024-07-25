#include "iter.hpp"

// FIX Make re

template <typename T>
void print(T const &element)
{
    std::cout << "Template = " << element << std::endl;
}

int main()
{
    int intArray[5] = {1, 2, 3, 4, 5};
    std::string strArray[5] = {"A", "B", "C", "D", "E"};

    std::cout << "Testing iter with int array:" << std::endl;
    ::iter(intArray, 5, print<int>);

    std::cout << "Testing iter with string array:" << std::endl;
    ::iter(strArray, 5, print<std::string>);

    return 0;
}

/*
void printInt(int x)
{
    std::cout << "Print Int = " << x << std::endl;
}

void printString(const std::string &str)
{
    std::cout << "print String = " << str << std::endl;
}
*/