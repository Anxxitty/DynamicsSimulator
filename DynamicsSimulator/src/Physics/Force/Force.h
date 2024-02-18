#pragma once
#include "DynamicsSimulator.h"

#include "Physics/Vector/Vector2D.h"
#include "Physics/Objects/MovableObject.h"

struct Force : public Vector2D {
	Force(float Intensity, float Angle);

	float GetIntensity();
	void SetIntensity(float intensity);
	float GetAngle();
	void SetAngle(float angle);
};