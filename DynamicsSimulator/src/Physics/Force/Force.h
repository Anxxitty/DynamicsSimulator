#pragma once
#include "../../DynamicsSimulator.h"

#include "../Vector/Vector2D.h"
#include "../Objects/MovableObject.h"

struct Force : public Vector2D {
	Force(float Intensity, float Angle);

	float GetIntensity();
	void SetIntensity(float intensity);
	float GetAngle();
	void SetAngle(float angle);
};