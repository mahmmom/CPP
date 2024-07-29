#include <iostream>
#include <queue>

/*

priority queues will always have the biggest number in top

the pop function wil remove the number in top always,

*/

int main()
{
    std::priority_queue<std::string> numbers;
    std::string temp = "default";

    std::cout << ".....Push to priority queue....." << std::endl;
    while (temp != "/")
    {
        std::cout << "Enter a string:  ";
        std::cin >> temp;
        if (temp != "/")
            numbers.push(temp);
    }
    
    std::cout << "=====Printing priority queue=====" << std::endl;
    std::cout << "{ ";
    while(!numbers.empty() && numbers.size() > 0)
    {
        std::cout << numbers.top();
        numbers.pop();
        std::cout << " ";
    }
    std::cout << "}" << std::endl;
    if(numbers.size() > 0)
        std::cout << numbers.top() << std::endl;
    else
        std::cout << "priority queue is empty" << std::endl;
}