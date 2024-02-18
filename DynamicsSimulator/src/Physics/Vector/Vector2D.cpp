#include "Vector2D.h"

#include <iostream>

Vector2D::Vector2D(double x, double y) 
	: x(x), y(y) {
#ifdef CONSTRUCTOR
	std::cout << "Created a 2D Vector" << std::endl;
#endif
}

#ifdef COPY_CONSTRUCTOR
Vector2D::Vector2D(const Vector2D& _v2d) 
	: x(_v2d.x), y(_v2d.y) {
	std::cout << "Copy-Created a 2D Vector" << std::endl;
}
#endif

Vector2D Vector2D::operator+(const Vector2D& other) {
	return Vector2D(x + other.x, y + other.y);
}

Vector2D& Vector2D::operator+=(const Vector2D& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2D Vector2D::operator*(const double& number) {
	return Vector2D(x * number, y * number);
}

Vector2D Vector2D::operator/(const double& number)
{
	return Vector2D(x / number, y / number);
}

std::ostream& operator<<(std::ostream& stream, const Vector2D& other)
{
	stream << "x: " << std::round(other.x * 1000000) / 1000000 << "; y: " << std::round(other.y * 1000000) / 1000000;
	return stream;
}
