// iterator.cpp by Bill Weinman <http://bw.org/>
// 2018-09-18 for CppSTL
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> vi2;
    vector<int>::iterator it2;   // iterator object
    vector<int>::iterator ibegin;
    vector<int>::iterator iend;

	for (int i = 0;  i < 5; i++)
	{
		vi2.push_back(i);
	}
    
	ibegin = vi2.begin();
	iend = vi2.end();
	
    for(it2 = ibegin; it2 < iend; ++it2)
	{
        cout << *it2 << " ";
    }
    cout << endl;
    
	//			C++11
    vector<int> vi1 = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    vector<int>::iterator it1;   // iterator object

	for(it1 = vi1.begin(); it1 < vi1.end(); ++it1){
        cout << *it1 << " ";
    }

    return 0;
}
