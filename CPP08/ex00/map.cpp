#include <iostream>
#include <map>
#include <cstdlib> // for atoi
//#include <unordered_map> // c++11

/*

Normal map allows to store data, will sort it in ascending order, will not store duplicates directly
Multi map: allows to store duplicates, duplicates are grouped after each other {7 6 6 6 5 2 2 2 1}

Map needs a key then the value, like (int,std::string) -> (0,mohamed), accessing done by key, and removal also

Unordered map and Unordered multi map are in c++11, thus we cant use them, but they just do the opposite

*/

//      map
void printmap(const std::map<int, std::string>& my_map)
{
    std::cout << "Map content = { ";
    for (std::map<int, std::string>::const_iterator it = my_map.begin(); it != my_map.end(); ++it)
    {
        std::cout << it->first << " --> " << it->second << " ";
    }
    std::cout << " }" << std::endl;
}

// //      multi map
void    printmap(const std::multimap<int,std::string>& my_map)
{
 std::cout << "Map content = { ";
    for (std::multimap<int, std::string>::const_iterator it = my_map.begin(); it != my_map.end(); ++it)
    {
        std::cout << it->first << " --> " << it->second << " ";
    }
    std::cout << " }" << std::endl;
}


int main()
{
    //          Adding to the list
    std::map<int,std::string> my_map;
    // std::multimap<int,int> my_map; // accepts duplicates

    //      C++11
    // std::unordered_map<int,int> my_map;
    // std::unordered_multimap<int,int> my_map; // accepts duplicates


    int temp = 0;
    std::string str;
    std::pair<int,std::string> p;
    std::cout << ".....Enetering in map....." << std::endl;
    while (temp >= 0)
    {
        std::cout << "Enter key:  ";
        std::getline(std::cin,str);
        temp = atoi(str.c_str());
        if (temp >= 0)
        {
            p.first = temp;
            std::cout << "Enter a string:  ";
            std::getline(std::cin,str);
            p.second = str;
            my_map.insert(p);
        }
    }
    printmap(my_map);

    //             Removing Item from list
    temp = 0;
    std::cout << "Removing element" << std::endl;
    while (!my_map.empty() && my_map.size() > 0)
    {
        std::cout << "Enter key:  ";
        std::getline(std::cin,str);
        temp = atoi(str.c_str());
        if (my_map.find(p.first) != my_map.end())
        {
            std::cout << "Item: " << my_map.at(temp) << " is removed" << std::endl;
            my_map.erase(temp);
        }
        else
        {
            std::cout << "Item not found in map" << std::endl;
            break;
        }
    }
    printmap(my_map);
}