#include "whatever.hpp"

int main( void )
{
	std::cout << "========================" << std::endl;
	int a = 2;
	int b = 3;
	std::cout << RED << "Before Swapping:" << RESET << std::endl;
	std::cout << BLUE << "a = " << a << ", b = " << b << RESET << std::endl;
	::swap( a, b );
	std::cout << MAGENTA << "After Swapping:" << RESET << std::endl;
	std::cout << YELLOW << "a = " << a << ", b = " << b << RESET << std::endl;
	std::cout << YELLOW << "min( a, b ) = " << ::min( a, b ) << RESET << std::endl;
	std::cout << YELLOW << "max( a, b ) = " << ::max( a, b ) << RESET << std::endl;

	std::cout << "========================" << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";
	std::cout << RED << "Before Swapping:" << RESET << std::endl;
	std::cout << BLUE << "c = " << c << ", d = " << d << RESET << std::endl;
	::swap(c, d);
	std::cout << MAGENTA << "After Swapping:" << RESET << std::endl;
	std::cout << GREEN << "c = " << c << ", d = " << d << RESET << std::endl;
	std::cout << GREEN << "min( c, d ) = " << ::min( c, d ) << RESET << std::endl;
	std::cout << GREEN << "max( c, d ) = " << ::max( c, d ) << RESET << std::endl;
	return 0;
}
