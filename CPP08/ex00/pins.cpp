#include <iostream>
#include <map>
#include <cstdlib> // for atoi


int main()
{
	std::map<std::pair<int,int>,std::string> pins;
	int temp=0;
	std::string str;
	std::pair<std::pair<int,int>,std::string> p;
	std::pair<int,int> landmark;
	
	std::cout<<"Inserting...\n";
	while(temp>=0)
    {
		std::cout<<"Enter latitude: ";
		std::getline(std::cin,str);
		temp=atoi(str.c_str());
		if(temp>=0)
        {
			landmark.first=temp;
			std::cout<<"Enter longitude: ";
			std::getline(std::cin,str);
			temp=atoi(str.c_str());
			landmark.second=temp;
			p.first=landmark;
			std::cout<<"Enter name: ";
			std::getline(std::cin,str);
			p.second=str;
			pins.insert(p);
		}
	}
	
	std::cout<<"{   ";
	for(std::map<std::pair<int,int>,std::string>::iterator it = pins.begin(); it!=pins.end();it++)
		std::cout << it->first.first <<","<<it->first.second << "->" << it->second << "   ";
	std::cout<<"}\n";
		
	return 0;
}
