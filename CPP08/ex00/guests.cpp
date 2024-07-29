// Birthday Party 
// vector and list usage example

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <list>
#include <cstdlib> // for atoi

using namespace std;
 
#define USE_VECTOR
// #define USE_LIST 
 
class guest{
public:
	guest(){}
	~guest(){}
	void set_gender(string in)
    {
		char i = in.c_str()[0];
		if (i=='b' || i=='B' || i=='m' || i=='M')
			gender="Boy";
		else
			gender="Girl";
	}
	string name;
	string gender;
	int age;
};

#ifdef USE_VECTOR
	typedef vector<guest> my_container;
#elif defined USE_LIST
	typedef list<guest> my_container;
#endif

void read_file(my_container * my_guests)
{
	string in_str;
	ifstream in_file("my_guests.txt");
	if(in_file.is_open())
    {
		guest temp;
		while(getline(in_file,in_str))
        {
			temp.name=in_str;
			getline(in_file,in_str);
			temp.set_gender(in_str);
			getline(in_file,in_str);
			temp.age=atoi(in_str.c_str());
			my_guests->push_back(temp);
		}
		in_file.close();
	}
	else
		cout << "Unable to open file!\n\n";
}

void print_guests(my_container * my_guests)
{
	// std::list<guest>::iterator it = my_guests->begin();
	std::vector<guest>::iterator it = my_guests->begin();
	
	cout << "-- Container Content Start --\n";
	cout << "-----------------------------\n";
	while(it != my_guests->end())
    {
		cout << "Name: " << it->name << endl;
		cout << "Gender: " << it->gender << endl;
		cout << "Age: " << it->age << endl;
		cout << "-----------------------------\n";
		it++;
	}
	cout << "--  Container Content End  --\n";
}

void	print_one(const guest& my_guest)
{
	std::cout << "-----------------------------" << std::endl;
	std::cout << "One guest info" << std::endl;
	cout << "Name: " << my_guest.name << endl;
	cout << "Gender: " << my_guest.gender << endl;
	cout << "Age: " << my_guest.age << endl;
	std::cout << "-----------------------------" << std::endl;
}

void	remove_one(my_container* my_guests, int index)
{
	std::vector<guest>::iterator it = my_guests->begin() + index;
	std::cout << "-----------------------------" << std::endl;
	std::cout << "Remove one guest" << std::endl;
	std::cout << "-----------------------------" << std::endl;
	my_guests->erase(it);
}

void print_average(my_container * my_guests)
{
	// std::list<guest>::iterator it = my_guests->begin();
	std::vector<guest>::iterator it = my_guests->begin();
	
	cout << "-----------------------------\n";
	cout << "-- Average age of guests --\n";
	float average = 0;
	float sum = 0;
	while(it != my_guests->end())
    {
		sum +=it->age;
		it++;
	}
	average = sum/my_guests->size();
	std::cout << "Average age of guests is = " << average << std::endl;
}

int main()
{
	my_container * my_guests = new my_container;
	read_file(my_guests);
	print_guests(my_guests);
	print_one(my_guests->at(3));
	remove_one(my_guests, 3);
	print_guests(my_guests);
	print_average(my_guests);
	delete my_guests;
	return 0;
}
