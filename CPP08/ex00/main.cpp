#include "easyfind.hpp"

int main()
{
    std::vector<int> v;
	// std::deque<int> v;
	// std::list<int> v;
	// std::set<int> v;
    
    v.push_back(22);
    v.push_back(13);
    v.push_back(100);
    v.push_back(-40);

    try
    {
        std::vector<int>::iterator it = easyfind(v, 100);
        std::cout << YELLOW << "Occurrence " << CYAN << *it << YELLOW <<" is found at position: ";
		std::cout << CYAN << std::distance(v.begin(), it) << RESET << std::endl;


        it = easyfind(v, 10);
        std::cout << GREEN << "Occurrence found at position: " << *it << RESET << std::endl;
    }
    catch (const std::exception& e)
    {
        std::cerr << RED << e.what() << RESET << std::endl;
    }

    return 0;
}
