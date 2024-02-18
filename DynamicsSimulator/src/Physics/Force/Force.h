#pragma once
#include "../../DynamicsSimulator.h"

#include "../Vector/Vector2D.h"
#include "../Objects/MovableObject.h"

struct Force : public Vector2D {
	Force(double Intensity, double Angle);

	double GetIntensity();
	void SetIntensity(double intensity);
	double GetAngle();
	void SetAngle(double angle);
};