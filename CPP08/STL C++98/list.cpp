#include <iostream>
#include <list>


void    printlist(const std::list<int>& my_list)
{
    std::cout << "list content = { ";
    for (std::list<int>::const_iterator it = my_list.begin(); it != my_list.end(); ++it)
        std::cout << *it << " ";
    std::cout << "}\n" << std::endl;
}


int main ()
{
    //         Example 1 - Push Back
    std::list<int> my_list;
    int value = 0;

    std::cout << "Pushing Back to list" << std::endl;
    while (value >=0)
    {
        std::cout << "Enter a number: ";
        std::cin >> value;
        if (value >= 0)
            my_list.push_back(value);
    }
    printlist(my_list);

    //         Example 2 - Push Front
    std::cout << "Pushing Front to list" << std::endl;
    value = 0;
    while (value >=0)
    {
        std::cout << "Enter a number: ";
        std::cin >> value;
        if (value >= 0)
            my_list.push_front(value) ;
    }
    printlist(my_list);

            //   Example insert in a specific location
    std::cout << "Inserting to list" << std::endl;
    std::list<int>::iterator it = my_list.begin(); // init iterator for the list
    int index = 0;
    value = 0;
    while (index >=0 && value >=0)
    {
        std::cout << "Enter an index: ";
        std::cin >> index;
        if (index >= 0)
        {
            std::advance(it, index); // Move iterator to the 3rd position
            std::cout << "Enter a number: ";
            std::cin >> value;
            if(value >= 0)
                my_list.insert(it, value); // use insert to insert the value in the list
        }
    }
    printlist(my_list);

    //          Modify element in a specific location
    std::cout << "Modify to list" << std::endl;
    it = my_list.begin(); // init iterator for the list
    index = 0;
    value = 0;
    while (index >=0 && value >=0)
    {
        std::cout << "Enter an index: ";
        std::cin >> index;
        if (index >= 0 && index < my_list.size())
        {
            std::advance(it, index); // Move iterator to the 3rd position
            std::cout << "Enter a number: ";
            std::cin >> value;
            if(value >= 0)
                *it = value;
        }
    }
    printlist(my_list);
}