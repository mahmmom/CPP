#include <iostream>
#include <queue>


int main()
{
    std::queue<int> numbers;
    int temp = 0;

    std::cout << ".....Push to queue....." << std::endl;
    while (temp >= 0)
    {
        std::cout << "Enter a number:  ";
        std::cin >> temp;
        if (temp >= 0)
            numbers.push(temp);
    }
    
    std::cout << "=====Printing queue=====" << std::endl;
    std::cout << "{ ";
    while(!numbers.empty() && numbers.size() > 0)
    {
        std::cout << numbers.front();
        numbers.pop();
        std::cout << " ";
    }
    std::cout << "}" << std::endl;
    if(numbers.size() > 0)
        std::cout << numbers.front() << std::endl;
    else
        std::cout << "queue is empty" << std::endl;
}