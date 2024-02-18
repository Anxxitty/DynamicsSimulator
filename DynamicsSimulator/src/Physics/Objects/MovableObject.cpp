#include "MovableObject.h"

#include <iostream>


MovableObject::MovableObject(float X, float Y, float Mass, Hitbox ObjectHitbox)
	: m_Position(X, Y), Mass(Mass), m_Speed(0, 0), m_Acceleration(0, 0), ObjectHitbox(ObjectHitbox), ObjectGraphics(Graphics()) {
#ifdef CONSTRUCTOR
	std::cout << "Created a MovableObject" << std::endl;
#endif
}

MovableObject::MovableObject(float X, float Y, float Mass, Hitbox ObjectHitbox, Graphics ObjectGraphics)
	: m_Position(X, Y), Mass(Mass), m_Speed(0, 0), m_Acceleration(0, 0), ObjectHitbox(ObjectHitbox), ObjectGraphics(ObjectGraphics) {
#ifdef CONSTRUCTOR
	std::cout << "Created a MovableObject" << std::endl;
#endif
}

MovableObject::MovableObject(float X, float Y, float Mass, Vector2D InitialSpeed, Hitbox ObjectHitbox, Graphics ObjectGraphics)
	: m_Position(X, Y), Mass(Mass), m_Speed(InitialSpeed), m_Acceleration(0, 0), ObjectHitbox(ObjectHitbox), ObjectGraphics(ObjectGraphics) {
#ifdef CONSTRUCTOR
	std::cout << "Created a MovableObject" << std::endl;
#endif
}

#ifdef COPY_CONSTRUCTOR
MovableObject::MovableObject(const MovableObject& _mo) 
	: m_Position(_mo.m_Position), Mass(_mo.Mass), m_Speed(_mo.m_Speed), m_Acceleration(_mo.m_Acceleration), ObjectHitbox(_mo.ObjectHitbox), ObjectGraphics(_mo.ObjectGraphics) {
	std::cout << "Copy-Created a MovableObject" << std::endl;
}
#endif

Vector2D MovableObject::GetPosition() const {
	return m_Position;
}

void MovableObject::SetPosition(float x, float y) {
	m_Position.x = x;
	m_Position.y = y;
}

void MovableObject::SetPosition(Vector2D p) {
	m_Position.x = p.x;
	m_Position.y = p.y;
}

Vector2D MovableObject::GetAcceleration() const {
	return m_Acceleration;
}

Vector2D MovableObject::GetSpeed() const {
	return m_Speed;
}

void MovableObject::SetAcceleration(Vector2D a) {
	m_Acceleration.x = a.x;
	m_Acceleration.y = a.y;
}

void MovableObject::SetSpeed(Vector2D s) {
	m_Speed.x = s.x;
	m_Speed.y = s.y;
}



