#include <iostream>
#include <vector>


void    printVector(const std::vector<int>& my_vector)
{
    std::cout << "Vector content = { ";
    for (std::vector<int>::const_iterator it = my_vector.begin(); it != my_vector.end(); ++it)
        std::cout << *it << " ";
    std::cout << "}\n" << std::endl;
}


int main ()
{
    //         Example 1 - Push Back
    std::vector<int> my_vector;
    int value = 0;

    std::cout << "Pushing Back to vector" << std::endl;
    while (value >=0)
    {
        std::cout << "Enter a number: ";
        std::cin >> value;
        if (value >= 0)
            my_vector.push_back(value);
    }
    printVector(my_vector);

    //         Example 2 - Push Front
    std::cout << "Pushing Front to vector" << std::endl;
    value = 0;
    while (value >=0)
    {
        std::cout << "Enter a number: ";
        std::cin >> value;
        if (value >= 0)
            my_vector.insert(my_vector.begin(), value);
    }
    printVector(my_vector);

    //          Example insert in a specific location
    std::cout << "Inserting to vector" << std::endl;
    int index = 0;
    value = 0;
    while (index >=0 && value >=0)
    {
        std::cout << "Enter an index: ";
        std::cin >> index;
        if (index >= 0)
        {
            std::cout << "Enter a number: ";
            std::cin >> value;
            if(value >= 0)
                my_vector.insert(my_vector.begin() + index, value);
        }
    }
    printVector(my_vector);

    //          Modify element in a specific location
     std::cout << "Modifying element in vector" << std::endl;
    index = 0;
    value = 0;
    while (index >=0 && value >=0)
    {
        std::cout << "Enter an index: ";
        std::cin >> index;
        if (index >= 0 && index < my_vector.size())
        {
            std::cout << "Enter a number: ";
            std::cin >> value;
            if(value >= 0)
                my_vector[index] = value;
        }
    }
    printVector(my_vector);
}