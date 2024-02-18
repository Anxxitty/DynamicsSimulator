#pragma once
#include "../../DynamicsSimulator.h"

#include "Hitbox.h"
#include "../../Display/Graphics.h"
#include "../Vector/Vector2D.h"

class MovableObject {
private:
	Vector2D m_Position, m_Speed, m_Acceleration;

public:
	double Mass;
	Hitbox ObjectHitbox;
	Graphics ObjectGraphics;

	MovableObject(double X, double Y, double Mass, Hitbox ObjectHitbox);
	MovableObject(double X, double Y, double Mass, Hitbox ObjectHitbox, Graphics ObjectGraphics);
	MovableObject(double X, double Y, double Mass, Vector2D InitialSpeed, Hitbox ObjectHitbox, Graphics ObjectGraphics);
#ifdef COPY_CONSTRUCTOR
	MovableObject(const MovableObject& _mo);
#endif

	Vector2D GetPosition() const;
	void SetPosition(double X, double Y);
	void SetPosition(Vector2D p);

	Vector2D GetAcceleration() const;
	Vector2D GetSpeed() const;
	void SetAcceleration(Vector2D a);
	void SetSpeed(Vector2D s);
};

