#include "Point.hpp"

int main()
{
    Point a;
	Point b(5,10);
	Point c(-10,0);
	Point newPoint(5,5);

	if (bsp(a, b, c, newPoint))
		std::cout << "Point is inside Triangle" << std::endl;
	else
		std::cout << "Point is NOT inside Triangle" << std::endl;

    return 0;
}
