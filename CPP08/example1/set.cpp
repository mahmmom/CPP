#include <iostream>
#include <set>
//#include <unordered_set> // c++11

/*

Normal set allows to store data, will sort it in ascending order, will not store duplicates directly
Multi set: allows to store duplicates, duplicates are grouped after each other {7 6 6 6 5 2 2 2 1}

Unordered set and Unordered multi set are in c++11, thus we cant use them, but they just do the opposite

*/

//      set
void    printSet(const std::set<int>& my_set)
{
    std::cout << "Vector content = { ";
    for (std::set<int>::const_iterator it = my_set.begin(); it != my_set.end(); ++it)
        std::cout << *it << " ";
    std::cout << "}\n" << std::endl;
}

//      multi set
void    printSet(const std::multiset<int>& my_set)
{
    std::cout << "Vector content = { ";
    for (std::multiset<int>::const_iterator it = my_set.begin(); it != my_set.end(); ++it)
        std::cout << *it << " ";
    std::cout << "}\n" << std::endl;
}

// //      unordered set
// void    printSet(const std::unordered_set<int>& my_set)
// {
//     std::cout << "Vector content = { ";
//     for (std::unordered_set<int>::const_iterator it = my_set.begin(); it != my_set.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << "}\n" << std::endl;
// }

// //      multi unorderded set
// void    printSet(const std::unordered_multiset<int>& my_set)
// {
//     std::cout << "Vector content = { ";
//     for (std::unordered_multiset<int>::const_iterator it = my_set.begin(); it != my_set.end(); ++it)
//         std::cout << *it << " ";
//     std::cout << "}\n" << std::endl;
// }

int main()
{
    //          Adding to the list
    std::set<int> my_set;
    // std::multiset<int> my_set; // accepts duplicates

    //      C++11
    // std::unordered_set<int> my_set;
    // std::unordered_multiset<int> my_set; // accepts duplicates


    int temp = 0;
    std::cout << ".....Enetering in set....." << std::endl;
    while (temp >= 0)
    {
        std::cout << "Enter a number:  ";
        std::cin >> temp;
        if (temp >= 0)
            my_set.insert(temp);
    }
    printSet(my_set);

    //             Removing Item from list
    temp = 0;
    std::cout << "Removing element" << std::endl;
    while (!my_set.empty() && my_set.size() > 0)
    {
        std::cout << "Enter a value to remove:  ";
        std::cin >> temp;
        if (my_set.find(temp) != my_set.end())
        {
            std::cout << "Item: " << *my_set.find(temp) << " is removed" << std::endl;
            my_set.erase(temp);
        }
        else
        {
            std::cout << "Item not found in list" << std::endl;
            break;
        }
    }
    printSet(my_set);
}