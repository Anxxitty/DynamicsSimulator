#include "Vector2D.h"
#include <iostream>

#ifdef ENABLE_SFML
// WITH SFML
Vector2D::Vector2D()
	: sf::Vector2f(0.0f, 0.0f) {
#ifdef CONSTRUCTOR
	std::cout << "Created a 2D Vector" << std::endl;
#endif
}

Vector2D::Vector2D(float x, float y)
	: sf::Vector2f(x, y) {
#ifdef CONSTRUCTOR
	std::cout << "Created a 2D Vector" << std::endl;
#endif
}

Vector2D& Vector2D::operator=(const sf::Vector2f& other)
{
	x = other.x;
	y = other.y;
	return *this;
}

#ifdef COPY_CONSTRUCTOR
Vector2D::Vector2D(const Vector2D& _v2d) 
	: sf::Vector2f(_v2d.x, _v2d.y) {
	std::cout << "Copy-Created a 2D Vector" << std::endl;
}
#endif


#else
// WITHOUT SFML
Vector2D::Vector2D()
	: x(0), y(0) {
#ifdef CONSTRUCTOR
	std::cout << "Created a 2D Vector" << std::endl;
#endif
}

Vector2D::Vector2D(float x, float y)
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

Vector2D Vector2D::operator*(const float& number) {
	return Vector2D(x * number, y * number);
}

Vector2D Vector2D::operator/(const float& number)
{
	return Vector2D(x / number, y / number);
}
#endif



// BOTH WITH AND WITHOUT SFML
std::ostream& operator<<(std::ostream& stream, const Vector2D& other)
{
	stream << "x: " << std::round(other.x * 1000000) / 1000000 << "; y: " << std::round(other.y * 1000000) / 1000000;
	return stream;
}