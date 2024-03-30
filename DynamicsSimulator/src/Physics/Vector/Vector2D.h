#pragma once
#include "DynamicsSimulator.h"

#include <iostream>

#ifdef ENABLE_SFML

// WITH SFML
#include "SFML/System/Vector2.hpp"
struct Vector2D : sf::Vector2f {
	Vector2D();
	Vector2D(float x, float y);
	Vector2D& operator=(const sf::Vector2f& other);
#ifdef COPY_CONSTRUCTOR
	Vector2D(const Vector2D& _v2d);
#endif
};

#else

// WITHOUT SFML
struct Vector2D {
	float x, y;
	Vector2D();
	Vector2D(float x, float y);
#ifdef COPY_CONSTRUCTOR
	Vector2D(const Vector2D& _v2d);
#endif

	Vector2D operator+(const Vector2D& other);
	Vector2D& operator+=(const Vector2D& other);
	Vector2D operator*(const float& number);
	Vector2D operator/(const float& number);
};

#endif


// BOTH WITH AND WITHOUT SFML
std::ostream& operator<<(std::ostream& stream, const Vector2D& other);