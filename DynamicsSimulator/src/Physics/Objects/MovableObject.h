#pragma once
#include "DynamicsSimulator.h"

#include "Hitbox.h"
#include "Display/Graphics.h"
#include "Physics/Vector/Vector2D.h"

class MovableObject {
private:
	Vector2D m_Position, m_Speed, m_Acceleration;

public:
	float Mass;
	Hitbox ObjectHitbox;
	Graphics ObjectGraphics;

	MovableObject(float X, float Y, float Mass, Hitbox ObjectHitbox);
	MovableObject(float X, float Y, float Mass, Hitbox ObjectHitbox, Graphics ObjectGraphics);
	MovableObject(float X, float Y, float Mass, Vector2D InitialSpeed, Hitbox ObjectHitbox, Graphics ObjectGraphics);
#ifdef COPY_CONSTRUCTOR
	MovableObject(const MovableObject& _mo);
#endif

	Vector2D GetPosition() const;
	void SetPosition(float X, float Y);
	void SetPosition(Vector2D p);

	Vector2D GetAcceleration() const;
	Vector2D GetSpeed() const;
	void SetAcceleration(Vector2D a);
	void SetSpeed(Vector2D s);
};

