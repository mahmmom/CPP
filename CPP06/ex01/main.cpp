#include "Serializer.hpp"


/*
						Data Struct
						||===========||
				4 bytes ||	 int x	 ||
						||===========||
				4 bytes ||   int y   ||
						||===========||
				4 bytes || char/bool ||
						||  2 bytes	 ||
						||===========||			

Test for reinterpret_cast
int main()
{
	Data ptr;

	ptr.x = 5;
	ptr.y = 10;
	ptr.c = 'A';
	ptr.flag = true;

	int *test = reinterpret_cast<int*>(&ptr);
	
	std::cout << MAGENTA << "x example = " << *test << RESET << std::endl;
	test++;
	std::cout << MAGENTA << "y example = " << *test << RESET << std::endl;
	test++;
	char* C = reinterpret_cast<char*>(test);
	std::cout << MAGENTA << "c example = " << *C << RESET << std::endl;
	test++;
	std::cout << MAGENTA << "flag example = " << *(reinterpret_cast<bool*>(++C)) << RESET << std::endl;
}
*/


int main()
{
	Data ptr;
	Data* newptr;
	uintptr_t raw;

	ptr.x = 5;
	ptr.y = 10;
	ptr.c = 'A';
	ptr.flag = true;

	std::cout << GREEN << "x before = " << ptr.x << RESET << std::endl;
	std::cout << GREEN << "y before = " << ptr.y << RESET << std::endl;
	std::cout << GREEN << "c before = " << ptr.c << RESET << std::endl;
	std::cout << GREEN << "flag before = " << ptr.flag << RESET << std::endl;

	raw = Serializer::serialize(&ptr);
	newptr = Serializer::deserialize(raw);

	std::cout << RED << "===============" << RESET << std::endl;
	std::cout << YELLOW << "x after = " << newptr->x << RESET << std::endl;
	std::cout << YELLOW << "y after = " << newptr->y << RESET << std::endl;
	std::cout << YELLOW << "c after = " << newptr->c << RESET << std::endl;
	std::cout << YELLOW << "flag after = " << newptr->flag << RESET << std::endl;
}
