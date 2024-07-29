#include <iostream>
#include <deque>

void    print_deque(std::deque<int> numbers)
{
    std::deque<int>::iterator it  = numbers.begin();
    std::cout << "==== My deque ====\n" << "{ ";
    for (it ; it != numbers.end(); ++it)
    {
        std::cout <<*it << " ";
    }
    std::cout << "}"<< std::endl;
    std::cout << "===================" << std::endl;
}

int main()
{
    std::deque<int> numbers;
    int temp = 0;

    std::cout << "....Pushing back...." << std::endl;
    while (temp >= 0)
    {
        std::cout << "Enter a Number:  ";
        std::cin >> temp;
        if (temp >= 0)
        {
            numbers.push_back(temp);
        }
    }
    print_deque(numbers);

    temp = 0;
    std::cout << "....Pushing Front...." << std::endl;
    while (temp >= 0)
    {
        std::cout << "Enter a Number:  ";
        std::cin >> temp;
        if (temp >= 0)
        {
            numbers.push_front(temp);
        }
    }
    print_deque(numbers);
}