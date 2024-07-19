#include "Serializer.hpp"


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
