// forward-iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    forward_list<int> fl1 = { 1, 2, 3, 4, 5 };
    forward_list<int>::iterator it1;     // forward iterator
    
    for(it1 = fl1.begin(); it1!= fl1.end(); ++it1)
	{
        cout << *it1 << " ";
    }
    cout << endl;
    
    return 0;
}
