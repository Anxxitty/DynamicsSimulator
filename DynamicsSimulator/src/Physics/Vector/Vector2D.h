#pragma once
#include "../../DynamicsSimulator.h"

#include <iostream>

struct Vector2D {
	double x, y;
	Vector2D(double x, double y);
#ifdef COPY_CONSTRUCTOR
	Vector2D(const Vector2D& _v2d);
#endif

	Vector2D operator+(const Vector2D& other);
	Vector2D& operator+=(const Vector2D& other);
	Vector2D operator*(const double& number);
	Vector2D operator/(const double& number);
};

std::ostream& operator<<(std::ostream& stream, const Vector2D &other);
