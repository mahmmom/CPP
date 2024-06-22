#include "Fixed.hpp"

int main( void )
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed num(10);
	std::cout << (num + 5) << std::endl;
	std::cout << (num - 5) << std::endl;
	std::cout << (num * 5) << std::endl;
	std::cout << (num / 5) << std::endl;
	return 0;
}
