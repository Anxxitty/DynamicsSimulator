#include <iostream>

#include "Force.h"

float Force::GetIntensity() {
	return sqrt(x*x + y*y);
}

void Force::SetIntensity(float intensity) {
	x = x / sqrt(x * x + y * y) * intensity;
	y = y / sqrt(x * x + y * y) * intensity;
}

float Force::GetAngle() {
	return std::round( (cosh(x / sqrt(x * x + y * y)) * 180.0f / M_PIf) * 1000000.0f ) / 1000000.0f;
}

void Force::SetAngle(float angle) {
	x = cos(angle * M_PIf / 180.0f) * sqrt(x * x + y * y);
	y = sin(angle * M_PIf / 180.0f) * sqrt(x * x + y * y);
}

Force::Force(float Intensity, float Angle)
	: Vector2D(cos(Angle * M_PIf / 180.0f) * Intensity, sin(Angle * M_PIf / 180.0f) * Intensity) {
#ifdef CONSTRUCTOR
	std::cout << "Created a Force Class" << std::endl;
#endif
}