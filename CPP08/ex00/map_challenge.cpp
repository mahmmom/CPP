#include <iostream>
#include <map>
// #include <unordered_map>
#include <cstdlib> // for atoi

using namespace std;

int main()
{
	map<int,string> hotel;
	int temp;
	string str;
	pair<int,string> p;
	
	cout<<"Inserting...\n";
	while(temp>=0)
    {
		cout<<"Enter room number: ";
		getline(cin,str);
		temp=atoi(str.c_str());
		if(temp>=0)
        {
			p.first=temp;
			cout<<"Enter name: ";
			getline(cin,str);
			p.second=str;
			hotel.insert(p);
		}
	}
	
	std::cout<<"{   ";
	for(std::map<int,std::string>::iterator it = hotel.begin(); it!=hotel.end();it++)
		std::cout << it->first << it->second << "   ";
	std::cout<<"}\n";
	
	cout<<"Enter an existing room number: ";
	getline(cin,str);
	temp=atoi(str.c_str());
	p.first=temp;
	cout<<"Enter a name: ";
	getline(cin,str);
	p.second=str;
	hotel.insert(p);
	
	cout<<"Enter an existing room number to delete: ";
	getline(cin,str);
	temp=atoi(str.c_str());
	hotel.erase(temp);
	
	std::cout<<"{   ";
	for(std::map<int,std::string>::iterator it = hotel.begin(); it!=hotel.end();it++)
		std::cout << it->first << it->second << "   ";
	std::cout<<"}\n";
		
	return 0;
}
