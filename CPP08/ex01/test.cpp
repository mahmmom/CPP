// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> sp(10);
    
    sp[0] = 0;
    sp[1] = 1;
    sp[2] = 2;
    sp[3] = 3;
    sp[4] = 4;
    
    for(int i = 0; i < sp.size(); i++)
    {
        std::cout << sp[i] << std::endl;
    }
    return 0;
}