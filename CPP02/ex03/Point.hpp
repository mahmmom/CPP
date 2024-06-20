#ifndef POINT_HPP
#define POINT_HPP

/*

• Public members:
◦ A default constructor that initializes x and y to 0.
◦ A constructor that takes as parameters two constant floating-point numbers.
It initializes x and y with those parameters.
◦ A copy constructor.
◦ A copy assignment operator overload.
◦ A destructor.
◦ Anything else useful.

Private members:
◦ A Fixed const attribute x.
◦ A Fixed const attribute y.
◦ Anything else useful.

*/

#include "Fixed.hpp"

class Point {
	public:
		Point();
		Point(const float x1, const float y1);
		Point(const Point& other);
		Point&	operator=(const Point& other);
		~Point();

		Fixed getX() const;
		Fixed getY() const;

	private:
		const Fixed x;
		const Fixed y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif