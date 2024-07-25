#include <iostream>
#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    // srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = i;
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
		std::cout << numbers[i] << std::endl;
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    return 0;
}

// int main()
// {
// 	size_t size = 5;
	
// 	Array<int> numbers(size);

// 	for (size_t i = 0; i < size; i++)
// 	{
// 		numbers[i] = i;
// 		std::cout << numbers[i] << std::endl;
// 	}

// 	Array<int> num2(numbers);
// 		for (size_t i = 0; i < size; i++)
// 	{
// 		num2[i] = 99;
// 		std::cout << num2[i] << std::endl;
// 	}

// }