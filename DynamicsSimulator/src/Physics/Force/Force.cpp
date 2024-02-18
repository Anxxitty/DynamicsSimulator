#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

#include "Force.h"

float Force::GetIntensity() {
	return sqrt(x*x + y*y);
}

void Force::SetIntensity(float intensity) {
	x = x / sqrt(x * x + y * y) * intensity;
	y = y / sqrt(x * x + y * y) * intensity;
}

float Force::GetAngle() {
	return std::round( (cosh(x / sqrt(x * x + y * y)) * 180.0 / M_PI) * 1000000.0 ) / 1000000.0;
}

void Force::SetAngle(float angle) {
	x = cos(angle * M_PI / 180.0) * sqrt(x * x + y * y);
	y = sin(angle * M_PI / 180.0) * sqrt(x * x + y * y);
}

Force::Force(float Intensity, float Angle)
	: Vector2D(cos(Angle * M_PI / 180.0) * Intensity, sin(Angle * M_PI / 180.0) * Intensity) {
#ifdef CONSTRUCTOR
	std::cout << "Created a Force Class" << std::endl;
#endif
}