#include "Point.hpp"

Fixed	abs(Fixed Area)
{
	// ABS we implement it here because we are using Fixed as data type
	// So if the num is negative at the end we change whatever inside
	// we multiply -1 the Num inside, while keeping it in setRawBits
	if(Area.getRawBits() < 0)
		return Area.operator*(-1);
	return Area;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	// Let's say the triangle vertices are a(x1, y1), b(x2, y2), and c(x3, y3)
	// and the point we want to check is (x, y).

	std::cout << "a: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
    std::cout << "b: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
    std::cout << "c: (" << c.getX() << ", " << c.getY() << ")" << std::endl;
    std::cout << "newPoint: (" << point.getX() << ", " << point.getY() << ")" << std::endl;
	/*
										b(x2, y2) 
									 /\
									/  \
								   /    \
								  /      \
								 /        \
								/          \
							   /            \
							  /              \
							 /                \
							/__________________\
					a(x1, y1)             c(x3, y3)

	*/

	// 			  = abs(((x2 - x1)*(y3 - y1) - (x3 - x1)*(y2 - y1)) / 2)
	Fixed bigArea = abs(((b.getX() - a.getX())*(c.getY() - a.getY()) - (c.getX() - a.getX())*(b.getY() - a.getY())) / 2);
	Fixed Area1 = abs(((point.getX() - a.getX())*(c.getY() - a.getY()) - (c.getY() - a.getX())*(point.getY() - a.getY())) / 2);
	Fixed Area2 = abs(((b.getX() - point.getX())*(c.getY() - point.getY()) - (point.getY() - a.getX())*(b.getY() - a.getY())) / 2);
	Fixed Area3 = abs(((b.getX() - point.getX())*(point.getY() - a.getY()) - (point.getY() - a.getX())*(b.getY() - a.getY())) / 2);
	Fixed Sum = Area1 + Area2 + Area3;
	
	std::cout << "Big Area = " << bigArea.toFloat() << std::endl;
	std::cout << "Sum = " << Sum.toFloat() << std::endl;

	return Sum == bigArea;
}
